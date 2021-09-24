/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include "AST.h"

namespace pasta {

class DeclBuilder {
 public:
  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {
    return T(std::move(ast_), decl_);
  }
};

class TypeBuilder {
 public:
  static pasta::Type Build(std::shared_ptr<ASTImpl> ast_,
                           clang::QualType type) {
    if (auto type_ptr = type.getTypePtrOrNull()) {
      return pasta::Type(
          std::move(ast_), type_ptr,
          static_cast<TypeClass>(type_ptr->getTypeClass()),
          type.getQualifiers().getAsOpaqueValue());
    }
    __builtin_unreachable();
  }

  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *type_) {
    return T(std::move(ast_), type_);
  }
};

}  // namespace pasta
