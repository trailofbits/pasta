/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

class ASTDumper final : public pasta::DeclVisitor {
 public:
  virtual ~ASTDumper(void) = default;

  explicit ASTDumper(const pasta::AST &ast_, std::ostream &os_)
      : ast(ast_),
        os(os_) {}

  pasta::AST ast;
  std::string indent;
  std::ostream &os;

  void PushIndent(void) {
    indent += "  ";
  }

  void PopIndent(void) {
    indent.resize(indent.size() - 2);
  }

  void VisitDeclContext(const pasta::DeclContext &dc) {
    os << " {\n";
    PushIndent();
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
      Accept(decl);
    }
    PopIndent();
    os << indent << "}\n";
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitTagDecl(const pasta::TagDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    os << indent << decl.KindName();

    auto loc = decl.Token();
    if (auto file_loc = loc.FileLocation()) {
      auto file = pasta::File::Containing(*file_loc);
      os << ' ' << file.Path().generic_string() << ':'
         << file_loc->Line() << ':' << file_loc->Column();
    }
    os << "\n";
  }
};

static void DumpAST(pasta::AST ast) {
  ASTDumper dumper(ast, std::cerr);
  dumper.Accept(ast.TranslationUnit());
}

int main(int argc, char *argv[]) {
  if (2 > argc) {
    std::cerr << "Usage: " << argv[0] << " COMPILE_COMMAND..."
              << std::endl;
    return EXIT_FAILURE;
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = maybe_command.TakeValue();
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      return EXIT_SUCCESS;
      DumpAST(maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}
