/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compiler.h"

#include <llvm/TargetParser/Host.h>
#include <pasta/Util/FileSystem.h>

namespace pasta {

// Get the file system used by a compiler.
std::shared_ptr<FileSystem> FileSystem::From(const Compiler &compiler) {
  return compiler.impl->file_manager.FileSystem();
}

// Return the file manager associated with a compiler.
FileManager FileManager::From(const Compiler &compiler) {
  return compiler.impl->file_manager;
}

Compiler::~Compiler(void) {}

Compiler::Compiler(std::shared_ptr<CompilerImpl> impl_)
    : impl(std::move(impl_)) {}

// Name/variant of this compiler.
CompilerName Compiler::Name(void) const {
  return impl->compiler_name;
}

// Target language for this compiler.
::pasta::TargetLanguage Compiler::TargetLanguage(void) const {
  return impl->target_lang;
}

std::string Compiler::HostTargetTriple(void) noexcept {
  return llvm::sys::getDefaultTargetTriple();
}

// Return the default target triple for this compiler.
std::string Compiler::TargetTriple(void) const noexcept {
  return impl->triple;
}

// Path to the executable.
std::filesystem::path Compiler::ExecutablePath(void) const {
  return impl->compiler_exe;
}

// Resource directory of the compiler, i.e. where you find compiler-specific
// header files.
std::filesystem::path Compiler::ResourceDirectory(void) const {
  return impl->resource_dir;
}

// Directory to treat as the system root. Useful for cross-compilation
// toolchains.
std::filesystem::path Compiler::SystemRootDirectory(void) const {
  return impl->sysroot_dir;
}

// Directory to treat as the system root for inclusions. Useful for cross-
// compilation toolchains.
std::filesystem::path Compiler::SystemRootIncludeDirectory(void) const {
  return impl->isysroot_dir;
}

// Directory where the compiler is installed.
std::filesystem::path Compiler::InstallationDirectory(void) const {
  return impl->install_dir;
}

// Invoke a callback `cb` for each system include directory. Think `-isystem`.
std::vector<IncludePath> Compiler::SystemIncludeDirectories(void) const {
  return impl->system_includes;
}

// Invoke a callback `cb` for each user include directory. Think `-I` or
// `-iquote`.
std::vector<IncludePath> Compiler::UserIncludeDirectories(void) const {
  return impl->user_includes;
}

// Invoke a callback `cb` for each user include directory. Think `-iframework`
// or `iframeworkwithsysroot`.
std::vector<IncludePath> Compiler::FrameworkDirectories(void) const {
  return impl->frameworks;
}

}  // namespace pasta
