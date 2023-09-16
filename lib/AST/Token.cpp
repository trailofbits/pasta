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

  out->assign(data, len);

  return true;
}

} // namespace

std::vector<pasta::TokenRole> TokenRoles = std::vector({
#define ROLE(role) TokenRole::k##role ,
  PASTA_FOR_EACH_TOKEN_ROLE(ROLE)
#undef ROLE
});

std::string TokenRoleName(const TokenRole role) {
  const static std::string TokenRoleNames[] = {
#define ROLE(role) #role,
  PASTA_FOR_EACH_TOKEN_ROLE(ROLE)
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
std::optional<Token> Token::DerivedLocation(void) const {
  if (!impl || impl->derived_index == kInvalidDerivedTokenIndex) {
    return std::nullopt;
  }

  if (impl->derived_index < Index()) {
    return Token(ast, &(ast->tokens[impl->derived_index]));
  }

  assert(false);
  return std::nullopt;
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
    }

    if (loc.isFileID()) {
      break;
    }

    max_index = tok_index;
    tok_index = tok.derived_index;
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
      }
      if (impl->context_index >= ast->root_macro_node.token_nodes.size()) {
        assert(false);
        return std::nullopt;
      }
      return MacroToken(
          ast, &(ast->root_macro_node.token_nodes[impl->context_index]));
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
  }
  return TokenKind::kUnknown;
}

// Return the role of this token.
TokenRole Token::Role(void) const noexcept {
  if (impl) {
    return impl->Role();
  }
  return TokenRole::kInvalid;
}

// Kind of this token.
const char *Token::KindName(void) const noexcept {
  if (impl) {
    return clang::tok::getTokenName(impl->Kind());
  }
  return clang::tok::getTokenName(clang::tok::unknown);
}

// Return the context of this token, or `nullptr`.
//
// TODO(pag): Eventually migrate this to `PrintedTokenImpl`.
const TokenContextImpl *TokenImpl::Context(
    const ASTImpl &ast,
    const std::vector<TokenContextImpl> &contexts) const noexcept {

  if (Role() != TokenRole::kFileToken) {
    assert(false);
    return nullptr;
  }

  if (context_index == kInvalidTokenContextIndex) {
    return nullptr;
  }

  if (context_index >= contexts.size()) {
    assert(false);
    return nullptr;
  }

  return &(contexts[context_index]);
}

std::string_view TokenImpl::Data(const ASTImpl &ast) const noexcept {
  if (data_len) {
    if (0 <= data_offset) {
      return std::string_view(ast.preprocessed_code).substr(
          static_cast<uint32_t>(data_offset), data_len);
    }
    return std::string_view(ast.backup_token_data).substr(
        static_cast<uint32_t>(-data_offset), data_len);
  }
  return {};
}

std::string_view TokenImpl::Data(
    const PrintedTokenRangeImpl &range) const noexcept {
  if (data_len) {
    return std::string_view(range.data).substr(
        static_cast<uint32_t>(data_offset), data_len);
  }
  return {};
}

// Return the data associated with this token.
std::string_view Token::Data(void) const {
  if (ast && impl) {
    return impl->Data(*ast);
  }
  return {};
}

// Index of this token in the AST's token list.
uint64_t Token::Index(void) const {
  if (ast && impl) {
    return static_cast<uint64_t>(impl - ast->tokens.data());
  }
  return kInvalidDerivedTokenIndex;
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
  if (!i) {
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

std::optional<TokenRange> TokenRange::From(Token begin, Token end) {
  if (begin.ast != end.ast || begin > end) {
    return std::nullopt;
  }
  return TokenRange(begin.ast, begin.impl, &(end.impl[1]));
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
  }
  return std::nullopt;
}

// Unsafe indexed access into the token range.
Token TokenRange::operator[](size_t index) const {
  return Token(ast, &(first[index]));
}

// Returns `true` if this range contains a specific token.
bool TokenRange::Contains(const Token &tok) const noexcept {
  return ast == tok.ast && first <= tok.impl && tok.impl < after_last;
}

std::vector<MacroSubstitution>
TokenRange::AlignedSubstitutions(bool heuristic) noexcept {
  // The big idea is that we want to find the all macros that aligns in the
  // front and back with the given statement. The catch is that a macro might
  // contain nested substitutions, e.g. argument expansions or nested
  // expansions. Also, we should match statements which were expanded from
  // macros containing a trailing semicolon.

  // Algorithm:
  // 1. Walk the first token's derived token chain from final expansion token to
  //    the initial macro use token.
  // 2. Walk up this token's expansion tree. If we encounter a non-substitution
  //    macro, stop traversing the expansion tree and ascend the derivation
  //    tree. If we encounter a macro substitution, check that this token is the
  //    first in the macro's replacement list. If so, the continue to the next
  //    step; otherwise keep ascending the token derivation tree. There is also
  //    an edge-case to check for: If the current token is the first token in
  //    the macro's intermediate expansion children, then we must immediately
  //    return early, because otherwise we might erroneously match a macro with
  //    one of its arguments if they share a derivation tree. For example:
  //      #define ADD(X, Y)
  //      int x = ADD(ADD(1, 2), 3)
  //    This check prevents 1 + 2 + 3 from aligning with both invocations of
  //    ADD(), and ensures that it will only align with the top-level
  //    invocation.
  // 3. Walk up the last token's derived token chain from the initial macro use
  //    token to the final macro expansion token.
  // 4. Walk up the last derived token's derivation tree. If the last token is
  //    ever derived from the same token that the first token is derived from,
  //    then exit this iteration early to avoid false positives. If we encounter
  //    a macro substitution, check that this token is the last in the macro's
  //    replacement list. Follow similar logic as when checking for
  //    front-alignment. This also where we incorporate the heuristic for
  //    aligning macros that contain semicolons. If this check succeeds, then we
  //    have found an aligned invocation.
  // 5. The algorithm ends once we have walked the first token's entire
  //    derivation chain.
  auto b_tok = Front(), e_tok = Back();

  std::vector<MacroSubstitution> result;
  if (!b_tok || !*b_tok || !e_tok || !*e_tok) {
    return result;
  }

  auto b_tok_deriv_chain = b_tok->DerivationChain();

  auto e_tok_deriv_chain = e_tok->DerivationChain();

  // If the heuristic is enabled, keep track of the token that immediately
  // follows this statement to check if it's a semicolon.
  auto tok_after_e_tok = (heuristic
                          ? e_tok->NextFinalExpansionOrFileToken()
                          : std::nullopt);
  bool semi = tok_after_e_tok && tok_after_e_tok->Kind() == TokenKind::kSemi;

  for (auto b_deriv : b_tok_deriv_chain) {
    std::optional<Macro> b_macro = b_deriv.MacroLocation();
    if (!b_macro) {
      continue;
    }

    for (auto b_parent = b_macro->Parent(); b_parent;
         b_macro = *b_parent, b_parent = b_parent->Parent()) {
      auto b_parent_sub = MacroSubstitution::From(*b_parent);
      if (!b_parent_sub) {
        break;
      }

      // Here is the first edge-case. We only allow a macro token to be the
      // first child in its parent's intermediate replacement list if the macro
      // token is a parameter substitution.
      if (auto b_parent_exp = MacroExpansion::From(*b_parent_sub)) {
        MacroRange body = b_parent_exp->IntermediateChildren();
        bool is_psub = b_macro->Kind() == MacroKind::kParameterSubstitution;
        if (b_macro == body.Front() && !is_psub) {
          return result;
        }
      }

      auto b_parent_replacement = b_parent_sub->ReplacementChildren();
      bool front_aligned = (b_macro == b_parent_replacement.Front());
      if (!front_aligned) {
        break;
      }

      for (auto e_deriv : e_tok_deriv_chain) {
        // Here's the rub: If the begin and end tokens ever converge to the same
        // derived token, then their derivation trees have started mixing. This
        // can happen if two separate arguments of the macro are invocations of
        // the same macro definition. To see an example, print the macro graph
        // of the following invocation code snippet:
        //
        // #define ONE 1
        // #define ADD(x, y) x + y
        // ADD(ONE, ONE)
        //
        // This isn't a problem if the begin and end tokens were the same tokens
        // to begin with (then of course their derivation trees would be the
        // same). Otherwise we should exit early, since this mixing might cause
        // us to return a false positive.

        // NOTE(bpappas): I am fairly certain that returning here will prevent
        // false positives, but I am not sure if it will create false negatives.
        if (b_deriv == e_deriv && b_tok != e_tok) {
          break;
        }

        std::optional<Macro> e_macro = e_deriv.MacroLocation();
        if (!e_macro) {
          continue;
        }

        for (auto e_parent = e_macro->Parent(); e_parent;
             e_macro = *e_parent, e_parent = e_parent->Parent()) {
          auto e_parent_sub = MacroSubstitution::From(*e_parent);
          if (!e_parent_sub) {
            break;
          }

          if (auto e_parent_exp = MacroExpansion::From(*e_parent_sub)) {
            MacroRange body = e_parent_exp->IntermediateChildren();
            bool is_psub = e_macro->Kind() == MacroKind::kParameterSubstitution;
            if (e_macro == body.Back() && !is_psub) {
              break;
            }
          }

          auto psub_last_tok = e_parent_sub->LastFullySubstitutedToken();
          auto e_parent_replacement = e_parent_sub->ReplacementChildren();
          bool back_aligned = ((e_macro == e_parent_replacement.Back()) ||
                               (semi && tok_after_e_tok == psub_last_tok));

          if (!back_aligned) {
            break;
          }

          if (b_parent == e_parent) {
            result.push_back(*b_parent_sub);
          }
        }
      }
    }
  }

  return result;
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
  if (loc.isFileID()) {
    return !clang::Lexer::getRawToken(
        loc, *out, source_manager, lang_opts, true);
  }
  return false;
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

} // namespace pasta
