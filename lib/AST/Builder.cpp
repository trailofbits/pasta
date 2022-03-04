/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Builder.h"

#include <cassert>
#include <cstdlib>

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP
Type TypeBuilder::Build(std::shared_ptr<ASTImpl> ast_, clang::QualType type) {
  if (auto type_ptr = type.getTypePtrOrNull();
      4095ul < reinterpret_cast<uintptr_t>(type_ptr)) {
    return Type(
        std::move(ast_), type_ptr,
        static_cast<TypeKind>(type_ptr->getTypeClass()),
        type.getQualifiers().getAsOpaqueValue());
  }
  assert(false && "`type` is a null type.");
  abort();
}
#endif

}  // namespace pasta
