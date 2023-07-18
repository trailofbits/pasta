/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#ifdef PASTA_IN_BOOTSTRAP

#include <memory>
#include <optional>
#include <vector>
#include <string_view>
#include "Token.h"

static pasta::Token *gDummyStmtTok;

namespace clang {
class Stmt;
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
enum class StmtKind : unsigned;
class TokenContext;
class Macro;

class Stmt {
 public:
  std::shared_ptr<ASTImpl> ast;
  union {
    const clang::Stmt *Stmt;
    const void *opaque;
  } u;
  StmtKind kind;

  inline explicit Stmt(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Stmt *decl_,
                       StmtKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    u.opaque = decl_;
  }

  inline StmtKind Kind(void) const noexcept {
    return kind;
  }

  std::string_view KindName(void) const noexcept;

  static std::optional<Stmt> From(const TokenContext &) {
    return std::nullopt;
  };
  pasta::Token BeginToken(void) const noexcept { return *gDummyStmtTok; };
  pasta::Token EndToken(void) const noexcept { return *gDummyStmtTok; };
  inline bool AlignsWith(::pasta::Macro &) const noexcept {
    return false;
  }
  inline std::vector<::pasta::Stmt> Children(void) const {
    return {};
  }

 private:
  Stmt(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit Stmt(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Stmt *decl_);
};

class Expr : public Stmt {
 public:
  using Stmt::Stmt;
};

}  // namespace pasta

#endif
