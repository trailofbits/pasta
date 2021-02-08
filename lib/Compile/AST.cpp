/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"
#include "Token.h"

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

AST::AST(AST &&that) noexcept : impl(that.impl) {
  that.impl = nullptr;
}

AST &AST::operator=(AST &&that) noexcept {
  std::swap(impl, that.impl);
  return *this;
}

AST::AST(std::shared_ptr<ASTImpl> impl_) : impl(std::move(impl_)) {}

std::string_view AST::PreprocessedCode(void) const {
  return impl->preprocessed_code;
}

const std::vector<clang::Token> &AST::Tokens(void) const {
  return impl->tokens;
}

bool AST::TryGetLocation(const clang::Token &tok, clang::FullSourceLoc *out_loc) const {
  const auto loc = tok.getLocation();
  if (loc.isInvalid()) {
    return false;
  }
  const auto &sm = impl->ci->getSourceManager();
  *out_loc = clang::FullSourceLoc(loc, sm);
  return true;
}

bool AST::TryReadToken(const clang::Token &tok, std::string *out) const {
  return ::pasta::ReadRawToken(impl->ci->getSourceManager(),
                               impl->ci->getLangOpts(), tok, out);
}

}  // namespace pasta
