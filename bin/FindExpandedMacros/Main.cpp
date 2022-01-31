/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Token.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <clang/Basic/TokenKinds.h>
#include <llvm/Support/FormatVariadic.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>

static bool IsMacroExpansionStart(const pasta::Token &token) {
  return token.Role() == pasta::TokenRole::kBeginOfMacroExpansionMarker;
}

// NOTE(pag): This code shows how to re-compute macro expansions and original
//            locations from scratch, but the data is available more
//            conveniently with APIs in the `pasta::Token` class.
static void DumpExpandedMacros(pasta::AST ast) {
  auto token_range = ast.Tokens();
  auto token_it = token_range.begin();
  auto token_end = token_range.end();

  llvm::json::Array macros;

  while (token_it != token_end) {
    pasta::Token token = *token_it;

    // Either point us to the beginning of the macro expansion, or skip to
    // the next token for next iteration.
    ++token_it;

    if (IsMacroExpansionStart(token)) {

      llvm::json::Array macro_use_toks;
      llvm::json::Array macro_exp_toks;

      // PASTA inject a token that should be able to be tied back to the
      // file where the macro was used. This should represent the identifier
      // token that names the macro.
      auto maybe_macro_use = token.FileLocation();
      assert(maybe_macro_use.has_value());

      // This token is the name of the macro. We might still need to collect
      // arguments if it's a function-like macro.
      pasta::FileToken macro_use = std::move(*maybe_macro_use);
      assert(clang::tok::isAnyIdentifier(macro_use.Kind()) ||
             clang::tok::getKeywordSpelling(macro_use.Kind()));

      pasta::File file_containing_macro_use =
          pasta::File::Containing(macro_use);

      std::cerr
          << file_containing_macro_use.Path().generic_string()
          << '!' << macro_use.Line()
          << '!' << macro_use.Column() << '!' << macro_use.Data() << '\n';

      // Collect parsed tokens up until the next token with a file location.
      // This should cover the entire expansion of the macro.
      std::optional<pasta::FileToken> end_tok;
      for (; token_it != token_end;) {
        pasta::Token expansion_tok = *token_it;
        end_tok = expansion_tok.FileLocation();


        if (!end_tok) {
          if (!expansion_tok.Data().empty()) {
            macro_exp_toks.emplace_back(expansion_tok.Data());
//
            std::cerr
                << '\t' << expansion_tok.Data() << '\n';
          }

          ++token_it;

        // This next token might be the beginning of another macro, so we want
        // to be able to observe it on the next iteration of the outer `while`
        // loop.
        } else {

          std::cerr
              << "\t>>> ends at "
              << pasta::File::Containing(*end_tok).Path().generic_string()
              << ':' << end_tok->Line()
              << ':' << end_tok->Column() << '\n';
          break;
        }
      }

      pasta::FileTokenRange file_tokens = file_containing_macro_use.Tokens();
      uint64_t start_index = macro_use.Index();
      uint64_t max_index = file_tokens.Size();

      if (end_tok.has_value()) {
        pasta::File file_of_end_tok = pasta::File::Containing(*end_tok);
        assert(file_of_end_tok == file_containing_macro_use);
        max_index = end_tok->Index();
      }
      assert(start_index < max_index);

      // Collect the macro use tokens.
      std::vector<pasta::FileToken> macro_use_tokens;
      for (auto i = start_index; i < max_index; ++i) {
        if (pasta::FileToken ft = file_tokens[i]; !ft.Data().empty()) {
          macro_use_toks.emplace_back(ft.Data());
        }
      }

      llvm::json::Array expansion;
      expansion.emplace_back(std::move(macro_use_toks));
      expansion.emplace_back(std::move(macro_exp_toks));

      macros.emplace_back(std::move(expansion));

    } else if (auto ft = token.FileLocation()) {
      std::cerr
          << pasta::File::Containing(*ft).Path().generic_string()
          << ':' << ft->Line()
          << ':' << ft->Column() << ':' << ft->Data() << '\n';
    } else {
      std::cerr
          << "Token " << token.KindName() << ": " << token.Data()
          << " that isn't a file token, and not in a macro?!" << std::endl;
    }
  }

//  std::error_code ec;
//  llvm::raw_fd_ostream os("-", ec);
//  assert(!ec);
//  llvm::json::Value v(std::move(macros));
//  os << llvm::formatv("{0:2}", v);
}

int main(int argc, char *argv[]) {
  if (2 > argc) {
    std::cout << "Usage: " << argv[0] << " COMPILE_COMMAND..."
              << std::endl;
    return EXIT_FAILURE;
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cout << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cout << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cout << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = maybe_command.TakeValue();
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cout << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cout << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      DumpExpandedMacros(maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}

