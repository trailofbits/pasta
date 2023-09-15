/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#ifdef PASTA_IN_BOOTSTRAP

#include <pasta/AST/DeclBootstrap.h>

namespace pasta {

Decl::Decl(std::shared_ptr<ASTImpl> ast_, const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_, static_cast<DeclKind>(0u)) {}

std::string_view Decl::KindName(void) const noexcept {
  return std::string_view();
}

}  // namespace pasta

#endif  // PASTA_IN_BOOTSTRAP
