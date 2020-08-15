/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/Compiler.h>
#include <pasta/Python/Bindings.h>

#include <optional>

namespace pasta {
namespace py {

template <>
struct StorageType<CompilerName> {
 public:
  using Type = EnumWrapper<CompilerName, unsigned>;
};

template <>
struct StorageType<TargetLanguage> {
 public:
  using Type = EnumWrapper<TargetLanguage, unsigned>;
};

class PyCompiler : public PythonObject<PyCompiler> {
 public:
  // Tries to add the `Compiler` type to the `pasta` module.
  static bool TryAddToModule(PyObject *module);

  ~PyCompiler(void);

  DEFINE_PYTHON_ARG(target_language, TargetLanguage);
  DEFINE_PYTHON_ARG(compiler_name, CompilerName);
  DEFINE_PYTHON_ARG(compiler_path, std::string_view);
  DEFINE_PYTHON_ARG(version_info, std::string_view);
  DEFINE_PYTHON_ARG(working_dir, std::string_view);
  DEFINE_PYTHON_CONSTRUCTOR(PyCompiler, compiler_name_arg name,
                            target_language_arg lang,
                            compiler_path_arg compiler_path,
                            version_info_arg version_info,
                            working_dir_arg working_dir);

  // Name/variant of this compiler.
  unsigned Name(void);

  // Target language for this compiler.
  unsigned TargetLanguage(void);

  // Path to the executable.
  BorrowedPythonPtr<PyObject> ExecutablePath(void);

  // Resource directory of the compiler, i.e. where you find compiler-specific
  // header files.
  BorrowedPythonPtr<PyObject> ResourceDirectory(void);

  // Directory to treat as the system root. Useful for cross-compilation
  // toolchains.
  BorrowedPythonPtr<PyObject> SystemRootDirectory(void);

 private:
  std::optional<Compiler> compiler;
  SharedPythonPtr<PyObject> exe_path;
  SharedPythonPtr<PyObject> resource_dir;
  SharedPythonPtr<PyObject> sysroot_dir;
};

}  // namespace py
}  // namespace pasta
