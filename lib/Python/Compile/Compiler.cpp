/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Compile/Compiler.h>
#include <pasta/Util/Error.h>

#include <filesystem>

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(Compiler, Name, name);
DEFINE_PYTHON_METHOD(Compiler, TargetLanguage, target_language);
DEFINE_PYTHON_METHOD(Compiler, ExecutablePath, executable_path);
DEFINE_PYTHON_METHOD(Compiler, ResourceDirectory, resource_directory);
DEFINE_PYTHON_METHOD(Compiler, SystemRootDirectory, system_root_directory);
DEFINE_PYTHON_METHOD(Compiler, InstallationDirectory, installation_directory);
DEFINE_PYTHON_METHOD(Compiler, SystemIncludeDirectories,
                     system_include_directories);
DEFINE_PYTHON_METHOD(Compiler, UserIncludeDirectories,
                     user_include_directories);
DEFINE_PYTHON_METHOD(Compiler, FrameworkDirectories, framework_directories);
DEFINE_PYTHON_METHOD(Compiler, CreateCommandForFile, create_file_command);
DEFINE_PYTHON_METHOD(Compiler, CreateJobsForCommand, create_command_jobs);

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
    PYTHON_METHOD(
        create_file_command,
        "Create a command that can be used to compile the input file."),
    PYTHON_METHOD(
        create_command_jobs,
        "Create and return a list of CompileJob instances representing the jobs needed to compile the source files referenced by the input CompileCommand."),
    PYTHON_METHOD_SENTINEL};

}  // namespace

// Return the current working directory.
std::string CurrentWorkingDir(const working_dir_kwarg &working_dir) {
  if (working_dir && !working_dir->empty()) {
    return *working_dir;
  } else {
    return std::filesystem::current_path().string();
  }
}

Compiler::~Compiler(void) {}

Compiler::Compiler(compiler_name_arg name, target_language_arg lang,
                   compiler_path_arg compiler_path,
                   version_info_arg version_info,
                   version_info_fake_sysroot_arg version_info_fake_sysroot,
                   working_dir_kwarg working_dir) {
  auto maybe_compiler =
      ::pasta::Compiler::Create(*name, *lang, *compiler_path, *version_info,
                                *version_info_fake_sysroot,
                                CurrentWorkingDir(working_dir));
  if (IsError(maybe_compiler)) {
    PythonErrorStreamer(PyExc_Exception) << ErrorString(maybe_compiler);
  } else {
    std::optional<::pasta::Compiler> cc(std::move(*maybe_compiler));
    cc.swap(compiler);
  }
}

unsigned Compiler::Name(void) {
  return static_cast<unsigned>(compiler->Name());
}

unsigned Compiler::TargetLanguage(void) {
  return static_cast<unsigned>(compiler->TargetLanguage());
}

std::string_view Compiler::ExecutablePath(void) {
  return compiler->ExecutablePath();
}

std::string_view Compiler::ResourceDirectory(void) {
  return compiler->ResourceDirectory();
}

std::string_view Compiler::SystemRootDirectory(void) {
  return compiler->SystemRootDirectory();
}

// Directory where the compiler is installed.
std::string_view Compiler::InstallationDirectory(void) {
  return compiler->InstallationDirectory();
}

// List of system include directories.
const std::vector<std::string> Compiler::SystemIncludeDirectories(void) {
  std::vector<std::string> list;
  compiler->ForEachSystemIncludeDirectory(
      [&](std::string_view path_str, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          list.emplace_back(path_str);
        } else {
          std::filesystem::path path(compiler->SystemRootDirectory());
          path += path_str;
          list.emplace_back(path.string());
        }
      });
  return list;
}

// List of user include directories.
const std::vector<std::string> Compiler::UserIncludeDirectories(void) {
  std::vector<std::string> list;
  compiler->ForEachUserIncludeDirectory(
      [&](std::string_view path_str, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          list.emplace_back(path_str);
        } else {
          std::filesystem::path path(compiler->SystemRootDirectory());
          path += path_str;
          list.emplace_back(path.string());
        }
      });
  return list;
}

// List of framework directories.
const std::vector<std::string> Compiler::FrameworkDirectories(void) {
  std::vector<std::string> list;
  compiler->ForEachFrameworkDirectory(
      [&](std::string_view path_str, IncludePathLocation loc) {
        if (loc == IncludePathLocation::kAbsolute) {
          list.emplace_back(path_str);
        } else {
          std::filesystem::path path(compiler->SystemRootDirectory());
          path += path_str;
          list.emplace_back(path.string());
        }
      });
  return list;
}

// Create a compile command for a single file in a working directory.
BorrowedPythonPtr<CompileCommand>
Compiler::CreateCommandForFile(file_path_arg file_path,
                               working_dir_kwarg working_dir) {
  auto maybe_command = compiler->CreateCommandForFile(
      *file_path, CurrentWorkingDir(working_dir));
  if (IsError(maybe_command)) {
    PythonErrorStreamer(PyExc_Exception) << ErrorString(maybe_command);
    return nullptr;
  } else {
    return CompileCommand::New(std::move(*maybe_command));
  }
}

// Create a compile command for a single file in a working directory.
std::vector<BorrowedPythonPtr<CompileJob>>
Compiler::CreateJobsForCommand(command_arg command) {
  std::vector<BorrowedPythonPtr<CompileJob>> ret;
  auto maybe_jobs = compiler->CreateJobsForCommand(*((*command)->command));
  if (IsError(maybe_jobs)) {
    PythonErrorStreamer(PyExc_Exception) << ErrorString(maybe_jobs);
  } else {
    auto jobs = std::move(*maybe_jobs);
    for (auto &job : jobs) {
      auto py_job = CompileJob::New(std::move(job));
      ret.emplace_back(std::move(py_job));
    }
  }
  return ret;
}

// Tries to add the `Compiler` type to the `pasta` module.
bool Compiler::TryAddToModule(PyObject *module) {
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
