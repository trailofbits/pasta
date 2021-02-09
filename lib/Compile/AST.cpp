/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"
#include "Token.h"

#include <cassert>
#include <limits>
#include <new>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Frontend/CompilerInstance.h>
#include <llvm/Support/VirtualFileSystem.h>
#pragma clang diagnostic pop

namespace pasta {

ASTImpl::ASTImpl(void) {
  tokens.reserve(1024ull * 32u);
}

ASTImpl::~ASTImpl(void) {}

// Append a token to the end of the AST. `offset` is positive if the data
// of the token can be found at a specific offset in `preprocessed_code`,
// and negative if `-offset` can be found in `backup_code`. `len` is the
// length in bytes of the token itself.
void ASTImpl::AppendToken(const clang::Token &tok, size_t offset_,
                          size_t len_) {
  const auto len = static_cast<uint16_t>(len_);
  assert(offset_ == (offset_ & 0x7FFFFFFFull));
  assert(len == len);
  tokens.emplace_back(tok.getLocation().getRawEncoding(),
                      static_cast<int32_t>(offset_), len,
                      tok.getKind());
}

// Append a token to the end of the AST. `offset` is the offset in
// `backup_token_data`, and `len` is the length in bytes of the token itself.
void ASTImpl::AppendBackupToken(const clang::Token &tok, size_t offset_,
                                size_t len_) {
  const auto len = static_cast<uint16_t>(len_);
  assert(offset_ == (offset_ & 0x7FFFFFFFull));
  assert(len == len);
  tokens.emplace_back(tok.getLocation().getRawEncoding(),
                      -static_cast<int32_t>(offset_), len,
                      tok.getKind());
}

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

// Return all lexed tokens.
TokenRange AST::Tokens(void) const {
  const auto first = impl->tokens.data();
  return TokenRange(impl, first, &(first[impl->tokens.size()]));
}

// Attempt to get the source location of the given token. If successful,
// return `true` and update `*loc_out`. Otherwise, return `false`.
bool AST::TryGetLocation(clang::SourceLocation loc,
                         clang::FullSourceLoc *out_loc) const {
  if (loc.isInvalid()) {
    return false;
  } else {
    const auto &sm = impl->ci->getSourceManager();
    *out_loc = clang::FullSourceLoc(loc, sm);
    return true;
  }
}

}  // namespace pasta
