/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Token.h"

#include <cassert>
#include <limits>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Printer/Printer.h"

namespace pasta {
namespace {

// Try to use the kind of the token to get its representation.
static bool ReadRawTokenByKind(clang::SourceManager &source_manager,
                               clang::Token tok, std::string *out) {
  llvm::StringRef backup;
  switch (const auto tok_kind = tok.getKind()) {
    case clang::tok::eof:
    case clang::tok::code_completion:
      return false;

    case clang::tok::identifier: {
      if (const auto ident_info = tok.getIdentifierInfo()) {
        backup = ident_info->getName();
      }
      break;
    }

    case clang::tok::raw_identifier:
      if (tok.getLength()) {
        backup = tok.getRawIdentifier();
      }
      break;

    case clang::tok::numeric_constant:
    case clang::tok::char_constant:
    case clang::tok::wide_char_constant:
    case clang::tok::utf8_char_constant:
    case clang::tok::utf16_char_constant:
    case clang::tok::utf32_char_constant:
    case clang::tok::string_literal:
    case clang::tok::wide_string_literal:
    case clang::tok::header_name:
    case clang::tok::utf8_string_literal:
    case clang::tok::utf16_string_literal:
    case clang::tok::utf32_string_literal:
      assert(tok.isLiteral());
      backup = llvm::StringRef(tok.getLiteralData(), tok.getLength());
      break;

#define PUNCTUATOR(case_label, rep) \
    case clang::tok::case_label: \
      backup = rep ; \
      break;

#define KEYWORD(case_label, feature) \
    case clang::tok::kw_ ## case_label: \
      backup = #case_label ; \
      break;

// TODO(pag): Deal with Objective-C @ keywords.

#include <clang/Basic/TokenKinds.def>

    case clang::tok::comment:
    case clang::tok::unknown:
    default:
      break;
  }

  if (!backup.empty()) {
    out->assign(backup.data(), backup.size());
    return true;
  }

  return false;
}

// Read the data of the token into the passed in string pointer. This tries
// to find the backing character data for the token, and fill it in that way.
static bool ReadRawTokenData(clang::SourceManager &source_manager,
                             const clang::LangOptions &lang_opts,
                             const clang::Token &tok,
                             const clang::SourceLocation begin_loc,
                             std::string *out) {

  const auto begin = source_manager.getDecomposedLoc(begin_loc);
  if (begin.first.isInvalid()) {
    return false;
  }

  auto invalid = false;
  const auto data = source_manager.getCharacterData(begin_loc, &invalid);
  if (invalid) {
    return false;
  }

  unsigned len = 0;
  if (tok.is(clang::tok::unknown)) {
    len = tok.getLength();
    out->reserve(len);

    for (auto i = 0U; i < len; ++i) {
      switch (data[i]) {
        case '\t':
        case ' ':
        case '\n':
        case '\\':
          out->push_back(data[i]);
          break;
        case '\r':
          break;

        // TODO(pag): This is kind of an error condition.
        default:
          len = i;
          break;
      }
    }

    return !out->empty();

  } else {
    len = clang::Lexer::MeasureTokenLength(begin_loc, source_manager,
                                           lang_opts);
  }

  if (!len) {
    return false;
  }

  // We'll try to get only valid UTF-8 characters, and printable ASCII
  // characters.
  //
  // TODO(pag): This may be overkill, but the lifetimes of the backing buffers
  //            for things like macro expansions is not clear to me, so this
  //            is a reasonable way to go about detecting unusual token data
  //            that may have been corrupted/reused.
  auto can_be_ident = true;

  // We can't allow `NUL` characters into our tokens as we'll be using them
  // to split tokens.
  for (auto i = 0U; i < len; ++i) {
    if (!data[i]) {
      len = i;
      break;
    }
  }

  if (!len) {
    return false;
  }

  out->assign(data, len);

  // Also try to catch errors when reading out identifiers or keywords.
  //
  // TODO(pag): We can't apply this to keywords as it very frequently triggers
  //            in macro definitions, where keyword tokens can contain line
  //            continuations and whitespace.
  if (!can_be_ident && tok.isAnyIdentifier()) {
    // ...
  }

  return true;
}

} // namespace

// Return the common ancestor between two contexts. This focuses on the data
// itself, so if there are two distinct contexts sharing the same data, or
// aliasing the same data, the context associated with the second token is
// returned.
const TokenContextImpl *TokenContextImpl::CommonAncestor(
    const TokenContextImpl *a, const TokenContextImpl *b,
    const std::vector<TokenContextImpl> &contexts) {
  if (!a || !b) {
    return nullptr;
  }
  for (auto i = std::max(a->depth, b->depth) * 2u + 1u;
       i--; ) {
    if (!a || !b) {
      return nullptr;

    } else if (a == b) {
      return a;

    } else if (a->data == b->data) {
      return a;

    } else if (a->Aliasee(contexts)->data ==
               b->Aliasee(contexts)->data) {
      return b;

    } else if (a->depth > b->depth) {
      a = a->Parent(contexts);

    } else if (a->depth < b->depth) {
      b = b->Parent(contexts);

    } else {
      a = a->Parent(contexts);
      b = b->Parent(contexts);
    }
  }

  return nullptr;
}

// Return the common ancestor between two tokens. This focuses on the data
// itself, so if there are two distinct contexts sharing the same data, or
// aliasing the same data, the context associated with the second token is
// returned.
const TokenContextImpl *TokenContextImpl::CommonAncestor(
    TokenImpl *a, TokenImpl *b, const std::vector<TokenContextImpl> &contexts) {
  auto a_index = a->context_index;
  auto b_index = b->context_index;
  if (a_index == kInvalidTokenContextIndex ||
      b_index == kInvalidTokenContextIndex) {
    return nullptr;
  }

  const TokenContextImpl *a_context = &(contexts[a_index]);
  const TokenContextImpl *b_context = &(contexts[b_index]);
  return CommonAncestor(a_context, b_context, contexts);
}

const TokenContextImpl *TokenContextImpl::Parent(
    const std::vector<TokenContextImpl> &contexts) const {
  if (parent_index == kInvalidTokenContextIndex) {
    return nullptr;
  }

  if (parent_index >= contexts.size()) {
    assert(false);
    return nullptr;
  }

  auto first_context = &(contexts.front());
  auto last_context = &(contexts.back());
  if (this < first_context || this > last_context) {
    assert(false);
    return nullptr;
  }

  if (parent_index >= static_cast<uint32_t>(this - first_context)) {
    assert(false);
    return nullptr;
  }

  return &(contexts[parent_index]);
}

const TokenContextImpl *TokenContextImpl::Aliasee(
    const std::vector<TokenContextImpl> &contexts) const {
  if (kind != TokenContextKind::kAlias) {
    return this;
  }

  auto alias_index = reinterpret_cast<uintptr_t>(data);
  assert(alias_index == static_cast<TokenContextIndex>(alias_index));

  if (alias_index >= contexts.size()) {
    assert(false);
    return this;
  }

  auto first_context = &(contexts.front());
  auto last_context = &(contexts.back());
  if (this < first_context || this > last_context) {
    assert(false);
    return this;
  }

  if (alias_index >= static_cast<uint32_t>(this - first_context)) {
    assert(false);
    return this;
  }

  return contexts[alias_index].Aliasee(contexts);
}

const char *TokenContextImpl::KindName(
      const std::vector<TokenContextImpl> &contexts) const {
  switch (kind) {
    case TokenContextKind::kInvalid:
      return "Invalid";
#define PASTA_TOKEN_CONTEXT_KIND_CASE(cls) \
    case TokenContextKind::k ## cls: return #cls ;
    PASTA_FOR_EACH_TOKEN_CONTEXT_KIND(PASTA_TOKEN_CONTEXT_KIND_CASE)
#undef PASTA_TOKEN_CONTEXT_KIND_CASE
    case TokenContextKind::kAlias:
      if (auto aliasee = Aliasee(contexts); aliasee != this) {
        return aliasee->KindName(contexts);
      } else {
        assert(false);
        return "Alias";
      }
    case TokenContextKind::kString:
      return "String";
    case TokenContextKind::kAST:
      return "AST";
  }
}

// Return the index of this token context.
uint32_t TokenContext::Index(void) const {
  if (impl) {
    return static_cast<TokenContextIndex>(impl - &(contexts->front()));
  } else {
    return kInvalidTokenContextIndex;
  }
}

// String representation of this token context kind.
const char *TokenContext::KindName(void) const {
  if (impl) {
    return impl->KindName(*contexts);
  } else {
    return "Invalid";
  }
}

// Return the kind of this token.
TokenContextKind TokenContext::Kind(void) const {
  if (impl) {
    return impl->Aliasee(*contexts)->kind;
  } else {
    return TokenContextKind::kInvalid;
  }
}

// Return the data of this context.
const void *TokenContext::Data(void) const {
  if (impl) {
    return impl->Aliasee(*contexts)->data;
  } else {
    return nullptr;
  }
}

// Return the parent context.
std::optional<TokenContext> TokenContext::Parent(void) const {
  if (!impl) {
    return std::nullopt;
  }

  auto parent = impl->Parent(*contexts);
  if (!parent) {
    return std::nullopt;
  }

  return TokenContext(parent, contexts);
}

// Return the context aliased by this context.
std::optional<TokenContext> TokenContext::Aliasee(void) const {
  if (!impl) {
    return std::nullopt;
  }

  auto aliasee = impl->Aliasee(*contexts);
  if (impl == aliasee) {
    return std::nullopt;
  }

  return TokenContext(aliasee, contexts);
}

// Try to update this context to point to its parent.
bool TokenContext::TryUpdateToParent(void) {
  if (!impl) {
    return false;
  }

  if (auto parent = impl->Parent(*contexts)) {
    impl = parent;
    return true;
  } else {
    return false;
  }
}

// Try to update this context to point to its aliasee.
bool TokenContext::TryUpdateToAliasee(void) {
  if (!impl) {
    return false;
  }

  if (auto aliasee = impl->Aliasee(*contexts); aliasee != impl) {
    impl = aliasee;
    return true;
  } else {
    return false;
  }
}

// Location of the token in a file.
std::optional<FileToken> Token::FileLocation(void) const {
  if (!impl) {
    return std::nullopt;
  }

  clang::SourceLocation loc = impl->Location();
  if (loc.isInvalid() || loc.isMacroID()) {
    return std::nullopt;
  }

  const clang::SourceManager &sm = ast->ci->getSourceManager();
  const auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
  auto file_it = ast->id_to_file.find(file_id.getHashValue());
  if (file_it == ast->id_to_file.end()) {
    return std::nullopt;
  }

  return file_it->second.TokenAtOffset(file_offset);
}

// Kind of this token.
TokenKind Token::Kind(void) const noexcept {
  if (impl) {
    return static_cast<TokenKind>(impl->Kind());
  } else {
    return TokenKind::kUnknown;
  }
}

// Return the role of this token.
TokenRole Token::Role(void) const noexcept {
  if (impl) {
    return impl->Role();
  } else {
    return TokenRole::kInvalid;
  }
}

// Kind of this token.
const char *Token::KindName(void) const noexcept {
  if (impl) {
    return clang::tok::getTokenName(impl->Kind());
  } else {
    return clang::tok::getTokenName(clang::tok::unknown);
  }
}

// If this token is a macro expansion token, or is the beginning or ending of
// a macro expansion range, then return the entire range of file tokens which
// led to this macro expansion. Otherwise, return an empty range.
FileTokenRange Token::MacroUseTokens(void) const noexcept {
  auto expansion_range = MacroExpandedTokens();
  auto begin = expansion_range.first;
  auto end = expansion_range.after_last;
  if (!begin) {
    return FileTokenRange(ast->main_source_file.impl);
  }

  assert((begin->Role() == TokenRole::kMacroExpansionToken) ||
         (begin->Role() == TokenRole::kEndOfMacroExpansionMarker));
  begin = &(begin[-1]);
  assert(begin->Role() == TokenRole::kBeginOfMacroExpansionMarker);
  assert(end->Role() == TokenRole::kEndOfMacroExpansionMarker);

  auto begin_loc = begin->Location();
  auto end_loc = end->Location();
  assert(begin_loc.isValid() && begin_loc.isFileID());
  assert(end_loc.isValid() && end_loc.isFileID());
  (void) begin_loc;
  (void) end_loc;

  auto begin_ft = Token(ast, begin).FileLocation();
  auto end_ft = Token(ast, end).FileLocation();

  // If we can't find file locations for the expansion markers, or if they
  // look like they're from different files, or if they aren't ordered properly
  // then bail out.
  if (!begin_ft ||
      !end_ft ||
      begin_ft->file != end_ft->file ||
      begin_ft->Index() >= end_ft->Index()) {
    assert(false);
    return FileTokenRange(ast->main_source_file.impl);
  }

  assert(begin_ft->impl < end_ft->impl);
  return FileTokenRange(begin_ft->file, begin_ft->impl, end_ft->impl);
}

// If this token is a macro expansion token, or is the beginning or ending of
// a macro expansion range, then return the entire range. Otherwise, this will
// return an empty range.
TokenRange Token::MacroExpandedTokens(void) const noexcept {
  switch (Role()) {
    case TokenRole::kBeginOfMacroExpansionMarker:
    case TokenRole::kMacroExpansionToken:
    case TokenRole::kEndOfMacroExpansionMarker:
      break;
    default:
      return TokenRange(ast);
  }

  auto min = &(ast->tokens.front());
  auto max = &(ast->tokens.back());

  // Scan backwards. There should always be /some/ tokens before the beginning
  // of a macro expansion marker, e.g. a file entry marker.
  auto begin = impl;
  for (; begin > min; --begin) {
    switch (begin->Role()) {
      case TokenRole::kBeginOfMacroExpansionMarker:
        goto found_begin;
      case TokenRole::kMacroExpansionToken:
      case TokenRole::kEndOfMacroExpansionMarker:
        continue;
      default:
        assert(false);
        return TokenRange(ast);
    }
  }
found_begin:

  // If we failed to find the beginning then bail out. Shouldn't happen.
  if (begin->Role() != TokenRole::kBeginOfMacroExpansionMarker) {
    assert(false);
    return TokenRange(ast);
  }

  // Scan forwards. There should always be /some/ tokens after the end
  // of a macro expansion marker, e.g. a file exit marker.
  auto end = impl;
  for (; end < max; ++end) {
    switch (end->Role()) {
      case TokenRole::kEndOfMacroExpansionMarker:
        goto found_end;
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kMacroExpansionToken:
        continue;
      default:
        assert(false);
        return TokenRange(ast);
    }
  }
found_end:

  // If we failed to find the end then bail out. Shouldn't happen.
  if (end->Role() != TokenRole::kEndOfMacroExpansionMarker) {
    assert(false);
    return TokenRange(ast);
  }

  // Return the range of tokens *inside* the two markers.
  return TokenRange(ast, &(begin[1]), end);
}

// Return the context of this token, or `nullptr`.
const TokenContextImpl *TokenImpl::Context(
    const std::vector<TokenContextImpl> &contexts) const noexcept {
  if (context_index == kInvalidTokenContextIndex) {
    return nullptr;
  } else if (context_index >= contexts.size()) {
    return nullptr;
  } else {
    return &(contexts[context_index]);
  }
}

// Return this token's context, or a null context.
std::optional<TokenContext> Token::Context(void) const noexcept {
  if (!impl) {
    return std::nullopt;
  } else if (auto context = impl->Context(ast->contexts)) {
    std::shared_ptr<const std::vector<TokenContextImpl>> contexts(
        ast, &(ast->contexts));
    return TokenContext(context, std::move(contexts));
  } else {
    return std::nullopt;
  }
}

std::string_view TokenImpl::Data(const ASTImpl &ast) const noexcept {
  if (data_len) {
    if (0 <= data_offset) {
      return std::string_view(ast.preprocessed_code).substr(
          static_cast<uint32_t>(data_offset), data_len);
    } else {
      return std::string_view(ast.backup_token_data).substr(
          static_cast<uint32_t>(-data_offset), data_len);
    }
  } else {
    return {};
  }
}

std::string_view TokenImpl::Data(
    const PrintedTokenRangeImpl &range) const noexcept {
  if (data_len) {
    return std::string_view(range.data).substr(
        static_cast<uint32_t>(data_offset), data_len);
  } else {
    return {};
  }
}

// Return the data associated with this token.
std::string_view Token::Data(void) const {
  if (!impl) {
    return {};
  } else {
    return impl->Data(*ast);
  }
}

// Index of this token in the AST's token list.
uint64_t Token::Index(void) const {
  if (impl) {
    return static_cast<uint64_t>(impl - ast->tokens.data());
  } else {
    return std::numeric_limits<uint64_t>::max();
  }
}

// Prefix increment operator.
TokenIterator &TokenIterator::operator++(void) noexcept {
  ++token.impl;
  return *this;
}

// Postfix increment operator.
TokenIterator TokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.impl;
  return ret;
}

// Prefix decrement operator.
TokenIterator &TokenIterator::operator--(void) noexcept {
  --token.impl;
  return *this;
}

// Postfix decrement operator.
TokenIterator TokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.impl;
  return ret;
}

TokenIterator TokenIterator::operator-(size_t offset) const noexcept {
  return TokenIterator(token.ast, token.impl - offset);
}

TokenIterator &TokenIterator::operator+=(size_t offset) noexcept {
  token.impl += offset;
  return *this;
}

TokenIterator &TokenIterator::operator-=(size_t offset) noexcept {
  token.impl -= offset;
  return *this;
}

Token TokenIterator::operator[](size_t offset) const noexcept {
  return Token(token.ast, &(token.impl[offset]));
}

ptrdiff_t TokenIterator::operator-(const TokenIterator &that) const noexcept {
  return token.impl - token.impl;
}

// Number of tokens in this range.
size_t TokenRange::Size(void) const noexcept {
  return static_cast<size_t>(after_last - first);
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<Token> TokenRange::At(size_t index) const noexcept {
  auto size = static_cast<size_t>(after_last - first);
  if (index < size) {
    return Token(ast, &(first[index]));
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
Token TokenRange::operator[](size_t index) const {
  return Token(ast, &(first[index]));
}

bool TryReadRawToken(clang::SourceManager &source_manager,
                     const clang::LangOptions &lang_opts,
                     const clang::Token &tok, std::string *out) {
  out->clear();

  // This could be our sentinel EOF that we add at the end of all tokens, or
  // it could be one of our special macro-expansion EOFs.
  if (tok.is(clang::tok::eof)) {
    return true;

  // Annotations are things like `#pragma`s.
  } else if (tok.isAnnotation()) {

  // A token that has trigraphs or digraphs is one that needs to be cleaned up.
  // The identifier info or literal data info of a token is the post-cleaning
  // representation. If the token therefore never needed cleaning, then we can
  // get its representation via some internal lookup.
  } else if (!tok.needsCleaning()) {
    clang::IdentifierInfo *ident_info = nullptr;

    if (tok.is(clang::tok::raw_identifier) && tok.getLength()) {
      const auto raw_ident = tok.getRawIdentifier();
      out->assign(raw_ident.data(), raw_ident.size());
      if (!out->empty()) {
        return true;
      }

    } else if (tok.is(clang::tok::identifier) &&
               nullptr != (ident_info = tok.getIdentifierInfo())) {

      if (!out->empty()) {
        out->assign(ident_info->getNameStart(), ident_info->getLength());
        return true;
      }

    } else if (tok.isLiteral() && tok.getLiteralData()) {
      if (!out->empty()) {
        out->assign(tok.getLiteralData(), tok.getLength());
        return true;
      }
    }
  }

  const auto orig_tok_begin = tok.getLocation();
  const auto tok_begin = source_manager.getSpellingLoc(orig_tok_begin);

  // Try to find the token's representation using its location.
  if (tok_begin.isValid()) {
    if (ReadRawTokenData(source_manager, lang_opts, tok, tok_begin, out)) {
      return true;
    }

    bool is_invalid = false;
    const clang::SourceRange token_range(tok_begin);

    auto spelling = clang::Lexer::getSourceText(
        clang::CharSourceRange::getTokenRange(token_range),
        source_manager, lang_opts, &is_invalid);

    if (!is_invalid && !spelling.empty()) {
      out->assign(spelling.data(), spelling.size());
      return true;
    }
  }

  // If all else fails, try to get the representation of the token using
  // its kind.
  return ReadRawTokenByKind(source_manager, tok, out);
}

// Try to lex the data at `loc` into the token `*out`.
bool TryLexRawToken(clang::SourceManager &source_manager,
                    const clang::LangOptions &lang_opts,
                    clang::SourceLocation loc, clang::Token *out) {
  if (loc.isFileID()) {
    return !clang::Lexer::getRawToken(
        loc, *out, source_manager, lang_opts, true);
  } else {
    return false;
  }
}

// Try to lex the data at `loc` into the token `*out`.
bool TryLexRawToken(clang::ASTContext &ast_context,
                    clang::SourceLocation loc, clang::Token *out) {
  return TryLexRawToken(ast_context.getSourceManager(),
                        ast_context.getLangOpts(), loc, out);
}

Token::~Token(void) {}

} // namespace pasta
