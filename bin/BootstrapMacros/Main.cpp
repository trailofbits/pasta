/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#ifndef PASTA_IN_BOOTSTRAP
#  error "`PASTA_IN_BOOTSTRAP` must be defined."
#endif

#include <pasta/AST/AST.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <iostream>
#include <memory>

#include "MacroGenerator.h"
#include "BootstrapConfig.h"

static int GenerateBindings(pasta::AST ast) {
  auto &ast_context = ast.UnderlyingAST();
  pasta::MacroGenerator visitor(&ast_context);
  visitor.TraverseAST(ast_context);
  return EXIT_SUCCESS;
}

int main(void) {

  const std::vector<std::string> clang_command{
      kCxxPath,
      "-x", "c++",
      "-c", kMacroGeneratorPath,
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
    std::cerr << "Can't create compile jobs " << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << "AST generation failed " << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    }

    return GenerateBindings(maybe_ast.TakeValue());
  }

  std::cerr << "No ASTs were produced." << std::endl;
  return EXIT_FAILURE;
}
