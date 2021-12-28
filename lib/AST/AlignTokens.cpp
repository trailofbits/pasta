/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "AST.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include <iostream>
#include <sstream>
#include <fstream>

#include "Printer/Printer.h"

#define PASTA_DEBUG_ALIGN 1

namespace pasta {
namespace {

enum class RegionKind {
  kStatement,
  kSequence,
  kBalanced
};

struct Region {
 public:
  virtual ~Region(void) = default;
  virtual RegionKind Kind(void) const noexcept = 0;

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const = 0;
  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const = 0;
#endif  // PASTA_DEBUG_ALIGN
};

struct Statement final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const final {
    os << indent;
    auto sep = "\"";
    for (auto it = begin; it <= end; ++it) {
      if (it->kind == clang::tok::string_literal) {
        os << sep << "<str>";
      } else {
        os << sep << it->Data(ast);
      }
      sep = " ";
    }
    os << "\"\n";
  }

  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    os << indent;
    auto sep = "\"";
    auto begin_ = reinterpret_cast<PrintedTokenImpl *>(begin);
    auto end_ = reinterpret_cast<PrintedTokenImpl *>(end);
    for (auto it = begin_; it <= end_; ++it) {
      if (it->kind == clang::tok::string_literal) {
        os << sep << "<str>";
      } else {
        os << sep << it->Data(range);
      }
      sep = " ";
    }
    os << "\"\n";
  }
#endif  // PASTA_DEBUG_ALIGN

  TokenImpl *begin{nullptr};
  TokenImpl *end{nullptr};
};

struct SequenceRegion final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kSequence;
  }

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent, ast);
    }
  }

  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent, range);
    }
  }
#endif  // PASTA_DEBUG_ALIGN

  // NOTE(pag): These are in reverse order.
  std::vector<Region *> regions;
};

struct BalancedRegion final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kBalanced;
  }

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const final {
    os << indent << begin->Data(ast) << '\n';
    if (statements) {
      statements->Print(os, indent + "  ", ast);
    }
    os << indent << end->Data(ast) << '\n';
  }

  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    os << indent << begin->Data(range) << '\n';
    if (statements) {
      statements->Print(os, indent + "  ", range);
    }
    os << indent << end->Data(range) << '\n';
  }
#endif  // PASTA_DEBUG_ALIGN

  TokenImpl *begin{nullptr};
  SequenceRegion *statements{nullptr};
  TokenImpl *end{nullptr};
};

static SequenceRegion *BuildRegions(
    std::vector<std::unique_ptr<Region>> &regions, std::stringstream &err,
    uint8_t *first, uint8_t *after_last, size_t tok_size_,
    const char *list_kind) {

  const ptrdiff_t tok_size = static_cast<ptrdiff_t>(tok_size_);
  std::vector<SequenceRegion *> region_stack;
  std::vector<TokenImpl *> stopper_stack;
  std::vector<std::pair<clang::tok::TokenKind, TokenImpl *>> match_stack;
  std::vector<std::tuple<clang::tok::TokenKind, clang::tok::TokenKind,
                         clang::tok::TokenKind>> stmt_stoppers;

  auto push_empty_sequence = [&] (void) {
    const auto empty = new SequenceRegion;
    regions.emplace_back(empty);
    region_stack.emplace_back(empty);
    return empty;
  };

  auto try_add_stmt = [&] (TokenImpl *begin) {
    if (!stopper_stack.empty()) {
      TokenImpl *end = stopper_stack.back();
      stopper_stack.pop_back();

      // If the end token is a closing thing then back it up.
      if (end->kind == clang::tok::r_paren ||
          end->kind == clang::tok::r_square ||
          end->kind == clang::tok::r_brace ||
          end->kind == clang::tok::l_paren ||
          end->kind == clang::tok::l_square ||
          end->kind == clang::tok::l_brace) {
        end = reinterpret_cast<TokenImpl *>(
            &(reinterpret_cast<uint8_t *>(end)[-tok_size]));
      }

      if (begin <= end) {
        auto stmt = new Statement;
        regions.emplace_back(stmt);

        stmt->begin = begin;
        stmt->end = end;
        region_stack.back()->regions.push_back(stmt);
      }
    }
  };

  // When we get to a stopping point, then try to form a statement.
  auto at_stop = [&] (uint8_t *tok_ptr, uint8_t *next_tok_ptr) {
    assert(&(tok_ptr[tok_size]) == next_tok_ptr);
    try_add_stmt(reinterpret_cast<TokenImpl *>(next_tok_ptr));
    stopper_stack.push_back(reinterpret_cast<TokenImpl *>(tok_ptr));
  };

  push_empty_sequence();
  stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi,
                             clang::tok::semi);

  // Traverse backwards through the printed tokens and try to match brackets,
  // braces, and parentheses with what is in the pre-processed code. We go
  // backward because the printed token ranges might start with declarations
  // for builtins, which are not present in the preprocessed code.
  for (auto it = after_last, end = first; it != end; ) {

    auto next_it = it;

    // Decrement by `sizeof(TokenImpl)` or `sizeof(PrintedTokenImpl)`.
    it = &(it[-tok_size]);

    TokenImpl &tok = *reinterpret_cast<TokenImpl *>(it);

    switch (auto kind = static_cast<clang::tok::TokenKind>(tok.kind)) {

      // We have found the beginning of a nested region, in terms of the ending
      // token of that nested region.
      case clang::tok::r_paren:
        at_stop(it, next_it);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_paren, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi,
                                   clang::tok::comma  /* parameter lists */,
                                   clang::tok::colon  /* for loops */);
        break;
      case clang::tok::r_square:
        at_stop(it, next_it);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_square, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi,
                                   clang::tok::comma  /* comma expressions */);
        break;
      case clang::tok::r_brace:
        at_stop(it, next_it);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_brace, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi,
                                   clang::tok::colon  /* `public:`, etc. */);
        break;

      // We have found the end of a nested region, in terms of the beginning
      // token of that nested region.
      case clang::tok::l_paren:
      case clang::tok::l_square:
      case clang::tok::l_brace:
        if (match_stack.empty()) {
          err << "Unable to match opening "
              << clang::tok::getTokenName(kind)
              << "; match stack is empty for " << list_kind << " tokens";
          return nullptr;
        } else {
          auto [opening_kind, r_tok] = match_stack.back();

          match_stack.pop_back();
          stmt_stoppers.pop_back();

          at_stop(it, next_it);

          if (opening_kind != kind) {
            err << "Unbalanced "
                << clang::tok::getTokenName(kind)
                << " (starting index " << ((it - first) / tok_size) << "); expected a "
                << clang::tok::getTokenName(opening_kind)
                << " (ending index "
                << ((reinterpret_cast<uint8_t *>(r_tok) - first) / tok_size)
                << ") in " << list_kind << " tokens";

            return nullptr;

          } else {
            assert(!region_stack.empty());
            auto br = new BalancedRegion;
            regions.emplace_back(br);

            br->begin = &tok;
            br->end = r_tok;
            br->statements = region_stack.back();
            region_stack.pop_back();
            assert(!region_stack.empty());
            region_stack.back()->regions.push_back(br);
          }
          break;
        }

      // We've found the end of a statement.
      case clang::tok::semi:
      case clang::tok::comma:
      case clang::tok::colon:
        if (kind == std::get<0>(stmt_stoppers.back()) ||
            kind == std::get<1>(stmt_stoppers.back()) ||
            kind == std::get<2>(stmt_stoppers.back())) {
          at_stop(it, next_it);
        }
        break;

      default:
        break;
    }
  }

  if (region_stack.size() != 1u) {
    err
        << "Region stack for " << list_kind << " tokens has "
        << region_stack.size() << " regions";
    return nullptr;

  } else {
    return region_stack.back();
  }
}

}  // namespace

// Try to align parsed tokens with printed tokens. See `AlignTokens.cpp`.
Result<AST, std::string> ASTImpl::AlignTokens(std::shared_ptr<ASTImpl> ast) {
  auto range = PrintedTokenRange::Create(
      ast->ci->getASTContext(), *ast->printing_policy, ast->tu);
  if (range.empty()) {
    return AST(std::move(ast));
  }

  std::stringstream err;
  std::vector<std::unique_ptr<Region>> regions;

  auto first_tok = &(ast->tokens.front());
  auto after_last_tok = &(ast->tokens.back());  // Has an `eof` token.
  assert(after_last_tok->kind == clang::tok::eof);

  auto parsed_tree = BuildRegions(
      regions, err, reinterpret_cast<uint8_t *>(first_tok),
      reinterpret_cast<uint8_t *>(after_last_tok), sizeof(*first_tok),
      "parsed");
  if (!parsed_tree) {
    return err.str();
  }

#if PASTA_DEBUG_ALIGN
  std::ofstream parsed_os("/tmp/tree.parsed");
  parsed_tree->Print(parsed_os, "", *ast);


//  std::ofstream source_os("/tmp/source.printed");
//  for (auto it = range.first; it < range.after_last; ++it) {
//    source_os << it->Data(*(range.impl)) << '\n';
//  }
#endif   // PASTA_DEBUG_ALIGN

  auto printed_tree = BuildRegions(
      regions, err, reinterpret_cast<uint8_t *>(range.first),
      reinterpret_cast<uint8_t *>(range.after_last), sizeof(*range.first),
      "printed");
  if (!printed_tree) {
    return err.str();
  }

#if PASTA_DEBUG_ALIGN
  std::ofstream printed_os("/tmp/tree.printed");
  printed_tree->Print(printed_os, "", *(range.impl));
#endif   // PASTA_DEBUG_ALIGN

  return AST(std::move(ast));
}

}  // namespace pasta
