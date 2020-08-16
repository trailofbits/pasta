/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Error.h>

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(CompileJob, WorkingDirectory, working_directory);
DEFINE_PYTHON_METHOD(CompileJob, ResourceDirectory, resource_directory);
DEFINE_PYTHON_METHOD(CompileJob, SystemRootDirectory, system_root_directory);
DEFINE_PYTHON_METHOD(CompileJob, TargetTriple, target_triple);
DEFINE_PYTHON_METHOD(CompileJob, AuxiliaryTargetTriple,
                     auxiliary_target_triple);
DEFINE_PYTHON_METHOD(CompileJob, Arguments, arguments);
DEFINE_PYTHON_METHOD(CompileJob, SourceFile, source_file);

static PyMethodDef gCompileJobMethods[] = {
    PYTHON_METHOD(working_directory,
                  "The directory in which the compile job should be invoked."),
    PYTHON_METHOD(
        resource_directory,
        "Path to the directory containing the compiler's internal header files."),
    PYTHON_METHOD(
        system_root_directory,
        "Default system root directory path for this compiler (useful for cross-compilation)."),
    PYTHON_METHOD(
        target_triple,
        "The LLVM triple describing the target architecture for this compilation job."),
    PYTHON_METHOD(
        auxiliary_target_triple,
        "The LLVM triple describing the auxiliary target architecture for this compilation job. This is generally related to CUDA."),
    PYTHON_METHOD(
        arguments,
        "The arguments of this compile job. This does not include the compiler executable path or name as the first argument."),
    PYTHON_METHOD(source_file,
                  "The path to the source file to be compiled by this job."),
    PYTHON_METHOD_SENTINEL};


}  // namespace

CompileJob::~CompileJob(void) {}

// Return an argument vector associated with this compilation job.
std::vector<std::string_view> CompileJob::Arguments(void) {
  std::vector<std::string_view> list;
  const auto &args = job->Arguments().Arguments();
  list.reserve(args.size());
  for (auto arg : args) {
    list.emplace_back(arg);
  }
  return list;
}

// Return the working directory in which this command executes.
std::string_view CompileJob::WorkingDirectory(void) {
  return job->WorkingDirectory();
}

// Return the compiler resource directory that this command should use.
std::string_view CompileJob::ResourceDirectory(void) {
  return job->ResourceDirectory();
}

// Return the compiler system root directory that this command should use.
std::string_view CompileJob::SystemRootDirectory(void) {
  return job->SystemRootDirectory();
}

// Return the target triple to use.
std::string_view CompileJob::TargetTriple(void) {
  return job->TargetTriple();
}

// Return the auxiliary target triple to use.
std::string_view CompileJob::AuxiliaryTargetTriple(void) {
  return job->AuxiliaryTargetTriple();
}

// Return the path to the source file that this job compiles.
std::string_view CompileJob::SourceFile(void) {
  return job->SourceFile();
}

CompileJob::CompileJob(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "pasta.CompileJob cannot be directly instantiated.";
}

// Tries to add the `CompileJob` type to the `pasta` module.
bool CompileJob::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.CompileJob";
  gType.tp_doc = "Wrapper around a backend (-cc1) compile command.";
  gType.tp_methods = gCompileJobMethods;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "CompileJob",
                             reinterpret_cast<PyObject *>(&gType));
}

}  // namespace py
}  // namespace pasta
