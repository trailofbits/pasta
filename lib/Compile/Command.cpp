/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Command.h"

#include <pasta/Util/FileSystem.h>

#include <memory>

#include "Compiler.h"
#include "Job.h"

namespace pasta {
namespace {

static const std::string_view kErrCompileCommandTooShort{
    "Too few values in argument vector for compile command"};

static const std::string_view kErrEmptyFilePath{
    "Cannot create a compile command for a file given an empty file path"};

}  // namespace

CompileCommand::~CompileCommand(void) {}

CompileCommand::CompileCommand(std::shared_ptr<CompileCommandImpl> impl_)
    : impl(std::move(impl_)) {}

// Create a compile command for a single file in a working directory.
//
// The reason for the complexity in this function is that the Clang/LLVM linked
// against this (pasta) library may not match up perfectly with the compiler
// used to compile this library, and so we ideally want to produce compilation
// commands that are going to find the "expected" incldue files/directories.
Result<CompileCommand, std::string_view>
Compiler::CreateCommandForFile(std::filesystem::path file_name,
                               std::filesystem::path working_dir) const {

  if (file_name.empty()) {
    return kErrEmptyFilePath;
  }

  const auto &info = *impl;

  std::vector<std::string> argv;

  // Make a compiler name if we don't have an executable path.
  if (info.compiler_exe.empty()) {
    switch (info.compiler_name) {
      case CompilerName::kAppleClang:
      case CompilerName::kClang:
        switch (info.target_lang) {
          case TargetLanguage::kC: argv.emplace_back("clang"); break;
          case TargetLanguage::kCXX: argv.emplace_back("clang++"); break;
        }
        break;
      case CompilerName::kClangCL:
        argv.emplace_back("clang-cl");
        break;
      case CompilerName::kCL:
        argv.emplace_back("cl");
        break;
      case CompilerName::kGNU:
        switch (info.target_lang) {
          case TargetLanguage::kC: argv.emplace_back("gcc"); break;
          case TargetLanguage::kCXX: argv.emplace_back("g++"); break;
        }
        break;
      default:
        switch (info.target_lang) {
          case TargetLanguage::kC: argv.emplace_back("cc"); break;
          case TargetLanguage::kCXX: argv.emplace_back("c++"); break;
        }
    }

    // If we've got an install directory, then put the fake command inside it.
    if (!info.install_dir.empty()) {
      std::filesystem::path install_dir(info.install_dir);
      if (std::filesystem::is_directory(install_dir)) {
        argv.back() = (install_dir / argv.back()).generic_string();
      }
    }

  // We've got an executable path, use it. Clang's command-line parser and
  // compiler instance classes might learn info from it.
  } else {
    argv.emplace_back(info.compiler_exe);
  }

  // Force the language.
  switch (info.target_lang) {
    case TargetLanguage::kC:
      argv.emplace_back("-x");
      argv.emplace_back("c");
      argv.emplace_back("-std=c11");
      break;
    case TargetLanguage::kCXX:
      argv.emplace_back("-x");
      argv.emplace_back("c++");
      argv.emplace_back("-std=c++17");
      break;
  }

  // Add in resource directories. If for some reaosn we have more than one, then
  // add the remaining ones as system include directories.
  if (!info.resource_dir.empty()) {
    const char *opt_name = "-isystem";
    switch (info.compiler_name) {
      case CompilerName::kAppleClang:
      case CompilerName::kClang:
      case CompilerName::kClangCL:  // TODO(pag): Probably wrong.
        opt_name = "-resource-dir";
        break;
      default: break;
    }

    argv.emplace_back(opt_name);
    argv.emplace_back(info.resource_dir.generic_string());
  }

  // System root directory.
  if (!info.sysroot_dir.empty()) {
    argv.emplace_back("-isysroot");
    argv.push_back(info.sysroot_dir.generic_string());
  }

  ForEachSystemIncludeDirectory(
      [&] (const std::filesystem::path &include_path, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          argv.emplace_back("-isystem");
        } else {
          argv.emplace_back("-iwithsysroot");
        }
        argv.emplace_back(include_path.generic_string());
      });

  ForEachUserIncludeDirectory(
      [&] (const std::filesystem::path &include_path, IncludePathLocation) {
        argv.emplace_back("-I");
        argv.emplace_back(include_path);
      });

  ForEachFrameworkDirectory(
      [&] (const std::filesystem::path &include_path, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          argv.emplace_back("-iframework");
        } else {
          argv.emplace_back("-iframeworkwithsysroot");
        }
        argv.emplace_back(include_path.generic_string());
      });

  argv.emplace_back("-c");
  argv.emplace_back(file_name.generic_string());

  return CompileCommand(
      std::make_shared<CompileCommandImpl>(argv, std::move(working_dir)));
}

// Create a compile command for a single file in a working directory.
Result<CompileCommand, std::string_view>
CompileCommand::CreateFromArguments(const ArgumentVector &argv,
                                    std::filesystem::path working_dir) {
  if (!argv.Size()) {
    return kErrCompileCommandTooShort;
  } else {
    return CompileCommand(
        std::make_shared<CompileCommandImpl>(argv, std::move(working_dir)));
  }
}

// Return an argument vector associated with this compilation command.
const ArgumentVector &CompileCommand::Arguments(void) const {
  return impl->argv;
}

// Return the working directory in which this command executes.
const std::filesystem::path &CompileCommand::WorkingDirectory(void) const {
  return impl->working_dir;
}

}  // namespace pasta
