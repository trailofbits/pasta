/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

#include <memory>
#include <optional>
#include <string_view>

namespace clang {
class FullSourceLoc;
class Token;
}  // namespace clang
namespace pasta {

class ASTImpl;
class CompileJob;
class Compiler;

// Abstraction around a Clang AST and the various data structures that need to
// be retained in order to use it.
class AST {
 public:
  ~AST(void);
  AST(AST &&) noexcept;
  AST &operator=(AST &&) noexcept;

  // Return the raw pre-processed code
  std::string_view PreprocessedCode(void) const;

  // Return the lexed tokens
  const std::vector<clang::Token> &Tokens(void) const;

  // Attempt to get the source location of the given token
  bool TryGetLocation(const clang::Token &tok, clang::FullSourceLoc &loc_out) const;

  // Attempt to read the raw data for the given token
  bool TryReadToken(const clang::Token &tok, std::string *out) const;

 private:
  friend class Compiler;
  friend class CompileJob;

  AST(std::shared_ptr<ASTImpl> impl_);

  std::shared_ptr<ASTImpl> impl;
};

//template <typename T>
//class ASTNode {
// public:
//
// private:
//  std::shared_ptr<ASTImpl> impl;
//  const T * const node;
//};
//
//class DeclASTNode : public ASTNode<clang::Decl> {
// public:
//  std::string_view KindName(void) const;
//
//  // Name of this AST node.
//  std::optional<std::string_view> Name(void) const;
//
//};
//
//class StmtASTNode : public ASTNode<clang::Stmt> {
// public:
//};
//
//class ExprASTNode : public ASTNode<clang::Stmt> {
// public:
//};

}  // namespace pasta
