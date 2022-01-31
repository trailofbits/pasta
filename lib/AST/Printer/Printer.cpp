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

PrintedToken::~PrintedToken(void) {}

// Return the data associated with this token.
std::string_view PrintedToken::Data(void) const {
  if (impl) {
    return impl->Data(*range);
  } else {
    return {};
  }
}

// Kind of this token.
clang::tok::TokenKind PrintedToken::Kind(void) const {
  if (impl) {
    return static_cast<clang::tok::TokenKind>(impl->kind);
  } else {
    return clang::tok::unknown;
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

// Return this token's context, or a null context.
std::optional<TokenContext> PrintedToken::Context(void) const noexcept {
  if (!impl) {
    return {};
  } else if (impl->context_index == kInvalidTokenContextIndex) {
    return {};
  } else if (impl->context_index >= range->contexts.size()) {
    return {};
  } else {
    std::shared_ptr<const std::vector<TokenContextImpl>> contexts(
        range, &(range->contexts));
    return TokenContext(&(range->contexts[impl->context_index]),
                        std::move(contexts));
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


const TokenContextIndex PrintedTokenRangeImpl::CreateAlias(
    TokenPrinterContext *tokenizer, TokenContextIndex aliasee) {

  // If the current thing on the stack is what we're aliasing, then don't alias
  // it.
  if (tokenizer->prev_printer_context &&
      tokenizer->prev_printer_context->context_index == aliasee) {
    return aliasee;
  }

  auto index = static_cast<TokenContextIndex>(contexts.size());
  assert(index == contexts.size());

  if (tokenizer->prev_printer_context &&
      tokenizer->prev_printer_context->context_index !=
          kInvalidTokenContextIndex) {
    auto parent_index = tokenizer->prev_printer_context->context_index;
    auto parent_depth = contexts[parent_index].depth;
    contexts.emplace_back(
        parent_index,
        parent_depth,
        aliasee);
  } else {
    assert(false);
    contexts.emplace_back(
        kInvalidTokenContextIndex,
        static_cast<uint16_t>(0),
        aliasee);
  }
  return index;
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

TokenPrinterContext::TokenPrinterContext(
    const TokenPrinterContext &that_, no_alias_tag)
    : out(that_.out),
      prev_printer_context(that_.tokens.curr_printer_context),
      context_index(that_.context_index),
      tokens(that_.tokens) {
  if (prev_printer_context) {
    prev_printer_context->Tokenize();
  }
  tokens.curr_printer_context = this;
}

TokenPrinterContext::TokenPrinterContext(const TokenPrinterContext &that_)
    : out(that_.out),
      prev_printer_context(that_.tokens.curr_printer_context),
      context_index(that_.tokens.CreateAlias(this, that_.context_index)),
      tokens(that_.tokens) {
  if (prev_printer_context) {
    prev_printer_context->Tokenize();
  }
  tokens.curr_printer_context = this;
}

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

    const auto data_offset = static_cast<uint32_t>(tokens.data.size());
    assert(0ll <= static_cast<int32_t>(data_offset));
    uint32_t data_len = 0u;
    tokens.data.reserve(data_offset + tok.getLength());
    for (last_i = i, i += tok.getLength(); last_i < i && token_data[last_i];
        ++last_i) {
      tokens.data.push_back(token_data[last_i]);
      ++data_len;
      assert(static_cast<uint16_t>(data_len) != 0u);
    }
    tokens.data.push_back('\0');  // Make sure all tokens end up NUL-terminated.

    // Add the token in.
    tokens.tokens.emplace_back(
        static_cast<int32_t>(data_offset), static_cast<uint16_t>(data_len),
        context_index, num_nl, num_sp, tok.getKind());

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

void TokenPrinterContext::MarkLocation(clang::SourceLocation loc) {
  Tokenize();
  if (!tokens.tokens.empty() && loc.isValid()) {

    // Go figure it out from the AST. We need to go through a lot of indirection
    // because the source locations inside of the parsed AST relate to a huge
    // in-memory file where each post-preprocessed token is on its own line.
    if (tokens.ast) {
      if (auto raw_tok = tokens.ast->RawTokenAt(loc)) {
        tokens.tokens.back().opaque_source_loc = raw_tok->opaque_source_loc;
      }

    // We don't has an `ASTImpl`, so we'll assume that `loc` is a "real" source
    // location and not our weird indirect kind.
    } else {
      tokens.tokens.back().opaque_source_loc = loc.getRawEncoding();
    }
  }
}

TokenPrinterContext::~TokenPrinterContext(void) {
  Tokenize();
  tokens.curr_printer_context = prev_printer_context;

  if (owns_data) {
    tokens.data_to_index.erase(owns_data);
  }
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Decl &decl) {
  return PrintedTokenRange::Create(
      decl.ast, const_cast<clang::Decl *>(decl.u.Decl));
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Stmt &stmt) {
  return PrintedTokenRange::Create(
      stmt.ast, const_cast<clang::Stmt *>(stmt.u.Stmt));
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(const Type &type) {

  auto &ast = type.ast;
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(type.u.Type,
                             type.qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(type.qualifiers));

  return PrintedTokenRange::Create(type.ast, self);
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
