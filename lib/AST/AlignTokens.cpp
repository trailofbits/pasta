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

#include <initializer_list>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Builder.h"
#include "Printer/Printer.h"

#define PASTA_DEBUG_ALIGN 1
#define TK(...)

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

struct StatementRegion final : public Region {
  virtual RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const final {
    for (TokenImpl *it = begin; it <= end; ++it) {
      if (it->kind == clang::tok::string_literal) {
        os << indent << "<str>";
      } else {
        os << indent << it->Data(ast);
      }
      TK( os << " " << clang::tok::getTokenName(it->kind); )
      if (it->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        os << " l:" << std::hex << it->opaque_source_loc << std::dec;
      }
      if (it->context_index != kInvalidTokenContextIndex) {
        os << " c:" << std::hex << it->context_index << std::dec;
      }
      os << '\n';
    }
  }

  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    auto begin_ = reinterpret_cast<PrintedTokenImpl *>(begin);
    auto end_ = reinterpret_cast<PrintedTokenImpl *>(end);
    for (PrintedTokenImpl *it = begin_; it <= end_; ++it) {
      if (it->kind == clang::tok::string_literal) {
        os << indent << "<str>";
      } else {
        os << indent << it->Data(range);
      }
      TK( os << " " << clang::tok::getTokenName(it->kind); )
      if (it->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        os << " l:" << std::hex << it->opaque_source_loc << std::dec;
      }
      if (it->context_index != kInvalidTokenContextIndex) {
        os << " c:" << std::hex << it->context_index << std::dec;
      }
      os << '\n';
    }
  }
#endif  // PASTA_DEBUG_ALIGN

  TokenImpl *begin{nullptr};
  TokenImpl *end{nullptr};  // Inclusive.
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
    os << indent << begin->Data(ast) << " " << clang::tok::getTokenName(begin->kind);
    if (begin->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      os << " l:" << std::hex << begin->opaque_source_loc << std::dec;
    }
    if (begin->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << begin->context_index << std::dec;
    }
    os << '\n';

    if (statements) {
      statements->Print(os, indent + "  ", ast);
    }

    os << indent << end->Data(ast) << " " << clang::tok::getTokenName(end->kind);
    if (end->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      os << " l:" << std::hex << end->opaque_source_loc << std::dec;
    }
    if (end->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << end->context_index << std::dec;
    }
    os << '\n';
  }

  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    os << indent << begin->Data(range) << " " << clang::tok::getTokenName(begin->kind);
    if (begin->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      os << " l:" << std::hex << begin->opaque_source_loc << std::dec;
    }
    if (begin->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << begin->context_index << std::dec;
    }
    os << '\n';
    if (statements) {
      statements->Print(os, indent + "  ", range);
    }
    os << indent << end->Data(range) << " " << clang::tok::getTokenName(end->kind);
    if (end->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      os << " l:" << std::hex << end->opaque_source_loc << std::dec;
    }
    if (end->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << end->context_index << std::dec;
    }
    os << '\n';
  }
#endif  // PASTA_DEBUG_ALIGN

  TokenImpl *begin{nullptr};
  SequenceRegion *statements{nullptr};
  TokenImpl *end{nullptr};
};

// Organize the tokens into a tree, grouped by brace/bracket/paren-enclosed
// regions, and comma/semicolon-separated regions.
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
        auto stmt = new StatementRegion;
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
                << " (starting index " << ((it - first) / tok_size)
                << "); expected a "
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

static bool MergeToken(TokenImpl *parsed, PrintedTokenImpl *printed) {
  if (parsed->context_index == printed->context_index &&
      parsed->context_index != kInvalidTokenContextIndex) {
    return false;
  } else {
    parsed->context_index = printed->context_index;
    printed->opaque_source_loc = parsed->opaque_source_loc;
    return true;
  }
}

class Matcher {
 private:
  ASTImpl &ast;
  PrintedTokenRangeImpl &range;
  std::vector<std::pair<BalancedRegion *, BalancedRegion *>> failed_balanced;

  template <typename Parsed, typename Printed, typename Eq>
  std::vector<std::vector<unsigned>>
  Distance(Parsed *parsed_begin, Parsed *parsed_end,
           Printed *printed_begin, Printed *printed_end,
           Eq equals);

 public:
  inline explicit Matcher(ASTImpl &ast_, PrintedTokenRangeImpl &range_)
      : ast(ast_),
        range(range_) {}

  bool DataEquals(TokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchToken(TokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchTokenByKindOrData(TokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                     int force);
  bool MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                     int force);
  bool MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                      int force);
  bool MatchRegions(Region *parsed, Region *printed,
                    int force);
  bool MatchFailed(void);

  bool MergeBackward(TokenImpl *parsed, PrintedTokenImpl *printed);
  bool MergeForward(TokenImpl *parsed, PrintedTokenImpl *printed);
};

template <typename Parsed, typename Printed, typename Eq>
std::vector<std::vector<unsigned>>
Matcher::Distance(Parsed *parsed_begin, Parsed *parsed_end,
                  Printed *printed_begin, Printed *printed_end,
                  Eq equals_pred) {
  const auto num_rows = static_cast<unsigned>(parsed_end - parsed_begin);
  const auto num_cols = static_cast<unsigned>(printed_end - printed_begin);

  std::vector<std::vector<unsigned>> cost;
  cost.resize(num_rows + 1u);
  for (auto row = 0u; row <= num_rows; ++row) {
    cost[row].resize(num_cols + 1u);
    cost[row][0] = static_cast<unsigned>(row);
  }

  for (auto col = 1u; col <= num_cols; ++col) {
    cost[0][col] = static_cast<unsigned>(col);
  }

  for (auto col = 1u; col <= num_cols; ++col) {
    for (auto row = 1u; row <= num_rows; ++row) {
      auto edit_cost = 0u;
      if (!equals_pred(parsed_begin[row - 1u], printed_begin[col - 1u])) {
        edit_cost = 1u;
      }

      cost[row][col] = std::min(std::initializer_list<unsigned>{
        cost[row - 1u][col] + 1u,
        cost[row][col - 1u] + 1u,
        cost[row - 1u][col - 1u] + edit_cost
      });
    }
  }

  return cost;
}

bool Matcher::DataEquals(TokenImpl *parsed, PrintedTokenImpl *printed) {
  return parsed->Data(ast) == printed->Data(range);
}

bool Matcher::MergeBackward(TokenImpl *parsed, PrintedTokenImpl *printed) {
  auto changed = false;

  const auto last_parsed = &(ast.tokens.back());
  const auto last_printed = &(range.tokens.back());
  while (parsed <= last_parsed && printed <= last_printed) {

    if (parsed->kind == clang::tok::comment ||
        parsed->kind == clang::tok::unknown) {
      ++parsed;
      continue;
    }

    if (!MatchTokenByKindOrData(parsed, printed)) {
      break;
    }

    if (!MergeToken(parsed, printed) && changed) {
      break;
    } else {
      changed = true;
      ++parsed;
      ++printed;
    }
  }

  return changed;
}

bool Matcher::MergeForward(TokenImpl *parsed, PrintedTokenImpl *printed) {

  auto changed = false;
  const auto first_parsed = &(ast.tokens.front());
  const auto first_printed = &(range.tokens.front());
  while (parsed >= first_parsed && printed >= first_printed) {

    if (parsed->kind == clang::tok::comment ||
        parsed->kind == clang::tok::unknown) {
      --parsed;
      continue;
    }

    if (!MatchTokenByKindOrData(parsed, printed)) {
      break;
    }

    if (!MergeToken(parsed, printed) && changed) {
      break;

    } else {
      changed = true;
      --parsed;
      --printed;
    }
  }

  return changed;
}

bool Matcher::MatchToken(TokenImpl *parsed, PrintedTokenImpl *printed) {
  if (parsed->opaque_source_loc == printed->opaque_source_loc &&
      parsed->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
    return true;

  } else {
    return MatchTokenByKindOrData(parsed, printed);
  }
}

bool Matcher::MatchTokenByKindOrData(TokenImpl *parsed,
                                     PrintedTokenImpl *printed) {
  if (clang::tok::isLiteral(parsed->kind)) {
    return parsed->kind == printed->kind;

  } else if (parsed->kind == printed->kind) {
    return true;

  } else {
    return DataEquals(parsed, printed);
  }
}

bool Matcher::MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                            int force) {
  if (parsed->begin->kind != printed->begin->kind) {
    return false;
  }

  assert(parsed->end->kind == printed->end->kind);

  auto begin_loc_matches =
      (parsed->begin->opaque_source_loc == printed->begin->opaque_source_loc) &&
      parsed->begin->opaque_source_loc != TokenImpl::kInvalidSourceLocation;

  auto end_loc_matches =
      (parsed->end->opaque_source_loc == printed->end->opaque_source_loc) &&
      parsed->begin->opaque_source_loc != TokenImpl::kInvalidSourceLocation;

  if (!begin_loc_matches && !end_loc_matches) {
    failed_balanced.emplace_back(parsed, printed);
    return false;
  }

  // If we pivoted from a match on the ending to injecting a match on the
  // beginning, then apply linear matching around the beginning of the range.
  auto printed_begin = reinterpret_cast<PrintedTokenImpl *>(printed->begin);
  MergeForward(parsed->begin, printed_begin);
  MergeForward(parsed->begin, printed_begin);

  // If we pivoted from a match on the beginning to injecting a match on the
  // ending, then apply linear matching around the ending of the range.
  auto printed_end = reinterpret_cast<PrintedTokenImpl *>(printed->end);
  MergeForward(parsed->end, printed_end);
  MergeBackward(parsed->end, printed_end);

  if (parsed->statements && printed->statements) {
    return MatchSequence(parsed->statements, printed->statements, force - 1);
  } else {
    return false;
  }
}

// NOTE(pag): The elements in a sequence are already in reverse order.
bool Matcher::MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                            int force) {
  if (parsed->regions.empty() != printed->regions.empty()) {
    return false;  // One is empty, the other isn't.

  } else if (parsed->regions.empty()) {
    return true;  // Both are empty.
  }

  auto parsed_begin = &(parsed->regions.front());
  const auto parsed_end = &(parsed->regions.back());

  auto printed_begin = &(printed->regions.front());
  const auto printed_end = &(printed->regions.back());

  auto num_matches = 0;
  auto num_missed_printed = 0;
  auto num_missed_parsed = 0;

  std::vector<Region *> not_matched_parsed;
  std::vector<Region *> not_matched_printed;

  do {
    auto parsed_dist = parsed_end - parsed_begin;
    auto printed_dist = printed_end - printed_begin;

    // Special case: Skip over parsed statements ending in unknown/comments.
    while (auto stmt = dynamic_cast<StatementRegion *>(*parsed_end)) {
      if (stmt->end->kind == clang::tok::unknown ||
          stmt->end->kind == clang::tok::comment) {
        ++parsed_begin;
        if (parsed_begin > parsed_end) {
          break;
        }
      } else {
        break;
      }
    }

    if (MatchRegions(*parsed_end, *printed_end, force - 1)) {
      ++parsed_begin;
      ++printed_begin;
      ++num_matches;

    } else if (parsed_dist < printed_dist) {
      not_matched_printed.push_back(*printed_end);
      ++printed_begin;
      ++num_missed_printed;

    } else if (parsed_dist > printed_dist) {
      not_matched_parsed.push_back(*parsed_end);
      ++parsed_begin;
      ++num_missed_parsed;

    } else {
      not_matched_printed.push_back(*printed_end);
      not_matched_parsed.push_back(*parsed_end);
      ++parsed_begin;
      ++printed_begin;
      ++num_missed_printed;
      ++num_missed_parsed;
    }

  } while (parsed_begin <= parsed_end && printed_begin <= printed_end);

  // Try an all-by-all matching strategy.
  for (auto &sub_parsed : not_matched_parsed) {
    for (auto &sub_printed : not_matched_printed) {
      if (!sub_parsed) {
        break;
      }
      if (!sub_printed) {
        continue;
      }
      if (MatchRegions(sub_parsed, sub_printed, force - 1)) {
        sub_parsed = nullptr;
        sub_printed = nullptr;
        ++num_matches;
      }
    }
  }

  auto match_miss_ratio = double(num_matches + 1) /
                          double(num_missed_parsed + num_missed_printed + 1);

  if (force <= 0 && match_miss_ratio < 1.0) {
    return false;
  }

  std::cerr
      << "sequence distance num_matches=" << num_matches
      << " num_missed_printed=" << num_missed_printed << " num_missed_parsed="
      << num_missed_parsed << '\n';

  return true;
}

bool Matcher::MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                             int force) {
  const auto parsed_begin = parsed->begin;
  auto parsed_end = parsed->end;

  const auto printed_begin = reinterpret_cast<PrintedTokenImpl *>(printed->begin);
  auto printed_end = reinterpret_cast<PrintedTokenImpl *>(printed->end);

  auto num_matches = 0;
  auto num_missed_parsed = 0;
  auto num_missed_printed = 0;
  auto num_location_matches = 0;

  std::vector<std::pair<TokenImpl *, PrintedTokenImpl *>> matches;

  do {
    auto parsed_dist = parsed_end - parsed_begin;
    auto printed_dist = printed_end - printed_begin;

    if (parsed_end->kind == clang::tok::unknown ||
        parsed_end->kind == clang::tok::comment) {
      --parsed_end;
      continue;
    }

    if (parsed_end->opaque_source_loc == printed_end->opaque_source_loc &&
        parsed_end->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      ++num_location_matches;
    }

    if (MatchToken(parsed_end, printed_end)) {
      matches.emplace_back(parsed_end, printed_end);
      --parsed_end;
      --printed_end;
      ++num_matches;

    } else if (parsed_dist < printed_dist) {
      --printed_end;
      ++num_missed_printed;

    } else if (parsed_dist > printed_dist) {
      --parsed_end;
      ++num_missed_parsed;

    } else {
      --parsed_end;
      --printed_end;
      ++num_missed_printed;
      ++num_missed_parsed;
    }

  } while (parsed_end >= parsed_begin && printed_end >= printed_begin);

  for (auto [parsed_tok, printed_tok] : matches) {
    MergeBackward(parsed_tok, printed_tok);
    MergeForward(parsed_tok, printed_tok);
  }

  auto match_miss_ratio = double(num_matches + 1) /
                          double(num_missed_parsed + num_missed_printed + 1);

  if (force <= 0 && !num_location_matches && match_miss_ratio < 1.0) {
    return false;
  }


  std::cerr
      << "statement distance num_matches=" << num_matches
      << " num_location_matches=" << num_location_matches
      << " num_missed_printed=" << num_missed_printed << " num_missed_parsed="
      << num_missed_parsed << '\n';

  return true;
//
//  if (num_matches != max_matches && max_run_len != max_matches) {
//    // Too many misses.
//    if (num_matches <= (num_missed_parsed + num_missed_printed) ||
//        1 <= max_run_len) {
//      return false;
//    }
//  }
//
//
//
//  return true;

//  auto cost = Distance(parsed_begin, &(parsed_end[1u]),
//                       printed_begin, &(printed_end[1u]),
//                       [this] (TokenImpl &sub_parsed,
//                               PrintedTokenImpl &sub_printed) {
//                         return MatchToken(&sub_parsed, &sub_printed);
//                       });
//
////  parsed_end->context_index = printed_end->context_index;
//
//  auto dist = cost.back().back();
//  auto percent = (double(dist) / double(parsed_end - parsed_begin));
//  if (0.3 >= percent) {
//    return false;
//  }
//
//  std::cerr
//      << "statement distance = " << dist << "(" << percent << ")"
//      << " / rows = " << (parsed_end - parsed_begin)
//      << " / cols = " << (printed_end - printed_begin) << "\n";
//
//
//  std::cerr << "statement distance = " << dist << "\n";
//  return true;
}

bool Matcher::MatchRegions(Region *parsed, Region *printed,
                           int force) {
  if (!parsed != !printed) {
    return false;
  }
  const auto kind = parsed->Kind();
  if (kind != printed->Kind()) {
    return false;
  }
  switch (kind) {
    case RegionKind::kBalanced:
      return MatchBalanced(dynamic_cast<BalancedRegion *>(parsed),
                           dynamic_cast<BalancedRegion *>(printed), force);
    case RegionKind::kSequence:
      return MatchSequence(dynamic_cast<SequenceRegion *>(parsed),
                           dynamic_cast<SequenceRegion *>(printed), force);
    case RegionKind::kStatement:
      return MatchStatement(dynamic_cast<StatementRegion *>(parsed),
                            dynamic_cast<StatementRegion *>(printed), force);
  }
  return false;
}

// Try to look at the tokens following balanced regions, and if they match, then
// back-propagate to the balanced regions. This is to help drill down on the
// source locations of things associated with types, as the type printer itself
// operates on `clang::QualType`s and not `clang::TypeLoc`s.
bool Matcher::MatchFailed(void) {
  std::vector<std::pair<BalancedRegion *, BalancedRegion *>>
      prev_failed_balanced;

  const auto first_parsed_tok = &(ast.tokens.front());

  auto global_changed = false;
  for (auto changed = true; changed && !failed_balanced.empty(); ) {
    changed = false;
    prev_failed_balanced.clear();
    prev_failed_balanced.swap(failed_balanced);
    for (auto [a, b] : failed_balanced) {
      BalancedRegion *parsed_balanced = a;
      BalancedRegion *printed_balanced = b;

      auto merge = [&] (void) {
        parsed_balanced->begin->context_index =
            printed_balanced->begin->context_index;
        parsed_balanced->end->context_index =
            printed_balanced->end->context_index;

        printed_balanced->begin->opaque_source_loc =
            parsed_balanced->begin->opaque_source_loc;
        printed_balanced->end->opaque_source_loc =
            parsed_balanced->end->opaque_source_loc;

        changed = true;
        global_changed = true;

        MatchBalanced(parsed_balanced, printed_balanced, 2);
      };

      if (parsed_balanced->begin->context_index == kInvalidTokenContextIndex &&
          parsed_balanced->end->context_index == kInvalidTokenContextIndex) {

        // Look at the token following the balanced token. It's safe-ish to look
        // ahead by one because there is always an `EOF` token at the end of the
        // parsed tokens.
        if ((parsed_balanced->end[1].context_index !=
                kInvalidTokenContextIndex) &&
            (parsed_balanced->end[1].opaque_source_loc ==
                printed_balanced->end[1].opaque_source_loc)) {

          merge();

        } else if (parsed_balanced->begin > first_parsed_tok &&
                   (parsed_balanced->begin[-1].context_index !=
                       kInvalidTokenContextIndex) &&
                   (parsed_balanced->begin[-1].opaque_source_loc ==
                       printed_balanced->begin[-1].opaque_source_loc)) {

          merge();
        }
      } else {
        failed_balanced.emplace_back(parsed_balanced, printed_balanced);
      }
    }
  }

  failed_balanced.clear();
  return global_changed;
}

}  // namespace

// Try to align parsed tokens with printed tokens. See `AlignTokens.cpp`.
Result<AST, std::string> ASTImpl::AlignTokens(std::shared_ptr<ASTImpl> ast) {
  auto tu = DeclBuilder::Create<TranslationUnitDecl>(ast, ast->tu);
  auto range = PrintedTokenRange::Create(tu);
  if (range.empty()) {
    return AST(std::move(ast));
  }

  std::stringstream err;
  std::vector<std::unique_ptr<Region>> parsed_regions;
  std::vector<std::unique_ptr<Region>> printed_regions;

  const auto first_tok = &(ast->tokens.front());
  const auto after_last_tok = &(ast->tokens.back());  // Has an `eof` token.
  assert(after_last_tok->kind == clang::tok::eof);

  auto parsed_tree = BuildRegions(
      parsed_regions, err, reinterpret_cast<uint8_t *>(first_tok),
      reinterpret_cast<uint8_t *>(after_last_tok), sizeof(*first_tok),
      "parsed");
  if (!parsed_tree) {
    return err.str();
  }

  auto printed_tree = BuildRegions(
      printed_regions, err, reinterpret_cast<uint8_t *>(range.first),
      reinterpret_cast<uint8_t *>(range.after_last), sizeof(*range.first),
      "printed");
  if (!printed_tree) {
    return err.str();
  }

  Matcher matcher(*ast, *(range.impl));

  // Join on the shared source locations, and linearly "spread"
  // outward from there. This should generally cover a bunch.
  auto join_based_linear_merge = [&] () {
    std::unordered_map<unsigned, std::pair<TokenImpl *, PrintedTokenImpl *>> loc_to_toks;
    for (auto tok = range.first; tok < range.after_last; ++tok) {
      if (tok->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        loc_to_toks[tok->opaque_source_loc].second = tok;
      }
    }
    for (auto tok = first_tok; tok < after_last_tok; ++tok) {
      if (loc_to_toks.count(tok->opaque_source_loc)) {
        loc_to_toks[tok->opaque_source_loc].first = tok;
      }
    }

    for (auto [loc, parsed_printed] : loc_to_toks) {
      auto [parsed, printed] = parsed_printed;
      if (parsed && printed) {
        matcher.MergeBackward(parsed, printed);
        matcher.MergeBackward(parsed, printed);
      }
    }
  };

  // Join on the shared source locations of balanced and statement regions.
  auto join_based_region_merge = [&] () {
    std::unordered_multimap<unsigned, BalancedRegion *> printed_begin_loc_to_balanced;
    std::unordered_multimap<unsigned, BalancedRegion *> printed_end_loc_to_balanced;
    std::unordered_multimap<unsigned, StatementRegion *> printed_end_loc_to_statement;

    // We generally have decent-ish ability in the token printer (due to clang
    // source locations) to find things like the location of a `}` or a `{`, or
    // a `;`.
    for (const auto &printed_region : printed_regions) {
      if (auto balanced = dynamic_cast<BalancedRegion *>(printed_region.get())) {
        if (balanced->begin->opaque_source_loc !=
            TokenImpl::kInvalidSourceLocation) {
          printed_begin_loc_to_balanced.emplace(
              balanced->begin->opaque_source_loc, balanced);
        }

        if (balanced->end->opaque_source_loc !=
            TokenImpl::kInvalidSourceLocation) {
          printed_end_loc_to_balanced.emplace(
              balanced->end->opaque_source_loc, balanced);
        }
      } else if (auto statement =
          dynamic_cast<StatementRegion *>(printed_region.get())) {
        if (statement->end->opaque_source_loc !=
            TokenImpl::kInvalidSourceLocation) {
          printed_end_loc_to_statement.emplace(
              statement->end->opaque_source_loc, statement);
        }
      }
    }

    for (const auto &parsed_region : parsed_regions) {
      if (auto balanced = dynamic_cast<BalancedRegion *>(parsed_region.get())) {
        auto [bb_it, bb_end] = printed_begin_loc_to_balanced.equal_range(
            balanced->begin->opaque_source_loc);
        for (; bb_it != bb_end; ++bb_it) {
          (void) matcher.MatchBalanced(balanced, bb_it->second, 2);
        }

        auto [be_it, be_end] = printed_end_loc_to_balanced.equal_range(
            balanced->end->opaque_source_loc);
        for (; be_it != be_end; ++be_it) {
          (void) matcher.MatchBalanced(balanced, be_it->second, 2);
        }
      } else if (auto statement =
          dynamic_cast<StatementRegion *>(parsed_region.get())) {
        auto [se_it, se_end] = printed_end_loc_to_statement.equal_range(
            statement->end->opaque_source_loc);
        for (; se_it != se_end; ++se_it) {
          (void) matcher.MatchStatement(statement, se_it->second, 1);
        }
      }
    }
  };

  join_based_linear_merge();
  join_based_region_merge();
  join_based_linear_merge();

  matcher.MatchRegions(parsed_tree, printed_tree, 0);
  join_based_linear_merge();

//
//
////  std::cerr << "printed_begin_loc_to_balanced.size() = " << printed_begin_loc_to_balanced.size() << '\n';
////  std::cerr << "printed_end_loc_to_balanced.size() = " << printed_end_loc_to_balanced.size() << '\n';
////  std::cerr << "printed_end_loc_to_statement.size() = " << printed_end_loc_to_statement.size() << '\n';
//  matcher.MatchFailed();
//  matcher.MatchFailed();

//  // Perform isolated forward and backward propagation. This is isolated becuase
//  // it looks at pairs of adjacent tokens. The key goal is that we know that
//  // the type printer operates on QualTypes and not TypeLocs, so none of the
//  // tokens nested inside of things like `[` or `(` are marked as such.
//  auto printed_tok = range.first;
//  for (auto tok = first_tok; tok < after_last_tok; ++tok) {
//    auto found = false;
//    auto prev_printed_tok = printed_tok;
//
//    // Does our current token have information?
//    auto tok_missing_info =
//        tok->opaque_source_loc == TokenImpl::kInvalidSourceLocation ||
//        tok->context_index == kInvalidTokenContextIndex;
//
//    // If the next token has no information, then we want to forward-propagate.
//    if (tok[1].opaque_source_loc == TokenImpl::kInvalidSourceLocation ||
//        tok[1].context_index == kInvalidTokenContextIndex) {
//
//      // This isn't great :-/
//      if (tok_missing_info) {
//        continue;
//      }
//
//    // If the next token has information, then we want to backward-propagate.
//    } else {
//
//    }
//
//    // If our parsed token has good source location and has context due to
//    // the above partial matching then we want to try to find a parsed token
//    // with matching location information.
//    if (tok->opaque_source_loc != TokenImpl::kInvalidSourceLocation &&
//        tok->context_index != kInvalidTokenContextIndex) {
//      for (; printed_tok < range.after_last; ++printed_tok) {
//        if (tok->opaque_source_loc == printed_tok->opaque_source_loc &&
//            tok->context_index == printed_tok->context_index) {
//          found = true;
//          break;
//        }
//      }
//
//      // Didn't find one :-/
//      if (!found) {
//        printed_tok = prev_printed_tok;
//
//      // We found one!
//      } else {
//
//      }
//    } else {
//      assert(false);
//    }
//
//  }

#if PASTA_DEBUG_ALIGN

  std::ofstream parsed_os("/tmp/tree.parsed");
  parsed_tree->Print(parsed_os, "", *ast);

  std::ofstream printed_os("/tmp/tree.printed");
  printed_tree->Print(printed_os, "", *(range.impl));
#endif   // PASTA_DEBUG_ALIGN

  return AST(std::move(ast));
}

}  // namespace pasta
