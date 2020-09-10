/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

#include <memory>
#include <optional>
#include <string_view>

namespace clang {
class Decl;
class Stmt;
class Expr;
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
