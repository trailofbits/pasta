/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/AST.h>
#include <pasta/Util/Error.h>

#include <functional>
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
  Compiler(Compiler &&) noexcept;
  Compiler &operator=(Compiler &&) noexcept;

  ~Compiler(void);

  // Name/variant of this compiler.
  CompilerName Name(void) const;

  // Target language for this compiler.
  enum TargetLanguage TargetLanguage(void) const;

  // Path to the executable.
  std::string_view ExecutablePath(void) const;

  // Resource directory of the compiler, i.e. where you find compiler-specific
  // header files.
  std::string_view ResourceDirectory(void) const;

  // Directory to treat as the system root. Useful for cross-compilation
  // toolchains.
  std::string_view SystemRootDirectory(void) const;

  // Invoke a callback `cb` for each system include directory. Think `-isystem`.
  void
  ForEachSystemIncludeDirectory(std::function<void(std::string_view)> cb) const;

  // Invoke a callback `cb` for each user include directory. Think `-I` or
  // `-iquote`.
  void
  ForEachUserIncludeDirectory(std::function<void(std::string_view)> cb) const;

  // Invoke a callback `cb` for each user include directory. Think `-iframework`
  // or `iframeworkwithsysroot`.
  void
  ForEachFrameworkDirectory(std::function<void(std::string_view)> cb) const;

  // Create a "host" compiler instance, i.e. a compiler instance based on the
  // compiler used to compile this library.
  static llvm::Expected<Compiler> CreateHostCompiler(enum TargetLanguage lang);

  // Create a compiler from a version string.
  //
  // NOTE(pag): The `working_dir` is the directory in which the compiler
  //            invocation was made.
  static llvm::Expected<Compiler>
  Create(CompilerName name, enum TargetLanguage lang,
         std::string_view compiler_path, std::string_view version_info,
         std::string_view working_dir);

  // Create a compile command for a single file in a working directory.
  llvm::Expected<CompileCommand>
  CreateCommandForFile(std::string_view file_name,
                       std::string_view working_dir) const;

 private:
  friend class CompileCommand;
  friend class CompileJob;

  Compiler(void) = delete;
  Compiler(const Compiler &) = delete;
  Compiler &operator=(const Compiler &) = delete;

  Compiler(CompilerImpl *impl_);

  CompilerImpl *impl;
};

}  // namespace pasta
