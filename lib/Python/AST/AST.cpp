/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(AST, PreprocessedCode, preprocessed_code);
DEFINE_PYTHON_METHOD(AST, Tokens, tokens);

static PyMethodDef gASTMethods[] = {
  PYTHON_METHOD_SENTINEL
};

static PyGetSetDef gASTGetterSetters[] = {
  PYTHON_GETTER(preprocessed_code, "The raw preprocessed code"),
  PYTHON_GETTER(tokens, "The parsed tokens"),
  PYTHON_GETTER_SETTER_SENTINEL
};

}  // namespace

AST::~AST(void) {}

AST::AST(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "pasta.AST cannot be directly instantiated.";
}

std::string_view AST::PreprocessedCode(void) {
  return ast->PreprocessedCode();
}

std::vector<BorrowedPythonPtr<::pasta::py::Token>> AST::Tokens(void) {
  std::vector<BorrowedPythonPtr<::pasta::py::Token>> ret;

  // TODO(pag,adrianh): Eventually, expose a `TokenRange` python object instead,
  //                    that implements things like `__getitem__` and `__iter__`
  //                    so that we only create `Token` objects on an as-
  //                    requested basis.
  for (const auto &token : ast->Tokens()) {
    ret.emplace_back(Token::New(token));
  }
  return ret;
}

// Tries to add the `AST` type to the `pasta` module.
bool AST::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.AST";
  gType.tp_doc = "Wrapper around Clang AST data structures.";
  gType.tp_methods = gASTMethods;
  gType.tp_getset = gASTGetterSetters;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "AST",
                             reinterpret_cast<PyObject *>(&gType));
}

}  // namespace py
}  // namespace pasta
