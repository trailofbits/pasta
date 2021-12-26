/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Printer.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Stmt.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Preprocessor.h>
#pragma clang diagnostic pop

#include "raw_ostream.h"

#include "../AST.h"  // For `ASTImpl`.

namespace pasta {

// Traverse up the chain.
std::shared_ptr<const PrintedTokenContext> PrintedTokenContext::Parent(
    std::shared_ptr<const PrintedTokenContext> curr) {
  if (curr) {
    return std::shared_ptr<const PrintedTokenContext>(curr, curr->parent);
  } else {
    return std::shared_ptr<const PrintedTokenContext>();
  }
}

PrintedToken::~PrintedToken(void) {}

// A pointer to the raw context.
std::shared_ptr<const PrintedTokenContext> PrintedToken::RawContext(void) const {
  if (impl) {
    return std::shared_ptr<const PrintedTokenContext>(range, impl->context);
  } else {
    return std::shared_ptr<const PrintedTokenContext>();
  }
}

// Return the data associated with this token.
std::string_view PrintedToken::Data(void) const {
  if (impl) {
    return impl->data;
  } else {
    return {};
  }
}

// Kind of this token.
clang::tok::TokenKind PrintedToken::Kind(void) const {
  if (impl) {
    return impl->kind;
  } else {
    return clang::tok::unknown;
  }
}

const char *PrintedTokenContext::KindName(void) const {
  switch (kind) {
#define PASTA_PRINTED_TOKEN_KIND_CASE(cls) \
    case PrintedTokenKind::k ## cls: return #cls ; \
  PASTA_FOR_EACH_PRINTED_TOKEN_KIND(PASTA_PRINTED_TOKEN_KIND_CASE)
#undef PASTA_PRINTED_TOKEN_KIND_CASE
    default:
      assert(false);
      return "Unknown";
  }
}

// Number of leading new lines (before any indentation spaces).
unsigned PrintedToken::NumLeadingNewLines(void) const {
  return impl->num_leading_new_lines;
}

// Number of leading spaces (after any leading new lines).
unsigned PrintedToken::NumleadingSpaces(void) const {
  return impl->num_leading_spaces;
}

// Return the index of this token in its token range.
unsigned PrintedToken::Index(void) const {
  if (!range) {
    return ~0u;
  }
  const auto num_tokens = range->tokens.size();
  if (!num_tokens) {
    return ~0u;
  }

  auto begin = range->tokens.data();
  auto end = &(begin[num_tokens]);
  if (begin <= impl && impl < end) {
    return static_cast<unsigned>(impl - begin);
  } else {
    return ~0u;
  }
}

// Prefix increment operator.
PrintedTokenIterator &PrintedTokenIterator::operator++(void) noexcept {
  ++token.impl;
  return *this;
}

// Postfix increment operator.
PrintedTokenIterator PrintedTokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.impl;
  return ret;
}

// Prefix decrement operator.
PrintedTokenIterator &PrintedTokenIterator::operator--(void) noexcept {
  --token.impl;
  return *this;
}

// Postfix decrement operator.
PrintedTokenIterator PrintedTokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.impl;
  return ret;
}

PrintedTokenIterator PrintedTokenIterator::operator-(size_t offset) const noexcept {
  return PrintedTokenIterator(token.range, token.impl - offset);
}

PrintedTokenIterator &PrintedTokenIterator::operator+=(size_t offset) noexcept {
  token.impl += offset;
  return *this;
}

PrintedTokenIterator &PrintedTokenIterator::operator-=(size_t offset) noexcept {
  token.impl -= offset;
  return *this;
}

PrintedToken PrintedTokenIterator::operator[](size_t offset) const noexcept {
  return PrintedToken(token.range, &(token.impl[offset]));
}

ptrdiff_t PrintedTokenIterator::operator-(
    const PrintedTokenIterator &that) const noexcept {
  return token.impl - token.impl;
}

PrintedTokenRangeImpl::~PrintedTokenRangeImpl(void) {}

void PrintedTokenRangeImpl::PopContext(void) {
  if (!tokenizer_stack.empty()) {
    const auto last_tokenizer = tokenizer_stack.back();
    last_tokenizer->Tokenize();

    context_stack.pop_back();
    tokenizer_stack.pop_back();
  }
}

namespace {

static std::tuple<unsigned, unsigned, unsigned> SkipWhitespace(
    const std::string &data, unsigned i) {
  unsigned num_leading_spaces = 0;
  unsigned num_leading_lines = 0;

  for (const auto size = data.size(); i < size; ++i) {
    switch (data[i]) {
      case '\t':
        num_leading_spaces += 4;
        break;
      case ' ':
        num_leading_spaces += 1;
        break;
      case '\r':
        break;
      case '\n':
        num_leading_spaces = 0;
        num_leading_lines += 1;
        break;
      case '\\':
        assert(false);
        return {num_leading_lines, num_leading_spaces, i};
      default:
        return {num_leading_lines, num_leading_spaces, i};
    }
  }
  return {num_leading_lines, num_leading_spaces, i};
}

}  // namespace

void TokenPrinterContext::Tokenize(void) {
  const clang::LangOptions &lo = tokens.ast_context.getLangOpts();

  std::string &token_data = out.str();
  if (token_data.empty()) {
    return;
  }

  clang::Lexer lexer(
      clang::SourceLocation(),
      lo,
      &(token_data[0]),
      &(token_data[0]),
      &(token_data[0]) + token_data.size());

  lexer.SetKeepWhitespaceMode(false);
  lexer.SetCommentRetentionState(false);

  clang::Token tok;

  unsigned num_nl = 0u;
  unsigned num_sp = 0u;
  unsigned i = 0u;

  for (auto size = token_data.size(); i < size; ) {
    auto last_i = i;
    std::tie(num_nl, num_sp, i) = SkipWhitespace(token_data, i);
    if (i >= size) {
      break;
    }

    lexer.skipOver(last_i - i);
    last_i = i;

    const auto at_end = lexer.LexFromRawLexer(tok);
    if (tok.is(clang::tok::eof)) {
      break;
    } else if (tok.isOneOf(clang::tok::semi, clang::tok::comma)) {
      num_nl = 0u;
      num_sp = 0u;
    }

    std::string token_value;
    token_value.reserve(tok.getLength());
    for (last_i = i, i += tok.getLength(); last_i < i; ++last_i) {
      token_value.push_back(token_data[last_i]);
    }

    // Add the token in.
    tokens.tokens.emplace_back(
        std::move(token_value), context, num_nl, num_sp, tok.getKind());

    if (at_end) {
      break;
    }
  }

  // Clear out so future streaming just re-fills.
  token_data.clear();

  // We only track spaces before a token, but there might be trailing whitespace
  // after a token that needs to get picked up by the next call to `Tokenize`,
  // so re-introduce the whitespace here.
  for (i = 0u; i < num_nl; ++i) {
    token_data.push_back('\n');
  }

  for (i = 0u; i < num_sp; ++i) {
    token_data.push_back(' ');
  }
}

void TokenPrinterContext::MarkLocation(clang::SourceLocation &loc) {
  Tokenize();
  if (!tokens.tokens.empty()) {
    tokens.tokens.back().parsed_location = loc;
  }
}

TokenPrinterContext::~TokenPrinterContext(void) {
  tokens.PopContext();
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Decl &decl_) {
  auto &ast = decl_.ast;
  PrintedTokenRange ret = PrintedTokenRange::Create(
      ast->ci->getASTContext(), *(ast->printing_policy),
      const_cast<clang::Decl *>(decl_.u.Decl));
  ret.impl->ast = ast;
  return ret;
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Stmt &stmt_) {
  auto &ast = stmt_.ast;
  PrintedTokenRange ret = PrintedTokenRange::Create(
      ast->ci->getASTContext(), *(ast->printing_policy),
      const_cast<clang::Stmt *>(stmt_.u.Stmt));
  ret.impl->ast = ast;
  return ret;
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Type &type_) {

  auto &ast = type_.ast;
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(type_.u.Type,
                             type_.qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(type_.qualifiers));

  PrintedTokenRange ret = PrintedTokenRange::Create(
      ast_ctx, *(ast->printing_policy), self);
  ret.impl->ast = ast;
  return ret;
}


// Number of tokens in this range.
size_t PrintedTokenRange::Size(void) const noexcept {
  return first ? impl->tokens.size() : 0;
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<PrintedToken> PrintedTokenRange::At(size_t index) const noexcept {
  if (auto ptr = &(first[index]); ptr < after_last) {
    return PrintedToken(impl, ptr);
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
PrintedToken PrintedTokenRange::operator[](size_t index) const {
  return PrintedToken(impl, &(first[index]));
}

}  // namespace pasta
