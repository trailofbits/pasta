/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <iostream>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#pragma GCC diagnostic pop

#if !defined(LLVM_CLANG_HAS_PASTA_EVENTS)

#include <pasta/Util/Compiler.h>

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace pasta {
namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, LexLevel, unsigned);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, CurTokenLexer, std::unique_ptr<clang::TokenLexer>);
}  // namespace detail

// Tracks macros.. sort of.
class LegacyMacroTracker : public clang::PPCallbacks {
 private:
  clang::Preprocessor &pp;
  clang::SourceManager &sm;

  ASTImpl * const ast;

  // What is the current file being parsed. This roughly corresponds to the
  // top of `file_id_stack` below.
  clang::FileID current_file_id;

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

  explicit LegacyMacroTracker(clang::Preprocessor &pp_,
                              clang::SourceManager &sm_,
                              ASTImpl *ast_)
      : pp(pp_),
        sm(sm_),
        ast(ast_) {
    (void) pp;
  }

  virtual ~LegacyMacroTracker(void) {}

  void Clear(void) {
    current_file_id = {};
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
      }

      // Add a dummy token signifying the end of the file.
      //
      // TODO(pag): Make it an `eof` token?
      InjectToken(sm.getLocForEndOfFile(file_id).getLocWithOffset(-1),
                  TokenRole::kEndOfFileMarker);
    }
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

    // We're lexing some macro arguments.
    auto &tok_lexer = pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, CurTokenLexer);
    if (tok_lexer) {
      return;
    }

    auto loc = macro_name.getLocation();
    assert(loc == use_range.getBegin());

    if (current_file_id.isInvalid()) {
      return;
    }

//    // Macro expansion inside of a macro, or inside of a directive.
//    auto level = pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, LexLevel);
//    if ((logical_level_0 + 1u) < level) {
//      assert(loc.isMacroID());
//      return;
//    }

    // If the macro use isn't in the current file (e.g. it is a macro being
    // expanded inside of another macro), then ignore it.
    if (!loc.isFileID()) {
      return;
    }

    assert(use_range.getEnd().isFileID());

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

}  // namespace pasta
#endif
