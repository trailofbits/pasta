/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(CompileJob, WorkingDirectory, working_directory);

static PyMethodDef gASTMethods[] = {
    PYTHON_METHOD(working_directory,
                  "The directory in which the compile job should be invoked."),
    PYTHON_METHOD_SENTINEL
};

}  // namespace

AST::~AST(void) {}

AST::AST(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "pasta.AST cannot be directly instantiated.";
}

// Tries to add the `CompileJob` type to the `pasta` module.
bool AST::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.AST";
  gType.tp_doc = "Wrapper around Clang AST data structures.";
  gType.tp_methods = gASTMethods;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "AST",
                             reinterpret_cast<PyObject *>(&gType));
}


}  // namespace py
}  // namespace pasta
