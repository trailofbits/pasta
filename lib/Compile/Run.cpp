/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <iostream>
#include <unordered_set>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTConsumer.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticSema.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Parse/Parser.h>
#include <clang/Sema/Sema.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Compiler.h>

#include "FileSystem.h"

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

#define PASTA_DEBUG_RUN 0

namespace pasta {
namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, LexLevel, unsigned);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, TLSSupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, VLASupported, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasLegalHalfType, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat128, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TargetInfo, HasFloat16, bool);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, FileEntry, File, std::unique_ptr<llvm::vfs::File>);
}  // namespace detail
namespace {

// Pre-process the code. This does a few things:
//
//    1)  Record all tokens produced as outputs from the preprocessor.
//    2)  Read out the data of each of the non-empty, non-whitespace, non-
//        comment tokens, and dump them into a buffer, `impl.preprocessed_code`.
//        This buffer will have one line for each origin preprocessed token.
//        Thus, we will have Clang re-preprocess this new buffer, and then we'll
//        be able to associated back to original tokens by using the line number
//        of the updated token.
static void PreprocessCode(ASTImpl &impl, clang::CompilerInstance &ci,
                           clang::Preprocessor &pp) {
  auto &source_manager = ci.getSourceManager();
  auto &lang_opts = ci.getLangOpts();

  llvm::raw_string_ostream os(impl.preprocessed_code);
  llvm::raw_string_ostream backup_os(impl.backup_token_data);

  std::string tok_data;
  std::string fixed_tok_data;

  pp.EnterMainSourceFile();

  // NOTE(pag): The `ParsedFileTracker` emits a token for entering files, so
  //            there will be one token already representing entering the main
  //            source file.
  auto &num_lines = impl.num_lines;

  clang::Token tok;
  for (;;) {

    // Check that we're maintaining our key invariant, which is that tokens
    // match up with line numbers.
    assert(num_lines == impl.tokens.size());

    pp.Lex(tok);

    // We might have just lexed the token following some macro expansion.
    impl.TryInjectEndOfMacroExpansion(tok.getLocation());

    // NOTE(pag): We don't need to inject a token here because the
    //            `ParsedFileTracker` will inject the end of file token for
    //            us when the `FileChanged` callback happens.
    if (tok.is(clang::tok::eof)) {
      break;
    }

    tok_data.clear();
    (void) TryReadRawToken(source_manager, lang_opts, tok, &tok_data);

    if (tok.isOneOf(clang::tok::eod, clang::tok::unknown, clang::tok::comment,
                    clang::tok::code_completion)) {
      if (tok_data.empty()) {

        // Only retain these if they're contributing something in terms of
        // source locations.
        if (auto loc = tok.getLocation(); loc.isValid() && loc.isFileID()) {
          impl.AppendMarker(loc, TokenRole::kFileToken);
        }

      // Comments and whitespace are stored "out-of-line" in the
      // `backup_token_data` so that they aren't part of our huge
      // fake file that has one token per line (comments/whitespace
      // might have multiple lines, so we don't want to risk them
      // spanning multiple lines in the fake file, which would break
      // our invariant of line:token, so that we can use a token's
      // line number as an index.
      } else {
        backup_os.flush();
        impl.AppendBackupToken(tok, impl.backup_token_data.size(),
                               tok_data.size());
        backup_os << tok_data;
        os << '\n';
        os.flush();
        ++num_lines;
      }
      continue;
    }

    // Figure out of the token introduces new lines. If so, we'll need
    // to "mute" them.
    auto has_new_line = false;
    for (auto ch : tok_data) {
      if ('\n' == ch || '\r' == ch) {
        has_new_line = true;
      }
    }

    // The token data read has no new lines, great!
    if (!has_new_line) {
      os.flush();
      impl.AppendToken(tok, impl.preprocessed_code.size(), tok_data.size());
      os << tok_data << '\n';
      os.flush();
      ++num_lines;
      continue;
    }

    // The token needs to be modified somehow, so add it to our backups.
    backup_os.flush();
    impl.AppendBackupToken(tok, impl.backup_token_data.size(), tok_data.size());
    backup_os << tok_data;

    // The token data read does have new lines; we need to fix it up.
    fixed_tok_data.clear();
    auto in_string = false;
    auto in_escape = false;

    for (const auto ch : tok_data) {
      if ('\n' == ch || '\r' == ch) {

        if (fixed_tok_data.empty()) {
          in_escape = false;
          continue;

        // Replace with an escaped character.
        } else if (in_string) {
          in_escape = false;

          fixed_tok_data.push_back('\\');
          if ('\n' == ch) {
            fixed_tok_data.push_back('n');
          } else {
            fixed_tok_data.push_back('r');
          }
        } else {
          in_escape = false;
          fixed_tok_data.push_back(' ');
        }

      } else if ('"' == ch) {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          fixed_tok_data.push_back('"');
          in_escape = false;

        } else if (!in_string) {
          fixed_tok_data.push_back('"');
          in_string = true;

        } else {
          fixed_tok_data.push_back('"');
          in_string = false;
        }

      } else if ('\\' == ch) {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          fixed_tok_data.push_back('\\');
          in_escape = false;
        } else {
          in_escape = true;
        }

      } else {
        if (in_escape) {
          fixed_tok_data.push_back('\\');
          in_escape = false;
        }
        fixed_tok_data.push_back(ch);
      }
    }

    os << fixed_tok_data << '\n';
    os.flush();
    ++num_lines;
  }

  pp.EndSourceFile();

  os.flush();

  // For some reason Clang doesn't invoke the `ExitFile` thing for the main
  // file.
  if (impl.tokens.back().Kind() != clang::tok::eof) {

    // We didn't get an `ExitFile`.
    if (impl.tokens.back().Role() != TokenRole::kEndOfFileMarker) {
      if (tok.is(clang::tok::eof)) {
        impl.AppendMarker(tok.getLocation().getLocWithOffset(-1),
                          TokenRole::kEndOfFileMarker);
      } else {
        auto loc = source_manager.getLocForEndOfFile(
            source_manager.getMainFileID());
        impl.AppendMarker(loc.getLocWithOffset(-1),
                          TokenRole::kEndOfFileMarker);
      }
    }
    impl.tokens.back().kind = clang::tok::eof;
  }

#if PASTA_DEBUG_RUN
  // NOTE(pag): If there's a compiler error that "shouldn't happen," then
  //            enabling the below code can help diagnose it.
  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
  write(fd, impl.preprocessed_code.data(), impl.preprocessed_code.size());
  close(fd);
#endif  // PASTA_DEBUG_RUN
}

}  // namespace


// Tracks open files.
class ParsedFileTracker : public clang::PPCallbacks {
 private:
  clang::Preprocessor &pp;
  clang::SourceManager &sm;
  const clang::LangOptions &lang_opts;
  const pasta::FileManager fm;
  std::shared_ptr<pasta::FileSystem> fs;
  const std::filesystem::path cwd;

  ASTImpl * const ast;

  // What is the current file being parsed. This roughly corresponds to the
  // top of `file_id_stack` below.
  clang::FileID current_file_id;
  std::optional<File> current_file;

  // Tracks whether or not we've tokenized a file.
  std::unordered_set<pasta::FileImpl *> seen;
//  std::unordered_map<std::string, clang::FileID> seen_file_ids;

  // Stack of file IDs that we're parsing.
  std::vector<clang::FileID> file_id_stack;

  // This represents what the logical "zero" lexer level is. Clang's lexer
  // is re-entrant, so there are recursive calls in it due to things like
  // macro expansion and such. The lexer level tracks these things. It also
  // might track things like the stack size, so we always want to be sure
  // that we know what the logical baseline lexer level is for the current
  // file, so that we can distinguish macro expansion tokens from the first
  // place where they occur in a file, from macro expansion tokens from sub-
  // expansions.
  unsigned logical_level_0{0u};

  // Try to inject an end-of-macro token.
  void TryInjectEOM(clang::SourceLocation loc) {
    ast->TryInjectEndOfMacroExpansion(loc);
  }

  void InjectToken(clang::SourceLocation loc, TokenRole role) {
    assert(loc.isValid());
    assert(loc.isFileID());
    TryInjectEOM(loc);
    ast->AppendMarker(loc, role);
  }

  clang::SourceLocation TryFindHash(clang::SourceLocation loc,
                                    clang::SourceLocation backup_loc) {
    if (loc.isInvalid() || !loc.isFileID()) {
      return backup_loc;
    }

    bool invalid = false;
    auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
    llvm::StringRef file_data = sm.getBufferData(file_id, &invalid);
    if (invalid) {
      return backup_loc;
    }

    // Scan backwards through the file buffer from the start of the macro token
    // that was undefined, hoping to find the `#` of the directive. If we find
    // it, then emit an injected token.
    for (int loc_offset = 0; file_offset; --loc_offset) {
      if (file_data[file_offset--] == '#') {
        return loc.getLocWithOffset(loc_offset);
      }
    }

    // TODO(pag): Use start of file location instead?
    return backup_loc;
  }

  // Try to locate the end of a directive. This is typically the first newline
  // that isn't preceded by a line continuation character.
  clang::SourceLocation TryFindEOD(clang::SourceLocation loc) {
    if (loc.isInvalid() || !loc.isFileID()) {
      assert(false);
      return clang::SourceLocation();
    }

    bool invalid = false;
    auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
    llvm::StringRef file_data = sm.getBufferData(file_id, &invalid);
    if (invalid) {
      assert(false);
      return clang::SourceLocation();
    }

    // Scan backwards through the file buffer from the start of the macro token
    // that was undefined, hoping to find the `#` of the directive. If we find
    // it, then emit an injected token.
    auto seen_continuation = false;
    auto max_offset = file_data.size();
    int loc_offset = 0;
    for (; file_offset < max_offset; ++loc_offset, ++file_offset) {

      switch (file_data[file_offset]) {
        case '\\':
          seen_continuation = true;
          break;
        case '\n':
          if (seen_continuation) {
            seen_continuation = false;
            continue;
          } else {
            return loc.getLocWithOffset(loc_offset);
          }
        default:
          continue;
      }
    }

    return sm.getLocForEndOfFile(file_id);
  }

 public:

  explicit ParsedFileTracker(clang::Preprocessor &pp_,
                             clang::SourceManager &sm_,
                             const clang::LangOptions &lang_opts_,
                             const pasta::FileManager &fm_,
                             std::filesystem::path cwd_,
                             ASTImpl *ast_)
      : pp(pp_),
        sm(sm_),
        lang_opts(lang_opts_),
        fm(fm_),
        fs(fm.FileSystem()),
        cwd(std::move(cwd_)),
        ast(ast_) {}

  virtual ~ParsedFileTracker(void) {}

  void Clear(void) {
    current_file_id = {};
    current_file.reset();
    seen.clear();
    fs.reset();
  }

  // Callback invoked whenever an inclusion directive of any kind (`#include`,
  // `#import`, etc.) has been processed, regardless of whether the inclusion
  // will actually result in an inclusion.
  void InclusionDirective(
      clang::SourceLocation hash_loc, const clang::Token & /* include_tok */,
      llvm::StringRef /* file_name */, bool /* is_angled */,
      clang::CharSourceRange /* file_name_range */,
      const clang::FileEntry * /* file */, llvm::StringRef /* search_path */,
      llvm::StringRef /* relative_path */, const clang::Module * /* imported */,
      clang::SrcMgr::CharacteristicKind /* file_type */) final {

    // Some macros might expand *just* before an `#include`, we want to
    // inject this to act as an upper bound on where the macro expansion ends.
    TryInjectEOM(hash_loc);
  }

//  // Callback invoked whenever a source file is skipped as the result
//  // of header guard optimization.
//  void FileSkipped(const clang::FileEntryRef &skipped_file,
//                   const clang::Token &filename_tok,
//                   clang::SrcMgr::CharacteristicKind) final {
//    if (!skipped_file.isValid()) {
//      return;
//    }
//
//    auto it = seen_file_ids.find(skipped_file.getName().str());
//    if (it == seen_file_ids.end()) {
//      return;
//    }
//
//    clang::FileID file_id = it->second;
//
//    // Inject dummy tokens representing the entry and exit of this file.
//    InjectToken(sm.getLocForStartOfFile(file_id),
//                TokenRole::kBeginOfFileMarker);
//    InjectToken(sm.getLocForEndOfFile(file_id),
//                TokenRole::kEndOfFileMarker);
//  }

  // Each time we enter a source file, try to keep track of it.
  void FileChanged(clang::SourceLocation loc,
                   clang::PPCallbacks::FileChangeReason reason,
                   clang::SrcMgr::CharacteristicKind file_type,
                   clang::FileID file_id = clang::FileID()) final {

    auto level = pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, LexLevel);

    if (clang::PPCallbacks::EnterFile == reason ||
        clang::PPCallbacks::ExitFile == reason) {

      // On entry, `level` is correct, on exit, we want to represent the new
      // logical level as the level *after* exiting, so `level` is off by one.
      if (clang::PPCallbacks::EnterFile == reason) {
        logical_level_0 = level - static_cast<unsigned>(reason);

      } else if (clang::PPCallbacks::ExitFile == reason) {
        assert(level > 0u);
        logical_level_0 = level - 1u;
      }

      switch (file_type) {
        case clang::SrcMgr::CharacteristicKind::C_User:
        case clang::SrcMgr::CharacteristicKind::C_System:
        case clang::SrcMgr::CharacteristicKind::C_ExternCSystem:
          break;
        case clang::SrcMgr::CharacteristicKind::C_User_ModuleMap:
        case clang::SrcMgr::CharacteristicKind::C_System_ModuleMap:
          return;
      }
    } else {
      return;
    }

    if (clang::PPCallbacks::EnterFile == reason) {
      assert(loc.isValid());
      assert(loc.isFileID());
      file_id = sm.getFileID(loc);
    }

    const clang::FileEntry *fe = sm.getFileEntryForID(file_id);
    if (!fe) {
      return;
    }

    auto fs_path = fs->ParsePath(fe->getName().str(), cwd, fs->PathKind());
    auto fs_stat = fs->Stat(fs_path, cwd);
    if (!fs_stat.Succeeded()) {
      assert(false);
      return;
    }

    auto maybe_file = fm.OpenFile(fs_stat.TakeValue());
    if (!maybe_file.Succeeded()) {
      assert(false);
      return;
    }

    auto file = maybe_file.TakeValue();
//    std::cerr
//        << "!!! reason=" << int(reason) << " file_type="
//        << int(file_type) << " loc_valid=" << loc.isValid()
//        << " loc_file=" << loc.isFileID() << " level=" << level
//        << " path=" << file.Path().generic_string() << '\n';

    // Keep track of the current file that we're in. This, along with the
    // `logical_level_0`, helps us to identify uses of macros.
    if (clang::PPCallbacks::EnterFile == reason) {
      file_id_stack.push_back(file_id);
      current_file_id = file_id;
      current_file = file;

      // Inject a dummy token representing the entry to this file.
      InjectToken(sm.getLocForStartOfFile(file_id),
                  TokenRole::kBeginOfFileMarker);

    } else if (clang::PPCallbacks::ExitFile == reason) {
      assert(!file_id_stack.empty());
      assert(file_id_stack.back() == file_id);
      file_id_stack.pop_back();
      if (!file_id_stack.empty()) {
        current_file_id = file_id_stack.back();
        auto prev_file_it = ast->id_to_file.find(
            current_file_id.getHashValue());
        assert(prev_file_it != ast->id_to_file.end());
        current_file = prev_file_it->second;
      }

      // Add a dummy token signifying the end of the file.
      //
      // TODO(pag): Make it an `eof` token?
      InjectToken(sm.getLocForEndOfFile(file_id).getLocWithOffset(-1),
                  TokenRole::kEndOfFileMarker);
    }

    // Keep a mapping of Clang file IDs to parsed files.
    auto old_file_it = ast->id_to_file.find(file_id.getHashValue());
    if (old_file_it == ast->id_to_file.end()) {
      ast->id_to_file.emplace(file_id.getHashValue(), file);
    } else {
      assert(old_file_it->second.impl.get() == file.impl.get());
    }

    // If we've seen this file already, then don't tokenize it.
    if (auto [seen_it, added] = seen.emplace(file.impl.get()); !added) {
      return;
    }

//    seen_file_ids.emplace(fe->getName().str(), file_id);

    auto maybe_data = file.Data();
    if (!maybe_data.Succeeded()) {
      return;
    }

    ast->parsed_files.emplace_back(std::move(file));

    std::unique_lock<std::mutex> locker(file.impl->tokens_lock);
    if (file.impl->has_tokens) {
      return;
    }

    auto data = maybe_data.TakeValue();
    file.impl->has_tokens = true;
    if (data.empty()) {
      return;
    }

    const char *last_tok_begin = data.data();
    const char * const buff_begin = last_tok_begin;
    const char * const buff_end = &(last_tok_begin[data.size()]);
    clang::Lexer lexer(loc, lang_opts, buff_begin, last_tok_begin, buff_end);
    lexer.SetKeepWhitespaceMode(true);  // Implies keep comments.

    // Raw lex this file's tokens.
    clang::Token tok;
    while (!lexer.LexFromRawLexer(tok)) {
      if (tok.is(clang::tok::eof)) {
        break;
      }
      const auto tok_loc = tok.getLocation();
      auto offset = sm.getFileOffset(tok_loc);
      assert(offset < data.size());
      auto ptr = &(buff_begin[offset]);
      auto &last_tok = file.impl->tokens.emplace_back(
          ptr, sm.getSpellingLineNumber(tok_loc),
          sm.getSpellingColumnNumber(tok_loc),
          tok.getKind());

      // TODO(pag): Try to merge with prior `tok::hash` and `tok::at`, and
      //            ignore whitespace.
      if (tok.is(clang::tok::identifier)) {
        if (clang::IdentifierInfo *ii = tok.getIdentifierInfo()) {
          auto ppk = ii->getPPKeywordID();
          auto atk = ii->getObjCKeywordID();
          if (ppk != clang::tok::pp_not_keyword) {
            last_tok.kind.extended.is_pp_kw = 1;
            last_tok.kind.extended.alt_kind = static_cast<uint16_t>(ppk);

          } else if (atk != clang::tok::objc_not_keyword) {
            last_tok.kind.extended.is_objc_kw = 1;
            last_tok.kind.extended.alt_kind = static_cast<uint16_t>(ppk);
          }
        }
      }
      last_tok_begin = ptr;
    }

    const auto tok_loc = tok.getLocation();
    file.impl->tokens.emplace_back(
        buff_end, sm.getSpellingLineNumber(tok_loc),
        sm.getSpellingColumnNumber(tok_loc), clang::tok::eof);
  }

  // Callback invoked when a `#ident` or `#sccs` directive is read.
  void Ident(clang::SourceLocation loc, clang::StringRef) final {
    TryInjectEOM(TryFindHash(loc, loc));
  }

  // Callback invoked when start reading any pragma directive.
  void PragmaDirective(clang::SourceLocation loc,
                       clang::PragmaIntroducerKind introducer) final {
    if (clang::PragmaIntroducerKind::PIK_HashPragma == introducer) {
      TryInjectEOM(TryFindHash(loc, loc));
    }
  }

  // Hook called when a source range is skipped.
  void SourceRangeSkipped(clang::SourceRange range,
                          clang::SourceLocation endif_loc) final {
    TryInjectEOM(range.getBegin());
    TryInjectEOM(range.getEnd());
    TryInjectEOM(endif_loc);
  }

  // Hook called whenever an `#if` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void If(clang::SourceLocation loc,
          clang::SourceRange /* condition_range */,
          ConditionValueKind cvk) final {

    if (ConditionValueKind::CVK_NotEvaluated == cvk) {
      TryInjectEOM(TryFindHash(loc, loc));

    // If the condition has been evaluated, then that implies that possible
    // macro expansion has also happened, and so we don't want to mark the
    // location of the `#` of the directive because that would precede the
    // location of the injected token with role `kBeginOfMacroExpansion`.
    } else if (auto eod_loc = TryFindEOD(loc); eod_loc.isValid()) {
      TryInjectEOM(eod_loc);
    }
  }

  // Hook called whenever an `#elif` is seen.
  //
  // NOTE(pag): `condition_range` might point into file locations.
  void Elif(clang::SourceLocation loc,
            clang::SourceRange /* condition_range */,
            ConditionValueKind cvk, clang::SourceLocation /* if_loc */) final {

    if (ConditionValueKind::CVK_NotEvaluated == cvk) {
      TryInjectEOM(TryFindHash(loc, loc));

    // If the condition has been evaluated, then that implies that possible
    // macro expansion has also happened, and so we don't want to mark the
    // location of the `#` of the directive because that would precede the
    // location of the injected token with role `kBeginOfMacroExpansion`.
    } else if (auto eod_loc = TryFindEOD(loc); eod_loc.isValid()) {
      TryInjectEOM(eod_loc);
    }
  }

  // Hook called whenever an `#ifdef` is seen.
  void Ifdef(clang::SourceLocation loc,
             const clang::Token & /* macro_name_tested */,
             const clang::MacroDefinition &) final {
    TryInjectEOM(TryFindHash(loc, loc));
  }

  // Hook called whenever an `#ifndef` is seen.
  void Ifndef(clang::SourceLocation loc,
              const clang::Token & /* macro_name_tested */,
              const clang::MacroDefinition &) final {
    TryInjectEOM(TryFindHash(loc, loc));
  }

  /// Hook called whenever an `#else` is seen.
  void Else(clang::SourceLocation loc,
            clang::SourceLocation /* if_loc */) final {
    TryInjectEOM(TryFindHash(loc, loc));
  }

  // Hook called whenever an `#endif` is seen.
  void Endif(clang::SourceLocation loc,
             clang::SourceLocation /* if_loc */) final {
    TryInjectEOM(TryFindHash(loc, loc));
  }

  // Hook called whenever a macro definition is seen.
  void MacroDefined(const clang::Token &macro_name,
                    const clang::MacroDirective *directive) final {
    auto loc = macro_name.getLocation();
    if (directive) {
      TryInjectEOM(TryFindHash(loc, directive->getLocation()));

    } else if (loc.isValid() && loc.isFileID()) {
      TryInjectEOM(TryFindHash(loc, loc));
      return;
    }
  }

  // Hook called whenever a macro `#undef` is seen.
  //
  // NOTE(pag): `directive` can't be trusted.
  void MacroUndefined(const clang::Token &macro_name,
                      const clang::MacroDefinition &,
                      const clang::MacroDirective *directive) final {

    auto loc = macro_name.getLocation();
    if (directive) {
      TryInjectEOM(TryFindHash(loc, directive->getLocation()));

    } else if (loc.isValid() && loc.isFileID()) {
      TryInjectEOM(TryFindHash(loc, loc));
      return;
    }
  }

  // Called by Preprocessor::HandleMacroExpandedIdentifier when a
  // macro invocation is found. We want to inject placeholder tokens into
  // the parsed range that relates to where the macro is in the original file.
  // Thus, we are trying to narrow down on the set of expansions that happen
  // at a file level, and not "sub-expansions" inside of other macro expansions.
  void MacroExpands(const clang::Token &macro_name,
                    const clang::MacroDefinition &def,
                    clang::SourceRange use_range,
                    const clang::MacroArgs *args) final {
    if (current_file_id.isInvalid()) {
      return;
    }

    // Macro expansion inside of a macro, or inside of a directive.
    auto level = pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, LexLevel);
    if ((logical_level_0 + 1u) < level) {
      return;
    }

    // If the macro use isn't in the current file (e.g. it is a macro being
    // expanded inside of another macro), then ignore it.
    auto loc = macro_name.getLocation();
    if (!loc.isFileID()) {
      return;
    }

    auto [file_id, offset] = sm.getDecomposedLoc(loc);
    if (file_id != current_file_id) {
      assert(false);
      return;
    }

    auto [end_fid, end_offset] = sm.getDecomposedLoc(use_range.getEnd());
    assert(end_fid == file_id);

    auto end_loc = use_range.getEnd();
    assert(end_loc.isValid());
    assert(end_loc.isFileID());
    assert(current_file.has_value());

#ifndef NDEBUG
    std::optional<FileToken> file_tok = current_file->TokenAtOffset(offset);
    if (!file_tok) {
      assert(false);
    } else {
      assert(clang::tok::isAnyIdentifier(file_tok->Kind()) ||
             clang::tok::getKeywordSpelling(file_tok->Kind()));
      bool invalid = false;
      auto ident_data = sm.getCharacterData(loc, &invalid);
      assert(!invalid);
      std::string_view ident_name(ident_data, macro_name.getLength());
      assert(file_tok->Data() == ident_name);
    }
#endif

    InjectToken(loc, TokenRole::kBeginOfMacroExpansionMarker);

    if (offset == end_offset) {
      assert(!args);
      ast->macro_use_end_loc = loc.getLocWithOffset(
          static_cast<int>(macro_name.getLength()));

    } else if (args) {
      assert(offset < end_offset);

#ifndef NDEBUG
      // Scan forward and find the closing parenthesis.
      bool invalid = false;
      auto end_data = sm.getCharacterData(end_loc, &invalid);
      assert(!invalid);
      assert(end_data[0] == ')');
#endif

      // TODO(pag): Handle the case where the ending parenthesis is the
      //            result of a macro expansion.
      ast->macro_use_end_loc = end_loc.getLocWithOffset(1);

    } else {
      assert(false);
      ast->macro_use_end_loc = end_loc.getLocWithOffset(1);
    }
  }
};

// Run a command ans return the AST or the first error.
Result<AST, std::string> CompileJob::Run(void) const {
  std::stringstream err;

  auto ast = std::make_shared<ASTImpl>(SourceFile());
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_vfs(
      new LLVMFileSystem(impl->file_manager));
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_vfs(
      new llvm::vfs::OverlayFileSystem(real_vfs.get()));
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_vfs(
      new llvm::vfs::InMemoryFileSystem);
  overlay_vfs->pushOverlay(mem_vfs.get());
  overlay_vfs->setCurrentWorkingDirectory(
      WorkingDirectory().generic_string());

  auto diag = std::make_unique<SaveFirstErrorDiagConsumer>(ast);
  llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> diagnostics_engine(
      new clang::DiagnosticsEngine(new clang::DiagnosticIDs,
                                   new clang::DiagnosticOptions, diag.get(),
                                   false /* Take ownership of the consumer */));

  diagnostics_engine->Reset();
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

  ast->ci = std::make_shared<clang::CompilerInstance>();
  auto &ci = *(ast->ci);
  ci.setDiagnostics(diagnostics_engine.get());
  ci.setASTConsumer(std::make_unique<clang::ASTConsumer>());

  auto &invocation = ci.getInvocation();
  auto &fs_options = invocation.getFileSystemOpts();
  WorkingDirectory().generic_string().swap(fs_options.WorkingDir);

  llvm::IntrusiveRefCntPtr<clang::FileManager> fm(
      new clang::FileManager(fs_options, overlay_vfs.get()));

  ci.setFileManager(fm.get());
  ci.createSourceManager(*fm);

  // Make sure the compiler instance is starting with the approximately
  // the right cross-compilation target info.
  auto &target_opts = invocation.getTargetOpts();
  target_opts.HostTriple = llvm::sys::getDefaultTargetTriple();
  target_opts.Triple = TargetTriple();
  target_opts.ForceEnableInt128 = true;

  auto target_info = clang::TargetInfo::CreateTargetInfo(ci.getDiagnostics(),
                                                         invocation.TargetOpts);

  // Some systems/targets declare/include these types, though the current target
  // may not. Nonetheless, we want to parse them.
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, TLSSupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, VLASupported) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasLegalHalfType) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat128) = true;
  target_info->*PASTA_ACCESS_MEMBER(clang, TargetInfo, HasFloat16) = true;
  ci.setTarget(target_info);

  const auto &argv = Arguments();
  llvm::ArrayRef<const char *> argv_arr(argv.Argv(), argv.Size());
  const auto invocation_is_valid = clang::CompilerInvocation::CreateFromArgs(
      invocation, argv_arr, *diagnostics_engine);

  if (!invocation_is_valid) {
    if (diag->error.empty()) {
      err << "Unable to create compiler invocation from command: "
          << argv.Join();
      return err.str();
    } else {
      err << "Unable to create compiler invocation from command due to error: "
          << diag->error;
      return err.str();
    }
  }

  // Just in case parsing of the command-line args changed this.
  diagnostics_engine->setConstexprBacktraceLimit(0);
  diagnostics_engine->setTemplateBacktraceLimit(0);
  diagnostics_engine->setErrorLimit(1);
  diagnostics_engine->setIgnoreAllWarnings(true);
  diagnostics_engine->setWarningsAsErrors(false);

  // Some old GNU code exposes some C++ functions, e.g. `acosf`, as `constexpr`
  // implemented in terms of builtins like `__builtin_acosf`, but really this is
  // not valid. Nonetheless, we want to parse these cases.
  diagnostics_engine->setSeverity(
      clang::diag::note_invalid_subexpr_in_const_expr,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());
  diagnostics_engine->setSeverity(
      clang::diag::ext_constexpr_function_never_constant_expr,
      clang::diag::Severity::Ignored,
      clang::SourceLocation());

  // TODO(pag): Consider setting `UsePredefines` to `false` and using an
  //            `-include` file generated by `mu-import` to deal with platform
  //            and compiler differences.
  //
  // TODO(pag): Generate said pre-define include file.
  //
  // TODO(pag): We can possibly also emit implicitly generated functions
  //            and typedefs (via pretty printing) to this file, and also
  //            disable their generation. This will then hopefully mean
  //            fewer implicit decls in the indexer.
  auto &pp_options = invocation.getPreprocessorOpts();
  pp_options.DetailedRecord = true;
  pp_options.SingleFileParseMode = false;
  pp_options.LexEditorPlaceholders = false;
  pp_options.RetainRemappedFileBuffers = true;

  auto &ppo_options = invocation.getPreprocessorOutputOpts();
  ppo_options = {};  // Reset to defaults.

  const auto lang_opts = invocation.getLangOpts();

  lang_opts->EmitAllDecls = true;
  lang_opts->CXXExceptions = true;
  lang_opts->Blocks = true;
  lang_opts->POSIXThreads = true;
  lang_opts->HeinousExtensions = true;
  lang_opts->DoubleSquareBracketAttributes = true;
  lang_opts->GNUMode = true;
  lang_opts->GNUKeywords = true;
  lang_opts->GNUAsm = true;
  lang_opts->SpellChecking = false;
  lang_opts->RetainCommentsFromSystemHeaders = false;
  lang_opts->AllowEditorPlaceholders = false;
  lang_opts->CommentOpts.ParseAllComments = false;

  // Affects `PPCallbacks`, and also does additional parsing of things in
  // Objective-C mode, e.g. parsing module imports.
  lang_opts->DebuggerSupport = true;

  // TODO(pag): Should pragmas be ignored?

  // Enable C++-style comments, even in C code. If we don't do this, then we
  // can observe two tokens for something like `// foo` in C code, one is a
  // `slash`, the second is a `comment`.
  lang_opts->LineComment = true;

  // Don't get whitespace.
  lang_opts->TraditionalCPP = false;

  auto &frontend_opts = invocation.getFrontendOpts();
  frontend_opts.StatsFile.clear();
  frontend_opts.OverrideRecordLayoutsFile.clear();
  frontend_opts.ASTDumpFilter.clear();

  // TODO(pag): Eventually support? A better way would be to load them into
  //            `Compiler` or into `CompileCommand`.
  frontend_opts.Plugins.clear();
  frontend_opts.ActionName.clear();
  frontend_opts.PluginArgs.clear();
  frontend_opts.AddPluginActions.clear();

  // Go check that we've got an input file, them initialize the source manager
  // with the first input file.
  auto &input_files = frontend_opts.Inputs;
  if (input_files.empty()) {
    err << "No input file in compilation command: " << argv.Join();
    return err.str();

  // There should only be one input files, as we're dealing with `-cc1`
  // commands, not frontend commands.
  } else if (1u < input_files.size()) {
    err << "Too many input files in compilation command: " << argv.Join();
    return err.str();
  }

  auto &invocation_target = ci.getTarget();

  // Create TargetInfo for the other side of CUDA and OpenMP compilation.
  if ((lang_opts->CUDA || lang_opts->OpenMPIsDevice) &&
      !frontend_opts.AuxTriple.empty()) {
    auto aux_target = std::make_shared<clang::TargetOptions>();
    aux_target->Triple = llvm::Triple::normalize(frontend_opts.AuxTriple);
    aux_target->HostTriple = invocation_target.getTriple().str();
    ci.setAuxTarget(
        clang::TargetInfo::CreateTargetInfo(*diagnostics_engine, aux_target));
  }

  invocation_target.adjust(*lang_opts);
  invocation_target.adjustTargetOptions(ci.getCodeGenOpts(),
                                        ci.getTargetOpts());

  if (auto aux_target = ci.getAuxTarget(); aux_target) {
    invocation_target.setAuxTarget(aux_target);
  }

  // Clear out any dependency file stuff. Sometimes the paths for the dependency
  // files are incorrect, and that shouldn't hold up a build.
  auto &dep_opts = ci.getDependencyOutputOpts();
  dep_opts = clang::DependencyOutputOptions();

  ci.createPreprocessor(clang::TU_Complete);
  auto &pp = ci.getPreprocessor();
  auto &sm = ci.getSourceManager();

  ast->orig_source_pp = ci.getPreprocessorPtr();

  // TODO(pag): Eventually add `PPCallbacks` so that we can capture macro
  //            definitions as tokens.
  auto file_tracker_ptr = new ParsedFileTracker(
      pp, sm, *lang_opts, impl->file_manager, WorkingDirectory(), ast.get());
  {
    std::unique_ptr<clang::PPCallbacks> file_tracker(file_tracker_ptr);
    pp.addPPCallbacks(std::move(file_tracker));
  }

  pp.SetCommentRetentionState(true /* KeepComments */,
                              true /* KeepMacroComments */);

  pp.getBuiltinInfo().initializeBuiltins(pp.getIdentifierTable(), *lang_opts);
  pp.setPragmasEnabled(true);

  // Picks up on the pre-processor and stuff.
  ci.InitializeSourceManager(input_files[0]);
  PreprocessCode(*ast, ci, pp);

  // If we didn't end up tracking any files then something is seriously wrong.
  assert(!ast->id_to_file.empty());

  file_tracker_ptr->Clear();

  // Replace the main source file with the preprocessed file.
  const auto main_file_name = input_files[0].getFile().str();
  auto added_file = mem_vfs->addFile(
      "<pasta-input>", std::numeric_limits<time_t>::max(),
      llvm::MemoryBuffer::getMemBuffer(ast->preprocessed_code,
                                       "<pasta-input>", false),
      llvm::None, llvm::None, llvm::sys::fs::file_type::regular_file,
      llvm::sys::fs::perms::all_read);

  if (!added_file) {
    err << "Could not add overlay file for '" << main_file_name << "'";
    return err.str();
  }

  const auto file_entry = fm->getFile("<pasta-input>");
  if (!file_entry) {
    err << "Could not add overlay file entry for file '"
        << main_file_name << "'";
    return err.str();
  }

  const auto prev_main_file_id = sm.getMainFileID();
  const auto main_file_id = sm.createFileID(
      *file_entry, clang::SourceLocation(), clang::SrcMgr::C_User);

  if (!main_file_id.isValid()) {
    err << "Failed to create a valid ID for the overlay file entry for file '"
        << main_file_name << "'";
    return err.str();
  }

  if (prev_main_file_id == main_file_id) {
    err << "Source manager ID for the overlay file '"
        << main_file_name << "' is the same as the original";
    return err.str();
  }

  // Disable `#include`s as we'll only be dealing with a single, already
  // pre-processed file from now on.
  pp_options.SingleFileParseMode = true;
  sm.setMainFileID(main_file_id);

  ci.createPreprocessor(clang::TU_Complete);
  ci.createASTContext();
  ci.createSema(clang::TU_Complete, nullptr);

  //auto &source_manager = ci.getSourceManager();
  auto &ast_context = ci.getASTContext();
  auto &ast_consumer = ci.getASTConsumer();
  auto &sema = ci.getSema();
  auto &pp2 = ci.getPreprocessor();
  ast->token_per_line_pp = ci.getPreprocessorPtr();

  std::unique_ptr<clang::Parser> parser(
      new clang::Parser(pp2, sema, false /* SkipFunctionBodies */));

  pp2.getBuiltinInfo().initializeBuiltins(pp2.getIdentifierTable(), *lang_opts);
  pp2.setPreprocessedOutput(false);
  pp2.setPragmasEnabled(true);
  pp2.EnterMainSourceFile();
  parser->Initialize();

  clang::Parser::DeclGroupPtrTy a_decl;
  for (auto at_eof = parser->ParseFirstTopLevelDecl(a_decl); !at_eof;
       at_eof = parser->ParseTopLevelDecl(a_decl)) {

    // Parsing a dangling top-level semicolon will result in a null declaration.
    if (a_decl && !ast_consumer.HandleTopLevelDecl(a_decl.get())) {
      break;
    }
  }

  // Process any TopLevelDecls generated by #pragma weak.
  for (auto decl : sema.WeakTopLevelDecls()) {
    if (decl && !ast_consumer.HandleTopLevelDecl(clang::DeclGroupRef(decl))) {
      break;
    }
  }

  // Finalize any leftover instantiations.
  sema.PerformPendingInstantiations(false);

  if (diagnostics_engine->hasUncompilableErrorOccurred() ||
      diagnostics_engine->hasFatalErrorOccurred()) {
    if (diag->error.empty()) {
      err << "A clang diagnostic or uncompilable error was produced when trying"
          << " to get an AST: " << argv.Join();
      return err.str();

    } else {
      err << "A clang diagnostic or uncompilable error was produced when trying"
          << " to get an AST due to error: " << diag->error;
    }
  }

  ast->real_fs = std::move(real_vfs);
  ast->overlay_fs = std::move(overlay_vfs);
  ast->mem_fs = std::move(mem_vfs);
  ast->fm = std::move(fm);
  ast->tu = ast_context.getTranslationUnitDecl();
  ast->printing_policy.reset(new clang::PrintingPolicy(*lang_opts));

  // Initialize the policy to print tokens as closely as possible to what is
  // written in the original code.
  if (auto pp = ast->printing_policy.get()) {
    pp->ConstantArraySizeAsWritten = true;
    pp->ConstantsAsWritten = true;
    pp->PrintCanonicalTypes = false;
    pp->PrintInjectedClassNameWithArguments = false;
    pp->SuppressUnwrittenScope = true;
    pp->AnonymousTagLocations = false;
  }

  return ASTImpl::AlignTokens(std::move(ast));
}

}  // namespace pasta
