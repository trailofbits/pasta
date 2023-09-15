/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <vector>

#include "Decl.h"
#include "Macro.h"
#include "Stmt.h"
#include "Token.h"
#include "Type.h"

#include <pasta/Util/File.h>

namespace clang {
class ASTContext;
class Decl;
class Stmt;
class Preprocessor;
class SourceLocation;
}  // namespace clang

namespace pasta {

class ASTImpl;
class Attr;
class CompileJob;
class Compiler;
class Decl;
class Macro;
class Stmt;
class Token;
class TokenContext;
class Type;

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

  // Return the AST containing a Stmt.
  static AST From(const Stmt &stmt);

  // Return the AST containing a Macro.
  static AST From(const Macro &macro);

  // Return the AST containing a Type.
  static AST From(const Type &type);

  ~AST(void);
  AST(const AST &);
  AST(AST &&) noexcept;
  AST &operator=(const AST &);
  AST &operator=(AST &&) noexcept;

  // Return the raw pre-processed code
  std::string_view PreprocessedCode(void) const;

  // Return all lexed tokens.
  TokenRange Tokens(void) const;

  // Return all top-level macro nodes (expansions, directives, substitutions,
  // etc.).
  MacroRange Macros(void) const;

  // Return a reference to the underlying Clang AST context. This is needed for
  // bootstrapping.
  clang::ASTContext &UnderlyingAST(void) const;

  // Returns the top-level translation unit decl inside of this AST.
  TranslationUnitDecl TranslationUnit(void) const;

  clang::Preprocessor &UnderlyingPP(void) const;

  // Return the main file which was parsed and thus resulted in this AST.
  File MainFile(void) const;

  // Return the list of all source files which were parsed as part of the
  // construction of this AST.
  const std::vector<::pasta::File> &ParsedFiles(void) const;

#ifndef PASTA_IN_BOOTSTRAP
  Token Adopt(const clang::SourceLocation &loc) const;
  Attr Adopt(const clang::Attr *attr) const;
  Decl Adopt(const clang::Decl *decl) const;
  Stmt Adopt(const clang::Stmt *stmt) const;
  Type Adopt(const clang::Type *type, uint32_t qual = 0u) const;
#endif

 private:
  friend class ASTImpl;
  friend class Compiler;
  friend class CompileJob;
  friend class DeclBase;
  friend class DeclPrinter;

  AST(void) = delete;

  AST(std::shared_ptr<ASTImpl> impl_);

  std::shared_ptr<ASTImpl> impl;
};


}  // namespace pasta
