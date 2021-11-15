/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <clang/AST/Decl.h>
#include <clang/AST/Type.h>
#include <clang/AST/Stmt.h>

#include <cstdlib>
#include <fstream>
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

static void PrintTokenGraph(pasta::Decl tld) {
  auto tokens = pasta::PrintedTokenRange::Create(tld);
  if (tokens.empty()) {
    std::cerr
        << "Empty tokens for " << tld.KindName();
    if (pasta::Token loc = tld.Token()) {
      if (std::optional<pasta::FileToken> floc = loc.FileLocation()) {
        std::cerr
            << " at " << pasta::File::Containing(*floc).Path()
            << ":" << floc->Line() << ":" << floc->Column();
      }
    }
    std::cerr << std::endl;
    return;
  }

  static int x = 0;
  std::ofstream os("/tmp/tokens/" + std::to_string(x++) + ".dot");

  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  const auto a = reinterpret_cast<uintptr_t>(tld.RawDecl());

  os
      << "tokens" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";


  std::unordered_set<const pasta::PrintedTokenContext *> contexts;

  for (pasta::PrintedToken tok : tokens) {
    for (auto context = tok.RawContext(); context;
         context = pasta::PrintedTokenContext::Parent(context)) {
      contexts.insert(context.get());
    }

    os
        << "<TD port=\"t" << tok.Index() << "\">" << TokData(tok) << "</TD>";
  }

  os << "</TR></TABLE>>];\n";

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

    os
        << "c" << a << '_' << c
        << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
        << "border=\"1\"><TR><TD" << bgcolor << ">";

    if (context->decl) {
      os << context->decl->getDeclKindName();
    } else if (context->stmt) {
      os << context->stmt->getStmtClassName();
    } else if (context->type) {
      os << context->type->getTypeClassName();
    }

    os
        << "</TD></TR></TABLE>>];\n";

    if (context->parent) {

      const auto cp = reinterpret_cast<uintptr_t>(context->parent);
      os
          << "c" << a << '_' << c
          << " -> c" << a << '_' << cp
          << ";\n";
    }
  }

  for (pasta::PrintedToken tok : tokens) {
    if (auto context = tok.RawContext().get()) {
      const auto c = reinterpret_cast<uintptr_t>(context);
      os
          << "tokens" << a
          << ":t" << tok.Index() << " -> c" << a << '_' << c << ";\n";
    }
  }

  os << "}\n";
}

// Visit all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 public:
  virtual ~TLDFinder(void) = default;

  void VisitDeclContext(const pasta::DeclContext &dc) {
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
    }
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &tpl) final {
    for (pasta::VarTemplateSpecializationDecl decl : tpl.Specializations()) {
      VisitVarTemplateSpecializationDecl(decl);
    }
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &tpl) final {
    for (pasta::ClassTemplateSpecializationDecl decl : tpl.Specializations()) {
      VisitClassTemplateSpecializationDecl(decl);
    }
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &tpl) final {
    for (pasta::FunctionDecl decl : tpl.Specializations()) {
      VisitFunctionDecl(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    PrintTokenGraph(decl);
  }
};

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

  for (const auto &job : *maybe_jobs) {
    auto maybe_ast = job.Run();
    if (maybe_ast.Failed()) {
      std::cout << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      TLDFinder finder;
      finder.Accept(maybe_ast->TranslationUnit());
    }
  }


  return EXIT_SUCCESS;
}

