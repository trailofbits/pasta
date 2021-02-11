/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Compile/AST.h>
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

static int GenerateBindings(pasta::AST ast, const char *out_dir) {

  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  if (3 > argc) {
    std::cerr << "Usage: " << argv[0] << " OUTPUT_DIR COMPILE_COMMAND..."
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
  const pasta::ArgumentVector args(argc - 2, &argv[2]);
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
    }

    return GenerateBindings(std::move(*maybe_ast), argv[1]);
  }

  std::cerr << "No ASTs were produced." << std::endl;
  return EXIT_FAILURE;
}
