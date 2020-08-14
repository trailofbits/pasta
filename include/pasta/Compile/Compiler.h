/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/AST.h>
#include <pasta/Util/Error.h>

#include <memory>
#include <string_view>

namespace clang {
class FrontendInputFile;
}  // namespace clang
namespace pasta {

class ArgumentVector;

enum class CompilerName : unsigned {
  kAppleClang,
  kClangCL,
  kClang,
  kGNU,
  kMinGW,
  kCL
};

enum class TargetLanguage : unsigned { kC, kCXX };

class CompileCommand;
class CompileJob;
class CompilerImpl;

// Abstract compiler interface.
class Compiler {
 public:
  Compiler(Compiler &&) noexcept = default;

  ~Compiler(void);

  // Create a "host" compiler instance, i.e. a compiler instance based on the
  // compiler used to compile this library.
  static llvm::Expected<Compiler> CreateHostCompiler(TargetLanguage lang);

  // Create a compiler from a version string.
  //
  // NOTE(pag): The `working_dir` is the directory in which the compiler
  //            invocation was made.
  static llvm::Expected<Compiler>
  Create(CompilerName name, TargetLanguage lang, std::string_view compiler_path,
         std::string_view version_info, std::string_view working_dir);

  // Run a backend compilation job and returns the AST or the first error.
  llvm::Expected<AST> Run(const CompileJob &job) const;

  // Create one or more compile jobs from a

 private:
  friend class CompileCommand;
  friend class CompileJob;

  Compiler(const Compiler &) = delete;
  Compiler &operator=(const Compiler &) = delete;
  Compiler &operator=(Compiler &&) noexcept = delete;

  Compiler(CompilerImpl *impl_);

  std::unique_ptr<CompilerImpl> impl;
};

}  // namespace pasta
