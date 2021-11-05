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

  // Update the next tokenizer down on the stack to not re-tokenize the
  // tokens just tokenized by `last_tokenizer`.
  if (!tokenizer_stack.empty()) {
    tokenizer_stack.back()->start_loc = last_tokenizer->start_loc;
  }
}

TokenPrinterContext::TokenPrinterContext(
    raw_string_ostream &out_, const clang::Decl *decl_,
    PrintedTokenRangeImpl &tokens_, const char *caller_)
    : out(out_),
      context(tokens_.PushContext(this, decl_)),
      tokens(tokens_),
      caller_fn(caller_),
      start_loc(out.str().size()) {}

TokenPrinterContext::TokenPrinterContext(
    raw_string_ostream &out_, const clang::Stmt *stmt_,
    PrintedTokenRangeImpl &tokens_, const char * caller_)
    : out(out_),
      context(tokens_.PushContext(this, stmt_)),
      tokens(tokens_),
      caller_fn(caller_),
      start_loc(out.str().size()) {}

void TokenPrinterContext::Tokenize(void) {
  clang::SourceManager &sm = tokens.ast_context.getSourceManager();
  const clang::LangOptions &lo = tokens.ast_context.getLangOpts();

  const std::string &token_data = out.str();
  if (start_loc >= token_data.size()) {
    return;
  }

  clang::Lexer lexer(
      clang::SourceLocation(),
      lo,
      &(token_data[0]),
      &(token_data[start_loc]),
      &(token_data[0]) + token_data.size());

  lexer.SetKeepWhitespaceMode(false);
  lexer.SetCommentRetentionState(false);

  clang::Token tok;

  for (lexer.LexFromRawLexer(tok); tok.isNot(clang::tok::eof);
       lexer.LexFromRawLexer(tok)) {

    std::string tok_data;
    if (!TryReadRawToken(sm, lo, tok, &tok_data)) {
      llvm::errs() << "Unable to read token";
      assert(false);
    }

    // Add the token in.
    PrintedTokenImpl &ptok = tokens.tokens.emplace_back(
        std::move(tok_data), context, tok.getKind());

    (void) ptok;
  }

  // Update for the next start location.
  start_loc = token_data.size();
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
