/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"

namespace pasta {

AST::~AST(void) {}

AST::AST(std::shared_ptr<ASTImpl> impl_) : impl(std::move(impl_)) {}

}  // namespace pasta
