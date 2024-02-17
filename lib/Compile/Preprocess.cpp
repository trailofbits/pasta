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

#define PASTA_DEBUG_RUN 0

#if PASTA_DEBUG_RUN
# include <fcntl.h>
# include <unistd.h>
#endif

namespace pasta {

// Pre-process the code. This does a few things:
//
//    1)  Record all tokens produced as outputs from the preprocessor.
//    2)  Read out the data of each of the non-empty, non-whitespace, non-
//        comment tokens, and dump them into a buffer,
//        `impl.parsed_tokens.Data()`. Thus, we will have Clang re-preprocess
//        this new buffer, and then we'll be able to associated back to original
//        tokens.
void PreprocessCode(ASTImpl &impl, clang::CompilerInstance &ci,
                    clang::Preprocessor &pp) {
  clang::SourceManager &source_manager = ci.getSourceManager();
  clang::LangOptions &lang_opts = ci.getLangOpts();

  std::string tok_data;

  pp.EnterMainSourceFile();

  clang::Token tok;
  for (;;) {
    pp.Lex(tok);

    // NOTE(pag): We don't need to inject a token here because the
    //            `ParsedFileTracker` will inject the end of file token for
    //            us when the `FileChanged` callback happens.
    if (tok.is(clang::tok::eof)) {
      break;
    }

    clang::SourceLocation tok_loc = tok.getLocation();

    // It's a macro expansion token. We will already have a copy of this token
    // as the most recently added token, so we need to transfer its data to
    // the code to be parsed, rather than the backup data area.
    if (tok_loc.isMacroID()) {
      impl.parsed_tokens.AppendMacroToken(impl.macro_tokens, tok);
    
    // It's a file token.    
    } else if (tok_loc.isFileID()) {
      tok_data.clear();
      (void) TryReadRawToken(source_manager, lang_opts, tok, &tok_data);
      SkipLeadingWhitespace(tok, tok_loc, tok_data);
      SkipTrailingWhitespace(tok_data);
      impl.parsed_tokens.AppendFileToken(tok_data, tok);

    } else {
      assert(tok_loc.isValid());
    }
  }

  pp.EndSourceFile();  // Will trigger a call to `EndOfMainFile`.

#if PASTA_DEBUG_RUN
  // NOTE(pag): If there's a compiler error that "shouldn't happen," then
  //            enabling the below code can help diagnose it.
  auto fd = open("/tmp/source.cpp", O_TRUNC | O_CREAT | O_WRONLY, 0666);
  auto parsed_data = impl.parsed_tokens.Data();
  write(fd, parsed_data, parsed_data.size());
  close(fd);
#endif  // PASTA_DEBUG_RUN
}

}  // namespace pasta
