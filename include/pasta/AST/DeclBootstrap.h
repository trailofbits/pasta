/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#ifdef PASTA_IN_BOOTSTRAP

#include <memory>
#include <string_view>

namespace clang {
class Decl;
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
enum class DeclKind : unsigned;

class Decl {
 public:
  std::shared_ptr<ASTImpl> ast;
  union {
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

  std::string_view KindName(void) const noexcept;

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

using TranslationUnitDecl = Decl;

}  // namespace pasta

#endif
