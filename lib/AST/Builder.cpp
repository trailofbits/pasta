/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Builder.h"

#include <cassert>

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP
Type TypeBuilder::Build(std::shared_ptr<ASTImpl> ast_, clang::QualType type) {
  if (auto type_ptr = type.getTypePtrOrNull()) {
    return Type(
        std::move(ast_), type_ptr,
        static_cast<TypeClass>(type_ptr->getTypeClass()),
        type.getQualifiers().getAsOpaqueValue());
  }
  assert(!"`type` is a null type.");
  __builtin_unreachable();
}
#endif

}  // namespace pasta
