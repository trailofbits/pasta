/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

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

namespace pasta {
namespace {

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

  } else {
    len = tok.getLength();
//    len = clang::Lexer::MeasureTokenLength(begin_loc, source_manager,
//                                           lang_opts);
  }

  if (!len) {
    return false;
  }

//  // We'll try to get only valid UTF-8 characters, and printable ASCII
//  // characters.
//  //
//  // TODO(pag): This may be overkill, but the lifetimes of the backing buffers
//  //            for things like macro expansions is not clear to me, so this
//  //            is a reasonable way to go about detecting unusual token data
//  //            that may have been corrupted/reused.
//  auto can_be_ident = true;

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

//  // Also try to catch errors when reading out identifiers or keywords.
//  //
//  // TODO(pag): We can't apply this to keywords as it very frequently triggers
//  //            in macro definitions, where keyword tokens can contain line
//  //            continuations and whitespace.
//  if (!can_be_ident && tok.isAnyIdentifier()) {
//    // ...
//  }

  return true;
}

} // namespace

std::vector<pasta::TokenRole> TokenRoles = std::vector({
  #define ROLE(role) TokenRole::k##role ,
  ROLES
  #undef ROLE
});

std::string TokenRoleName(const TokenRole role) {
  const static std::string TokenRoleNames[] = {
#define ROLE(role) #role,
  ROLES
#undef ROLE
  };
  return TokenRoleNames[static_cast<size_t>(role)];
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
  return "";
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

// Find the token from which this token was derived.
std::optional<Token> Token::DerivedLocation(void) const {
  if (!impl || impl->derived_index == kInvalidDerivedTokenIndex) {
    return std::nullopt;

  } else if (impl->derived_index < Index()) {
    return Token(ast, &(ast->tokens[impl->derived_index]));

  } else {
    assert(false);
    return std::nullopt;
  }
}

// Follow this token's derived token list and accumulate results along the
  // way. The result vector's first element is this token, and the last element
  // is the first token this token was derived from.
std::vector<Token> Token::DerivationChain(void) const {
  std::optional<Token> cur = std::optional(*this);
  std::vector<Token> derivation_chain;
  do {
    derivation_chain.push_back(*cur);
    cur = cur->DerivedLocation();
  } while (cur.has_value());
  return derivation_chain;
}

// Location of the token in a file.
std::optional<FileToken> Token::FileLocation(void) const {
  if (!impl) {
    return std::nullopt;
  }

  size_t tok_index = Index();
  size_t max_index = ast->tokens.size();

  clang::SourceLocation loc;
  while (tok_index < max_index) {
    const TokenImpl &tok = ast->tokens[tok_index];
    loc = tok.Location();
    if (loc.isInvalid()) {
      return std::nullopt;

    } else if (loc.isFileID()) {
      break;

    } else {
      max_index = tok_index;
      tok_index = tok.derived_index;
    }
  }

  return ast->FileTokenAt(loc);
}

// Location of the token in a macro expansion.
std::optional<MacroToken> Token::MacroLocation(void) const {
  switch (Role()) {
    default:
    case TokenRole::kBeginOfMacroExpansionMarker:
    case TokenRole::kEndOfMacroExpansionMarker:
      return std::nullopt;
    case TokenRole::kEndOfInternalMacroEventMarker:
    case TokenRole::kInitialMacroUseToken:
    case TokenRole::kIntermediateMacroExpansionToken:
    case TokenRole::kFinalMacroExpansionToken:
      if (impl->context_index == kInvalidTokenContextIndex) {
        return std::nullopt;
      } else if (impl->context_index >= ast->root_macro_node.token_nodes.size()) {
        assert(false);
        return std::nullopt;
      } else {
        return MacroToken(
            ast, &(ast->root_macro_node.token_nodes[impl->context_index]));
      }
  }
}

// `#define` associated with the name of this token. This doesn't
// necessarily mean that this token is actually expanded as the macro,
// just that it could be referring to it at the point of use. An example
// of where this can seem misleading is:
//
//      #define FOO() ...
//      #define not_FOO
//      #define BAR(x) not_ ## x
//
//      BAR(FOO)
//
// Here, `FOO` in the parameter to `BAR` refers to the macro `FOO`, but it
// actually ends up being concatenated with `not_`, becoming a different
// macro, `not_FOO`, which expands to nothing.
std::optional<DefineMacroDirective> Token::AssociatedMacro(void) const {
  if (!impl->is_macro_name) {
    return std::nullopt;
  }

  auto node_it = ast->tokens_to_macro_definitions.find(
      static_cast<unsigned>(Index()));
  if (node_it == ast->tokens_to_macro_definitions.end()) {
    return std::nullopt;
  }

  return DefineMacroDirective(ast, &(node_it->second));
}

// Returns true if we can follow the token's derived location chain to a token
// expanded under the given macro.
bool Token::IsDerivedFromMacro(const Macro &macro) const noexcept {
  for (auto derived_tok = std::optional(*this); derived_tok;
       derived_tok = derived_tok->DerivedLocation()) {
    if (auto derived_macro_tok = derived_tok->MacroLocation()) {
      if (auto derived_macro_parent = derived_macro_tok->Parent()) {
        if (macro == *derived_macro_parent) {
          return true;
        }
      }
    }
  }
  return false;
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

// Return the context of this token, or `nullptr`.
const TokenContextImpl *TokenImpl::Context(
    const ASTImpl &ast,
    const std::vector<TokenContextImpl> &contexts) const noexcept {

  TokenContextIndex ci = context_index;
  switch (Role()) {
    case TokenRole::kInitialMacroUseToken:
    case TokenRole::kIntermediateMacroExpansionToken:
    case TokenRole::kFinalMacroExpansionToken:
    case TokenRole::kEndOfInternalMacroEventMarker:
      if (ci == kInvalidTokenContextIndex) {
        return nullptr;
      } else if (ci >= ast.root_macro_node.token_nodes.size()) {
        assert(false);
        return nullptr;
      } else {
        ci = ast.root_macro_node.tokens[ci].token_context;
        break;
      }
    default:
      break;
  }

  if (ci == kInvalidTokenContextIndex) {
    return nullptr;
  } else if (ci >= contexts.size()) {
    assert(false);
    return nullptr;
  } else {
    return &(contexts[ci]);
  }
}

// Return this token's context, or a null context.
std::optional<TokenContext> Token::Context(void) const noexcept {
  if (!impl) {
    return std::nullopt;
  } else if (auto context = impl->Context(*ast, ast->contexts)) {
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

// Returns the first final expansion or file token in the AST after this token.
std::optional<Token> Token::NextFinalExpansionOrFileToken(void) const noexcept {
  const auto &tokens = ast->tokens;
  for (auto i = Index() + 1; i < tokens.size(); i++) {
    const auto tok_impl = tokens.at(i);
    const auto tok_impl_role = tok_impl.Role();
    if (tok_impl_role == TokenRole::kFinalMacroExpansionToken ||
        tok_impl_role == TokenRole::kFileToken) {
      return Token(ast, tokens.data() + i);
    }
  }
  return std::nullopt;
}

// Returns the first final expansion or file token in the AST before this token.
std::optional<Token> Token::PrevFinalExpansionOrFileToken(void) const noexcept {
  uint64_t i = Index();
  // If this is the first token in the AST, then no token precedes it. Return
  // early to avoid accidental integer underflow.
  if (i == 0) {
    return std::nullopt;
  }
  const auto &tokens = ast->tokens;
  for (; i > 0; i--) {
    const auto tok_impl = tokens.at(i - 1);
    const auto tok_impl_role = tok_impl.Role();
    if (tok_impl_role == TokenRole::kFinalMacroExpansionToken ||
        tok_impl_role == TokenRole::kFileToken) {
      return Token(ast, tokens.data() + (i - 1));
    }
  }
  return std::nullopt;
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
  return token.impl - that.token.impl;
}

// Number of tokens in this range.
size_t TokenRange::Size(void) const noexcept {
  return static_cast<size_t>(after_last - first);
}

// If this range is not empty, returns the first token. Otherwise returns
// std::nullopt.
std::optional<Token> TokenRange::Front(void) const noexcept {
  return empty() ? std::nullopt : At(0);
}

// If this range is not empty, returns the last token. Otherwise returns
// std::nullopt.
std::optional<Token> TokenRange::Back(void) const noexcept {
  return empty() ? std::nullopt : At(Size() - 1);
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

// Strip off leading whitespace from a token that has been read.
void SkipLeadingWhitspace(clang::Token &tok, clang::SourceLocation &tok_loc,
                          std::string &tok_data) {
  std::reverse(tok_data.begin(), tok_data.end());
  while (!tok_data.empty()) {
    switch (tok_data.back()) {
      case '\\':
      case ' ':
      case '\t':
      case '\r':
      case '\n':
        tok_data.pop_back();
        tok_loc = tok_loc.getLocWithOffset(1);
        break;
      default:
        goto done;
    }
  }
done:
  tok.setLocation(tok_loc);
  std::reverse(tok_data.begin(), tok_data.end());
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
