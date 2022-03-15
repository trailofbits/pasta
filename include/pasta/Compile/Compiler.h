/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/AST.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/Result.h>

#include <functional>
#include <memory>
#include <string_view>
#include <vector>

namespace pasta {

enum class CompilerName : unsigned {
  kUnknown = 0,
  kClang = 1,
  kAppleClang = 2,
  kClangCL = 3,
  kCL = 4,
  kGNU = 5,
};

enum class IncludePathLocation : unsigned {
  kAbsolute,
  kSysrootRelative
};

// TODO(pag): Eventually support specific versions of the languages?
enum class TargetLanguage : unsigned { kC, kCXX };

class ArgumentVector;
class CompileCommand;
class CompileJob;
class CompilerImpl;

class IncludePath {
 private:
  std::filesystem::path path;
  IncludePathLocation location;

 public:
  inline IncludePath(std::filesystem::path path_, IncludePathLocation location_)
      : path(std::move(path_)),
        location(location_) {}

  inline std::filesystem::path Path(void) const noexcept {
    return path;
  }

  inline IncludePathLocation Location(void) const noexcept {
    return location;
  }
};

// Abstract compiler interface.
class Compiler {
 public:
  Compiler(const Compiler &) = default;
  Compiler &operator=(const Compiler &) = default;
  Compiler(Compiler &&) noexcept = default;
  Compiler &operator=(Compiler &&) noexcept = default;

  ~Compiler(void);

  // Name/variant of this compiler.
  CompilerName Name(void) const;

  // Target language for this compiler.
  enum TargetLanguage TargetLanguage(void) const;

  // Return the default target triple for the host.
  static std::string HostTargetTriple(void) noexcept;

  // Return the default target triple for this compiler.
  std::string TargetTriple(void) const noexcept;

  // Path to the executable.
  std::filesystem::path ExecutablePath(void) const;

  // Resource directory of the compiler, i.e. where you find compiler-specific
  // header files.
  std::filesystem::path ResourceDirectory(void) const;

  // Directory to treat as the system root. Useful for cross-compilation
  // toolchains.
  std::filesystem::path SystemRootDirectory(void) const;

  // Directory to treat as the system root for inclusions. Useful for cross-
  // compilation toolchains.
  std::filesystem::path SystemRootIncludeDirectory(void) const;

  // Directory where the compiler is installed.
  std::filesystem::path InstallationDirectory(void) const;

  // Return the file system associated with this compiler's paths.
  std::shared_ptr<FileSystem> FileSystem(void) const;

  // Return the file manager associated with files that will be opened and
  // read by this compiler.
  FileManager FileManager(void) const;

  // Related to `-isystem`.
  std::vector<IncludePath> SystemIncludeDirectories(void) const;

  // User include directories, think `-I` or `-iquote`.
  std::vector<IncludePath> UserIncludeDirectories(void) const;

  // System framework include directories. Think `-iframework`
  // or `iframeworkwithsysroot`.
  std::vector<IncludePath> FrameworkDirectories(void) const;

  // Create a "host" compiler instance, i.e. a compiler instance based on the
  // compiler used to compile this library.
  static Result<Compiler, std::string>
  CreateHostCompiler(class FileManager file_manager,
                     enum TargetLanguage lang);

  // Create a compiler from a version string.
  //
  // NOTE(pag): The `working_dir` is the directory in which the compiler
  //            invocation was made.
  static Result<Compiler, std::string>
  Create(class FileManager file_manager,
         std::filesystem::path compiler_path,
         std::filesystem::path working_dir,
         CompilerName name, enum TargetLanguage lang,
         std::string_view version_info,
         std::string_view version_info_fake_sysroot);

  // Create a compile command for a single file in a working directory.
  Result<CompileCommand, std::string_view>
  CreateCommandForFile(std::filesystem::path file_name,
                       std::filesystem::path working_dir) const;

  // The list of compiler jobs associated with this command.
  Result<std::vector<CompileJob>, std::string>
  CreateJobsForCommand(const CompileCommand &command) const;

 private:
  friend class CompileCommand;
  friend class CompileJob;

  Compiler(void) = delete;

  Compiler(std::shared_ptr<CompilerImpl> impl_);

  std::shared_ptr<CompilerImpl> impl;
};

}  // namespace pasta
