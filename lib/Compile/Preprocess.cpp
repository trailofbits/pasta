/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <fcntl.h>
#include <string>
#include <string_view>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

#include "../AST/AST.h"

namespace pasta {
namespace {

static void FixupTokData(std::string_view tok_data,
                         std::string &fixed_tok_data) {
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
}

}  // namespace

// Pre-process the code. This does a few things:
//
//    1)  Record all tokens produced as outputs from the preprocessor.
//    2)  Read out the data of each of the non-empty, non-whitespace, non-
//        comment tokens, and dump them into a buffer, `impl.preprocessed_code`.
//        This buffer will have one line for each origin preprocessed token.
//        Thus, we will have Clang re-preprocess this new buffer, and then we'll
//        be able to associated back to original tokens by using the line number
//        of the updated token.
void PreprocessCode(ASTImpl &impl, clang::CompilerInstance &ci,
                    clang::Preprocessor &pp) {
  clang::SourceManager &source_manager = ci.getSourceManager();
  clang::LangOptions &lang_opts = ci.getLangOpts();

  llvm::raw_string_ostream os(impl.preprocessed_code);
  llvm::raw_string_ostream backup_os(impl.backup_token_data);

  std::string tok_data;
  std::string fixed_tok_data;

  pp.EnterMainSourceFile();

  // NOTE(pag): The `ParsedFileTracker` emits a token for entering files, so
  //            there will be one token already representing entering the main
  //            source file.
  unsigned &num_lines = impl.num_lines;
  std::vector<TokenImpl> &tokens = impl.tokens;

  clang::Token tok;
  std::optional<TokenImpl> end_of_macro_tok;
  for (;;) {

    // Check that we're maintaining our key invariant, which is that tokens
    // match up with line numbers.
    assert(num_lines == tokens.size());

    pp.Lex(tok);

    // NOTE(pag): We don't need to inject a token here because the
    //            `ParsedFileTracker` will inject the end of file token for
    //            us when the `FileChanged` callback happens.
    if (tok.is(clang::tok::eof)) {
      break;
    }

    // The end of an expansion is tracked by the patched macro tracker, but the
    // last outputted token really comes before the end marker, so we always
    // want to remove it.
    if (tokens.back().Role() == TokenRole::kEndOfMacroExpansionMarker) {
      end_of_macro_tok = std::move(tokens.back());
      assert(impl.preprocessed_code.back() == '\n');
      tokens.pop_back();
      impl.preprocessed_code.pop_back();
      --num_lines;
      assert(tokens.back().HasMacroRole());
    } else {
      end_of_macro_tok.reset();
    }

    clang::SourceLocation tok_loc = tok.getLocation();
    assert(tok_loc.isValid());

    tok_data.clear();
    (void) TryReadRawToken(source_manager, lang_opts, tok, &tok_data);
    SkipLeadingWhitspace(tok, tok_loc, tok_data);

    // It's a macro expansion token. We will already have a copy of this token
    // as the most recently added token, so we need to transfer its data to
    // the code to be parsed, rather than the backup data area.
    if (tok_loc.isMacroID()) {
      TokenImpl &prev_tok = tokens.back();

      assert(prev_tok.Role() == TokenRole::kIntermediateMacroExpansionToken);

      // Remove the `\n` that was in place for the macro expansion token, then
      // add in the proper data in place of it.
      assert(impl.preprocessed_code.back() == '\n');
      impl.preprocessed_code.pop_back();

      // NOTE(pag): The `prev_tok.Location()` isn't really sensibly comparable
      //            to `tok_loc` because of how `PatchedMacroTracker`s
      //            `FixupDerivedLocations` method overloads too many meanings
      //            into `TokenImpl::opaque_source_loc`.
      assert(prev_tok.Kind() == clang::tok::unknown);
      assert(tok_data == prev_tok.Data(impl));

      // We want to convert the intermediate macro expansion token into a
      // final macro expansion token, which means migrating its data to
      // `impl.preprocessed_code`. As an intermediate macro expansion token,
      // it is represented as a blank newline in `impl.preprocessed_code`, but
      // now we want to represent it as the whole code. But that means that if
      // the token has any embedded newlines, e.g. a string literal using line
      // continuations (`\`) to span multiple lines (this happens in the Linux
      // kernel) then we'll need to fixup the token.
      auto needs_newline_fixup = false;
      for (auto ch : tok_data) {
        if (ch == '\n' || ch == '\r') {
          needs_newline_fixup = true;
          break;
        }
      }

      prev_tok.kind = static_cast<TokenKindBase>(tok.getKind());
      prev_tok.role = static_cast<TokenKindBase>(
          TokenRole::kFinalMacroExpansionToken);
      prev_tok.data_len = static_cast<uint32_t>(tok_data.size());

      if (needs_newline_fixup) {
        backup_os.flush();

        prev_tok.data_offset = static_cast<TokenDataOffset>(
            -static_cast<ssize_t>(impl.backup_token_data.size()));

        backup_os << tok_data;
        FixupTokData(tok_data, fixed_tok_data);
        os << fixed_tok_data << '\n';

      } else {
        prev_tok.data_offset = static_cast<TokenDataOffset>(
            impl.preprocessed_code.size());
        os << tok_data << '\n';
      }


      // Put the macro ending marker back on. If we don't put it back on, then
      // `PatchedMacroTracker::CloseUnclosedExpansion` will go and re-inject it,
      // which will re-run `PatchedMacroTracker::FixupDerivedLocations` on
      // already fixed-up locations.
      if (end_of_macro_tok) {
        ++num_lines;
        os << '\n';
        tokens.push_back(std::move(end_of_macro_tok.value()));
        end_of_macro_tok.reset();
      }

      continue;
    }

    // The last token was the "true" ending of the macro token, put it back in.
    if (end_of_macro_tok) {
      ++num_lines;
      os << '\n';
      tokens.push_back(std::move(end_of_macro_tok.value()));
      end_of_macro_tok.reset();
    }

    // It's a file token, we need to parse it.
    assert(tok_loc.isFileID());

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
                               tok_data.size(), TokenRole::kFileToken);
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
      impl.AppendToken(tok, impl.preprocessed_code.size(), tok_data.size(),
                       TokenRole::kFileToken);
      os << tok_data << '\n';
      os.flush();
      ++num_lines;
      continue;
    }

    // The token data read does have new lines; we need to fix it up.
    // The token needs to be modified somehow, so add it to our backups.
    backup_os.flush();
    impl.AppendBackupToken(tok, impl.backup_token_data.size(), tok_data.size(),
                           TokenRole::kFileToken);
    backup_os << tok_data;
    FixupTokData(tok_data, fixed_tok_data);
    os << fixed_tok_data << '\n';
    os.flush();
    ++num_lines;
  }

  pp.EndSourceFile();

  os.flush();

  // For some reason Clang doesn't invoke the `ExitFile` thing for the main
  // file.
  if (tokens.back().Kind() != clang::tok::eof) {

    // We didn't get an `ExitFile`.
    if (tokens.back().Role() != TokenRole::kEndOfFileMarker) {
      auto loc = source_manager.getLocForEndOfFile(
          source_manager.getMainFileID());
      impl.AppendMarker(loc,
                        TokenRole::kEndOfFileMarker);
    }
    tokens.back().kind = static_cast<TokenKindBase>(clang::tok::eof);
  }

#if PASTA_DEBUG_RUN
  // NOTE(pag): If there's a compiler error that "shouldn't happen," then
  //            enabling the below code can help diagnose it.
  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
  write(fd, impl.preprocessed_code.data(), impl.preprocessed_code.size());
  close(fd);
#endif  // PASTA_DEBUG_RUN
}

}  // namespace pasta
