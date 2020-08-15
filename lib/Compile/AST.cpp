/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Frontend/CompilerInstance.h>
#include <llvm/Support/VirtualFileSystem.h>
#pragma clang diagnostic pop

namespace pasta {

ASTImpl::ASTImpl(void) {}
ASTImpl::~ASTImpl(void) {}

AST::~AST(void) {}

AST::AST(std::shared_ptr<ASTImpl> impl_) : impl(std::move(impl_)) {}

}  // namespace pasta
