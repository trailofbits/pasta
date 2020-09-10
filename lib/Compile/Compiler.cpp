/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compiler.h"

#include <filesystem>

namespace pasta {

Compiler::Compiler(Compiler &&that) noexcept : impl(that.impl) {
  that.impl = nullptr;
}

Compiler &Compiler::operator=(Compiler &&that) noexcept {
  std::swap(impl, that.impl);
  return *this;
}

Compiler::~Compiler(void) {
  if (impl) {
    delete impl;
  }
}

Compiler::Compiler(CompilerImpl *impl_) : impl(impl_) {}

// Name/variant of this compiler.
CompilerName Compiler::Name(void) const {
  return impl->compiler_name;
}

// Target language for this compiler.
::pasta::TargetLanguage Compiler::TargetLanguage(void) const {
  return impl->target_lang;
}

// Path to the executable.
std::string_view Compiler::ExecutablePath(void) const {
  return impl->compiler_exe;
}

// Resource directory of the compiler, i.e. where you find compiler-specific
// header files.
std::string_view Compiler::ResourceDirectory(void) const {
  return impl->resource_dir;
}

// Directory to treat as the system root. Useful for cross-compilation
// toolchains.
std::string_view Compiler::SystemRootDirectory(void) const {
  return impl->sysroot_dir;
}

// Directory where the compiler is installed.
std::string_view Compiler::InstallationDirectory(void) const {
  return impl->install_dir;
}

// Invoke a callback `cb` for each system include directory. Think `-isystem`.
void Compiler::ForEachSystemIncludeDirectory(
    std::function<void(std::string_view, IncludePathLocation)> cb) const {
  for (const auto &entry : impl->system_includes) {
    if (!entry.first.empty()) {
      cb(entry.first, entry.second);
    }
  }
}

// Invoke a callback `cb` for each user include directory. Think `-I` or
// `-iquote`.
void Compiler::ForEachUserIncludeDirectory(
    std::function<void(std::string_view, IncludePathLocation)> cb) const {
  for (const auto &entry : impl->user_includes) {
    if (!entry.first.empty()) {
      cb(entry.first, entry.second);
    }
  }
}

// Invoke a callback `cb` for each user include directory. Think `-iframework`
// or `iframeworkwithsysroot`.
void Compiler::ForEachFrameworkDirectory(
    std::function<void(std::string_view, IncludePathLocation)> cb) const {
  for (const auto &entry : impl->frameworks) {
    if (!entry.first.empty()) {
      cb(entry.first, entry.second);
    }
  }
}

}  // namespace pasta
