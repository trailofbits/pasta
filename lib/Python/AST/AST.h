/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/AST.h>
#include <pasta/AST/Token.h>
#include <pasta/Python/Bindings.h>

#include <optional>

namespace clang {
class SourceLocation;
} // namespace clang

namespace pasta {
namespace py {

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


// Python wrapper over a token kind.
class TokenKind : public PythonObject<::pasta::py::TokenKind> {
 public:
  ~TokenKind(void);

  inline TokenKind(clang::tok::TokenKind kind_)
      : kind(kind_) {}

  DEFINE_PYTHON_CONSTRUCTOR(TokenKind, void);

  static bool TryAddToModule(PyObject *module);

  std::string_view Str(void) const;

  clang::tok::TokenKind kind{clang::tok::unknown};
};

// Python wrapper over a token.
class Token : public PythonObject<::pasta::py::Token> {
 public:
  ~Token(void);

  inline explicit Token(const ::pasta::Token &token_)
      : token(token_) {}

  DEFINE_PYTHON_CONSTRUCTOR(Token, void);

  // Tries to add the `Token` type to the `pasta` module
  static bool TryAddToModule(PyObject *module);

  // Return the token kind
  BorrowedPythonPtr<TokenKind> Kind(void);

  // Return the token length in bytes.
  unsigned Length(void);

  // Return the token data.
  std::string_view Data(void);

  // Return source location information for a given token.
  BorrowedPythonPtr<SourceLocation> Location(void);

  ::pasta::Token token;
};

// Abstraction around a Clang AST and the various data structures that need to
// be retained in order to use it.
class AST : public PythonObject<::pasta::py::AST> {
 public:
  ~AST(void);

  inline AST(::pasta::AST ast_) : ast(std::move(ast_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(AST, void);

  // Tries to add the `AST` type to the `pasta` module.
  static bool TryAddToModule(PyObject *module);

  // Return the raw preprocessed code.
  std::string_view PreprocessedCode(void);

  // Return the tokens.
  std::vector<BorrowedPythonPtr<::pasta::py::Token>> Tokens(void);

  std::optional<::pasta::AST> ast;
};

}  // namespace py
}  // namespace pasta
