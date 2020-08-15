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
DEFINE_PYTHON_METHOD(PyCompiler, InstallationDirectory, installation_directory);
DEFINE_PYTHON_METHOD(PyCompiler, SystemIncludeDirectories,
                     system_include_directories);
DEFINE_PYTHON_METHOD(PyCompiler, UserIncludeDirectories,
                     user_include_directories);
DEFINE_PYTHON_METHOD(PyCompiler, FrameworkDirectories, framework_directories);

static PyMethodDef gCompilerMethods[] = {
    PYTHON_METHOD(name, "Return the identifier of this compiler."),
    PYTHON_METHOD(
        target_language,
        "Return the identifier of the language targeted by this compiler."),
    PYTHON_METHOD(executable_path, "Path to the executable of this compiler."),
    PYTHON_METHOD(
        resource_directory,
        "Path to the directory containing the compiler's internal header files."),
    PYTHON_METHOD(installation_directory,
                  "Path to the directory where the compiler was installed."),
    PYTHON_METHOD(
        system_root_directory,
        "Default system root directory path for this compiler (useful for cross-compilation)."),
    PYTHON_METHOD(
        system_include_directories,
        "List of system include directories scanned by the compiler when trying to resolve #include files."),
    PYTHON_METHOD(
        user_include_directories,
        "List of user include directories scanned by the compiler when trying to resolve #include files."),
    PYTHON_METHOD(
        framework_directories,
        "List of framework directories scanned by the compiler when trying to resolve #include files."),
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

std::string_view PyCompiler::ExecutablePath(void) {
  return compiler->ExecutablePath();
}

std::string_view PyCompiler::ResourceDirectory(void) {
  return compiler->ResourceDirectory();
}

std::string_view PyCompiler::SystemRootDirectory(void) {
  return compiler->SystemRootDirectory();
}

// Directory where the compiler is installed.
std::string_view PyCompiler::InstallationDirectory(void) {
  return compiler->InstallationDirectory();
}

// List of system include directories.
std::vector<std::string_view> PyCompiler::SystemIncludeDirectories(void) {
  std::vector<std::string_view> list;
  compiler->ForEachSystemIncludeDirectory(
      [&list](std::string_view path) { list.emplace_back(path); });
  return list;
}

// List of user include directories.
std::vector<std::string_view> PyCompiler::UserIncludeDirectories(void) {
  std::vector<std::string_view> list;
  compiler->ForEachUserIncludeDirectory(
      [&list](std::string_view path) { list.emplace_back(path); });
  return list;
}

// List of framework directories.
std::vector<std::string_view> PyCompiler::FrameworkDirectories(void) {
  std::vector<std::string_view> list;
  compiler->ForEachFrameworkDirectory(
      [&list](std::string_view path) { list.emplace_back(path); });
  return list;
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
