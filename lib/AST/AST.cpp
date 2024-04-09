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
    : main_source_file(std::move(main_source_file_)),
      invalid_tokens(this),
      parsed_tokens(this),
      macro_tokens(this) {

  invalid_tokens.InitInvalid();
}

ASTImpl::~ASTImpl(void) {}

// Return the AST containing a token.
AST AST::From(const Token &token) {
  return AST(std::shared_ptr<ASTImpl>(token.storage, token.storage->ast));
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

// Return the AST containing a template argument.
AST AST::From(const TemplateArgument &arg) {
  return AST(arg.ast);
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
  return impl->parsed_tokens.Data();
}

// Return all lexed tokens.
TokenRange AST::Tokens(void) const {
  return TokenRange(
      std::shared_ptr<ParsedTokenStorage>(impl, &(impl->parsed_tokens)),
      0u, impl->parsed_tokens.size());
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
  if (!loc.isValid() || !loc.isFileID()) {
    return std::nullopt;
  }

  const clang::SourceManager &sm = ci->getSourceManager();
  const auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
  auto file_it = id_to_file.find(file_id.getHashValue());
  if (file_it == id_to_file.end()) {
    assert(sm.isWrittenInBuiltinFile(loc) ||
           sm.isWrittenInCommandLineFile(loc) ||
           sm.isWrittenInScratchSpace(loc));
    return std::nullopt;
  }

  return file_it->second.TokenAtOffset(file_offset);
}

std::optional<DerivedTokenIndex> ASTImpl::ParsedTokenOffset(
    clang::SourceLocation loc) const {
  if (loc.isInvalid()) {
    return std::nullopt;
  }

  auto &sm = ci->getSourceManager();

  // Macro location requests can come from split tokens. We ideally don't want
  // to see them, as it suggests that we haven't renamed the `l_angle` or
  // `r_angle` tokens. There are cases where the requests are valid, though,
  // e.g. `A<B>>>`. 
  if (loc.isMacroID()) {
    loc = sm.getFileLoc(loc);
    if (!loc.isFileID()) {
      assert(false);
      return std::nullopt;
    }
  }

  const auto [file_id, file_offset] = sm.getDecomposedLoc(loc);

  if (file_id != sm.getMainFileID()) {
    assert(false);
    return std::nullopt;
  }

  return parsed_tokens.DataOffsetToTokenIndex(file_offset);
}

ParsedTokenIterator ASTImpl::InvalidRawToken(void) const {
  return ParsedTokenIterator(&invalid_tokens, 0u, 0u);
}

ParsedTokenIterator ASTImpl::RawTokenAt(clang::SourceLocation loc) const {
  if (auto offset = ParsedTokenOffset(loc)) {
    return ParsedTokenIterator(&parsed_tokens, offset.value());
  } else {
    return InvalidRawToken();
  }
}

ParsedTokenIterator ASTImpl::RawTokenAt(DerivedTokenIndex offset_) const {
  return ParsedTokenIterator(&parsed_tokens, offset_);
}

// Try to return the token at the specified location.
Token ASTImpl::TokenAt(clang::SourceLocation loc) {
  return TokenAt(ParsedTokenOffset(loc));
}

// Try to return the token at the specified offset.
Token ASTImpl::TokenAt(DerivedTokenIndex offset) {
  assert(offset < parsed_tokens.size());
  return Token(
      std::shared_ptr<ParsedTokenStorage>(shared_from_this(), &parsed_tokens),
      offset);
}

// Try to return the token at the specified offset.
Token ASTImpl::TokenAt(std::optional<DerivedTokenIndex> offset) {
  if (offset) {
    return TokenAt(offset.value());
  } else {
    return Token(shared_from_this());
  }
}

// Try to return the token range from the specified source range.
TokenRange ASTImpl::TokenRangeFrom(clang::SourceRange range) {
  auto begin = TokenAt(range.getBegin());
  auto end = TokenAt(range.getEnd());
  
  if (begin && end) {
    if (auto range = TokenRange::From(std::move(begin), std::move(end))) {
      return range.value();
    }
    assert(false);
  } else if (begin) {
    return TokenRange::From(std::move(begin));

  } else if (end) {
    return TokenRange::From(std::move(end));
  }

  return TokenRange(shared_from_this());
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
  return Decl(impl, decl->RemappedDecl);
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

std::optional<CXXCtorInitializer> CXXCtorInitializer::From(
    const TokenContext &context) noexcept {
  if (context.Kind() != TokenContextKind::kCXXCtorInitializer) {
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
  return CXXCtorInitializer(
      ast->shared_from_this(),
      reinterpret_cast<const clang::CXXCtorInitializer *>(context.Data()));
}

#endif  // PASTA_IN_BOOTSTRAP
}  // namespace pasta
