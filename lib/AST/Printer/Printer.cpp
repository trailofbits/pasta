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

// Number of leading new lines (before any indentation spaces).
unsigned PrintedToken::NumLeadingNewLines(void) const {
  return impl->num_leading_new_lines;
}

// Number of leading spaces (after any leading new lines).
unsigned PrintedToken::NumleadingSpaces(void) const {
  return impl->num_leading_spaces;
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

const PrintedTokenContext *PrintedTokenRangeImpl::PushContext(
    TokenPrinterContext *tokenizer, const clang::Stmt *stmt) {

  // Make sure any data streamed out between the last token context call and
  // this one gets tokenized.
  if (!tokenizer_stack.empty()) {
    tokenizer_stack.back()->Tokenize();
  }
  tokenizer_stack.push_back(tokenizer);

  if (!context_stack.empty() && context_stack.back()->stmt == stmt) {
    auto context = context_stack.back();
    context_stack.push_back(context);  // Re-use.
    return context;

  } else {
    auto context = new PrintedTokenContext(
        (context_stack.empty() ? nullptr : context_stack.back()),
        stmt);
    contexts.emplace_back(context);
    context_stack.push_back(context);
    return context;
  }
}

const PrintedTokenContext *PrintedTokenRangeImpl::PushContext(
    TokenPrinterContext *tokenizer, const clang::Decl *decl) {
  // Make sure any data streamed out between the last token context call and
  // this one gets tokenized.
  if (!tokenizer_stack.empty()) {
    tokenizer_stack.back()->Tokenize();
  }
  tokenizer_stack.push_back(tokenizer);

  if (!context_stack.empty() && context_stack.back()->decl == decl) {
    auto context = context_stack.back();
    context_stack.push_back(context);  // Re-use.
    return context;

  } else {
    auto context = new PrintedTokenContext(
        (context_stack.empty() ? nullptr : context_stack.back()),
        decl);
    contexts.emplace_back(context);
    context_stack.push_back(context);
    return context;
  }
}

const PrintedTokenContext *PrintedTokenRangeImpl::PushContext(
    TokenPrinterContext *tokenizer, const clang::Type *type) {
  // Make sure any data streamed out between the last token context call and
  // this one get tokenized.
  if (!tokenizer_stack.empty()) {
    tokenizer_stack.back()->Tokenize();
  }
  tokenizer_stack.push_back(tokenizer);

  if (!context_stack.empty() && context_stack.back()->type == type) {
    auto context = context_stack.back();
    context_stack.push_back(context);  // Re-use.
    return context;

  } else {
    auto context = new PrintedTokenContext(
        (context_stack.empty() ? nullptr : context_stack.back()),
        type);
    contexts.emplace_back(context);
    context_stack.push_back(context);
    return context;
  }
}

void PrintedTokenRangeImpl::PopContext(void) {
  const auto last_tokenizer = tokenizer_stack.back();
  last_tokenizer->Tokenize();

  context_stack.pop_back();
  tokenizer_stack.pop_back();
}

TokenPrinterContext::TokenPrinterContext(
    raw_string_ostream &out_, const clang::Decl *decl_,
    PrintedTokenRangeImpl &tokens_, const char *caller_)
    : out(out_),
      context(tokens_.PushContext(this, decl_)),
      tokens(tokens_),
      caller_fn(caller_) {}

TokenPrinterContext::TokenPrinterContext(
    raw_string_ostream &out_, const clang::Stmt *stmt_,
    PrintedTokenRangeImpl &tokens_, const char * caller_)
    : out(out_),
      context(tokens_.PushContext(this, stmt_)),
      tokens(tokens_),
      caller_fn(caller_) {}

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

}  // namespace pasta
