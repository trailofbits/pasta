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
#include <sstream>

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
  return impl->opaque_source_loc != TokenImpl::kInvalidSourceLocation &&
         impl->context_index != kInvalidTokenContextIndex;
}

static bool TokenLocationsMatch(const PrintedTokenImpl *parsed,
                                const PrintedTokenImpl *printed) {
  if (parsed->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
    return false;
  } else if (printed->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
    return false;
  } else {
    return parsed->opaque_source_loc == printed->opaque_source_loc;
  }
}

static bool TokenCanBeAssignedContext(const TokenImpl *token) {
  switch (token->Kind()) {
    case clang::tok::unknown:
    case clang::tok::eod:
    case clang::tok::eof:
    case clang::tok::code_completion:
    case clang::tok::comment:
      return false;
    default:
      if (token->IsParsed()) {
        return token->data_len != 0;

      // Probably a printed token.
      } else {
        return token->Role() == TokenRole::kInvalid;
      }
  }
}

enum class RegionKind {
  kStatement,
  kSequence,
  kBalanced
};

struct Region {
 public:
  // Some context that is shared across all things in this region.
  std::optional<TokenContextIndex> common_context;

  // If we match this region with another, then we commit to that match and
  // record it here. If this is a parsed region, then this points at a printed
  // region. If it's a printed region, then this points at a parsed region.
  Region *matched_with{nullptr};

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
  virtual TokenContextIndex CommonContext(
      const PrintedTokenRangeImpl &range,
      TokenContextIndex parent_context) = 0;
};

struct StatementRegion final : public Region {

  PrintedTokenImpl *begin{nullptr};
  PrintedTokenImpl *end{nullptr};  // Inclusive.

  RegionKind Kind(void) const noexcept final {
    return RegionKind::kStatement;
  }

  PrintedTokenImpl *FirstParsedToken(void) const final {
    for (auto it = begin; it <= end; ++it) {
      if (TokenHasLocationAndContext(it) && TokenCanBeAssignedContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

  PrintedTokenImpl *LastParsedToken(void) const final {
    for (auto it = end; it >= begin; --it) {
      if (TokenHasLocationAndContext(it) && TokenCanBeAssignedContext(it)) {
        return it;
      }
    }
    return nullptr;
  }

  TokenContextIndex CommonContext(const PrintedTokenRangeImpl &range,
                                  TokenContextIndex parent_context) final {
    if (common_context) {
      return common_context.value();
    }

    // Try to find the common ancestor of everything in this statement.
    const TokenContextImpl *prev = nullptr;

    for (auto tok = reinterpret_cast<PrintedTokenImpl *>(begin);
         tok <= end; ++tok) {

      if (TokenHasLocationAndContext(tok)) {
        if (tok->context_index < parent_context) {
          continue;
        }
        assert(TokenCanBeAssignedContext(tok));
        const TokenContextImpl *curr = &(range.contexts[tok->context_index]);
        if (!prev) {
          prev = curr;
        } else {
          prev = TokenContextImpl::CommonAncestor(prev, curr, range.contexts);
        }
      }
    }

    if (!prev) {
      common_context.emplace(parent_context);
      return parent_context;
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    auto index = static_cast<TokenContextIndex>(prev - range.contexts.data());
    assert(index < range.contexts.size());
    common_context.emplace(index);
    return index;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {
    os << indent << "------ST "
       << std::hex
       << (common_context ? common_context.value() : kInvalidTokenContextIndex)
       << std::dec << "------\n";

    for (PrintedTokenImpl *it = begin; it <= end; ++it) {
      if (!TokenCanBeAssignedContext(it)) {
        continue;
      }
      if (it->Kind() == clang::tok::string_literal ||
          it->Kind() == clang::tok::wide_string_literal) {
        os << indent << "<str>";
      } else {
        os << indent << it->Data(data_range);
      }
      TK( os << " " << clang::tok::getTokenName(it->Kind()); )
      if (it->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        os << " l:" << std::hex << it->opaque_source_loc << std::dec;
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

  TokenContextIndex CommonContext(const PrintedTokenRangeImpl &range,
                                  TokenContextIndex parent_context) final {
    if (common_context) {
      return common_context.value();
    }

    // Try to find the common ancestor of everything in this statement.
    const TokenContextImpl *prev = nullptr;
    for (Region *region : regions) {
      auto index = region->CommonContext(range, parent_context);
      if (index == kInvalidTokenContextIndex ||
          index < parent_context) {
        continue;
      }

      assert(index < range.contexts.size());
      const TokenContextImpl *curr = &(range.contexts[index]);
      if (!prev) {
        prev = curr;
      } else {
        prev = TokenContextImpl::CommonAncestor(prev, curr, range.contexts);
      }
    }

    if (!prev) {
      common_context.emplace(parent_context);
      return parent_context;
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    auto index = static_cast<TokenContextIndex>(prev - range.contexts.data());
    assert(index < range.contexts.size());
    common_context.emplace(index);
    return index;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {

    os << indent << "------SE "
       << std::hex
       << (common_context ? common_context.value() : kInvalidTokenContextIndex)
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

  TokenContextIndex CommonContext(const PrintedTokenRangeImpl &range,
                                  TokenContextIndex parent_context) final {
    if (common_context) {
      return common_context.value();
    }

    const TokenContextImpl *prev = nullptr;

    // Get it from the leading identifier.
    if (leading_ident) {
      auto tok = reinterpret_cast<PrintedTokenImpl *>(leading_ident);
      if (TokenHasLocationAndContext(tok)) {
        assert(tok->context_index < range.contexts.size());
        prev = &(range.contexts[tok->context_index]);
      }
    }

    // Get it from the brackets/braces/parens.
    if (!prev && begin && end) {
      auto tok = reinterpret_cast<PrintedTokenImpl *>(begin);
      if (TokenHasLocationAndContext(tok)) {
        prev = &(range.contexts[tok->context_index]);
      }

      tok = reinterpret_cast<PrintedTokenImpl *>(end);
      if (TokenHasLocationAndContext(tok)) {
        auto curr = &(range.contexts[tok->context_index]);
        if (!prev) {
          prev = curr;
        } else {
          prev = TokenContextImpl::CommonAncestor(prev, curr, range.contexts);
        }
      }
    }

    // Did we get it?
    if (prev) {
      parent_context = static_cast<TokenContextIndex>(
          prev - range.contexts.data());
      assert(parent_context < range.contexts.size());
    }

    // Top-down mutational update.
    if (statements) {
      parent_context = statements->CommonContext(range, parent_context);
    }

    assert(parent_context < range.contexts.size());
    common_context.emplace(parent_context);

    return parent_context;
  }

#if PASTA_DEBUG_ALIGN
  void Print(std::ostream &os, std::string indent,
             const PrintedTokenRangeImpl &data_range,
             const PrintedTokenRangeImpl &context_range) const final {

    os << indent << "------BA "
       << std::hex
       << (common_context ? common_context.value() : kInvalidTokenContextIndex)
       << std::dec << "------\n";
    os << indent << begin->Data(data_range) << " " << clang::tok::getTokenName(begin->Kind());

    if (begin->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
      os << " l:" << std::hex << begin->opaque_source_loc << std::dec;
    }
    if (begin->context_index != kInvalidTokenContextIndex) {
      os << " c:" << std::hex << begin->context_index << std::dec;
    }
    os << '\n';
    if (statements) {
      statements->Print(os, indent + "  ", data_range, context_range);
    }
    os << indent << end->Data(data_range) << " " << clang::tok::getTokenName(end->Kind());
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

static bool MergeToken(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                       bool &changed, bool force=false) {

  // `printed` tokens will always have a valid token context index, even if it's
  // just `0`, which is the AST context, whereas `parsed` is initialized with
  // `kInvalidTokenContextIndex`.
  if (parsed->context_index == printed->context_index) {
    if (printed->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
      printed->opaque_source_loc = parsed->opaque_source_loc;
      printed->derived_index = parsed->derived_index;
      changed = true;

    } else {
      return TokenLocationsMatch(parsed, printed);
    }
  }

  assert(printed->context_index != kInvalidTokenContextIndex);

  if (force) {
    if (!printed->matched_in_align) {
      printed->matched_in_align = true;
      changed = true;
    }

    if (printed->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
      printed->opaque_source_loc = parsed->opaque_source_loc;
      printed->derived_index = parsed->derived_index;
      parsed->context_index = printed->context_index;
      changed = true;
    }

    if (parsed->context_index == kInvalidTokenContextIndex) {
      parsed->context_index = printed->context_index;
      changed = true;
    }

    return true;
  
  } else if (TokenImpl::kInvalidSourceLocation == printed->opaque_source_loc) {

    parsed->context_index = printed->context_index;
    printed->opaque_source_loc = parsed->opaque_source_loc;
    printed->derived_index = parsed->derived_index;

    if (!printed->matched_in_align) {
      printed->matched_in_align = true;
      changed = true;
    }

    return true;

  } else if (TokenImpl::kInvalidSourceLocation == parsed->opaque_source_loc) {
    assert(false);
    return false;

  } else if (parsed->opaque_source_loc == printed->opaque_source_loc) {

    parsed->context_index = printed->context_index;
    printed->derived_index = parsed->derived_index;

    if (!printed->matched_in_align) {
      printed->matched_in_align = true;
      changed = true;
    }

    return true;

  // Different locations.
  } else {
    return false;
  }
}

class Matcher {
 private:
  ASTImpl &ast;
  PrintedTokenRangeImpl &parsed_range;
  PrintedTokenRangeImpl &printed_range;
  PrintedTokenImpl * const first_parsed;
  PrintedTokenImpl * const last_parsed;  // Exclusive, but can be read.
  PrintedTokenImpl * const first_printed;
  PrintedTokenImpl * const last_printed;  // Exclusive, but can be read.

  std::vector<std::unique_ptr<Region>> parsed_regions;
  std::vector<std::unique_ptr<Region>> printed_regions;

  // Maps identifiers or keywords that precede a balanced region to the
  // token just after the balanced region. This is used to jump over
  // `__attribute__` tokens when doing forward matching.
  std::unordered_map<PrintedTokenImpl *, PrintedTokenImpl *> skip_balanced;

 public:
  inline explicit Matcher(ASTImpl &ast_,
                          PrintedTokenRangeImpl &parsed_range_,
                          PrintedTokenRangeImpl &printed_range_,
                          PrintedTokenImpl *first_parsed_,
                          PrintedTokenImpl *last_parsed_,
                          PrintedTokenImpl *first_printed_,
                          PrintedTokenImpl *last_printed_)
      : ast(ast_),
        parsed_range(parsed_range_),
        printed_range(printed_range_),
        first_parsed(first_parsed_),
        last_parsed(last_parsed_),
        first_printed(first_printed_),
        last_printed(last_printed_) {}

  // Organize the tokens into a tree, grouped by brace/bracket/paren-enclosed
  // regions, and comma/semicolon-separated regions.
  SequenceRegion *BuildRegions(
      std::vector<std::unique_ptr<Region>> &regions,
      std::stringstream &err, PrintedTokenImpl *first,
      PrintedTokenImpl *after_last, const char *list_kind);

  bool DataEquals(PrintedTokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchToken(PrintedTokenImpl *parsed, PrintedTokenImpl *printed);
  bool MatchTokenByKindOrData(PrintedTokenImpl *parsed,
                              PrintedTokenImpl *printed);
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

  bool MergeForward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                    bool &changed);
  bool MergeBackward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                     bool &changed);

  void FixContexts(Region *parsed, std::vector<TokenContextIndex> &stack);
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

    // This is a macro expansion token; ignore it.
    if (!TokenCanBeAssignedContext(&tok)) {
      if (!unused_end) {
        unused_end = &tok;
      }
      continue;  // Skip.
    }

    const clang::tok::TokenKind tok_kind = tok.Kind();

    // If we just saw a balanced region, and now we're seeing an identifier,
    // then we want to use that identifier as part of our matching criteria.
    if (last_balanced &&
        (clang::tok::isAnyIdentifier(tok_kind) ||
         clang::tok::getKeywordSpelling(tok_kind) != nullptr)) {
      last_balanced->leading_ident = &tok;

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

          if (Token hl_tok = ast.TokenAt(&tok)) {
            err << " (index " << hl_tok.Index() << ')';
            if (auto ft = hl_tok.FileLocation()) {
              auto file = File::Containing(ft.value());
              err << " at " << file.Path().generic_string()
                  << ':' << ft->Line() << ':' << ft->Column();
            }
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

            if (Token hl_tok_begin = ast.TokenAt(&tok)) {
              if (auto ft = hl_tok_begin.FileLocation()) {
                auto file = File::Containing(ft.value());
                err << " starting at " << file.Path().generic_string()
                    << ':' << ft->Line() << ':' << ft->Column();
              }
            }

            if (Token hl_tok_end = ast.TokenAt(r_tok)) {
              if (auto ft = hl_tok_end.FileLocation()) {
                auto file = File::Containing(ft.value());
                err << " ending at " << file.Path().generic_string()
                    << ':' << ft->Line() << ':' << ft->Column();
              }
            }
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
  auto size = view.size();
  while (!view.empty() && view.front() == '_') {
    --size;
    view = view.substr(1u, size);
  }

  while (!view.empty() && view.back() == '_') {
    --size;
    view = view.substr(0, size);
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
  } else {
    return kHasher(HashableData(view));
  }
}

bool Matcher::DataEquals(PrintedTokenImpl *parsed, PrintedTokenImpl *printed) {
  auto parsed_data = parsed->Data(parsed_range);
  auto printed_data = printed->Data(printed_range);
  if (clang::tok::getKeywordSpelling(parsed->Kind())) {
    return HashableData(parsed_data) == HashableData(printed_data);
  } else {
    return parsed_data == printed_data;
  }
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

bool Matcher::MergeForward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                           bool &changed) {
  auto merged = false;
  auto num_skips = 0u;

  std::vector<PrintedTokenImpl *> backtrack_locs;

  const auto last_printed = &(printed_range.tokens.back());
  while (parsed < last_parsed && printed <= last_printed && num_skips < 16u) {
    if (!TokenCanBeAssignedContext(parsed)) {
      ++parsed;
      ++num_skips;
      continue;
    }

    if (!TokenCanBeAssignedContext(printed)) {
      ++printed;
      ++num_skips;
      continue;
    }

    const auto parsed_kind = parsed->Kind();
    const auto printed_kind = printed->Kind();

    // Try to skip over `__attribute__` sections when matching.
    if (parsed_kind != printed_kind) {
      if (IsAttributeLikeKeword(parsed_kind)) {
        if (auto skip_it = skip_balanced.find(parsed);
            skip_it != skip_balanced.end()) {
          parsed = skip_it->second;
          ++num_skips;
          continue;
        }

      } else if (IsAttributeLikeKeword(printed_kind)) {
        if (auto skip_it = skip_balanced.find(printed);
            skip_it != skip_balanced.end()) {
          printed = reinterpret_cast<PrintedTokenImpl *>(skip_it->second);
          ++num_skips;
          continue;
        }
      }
    }

    if (!MatchToken(parsed, printed)) {
      if (clang::tok::isAnyIdentifier(parsed_kind)) {
        ++parsed;
        ++num_skips;
        continue;
      } else if (clang::tok::getPunctuatorSpelling(parsed_kind)) {
        ++printed;
        ++num_skips;
        continue;
      } else {
        break;
      }
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
      auto tk = parsed->Kind();
      auto is_string_literal = tk == clang::tok::string_literal ||
                               tk == clang::tok::wide_string_literal;

      if (is_string_literal && parsed->context_index != kInvalidTokenContextIndex) {
        for (; (parsed + 1u) < last_parsed; ++parsed) {
          tk = parsed[1u].Kind();
          if (tk != clang::tok::string_literal &&
              tk != clang::tok::wide_string_literal) {
            break;
          } else if (parsed[1u].context_index != kInvalidTokenContextIndex) {
            break;

          } else {
            parsed[1u].context_index = parsed->context_index;
          }
        }
      }

      ++parsed;
      ++printed;

    // We hit a blocker, but we previously made progress.
    } else if (merged) {
      break;

    // Skip these unmergeable tokens.
    } else {
      ++parsed;
      ++printed;
      ++num_skips;
    }
  }

  return merged;
}

bool Matcher::MergeBackward(PrintedTokenImpl *parsed, PrintedTokenImpl *printed,
                            bool &changed) {
  auto num_skips = 0u;
  auto merged = false;
  const auto first_printed = &(printed_range.tokens.front());
  while (parsed >= first_parsed && printed >= first_printed &&
         num_skips <= 16u) {
    if (!TokenCanBeAssignedContext(parsed)) {
      ++num_skips;
      --parsed;
      continue;
    }

    if (!TokenCanBeAssignedContext(printed)) {
      ++num_skips;
      --printed;
      continue;
    }

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

  } else if (MatchTokenByKindOrData(parsed, printed)) {
    return true;
  
  // The previous matches, the next matches, so assume this one matches too!
  } else if (first_parsed < parsed && parsed < last_parsed &&
             first_printed < printed && printed < last_printed &&
             TokenLocationsMatch(&(parsed[-1]), &(printed[-1])) &&
             TokenLocationsMatch(&(parsed[1]), &(printed[1]))) {
    return true;
  
  } else {
    return false;
  }
}

bool Matcher::MatchTokenByKindOrData(PrintedTokenImpl *parsed,
                                     PrintedTokenImpl *printed) {
  const auto parsed_kind = parsed->Kind();
  const auto kinds_equal = parsed_kind == printed->Kind();
  if (clang::tok::isLiteral(parsed_kind)) {
    return kinds_equal;

  } else if (kinds_equal) {
    if (clang::tok::getKeywordSpelling(parsed_kind) ||
        !clang::tok::isAnyIdentifier(parsed_kind)) {
      return true;
    } else {
      return DataEquals(parsed, printed);
    }

  } else {
    return DataEquals(parsed, printed);
  }
}

bool Matcher::MatchBalanced(BalancedRegion *parsed, BalancedRegion *printed,
                            bool &changed) {
  if (parsed->matched_with == printed) {
    return true;
  }

  if (parsed->begin->Kind() != printed->begin->Kind()) {
    return false;
  }

  if (!parsed->leading_ident != !printed->leading_ident) {
    return false;
  }

  if (parsed->leading_ident &&
      !MatchToken(
          parsed->leading_ident,
          reinterpret_cast<PrintedTokenImpl *>(printed->leading_ident))) {
    return false;
  }

  assert(parsed->end->Kind() == printed->end->Kind());

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
    if (parsed->begin > first_parsed && printed_begin > first_printed) {
      auto before_parsed = &(parsed->begin[-1]);
      auto before_printed = &(printed_begin[-1]);
      if (TokenLocationsMatch(before_parsed, before_printed)) {
        begin_loc_matches = true;
      }
    }

    // Look one beyond.
    if (parsed->end < last_parsed && printed_end < last_printed) {
      auto after_parsed = &(parsed->end[1]);
      auto after_printed = &(printed_end[1]);
      if (TokenLocationsMatch(after_parsed, after_printed)) {
        end_loc_matches = true;
      }
    }
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

  if (parsed->matched_with) {
    return false;
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

  if (!parsed->common_context) {
    parsed->common_context = printed->common_context;
  }

  // We've already matched.
  if (parsed->matched_with == printed) {
    return true;
  }

  if (!parsed->matched_with || !printed->matched_with) {
    changed = true;
  }

  auto local_changed_begin = false;
  auto local_changed_end = false;
  parsed->matched_with = printed;
  MergeToken(parsed->begin, printed_begin, local_changed_begin, true);
  MergeToken(parsed->end, printed_end, local_changed_end, true);

  // Commit to this match.
  if (!printed->matched_with) {
    printed->matched_with = parsed;
  }

  if (local_changed_begin) {
    changed = true;
    MergeForward(&(parsed->begin[1]), &(printed_begin[1]), changed);
    MergeBackward(&(parsed->begin[-1]), &(printed_begin[-1]), changed);
  }

  if (local_changed_end) {
    changed = true;
    MergeBackward(&(parsed->end[-1]), &(printed_end[-1]), changed);
    MergeForward(&(parsed->end[1]), &(printed_end[1]), changed);
  }

  // If we have statements, then commit to them too.
  if (!did_recurse && parsed->statements && printed->statements) {
//
//    if (parsed->statements->matched_with != printed->statements) {
//      changed = true;
//      parsed->statements->matched_with = printed->statements;
//      printed->statements->matched_with = parsed->statements;
//    }

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
    if (!parsed_sub) {
      continue;
    }
    for (Region *&printed_sub : printed_regions) {
      if (printed_sub &&
          parsed_sub->matched_with != printed_sub &&
          MatchRegions(parsed_sub, printed_sub, changed)) {

        if (!parsed_sub->common_context) {
          parsed_sub->common_context = printed_sub->common_context;
        }

        if (!parsed_sub->matched_with) {
          changed = true;
          parsed_sub->matched_with = printed_sub;
        }

        if (!printed_sub->matched_with) {
          changed = true;
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
  if (parsed->matched_with == printed) {
    return true;

  } else if (parsed->matched_with) {
    return false;
  }

  if (parsed->regions.empty() != printed->regions.empty()) {
    return false;  // One is empty, the other isn't.

  } else if (parsed->regions.empty()) {
    return true;  // Both are empty.
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

  // Allow ourselves to locally fail on this run, but benefit from a prior
  // matching.
  if (!matched) {
    return false;
  }

  if (!parsed->common_context) {
    changed = true;
    parsed->common_context = printed->common_context;
  }

  if (!parsed->matched_with || !printed->matched_with) {
    changed = true;
  }

  parsed->matched_with = printed;

  if (!printed->matched_with) {
    printed->matched_with = parsed;
  }

  return true;
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

  std::unordered_map<uint64_t, std::vector<PrintedTokenImpl *>> parsed_toks;
  std::unordered_map<uint64_t, std::vector<PrintedTokenImpl *>> printed_toks;

  // Do some join-based hashing, then try to match tokens with the same hash.
  // This can have really bad time complexity when the two statements contain
  // tons of literal/punctuation values, which happens with giant arrays.

  for (PrintedTokenImpl *it = parsed_begin; it <= parsed_end; ++it) {
    if (TokenCanBeAssignedContext(it) &&
        it->context_index == kInvalidTokenContextIndex) {
      parsed_toks[Hash(it->Kind(), it->Data(parsed_range))].emplace_back(it);
    }
  }

  for (PrintedTokenImpl *it = printed_begin; it <= printed_end; ++it) {
    if (TokenCanBeAssignedContext(it) && !it->matched_in_align) {
      printed_toks[Hash(it->Kind(), it->Data(printed_range))].emplace_back(it);
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

        } else if (parsed_tok->context_index == printed_tok->context_index) {
          matched = true;

        } else if (TokenLocationsMatch(parsed_tok, printed_tok) ||
                   (!TokenHasLocationAndContext(printed_tok) &&
                    MatchTokenByKindOrData(parsed_tok, printed_tok))) {

          if (!MergeToken(parsed_tok, printed_tok, changed)) {
            continue;
          }

          MergeForward(&(parsed_tok[1]), &(printed_tok[1]), changed);
          MergeBackward(&(parsed_tok[-1]), &(printed_tok[-1]), changed);

          matched = true;
          printed_tok = nullptr;

          // Try to reduce scope of O(n^2) problems.
          std::swap(matching_printed[i], matching_printed[start]);
          ++start;

          break;
        }
      }
    }
  }

  if (matched) {
    if (!parsed->common_context) {
      parsed->common_context = printed->common_context;
    }

    if (!parsed->matched_with || !printed->matched_with) {
      changed = true;
    }

    if (parsed->matched_with != printed) {
      parsed->matched_with = printed;
    }

    if (!printed->matched_with) {
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

  if (parsed->matched_with) {
    return parsed->matched_with == printed;
  }

  if (parsed->common_context && printed->common_context &&
      parsed->common_context.value() != printed->common_context.value()) {
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

// Make sure that every parsed token is assigned *some* kind of context. We try
// to benefit from existing matches and common ancestors to apply contexts.
void Matcher::FixContexts(
    Region *parsed, std::vector<TokenContextIndex> &stack) {

  TokenContextIndex prev_context = stack.back();

  if (auto bal = dynamic_cast<BalancedRegion *>(parsed)) {
    assert(!stack.empty());

    // If we have a predecessor context from an identifier or keyword, take
    // it.
    if (bal->leading_ident && TokenHasLocationAndContext(bal->leading_ident)) {
      prev_context = bal->leading_ident->context_index;
      bal->common_context.emplace(prev_context);

    } else if (bal->common_context.has_value()) {
      prev_context = bal->common_context.value();
    }

    // Happens when we match the `)` of an `__attribute__` against the `)`
    // of the parameter list of the function to which the attribute applies.
    if (TokenHasLocationAndContext(bal->begin) !=
        TokenHasLocationAndContext(bal->end)) {
      bal->begin->context_index = prev_context;
      bal->end->context_index = prev_context;
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

    const TokenContextImpl *prev = nullptr;
    if (stmt->common_context.has_value()) {
      prev = &(printed_range.contexts[stmt->common_context.value()]);
    }

    // Try to find the common ancestor of everything in this statement.
    if (!prev) {
      for (auto tok = stmt->begin; tok <= stmt->end; ++tok) {
        if (TokenHasLocationAndContext(tok)) {
          assert(TokenCanBeAssignedContext(tok));
          const TokenContextImpl *curr = &(printed_range.contexts[tok->context_index]);
          if (!prev) {
            prev = curr;
          } else {
            prev = TokenContextImpl::CommonAncestor(prev, curr, printed_range.contexts);
          }
        }
      }
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    if (prev) {
      auto index = static_cast<TokenContextIndex>(prev - printed_range.contexts.data());
      assert(index < printed_range.contexts.size());

      stmt->common_context.emplace(index);

      if (prev_context != kInvalidTokenContextIndex) {
        auto parent = &(printed_range.contexts[prev_context]);
        auto ancestor = TokenContextImpl::CommonAncestor(
            prev, parent, printed_range.contexts);
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
      if (!TokenHasLocationAndContext(tok) && TokenCanBeAssignedContext(tok)) {
        tok->context_index = stack.back();
      }
    }

  } else if (auto seq = dynamic_cast<SequenceRegion *>(parsed)) {

    // Try to find the common ancestor of everything in this sequence.
    const TokenContextImpl *prev = nullptr;
    if (seq->common_context.has_value()) {
      prev = &(printed_range.contexts[seq->common_context.value()]);
    }

    if (!prev) {
      for (Region *region : seq->regions) {
        if (PrintedTokenImpl *tok = region->FirstParsedToken()) {
          assert(TokenHasLocationAndContext(tok));
          assert(TokenCanBeAssignedContext(tok));
          const TokenContextImpl *curr = &(printed_range.contexts[tok->context_index]);
          if (!prev) {
            prev = curr;
          } else {
            prev = TokenContextImpl::CommonAncestor(prev, curr, printed_range.contexts);
          }
        }
        if (PrintedTokenImpl *tok = region->LastParsedToken()) {
          assert(TokenHasLocationAndContext(tok));
          assert(TokenCanBeAssignedContext(tok));
          const TokenContextImpl *curr = &(printed_range.contexts[tok->context_index]);
          if (!prev) {
            prev = curr;
          } else {
            prev = TokenContextImpl::CommonAncestor(prev, curr, printed_range.contexts);
          }
        }
      }
    }

    // If we've got a common ancestor, then push its index, and double check
    // it against our parent. Otherwise, push our parent.
    if (prev) {
      auto index = static_cast<TokenContextIndex>(prev - printed_range.contexts.data());
      assert(index < printed_range.contexts.size());

      seq->common_context.emplace(index);

      if (prev_context != kInvalidTokenContextIndex) {
        auto parent = &(printed_range.contexts[prev_context]);
        auto ancestor = TokenContextImpl::CommonAncestor(
            prev, parent, printed_range.contexts);
        if (!ancestor || ancestor->depth < parent->depth) {
          index = prev_context;  // Fixup.
        }
      }

      stack.push_back(index);

    } else {
      stack.push_back(prev_context);
    }

    // Fix the contexts of any tokens inside of this sequence.
    for (Region *region : seq->regions) {
      FixContexts(region, stack);
    }
  }

  stack.pop_back();
}

static bool HasNotBeenMatched(Region *r) {
  return !r->matched_with;
}

}  // namespace

std::optional<std::string> PrintedTokenRangeImpl::AlignTokens(
    PrintedTokenRangeImpl &printed_range,
    TokenContextIndex decl_context_id) {

  PrintedTokenImpl *parsed_begin = tokens.data();
  PrintedTokenImpl *parsed_end = &(parsed_begin[tokens.size() - 1u]);  // EOF

  PrintedTokenImpl *printed_begin = printed_range.tokens.data();
  PrintedTokenImpl *printed_end =
      &(printed_begin[printed_range.tokens.size() - 1u]);  // EOF

  assert(parsed_begin < parsed_end);
  assert(printed_begin < printed_end);

  std::stringstream err;
  std::vector<std::unique_ptr<Region>> parsed_regions;
  std::vector<std::unique_ptr<Region>> printed_regions;

  Matcher matcher(*ast, *this, printed_range, parsed_begin, parsed_end,
                  printed_begin, printed_end);

  std::unordered_map<OpaqueSourceLoc, PrintedTokenImpl *> loc_to_toks;
  for (auto tok = parsed_begin; tok < parsed_end; ++tok) {
    if (TokenCanBeAssignedContext(tok)) {
      loc_to_toks.emplace(tok->opaque_source_loc, tok);
    }
  }

  // Join on the shared source locations, and linearly "spread"
  // outward from there. This should generally cover a bunch.
  bool changed = false;
  for (PrintedTokenImpl *printed = printed_begin;
       printed < printed_end; ++printed) {

    if (printed->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
      continue;
    }

    auto loc_it = loc_to_toks.find(printed->opaque_source_loc);
    if (loc_it == loc_to_toks.end()) {
      continue;
    }

    PrintedTokenImpl *parsed = loc_it->second;
    if (!parsed || TokenHasLocationAndContext(parsed)) {
      continue;
    }

    if (auto local_changed = false;
        MergeToken(parsed, printed, local_changed, false) && local_changed) {
      changed = true;
      matcher.MergeBackward(&(parsed[-1]), &(printed[-1]), changed);
      matcher.MergeForward(&(parsed[1]), &(printed[1]), changed);
    }
  }

  SequenceRegion *parsed_tree = matcher.BuildRegions(
      parsed_regions, err, parsed_begin, parsed_end, "parsed");
  if (!parsed_tree) {
    return err.str();
  }

  auto printed_tree = matcher.BuildRegions(
      printed_regions, err, printed_begin, printed_end, "printed");
  if (!printed_tree) {
    return err.str();
  }

  // Initialize the printed regions with the contexts.
  (void) printed_tree->CommonContext(printed_range, decl_context_id);

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

  std::unordered_multimap<OpaqueSourceLoc, BalancedRegion *>
      printed_loc_to_balanced;
  std::unordered_multimap<OpaqueSourceLoc, StatementRegion *>
      printed_end_loc_to_statement;

  for (const auto &region_ref : parsed_regions) {
    const auto region = region_ref.get();
    if (auto balanced = dynamic_cast<BalancedRegion *>(region)) {
      parsed_balanced.push_back(balanced);

      auto loc = balanced->begin->opaque_source_loc;
      if (loc != TokenImpl::kInvalidSourceLocation) {
        printed_loc_to_balanced.emplace(loc, balanced);
      }

      loc = balanced->end->opaque_source_loc;
      if (loc != TokenImpl::kInvalidSourceLocation) {
        printed_loc_to_balanced.emplace(loc, balanced);
      }

    } else if (auto statement = dynamic_cast<StatementRegion *>(region)) {
      parsed_statements.push_back(statement);

      auto loc = statement->end->opaque_source_loc;
      if (loc != TokenImpl::kInvalidSourceLocation) {
        printed_end_loc_to_statement.emplace(loc, statement);
      }
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

  // Join on the shared source locations of balanced and statement regions.
  // This only joins unmatched ones. We generally have decent-ish ability in
  // the token printer (due to clang source locations) to find things like the
  // location of a `}` or a `{`, or a `;`.
  auto join_based_region_merge = [&] (bool &changed) {
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
        << "parsed_balanced=" << parsed_balanced.size()
        << " printed_balanced=" << printed_balanced.size()
        << " parsed_statements=" << parsed_statements.size()
        << " printed_statements=" << printed_statements.size()
        <<'\n';
#endif

    for (BalancedRegion *region : printed_balanced) {
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

    for (StatementRegion *region : printed_statements) {
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

  auto max_iters = (parsed_regions.size() / 2) + 1u;

  join_based_region_merge(changed);

  // Try to see if we can make matching progress right from the beginning. This
  // can help with leading tokens, e.g. `extern`.
  matcher.MergeForward(parsed_begin, printed_begin, changed);
  matcher.MergeBackward(&(parsed_end[-1]), &(printed_end[-1]), changed);

  for (size_t i = 0u; i < max_iters; ++i) {
    changed = false;
    matcher.MatchRegions(parsed_tree, printed_tree, changed);
    if (!changed) {
      break;
    }
  }

  for (size_t i = 0u; i < max_iters; ++i) {
    changed = false;
    join_based_region_merge(changed);
    if (!changed) {
      break;
    }
  }

  // Look for `<matched> <unmatched hole...> <matched>` where the two matched
  // tokens are separated by a N-token-sized hole.
  for (auto tok = printed_begin; tok < printed_end; ++tok) {
    if (tok->opaque_source_loc == TokenImpl::kInvalidSourceLocation) {
      continue;
    }

    // Find the end of the hole.
    auto end_of_hole = &(tok[1]);
    for (; end_of_hole < printed_end; ++end_of_hole) {
      if (end_of_hole->opaque_source_loc != TokenImpl::kInvalidSourceLocation) {
        break;
      }
    }

    // There is no hole.
    if (end_of_hole == &(tok[1])) {
      continue;
    }

    // Convert our printed token hole bounds into parsed token hole bounds.
    auto parsed_it = loc_to_toks.find(tok->opaque_source_loc);
    auto parsed_end_it = loc_to_toks.find(end_of_hole->opaque_source_loc);
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

  std::vector<TokenContextIndex> context_stack;
  context_stack.push_back(decl_context_id);
  matcher.FixContexts(parsed_tree, context_stack);

#if PASTA_DEBUG_ALIGN

  // NOTE(pag): Contexts of `parsed_tree` are still from `printed_range`.

  std::ofstream parsed_os("/tmp/tree.parsed", std::ios_base::trunc | std::ios_base::out);
  parsed_tree->Print(parsed_os, "", *this, printed_range);

  std::ofstream printed_os("/tmp/tree.printed", std::ios_base::trunc | std::ios_base::out);
  printed_tree->Print(printed_os, "", printed_range, printed_range);

  parsed_os.flush();
  printed_os.flush();

  auto i = 0u;
  for (PrintedTokenImpl *tok = printed_begin; tok < printed_end; ++tok) {
    std::cerr
        << (i++) << '\t'
        << '\t' << std::hex << tok->opaque_source_loc << std::dec
        << '\t' << std::hex << tok->context_index << std::dec
        << '\t' << clang::tok::getTokenName(tok->Kind())
        << '\t' << tok->Data(printed_range) << '\n';
  }
  std::cerr << "---------------------------------\n";
  i = 0u;
  for (PrintedTokenImpl *tok = parsed_begin; tok < parsed_end; ++tok) {
    if (!TokenCanBeAssignedContext(tok)) {
      ++i;
      continue;
    }
    std::cerr
        << (i++) << '\t'
        << '\t' << std::hex << tok->opaque_source_loc << std::dec
        << '\t' << std::hex << tok->context_index << std::dec
        << '\t' << clang::tok::getTokenName(tok->Kind())
        << '\t' << tok->Data(*this) << '\n';
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

  const auto first_ast_tok = a.impl->ast->tokens.data();
  auto fixup_tok = [=] (const auto &ast, auto &tok) {
    tok.matched_in_align = false;
    if (tok.opaque_source_loc != TokenImpl::kInvalidSourceLocation &&
        tok.derived_index == kInvalidDerivedTokenIndex) {
      if (auto parsed_tok = ast->RawTokenAt(tok.Location())) {
        tok.derived_index = static_cast<DerivedTokenIndex>(
            parsed_tok - first_ast_tok);
      }
    }
  };

  // Reset the tokens that have the locations.
  for (auto &tok : a.impl->tokens) {
    tok.context_index = kInvalidTokenContextIndex;
    fixup_tok(a.impl->ast, tok);

    if (tok.derived_index == kInvalidDerivedTokenIndex &&
        tok.Kind() != clang::tok::eof) {
      return kMissingSourceLoc;
    }
  }

  // Reset the tokens that have the contexts.
  for (auto &tok : b.impl->tokens) {
    tok.matched_in_align = false;
  }

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

  for (auto &tok : a.impl->tokens) {
    tok.matched_in_align = false;
  }

  for (auto &tok : b.impl->tokens) {
    fixup_tok(b.impl->ast, tok);
  }

  return std::nullopt;
}

}  // namespace pasta
