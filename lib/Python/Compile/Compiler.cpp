/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Compile/Compiler.h>
#include <pasta/Util/Error.h>

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(PyCompiler, Name, name);
DEFINE_PYTHON_METHOD(PyCompiler, TargetLanguage, target_language);
DEFINE_PYTHON_METHOD(PyCompiler, ExecutablePath, executable_path);
DEFINE_PYTHON_METHOD(PyCompiler, ResourceDirectory, resource_directory);
DEFINE_PYTHON_METHOD(PyCompiler, SystemRootDirectory, system_root_directory);

static PyMethodDef gCompilerMethods[] = {
    PYTHON_METHOD(name, "Return the identifier of this compiler."),
    PYTHON_METHOD(
        target_language,
        "Return the identifier of the language targeted by this compiler."),
    PYTHON_METHOD(executable_path, "Path to the executable of this compiler."),
    PYTHON_METHOD(
        resource_directory,
        "Path to the directory containing the compiler's internal header files."),
    PYTHON_METHOD(
        system_root_directory,
        "Default system root directory path for this compiler (useful for cross-compilation)."),
    PYTHON_METHOD_SENTINEL};

}  // namespace


PyCompiler::~PyCompiler(void) {}

PyCompiler::PyCompiler(compiler_name_arg name, target_language_arg lang,
                       compiler_path_arg compiler_path,
                       version_info_arg version_info,
                       working_dir_arg working_dir) {
  auto maybe_compiler = Compiler::Create(*name, *lang, *compiler_path,
                                         *version_info, *working_dir);
  if (IsError(maybe_compiler)) {
    PythonErrorStreamer(PyExc_Exception) << ErrorString(maybe_compiler);
  } else {
    std::optional<Compiler> cc(std::move(*maybe_compiler));
    cc.swap(compiler);
  }
}

unsigned PyCompiler::Name(void) {
  return static_cast<unsigned>(compiler->Name());
}

unsigned PyCompiler::TargetLanguage(void) {
  return static_cast<unsigned>(compiler->TargetLanguage());
}

BorrowedPythonPtr<PyObject> PyCompiler::ExecutablePath(void) {
  if (!exe_path) {
    exe_path.Take(convert::FromStdStrView(compiler->ExecutablePath()));
  }
  return exe_path.Borrow();
}

BorrowedPythonPtr<PyObject> PyCompiler::ResourceDirectory(void) {
  if (!resource_dir) {
    resource_dir.Take(convert::FromStdStrView(compiler->ResourceDirectory()));
  }
  return resource_dir.Borrow();
}

BorrowedPythonPtr<PyObject> PyCompiler::SystemRootDirectory(void) {
  if (!sysroot_dir) {
    sysroot_dir.Take(convert::FromStdStrView(compiler->SystemRootDirectory()));
  }
  return sysroot_dir.Borrow();
}

// Tries to add the `Compiler` type to the `pasta` module.
bool PyCompiler::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.Compiler";
  gType.tp_doc = "Interface to running compile commands and compiling files";
  gType.tp_methods = gCompilerMethods;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "Compiler",
                             reinterpret_cast<PyObject *>(&gType));
}

}  // namespace py
}  // namespace pasta
