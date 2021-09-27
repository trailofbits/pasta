/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <type_traits>

#include "AST.h"

namespace pasta {

enum class TypeClass : unsigned int;

class DeclBuilder {
 public:
  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {
    return T(std::move(ast_), decl_);
  }
};

class TypeBuilder {
 public:
#ifndef PASTA_IN_BOOTSTRAP
  static Type Build(std::shared_ptr<ASTImpl> ast_, clang::QualType type);
#endif

  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *type_) {
    return T(std::move(ast_), type_,
             static_cast<TypeClass>(type_->getTypeClass()), 0);
  }

#ifndef PASTA_IN_BOOTSTRAP
  template <typename T>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, clang::QualType type) {
    if constexpr (std::is_same_v<T, pasta::Type>) {
      return Build(std::move(ast_), type);
    } else {
      return T::From(Build(std::move(ast_), type));
    }
  }
#endif
};

}  // namespace pasta
