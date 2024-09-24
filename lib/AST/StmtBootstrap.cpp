/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#ifdef PASTA_IN_BOOTSTRAP

#include <pasta/AST/StmtBootstrap.h>

namespace pasta {

Stmt::Stmt(std::shared_ptr<ASTImpl> ast_, const ::clang::Stmt *stmt_)
    : Stmt(std::move(ast_), stmt_, static_cast<StmtKind>(0u)) {}

std::string_view Stmt::KindName(void) const noexcept {
  return std::string_view("");
}

}  // namespace pasta

#endif  // PASTA_IN_BOOTSTRAP
