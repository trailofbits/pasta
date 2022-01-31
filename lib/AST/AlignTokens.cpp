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

#define PASTA_DEBUG_ALIGN 0
#define TK(...)

namespace pasta {
namespace {

static bool TokenHasLocationAndContext(TokenImpl *impl) {
  return impl->opaque_source_loc != TokenImpl::kInvalidSourceLocation &&
         impl->context_index != kInvalidTokenContextIndex;
}

static bool TokenLocationsMatch(TokenImpl *parsed, PrintedTokenImpl *printed) {
  return (parsed->opaque_source_loc == printed->opaque_source_loc) &&
          parsed->opaque_source_loc != TokenImpl::kInvalidSourceLocation;
}

enum class RegionKind {
  kStatement,
  kSequence,
  kBalanced
};

struct Region {
 public:
  // If we match this region with another, then we commit to that match and
  // record it here. If this is a parsed region, then this points at a printed
  // region. If it's a printed region, then this points at a parsed region.
  Region *matched_with{nullptr};

  virtual ~Region(void) = default;
  virtual RegionKind Kind(void) const noexcept = 0;

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const = 0;
  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const = 0;
#endif  // PASTA_DEBUG_ALIGN

  // Return the first token that has location and context information.
  virtual TokenImpl *FirstParsedToken(void) const = 0;
  virtual PrintedTokenImpl *FirstPrintedToken(void) const = 0;
};

struct StatementRegion final : public Region {
  RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

  TokenImpl *FirstParsedToken(void) const final {
    if (TokenHasLocationAndContext(end)) {
      if (end->kind == clang::tok::semi ||
          end->kind == clang::tok::comma ||
          end->kind == clang::tok::colon) {
        return end;
      }
    }
    for (auto it = begin; it <= end; ++it) {
      if (TokenHasLocationAndContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

  PrintedTokenImpl *FirstPrintedToken(void) const final {
    if (TokenHasLocationAndContext(end)) {
      if (end->kind == clang::tok::semi ||
          end->kind == clang::tok::comma ||
          end->kind == clang::tok::colon) {
        return reinterpret_cast<PrintedTokenImpl *>(end);
      }
    }
    for (auto it = reinterpret_cast<PrintedTokenImpl *>(begin),
              it_end = reinterpret_cast<PrintedTokenImpl *>(end);
         it <= it_end; ++it) {
      if (TokenHasLocationAndContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
                     const ASTImpl &ast) const final {
    os << indent << "------ST " << reinterpret_cast<const void *>(matched_with) << "------\n";
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

  void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &range) const final {
    os << indent << "------ST " << reinterpret_cast<const void *>(this) << "------\n";
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
  RegionKind Kind(void) const noexcept final {
    return RegionKind::kSequence;
  }

  TokenImpl *FirstParsedToken(void) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      if (auto tok = (*it)->FirstParsedToken()) {
        return tok;
      }
    }
    return nullptr;
  }

  PrintedTokenImpl *FirstPrintedToken(void) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      if (auto tok = (*it)->FirstPrintedToken()) {
        return tok;
      }
    }
    return nullptr;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const ASTImpl &ast) const final {
    os << indent << "------SE " << reinterpret_cast<const void *>(matched_with) << "------\n";
    indent += "  ";
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent, ast);
    }
  }

  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &range) const final {
    os << indent << "------SE " << reinterpret_cast<const void *>(this) << "------\n";
    indent += "  ";
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent, range);
    }
  }
#endif  // PASTA_DEBUG_ALIGN

  // NOTE(pag): These are in reverse order.
  std::vector<Region *> regions;
};

struct BalancedRegion final : public Region {

  StatementRegion *predecessor{nullptr};
  TokenImpl *begin{nullptr};
  SequenceRegion *statements{nullptr};
  TokenImpl *end{nullptr};

  RegionKind Kind(void) const noexcept final {
    return RegionKind::kBalanced;
  }

  TokenImpl *FirstParsedToken(void) const final {
    if (TokenHasLocationAndContext(begin)) {
      return begin;
    }
    if (TokenHasLocationAndContext(end)) {
      return end;
    }
    if (statements) {
      return statements->FirstParsedToken();
    }
    return nullptr;
  }

  PrintedTokenImpl *FirstPrintedToken(void) const final {
    if (TokenHasLocationAndContext(begin)) {
      return reinterpret_cast<PrintedTokenImpl *>(begin);
    }
    if (TokenHasLocationAndContext(end)) {
      return reinterpret_cast<PrintedTokenImpl *>(end);
    }
    if (statements) {
      return statements->FirstPrintedToken();
    }
    return nullptr;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const ASTImpl &ast) const final {
    os << indent << "------BA " << reinterpret_cast<const void *>(matched_with) << "------\n";
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

  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &range) const final {
    os << indent << "------BA " << reinterpret_cast<const void *>(this) << "------\n";
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

static bool MergeToken(TokenImpl *parsed, PrintedTokenImpl *printed,
                       bool &changed, bool force=false) {

  if (parsed->context_index != printed->context_index) {
    if (force) {
      parsed->context_index = printed->context_index;
      printed->opaque_source_loc = parsed->opaque_source_loc;
      changed = true;
      return true;

    } else if (parsed->context_index == kInvalidTokenContextIndex) {
      parsed->context_index = printed->context_index;
      assert(parsed->context_index != kInvalidTokenContextIndex);
      printed->opaque_source_loc = parsed->opaque_source_loc;
      changed = true;
      return true;

    } else {
      return false;
    }
  } else {
    return false;
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
                     bool &changed);
  bool MatchProduct(std::vector<Region *> &parsed_regions,
                    std::vector<Region *> &printed_regions,
                    bool &changed);
  bool MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                     bool &changed);
  bool MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                      bool &changed);
  bool MatchRegions(Region *parsed, Region *printed,
                    bool &changed);

  bool MergeForward(TokenImpl *parsed, PrintedTokenImpl *printed, bool &changed);
  bool MergeBackward(TokenImpl *parsed, PrintedTokenImpl *printed, bool &changed);

  void FixContexts(Region *parsed, std::vector<TokenContextIndex> &stack);
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

static const std::hash<std::string_view> kHasher;

// Strip off leading and trailing underscores, then hash. This is to deal with
// things like `asm` vs. `__asm`.
static std::string_view HashableData(std::string_view view) {
  while (!view.empty() && view.front() == '_') {
    view = view.substr(1u, view.size() - 1u);
  }

  while (!view.empty() && view.back() == '_') {
    view = view.substr(0, view.size() - 1u);
  }

  return view;
}

// Strip off leading and trailing underscores, then hash. This is to deal with
// things like `asm` vs. `__asm`.
static uint64_t Hash(TokenKindBase kind,  std::string_view view) {
  if (clang::tok::isLiteral(static_cast<clang::tok::TokenKind>(kind))) {
    return static_cast<uint64_t>(kind);
  } else {
    return kHasher(HashableData(view));
  }
}

bool Matcher::DataEquals(TokenImpl *parsed, PrintedTokenImpl *printed) {
  auto parsed_data = parsed->Data(ast);
  auto printed_data = printed->Data(range);
  if (clang::tok::getKeywordSpelling(
      static_cast<clang::tok::TokenKind>(parsed->kind))) {
    return HashableData(parsed_data) == HashableData(printed_data);
  } else {
    return parsed_data == printed_data;
  }
}

bool Matcher::MergeForward(TokenImpl *parsed, PrintedTokenImpl *printed,
                           bool &changed) {
  auto merged = false;

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

    if (!MergeToken(parsed, printed, changed) && merged) {
      break;
    } else {
      merged = true;
      ++parsed;
      ++printed;
    }
  }

  return merged;
}

bool Matcher::MergeBackward(TokenImpl *parsed, PrintedTokenImpl *printed,
                            bool &changed) {

  auto merged = false;
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

    if (!MergeToken(parsed, printed, changed) && merged) {
      break;

    } else {
      merged = true;
      --parsed;
      --printed;
    }
  }

  return merged;
}

bool Matcher::MatchToken(TokenImpl *parsed, PrintedTokenImpl *printed) {
  if (TokenLocationsMatch(parsed, printed)) {
    return true;

  } else {
    return MatchTokenByKindOrData(parsed, printed);
  }
}

bool Matcher::MatchTokenByKindOrData(TokenImpl *parsed,
                                     PrintedTokenImpl *printed) {
  if (clang::tok::isLiteral(static_cast<clang::tok::TokenKind>(parsed->kind))) {
    return parsed->kind == printed->kind;

  } else if (parsed->kind == printed->kind) {
    return true;

  } else {
    return DataEquals(parsed, printed);
  }
}

bool Matcher::MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                            bool &changed) {
  if (parsed->matched_with && parsed->matched_with != printed) {
    return false;
  } else if (parsed->begin->kind != printed->begin->kind) {
    return false;
  }

  assert(parsed->begin->kind == printed->begin->kind);
  assert(parsed->end->kind == printed->end->kind);

  auto printed_begin = reinterpret_cast<PrintedTokenImpl *>(printed->begin);
  auto begin_loc_matches = TokenLocationsMatch(parsed->begin, printed_begin);
  if (TokenHasLocationAndContext(printed_begin) && !begin_loc_matches) {
    return false;
  }

  auto printed_end = reinterpret_cast<PrintedTokenImpl *>(printed->end);
  auto end_loc_matches = TokenLocationsMatch(parsed->end, printed_end);
  if (TokenHasLocationAndContext(printed_end) && !end_loc_matches) {
    return false;
  }

  // Look just before and just after the opening and/or closing tokens to
  // see if we can match on those.
  if (!begin_loc_matches && !end_loc_matches) {
    const auto first_parsed_tok = &(ast.tokens.front());
    const auto first_printed_tok = &(range.tokens.front());

    // Look one before.
    if (parsed->begin > first_parsed_tok &&
        printed_begin > first_printed_tok) {
      auto before_parsed = &(parsed->begin[-1]);
      auto before_printed = &(printed_begin[-1]);
      if (TokenLocationsMatch(before_parsed, before_printed)) {
        begin_loc_matches = true;
      }
    }

    // Look one beyond.
    const auto last_parsed_tok = &(ast.tokens.back());
    const auto last_printed_tok = &(range.tokens.back());
    if (parsed->end < last_parsed_tok &&
        printed_end < last_printed_tok) {
      auto after_parsed = &(parsed->end[1]);
      auto after_printed = &(printed_end[1]);
      if (TokenLocationsMatch(after_parsed, after_printed)) {
        end_loc_matches = true;
      }
    }
  }

  auto did_recurse = false;
  if (!begin_loc_matches && !end_loc_matches) {
    if (parsed->predecessor && printed->predecessor &&
        parsed->predecessor->matched_with == printed->predecessor) {

      if (parsed->statements && printed->statements &&
          MatchSequence(parsed->statements, printed->statements, changed)) {
        did_recurse = true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  // Commit to this match.
  parsed->matched_with = printed;
  printed->matched_with = parsed;

  MergeToken(parsed->begin, printed_begin, changed, true);
  MergeToken(parsed->end, printed_end, changed, true);

  // If we pivoted from a match on the ending to injecting a match on the
  // beginning, then apply linear matching around the beginning of the range.
  MergeForward(parsed->begin, printed_begin, changed);
  MergeBackward(parsed->begin, printed_begin, changed);

  // If we pivoted from a match on the beginning to injecting a match on the
  // ending, then apply linear matching around the ending of the range.
  MergeForward(parsed->end, printed_end, changed);
  MergeBackward(parsed->end, printed_end, changed);

  // If we have statements, then commit to them too.
  if (!did_recurse && parsed->statements && printed->statements) {

    if (parsed->statements->matched_with != printed->statements) {
      changed = true;
      parsed->statements->matched_with = printed->statements;
      printed->statements->matched_with = parsed->statements;
    }

    (void) MatchSequence(parsed->statements, printed->statements, changed);
  }

  return parsed->matched_with == printed;
}

template <typename T>
static std::vector<Region *> FilterRegionsInto(
    const std::vector<Region *> &regions) {
  std::vector<Region *> filtered;
  for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
    if (auto f = dynamic_cast<T *>(*it)) {
      filtered.push_back(f);
    }
  }
  return filtered;
}

bool Matcher::MatchProduct(std::vector<Region *> &parsed_regions,
                           std::vector<Region *> &printed_regions,
                           bool &changed) {
  bool matched = false;
  for (Region *&parsed_sub : parsed_regions) {
    for (Region *&printed_sub : printed_regions) {
      if (printed_sub && MatchRegions(parsed_sub, printed_sub, changed)) {
        if (parsed_sub->matched_with != printed_sub) {
          changed = true;
          parsed_sub->matched_with = printed_sub;
          printed_sub->matched_with = parsed_sub;
        }

        parsed_sub = nullptr;
        printed_sub = nullptr;
        matched = true;
        break;
      }
    }
  }
  return matched;
}

// NOTE(pag): The elements in a sequence are already in reverse order.
bool Matcher::MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                            bool &changed) {
  if (parsed->regions.empty() != printed->regions.empty()) {
    return false;  // One is empty, the other isn't.

  } else if (parsed->regions.empty()) {
    return true;  // Both are empty.
  }

  if (parsed->matched_with && parsed->matched_with != printed) {
    return false;
  }

  auto matched = false;

  {
    auto parsed_regions = FilterRegionsInto<StatementRegion>(parsed->regions);
    auto printed_regions = FilterRegionsInto<StatementRegion>(printed->regions);
    if (MatchProduct(parsed_regions, printed_regions, changed)) {
      matched = true;
    }
  }
  {
    auto parsed_regions = FilterRegionsInto<SequenceRegion>(parsed->regions);
    auto printed_regions = FilterRegionsInto<SequenceRegion>(printed->regions);
    if (MatchProduct(parsed_regions, printed_regions, changed)) {
      matched = true;
    }
  }
  {
    auto parsed_regions = FilterRegionsInto<BalancedRegion>(parsed->regions);
    auto printed_regions = FilterRegionsInto<BalancedRegion>(printed->regions);
    if (MatchProduct(parsed_regions, printed_regions, changed)) {
      matched = true;
    }
  }

  if (matched) {
    if (parsed->matched_with != printed) {
      changed = true;
      parsed->matched_with = printed;
      printed->matched_with = parsed;
    }
  }

  // Allow ourselves to locally fail on this run, but benefit from a prior
  // matching.
  return parsed->matched_with == printed;
}

bool Matcher::MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                             bool &changed) {

  if (parsed->matched_with && parsed->matched_with != printed) {
    return false;
  }

  const auto parsed_begin = parsed->begin;
  auto parsed_end = parsed->end;

  const auto printed_begin =
      reinterpret_cast<PrintedTokenImpl *>(printed->begin);
  auto printed_end = reinterpret_cast<PrintedTokenImpl *>(printed->end);

  std::unordered_map<uint64_t, std::vector<TokenImpl *>> parsed_toks;
  std::unordered_map<uint64_t, std::vector<PrintedTokenImpl *>> printed_toks;

  for (auto it = parsed_begin; it <= parsed_end; ++it) {
    if (it->kind != clang::tok::unknown && it->kind != clang::tok::comment) {
      parsed_toks[Hash(it->kind, it->Data(ast))].emplace_back(it);
    }
  }

  for (auto it = printed_begin; it <= printed_end; ++it) {
    printed_toks[Hash(it->kind, it->Data(range))].emplace_back(it);
  }

  auto matched = false;
  for (auto &[hash, parsed_tok_group] : parsed_toks) {
    auto printed_toks_it = printed_toks.find(hash);
    if (printed_toks_it == printed_toks.end()) {
      continue;
    }

    for (TokenImpl *&parsed_tok : parsed_tok_group) {
      for (PrintedTokenImpl *&printed_tok : printed_toks_it->second) {
        if (!printed_tok) {
          continue;

        } else if (TokenLocationsMatch(parsed_tok, printed_tok)) {
          matched = true;
          break;

        } else if (!TokenHasLocationAndContext(printed_tok) &&
                   MatchTokenByKindOrData(parsed_tok, printed_tok)) {
          MergeForward(parsed_tok, printed_tok, changed);
          MergeBackward(parsed_tok, printed_tok, changed);
          matched = true;
          printed_tok = nullptr;
          break;
        }
      }
    }
  }

  if (matched) {
    if (parsed->matched_with != printed) {
      changed = true;
      parsed->matched_with = printed;
      printed->matched_with = parsed;
    }
  }

  // Allow ourselves to locally fail on this run, but benefit from a prior
  // matching.
  return parsed->matched_with == printed;
}

bool Matcher::MatchRegions(Region *parsed, Region *printed,
                           bool &changed) {
  if (!parsed != !printed) {
    return false;
  }

  if (parsed->matched_with && parsed->matched_with != printed) {
    return false;
  }

  const auto kind = parsed->Kind();
  if (kind != printed->Kind()) {
    return false;
  }
  switch (kind) {
    case RegionKind::kBalanced:
      return MatchBalanced(dynamic_cast<BalancedRegion *>(parsed),
                           dynamic_cast<BalancedRegion *>(printed), changed);
    case RegionKind::kSequence:
      return MatchSequence(dynamic_cast<SequenceRegion *>(parsed),
                           dynamic_cast<SequenceRegion *>(printed), changed);
    case RegionKind::kStatement:
      return MatchStatement(dynamic_cast<StatementRegion *>(parsed),
                            dynamic_cast<StatementRegion *>(printed), changed);
  }
  return false;
}

// Make sure that every parsed token is assign *some* kind of context. We try
// to benefit from existing matches and common ancestors to apply contexts.
void Matcher::FixContexts(
    Region *parsed, std::vector<TokenContextIndex> &stack) {

  TokenContextIndex prev_context = stack.back();

  if (auto bal = dynamic_cast<BalancedRegion *>(parsed)) {
    assert(!stack.empty());

    // Happens when we match the `)` of an `__attribute__` against the `)`
    // of the parameter list of the function to which the attribute applies.
    if (TokenHasLocationAndContext(bal->begin) !=
        TokenHasLocationAndContext(bal->end)) {
      bal->begin->context_index = kInvalidTokenContextIndex;
      bal->end->context_index = kInvalidTokenContextIndex;
    }

    // Take the parent context.
    if (!TokenHasLocationAndContext(bal->begin)) {
      assert(!TokenHasLocationAndContext(bal->end));
      bal->begin->context_index = prev_context;
      bal->end->context_index = prev_context;
      stack.push_back(prev_context);

    // Get the context from the balanced tokens.
    } else {
      stack.push_back(bal->begin->context_index);
    }

    // Fix the contexts of any tokens inside of this balanced range.
    if (bal->statements) {
      FixContexts(bal->statements, stack);
    }

  } else if (auto stmt = dynamic_cast<StatementRegion *>(parsed)) {

    // Try to find the common ancestor of everything in this statement.
    const TokenContextImpl *prev = nullptr;
    for (auto tok = stmt->begin; tok <= stmt->end; ++tok) {
      if (TokenHasLocationAndContext(tok)) {
        const TokenContextImpl *curr = &(ast.contexts[tok->context_index]);
        if (!prev) {
          prev = curr;
        } else {
          prev = TokenContextImpl::CommonAncestor(prev, curr, ast.contexts);
        }
      }
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    if (prev) {
      auto index = static_cast<TokenContextIndex>(
          prev - &(ast.contexts.front()));

      if (prev_context != kInvalidTokenContextIndex) {
        auto parent = &(ast.contexts[prev_context]);
        auto ancestor = TokenContextImpl::CommonAncestor(
            prev, parent, ast.contexts);

        if (!ancestor || ancestor->depth < parent->depth) {
          index = prev_context;  // Fixup.
        }
      }

      stack.push_back(index);

    } else {
      stack.push_back(prev_context);
    }

    // Assign the top context on the stack to any token lacking the context.
    for (auto tok = stmt->begin; tok <= stmt->end; ++tok) {
      if (!TokenHasLocationAndContext(tok)) {
        tok->context_index = stack.back();
      }
    }

  } else if (auto seq = dynamic_cast<SequenceRegion *>(parsed)) {

    // Try to find the common ancestor of everything in this sequence.
    const TokenContextImpl *prev = nullptr;
    for (auto region : seq->regions) {
      if (auto tok = region->FirstParsedToken()) {
        assert(TokenHasLocationAndContext(tok));
        const TokenContextImpl *curr = &(ast.contexts[tok->context_index]);
        if (!prev) {
          prev = curr;
        } else {
          prev = TokenContextImpl::CommonAncestor(prev, curr, ast.contexts);
        }
      }
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    if (prev) {
      auto index = static_cast<TokenContextIndex>(
          prev - &(ast.contexts.front()));

      if (prev_context != kInvalidTokenContextIndex) {
        auto parent = &(ast.contexts[prev_context]);
        auto ancestor = TokenContextImpl::CommonAncestor(
            prev, parent, ast.contexts);
        if (!ancestor || ancestor->depth < parent->depth) {
          index = prev_context;  // Fixup.
        }
      }

      stack.push_back(index);

    } else {
      stack.push_back(prev_context);
    }

    // Fix the contexts of any tokens inside of this sequence.
    for (auto region : seq->regions) {
      FixContexts(region, stack);
    }
  }

  stack.pop_back();
}

static bool HasNotBeenMatched(Region *r) {
  return !r->matched_with;
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

  std::unordered_map<unsigned, TokenImpl *> loc_to_toks;
  for (auto tok = first_tok; tok < after_last_tok; ++tok) {
    loc_to_toks.emplace(tok->opaque_source_loc, tok);
  }

  // Join on the shared source locations, and linearly "spread"
  // outward from there. This should generally cover a bunch.
  auto join_based_linear_merge = [&] (bool &changed) {
    for (auto printed = range.first; printed < range.after_last; ++printed) {
      if (printed->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        if (auto parsed = loc_to_toks[printed->opaque_source_loc];
            parsed && !TokenHasLocationAndContext(parsed)) {

          matcher.MergeBackward(parsed, printed, changed);
          matcher.MergeForward(parsed, printed, changed);
        }
      }
    }
  };

  // Assign the predecessor sequences of balanced regions. These can be helpful
  // for matching.
  auto assign_preds = [] (Region *region) {
    if (auto seq = dynamic_cast<SequenceRegion *>(region)) {
      StatementRegion *pred_stmt = nullptr;
      for (auto it = seq->regions.rbegin(), end = seq->regions.rend();
           it != end; ++it) {
        Region *curr = *it;
        if (auto balanced = dynamic_cast<BalancedRegion *>(curr)) {
          balanced->predecessor = pred_stmt;
        }
        pred_stmt = dynamic_cast<StatementRegion *>(curr);
      }
    }
  };

  for (const auto &printed_region : printed_regions) {
    assign_preds(printed_region.get());
  }

  std::vector<BalancedRegion *> parsed_balanced;
  std::vector<StatementRegion *> parsed_statements;

  std::vector<BalancedRegion *> printed_balanced;
  std::vector<StatementRegion *> printed_statements;

  for (const auto &region_ref : parsed_regions) {
    const auto region = region_ref.get();
    if (auto balanced = dynamic_cast<BalancedRegion *>(region)) {
      parsed_balanced.push_back(balanced);
    } else if (auto statement = dynamic_cast<StatementRegion *>(region)) {
      parsed_statements.push_back(statement);
    }
  }

  for (const auto &region_ref : printed_regions) {
    const auto region = region_ref.get();
    if (auto balanced = dynamic_cast<BalancedRegion *>(region)) {
      printed_balanced.push_back(balanced);
    } else if (auto statement = dynamic_cast<StatementRegion *>(region)) {
      printed_statements.push_back(statement);
    }
  }

  std::unordered_multimap<unsigned, BalancedRegion *> printed_loc_to_balanced;
  std::unordered_multimap<unsigned, StatementRegion *> printed_end_loc_to_statement;

  // Join on the shared source locations of balanced and statement regions.
  // This only joins unmatched ones. We generally have decent-ish ability in
  // the token printer (due to clang source locations) to find things like the
  // location of a `}` or a `{`, or a `;`.
  auto join_based_region_merge = [&] (bool &changed) {
    printed_loc_to_balanced.clear();
    printed_end_loc_to_statement.clear();

    {
      auto it = std::partition(parsed_balanced.begin(), parsed_balanced.end(),
                               HasNotBeenMatched);
      parsed_balanced.erase(it, parsed_balanced.end());
    }
    {
      auto it = std::partition(printed_balanced.begin(), printed_balanced.end(),
                               HasNotBeenMatched);
      printed_balanced.erase(it, printed_balanced.end());
    }
    {
      auto it = std::partition(parsed_statements.begin(),
                               parsed_statements.end(), HasNotBeenMatched);
      parsed_statements.erase(it, parsed_statements.end());
    }
    {
      auto it = std::partition(printed_statements.begin(),
                               printed_statements.end(), HasNotBeenMatched);
      printed_statements.erase(it, printed_statements.end());
    }

#if PASTA_DEBUG_ALIGN
    std::cerr
        << "parsed_balanced="<<parsed_balanced.size()
        << " printed_balanced="<<printed_balanced.size()
        << " parsed_statements="<<parsed_statements.size()
        << " printed_statements="<<printed_statements.size()
        <<'\n';
#endif

    for (auto region : parsed_balanced) {
      auto loc = region->begin->opaque_source_loc;
      assert(loc != TokenImpl::kInvalidSourceLocation);
      printed_loc_to_balanced.emplace(loc, region);

      loc = region->end->opaque_source_loc;
      assert(loc != TokenImpl::kInvalidSourceLocation);
      printed_loc_to_balanced.emplace(loc, region);
    }

    for (auto region : printed_balanced) {
      if (const auto begin_loc = region->begin->opaque_source_loc;
          begin_loc != TokenImpl::kInvalidSourceLocation) {

        auto [bb_it, bb_end] = printed_loc_to_balanced.equal_range(begin_loc);
        for (; bb_it != bb_end; ++bb_it) {
          matcher.MatchBalanced(bb_it->second, region, changed);
        }
      }

      if (const auto end_loc = region->end->opaque_source_loc;
          end_loc != TokenImpl::kInvalidSourceLocation) {

        auto [bb_it, bb_end] = printed_loc_to_balanced.equal_range(end_loc);
        for (; bb_it != bb_end; ++bb_it) {
          matcher.MatchBalanced(bb_it->second, region, changed);
        }
      }
    }

    for (auto region : parsed_statements) {
      auto loc = region->end->opaque_source_loc;
      assert(loc != TokenImpl::kInvalidSourceLocation);
      printed_end_loc_to_statement.emplace(loc, region);
    }

    for (auto region : printed_statements) {
      if (const auto end_loc = region->end->opaque_source_loc;
          end_loc != TokenImpl::kInvalidSourceLocation) {

        auto [bb_it, bb_end] =
            printed_end_loc_to_statement.equal_range(end_loc);
        for (; bb_it != bb_end; ++bb_it) {
          matcher.MatchStatement(bb_it->second, region, changed);
        }
      }
    }
  };

  parsed_tree->matched_with = printed_tree;
  printed_tree->matched_with = parsed_tree;

  ast->contexts = std::move(range.impl->contexts);

  auto max_iters = (parsed_regions.size() / 2) + 1u;
  bool changed = true;

  join_based_region_merge(changed);
  join_based_linear_merge(changed);

  for (changed = true; changed; ) {
    changed = false;
    matcher.MatchRegions(parsed_tree, printed_tree, changed);
  }

  for (size_t i = 0u; i < max_iters; ++i) {
    changed = false;
    join_based_region_merge(changed);
    if (!changed) {
      break;
    }
  }


  std::vector<TokenContextIndex> context_stack;
  context_stack.push_back(kInvalidTokenContextIndex);
  matcher.FixContexts(parsed_tree, context_stack);

  ast->RefineTokens();

#if PASTA_DEBUG_ALIGN

  std::ofstream parsed_os("/tmp/tree.parsed");
  parsed_tree->Print(parsed_os, "", *ast);

  std::ofstream printed_os("/tmp/tree.printed");
  printed_tree->Print(printed_os, "", *(range.impl));
#endif   // PASTA_DEBUG_ALIGN

//  for (const auto &parsed_region : parsed_regions) {
//    auto balanced = dynamic_cast<BalancedRegion *>(parsed_region.get());
//    if (!balanced) {
//      continue;
//    }
//
//  }

  // This is pretty sketchy, but place a raw reference back to the AST at the
  // end of the contexts list. Because `ASTImpl` extends
  // `std::enable_shared_from_this`, and because references to this vector in
  // token contexts alias the lifetime of the `ASTImpl`, we can safely go and
  // find the AST given any token context.
  ast->contexts.emplace_back(*ast);

  return AST(std::move(ast));
}

}  // namespace pasta
