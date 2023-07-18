/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#ifdef PASTA_IN_BOOTSTRAP

#include <memory>
#include <optional>
#include <string_view>
#include "Token.h"

static pasta::Token *gDummyDeclTok;

namespace clang {
class Decl;
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
enum class DeclKind : unsigned;
class TokenContext;

class Decl {
 public:
  std::shared_ptr<ASTImpl> ast;
  union {
    const clang::Decl *Decl;
    const void *opaque;
  } u;
  DeclKind kind;

  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Decl *decl_,
                       DeclKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    u.opaque = decl_;
  }

  inline DeclKind Kind(void) const noexcept {
    return kind;
  }

  std::string_view KindName(void) const noexcept;

  inline const clang::Decl *RawDecl(void) const noexcept {
    return u.Decl;
  }

  static std::optional<Decl> From(const TokenContext &) { return
    std::nullopt;
  };
  pasta::Token BeginToken(void) const noexcept { return *gDummyDeclTok; };
  pasta::Token EndToken(void) const noexcept { return *gDummyDeclTok; };

 private:
  Decl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit Decl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

class TranslationUnitDecl : public Decl {};

}  // namespace pasta

#endif
