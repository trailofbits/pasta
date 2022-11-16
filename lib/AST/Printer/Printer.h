/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/Printer.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

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

  inline PrintedTokenImpl(TokenDataOffset data_offset_, uint32_t data_len_,
                          TokenContextIndex token_context_index_,
                          unsigned num_leading_new_lines_,
                          unsigned num_leading_spaces_,
                          clang::tok::TokenKind kind_)
      : TokenImpl(TokenImpl::kInvalidSourceLocation, data_offset_,
                  data_len_, kind_, TokenRole::kInvalid,
                  token_context_index_),
        num_leading_new_lines(static_cast<uint16_t>(num_leading_new_lines_)),
        num_leading_spaces(static_cast<uint16_t>(num_leading_spaces_)) {
    assert(num_leading_new_lines == num_leading_new_lines_);
    assert(num_leading_spaces == num_leading_spaces_);
  }
};

// The range of data contained in a token.
class PrintedTokenRangeImpl {
 public:

  // The AST context. This is nifty to have because generally `clang::Stmt`s
  // don't know about the context.
  clang::ASTContext &ast_context;

  //
  // NOTE(pag): May be null if we're printing a "raw" pointer, that possibly
  //            was not produced via PASTA.
  std::shared_ptr<ASTImpl> ast;

  std::vector<PrintedTokenImpl> tokens;

  // The `data_offset` of the `TokenImpl` base of `PrintedTokenImpl` in `tokens`
  // points into this string.
  std::string data;

  // All allocated token contexts live here. The `TokenImpl::context_index` of
  // a `PrintedTokenImpl` points into `contexts`.
  std::vector<TokenContextImpl> contexts;

  // Maps something, e.g. a `clang::Decl *`, `clang::Stmt *`, `clang::Type *`,
  // etc. to the "owning" context for that thing. There can be multiple open
  // contexts for a given thing; the first one is always the owning one, and
  // the rest are aliasing ones.
  std::unordered_map<const void *, unsigned> data_to_index;

  // The current top of the token printer context stack. The structure of the
  // token printing context stack is induced via the call stack, which happens
  // when we recursively print different AST entities.
  TokenPrinterContext *curr_printer_context{nullptr};

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

// Context class for tokenizing what's inside of a particular stream.
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
  if (!data) {
    if (tokenizer->prev_printer_context) {
      return tokenizer->prev_printer_context->context_index;
    } else {
      return kInvalidTokenContextIndex;
    }
  }

  auto dedup = !std::is_same_v<T, char> && !std::is_base_of_v<clang::Type, T>;
  if (dedup) {
    data = Canonicalize(data);
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

  if (tokenizer->prev_printer_context &&
      tokenizer->prev_printer_context->context_index !=
          kInvalidTokenContextIndex) {
    auto parent_index = tokenizer->prev_printer_context->context_index;
    auto parent_depth = contexts[parent_index].depth;
    contexts.emplace_back(
        parent_index,
        parent_depth,
        data);

    // If our parent context is a type, or points to a type, or isn't itself
    // subject to deduplication, then don't deduplicate this one. See
    // Issue #54 (https://github.com/trailofbits/pasta/issues/54).
    switch (contexts[parent_index].kind) {
      case TokenContextKind::kString:
      case TokenContextKind::kType:
        dedup = false;
        break;
      default:
        if (!data_to_index.count(contexts[parent_index].data)) {
          dedup = false;
        }
        break;
    }
  } else {
    contexts.emplace_back(
        kInvalidTokenContextIndex,
        static_cast<uint16_t>(0),
        data);
  }

  tokenizer->owns_data = data;
  if (dedup) {
    data_to_index.emplace(data, index);
  }

  return index;
}

}  // namespace pasta
