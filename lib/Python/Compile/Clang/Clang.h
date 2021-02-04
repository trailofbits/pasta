/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Python/Bindings.h>

#include <clang/Lex/Token.h>

#include <optional>

namespace pasta {
namespace py {

class TokenKind : public PythonObject<::pasta::py::TokenKind> {
 public:
  ~TokenKind(void);

  inline TokenKind(clang::tok::TokenKind kind_) : kind(std::move(kind_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(TokenKind, void);

  static bool TryAddToModule(PyObject *module);

  std::string_view Str(void);

  std::optional<clang::tok::TokenKind> kind;
};

// Python wrapper for a Clang token.
class Token : public PythonObject<::pasta::py::Token> {
 public:
  ~Token(void);

  inline Token(clang::Token token_) : token(std::move(token_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(Token, void);

  // Tries to add the `Token` type to the `pasta` module
  static bool TryAddToModule(PyObject *module);

  // Return the token kind
  BorrowedPythonPtr<TokenKind> Kind(void);

  unsigned Length(void);

  std::optional<clang::Token> token;
};

}  // namespace py
}  // namespace pasta
