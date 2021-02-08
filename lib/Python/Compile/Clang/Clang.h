/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Python/Bindings.h>

#include <clang/Lex/Token.h>

#include <optional>

namespace clang {
class SourceLocation;
} // namespace clang

namespace pasta {
namespace py {

class TokenKind : public PythonObject<::pasta::py::TokenKind> {
 public:
  ~TokenKind(void);

  inline TokenKind(clang::tok::TokenKind kind_) : kind(std::move(kind_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(TokenKind, void);

  static bool TryAddToModule(PyObject *module);

  std::string_view Str(void) const;

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

  // Return the token length
  unsigned Length(void);

  // Return the token data
  std::string_view Data(void);

  std::optional<clang::Token> token;
};

// Python wrapper for a source location.
class SourceLocation : public PythonObject<::pasta::py::SourceLocation> {
 public:
  ~SourceLocation(void);

  inline SourceLocation(clang::FullSourceLoc loc_) : loc(std::move(loc_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(SourceLocation, void);

  // Location where the token was ultimately expanded
  BorrowedPythonPtr<SourceLocation> ExpansionLoc(void);

  // Location of the token's character data
  BorrowedPythonPtr<SourceLocation> SpellingLoc(void);

  // Expansion or spelling location for a macro
  BorrowedPythonPtr<SourceLocation> FileLoc(void);

  // Source file
  std::string_view File(void);

  // Line number
  unsigned LineNumber(void);

  // Column number
  unsigned ColumnNumber(void);

  // String representation of a source location
  std::string Str(void) const;

  // Tries to add the `SourceLocation` type to the `pasta` module
  static bool TryAddToModule(PyObject *module);

  std::optional<clang::FullSourceLoc> loc;
};

}  // namespace py
}  // namespace pasta
