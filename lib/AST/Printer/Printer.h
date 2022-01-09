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

  uint16_t num_leading_new_lines;
  uint16_t num_leading_spaces;

  inline PrintedTokenImpl(int32_t data_offset_, uint16_t data_len_,
                          uint32_t token_context_index_,
                          unsigned num_leading_new_lines_,
                          unsigned num_leading_spaces_,
                          clang::tok::TokenKind kind_)
      : TokenImpl(TokenImpl::kInvalidSourceLocation, data_offset_,
                  data_len_, kind_, token_context_index_),
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

  std::vector<TokenContextImpl> contexts;
  std::unordered_map<const void *, unsigned> data_to_index;

  TokenPrinterContext *curr_printer_context{nullptr};

//  std::vector<TokenContextIndex> context_stack;
//  std::vector<TokenPrinterContext *> tokenizer_stack;

  inline PrintedTokenRangeImpl(clang::ASTContext &ast_context_)
      : ast_context(ast_context_) {}

  ~PrintedTokenRangeImpl(void);

  template <typename T>
  const TokenContextIndex CreateContext(
      TokenPrinterContext *tokenizer, const T *data);

  const TokenContextIndex CreateAlias(
      TokenPrinterContext *tokenizer, TokenContextIndex aliasee);

//  void PopContext(void);
};

struct no_alias_tag {};

// Context class for tokenizing what's inside of a particular stream stream.
class TokenPrinterContext {
 public:
  template <typename T>
  inline TokenPrinterContext(
      raw_string_ostream &out_, const T *data_,
      PrintedTokenRangeImpl &tokens_)
      : out(out_),
        prev_printer_context(tokens_.curr_printer_context),
        context_index(tokens_.CreateContext<T>(this, data_)),
        tokens(tokens_) {
    if (prev_printer_context) {
      prev_printer_context->Tokenize();
    }
    tokens.curr_printer_context = this;
  }
  TokenPrinterContext(const TokenPrinterContext &that_, no_alias_tag);
  TokenPrinterContext(const TokenPrinterContext &that_);

  void Tokenize(void);

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  void MarkLocation(clang::SourceLocation loc);

  ~TokenPrinterContext(void);

  pasta::raw_string_ostream &out;
  TokenPrinterContext * const prev_printer_context;
  const TokenContextIndex context_index;
  PrintedTokenRangeImpl &tokens;
  const void *owns_data{nullptr};
};

template <typename T>
const TokenContextIndex PrintedTokenRangeImpl::CreateContext(
    TokenPrinterContext *tokenizer, const T *data) {

  if (data) {
    if (auto it = data_to_index.find(data); it != data_to_index.end()) {
      return it->second;
    }
  }

  if (tokenizer->prev_printer_context) {
    auto &prev = contexts[tokenizer->prev_printer_context->context_index];
    if (prev.data == data) {
      return tokenizer->prev_printer_context->context_index;
    }
  }

  auto index = static_cast<TokenContextIndex>(contexts.size());
  assert(index == contexts.size());
  contexts.emplace_back(
      (tokenizer->prev_printer_context ?
          tokenizer->prev_printer_context->context_index :
          kInvalidTokenContextIndex),
      data);

  if (data) {
    tokenizer->owns_data = data;
    data_to_index.emplace(data, index);
  }

  return index;
}

}  // namespace pasta
