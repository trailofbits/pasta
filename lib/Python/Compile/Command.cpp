/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Compile/Command.h>
#include <pasta/Util/ArgumentVector.h>

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(CompileCommand, WorkingDirectory, working_directory);
DEFINE_PYTHON_METHOD(CompileCommand, Arguments, arguments);

static PyGetSetDef gCompileCommandGettersSetters[] = {
  PYTHON_GETTER(
      working_directory,
      "The directory in which the compile command should be invoked."),
  PYTHON_GETTER(arguments, "The arguments of this compile command."),
  PYTHON_GETTER_SETTER_SENTINEL
};

}  // namespace

CompileCommand::~CompileCommand(void) {}

CompileCommand::CompileCommand(command_arg command_,
                               working_dir_kwarg working_dir) {
  auto maybe_command = ::pasta::CompileCommand::CreateFromArguments(
      *command_, CurrentWorkingDir(working_dir));
  if (maybe_command.Failed()) {
    PythonErrorStreamer(PyExc_Exception) << maybe_command.TakeError();
  } else {
    std::optional<::pasta::CompileCommand> cc(maybe_command.TakeValue());
    cc.swap(command);
  }
}

// Return an argument vector associated with this compilation command.
std::vector<std::string_view> CompileCommand::Arguments(void) {
  std::vector<std::string_view> list;
  const auto &args = command->Arguments().Arguments();
  list.reserve(args.size());
  for (auto arg : args) {
    list.emplace_back(arg);
  }
  return list;
}

// Return the working directory in which this command executes.
std::string_view CompileCommand::WorkingDirectory(void) {
  return command->WorkingDirectory();
}

// Tries to add the `CompileCommand` type to the `pasta` module.
bool CompileCommand::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.CompileCommand";
  gType.tp_doc = "Wrapper around a frontend compile command.";
  gType.tp_methods = nullptr;
  gType.tp_getset = gCompileCommandGettersSetters;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "CompileCommand",
                             reinterpret_cast<PyObject *>(&gType));
}

}  // namespace py
}  // namespace pasta
