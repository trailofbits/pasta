/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

#include <memory>
#include <optional>
#include <string_view>

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
  AST(AST &&) noexcept;
  AST &operator=(AST &&) noexcept;

  // Return the raw pre-processed code
  std::string_view PreprocessedCode(void) const;

  // Return all lexed tokens.
  TokenRange Tokens(void) const;

  // Try to return the token at the specified location.
  std::optional<Token> TokenAt(clang::SourceLocation loc) const;

  // Return a pointer to the underlying Clang AST context. This is needed for
  // bootstrapping.
  clang::ASTContext &UnderlyingAST(void) const;

 private:
  friend class Compiler;
  friend class CompileJob;
  friend class DeclBase;

  AST(std::shared_ptr<ASTImpl> impl_);

  std::shared_ptr<ASTImpl> impl;
};


}  // namespace pasta
