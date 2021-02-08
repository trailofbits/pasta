/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compile.h"

namespace pasta {
namespace py {
namespace {

DEFINE_PYTHON_METHOD(AST, PreprocessedCode, preprocessed_code);
DEFINE_PYTHON_METHOD(AST, Tokens, tokens);
DEFINE_PYTHON_METHOD(AST, GetLocation, get_location);
DEFINE_PYTHON_METHOD(AST, GetRawToken, token_data);

static PyMethodDef gASTMethods[] = {
  PYTHON_METHOD(get_location, "Get the location of the given token."),
  PYTHON_METHOD(token_data, "Read the raw token data."),
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

std::vector<BorrowedPythonPtr<Token>> AST::Tokens(void) {
  std::vector<BorrowedPythonPtr<Token>> ret;

  std::for_each(ast->Tokens().begin(), ast->Tokens().end(), [&ret](auto &token){
    ret.emplace_back(std::move(Token::New(token)));
  });

  return ret;
}

BorrowedPythonPtr<SourceLocation> AST::GetLocation(token_arg tok) {
  clang::FullSourceLoc loc;
  if (!ast->TryGetLocation(*(*tok)->token, &loc)) {
    return nullptr;
  }
  return SourceLocation::New(loc);
}

std::string AST::GetRawToken(token_arg tok) {
  std::string out;

  if (!ast->TryReadToken(*(*tok)->token, &out)) {
    // Adrian: Return something more meaningful than the empty string
    return "";
  }

  return out;
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
