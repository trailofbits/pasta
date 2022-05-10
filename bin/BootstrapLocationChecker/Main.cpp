/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#ifdef PASTA_IN_BOOTSTRAP
int main(void) {
  return 1;
}
#else

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

#include "BootstrapConfig.h"

#define DECL_NAME(name) #name "Decl",
#define TYPE_NAME(name) #name "Type",
#define STR_NAME(name) #name,

static const std::unordered_set<std::string> gDeclNames{
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, STR_NAME)
};

static int GenerateFromClasses(std::vector<pasta::CXXRecordDecl> decls,
                               std::ostream &os) {

  os << "class LocationCheckerVisitor : public pasta::DeclVisitor {\n"
     << " public:\n";

  for (auto decl : decls) {
    auto decl_name = decl.Name();
    os << "  void Visit" << decl_name << "(const pasta::"
       << decl_name << " &decl) final {\n"
       << "    auto decl_range = decl.Tokens();\n"
       << "    if (decl.IsImplicit() || !decl_range.Size()) {\n"
       << "      return;\n"
       << "    }\n"
       << "    auto begin_index = decl_range.begin()->Index();\n"
       << "    auto end_index = (--decl_range.end())->Index();\n"
       << "    CHECK_LE(begin_index, end_index);\n";

    auto i = 0u;
    auto methods = decl.Methods();
    if (methods) {
      for (auto method : *methods) {
        auto meth_name = method.Name();
        if (meth_name == "Tokens") {
          continue;
        }

        auto return_type = method.ReturnType();
        auto record = return_type.AsRecordDeclaration();
        if (!record) {
          continue;
        }

        auto rname = record->Name();
        if (rname == "Token") {
          os << "    if (auto t_" << i << " = decl." << meth_name << "()) {\n"
             << "      LOG_IF(ERROR, begin_index > t_" << i << ".Index()) << \"" << decl_name << ":" << meth_name << "\";\n"
             << "      LOG_IF(ERROR, t_" << i << ".Index() > end_index) << \"" << decl_name << ":" << meth_name << "\";\n"
             << "    }\n";
          ++i;
        } else if (rname == "Tokens") {
          os << "    if (auto r_" << i << " = decl." << meth_name << "(); r_"
             << i << ".Size()) {\n"
             << "      auto r_begin_index = r_" << i << ".begin()->Index();\n"
             << "      auto r_end_index = (--r_" << i << ".end())->Index();\n"
             << "      CHECK_LE(r_begin_index, r_end_index) << \"" << decl_name << ":" << meth_name << "\";\n"
             << "      LOG_IF(ERROR, r_begin_index < begin_index) << \"" << decl_name << ":" << meth_name << "\";\n"
             << "      LOG_IF(ERROR, r_end_index > end_index) << \"" << decl_name << ":" << meth_name << "\";\n"
             << "    }\n";
          ++i;
        }
      }
    }

    os << "    this->pasta::DeclVisitor::Visit" << decl_name << "(decl);\n"
       << "  }\n";
  }

  os << "};\n\n";

  return EXIT_SUCCESS;
}

static int GenerateFromNamespaces(std::vector<pasta::NamespaceDecl> pastas,
                                  std::ostream &os) {
  std::vector<pasta::CXXRecordDecl> decls;
  for (pasta::NamespaceDecl pasta : pastas) {
    for (auto decl : pasta::DeclContext(pasta).Declarations()) {
      if (auto cls = pasta::CXXRecordDecl::From(decl);
          cls && cls->IsThisDeclarationADefinition()) {
        auto name = cls->Name();
        if (gDeclNames.count(name)) {
          decls.emplace_back(std::move(*cls));
        }
      }
    }
  }

  if (decls.empty()) {
    std::cerr << "Could not locate any declarations.\n";
    return EXIT_FAILURE;

  } else {
    return GenerateFromClasses(std::move(decls), os);
  }
}

static int Generate(pasta::TranslationUnitDecl tu, std::ostream &os) {
  std::vector<pasta::NamespaceDecl> pastas;
  for (auto decl : pasta::DeclContext(tu).Declarations()) {
    if (auto ns = pasta::NamespaceDecl::From(decl);
        ns && ns->Name() == "pasta") {
      pastas.emplace_back(std::move(*ns));
    }
  }
  if (pastas.empty()) {
    std::cerr << "Unable to locate 'pasta' namespace.\n";
    return EXIT_FAILURE;
  } else {
    return GenerateFromNamespaces(std::move(pastas), os);
  }
}

int main(void) {

  const std::vector<std::string> clang_command{
      kCxxPath,
      "-x", "c++",
      "-c", __FILE__,
      "-o", "/dev/null",
      "-std=c++17",
      "-isystem", kPastaBinaryPath,
      "-isystem", kPastaIncludeSourcePath,
      "-isystem", kVcpkgIncludePath
  };

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

  const pasta::ArgumentVector args(clang_command);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(
      maybe_command.TakeValue());
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    }

    return Generate(maybe_ast.TakeValue().TranslationUnit(), std::cout);
  }

  std::cerr << "No ASTs were produced." << std::endl;
  return EXIT_FAILURE;
}

#endif  // PASTA_IN_BOOTSTRAP
