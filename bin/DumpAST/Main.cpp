/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Error.h>
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
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
    }
    PopIndent();
    os << indent << "}\n";
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitRecordDecl(const pasta::RecordDecl &decl) final {
    os << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitTypedefDecl(const pasta::TypedefDecl &decl) final {
    os << indent << decl.KindName() << "\n";
  }

  void VisitDecl(const pasta::Decl &decl) final {
    os << indent << decl.KindName() << "\n";
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

  const auto cwd = std::filesystem::current_path().string();

  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(pasta::TargetLanguage::kCXX);

  if (pasta::IsError(maybe_compiler)) {
    std::cerr << pasta::ErrorString(maybe_compiler) << std::endl;
    return EXIT_FAILURE;
  }

  const auto compiler = std::move(*maybe_compiler);
  //auto maybe_command = compiler.CreateCommandForFile(argv[1], cwd);
  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(args, cwd);

  if (pasta::IsError(maybe_command)) {
    std::cerr << pasta::ErrorString(maybe_command) << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = std::move(*maybe_command);
  auto maybe_jobs = compiler.CreateJobsForCommand(command);

  if (pasta::IsError(maybe_jobs)) {
    std::cerr << pasta::ErrorString(maybe_jobs) << std::endl;
    return EXIT_FAILURE;
  }

  const auto jobs = std::move(*maybe_jobs);
  for (const auto &job : jobs) {
    auto maybe_ast = job.Run();
    if (pasta::IsError(maybe_ast)) {
      std::cerr << pasta::ErrorString(maybe_ast) << std::endl;
      return EXIT_FAILURE;
    } else {
      DumpAST(std::move(*maybe_ast));
    }
  }

  return EXIT_SUCCESS;
}
