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

#include <iostream>

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

// Append a marker token to the parsed token list.
void ASTImpl::AppendMarker(clang::SourceLocation loc, TokenRole role) {

  ++num_lines;
  size_t offset = preprocessed_code.size();
  preprocessed_code.push_back('\n');
  tokens.emplace_back(loc.getRawEncoding(), offset, 0u, clang::tok::unknown,
                      role);
}

// Append a token to the end of the AST. `offset` is positive if the data
// of the token can be found at a specific offset in `preprocessed_code`,
// and negative if `-offset` can be found in `backup_code`. `len` is the
// length in bytes of the token itself.
void ASTImpl::AppendToken(const clang::Token &tok, size_t offset_,
                          size_t len_, TokenRole role_) {
  const auto len = static_cast<uint32_t>(len_ & TokenImpl::kTokenSizeMask);
  // Make sure it fits in 31 bits.
  assert(0 <= static_cast<TokenDataOffset>(offset_));
  assert(len == len_);
  clang::SourceLocation loc = tok.getLocation();
  tokens.emplace_back(
      loc.getRawEncoding(),
      static_cast<TokenDataOffset>(offset_), len,
      tok.getKind(), role_);
}

// Append a token to the end of the AST. `offset` is the offset in
// `backup_token_data`, and `len` is the length in bytes of the token itself.
void ASTImpl::AppendBackupToken(const clang::Token &tok, size_t offset_,
                                size_t len_, TokenRole role_) {
  const auto len = static_cast<uint32_t>(len_ & TokenImpl::kTokenSizeMask);
  assert(0 < static_cast<TokenDataOffset>(offset_));
  assert(len == len_);
  clang::SourceLocation loc = tok.getLocation();
  tokens.emplace_back(
      loc.getRawEncoding(),
      -static_cast<TokenDataOffset>(offset_), len,
      tok.getKind(), role_);
}

AST AST::From(const Decl &decl) {
  return AST(decl.ast);
}

AST AST::From(const Stmt &stmt) {
  return AST(stmt.ast);
}

AST AST::From(const Macro &macro) {
  return AST(macro.ast);
}

AST AST::From(const Type &type) {
  return AST(type.ast);
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

// Return all top-level macro nodes (expansions, directives, substitutions,
// etc.).
MacroRange AST::Macros(void) const {
  const auto first = impl->root_macro_node.nodes.data();
  return MacroRange(
      impl, first, &(first[impl->root_macro_node.nodes.size()]));
}

// Try to return the file token at the specified location.
std::optional<FileToken> ASTImpl::FileTokenAt(clang::SourceLocation loc) {
  if (loc.isValid() && loc.isFileID()) {
    const clang::SourceManager &sm = ci->getSourceManager();
    const auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
    auto file_it = id_to_file.find(file_id.getHashValue());
    if (file_it == id_to_file.end()) {
      return std::nullopt;
    }
    return file_it->second.TokenAtOffset(file_offset);
  }
  return std::nullopt;
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
  }
  return Token(std::move(self));
}

// Try to return the token at the specified location.
Token ASTImpl::TokenAt(const TokenImpl *tok) {
  auto self = shared_from_this();
  auto begin = tokens.data();
  auto end = &(begin[tokens.size()]);
  if (begin <= tok && tok < end) {
    return Token(std::move(self), tok);
  }
  return Token(std::move(self));
}

// Try to return the token range from the specified source range.
TokenRange ASTImpl::TokenRangeFrom(clang::SourceRange range) {
  auto self = shared_from_this();
  auto begin = TokenAt(range.getBegin());
  auto end = TokenAt(range.getEnd());

  if (begin && end) {
    if (begin.impl <= end.impl) {
      return TokenRange(std::move(self), begin.impl, &(end.impl[1]));
    }
    return TokenRange(std::move(self), end.impl, &(begin.impl[1]));
  }

  if (begin) {
    return TokenRange(std::move(self), begin.impl, &(begin.impl[1]));
  }

  if (end) {
    return TokenRange(std::move(self), end.impl, &(end.impl[1]));
  }

  return TokenRange(std::move(self));
}

// Return a reference to the underlying Clang AST context. This is needed for
// bootstrapping.
clang::ASTContext &AST::UnderlyingAST(void) const {
  return impl->ci->getASTContext();
}

clang::Preprocessor &AST::UnderlyingPP(void) const {
  return impl->ci->getPreprocessor();
}

#ifndef PASTA_IN_BOOTSTRAP
// Returns the top-level translation unit decl inside of this AST.
TranslationUnitDecl AST::TranslationUnit(void) const {
  return TranslationUnitDecl(impl, impl->tu);
}
#endif

// Return the main file which was parsed and thus resulted in this AST.
File AST::MainFile(void) const {
  return impl->main_source_file;
}

// Return the list of all source files which were parsed as part of the
// construction of this AST.
const std::vector<::pasta::File> &AST::ParsedFiles(void) const {
  return impl->parsed_files;
}

#ifndef PASTA_IN_BOOTSTRAP
Token AST::Adopt(const clang::SourceLocation &loc) const {
  return impl->TokenAt(loc);
}

Attr AST::Adopt(const clang::Attr *attr) const {
  return Attr(impl, attr);
}

Decl AST::Adopt(const clang::Decl *decl) const {
  return Decl(impl, decl);
}

Stmt AST::Adopt(const clang::Stmt *stmt) const {
  return Stmt(impl, stmt);
}

Type AST::Adopt(const clang::Type *type, uint32_t quals) const {
  return TypeBuilder::Create<Type, clang::Type>(impl, type, quals);
}

std::optional<Decl> Decl::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kDecl) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
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

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
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

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return TypeBuilder::Create<Type, clang::Type>(
      ast->shared_from_this(),
      reinterpret_cast<const clang::Type *>(context.Data()));
}

std::optional<Attr> Attr::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kAttr) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return AttrBuilder::Create<Attr, clang::Attr>(
      ast->shared_from_this(),
      reinterpret_cast<const clang::Attr *>(context.Data()));
}

std::optional<Designator> Designator::From(const TokenContext &context) {
  if (context.Kind() != TokenContextKind::kDesignator) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return Designator(ast->shared_from_this(), context.Data());
}

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::From(
    const TokenContext &context) noexcept {
  if (context.Kind() != TokenContextKind::kCXXBaseSpecifier) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return CXXBaseSpecifier(
      ast->shared_from_this(),
      reinterpret_cast<const clang::CXXBaseSpecifier *>(context.Data()));
}

std::optional<TemplateArgument> TemplateArgument::From(
    const TokenContext &context) noexcept {
  if (context.Kind() != TokenContextKind::kTemplateArgument) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return TemplateArgument(
      ast->shared_from_this(),
      reinterpret_cast<const clang::TemplateArgument *>(context.Data()));
}

std::optional<TemplateParameterList> TemplateParameterList::From(
    const TokenContext &context) noexcept {
  if (context.Kind() != TokenContextKind::kTemplateArgument) {
    return std::nullopt;
  }

  auto &contexts = *(context.contexts);
  if (contexts.empty()) {
    return std::nullopt;
  }

  auto &first_context = contexts.front();
  if (!first_context.data || first_context.kind != TokenContextKind::kAST ||
      first_context.depth != 0u ||
      first_context.parent_index != kInvalidTokenContextIndex) {
    return std::nullopt;
  }

  auto ast = reinterpret_cast<ASTImpl *>(const_cast<void *>(first_context.data));
  return TemplateParameterList(
      ast->shared_from_this(),
      reinterpret_cast<const clang::TemplateParameterList *>(context.Data()));
}

#endif  // PASTA_IN_BOOTSTRAP
}  // namespace pasta
