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

#include "Printer/Printer.h"

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
  virtual void Print(std::ostream &os, std::string indent) const = 0;
};

struct Statement final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

  virtual void Print(std::ostream &os, std::string indent) const final {
    os << indent;
    auto sep = "\"";
    for (auto it = begin; it <= end; ++it) {
      if (it->kind == clang::tok::string_literal) {
        os << sep << "<str>";
      } else {
        os << sep << it->data;
      }
      sep = " ";
    }
    os << "\"\n";
  }

  PrintedTokenImpl *begin{nullptr};
  PrintedTokenImpl *end{nullptr};
};

struct SequenceRegion final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kSequence;
  }

  virtual void Print(std::ostream &os, std::string indent) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent);
    }
  }

  // NOTE(pag): These are in reverse order.
  std::vector<Region *> regions;
};

struct BalancedRegion final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kBalanced;
  }

  virtual void Print(std::ostream &os, std::string indent) const final {
    os << indent << begin->data << '\n';
    if (statements) {
      statements->Print(os, indent + "  ");
    }
    os << indent << end->data << '\n';
  }

  PrintedTokenImpl *begin{nullptr};
  SequenceRegion *statements{nullptr};
  PrintedTokenImpl *end{nullptr};
};

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
  std::vector<SequenceRegion *> region_stack;
  std::vector<PrintedTokenImpl *> stopper_stack;
  std::vector<std::tuple<clang::tok::TokenKind, clang::tok::TokenKind, clang::tok::TokenKind>> stmt_stoppers;

  auto push_empty_sequence = [&regions, &region_stack] (void) {
    const auto empty = new SequenceRegion;
    regions.emplace_back(empty);
    region_stack.emplace_back(empty);
    return empty;
  };

  auto try_add_stmt = [&] (PrintedTokenImpl *begin) {
    if (!stopper_stack.empty()) {
      auto end = stopper_stack.back();
      stopper_stack.pop_back();

      // If the end token is a closing thing then back it up.
      if (end->kind == clang::tok::r_paren ||
          end->kind == clang::tok::r_square ||
          end->kind == clang::tok::r_brace ||
          end->kind == clang::tok::l_paren ||
          end->kind == clang::tok::l_square ||
          end->kind == clang::tok::l_brace) {
        end = &(end[-1]);
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
  auto at_stop = [&] (PrintedTokenImpl *tok_ptr) {
    try_add_stmt(&(tok_ptr[1u]));
    stopper_stack.push_back(tok_ptr);
  };

  push_empty_sequence();
  stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi, clang::tok::semi);

  // Traverse backwards through the printed tokens and try to match brackets,
  // braces, and parentheses with what is in the pre-processed code. We go
  // backward because the printed token ranges might start with declarations
  // for builtins, which are not present in the preprocessed code.
  std::vector<std::pair<clang::tok::TokenKind, PrintedTokenImpl *>> match_stack;
  for (auto it = range.after_last, end = range.first; it != end; ) {
    PrintedTokenImpl &tok = *--it;
    switch (auto kind = static_cast<clang::tok::TokenKind>(tok.kind)) {

      // We have found the beginning of a nested region, in terms of the ending
      // token of that nested region.
      case clang::tok::r_paren:
        at_stop(&tok);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_paren, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi,
                                   clang::tok::comma  /* parameter lists */,
                                   clang::tok::colon  /* for loops */);
        break;
      case clang::tok::r_square:
        at_stop(&tok);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_square, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi,
                                   clang::tok::comma  /* comma expressions */);
        break;
      case clang::tok::r_brace:
        at_stop(&tok);
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
              << clang::tok::getKeywordSpelling(kind)
              << "; match stack is empty";
          return err.str();
        } else {
          auto [opening_kind, r_tok] = match_stack.back();

          match_stack.pop_back();
          stmt_stoppers.pop_back();

          at_stop(&tok);

          if (opening_kind != kind) {
            err << "Unbalanced "
                << clang::tok::getKeywordSpelling(kind)
                << "; expected a "
                << clang::tok::getKeywordSpelling(opening_kind);
            return err.str();

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
          at_stop(&tok);
        }
        break;

      default:
        break;
    }
  }

  if (region_stack.size() != 1) {
    err
        << "Region stack for printed tokens has " << region_stack.size()
        << " regions";
    return err.str();
  }

  region_stack.back()->Print(std::cout, "");

  return AST(std::move(ast));
}

}  // namespace pasta
