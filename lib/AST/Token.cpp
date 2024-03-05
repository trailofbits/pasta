/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Macro.h"
#include "Token.h"

#include <cassert>
#include <limits>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Token.h>
#pragma GCC diagnostic pop

#include "AST.h"
#include "Printer/Printer.h"
#include <iostream>
namespace pasta {
namespace {

// static const std::string_view kEmptyStringView("");

// Try to use the kind of the token to get its representation.
static bool ReadRawTokenByKind(clang::SourceManager &source_manager,
                               clang::Token tok, std::string *out) {
  llvm::StringRef backup;
  switch (tok.getKind()) {
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
  }

  len = tok.getLength();
  if (!len) {
    return false;
  }

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

  // There might be leading/trailing whitespace.
  if (tok.needsCleaning() && tok.is(clang::tok::identifier)) {
    auto name = tok.getIdentifierInfo()->getName();
    out->assign(name.data(), name.size());
  } else {
    out->assign(data, len);
  }

  return true;
}

} // namespace

const std::vector<pasta::TokenRole> gTokenRoles{
#define ROLE(role) TokenRole::k##role ,
  PASTA_FOR_EACH_TOKEN_ROLE(ROLE)
#undef ROLE
};

std::string_view TokenRoleName(TokenRole role) {
  const static std::string_view kTokenRoleNames[] = {
#define ROLE(role) #role,
  PASTA_FOR_EACH_TOKEN_ROLE(ROLE)
#undef ROLE
  };
  return kTokenRoleNames[static_cast<size_t>(role)];
}

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
    }

    if (a == b) {
      return a;
    }

    if (a->data == b->data) {
      return a;
    }

    if (a->Aliasee(contexts)->data == b->Aliasee(contexts)->data) {
      return b;
    }

    if (a->depth > b->depth) {
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
    PrintedTokenImpl *a, PrintedTokenImpl *b,
    const std::vector<TokenContextImpl> &contexts) {

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
      }
      assert(false);
      return "Alias";
    case TokenContextKind::kString:
      return "String";
    case TokenContextKind::kAST:
      return "AST";
  }
  return "";
}

// Return the index of this token context.
uint32_t TokenContext::Index(void) const {
  if (impl) {
    return static_cast<TokenContextIndex>(impl - &(contexts->front()));
  }
  return kInvalidTokenContextIndex;
}

// String representation of this token context kind.
const char *TokenContext::KindName(void) const {
  if (impl) {
    return impl->KindName(*contexts);
  }

  return "Invalid";
}

// Return the kind of this token.
TokenContextKind TokenContext::Kind(void) const {
  if (impl) {
    return impl->Aliasee(*contexts)->kind;
  }
  return TokenContextKind::kInvalid;
}

// Return the data of this context.
const void *TokenContext::Data(void) const {
  if (impl) {
    return impl->Aliasee(*contexts)->data;
  }
  return nullptr;
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
  }

  return false;
}

// Try to update this context to point to its aliasee.
bool TokenContext::TryUpdateToAliasee(void) {
  if (!impl) {
    return false;
  }

  if (auto aliasee = impl->Aliasee(*contexts); aliasee != impl) {
    impl = aliasee;
    return true;
  }

  return false;
}

// Find the token from which this token was derived.
DerivedToken Token::DerivedLocation(void) const {
  auto bit_loc = storage->location[offset];
  if (bit_loc == kInvalidBitPackedLocation) {
    return {};
  }

  if (auto file_pair = UnpackFileAndTokenOffset(bit_loc)) {
    auto [file_index, token_index] = *file_pair;
    auto &file = storage->ast->parsed_files[file_index];
    auto file_loc = file.TokenAtIndex(token_index);
    if (file_loc) {
      return std::move(file_loc.value());
    }

  } else if (auto macro_loc = MacroLocation()) {
    return std::move(macro_loc.value());
  }

  assert(false);
  return {};
}

// Location of the token in a file. This will try to track the token back to
// any file token, so it's really a multi-step process, unlike
// `DerivedLocation`.
std::optional<FileToken> Token::FileLocation(void) const {
  auto target_offset = offset;
  auto target_storage = storage.get();
  auto ast = target_storage->ast;
  auto &macro_tokens = ast->macro_tokens;
  for (;;) {
    BitPackedLocation raw_loc = target_storage->location[target_offset];
    if (IsMacroTokenOffset(raw_loc)) {
      target_offset = MacroTokenOffset(raw_loc);
      target_storage = &macro_tokens;
      continue;
    } else if (auto file_pair = UnpackFileAndTokenOffset(raw_loc)) {
      auto [file_index, token_index] = *file_pair;
      return ast->parsed_files[file_index].TokenAtIndex(token_index);
    } else {
      return std::nullopt;
    }
  }
  return std::nullopt;
}

// Location of the token in a macro expansion.
std::optional<MacroToken> Token::MacroLocation(void) const {
  auto bit_loc = storage->location[offset];
  if (IsInvalidOrFileBitPackedLocation(bit_loc)) {
    return std::nullopt;
  }

  auto ast = storage->ast;
  auto &macro_tokens = ast->macro_tokens;

  return MacroToken(
      std::shared_ptr<ASTImpl>(storage, ast),
      &(ast->root_macro_node.token_nodes[
          macro_tokens.macro_token_offset[MacroTokenOffset(bit_loc)]]));
}

// This token may represent a marker for the location of a macro directive.
// If so, return that directive.
std::optional<MacroDirective> Token::Directive(void) const {
  if (Role() != TokenRole::kMacroDirectiveMarker) {
    return std::nullopt;
  }

  auto node_it = storage->ast->macro_directives.find(offset);
  if (node_it == storage->ast->macro_directives.end()) {
    assert(false);
    return std::nullopt;
  }

  return MacroDirective(std::shared_ptr<ASTImpl>(storage, storage->ast),
                        &(node_it->second));
}

// Kind of this token.
TokenKind Token::Kind(void) const noexcept {
  return storage->Kind(offset);
}

// Return the role of this token.
TokenRole Token::Role(void) const noexcept {
  return storage->Role(offset);
}
namespace {
static const char *KindName(TokenKind kind) {
  switch (kind) {
    case TokenKind::kLAngle:
      return "l_angle";
    case TokenKind::kRAngle:
      return "r_angle";
    default:
      return clang::tok::getTokenName(static_cast<clang::tok::TokenKind>(kind));
  }
}
}  // namespace

// Kind of this token.
const char *Token::KindName(void) const noexcept {
  return ::pasta::KindName(Kind());
}

// Return the data associated with this token.
std::string_view Token::Data(void) const {
  return storage->Data(offset);
}

const void *Token::RawToken(void) const noexcept {
  return &(storage->data[storage->data_offset[offset]]);
}

// Returns whether or no this token is valid.
Token::operator bool(void) const noexcept {
  assert(!!storage);
  return storage.get() != &(storage->ast->invalid_tokens);
}

// Prefix increment operator.
TokenIterator &TokenIterator::operator++(void) noexcept {
  ++token.offset;
  return *this;
}

// Postfix increment operator.
TokenIterator TokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.offset;
  return ret;
}

// Prefix decrement operator.
TokenIterator &TokenIterator::operator--(void) noexcept {
  --token.offset;
  return *this;
}

// Postfix decrement operator.
TokenIterator TokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.offset;
  return ret;
}

namespace {

inline static std::shared_ptr<ParsedTokenStorage> ValidFrom(
    std::shared_ptr<ASTImpl> ast) {
  auto raw = &(ast->parsed_tokens);
  return std::shared_ptr<ParsedTokenStorage>(std::move(ast), raw);
}

inline static std::shared_ptr<ParsedTokenStorage> InvalidFrom(
    std::shared_ptr<ASTImpl> ast) {
  auto raw = &(ast->invalid_tokens);
  return std::shared_ptr<ParsedTokenStorage>(std::move(ast), raw);
}

}  // namespace

Token::Token(std::shared_ptr<ASTImpl> ast_)
    : Token(InvalidFrom(std::move(ast_))) {}

TokenRange::TokenRange(std::shared_ptr<ASTImpl> ast_)
    : TokenRange(InvalidFrom(std::move(ast_)), 0u, 0u) {}

TokenRange::TokenRange(std::shared_ptr<ASTImpl> ast_,
                       unsigned first_, unsigned after_last_)
    : TokenRange(ValidFrom(std::move(ast_)), first_, after_last_) {}

TokenRange TokenRange::From(Token tok) {
  if (tok) {
    return TokenRange(std::move(tok.storage), tok.offset, tok.offset + 1u);
  } else {
    return TokenRange(std::move(tok.storage));
  }
}

std::optional<TokenRange> TokenRange::From(Token begin, Token end) {
  if (begin.storage != end.storage || begin.offset > end.offset) {
    return std::nullopt;
  }
  return TokenRange(begin.storage, begin.offset, end.offset + 1u);
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<Token> TokenRange::At(size_t index) const noexcept {
 auto indexed_offset = first + index;
  if (indexed_offset >= after_last) {
    return std::nullopt;
  }
  return Token(storage, static_cast<unsigned>(indexed_offset));
}

// Unsafe indexed access into the token range.
Token TokenRange::operator[](size_t index) const {
  auto indexed_offset = first + index;
  if (indexed_offset >= after_last) {
    assert(false);
    return Token(
        std::shared_ptr<ParsedTokenStorage>(
            storage, &(storage->ast->invalid_tokens)),
        0u);
  }
  return Token(storage, static_cast<unsigned>(indexed_offset));
}

// Returns `true` if this range contains a specific token.
bool TokenRange::Contains(const Token &tok) const noexcept {
  return storage == tok.storage && first <= tok.offset &&
         tok.offset < after_last;
}

std::vector<MacroSubstitution>
TokenRange::AlignedSubstitutions(bool heuristic) noexcept {
  auto maybe_front = Front();
  std::vector<MacroSubstitution> result;
  if (!maybe_front) {
    return result;
  }

  Token front = std::move(maybe_front.value());
  Token back = Back().value();

  auto maybe_front_macro = front.MacroLocation();
  auto maybe_back_macro = front.MacroLocation();
  if (!maybe_front_macro || !maybe_back_macro) {
    return result;
  }

  MacroToken fm = std::move(maybe_front_macro.value());
  MacroToken bm = std::move(maybe_back_macro.value());

  (void) fm;
  (void) bm;

  return result;
}

// Return the underlying token data.
std::string_view TokenRange::Data(void) const noexcept {
  if (first >= after_last) {
    return "";
  }

  auto first_data = storage->Data(first);
  auto last_data = storage->Data(after_last - 1u);

  if (first_data.data() >= last_data.data()) {
    assert(false);
    return "";
  }

  auto begin_of_first_data = first_data.data();
  auto end_of_last_data = last_data.data() + last_data.size();
  return std::string_view(begin_of_first_data, end_of_last_data);
}

// Strip off trailing whitespace from a token that has been read.
void SkipTrailingWhitespace(std::string &tok_data) {
  while (!tok_data.empty()) {
    switch (tok_data.back()) {
      case '\\':
      case ' ':
      case '\t':
      case '\r':
      case '\n':
        tok_data.pop_back();
        break;
      default:
        return;
    }
  }
}

// Strip off leading whitespace from a token that has been read.
void SkipLeadingWhitespace(std::string &tok_data) {
  std::reverse(tok_data.begin(), tok_data.end());
  SkipTrailingWhitespace(tok_data);
  std::reverse(tok_data.begin(), tok_data.end());
}

// Strip off leading whitespace from a token that has been read.
void SkipLeadingWhitespace(clang::Token &tok, clang::SourceLocation &tok_loc,
                          std::string &tok_data) {
  auto old_size = tok_data.size();
  SkipLeadingWhitespace(tok_data);
  tok_loc = tok_loc.getLocWithOffset(
      static_cast<int>(old_size - tok_data.size()));
  tok.setLocation(tok_loc);
}

bool TryReadRawToken(clang::SourceManager &source_manager,
                     const clang::LangOptions &lang_opts,
                     const clang::Token &tok, std::string *out) {
  out->clear();

  // This could be our sentinel EOF that we add at the end of all tokens, or
  // it could be one of our special macro-expansion EOFs.
  if (tok.isOneOf(clang::tok::eof, clang::tok::eod)) {
    return true;
  }

  // Annotations are things like `#pragma`s.
  if (tok.isAnnotation()) {

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
  if (ReadRawTokenData(source_manager, lang_opts, tok, orig_tok_begin, out)) {
    return true;
  }

  // Try to find the token's representation using its location.
  const auto tok_begin = source_manager.getSpellingLoc(orig_tok_begin);
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

  // NOTE(pag): Giving a macro source location ID to a raw lexer will go and
  //            find the expansion/usage location, and not just lex whatever
  //            backing buffer `loc` is referencing.
  if (!loc.isFileID()) {
    return false;
  }

  return !clang::Lexer::getRawToken(
      loc, *out, source_manager, lang_opts, true);
}

// Try to lex the data at `loc` into the token `*out`.
bool TryLexRawToken(clang::ASTContext &ast_context,
                    clang::SourceLocation loc, clang::Token *out) {
  return TryLexRawToken(ast_context.getSourceManager(),
                        ast_context.getLangOpts(), loc, out);
}

Token::~Token(void) {}

// Recursively migrate token contexts.
TokenContextIndex MigrateContexts(
    TokenContextIndex id,
    const std::vector<TokenContextImpl> &from_contexts,
    std::vector<TokenContextImpl> &to_contexts,
    std::unordered_multimap<const void *, TokenContextIndex> &data_to_context,
    std::vector<TokenContextIndex> &context_map) {

  if (id == kInvalidTokenContextIndex || id >= context_map.size()) {
    return kInvalidTokenContextIndex;
  }

  assert(id < from_contexts.size());
  const TokenContextImpl *from_c = &(from_contexts[id]);
  TokenContextIndex &ret_id = context_map[id];

  if (ret_id != kInvalidTokenContextIndex) {
#ifndef NDEBUG
    TokenContextImpl *to_c = &(to_contexts[ret_id]);
    assert(to_c->kind == from_c->kind);
    assert(to_c->depth == from_c->depth);
    assert(to_c->data == from_c->data || to_c->kind == TokenContextKind::kAlias);
#endif
    return ret_id;
  }

  TokenContextIndex parent_id = MigrateContexts(
      from_c->parent_index, from_contexts, to_contexts, data_to_context,
      context_map);

  if (from_c->kind == TokenContextKind::kAlias) {
    TokenContextIndex aliasee_id = MigrateContexts(
        static_cast<TokenContextIndex>(reinterpret_cast<uintptr_t>(from_c->data)),
        from_contexts, to_contexts, data_to_context, context_map);

    ret_id = static_cast<TokenContextIndex>(to_contexts.size());
    (void) to_contexts.emplace_back(parent_id, from_c->depth - 1u, aliasee_id);

  } else {

    // Search for the matching one.
    for (auto [it, end] = data_to_context.equal_range(from_c->data);
         it != end; ++it) {

      TokenContextIndex maybe_id = it->second;
      assert(maybe_id != kInvalidTokenContextIndex);
      assert(maybe_id < to_contexts.size());

      TokenContextImpl *to_c = &(to_contexts[maybe_id]);
      if (to_c->data == from_c->data && to_c->parent_index == parent_id &&
          to_c->depth == from_c->depth && to_c->kind == from_c->kind) {
        ret_id = maybe_id;
        return maybe_id;
      }
    }

    // Didn't find it.
    ret_id = static_cast<TokenContextIndex>(to_contexts.size());
    (void) to_contexts.emplace_back(from_c->data, parent_id, from_c->depth,
                                    from_c->kind);
    data_to_context.emplace(from_c->data, ret_id);
  }

  assert(ret_id != kInvalidTokenContextIndex);
  return ret_id;
}

BitPackedLocation ParsedTokenStorage::CreateFileLocation(
    clang::SourceLocation loc) {
  if (!loc.isFileID()) {
    assert(false);
    return kInvalidBitPackedLocation;
  }

  auto &sm = ast->ci->getSourceManager();
  auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
  auto raw_file_id = file_id.getHashValue();
  auto file_it = ast->id_to_file.find(raw_file_id);
  if (file_it == ast->id_to_file.end()) {
    assert(sm.isWrittenInBuiltinFile(loc) ||
           sm.isWrittenInCommandLineFile(loc) ||
           sm.isWrittenInScratchSpace(loc));
    return kInvalidBitPackedLocation;
  }

  auto file_tok = file_it->second.TokenAtOffset(file_offset);
  if (!file_tok) {
    assert(false);
    return kInvalidBitPackedLocation;
  }

  auto index_it = ast->id_to_file_offset.find(raw_file_id);
  if (index_it == ast->id_to_file_offset.end()) {
    assert(false);
    return kInvalidBitPackedLocation;
  }

  auto file_index = index_it->second;
  assert(ast->parsed_files[file_index] == file_it->second);

  auto tok_index = file_tok->Index();
  assert(tok_index <= file_offset);

  return (static_cast<BitPackedLocation>(file_index + 1u) << 32u) |
         static_cast<BitPackedLocation>(tok_index + 1u);
}

BitPackedLocation ParsedTokenStorage::CreateInitialMacroLocation(
    clang::SourceLocation loc) {
  static_assert(sizeof(uint32_t) == sizeof(OpaqueSourceLoc));
  return (static_cast<BitPackedLocation>(~0u) << 32u) |
         static_cast<BitPackedLocation>(loc.getRawEncoding());
}

BitPackedLocation ParsedTokenStorage::CreateMacroLocation(
    DerivedTokenIndex offset) {
  return static_cast<BitPackedLocation>(offset + 1u) << 32u;
}

// Clang's `Parser::ParseGreaterThanInTemplateList` is responsible for doing
// deffered splitting of these tokens into other tokens when parsing template
// parameter lists.
static unsigned NumSplits(TokenKind kind) {
  switch (kind) {
    case TokenKind::kGreaterEqual:
    case TokenKind::kGreaterGreater:
    case TokenKind::kLessLess:
      return 1u;
    case TokenKind::kGreaterGreaterEqual:
    case TokenKind::kGreaterGreaterGreater:
    case TokenKind::kLessLessLess:
      return 2u;
    default:
      return 0u;
  }
}

static TokenKind SplitTokenPrefixKind(TokenKind kind) {
  switch (kind) {
    case TokenKind::kGreaterEqual:
    case TokenKind::kGreaterGreater:
    case TokenKind::kGreaterGreaterEqual:
    case TokenKind::kGreaterGreaterGreater:
      return TokenKind::kGreater;
    case TokenKind::kLessLess:
    case TokenKind::kLessLessLess:
      return TokenKind::kLess;
    default:
      assert(false);
      return TokenKind::kUnknown;
  }
}

static TokenKind SplitTokenSuffixKind(TokenKind kind) {
  switch (kind) {
    case TokenKind::kGreaterEqual:
      return TokenKind::kEqual;
    case TokenKind::kGreaterGreater:
      return TokenKind::kGreater;
    case TokenKind::kGreaterGreaterEqual:
      return TokenKind::kGreaterEqual;
    case TokenKind::kGreaterGreaterGreater:
      return TokenKind::kGreaterGreater;
    case TokenKind::kLessLess:
      return TokenKind::kLess;
    case TokenKind::kLessLessLess:
      return TokenKind::kLessLess;
    default:
      assert(false);
      return TokenKind::kUnknown;
  }
}

void ParsedTokenStorage::AppendSplitTokens(
    BitPackedLocation loc, TokenKind kind_, bool is_in_pragma) {
  auto num_splits = NumSplits(kind_);
  for (auto i = 0u; i < num_splits; ++i) {
    kind.emplace_back(TokenKind::kUnknown);
    role.emplace_back(TokenRole::kInvalid);
    is_in_pragma_directive.emplace_back(false);
    location.emplace_back(kInvalidBitPackedLocation);
    FinishToken();
  }
}

void ParsedTokenStorage::InventLeadingWhitespace(const clang::Token &tok) {
  auto tk = tok.getKind();
  if (!data.empty() && !std::isspace(data.back())) {
    auto space = '\0';
    if (tok.hasLeadingSpace() || tok.hasLeadingEmptyMacro()) {
      space = ' ';
    } else if (tok.isAtStartOfLine()) {
      space = '\n';
    } else if (clang::tok::isAnyIdentifier(tk) ||
               clang::tok::getKeywordSpelling(tk)) {
      space = ' ';
    }
    if (space) {
      data.push_back(space);
      data_offset.back() += 1u;
    }
  }
}

namespace {

static bool IsWhitespace(std::string_view data) {
  for (auto ch : data) {
    switch (ch) {
      case '\r':
      case '\n':
      case '\t':
      case ' ':
      case '\\':
        continue;
      default:
        return false;
    }
  }
  return true;
}

static bool IsWhitespaceOrComment(std::optional<FileToken> ft) {
  if (!ft) {
    return false;
  }
  switch (ft->Kind()) {
    case TokenKind::kUnknown:
      return IsWhitespace(ft->Data());
    case TokenKind::kComment:
      return true;
    default:
      return false;
  }
}

}  // namespace

bool ParsedTokenStorage::AddLeadingWhitespaceAndComments(
    BitPackedLocation floc) {

  // If this is the first file location, then formulate a location that is the
  // first location from the relevant file.
  BitPackedLocation prev_floc = kInvalidBitPackedLocation;
  auto inclusive = false;
  if (role.empty()) {
    return false;

  } else if (role.back() == TokenRole::kFileToken ||
             role.back() == TokenRole::kEndOfMacroExpansionMarker) {
    prev_floc = location.back();
  
  } else if (role.back() == TokenRole::kBeginOfFileMarker) {
    prev_floc = location.back();
    inclusive = true;
  
  } else {
    return false;
  }

  auto file_pair = UnpackFileAndTokenOffset(floc);
  if (!file_pair) {
    return false;
  }

  auto prev_file_pair = UnpackFileAndTokenOffset(prev_floc);
  if (!prev_file_pair) {
    return false;
  }

  if (prev_file_pair->first != file_pair->first ||
      prev_file_pair->second >= file_pair->second) {
    return false;
  }

  // Count the whitespace and comments.
  const File &file = ast->parsed_files[prev_file_pair->first];
  auto i = file_pair->second - 1u;
  for (;;) {
    if (i == prev_file_pair->second) {
      if (!inclusive) {
        ++i;
      }
      break;
    } else if (!IsWhitespaceOrComment(file.TokenAtIndex(i))) {
      ++i;
      break;
    } else {
      --i;
    }
  }

  // Inject in the whitespace and comments.
  for (; i < file_pair->second; ++i) {
    auto missing_floc =
        (static_cast<BitPackedLocation>(file_pair->first + 1u) << 32u) |
        static_cast<BitPackedLocation>(i + 1u);

    auto missing_ft = file.TokenAtIndex(i);
    auto tok_data = missing_ft->Data();
    data.insert(data.end(), tok_data.begin(), tok_data.end());
    kind.emplace_back(missing_ft->Kind());
    role.emplace_back(TokenRole::kFileToken);
    is_in_pragma_directive.emplace_back(false);
    location.emplace_back(missing_floc);
    FinishToken();
  }

  return true;
}

// The marker for entering a file will be delivered while we're still in
// the macro expansion event for a `#include`, so we have a way of deferring
// it until after.
void ParsedTokenStorage::TryAddBeginOfFileMarker(void) {
  if (!pending_begin_of_file_marker) {
    return;
  }

  auto include_loc = kInvalidBitPackedLocation;
  if (!role.empty() && role.back() == TokenRole::kEndOfMacroExpansionMarker) {
    include_loc = location.back();
  }

  AppendMarkerToken(pending_begin_of_file_marker->first,
                    pending_begin_of_file_marker->second);
  pending_begin_of_file_marker.reset();
  include_location.push_back(include_loc);
}

void ParsedTokenStorage::AppendFileToken(
    std::string_view tok_data, const clang::Token &tok) {

  ast->macro_tokens.MarkPreviousTokenAsEndOfExpansion();

  TryAddBeginOfFileMarker();

  auto floc = CreateFileLocation(tok.getLocation());
  if (!AddLeadingWhitespaceAndComments(floc)) {
    InventLeadingWhitespace(tok);
  }

  auto kind_ = static_cast<TokenKind>(tok.getKind());
  if (kind_ == TokenKind::kRawIdentifier) {
    kind_ = TokenKind::kIdentifier;
  }

  AppendSplitTokens(floc, kind_, false);

  data.insert(data.end(), tok_data.begin(), tok_data.end());
  kind.emplace_back(kind_);
  role.emplace_back(TokenRole::kFileToken);
  is_in_pragma_directive.emplace_back(false);
  location.emplace_back(floc);
  FinishToken();
}

void ParsedTokenStorage::AppendMacroToken(const clang::Token &tok) {
  MacroTokenStorage &macro_tokens = ast->macro_tokens;

#ifndef NDEBUG
  auto loc = tok.getLocation();
  assert(loc.isMacroID());
  assert(!macro_tokens.role.empty());
  assert(macro_tokens.role.back() == TokenRole::kIntermediateMacroExpansionToken);
  assert(static_cast<TokenKind>(tok.getKind()) == macro_tokens.kind.back());
#endif

  InventLeadingWhitespace(tok);

  auto macro_token_offset = static_cast<DerivedTokenIndex>(
      macro_tokens.role.size() - 1u);
  auto mloc = CreateMacroLocation(macro_token_offset);
  auto kind_ = macro_tokens.Kind(macro_token_offset);
  auto is_in_pragma = macro_tokens.is_in_pragma_directive.back();

  AppendSplitTokens(mloc, kind_, is_in_pragma);

  // Update the role in the macro tokens to make it as having made it into
  // the parsed tokens.
  macro_tokens.SetRole(macro_token_offset,
                       TokenRole::kFinalMacroExpansionToken);

  kind.emplace_back(kind_);
  role.emplace_back(TokenRole::kFinalMacroExpansionToken);
  is_in_pragma_directive.emplace_back(is_in_pragma);
  location.emplace_back(mloc);

  auto tok_data = macro_tokens.Data(macro_token_offset);
  data.insert(data.end(), tok_data.begin(), tok_data.end());
  FinishToken();
}

// Append an internal preprocessor token. This is to handle things like
// pragma directives. We observe these directives inside of preprocessing,
// and sometimes only as a result of macro expansion (e.g. with `_Pragma`),
// but we need to reify the intrinsic back into the parsed token representation.
// Another reason for this is to embed the presence of an "empty" expansion.
void ParsedTokenStorage::AppendInternalToken(std::string_view tok_data,
                                             clang::SourceLocation loc,
                                             TokenRole role_,
                                             bool is_in_pragma) {
  if (!data.empty() && data.back() != '\n') {
    data.push_back('\n');
    data_offset.back() += 1u;
  }

  data.insert(data.end(), tok_data.begin(), tok_data.end());
  data.push_back('\n');

  kind.emplace_back(TokenKind::kUnknown);
  role.emplace_back(role_);
  is_in_pragma_directive.emplace_back(is_in_pragma);
  if (loc.isFileID()) {
    location.emplace_back(CreateFileLocation(loc));
  } else if (loc.isMacroID()) {
    assert(ast->macro_tokens.last_expansion_begin_offset.has_value());
    location.emplace_back(CreateMacroLocation(
        ast->macro_tokens.last_expansion_begin_offset.value()));
  } else {
    assert(false);
    location.emplace_back(kInvalidBitPackedLocation);
  }
  FinishToken();
}

// Append a marker token to the parsed token list.
void ParsedTokenStorage::AppendMarkerToken(
    clang::SourceLocation loc, TokenRole role_) {

  // If we're in the expansion of a `#include`, then defer adding of the
  // befin of file marker.
  if (role_ == TokenRole::kBeginOfFileMarker &&
      ast->macro_tokens.last_expansion_begin_offset.has_value()) {
    assert(!pending_begin_of_file_marker.has_value());
    pending_begin_of_file_marker.reset();
    pending_begin_of_file_marker.emplace(loc, role_);
    return;
  }

  data.push_back('\n');

  is_in_pragma_directive.emplace_back(false);
  kind.emplace_back(TokenKind::kUnknown);
  role.emplace_back(role_);
  location.emplace_back(CreateFileLocation(loc));
  FinishToken();

  if (role_ != TokenRole::kEndOfFileMarker || include_location.empty()) {
    return;
  }

  auto file_pair = UnpackFileAndTokenOffset(include_location.back());
  include_location.pop_back();
  if (!file_pair) {
    return;
  }

  // Try to add whitespace/comments following the resumption of the file.
  const auto &file = ast->parsed_files[file_pair->first];
  for (auto i = file_pair->second; ; ++i) {
    auto ft = file.TokenAtIndex(i);
    if (!ft) {
      return;
    }

    if (!IsWhitespaceOrComment(ft)) {
      return;
    }

    auto floc = (static_cast<BitPackedLocation>(file_pair->first + 1u) << 32u) +
                static_cast<BitPackedLocation>(i + 1u);
    auto tok_data = ft->Data();

    location.push_back(floc);
    role.push_back(TokenRole::kFileToken);
    kind.push_back(ft->Kind());
    data.insert(data.end(), tok_data.begin(), tok_data.end());
    is_in_pragma_directive.push_back(false);
    FinishToken();
  }
}

std::string_view ParsedTokenStorage::Data(DerivedTokenIndex offset) const {
  auto begin_offset = data_offset[offset];
  auto end_offset = data_offset[offset + 1u];
  auto raw_data = data.data();
  std::string_view ret(&(raw_data[begin_offset]),
                       &(raw_data[end_offset]));
  while (!ret.empty() && std::isspace(ret.back())) {
    ret.remove_suffix(1u);
  }
  return ret;
}

std::optional<DerivedTokenIndex> ParsedTokenStorage::DataOffsetToTokenIndex(
    unsigned offset) const {
  if (offset >= data.size()) {
    assert(false);
    return std::nullopt;
  }

  auto begin = data_offset.begin();
  auto end = data_offset.end();
  auto it = std::upper_bound(begin, end, offset);
  auto index = static_cast<DerivedTokenIndex>(it - begin);
  assert(0u < index);
  assert(offset >= data_offset[index - 1u]);
  return index - 1u;
}

void ParsedTokenStorage::InitInvalid(void) {
  role.push_back(TokenRole::kInvalid);
  kind.push_back(TokenKind::kUnknown);
  data_offset.push_back(0u);
  data.push_back('\0');
  location.push_back(kInvalidBitPackedLocation);
  is_in_pragma_directive.push_back(false);
}

ParsedTokenStorage::~ParsedTokenStorage(void) {}
MacroTokenStorage::~MacroTokenStorage(void) {}

// Try to split the token at offset `offset`.
void ParsedTokenStorage::SplitToken(DerivedTokenIndex offset) {
  auto num_splits = NumSplits(kind[offset]);
  if (!num_splits) {
    return;
  }

  assert(num_splits <= offset);
  assert(role[offset - num_splits] == TokenRole::kInvalid);
  assert(kind[offset - num_splits] == TokenKind::kUnknown);
  assert(data_offset[offset - num_splits] <= data_offset[offset]);

  auto prev_kind = kind[offset];

  role[offset - num_splits] = role[offset];
  location[offset - num_splits] = location[offset];
  kind[offset - num_splits] = SplitTokenPrefixKind(prev_kind);
  kind[offset] = SplitTokenSuffixKind(prev_kind);

  for (auto i = (offset - num_splits + 1u); i <= offset; ++i) {
    data_offset[i] += 1u;
  }
}

void ParsedTokenStorage::Finalize(void) {
  assert(role.size() == kind.size());
  assert(role.size() == location.size());
  assert(role.size() == is_in_pragma_directive.size());
  assert((role.size() + 1u) == data_offset.size());
  assert(data_offset.back() == data.size());
  data.push_back('\0');
}

DerivedTokenIndex MacroTokenStorage::AppendMacroToken(
    std::string_view tok_data, const clang::Token &tok, TokenRole role_,
    DerivedTokenIndex macro_token_offset_) {

  auto loc = tok.getLocation();

  assert(last_expansion_begin_offset.has_value());
  auto offset = static_cast<DerivedTokenIndex>(kind.size());
  if (offset == last_expansion_begin_offset.value()) {
    ast->parsed_tokens.AppendInternalToken(
        {}, loc, TokenRole::kBeginOfMacroExpansionMarker);
  }

  auto kind_ = tok.getKind();
  if (kind_ == clang::tok::raw_identifier) {
    kind_ = clang::tok::identifier;
  }

  data.insert(data.end(), tok_data.begin(), tok_data.end());
  kind.emplace_back(static_cast<TokenKind>(kind_));
  role.emplace_back(role_);
  is_in_pragma_directive.emplace_back(false);
  macro_token_offset.emplace_back(macro_token_offset_);
  next_is_begin_expansion = false;
  location.emplace_back(CreateInitialMacroLocation(loc));
  FinishToken();
  return offset;
}

DerivedTokenIndex MacroTokenStorage::CloneMacroToken(
    DerivedTokenIndex offset, DerivedTokenIndex macro_token_offset_) {
  assert(!next_is_begin_expansion);

  auto data_len = data_offset[offset + 1u] - data_offset[offset];
  data.reserve(data.size() + data_len);

  auto tok_data = Data(offset);
  data.insert(data.end(), tok_data.begin(), tok_data.end());

  auto new_offset = static_cast<DerivedTokenIndex>(kind.size());
  kind.emplace_back(kind[offset]);
  role.emplace_back(TokenRole::kIntermediateMacroExpansionToken);
  is_in_pragma_directive.emplace_back(is_in_pragma_directive[offset]);
  macro_token_offset.emplace_back(macro_token_offset_);
  location.emplace_back(location[offset]);
  FinishToken();

  auto it = macro_definition.find(offset);
  if (it != macro_definition.end()) {
    macro_definition.emplace(new_offset, it->second);
  }

  return new_offset;
}

void MacroTokenStorage::FixupTokenProvenance(
    DerivedTokenIndex tok_index, DerivedTokenIndex min_derived_index,
    bool can_be_derived, int depth, clang::SourceLocation loc) {

  // Make the token point to itself.
  if (!loc.isValid()) {
    return;
  }

  auto raw_loc = loc.getRawEncoding();
  auto it = macro_token_refs.find(raw_loc);
  auto has_tok_for_loc = it != macro_token_refs.end();
  auto has_derived = false;
  if (has_tok_for_loc) {
    assert(min_derived_index <= MacroTokenOffset(it->second));
    assert(MacroTokenOffset(it->second) < tok_index);
    assert(Kind(tok_index) == TokenKind::kHeaderName ||
           Data(tok_index) == Data(MacroTokenOffset(it->second)));
    SetLocation(tok_index, it->second);
    has_derived = true;
  
  } else if (loc.isMacroID()) {
    auto &sm = ast->ci->getSourceManager();
    FixupTokenProvenance(tok_index, min_derived_index, false,
                         depth + 1, sm.getImmediateSpellingLoc(loc));
  }

  if (can_be_derived) {
    auto next_loc = CreateMacroLocation(tok_index);
    if (has_tok_for_loc) {
      it->second = next_loc;  // Overwrite.
    } else {
      macro_token_refs.emplace(raw_loc, next_loc);
    }
  }

  if (!loc.isFileID()) {
    return;
  }

  it = file_token_refs.find(raw_loc);
  has_tok_for_loc = it != file_token_refs.end();
  
  // TODO(pag): May be able to simplify this logic to not trigger if
  //            `has_derived` is true.

  if (has_tok_for_loc) {
    auto derived_index = MacroTokenOffset(it->second);
    assert(Kind(tok_index) == TokenKind::kHeaderName ||
           Data(tok_index) == Data(derived_index));
    SetLocation(tok_index, it->second);

    auto role = Role(tok_index);
    if (role == TokenRole::kIntermediateMacroExpansionToken) {
      assert(Role(tok_index) == TokenRole::kIntermediateMacroExpansionToken);
      
      // E.g. referencing a token from the body of a `#define`.
      if (min_derived_index > derived_index) {
        SetRole(tok_index, TokenRole::kInitialMacroUseToken);
        can_be_derived = false;

        // Propagate macro use tokens back into definition bodies.
        if (auto def_it = macro_definition.find(tok_index);
            def_it != macro_definition.end()) {
          macro_definition.emplace(derived_index, def_it->second);
        }
      }
    } else {
      assert(role == TokenRole::kFinalMacroExpansionToken);
      assert(!can_be_derived);
    }

  } else {
    
    // NOTE(pag): Might trigger for pre-expansions. Added during split token
    //            rework.
    assert(!has_derived);
    SetRole(tok_index, TokenRole::kInitialMacroUseToken);
    SetLocation(tok_index, CreateFileLocation(loc));
    
    // Track the location of the next possible token immediately following a
    // macro expansion.
    auto next_last_use_loc = loc.getLocWithOffset(
        static_cast<int>(Data(tok_index).size()));    
    if (!last_use_loc || 
        last_use_loc->getRawEncoding() < next_last_use_loc.getRawEncoding()) {
      last_use_loc = next_last_use_loc;
    }
  }

  if (!can_be_derived) {
    return;
  }

  auto next_loc = CreateMacroLocation(tok_index);
  if (has_tok_for_loc) {
    it->second = next_loc;  // Overwrite.

  } else {
    assert(!has_derived);
    file_token_refs.emplace(raw_loc, next_loc);
  }
}

clang::SourceLocation MacroTokenStorage::OriginalLocation(
    DerivedTokenIndex offset) const {

  auto bit_packed_loc = location[offset];
  if (!bit_packed_loc || (bit_packed_loc >> 32u) != ~0u) {
    return {};
  }

  // We can only ask for the original location of a macro token while we are
  // still processing the the expansion itself. Otherwise the above
  // `FixupTokenProvenance` might have altered it.
  assert(last_expansion_begin_offset.has_value());
  assert(offset >= last_expansion_begin_offset.value());

  static_assert(sizeof(uint32_t) == sizeof(OpaqueSourceLoc));

  return clang::SourceLocation::getFromRawEncoding(
      static_cast<uint32_t>(location[offset]));
}

void MacroTokenStorage::MarkPreviousTokenAsEndOfExpansion(void) {
  if (!last_expansion_begin_offset) {
    return;
  }

  macro_token_refs.clear();

  auto begin_offset = last_expansion_begin_offset.value();
  auto end_offset = static_cast<unsigned>(role.size());

  for (auto i = begin_offset; i < end_offset; ++i) {
    auto tok_role = Role(i);
    auto can_be_derived =
        tok_role == TokenRole::kInitialMacroUseToken ||
        tok_role == TokenRole::kIntermediateMacroExpansionToken;
    auto loc = OriginalLocation(i);
    SetLocation(i, kInvalidBitPackedLocation);
    FixupTokenProvenance(i, begin_offset, can_be_derived, 0u, loc);
    assert(CreateMacroLocation(i) != location[i]);
    assert(static_cast<uint32_t>(location[i] >> 32) != ~0u);
  }

  last_expansion_begin_offset.reset();

  assert(last_use_loc.has_value());

  ast->parsed_tokens.AppendInternalToken(
      {}, last_use_loc.value(), TokenRole::kEndOfMacroExpansionMarker);

  ast->matching.emplace(begin_offset, end_offset);
  ast->matching.emplace(end_offset, begin_offset);

  last_use_loc.reset();
}

DerivedTokenIndex MacroTokenStorage::MarkNextTokenAsBeginOfExpansion(void) {
  MarkPreviousTokenAsEndOfExpansion();
  ast->parsed_tokens.TryAddBeginOfFileMarker();

  next_is_begin_expansion = true;
  last_expansion_begin_offset = static_cast<unsigned>(kind.size());
  return last_expansion_begin_offset.value();
}

void MacroTokenStorage::Finalize(void) {
  ParsedTokenStorage::Finalize();
  MarkPreviousTokenAsEndOfExpansion();
  TokenProvenanceMap().swap(file_token_refs);
  TokenProvenanceMap().swap(macro_token_refs);

  assert(role.size() == macro_token_offset.size());
}

const Node *MacroTokenStorage::MacroName(DerivedTokenIndex offset) const {
  auto it = macro_definition.find(offset);
  if (it == macro_definition.end()) {
    return nullptr;
  }
  return &(it->second);
}

void MacroTokenStorage::MarkAsMacroName(DerivedTokenIndex offset, Node macro) {
  macro_definition.emplace(offset, std::move(macro));
}

ParsedTokenIterator ParsedTokenIterator::WithOffset(
    DerivedTokenIndex new_offset) const noexcept {
  
  if (new_offset > upper_bound) {
    return ParsedTokenIterator(&(storage->ast->invalid_tokens), 0u, 0u);
  }

  ParsedTokenIterator it(storage, upper_bound, new_offset);
  assert(it.IsParsed());
  return it;
}

bool ParsedTokenIterator::IsParsed(void) const noexcept {
  switch (Role()) {
    case TokenRole::kInvalid:
    case TokenRole::kBeginOfFileMarker:
    case TokenRole::kEndOfFileMarker:
    case TokenRole::kBeginOfMacroExpansionMarker:
    case TokenRole::kEndOfMacroExpansionMarker:
    case TokenRole::kMacroDirectiveMarker:
      return false;
    default:
      switch (Kind()) {
        case TokenKind::kUnknown:
          return !IsWhitespace(Data());
        case TokenKind::kComment:
        case TokenKind::kEndOfFile:
        case TokenKind::kEndOfDirective:
        case TokenKind::kCodeCompletion:
          return false;
        case TokenKind::kAnnotCxxscope:
        case TokenKind::kAnnotTypename:
        case TokenKind::kAnnotTemplateId:
        case TokenKind::kAnnotNonType:
        case TokenKind::kAnnotNonTypeUndeclared:
        case TokenKind::kAnnotNonTypeDependent:
        case TokenKind::kAnnotOverload:
        case TokenKind::kAnnotPrimaryExpression:
        case TokenKind::kAnnotDecltype:
        case TokenKind::kAnnotPragmaUnused:
        case TokenKind::kAnnotPragmaVis:
        case TokenKind::kAnnotPragmaPack:
        case TokenKind::kAnnotPragmaParserCrash:
        case TokenKind::kAnnotPragmaCaptured:
        case TokenKind::kAnnotPragmaDump:
        case TokenKind::kAnnotPragmaMsstruct:
        case TokenKind::kAnnotPragmaAlign:
        case TokenKind::kAnnotPragmaWeak:
        case TokenKind::kAnnotPragmaWeakalias:
        case TokenKind::kAnnotPragmaRedefineExtname:
        case TokenKind::kAnnotPragmaFpContract:
        case TokenKind::kAnnotPragmaFenvAccess:
        case TokenKind::kAnnotPragmaFenvAccessMs:
        case TokenKind::kAnnotPragmaFenvRound:
        case TokenKind::kAnnotPragmaFloatControl:
        case TokenKind::kAnnotPragmaMsPointersToMembers:
        case TokenKind::kAnnotPragmaMsVtordisp:
        case TokenKind::kAnnotPragmaMsPragma:
        case TokenKind::kAnnotPragmaOpenclExtension:
        case TokenKind::kAnnotAttributeOpenmp:
        case TokenKind::kAnnotPragmaOpenmp:
        case TokenKind::kAnnotPragmaOpenmpEnd:
        case TokenKind::kAnnotPragmaLoopHint:
        case TokenKind::kAnnotPragmaFp:
        case TokenKind::kAnnotPragmaAttribute:
        case TokenKind::kAnnotPragmaRiscv:
        case TokenKind::kAnnotModuleInclude:
        case TokenKind::kAnnotModuleBegin:
        case TokenKind::kAnnotModuleEnd:
        case TokenKind::kAnnotHeaderUnit:
        case TokenKind::kAnnotReplInputEnd:
          return false;
        default:
          return true;
      }
  }
}

bool ParsedTokenIterator::Next(DerivedTokenIndex inclusive_upper_bound) {
  while ((offset + 1u) <= inclusive_upper_bound) {
    offset = (offset + 1u);
    if (IsParsed()) {
      return true;
    }
  }
  storage = &(storage->ast->invalid_tokens);
  offset = 0u;
  upper_bound = 0u;
  return false;
}

bool ParsedTokenIterator::Previous(DerivedTokenIndex inclusive_lower_bound) {
  while (inclusive_lower_bound < offset) {
    offset = offset - 1u;
    if (IsParsed()) {
      return true;
    }
  }

  *this = storage->ast->InvalidRawToken();
  storage = &(storage->ast->invalid_tokens);
  offset = 0u;
  upper_bound = 0u;
  return false;
}

} // namespace pasta
