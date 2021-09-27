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

class TypeDumper final : public pasta::TypeVisitor {
 public:

  pasta::AST ast;
  std::string indent;
  std::ostream &os;

  virtual ~TypeDumper(void) = default;

  explicit TypeDumper(const pasta::AST &ast_, std::ostream &os_)
      : ast(ast_),
        os(os_) {}

  void PushIndent(void) {
    indent += "  ";
  }

  void PopIndent(void) {
    indent.resize(indent.size() - 2);
  }

  void AcceptQualified(const pasta::Type &type) {
    auto sep = "";
    if (type.IsConstQualified()) {
      os << sep << "const";
      sep = " ";
    }
    if (type.IsRestrictQualified()) {
      os << sep << "restrict";
      sep = " ";
    }
    if (type.IsVolatileQualified()) {
      os << sep << "volatile";
      sep = " ";
    }

    return Accept(type.UnqualifiedType());
  }

  void VisitRecordType(const pasta::RecordType &type) {
    pasta::RecordDecl record = type.Decl();

    os << "record ";
    if (auto name = record.Name(); !name.empty()) {
      os << name << " ";
    }
    os << "{\n";
    PushIndent();
    for (pasta::FieldDecl field : record.Fields()) {
      pasta::Type field_type = field.Type();
      os << indent;
      if (field_type.IsQualified()) {
        AcceptQualified(field_type);
      } else {
        Accept(field_type);
      }
      os << " " << field.Name() << ";\n";
    }
    PopIndent();
    os << indent << "}";
  }
};

// Visit all structures.
class StructureFinder final : public pasta::DeclVisitor {
 private:
  TypeDumper &type_dumper;

 public:
  virtual ~StructureFinder(void) = default;

  explicit StructureFinder(TypeDumper &type_dumper_)
      : type_dumper(type_dumper_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
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

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitRecordDecl(const pasta::RecordDecl &decl) final {
    type_dumper.Accept(decl.TypeForDecl());
    type_dumper.os << "\n\n";
    VisitDeclContext(decl);
  }
};

static void DumpStructures(pasta::AST ast) {
  TypeDumper dumper(ast, std::cerr);
  StructureFinder finder(dumper);
  finder.Accept(ast.TranslationUnit());
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
  if (maybe_compiler.Failed()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
  if (maybe_cwd.Failed()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (maybe_command.Failed()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = std::move(*maybe_command);
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (maybe_jobs.Failed()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : *maybe_jobs) {
    auto maybe_ast = job.Run();
    if (maybe_ast.Failed()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      DumpStructures(*maybe_ast);
    }
  }

  return EXIT_SUCCESS;
}
