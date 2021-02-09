/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Compile.h"

namespace pasta {
namespace py {

TokenKind::~TokenKind(void) {}

TokenKind::TokenKind(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "pasta.TokenKind cannot be directly instantiated.";
}

std::string_view TokenKind::Str(void) const {
  return clang::tok::getTokenName(kind);
}

// Tried to add the `TokenKind` type to the `pasta` module.
bool TokenKind::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.TokenKind";
  gType.tp_doc = "Clang token kind.";
  gType.tp_methods = nullptr;
  gType.tp_str = [] (PyObject *self_) {
    auto self = reinterpret_cast<TokenKind*>(self_);
    return convert::FromStdStrView(self->Str());
  };
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "TokenKind",
                             reinterpret_cast<PyObject *>(&gType));
}

namespace {
DEFINE_PYTHON_METHOD(Token, Kind, kind);
DEFINE_PYTHON_METHOD(Token, Length, length);
DEFINE_PYTHON_METHOD(Token, Data, data);
DEFINE_PYTHON_METHOD(Token, Location, location);

static PyGetSetDef gTokenGettersSetters[] = {
  PYTHON_GETTER(kind, "The token kind."),
  PYTHON_GETTER(location, "The source location information associated with "
                          "this token."),
  PYTHON_GETTER(length, "Length of the token in bytes. This may differ than "
                        "the length of `data`, which may have a different "
                        "character encoding."),
  PYTHON_GETTER(data, "Data of this token, as it appears in a source file, or "
                      "as produced by token pasting / stringification in the "
                      "Clang preprocessor."),
  PYTHON_GETTER_SETTER_SENTINEL
};
} // namespace

Token::~Token(void) {}

Token::Token(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "past.Token cannot be directly instantiated.";
}

BorrowedPythonPtr<TokenKind> Token::Kind(void) {
  return TokenKind::New(token.Kind());
}

unsigned Token::Length(void) {
  return static_cast<unsigned>(token.Data().size());
}

std::string_view Token::Data(void) {
  return token.Data();
}

BorrowedPythonPtr<SourceLocation> Token::Location(void) {
  if (token) {
    auto ast = ::pasta::AST::From(token);
    clang::FullSourceLoc loc;
    if (ast.TryGetLocation(token.Location(), &loc)) {
      return SourceLocation::New(loc);
    }
  }

  return nullptr;  // Turns into `Py_None`.
}

// Tries to add the `Token` type to the `pasta` module.
bool Token::TryAddToModule(PyObject *module) {

  // TODO(pag,adrianh): Eventually add a `__hash__`, `__id__`, and `__eq__`
  //                    methods based on the underlying raw `TokenImpl` pointer.

  gType.tp_name = "pasta.Token";
  gType.tp_doc = "A parsed, lexed, or macro-expanded token.";
  gType.tp_methods = nullptr;
  gType.tp_getset = gTokenGettersSetters;
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "Token",
                             reinterpret_cast<PyObject *>(&gType));
}

} // namespace py
} // namespace pasta
