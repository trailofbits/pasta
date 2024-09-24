/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Builder.h"

#include <cassert>
#include <cstdlib>

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP
Type TypeBuilder::Build(std::shared_ptr<ASTImpl> ast_, clang::QualType type) {
  if (auto type_ptr = type.getTypePtrOrNull();
      4095ul < reinterpret_cast<uintptr_t>(type_ptr)) {
    assert(ast_.get() != nullptr);
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
