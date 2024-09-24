/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#ifdef PASTA_IN_BOOTSTRAP

#include <memory>
#include <string_view>

namespace clang {
class Type;
}  // namespace clang
namespace pasta {

class AST;
class ASTImpl;
enum class TypeKind : unsigned;

class Type {
 public:
  std::shared_ptr<ASTImpl> ast;
  union {
    const clang::Type *Type;
    const void *opaque;
  } u;
  TypeKind kind;
  unsigned qualifiers{0};

  inline explicit Type(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Type *type_,
                       TypeKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    u.opaque = type_;
  }

  inline TypeKind Kind(void) const noexcept {
    return kind;
  }

  std::string_view KindName(void) const noexcept;

 private:
  Type(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit Type(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Type *type_);
};

}  // namespace pasta

#endif
