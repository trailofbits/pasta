/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

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
};

}  // namespace pasta
