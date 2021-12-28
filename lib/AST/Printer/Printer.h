/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/Printer.h>

#include <llvm/Support/raw_ostream.h>

#include <cassert>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "../Token.h"

namespace clang {
class Decl;
class LangOptions;
class SourceLocation;
class SourceManager;
class Stmt;
class Type;
}  // namespace clang
namespace pasta {

class ASTImpl;
class raw_string_ostream;

class PrintedTokenImpl : public TokenImpl {
 public:
  // The context inherited from the token printer.
  const PrintedTokenContext * const context;

  uint16_t num_leading_new_lines;
  uint16_t num_leading_spaces;

  inline PrintedTokenImpl(int32_t data_offset_, uint16_t data_len_,
                          const PrintedTokenContext *context_,
                          unsigned num_leading_new_lines_,
                          unsigned num_leading_spaces_,
                          clang::tok::TokenKind kind_)
      : TokenImpl(0u  /* source loc */, data_offset_, data_len_, kind_),
        context(context_),
        num_leading_new_lines(static_cast<uint16_t>(num_leading_new_lines_)),
        num_leading_spaces(static_cast<uint16_t>(num_leading_spaces_)) {
    assert(num_leading_new_lines == num_leading_new_lines_);
    assert(num_leading_spaces == num_leading_spaces_);
  }
};

// The range of data contained in a token.
class PrintedTokenRangeImpl {
 public:

  clang::ASTContext &ast_context;
  std::shared_ptr<ASTImpl> ast;
  std::vector<PrintedTokenImpl> tokens;

  // The `data_offset` of the `TokenImpl` base of `PrintedTokenImpl` in `tokens`
  // points into this string.
  std::string data;

  std::vector<std::unique_ptr<PrintedTokenContext>> contexts;
  std::vector<PrintedTokenContext *> context_stack;
  std::vector<TokenPrinterContext *> tokenizer_stack;

  inline PrintedTokenRangeImpl(clang::ASTContext &ast_context_)
      : ast_context(ast_context_) {}

  ~PrintedTokenRangeImpl(void);

  template <typename T>
  const PrintedTokenContext *PushContext(
      TokenPrinterContext *tokenizer, const T *data);

  void PopContext(void);
};

// Context class for tokenizing what's inside of a particular stream stream.
class TokenPrinterContext {
 public:
  template <typename T>
  inline TokenPrinterContext(
      raw_string_ostream &out_, const T *data_,
      PrintedTokenRangeImpl &tokens_, const char *caller_="")
      : out(out_),
        context(tokens_.PushContext<T>(this, data_)),
        tokens(tokens_),
        caller_fn(caller_){}

  void Tokenize(void);

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  void MarkLocation(clang::SourceLocation &loc);

  ~TokenPrinterContext(void);

  pasta::raw_string_ostream &out;
  const PrintedTokenContext * const context;
  PrintedTokenRangeImpl &tokens;
  const char * const caller_fn;
};

template <typename T>
const PrintedTokenContext *PrintedTokenRangeImpl::PushContext(
    TokenPrinterContext *tokenizer, const T *data) {
  // Make sure any data streamed out between the last token context call and
  // this one get tokenized.
  if (!tokenizer_stack.empty()) {
    tokenizer_stack.back()->Tokenize();
  }

  tokenizer_stack.push_back(tokenizer);

  if (!context_stack.empty() && context_stack.back()->data == data) {
    auto context = context_stack.back();
    context_stack.push_back(context);  // Re-use.
    return context;

  } else {
    auto context = new PrintedTokenContext(
        (context_stack.empty() ? nullptr : context_stack.back()),
        data);
    contexts.emplace_back(context);
    context_stack.push_back(context);
    return context;
  }
}

}  // namespace pasta
