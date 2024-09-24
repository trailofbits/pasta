/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <type_traits>

#include "AST.h"

namespace pasta {

enum class DeclKind : unsigned int;
enum class StmtKind : unsigned int;
enum class TypeKind : unsigned int;

class AttrBuilder {
 public:
  template <typename T, typename A>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const A *attr_) {
    return T(std::move(ast_), attr_);
  }
};

class DeclBuilder {
 public:
  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {
    return T(std::move(ast_), reinterpret_cast<const D *>(decl_->RemappedDecl));
  }
};

class DesignatorBuilder {
 public:
  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *designator_) {
    return T(std::move(ast_), designator_);
  }
};

class StmtBuilder {
 public:
  template <typename T, typename S>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const S *stmt_) {
    return T(std::move(ast_), stmt_);
  }
};

class TypeBuilder {
 public:
#ifndef PASTA_IN_BOOTSTRAP
  static Type Build(std::shared_ptr<ASTImpl> ast_, clang::QualType type);
#endif

  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *type_) {
    assert(ast_.get() != nullptr);
    return T(std::move(ast_), type_,
             static_cast<TypeKind>(type_->getTypeClass()), 0);
  }

  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *type_,
                         uint32_t qualifiers_) {
    assert(ast_.get() != nullptr);
    return T(std::move(ast_), type_,
             static_cast<TypeKind>(type_->getTypeClass()), qualifiers_);
  }

#ifndef PASTA_IN_BOOTSTRAP
  template <typename T>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, clang::QualType type) {
    assert(ast_.get() != nullptr);
    if constexpr (std::is_same_v<T, pasta::Type>) {
      return Build(std::move(ast_), type);
    } else {
      return T::From(Build(std::move(ast_), type));
    }
  }
#endif
};

}  // namespace pasta
