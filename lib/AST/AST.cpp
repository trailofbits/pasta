/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "AST.h"

#include <pasta/AST/Decl.h>

#include <cassert>
#include <limits>
#include <new>

#include "Builder.h"
#include "Token.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Frontend/CompilerInstance.h>
#include <llvm/Support/VirtualFileSystem.h>
#pragma clang diagnostic pop

namespace pasta {

ASTImpl::ASTImpl(File main_source_file_)
    : main_source_file(std::move(main_source_file_)) {
  tokens.reserve(1024ull * 32u);
  backup_token_data.reserve(1024ull * 4);

  // A negative value of `TokenImpl::data_offset` represents an index into
  // `backup_token_data`; thus we must initialize this string with at least one
  // character, lest we try to store `-0`, which in two's complement is `0`,
  // and which would then look just like an index into `token_data`.
  backup_token_data.push_back('\0');
}

ASTImpl::~ASTImpl(void) {}

// Append a token to the end of the AST. `offset` is positive if the data
// of the token can be found at a specific offset in `preprocessed_code`,
// and negative if `-offset` can be found in `backup_code`. `len` is the
// length in bytes of the token itself.
void ASTImpl::AppendToken(const clang::Token &tok, size_t offset_,
                          size_t len_) {
  const auto len = static_cast<uint16_t>(len_);
  assert(0u <= static_cast<int32_t>(offset_));  // Make sure it fits in 31 bits.
  assert(len == len_);
  tokens.emplace_back(tok.getLocation().getRawEncoding(),
                      static_cast<int32_t>(offset_), len, tok.getKind());
}

// Append a token to the end of the AST. `offset` is the offset in
// `backup_token_data`, and `len` is the length in bytes of the token itself.
void ASTImpl::AppendBackupToken(const clang::Token &tok, size_t offset_,
                                size_t len_) {
  const auto len = static_cast<uint16_t>(len_);
  assert(0u < static_cast<int32_t>(offset_));
  assert(len == len_);
  tokens.emplace_back(tok.getLocation().getRawEncoding(),
                      -static_cast<int32_t>(offset_), len, tok.getKind());
}

// Return the AST containing a declaration.
AST AST::From(const Decl &decl) {
  return AST(decl.ast);
}

AST::~AST(void) {}

AST::AST(const AST &that) : impl(that.impl) {}

AST::AST(AST &&that) noexcept : impl(that.impl) {
  that.impl = nullptr;
}

AST &AST::operator=(const AST &that) {
  impl = that.impl;
  return *this;
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

// Try to return the token at the specified location.
TokenImpl *ASTImpl::RawTokenAt(clang::SourceLocation loc) {
  if (loc.isInvalid()) {
    return nullptr;
  }

  // We shouldn't be getting requests with source locations in macro expansions
  // as that implies they are from the original parse of source, and not from
  // the parse of the pre-processed source.
  if (loc.isMacroID()) {
    return nullptr;
  }

  bool invalid = false;
  auto &sm = ci->getSourceManager();
  const auto line = sm.getSpellingLineNumber(loc, &invalid);
  if (!line || invalid || static_cast<size_t>(line) > tokens.size()) {
    return nullptr;
  }

  return &(tokens[line - 1u]);
}

// Try to return the token at the specified location.
Token ASTImpl::TokenAt(clang::SourceLocation loc) {
  auto self = shared_from_this();
  if (auto tok = RawTokenAt(loc)) {
    return Token(std::move(self), tok);
  } else {
    return Token(std::move(self));
  }
}

// Try to return the token range from the specified source range.
TokenRange ASTImpl::TokenRangeFrom(clang::SourceRange range) {
  auto self = shared_from_this();
  auto begin = TokenAt(range.getBegin());
  auto end = TokenAt(range.getEnd());

  if (begin && end) {
    if (begin.impl <= end.impl) {
      return TokenRange(std::move(self), begin.impl, &(end.impl[1]));
    } else {
      return TokenRange(std::move(self), end.impl, &(begin.impl[1]));
    }
  } else if (begin) {
    return TokenRange(std::move(self), begin.impl, &(begin.impl[1]));
  } else if (end) {
    return TokenRange(std::move(self), end.impl, &(end.impl[1]));
  } else {
    return TokenRange(std::move(self));
  }
}

// Return a reference to the underlying Clang AST context. This is needed for
// bootstrapping.
clang::ASTContext &AST::UnderlyingAST(void) const {
  return impl->ci->getASTContext();
}

clang::Preprocessor &AST::UnderlyingPP(void) const {
  return impl->ci->getPreprocessor();
}

// Returns the top-level translation unit decl inside of this AST.
TranslationUnitDecl AST::TranslationUnit(void) const {
  return TranslationUnitDecl(impl, impl->tu);
}

// Return the main file which was parsed and thus resulted in this AST.
File AST::MainFile(void) const {
  return impl->main_source_file;
}

// Return the list of all source files which were parsed as part of the
// construction of this AST.
const std::vector<::pasta::File> &AST::ParsedFiles(void) const {
  return impl->parsed_files;
}

std::optional<Decl> Decl::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kDecl) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &last_context = contexts.back();
  if (!last_context.data || last_context.kind != TokenContextKind::kInvalid ||
      last_context.depth != std::numeric_limits<uint16_t>::max() ||
      last_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(last_context.data));
  if (&(ast->contexts) != &contexts) {
    assert(false);
    return std::nullopt;
  }

  return DeclBuilder::Create<Decl, clang::Decl>(
      ast->shared_from_this(),
      reinterpret_cast<const clang::Decl *>(context.Data()));
}

std::optional<Stmt> Stmt::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kStmt) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &last_context = contexts.back();
  if (!last_context.data || last_context.kind != TokenContextKind::kInvalid ||
      last_context.depth != std::numeric_limits<uint16_t>::max() ||
      last_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(last_context.data));
  if (&(ast->contexts) != &contexts) {
    assert(false);
    return std::nullopt;
  }

  return StmtBuilder::Create<Stmt, clang::Stmt>(
      ast->shared_from_this(),
      reinterpret_cast<const clang::Stmt *>(context.Data()));
}

std::optional<Type> Type::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kType) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &last_context = contexts.back();
  if (!last_context.data || last_context.kind != TokenContextKind::kInvalid ||
      last_context.depth != std::numeric_limits<uint16_t>::max() ||
      last_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(last_context.data));
  if (&(ast->contexts) != &contexts) {
    assert(false);
    return std::nullopt;
  }

  return TypeBuilder::Create<Type, clang::Type>(
      ast->shared_from_this(),
      reinterpret_cast<const clang::Type *>(context.Data()));
}

}  // namespace pasta

#ifndef PASTA_IN_BOOTSTRAP
namespace std {

uint64_t hash<::pasta::Decl>::operator()(
    const ::pasta::Decl &decl) const noexcept {
  return std::hash<const void *>{}(decl.RawDecl());
}

}  // namespace std
#endif  // PASTA_IN_BOOTSTRAP
