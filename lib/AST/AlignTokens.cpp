/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "AST.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include <fstream>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <optional>
#include <span>
#include <sstream>
#include <set>

#include "Builder.h"
#include "Printer/Printer.h"
#include "Printer/DeclStmtPrinter.h"
#include "Token.h"
#include "Util.h"

#define PASTA_DEBUG_ALIGN 0
#define TK(...)

namespace pasta {
namespace {

static bool TokenHasLocationAndContext(const PrintedTokenImpl *impl) {
  return impl->derived_index != kInvalidDerivedTokenIndex &&
         impl->context_index != kInvalidTokenContextIndex;
}

static bool TokenLocationsMatch(const PrintedTokenImpl *parsed,
                                const PrintedTokenImpl *printed) {
  if (parsed->derived_index == kInvalidDerivedTokenIndex) {
    return false;
  }

  if (printed->derived_index == kInvalidDerivedTokenIndex) {
    return false;
  }

  return parsed->derived_index == printed->derived_index;
}

static const TokenContextImpl *ContextFromToken(
    const PrintedTokenRangeImpl &range, PrintedTokenImpl *tok) {
  if (!tok) {
    return nullptr;
  }

  if (!TokenHasLocationAndContext(tok)) {
    return nullptr;
  }

  if (tok->context_index >= range.contexts.size()) {
    assert(false);
    return nullptr;
  }

  return &(range.contexts[tok->context_index]);
}

static TokenContextIndex IndexOfContext(
    const PrintedTokenRangeImpl &range, const TokenContextImpl *context) {
  auto index = static_cast<TokenContextIndex>(
      context - range.contexts.data());
  assert(index < range.contexts.size());
  return index;
}

static const TokenContextImpl *CommonContext(const PrintedTokenRangeImpl &range,
                                             const TokenContextImpl *parent,
                                             const TokenContextImpl *prev,
                                             const PrintedTokenImpl *tok) {
  if (!TokenHasLocationAndContext(tok)) {
    return prev;
  }

  if (tok->context_index >= range.contexts.size()) {
    return prev;
  }

  const TokenContextImpl *curr = &(range.contexts[tok->context_index]);
  if (!prev) {  
    if (parent && curr->depth < parent->depth) {
      return nullptr;
    }

    return curr;
  }

  auto ancestor = TokenContextImpl::CommonAncestor(prev, curr, range.contexts);
  if (parent && ancestor && ancestor->depth < parent->depth) {
    return parent;
  }

  return ancestor;
}

static bool MergeToken(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                       bool &changed, bool force=false) {

  if (parsed->context_index == kInvalidTokenContextIndex) {
    parsed->context_index = printed->context_index;
    changed = true;
    force = true;
  }

  if (printed->derived_index == kInvalidDerivedTokenIndex &&
      parsed->derived_index != kInvalidDerivedTokenIndex) {
    printed->derived_index = parsed->derived_index;
    changed = true;
    force = true;
  }

  auto locs_match = TokenLocationsMatch(parsed, printed);
  if (locs_match) {
    force = true;
  }

  if (force && parsed->context_index != printed->context_index) {
    parsed->context_index = printed->context_index;
    changed = true;
  }

  if (force && !printed->matched_in_align) {
    printed->matched_in_align = true;
    changed = true;
  }

  if (force && !parsed->matched_in_align) {
    parsed->matched_in_align = true;
    changed = true;
  }

  return locs_match;
}

enum class RegionKind {
  kStatement,
  kSequence,
  kBalanced
};

struct Region {
 public:
  // Some context that is shared across all things in this region.
  const TokenContextImpl *common_context{nullptr};

  // Keep track of whether or not this region has ever been matched.
  bool has_been_matched{false};

  virtual ~Region(void) = default;
  virtual RegionKind Kind(void) const noexcept = 0;

#if PASTA_DEBUG_ALIGN
  virtual void Print(std::ostream &os, std::string indent,
                     const PrintedTokenRangeImpl &data_range,
                     const PrintedTokenRangeImpl &context_range) const = 0;
#endif  // PASTA_DEBUG_ALIGN

  // Return the first token that has location and context information.
  virtual PrintedTokenImpl *FirstParsedToken(void) const = 0;
  virtual PrintedTokenImpl *LastParsedToken(void) const = 0;
  virtual const TokenContextImpl *CommonContext(
      const PrintedTokenRangeImpl &range,
      const TokenContextImpl *parent_context) = 0;

  static void MarkAsMatched(Region *parsed, Region *printed, bool &changed) {
    if (!parsed->has_been_matched) {
      parsed->has_been_matched = true;
      changed = true;
    }

    if (!printed->has_been_matched) {
      printed->has_been_matched = true;
      changed = true;
    }

    if (!parsed->common_context) {
      parsed->common_context = printed->common_context;
      changed = true;
    }
  }
};

struct StatementRegion final : public Region {

  PrintedTokenImpl *begin{nullptr};
  PrintedTokenImpl *end{nullptr};  // Inclusive.

  RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

  PrintedTokenImpl *FirstParsedToken(void) const final {
    for (auto it = begin; it <= end; ++it) {
      if (TokenHasLocationAndContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

  PrintedTokenImpl *LastParsedToken(void) const final {
    for (auto it = end; it >= begin; --it) {
      if (TokenHasLocationAndContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

  // Try to find the common ancestor of everything in this statement.
  const TokenContextImpl *CommonContext(
      const PrintedTokenRangeImpl &range,
      const TokenContextImpl *parent_context) final {

    if (common_context) {
      return common_context;
    }

    for (auto tok = begin; tok <= end; ++tok) {
      common_context = ::pasta::CommonContext(
          range, parent_context, common_context, tok);
    }

    if (!common_context) {
      common_context = parent_context;
    }

    return common_context;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {
    os << indent << "------ST "
       << std::hex
       << (common_context ? IndexOfContext(context_range, common_context) : kInvalidTokenContextIndex)
       << std::dec << "------\n";

    for (PrintedTokenImpl *it = begin; it <= end; ++it) {
      if (it->kind == clang::tok::string_literal ||
          it->kind == clang::tok::wide_string_literal) {
        os << indent << "<str>";
      } else {
        os << indent << it->Data(data_range);
      }
      TK( os << " " << clang::tok::getTokenName(it->kind); )
      if (it->derived_index != kInvalidDerivedTokenIndex) {
        os << " d:" << std::hex << it->derived_index << std::dec;
      }
      if (it->context_index != kInvalidTokenContextIndex) {
        os << " c:" << std::hex << it->context_index << std::dec;

        const TokenContextImpl &context = context_range.contexts[it->context_index];
        if (context.kind == TokenContextKind::kDecl) {
          os << ' ' << reinterpret_cast<const clang::Decl *>(context.data)->getDeclKindName();

        } else if (context.kind == TokenContextKind::kStmt) {
          os << ' ' << reinterpret_cast<const clang::Stmt *>(context.data)->getStmtClassName();

        } else if (context.kind == TokenContextKind::kType) {
          os << ' ' << reinterpret_cast<const clang::Type *>(context.data)->getTypeClassName();
        }
      }
      os << '\n';
    }
  }
#endif  // PASTA_DEBUG_ALIGN
};

struct SequenceRegion final : public Region {
  // NOTE(pag): These are in reverse order.
  std::vector<Region *> regions;

  RegionKind Kind(void) const noexcept final {
    return RegionKind::kSequence;
  }

  PrintedTokenImpl *FirstParsedToken(void) const final {
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      Region *region = *it;
      if (PrintedTokenImpl *tok = region->FirstParsedToken()) {
        return tok;
      }
    }
    return nullptr;
  }

  PrintedTokenImpl *LastParsedToken(void) const final {
    for (Region *region : regions) {
      if (PrintedTokenImpl *tok = region->LastParsedToken()) {
        return tok;
      }
    }
    return nullptr;
  }

  const TokenContextImpl *CommonContext(
      const PrintedTokenRangeImpl &range,
      const TokenContextImpl *parent_context) final {

    if (common_context) {
      return common_context;
    }

    // Try to find the common ancestor of everything in this statement.
    for (Region *region : regions) {
      auto curr = region->CommonContext(range, parent_context);
      if (!curr || curr->depth < parent_context->depth) {
        continue;
      }

      if (!common_context) {
        common_context = curr;
        continue;
      }

      auto ancestor = TokenContextImpl::CommonAncestor(
          common_context, curr, range.contexts);
      if (ancestor->depth < parent_context->depth) {
        continue;
      }

      common_context = ancestor;
    }

    if (!common_context) {
      common_context = parent_context;
    }

    return common_context;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {

    os << indent << "------SE "
       << std::hex
       << (common_context ? IndexOfContext(context_range, common_context) : kInvalidTokenContextIndex)
       << std::dec << "------\n";
  indent += "  ";
    for (auto it = regions.rbegin(), end = regions.rend(); it != end; ++it) {
      (*it)->Print(os, indent, data_range, context_range);
    }
  }
#endif  // PASTA_DEBUG_ALIGN
};

struct BalancedRegion final : public Region {

  StatementRegion *predecessor{nullptr};
  PrintedTokenImpl *leading_ident{nullptr};
  PrintedTokenImpl *begin{nullptr};
  SequenceRegion *statements{nullptr};
  PrintedTokenImpl *end{nullptr};

  RegionKind Kind(void) const noexcept final {
    return RegionKind::kBalanced;
  }

  PrintedTokenImpl *FirstParsedToken(void) const final {
    if (TokenHasLocationAndContext(begin)) {
      return begin;
    }
    if (statements) {
      return statements->FirstParsedToken();
    }
    if (TokenHasLocationAndContext(end)) {
      return end;
    }
    return nullptr;
  }

  PrintedTokenImpl *LastParsedToken(void) const final {
    if (TokenHasLocationAndContext(end)) {
      return end;
    }
    if (statements) {
      return statements->LastParsedToken();
    }
    if (TokenHasLocationAndContext(begin)) {
      return begin;
    }
    return nullptr;
  }

  const TokenContextImpl *CommonContext(
      const PrintedTokenRangeImpl &range,
      const TokenContextImpl *parent_context) final {

    if (common_context) {
      return common_context;
    }

    // Get it from the leading identifier.
    common_context = ContextFromToken(range, leading_ident);

    // Get it from the brackets/braces/parens.
    if (!common_context && begin && end) {
      auto begin_ctx = ContextFromToken(range, begin);
      auto end_ctx = ContextFromToken(range, end);

      if (begin_ctx && end_ctx) {
        common_context = TokenContextImpl::CommonAncestor(
            begin_ctx, end_ctx, range.contexts);
      
      } else if (begin_ctx && !end_ctx) {
        common_context = begin_ctx;

      } else if (!begin_ctx && end_ctx) {
        common_context = end_ctx;
      }
    }

    if (!common_context) {
      common_context = parent_context;
    }

    if (common_context->depth < parent_context->depth) {
      common_context = parent_context;
    }

    // Top-down mutational update.
    if (statements) {
      common_context = statements->CommonContext(range, common_context);
    }

    return common_context;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {

    os << indent << "------BA "
       << std::hex
       << (common_context ? IndexOfContext(context_range, common_context) : kInvalidTokenContextIndex)
       << std::dec << "------\n";
    os << indent << begin->Data(data_range) << " " << clang::tok::getTokenName(begin->kind);

    if (begin->derived_index != kInvalidDerivedTokenIndex) {
      os << " d:" << std::hex << begin->derived_index << std::dec;
    }
    if (begin->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << begin->context_index << std::dec;
    }
    os << '\n';
    if (statements) {
      statements->Print(os, indent + "  ", data_range, context_range);
    }
    os << indent << end->Data(data_range) << " " << clang::tok::getTokenName(end->kind);
    if (end->derived_index != kInvalidDerivedTokenIndex) {
      os << " l:" << std::hex << end->derived_index << std::dec;
    }
    if (end->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << end->context_index << std::dec;
    }
    os << '\n';
  }
#endif  // PASTA_DEBUG_ALIGN
};

struct Bounds {
  PrintedTokenImpl * const begin;
  PrintedTokenImpl * const end;  // Exclusive.

  inline explicit Bounds(PrintedTokenRangeImpl &range)
      : begin(range.tokens.data()),
        end(&(begin[range.tokens.size() - 1u])) {}

  inline explicit Bounds(PrintedTokenImpl *begin_, PrintedTokenImpl *end_)
      : begin(begin_),
        end(end_) {}

  inline bool Empty(void) const noexcept {
    return begin == end;
  }

  inline PrintedTokenImpl *Front(void) const noexcept {
    assert(!Empty());
    return begin;
  }

  inline PrintedTokenImpl *Back(void) const noexcept {
    assert(!Empty());
    return &(end[-1]);
  }

  inline bool StrictlyContains(const PrintedTokenImpl *tok) const noexcept {
    return begin < tok && tok < end;
  }

  inline std::span<PrintedTokenImpl> Range(void) const noexcept {
    return std::span<PrintedTokenImpl>(begin, end);
  }
};

class Matcher {
 public:
  ASTImpl &ast;
  PrintedTokenRangeImpl &parsed_range;
  PrintedTokenRangeImpl &printed_range;
  
  const Bounds parsed_bounds;
  const Bounds printed_bounds;

  // Tracks if we've done recursive matching on two regions.
  using MatchKey = std::pair<Region *, Region *>;
  std::set<MatchKey> matched_with;

  std::vector<std::unique_ptr<Region>> parsed_regions;
  std::vector<std::unique_ptr<Region>> printed_regions;

  // Maps parsed locations to parsed tokens.
  std::unordered_map<DerivedTokenIndex, PrintedTokenImpl *> loc_to_toks;

  // Maps identifiers or keywords that precede a balanced region to the
  // token just after the balanced region. This is used to jump over
  // `__attribute__` tokens when doing forward matching.
  std::unordered_map<PrintedTokenImpl *, PrintedTokenImpl *> skip_balanced;

  inline explicit Matcher(ASTImpl &ast_,
                          PrintedTokenRangeImpl &parsed_range_,
                          PrintedTokenRangeImpl &printed_range_)
      : ast(ast_),
        parsed_range(parsed_range_),
        printed_range(printed_range_),
        parsed_bounds(parsed_range),
        printed_bounds(printed_range) {}

  // Organize the tokens into a tree, grouped by brace/bracket/paren-enclosed
  // regions, and comma/semicolon-separated regions.
  SequenceRegion *BuildRegions(
      std::vector<std::unique_ptr<Region>> &regions,
      std::stringstream &err, PrintedTokenImpl *first,
      PrintedTokenImpl *after_last, const char *list_kind);

  bool MatchToken(PrintedTokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchTokenByKindOrData(PrintedTokenImpl *parsed,
                              PrintedTokenImpl *printed);
  bool MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                     bool &changed);
  bool MatchProduct(std::vector<Region *> parsed_regions,
                    std::vector<Region *> printed_regions,
                    bool &changed);
  bool MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                     bool should_match, bool &changed);
  bool MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                      bool &changed);
  bool MatchRegions(Region *parsed, Region *printed,
                    bool &changed);

  bool HashBasedMatch(Bounds parsed, Bounds printed, bool &changed);

  bool MergeAround(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                   bool &changed);

  bool MergeForward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                    bool &changed);
  bool MergeBackward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                     bool &changed);

  void InitParsedLocationsMap(void);
  void JoinOnLocations(void);
  void MergeSameSizedHoles(void);

  void AssignPredecessors(const std::vector<std::unique_ptr<Region>> &regions);

  void FixBalancedRegionContexts(
      BalancedRegion *bal, const TokenContextImpl *parent_context);
  void FixStatementRegionContexts(
      StatementRegion *stmt, const TokenContextImpl *parent_context);
  void FixSequenceRegionContexts(
      SequenceRegion *seq, const TokenContextImpl *parent_context);
  void FixContexts(Region *parsed, const TokenContextImpl *parent_context);
};

// Organize the tokens into a tree, grouped by brace/bracket/paren-enclosed
// regions, and comma/semicolon-separated regions.
SequenceRegion *Matcher::BuildRegions(
    std::vector<std::unique_ptr<Region>> &regions, std::stringstream &err,
    PrintedTokenImpl *first, PrintedTokenImpl *after_last,
    const char *list_kind) {

  std::vector<SequenceRegion *> region_stack;
  std::vector<std::pair<clang::tok::TokenKind, PrintedTokenImpl *>> match_stack;
  std::vector<std::tuple<clang::tok::TokenKind, clang::tok::TokenKind,
                         clang::tok::TokenKind>> stmt_stoppers;

  PrintedTokenImpl *unused_end = nullptr;

  auto push_empty_sequence = [&] (void) {
    const auto empty = new SequenceRegion;
    regions.emplace_back(empty);
    region_stack.emplace_back(empty);
    return empty;
  };

  auto add_uncollected_stmt = [&] (PrintedTokenImpl *begin) {
    if (unused_end) {
      auto seq = dynamic_cast<SequenceRegion *>(region_stack.back());
      assert(seq != nullptr);
      auto stmt = new StatementRegion;
      regions.emplace_back(stmt);
      stmt->begin = begin;
      stmt->end = unused_end;
      seq->regions.push_back(stmt);
      unused_end = nullptr;
    }
  };

  push_empty_sequence();
  stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::comma,
                             clang::tok::eof);

  BalancedRegion *last_balanced = nullptr;

  // Traverse backwards through the printed tokens and try to match brackets,
  // braces, and parentheses with what is in the pre-processed code. We go
  // backward because the printed token ranges might start with declarations
  // for builtins, which are not present in the preprocessed code.
  PrintedTokenImpl *prev_it = after_last;
  for (PrintedTokenImpl *it = after_last, *end = first;
       it != end; prev_it = it) {

    PrintedTokenImpl *next_tok_ptr = it;
    --it;

    assert(it < prev_it);
    (void) prev_it;

    PrintedTokenImpl &tok = *it;
    const clang::tok::TokenKind tok_kind = tok.kind;

    // If we just saw a balanced region, and now we're seeing an identifier,
    // then we want to use that identifier as part of our matching criteria.
    if (last_balanced &&
        (clang::tok::isAnyIdentifier(tok_kind) ||
         clang::tok::getKeywordSpelling(tok_kind))) {
      last_balanced->leading_ident = &tok;

      // Make it possible for us to later skip over a balanced region given
      // the leading identifier.
      PrintedTokenImpl *after_balanced = &(last_balanced->end[1u]);
      if (after_balanced < after_last) {
        skip_balanced.emplace(&tok, after_balanced);
      }
    }

    last_balanced = nullptr;

    switch (tok_kind) {

      // We have found the beginning of a nested region, in terms of the ending
      // token of that nested region.
      case clang::tok::r_paren:
        add_uncollected_stmt(next_tok_ptr);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_paren, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi,
                                   clang::tok::comma  /* parameter lists */,
                                   clang::tok::colon  /* for loops */);
        break;
      case clang::tok::r_square:
        add_uncollected_stmt(next_tok_ptr);
        push_empty_sequence();
        match_stack.emplace_back(clang::tok::l_square, &tok);
        stmt_stoppers.emplace_back(clang::tok::semi, clang::tok::semi,
                                   clang::tok::comma  /* comma expressions */);
        break;
      case clang::tok::r_brace:
        add_uncollected_stmt(next_tok_ptr);
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
        add_uncollected_stmt(next_tok_ptr);

        // If this happens, it's likely a bug in `Bounds.cpp`.
        if (match_stack.empty()) {
          err << "Unable to match opening "
              << clang::tok::getTokenName(tok_kind)
              << "; match stack is empty for " << list_kind << " tokens";

          if (tok.derived_index != kInvalidDerivedTokenIndex) {
            err << " (index " << tok.derived_index << ')';
          }
          return nullptr;
        } else {
          auto [opening_kind, r_tok] = match_stack.back();

          match_stack.pop_back();
          stmt_stoppers.pop_back();

          if (opening_kind != tok_kind) {
            err << "Unbalanced "
                << clang::tok::getTokenName(tok_kind)
                << " (starting index " << (it - first)
                << "); expected a "
                << clang::tok::getTokenName(opening_kind)
                << " (ending index " << (r_tok - first)
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
            last_balanced = br;
          }
          break;
        }

      // We've found the end of a statement.
      case clang::tok::semi:
      case clang::tok::comma:
      case clang::tok::colon:
        if (tok_kind == std::get<0>(stmt_stoppers.back()) ||
            tok_kind == std::get<1>(stmt_stoppers.back()) ||
            tok_kind == std::get<2>(stmt_stoppers.back())) {
          add_uncollected_stmt(next_tok_ptr);
          unused_end = &tok;
          break;
        }
        [[clang::fallthrough]];

      default:
        if (!unused_end) {
          unused_end = &tok;
        }
        break;
    }
  }

  // Flush out empty regions. This seems to happen in the following case from
  // the XNU kernel:
  //
  //        _Atomic(struct thread_group *) *
  //        kqr_preadopt_thread_group_addr(workq_threadreq_t req);
  while (1u < region_stack.size()) {
    if (region_stack.back()->regions.empty()) {
      region_stack.pop_back();
    }
  }

  if (region_stack.size() != 1u) {
    err
        << "Region stack for " << list_kind << " tokens has "
        << region_stack.size() << " regions";
    return nullptr;
  }

  add_uncollected_stmt(first);

  return region_stack.back();
}

static const std::hash<std::string_view> kHasher;

// Strip off leading and trailing underscores, then hash. This is to deal with
// things like `asm` vs. `__asm`.
static std::string_view HashableData(std::string_view view) {
  while (!view.empty() && view.front() == '_') {
    view.remove_prefix(1u);
  }

  while (!view.empty() && view.back() == '_') {
    view.remove_suffix(1u);
  }

  return view;
}

// Strip off leading and trailing underscores, then hash. This is to deal with
// things like `asm` vs. `__asm`.
static uint64_t Hash(clang::tok::TokenKind kind, std::string_view view) {
  if (clang::tok::isLiteral(kind) ||
      clang::tok::getPunctuatorSpelling(kind) ||
      clang::tok::getKeywordSpelling(kind)) {
    return static_cast<uint64_t>(kind);
  }
  if (auto new_view = HashableData(view); !new_view.empty()) {
    view = new_view;
  }
  return kHasher(view);
}

static bool IsAttributeLikeKeword(clang::tok::TokenKind tk) {
  switch (tk) {
    case clang::tok::kw___attribute:
    case clang::tok::kw___declspec:
      return true;
    default:
      return false;
  }
}

bool Matcher::MergeAround(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                          bool &changed) {
  auto before = MergeBackward(&(parsed[-1]), &(printed[-1]), changed);
  auto after = MergeForward(&(parsed[1]), &(printed[1]), changed);
  return before || after;
}

bool Matcher::MergeForward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                           bool &changed) {
  auto merged = false;
  auto num_skips = 0u;

  std::vector<PrintedTokenImpl *> backtrack_locs;

  // Compute the next token to analyze. If `tok` appears just before a balanced
  // region, then skip over the balanced region.
  auto next_tok = [this] (PrintedTokenImpl *tok) {
    if (auto skip_it = skip_balanced.find(tok);
        skip_it != skip_balanced.end()) {
      return skip_it->second;
    }
    return &(tok[1]);
  };

  while (num_skips < 16u &&
         parsed_bounds.StrictlyContains(parsed) &&
         printed_bounds.StrictlyContains(printed)) {

    auto skip = false;
    if (!MatchToken(parsed, printed)) {

      // Try to skip over `__attribute__` sections when matching.
      const auto parsed_kind = parsed->kind;
      if (IsAttributeLikeKeword(parsed_kind) ||
          clang::tok::isAnyIdentifier(parsed_kind) ||
          clang::tok::getPunctuatorSpelling(parsed_kind)) {
        parsed = next_tok(parsed);
        skip = true;
      }

      const auto printed_kind = printed->kind;
      if (IsAttributeLikeKeword(printed_kind)) {
        printed = next_tok(printed);
        skip = true;
      }

      if (!skip) {
        break;
      }
    }

    if (skip) {
      ++num_skips;
      continue;
    }

    // We have found something on which we can make progress.
    if (auto local_changed = false;
        MergeToken(parsed, printed, local_changed)) {

      merged = true;

      // A previous step presumably made progress for us.
      if (!local_changed) {
        break;
      }

      changed = true;

      // Spread string literal contexts linearly.
      auto tk = parsed->kind;
      auto is_string_literal = tk == clang::tok::string_literal ||
                               tk == clang::tok::wide_string_literal;

      if (is_string_literal && parsed->context_index != kInvalidTokenContextIndex) {
        for (; parsed_bounds.StrictlyContains(parsed + 1); ++parsed) {
          tk = parsed[1u].kind;
          if (tk != clang::tok::string_literal &&
              tk != clang::tok::wide_string_literal) {
            break;
          }

          if (parsed[1u].context_index != kInvalidTokenContextIndex) {
            break;
          }

          parsed[1u].context_index = parsed->context_index;
        }
      }

      parsed = next_tok(parsed);
      printed = next_tok(printed);

    // We hit a blocker, but we previously made progress.
    } else if (merged) {
      break;

    // Skip these unmergeable tokens.
    } else {
      parsed = next_tok(parsed);
      printed = next_tok(printed);
      ++num_skips;
    }
  }

  return merged;
}

bool Matcher::MergeBackward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                            bool &changed) {
  auto num_skips = 0u;
  auto merged = false;
  const auto first_parsed = parsed_bounds.begin;
  const auto first_printed = printed_bounds.begin;
  while (parsed >= first_parsed && printed >= first_printed &&
         num_skips <= 16u) {
    if (!MatchToken(parsed, printed)) {
      break;
    }

    // We have found something on which we can make progress.
    auto local_changed = false;
    if (!MergeToken(parsed, printed, local_changed)) {
      break;
    }

    merged = true;
    if (local_changed) {
      changed = true;
      --parsed;
      --printed;
    } else {
      break;
    }
  }

  return merged;
}

bool Matcher::MatchToken(PrintedTokenImpl *parsed, PrintedTokenImpl *printed) {
  if (TokenLocationsMatch(parsed, printed)) {
    return true;
  }

  if (MatchTokenByKindOrData(parsed, printed)) {
    return true;
  }

  // If previous matches, and the next matches, then assume this one matches too!
  return parsed_bounds.StrictlyContains(parsed) &&
         printed_bounds.StrictlyContains(printed) &&
         TokenLocationsMatch(&(parsed[-1]), &(printed[-1])) &&
         TokenLocationsMatch(&(parsed[1]), &(printed[1]));
}

bool Matcher::MatchTokenByKindOrData(PrintedTokenImpl *parsed,
                                     PrintedTokenImpl *printed) {
  const auto parsed_kind = parsed->kind;
  if (clang::tok::isLiteral(parsed_kind) ||
      clang::tok::getKeywordSpelling(parsed_kind) ||
      !clang::tok::isAnyIdentifier(parsed_kind)) {
    return parsed_kind == printed->kind;
  }

  return parsed->Data(parsed_range) == printed->Data(printed_range);
}

bool Matcher::MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                            bool &changed) {

  if (parsed->begin->kind != printed->begin->kind) {
    return false;
  }

  if (!parsed->leading_ident != !printed->leading_ident) {
    return false;
  }

  if (parsed->leading_ident &&
      !MatchToken(parsed->leading_ident, printed->leading_ident)) {
    return false;
  }

  assert(parsed->end->kind == printed->end->kind);

  auto printed_begin = printed->begin;
  auto begin_loc_matches = TokenLocationsMatch(parsed->begin, printed_begin);
  auto has_begin_loc = TokenHasLocationAndContext(printed_begin);
  if (has_begin_loc && !begin_loc_matches) {
    return false;
  }

  auto printed_end = printed->end;
  auto end_loc_matches = TokenLocationsMatch(parsed->end, printed_end);
  auto has_end_loc = TokenHasLocationAndContext(printed_end);
  if (has_end_loc && !end_loc_matches) {
    return false;
  }

  // Look just before and just after the opening and/or closing tokens to
  // see if we can match on those.
  if (!begin_loc_matches && !end_loc_matches) {

    // Look one before.
    begin_loc_matches =
        parsed_bounds.StrictlyContains(parsed->begin) &&
        printed_bounds.StrictlyContains(printed->begin) &&
        TokenLocationsMatch(&(parsed->begin[-1]), &(printed_begin[-1]));

    // Look one beyond.
    end_loc_matches =
        parsed_bounds.StrictlyContains(parsed->end) &&
        printed_bounds.StrictlyContains(printed->end) &&
        TokenLocationsMatch(&(parsed->end[1]), &(printed_end[1]));
  }

  // Force match the parens/brackets/braces. Here we're targeting the attribute
  // case, where we might have multiple attributes syntax blocks printed, but
  // only one attribute syntax block in the parsed code.
  if (has_begin_loc && begin_loc_matches && !has_end_loc) {
    MergeToken(parsed->end, printed->end, changed, true  /* force */);
    end_loc_matches = true;

  } else if (has_end_loc && end_loc_matches && !has_begin_loc) {
    MergeToken(parsed->begin, printed->begin, changed, true  /* force */);
    begin_loc_matches = true;
  }

  if (!begin_loc_matches || !end_loc_matches) {
    return false;
  }

  // We've previously matched these before, don't do any recursive processing.
  if (!matched_with.emplace(parsed, printed).second) {
    return true;
  }

  changed = true;  // Made a new match.

  Region::MarkAsMatched(parsed, printed, changed);

  MergeToken(parsed->begin, printed_begin, changed, true);
  MergeAround(parsed->begin, printed_begin, changed);

  MergeToken(parsed->end, printed_end, changed, true);
  MergeAround(parsed->end, printed_end, changed);

  // Attribute printing can end up printing identifiers differently, e.g.
  // `macos` vs. `macosx` in availability attributes, which are problematic
  // for matching, but then have things like the `availability` identifier
  // be easy for matching. We want to make it more likely that we'll match
  // things.
  if (parsed->leading_ident &&
      IsAttributeLikeKeword(parsed->leading_ident->kind)) {
    HashBasedMatch(Bounds(&(parsed->begin[1]), parsed->end),
                   Bounds(&(printed->begin[1]), printed->end),
                   changed);
  }

  // If we have statements, then commit to them too. This will benefit from
  // the above hash-based matching.
  if (parsed->statements && printed->statements) {
    MatchSequence(parsed->statements, printed->statements,
                  true  /* should_match */, changed);
  }

  return true;
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

bool Matcher::MatchProduct(std::vector<Region *> parsed_regions,
                           std::vector<Region *> printed_regions,
                           bool &changed) {
  bool matched = false;
  for (Region *&parsed_sub : parsed_regions) {
    if (!parsed_sub) {
      continue;
    }

    for (Region *&printed_sub : printed_regions) {
      if (!printed_sub) {
        continue;
      }

      if (MatchRegions(parsed_sub, printed_sub, changed)) {
        assert(parsed_sub->common_context != nullptr);
        assert(parsed_sub->has_been_matched);
        assert(printed_sub->has_been_matched);
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
//
// `should_match` communicates a higher-level belief that these two sequences
// should actually match. Usually, this comes from `MatchBalanced`. That is,
// if we've matched the `{` and `}` of a `CompoundStmt`, then we expect the
// statements within to match. Same goes for parameter lists in a
// `FunctionDecl`, for example.
bool Matcher::MatchSequence(SequenceRegion *parsed, SequenceRegion *printed,
                            bool should_match, bool &changed) {

  if (parsed->regions.empty() != printed->regions.empty()) {
    return false;  // One is empty, the other isn't.
  }

  if (parsed->regions.empty()) {
    return true;  // Both are empty.
  }

  if (should_match) {
    if (!matched_with.emplace(parsed, printed).second) {
      return true;
    }
  } else if (matched_with.count(MatchKey(parsed, printed))) {
    return true;
  }

  // First, try to match nested balanced/statement regions. These are much
  // easier to match with one-another.
  auto matched_balanced = MatchProduct(
      FilterRegionsInto<BalancedRegion>(parsed->regions),
      FilterRegionsInto<BalancedRegion>(printed->regions),
      changed);

  auto matched_stmts = MatchProduct(
      FilterRegionsInto<StatementRegion>(parsed->regions),
      FilterRegionsInto<StatementRegion>(printed->regions),
      changed);

  // If we matched balanced or statements, and regardless of if we are trying
  // to force things, then go try to match sequences.
  if (matched_balanced || matched_stmts) {
    MatchProduct(
        FilterRegionsInto<SequenceRegion>(parsed->regions),
        FilterRegionsInto<SequenceRegion>(printed->regions),
        changed);

  // If we failed to match on balanced and statements, but the caller context
  // is telling us that we should match, then go and try to match those too.
  } else if (should_match) {
    MatchProduct(
        FilterRegionsInto<SequenceRegion>(parsed->regions),
        FilterRegionsInto<SequenceRegion>(printed->regions),
        changed);
  
  // The caller didn't give us a strong hint, and we didn't match balanced or
  // statements, so don't go aggressive into sequences.
  } else {
    return false;
  }

  matched_with.emplace(parsed, printed);
  Region::MarkAsMatched(parsed, printed, changed);

  return true;
}

bool Matcher::HashBasedMatch(Bounds parsed, Bounds printed, bool &changed) {

  std::unordered_map<uint64_t, std::vector<PrintedTokenImpl *>> parsed_toks;
  std::unordered_map<uint64_t, std::vector<PrintedTokenImpl *>> printed_toks;

  // Do some join-based hashing, then try to match tokens with the same hash.
  // This can have really bad time complexity when the two statements contain
  // tons of literal/punctuation values, which happens with giant arrays.

  for (PrintedTokenImpl &it : parsed.Range()) {
    if (!it.matched_in_align) {
      parsed_toks[Hash(it.kind, it.Data(parsed_range))].emplace_back(&it);
    }
  }

  for (PrintedTokenImpl &it : printed.Range()) {
    if (!it.matched_in_align) {
      printed_toks[Hash(it.kind, it.Data(printed_range))].emplace_back(&it);
    }
  }

  auto matched = false;
  for (auto &[hash, parsed_tok_group] : parsed_toks) {
    auto printed_toks_it = printed_toks.find(hash);
    if (printed_toks_it == printed_toks.end()) {
      continue;
    }

    std::vector<PrintedTokenImpl *> &matching_printed =
        printed_toks_it->second;
    size_t start = 0u;
    const size_t size = matching_printed.size();

    for (PrintedTokenImpl *&parsed_tok : parsed_tok_group) {
      for (auto i = start; i < size; ++i) {
        PrintedTokenImpl *&printed_tok = matching_printed[i];

        if (!printed_tok) {
          assert(false);
          continue;
        }

        if (MatchToken(parsed_tok, printed_tok)) {
          MergeToken(parsed_tok, printed_tok, changed, true);
          MergeAround(parsed_tok, printed_tok, changed);

          matched = true;
          printed_tok = nullptr;

          // Try to reduce scope of O(n^2) problems.
          if (i > start) {
            assert(matching_printed[start] != nullptr);
            std::swap(printed_tok, matching_printed[start]); 
          }
          ++start;

          break;
        }
      }
    }
  }

  return matched;
}

bool Matcher::MatchStatement(StatementRegion *parsed, StatementRegion *printed,
                             bool &changed) {

  if (parsed->end->kind != printed->end->kind) {
    return false;
  }

  bool force = TokenLocationsMatch(parsed->end, printed->end);
  if (force && !matched_with.emplace(parsed, printed).second) {
    return true;  // Already matched.
  }

  auto matched = HashBasedMatch(
      Bounds(parsed->begin, &(parsed->end[1])),
      Bounds(printed->begin, &(printed->end[1])),
      changed) || force;

  if (!matched) {
    return false;
  }

  Region::MarkAsMatched(parsed, printed, changed);

  // Allow ourselves to locally fail on this run, but benefit from a prior
  // matching.
  return true;
}

bool Matcher::MatchRegions(Region *parsed, Region *printed,
                           bool &changed) {
  if (!parsed != !printed) {
    return false;
  }

  const auto kind = parsed->Kind();
  if (kind != printed->Kind()) {
    return false;
  }

  if (parsed->has_been_matched && printed->has_been_matched &&
      matched_with.count(MatchKey(parsed, printed))) {
    return true;
  }

  if (parsed->common_context && printed->common_context &&
      parsed->common_context != printed->common_context) {
    return false;
  }

  switch (kind) {
    case RegionKind::kBalanced:
      return MatchBalanced(dynamic_cast<BalancedRegion *>(parsed),
                           dynamic_cast<BalancedRegion *>(printed), changed);
    case RegionKind::kSequence:
      return MatchSequence(dynamic_cast<SequenceRegion *>(parsed),
                           dynamic_cast<SequenceRegion *>(printed),
                           false, changed);
    case RegionKind::kStatement:
      return MatchStatement(dynamic_cast<StatementRegion *>(parsed),
                            dynamic_cast<StatementRegion *>(printed), changed);
  }
  return false;
}

void Matcher::FixBalancedRegionContexts(
    BalancedRegion *bal, const TokenContextImpl *parent_context) {

  auto common_context = bal->CommonContext(parsed_range, parent_context);
  auto common_context_index = IndexOfContext(parsed_range, common_context);  

  // Happens when we match the `)` of an `__attribute__` against the `)`
  // of the parameter list of the function to which the attribute applies.
  if (bal->begin->context_index != bal->end->context_index ||
      bal->begin->context_index == kInvalidTokenContextIndex ||
      bal->end->context_index == kInvalidTokenContextIndex) {
    bal->begin->context_index = common_context_index;
    bal->end->context_index = common_context_index;
  }

  // Fix the contexts of any tokens inside of this balanced range.
  if (bal->statements) {
    FixContexts(bal->statements, common_context);
  }
}

void Matcher::FixStatementRegionContexts(
    StatementRegion *stmt, const TokenContextImpl *parent_context) {

  const TokenContextImpl *common_context =
      stmt->CommonContext(parsed_range, parent_context);
  auto common_context_index = IndexOfContext(parsed_range, common_context);  

  // Assign the top context on the stack to any token lacking the context.
  for (auto tok = stmt->begin; tok <= stmt->end; ++tok) {
    if (!TokenHasLocationAndContext(tok)) {
      tok->context_index = common_context_index;
    }
  }
}

void Matcher::FixSequenceRegionContexts(
    SequenceRegion *seq, const TokenContextImpl *parent_context) {

  const TokenContextImpl *common_context =
      seq->CommonContext(parsed_range, parent_context);

  // Fix the contexts of any tokens inside of this sequence.
  for (Region *region : seq->regions) {
    FixContexts(region, common_context);
  }
}

// Make sure that every parsed token is assigned *some* kind of context. We try
// to benefit from existing matches and common ancestors to apply contexts.
void Matcher::FixContexts(
    Region *parsed, const TokenContextImpl *parent_context) {

  if (auto bal = dynamic_cast<BalancedRegion *>(parsed)) {
    FixBalancedRegionContexts(bal, parent_context);

  } else if (auto stmt = dynamic_cast<StatementRegion *>(parsed)) {
    FixStatementRegionContexts(stmt, parent_context);

  } else if (auto seq = dynamic_cast<SequenceRegion *>(parsed)) {
    FixSequenceRegionContexts(seq, parent_context);
  }
}

// Look for `<matched> <unmatched hole...> <matched>` where the two matched
// tokens are separated by a N-token-sized hole.
void Matcher::MergeSameSizedHoles(void) {
  for (PrintedTokenImpl &tok_ref : printed_bounds.Range()) {
    auto tok = &tok_ref;

    if (tok->derived_index == kInvalidDerivedTokenIndex) {
      continue;
    }

    // Find the end of the hole.
    const auto next_tok = &(tok[1]);
    auto end_of_hole = next_tok;
    for (; end_of_hole < printed_bounds.end; ++end_of_hole) {
      if (end_of_hole->derived_index != kInvalidDerivedTokenIndex) {
        break;
      }
    }

    // There is no hole.
    if (end_of_hole == next_tok) {
      continue;
    }

    // Convert our printed token hole bounds into parsed token hole bounds.
    auto parsed_it = loc_to_toks.find(tok->derived_index);
    auto parsed_end_it = loc_to_toks.find(end_of_hole->derived_index);
    if (parsed_it == loc_to_toks.end() || parsed_end_it == loc_to_toks.end()) {
      continue;
    }

    auto first_parsed_tok = parsed_it->second;
    auto last_parsed_tok = parsed_end_it->second;

    // Make sure our hole sized match.
    if (first_parsed_tok >= last_parsed_tok ||
        (last_parsed_tok - first_parsed_tok) != (end_of_hole - tok)) {
      continue;
    }

    // Force merge on the hole.
    bool changed = false;
    for (auto hole_tok = tok; hole_tok < end_of_hole; ) {
      ++first_parsed_tok;
      ++hole_tok;
      MergeToken(first_parsed_tok, hole_tok, changed, true  /* force */);
    }

    assert(changed);
    (void) changed;
  }
}

static bool HasNotBeenMatched(Region *r) {
  return !r->has_been_matched;
}

void Matcher::InitParsedLocationsMap(void) {
  for (PrintedTokenImpl &tok : parsed_bounds.Range()) {
    loc_to_toks.emplace(tok.derived_index, &tok);
  }

  // This shouldn't remove anything, but just in case.
  loc_to_toks.erase(kInvalidDerivedTokenIndex);
}

void Matcher::JoinOnLocations(void) {

  // Join on the shared source locations, and linearly "spread"
  // outward from there. This should generally cover a bunch.
  bool changed = false;
  for (PrintedTokenImpl &printed : printed_bounds.Range()) {

    if (printed.derived_index == kInvalidDerivedTokenIndex) {
      continue;
    }

    auto loc_it = loc_to_toks.find(printed.derived_index);
    if (loc_it == loc_to_toks.end()) {
      continue;
    }

    PrintedTokenImpl *parsed = loc_it->second;
    if (!parsed || TokenHasLocationAndContext(parsed)) {
      continue;
    }

    if (auto local_changed = false;
        MergeToken(parsed, &printed, local_changed, false) && local_changed) {
      changed = true;
      MergeAround(parsed, &printed, changed);
    }
  }
}

// Assign the predecessor sequences of balanced regions. These can be helpful
// for matching.
void Matcher::AssignPredecessors(
    const std::vector<std::unique_ptr<Region>> &regions) {

  for (const std::unique_ptr<Region> &region : regions) {
    auto seq = dynamic_cast<SequenceRegion *>(region.get());
    if (!seq) {
      continue;
    }

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
}

}  // namespace

std::optional<std::string> PrintedTokenRangeImpl::AlignTokens(
    PrintedTokenRangeImpl &printed_range,
    TokenContextIndex root_context_id) {

  assert(root_context_id != kInvalidTokenContextIndex);
  assert(root_context_id < contexts.size());
  const TokenContextImpl * const root_context = &(contexts[root_context_id]);

  Bounds parsed_bounds(*this);
  Bounds printed_bounds(printed_range);

  assert(parsed_bounds.begin <= parsed_bounds.end);
  assert(printed_bounds.begin <= printed_bounds.end);

  std::stringstream err;
  std::vector<std::unique_ptr<Region>> parsed_regions;
  std::vector<std::unique_ptr<Region>> printed_regions;

  Matcher matcher(*ast, *this, printed_range);
  
  matcher.InitParsedLocationsMap();    

  // Try to merge as many tokens as possible as early as possible based on
  // shared locations.
  matcher.JoinOnLocations();
  matcher.MergeSameSizedHoles();

  SequenceRegion *parsed_tree = matcher.BuildRegions(
      parsed_regions, err, parsed_bounds.begin, parsed_bounds.end, "parsed");
  if (!parsed_tree) {
    return err.str();
  }

  SequenceRegion *printed_tree = matcher.BuildRegions(
      printed_regions, err, printed_bounds.begin, printed_bounds.end,
      "printed");
  if (!printed_tree) {
    return err.str();
  }

  // Assign predecessors of balanced regions.
  matcher.AssignPredecessors(parsed_regions);
  matcher.AssignPredecessors(printed_regions);

  // Initialize the printed regions with the contexts.
  //
  // NOTE(pag): `root_context` points into `this->contexts`. This is fine
  //            because `parsed_tree` and `printed_tree` only live as long as
  //            this function.
  (void) printed_tree->CommonContext(*this, root_context);

  std::vector<BalancedRegion *> parsed_balanced;
  std::vector<StatementRegion *> parsed_statements;

  std::vector<BalancedRegion *> printed_balanced;
  std::vector<StatementRegion *> printed_statements;

  std::unordered_multimap<DerivedTokenIndex, BalancedRegion *> loc_to_balanced;
  std::unordered_multimap<DerivedTokenIndex, StatementRegion *> loc_to_statement;

  for (const auto &region : parsed_regions) {
    if (auto bal = dynamic_cast<BalancedRegion *>(region.get())) {
      parsed_balanced.push_back(bal);
      loc_to_balanced.emplace(bal->begin->derived_index, bal);
      loc_to_balanced.emplace(bal->end->derived_index, bal);

    } else if (auto stmt = dynamic_cast<StatementRegion *>(region.get())) {
      parsed_statements.push_back(stmt);
      loc_to_statement.emplace(stmt->end->derived_index, stmt);
    }
  }

  loc_to_balanced.erase(kInvalidDerivedTokenIndex);
  loc_to_statement.erase(kInvalidDerivedTokenIndex);

  for (const auto &region : printed_regions) {
    if (auto bal = dynamic_cast<BalancedRegion *>(region.get())) {
      printed_balanced.push_back(bal);
    } else if (auto stmt = dynamic_cast<StatementRegion *>(region.get())) {
      printed_statements.push_back(stmt);
    }
  }

  auto join_balanced = [&] (bool &changed, BalancedRegion *region,
                            const PrintedTokenImpl *begin_end) {
    auto [bb_it, bb_end] =
        loc_to_balanced.equal_range(begin_end->derived_index);
    for (; bb_it != bb_end; ++bb_it) {
      matcher.MatchBalanced(bb_it->second, region, changed);
    }
  };

  auto remove_matched = [] (auto &range) {
    auto it = std::partition(range.begin(), range.end(), HasNotBeenMatched);
    range.erase(it, range.end());
  };

  // Join on the shared source locations of balanced and statement regions.
  // This only joins unmatched ones. We generally have decent-ish ability in
  // the token printer (due to clang source locations) to find things like the
  // location of a `}` or a `{`, or a `;`.
  auto join_based_region_merge = [&] (void) -> bool {
    remove_matched(parsed_balanced);
    remove_matched(printed_balanced);

    remove_matched(parsed_statements);
    remove_matched(printed_statements);

#if PASTA_DEBUG_ALIGN
    std::cerr
        << "parsed_balanced=" << parsed_balanced.size()
        << " printed_balanced=" << printed_balanced.size()
        << " parsed_statements=" << parsed_statements.size()
        << " printed_statements=" << printed_statements.size()
        <<'\n';
#endif

    bool changed = false;
    for (BalancedRegion *region : printed_balanced) {
      join_balanced(changed, region, region->begin);
      join_balanced(changed, region, region->end);
    }

    for (StatementRegion *region : printed_statements) {
      auto [bb_it, bb_end] =
          loc_to_statement.equal_range(region->end->derived_index);
      for (; bb_it != bb_end; ++bb_it) {
        matcher.MatchStatement(bb_it->second, region, changed);
      }
    }

    return changed;
  };

  matcher.matched_with.emplace(parsed_tree, printed_tree);
  bool changed = false;
  Region::MarkAsMatched(parsed_tree, printed_tree, changed);

  auto max_iters = (parsed_regions.size() / 2) + 1u;
  changed = join_based_region_merge();

  // Try to see if we can make matching progress right from the beginning. This
  // can help with leading tokens, e.g. `extern`.
  if (!parsed_bounds.Empty() && !printed_bounds.Empty()) {
    matcher.MergeForward(parsed_bounds.Front(), printed_bounds.Front(), changed);
    matcher.MergeBackward(parsed_bounds.Back(), printed_bounds.Back(), changed);
  }

  for (size_t i = 0u; i < max_iters; ++i) {
    changed = false;
    matcher.MatchRegions(parsed_tree, printed_tree, changed);
    if (!changed) {
      break;
    }
  }

  // Fixpoint merge loop.
  for (size_t i = 0u; i < max_iters && join_based_region_merge(); ++i) {}

  matcher.MergeSameSizedHoles();
  matcher.HashBasedMatch(parsed_bounds, printed_bounds, changed);
  matcher.FixContexts(parsed_tree, root_context);

#if PASTA_DEBUG_ALIGN

  // NOTE(pag): Contexts of `printed_tree` point into `this->contexts`.
  // NOTE(pag): `this->contexts` is a *copy* of `printed_range.contexts`.

  std::ofstream parsed_os("/tmp/tree.parsed",
                          std::ios_base::trunc | std::ios_base::out);
  parsed_tree->Print(parsed_os, "", *this, *this);

  std::ofstream printed_os("/tmp/tree.printed",
                           std::ios_base::trunc | std::ios_base::out);
  printed_tree->Print(printed_os, "", printed_range, *this);

  parsed_os.flush();
  printed_os.flush();

  auto i = 0u;
  for (PrintedTokenImpl &tok : printed_bounds.Range()) {
    std::cerr
        << (i++) << '\t'
        << tok.matched_in_align
        << '\t' << tok.derived_index << std::dec
        << '\t' << tok.context_index << std::dec
        << '\t' << clang::tok::getTokenName(tok.kind)
        << '\t' << tok.Data(printed_range) << '\n';
  }
  std::cerr << "---------------------------------\n";
  i = 0u;
  for (PrintedTokenImpl &tok : parsed_bounds.Range()) {
    std::cerr
        << (i++) << '\t'
        << tok.matched_in_align
        << '\t' << tok.derived_index << std::dec
        << '\t' << tok.context_index << std::dec
        << '\t' << clang::tok::getTokenName(tok.kind)
        << '\t' << tok.Data(*this) << '\n';
  }

#endif
  return std::nullopt;
}

namespace {

static const std::string kEmptyParsed = "Parsed token range is empty";
static const std::string kEmptyPrinted = "Printed token range is empty";
static const std::string kMismatchedASTs = "Backing ASTs of parsed and printed token ranges don't match";
static const std::string kMissingASTs = "No backing AST";
static const std::string kMissingSourceLoc = "Missing source location in token";
}  // namespace

// Align the token locations from `a` with the token contexts from `b`. Returns
// a string if an error occured.
std::optional<std::string> PrintedTokenRange::Align(PrintedTokenRange &a,
                                                    PrintedTokenRange &b) {

  if (a.impl == b.impl) {
    return std::nullopt;
  }

  if (!a) {
    return kEmptyParsed;
  }

  if (!b) {
    return kEmptyPrinted;
  }

  if (a.impl->ast.get() != b.impl->ast.get()) {
    return kMismatchedASTs;
  }

  if (!a.impl->ast) {
    return kMissingASTs;
  }

  // Top-level context should be the AST.
  a.impl->contexts = b.impl->contexts;

  auto reset_matches = [] (auto &tokens) {
    for (auto &tok : tokens) {
      tok.matched_in_align = false;
    }
  };

  // Reset the tokens that have the locations.
  for (auto &tok : a.impl->tokens) {
    tok.context_index = kInvalidTokenContextIndex;
    tok.matched_in_align = false;

    if (tok.derived_index == kInvalidDerivedTokenIndex &&
        tok.kind != clang::tok::eof) {
      return kMissingSourceLoc;
    }
  }

  // Reset the tokens that have the contexts.

  reset_matches(b.impl->tokens);

  auto error = a.impl->AlignTokens(*(b.impl), kASTTokenContextIndex);
  if (error) {
    return error.value();
  }

  // Make sure all of the tokens in `a` have a token index.
  for (auto &tok : a.impl->tokens) {
    if (tok.context_index == kInvalidTokenContextIndex) {
      tok.context_index = kASTTokenContextIndex;
    }
  }

  // Migrate the token contexts into the AST. This will migrate only the
  // contexts that were actually propagated into the parsed tokens, as
  // opposed to all token contexts.
  std::vector<TokenContextIndex> context_map;
  std::unordered_multimap<const void *, TokenContextIndex> data_to_context;
  context_map.assign(b.impl->contexts.size(), kInvalidTokenContextIndex);
  data_to_context.emplace(a.impl->ast.get(), kASTTokenContextIndex);

  reset_matches(a.impl->tokens);
  reset_matches(b.impl->tokens);

  return std::nullopt;
}

}  // namespace pasta
