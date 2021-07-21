/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <string_view>

#include "Decl.h"
#include "Token.h"

namespace clang {
class ASTContext;
class FullSourceLoc;
class Token;
}  // namespace clang

namespace pasta {

class ASTImpl;
class CompileJob;
class Compiler;
class Decl;

// Abstraction around a Clang AST and the various data structures that need to
// be retained in order to use it.
class AST {
 public:
  // Return the AST containing a token.
  inline static AST From(const Token &token) {
    return AST(token.ast);
  }

  // Return the AST containing a declaration.
  static AST From(const Decl &decl);

  ~AST(void);
  AST(const AST &);
  AST(AST &&) noexcept;
  AST &operator=(const AST &);
  AST &operator=(AST &&) noexcept;

  // Return the raw pre-processed code
  std::string_view PreprocessedCode(void) const;

  // Return all lexed tokens.
  TokenRange Tokens(void) const;

  // Try to return the token at the specified location.
  Token TokenAt(clang::SourceLocation loc) const;

  // Try to return teh token range from the specified source range.
  TokenRange TokenRangeFrom(clang::SourceRange range);

  // Return a reference to the underlying Clang AST context. This is needed for
  // bootstrapping.
  clang::ASTContext &UnderlyingAST(void) const;

  // Returns the top-level translation unit decl inside of this AST.
  TranslationUnitDecl TranslationUnit(void) const;

 private:
  friend class Compiler;
  friend class CompileJob;
  friend class DeclBase;

  AST(std::shared_ptr<ASTImpl> impl_);

  std::shared_ptr<ASTImpl> impl;
};


}  // namespace pasta
