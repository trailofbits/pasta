/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#ifdef PASTA_IN_BOOTSTRAP

#include <pasta/AST/TypeBootstrap.h>

namespace pasta {

Type::Type(std::shared_ptr<ASTImpl> ast_, const ::clang::Type *type_)
    : Type(std::move(ast_), type_, static_cast<TypeKind>(0u)) {}

std::string_view Type::KindName(void) const noexcept {
  return std::string_view("");
}

}  // namespace pasta

#endif  // PASTA_IN_BOOTSTRAP
