/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <clang/AST/Decl.h>
#include <clang/AST/Type.h>
#include <clang/AST/Stmt.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>

static std::string TokData(pasta::PrintedToken tok) {
  std::stringstream ss;
  for (auto ch : tok.Data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void PrintTokenGraph(pasta::Decl tld, pasta::PrintedTokenRange tokens) {
  const auto a = reinterpret_cast<uintptr_t>(tld.RawDecl());

  std::cout
      << "tokens" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";


  std::unordered_set<const pasta::PrintedTokenContext *> contexts;

  for (pasta::PrintedToken tok : tokens) {
    for (auto context = tok.RawContext(); context;
         context = pasta::PrintedTokenContext::Parent(context)) {
      contexts.insert(context.get());
    }

    std::cout
        << "<TD port=\"t" << tok.Index() << "\">" << TokData(tok) << "</TD>";
  }

  std::cout << "</TR></TABLE>>];\n";

  for (const pasta::PrintedTokenContext *context : contexts) {
    auto bgcolor = "";
    if (context->decl) {
      bgcolor = " bgcolor=\"antiquewhite\"";
    } else if (context->stmt) {
      bgcolor = " bgcolor=\"aquamarine\"";
    } else if (context->type) {
      bgcolor = " bgcolor=\"cadetblue1\"";
    }

    const auto c = reinterpret_cast<uintptr_t>(context);

    std::cout
        << "c" << a << '_' << c
        << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
        << "border=\"1\"><TR><TD" << bgcolor << ">";

    if (context->decl) {
      std::cout << context->decl->getDeclKindName();
    } else if (context->stmt) {
      std::cout << context->stmt->getStmtClassName();
    } else if (context->type) {
      std::cout << context->type->getTypeClassName();
    }

    std::cout
        << "</TD></TR></TABLE>>];\n";

    if (context->parent) {

      const auto cp = reinterpret_cast<uintptr_t>(context->parent);
      std::cout
          << "c" << a << '_' << c
          << " -> c" << a << '_' << cp
          << ";\n";
    }
  }

  for (pasta::PrintedToken tok : tokens) {
    if (auto context = tok.RawContext().get()) {
      const auto c = reinterpret_cast<uintptr_t>(context);
      std::cout
          << "tokens" << a
          << ":t" << tok.Index() << " -> c" << a << '_' << c << ";\n";
    }
  }
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
  if (maybe_compiler.Failed()) {
    std::cout << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
  if (maybe_cwd.Failed()) {
    std::cout << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (maybe_command.Failed()) {
    std::cout << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = std::move(*maybe_command);
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (maybe_jobs.Failed()) {
    std::cout << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  std::cout
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  for (const auto &job : *maybe_jobs) {
    auto maybe_ast = job.Run();
    if (maybe_ast.Failed()) {
      std::cout << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      auto tu = maybe_ast->TranslationUnit();
      pasta::DeclContext dc(tu);
      for (pasta::Decl decl : dc.Declarations()) {
        PrintTokenGraph(decl, pasta::PrintedTokenRange::Create(decl));
      }
    }
  }

  std::cout << "}\n";

  return EXIT_SUCCESS;
}

