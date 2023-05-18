/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/StmtManual.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <clang/AST/Expr.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Builder.h"

#include <algorithm>

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP

// Follow a macro token's parent chain to the end, and returns the final parent.
// If the macro token has no parent, this returns std::nullopt;
std::optional<Macro>
RootSubstitution(const MacroToken &macro_token) noexcept {
  std::optional<Macro> root;
  std::optional<Macro> next_root = macro_token.Parent();
  do {
    root = std::move(next_root);
    next_root = root->Parent();
  } while (next_root);
  return root;
}

// Returns the highest substitution that covers this Stmt, if any.
std::optional<Macro> Stmt::HighestContainingSubstitution(void) const noexcept {
  // If the first token in this Stmt did not come from a macro substitution,
  // then this Stmt is not covered by a substitution
  const auto begin_macro_token = BeginToken().MacroLocation();
  if (!begin_macro_token) {
    return std::nullopt;
  }

  // If the last token in this Stmt did not come from a macro substitution,
  // then this Stmt is not covered by a substitution
  const auto end_macro_token = EndToken().MacroLocation();
  if (!end_macro_token) {
    return std::nullopt;
  }

  const auto begin_macro_token_root = RootSubstitution(*begin_macro_token);
  const auto end_macro_token_root = RootSubstitution(*end_macro_token);

  // If the root of the begin token and end token are the same, then return that
  // root
  if (begin_macro_token_root && end_macro_token_root &&
      *begin_macro_token_root == *end_macro_token_root) {
    return begin_macro_token_root;
  }

  // Otherwise, this statement was composed of multiple substitution trees, so
  // return nothing
  return std::nullopt;
}

// Returns the lowest macro argument that contains this Stmt, if any.
std::optional<MacroArgument>
Stmt::LowestContainingMacroArgument(void) const noexcept {
  // Algorithm:
  // 1. Find the lowest macro argument that the first token in this Stmt was
  //    expanded from.
  // 2. Check if the last token in the Stmt was also expanded from this argument
  //    at some point.
  // 3. If so, then return the argument that the first token was expanded from.
  // 4. Otherwise, find the next-lowest macro argument that the first token was
  //    expanded from and repeat steps 2 and 3. If we reach a point where the
  //    first token is no longer expanded from a macro argument, then return
  //    std::nullopt.
  const auto tokens = Tokens();
  const auto first_tok = tokens.Front();
  if (!first_tok || !*first_tok) {
    return std::nullopt;
  }

  const Token last_tok = tokens.Back().value();
  for (auto begin = first_tok; begin; begin = begin->DerivedLocation()) {
    const auto macro_tok = begin->MacroLocation();

    // Does the token have an associated macro location?
    if (!macro_tok) {
      continue;
    }

    const auto parent = macro_tok->Parent();
    // Does this macro location have a parent?
    if (parent.has_value() &&
        // Is this parent a macro argument?
        parent->Kind() == MacroKind::kArgument &&
        // Is the last token derived from this argument as well?
        last_tok.IsDerivedFromMacro(*parent)) {
      return MacroArgument::From(parent.value());
    }
  }
  return std::nullopt;
}

// Returns the lowest macro argument that covers this Stmt, if any.
std::optional<MacroArgument>
Stmt::LowestCoveringMacroArgument(void) const noexcept {
  // Algorithm:
  // 1. Walk down the Stmt's begin token's derivation tree until we reach a
  //    token that was expanded from a macro argument, and is the first token
  //    expanded from that argument. The Stmt aligns in the front with this
  //    macro argument.
  // 2. If we find such a macro argument, then walk down the Stmt's end token's
  //    derivation tree until we reach a token that was expanded from a macro
  //    argument, and is the last token expanded from that argument. The Stmt
  //    aligns in the back with this macro argument. One extra wrinkle is that,
  //    if while walking the end token's derivation tree we ever reach a point
  //    where the begin token and end token are derived from the same token,
  //    then we have to also check that the begin and end token are the same;
  //    otherwise we must stop checking for back alignment at this point because
  //    the begin and end tokens derivation trees have mixed and may fall under
  //    the same macro argument, even though the begin and end tokens do not
  //    actually expand from the same argument.
  // 3. If we cannot find a back-aligned macro argument, then walk down the
  //    begin token's derivation tree and try to find another front-aligned
  //    macro argument.
  // 4. If we cannot find a front-aligned macro argument, then return
  //    std::nullopt.
  Token stmt_begin_tok = BeginToken(), stmt_end_tok = EndToken();

  // Check that the first token is not null
  if (!stmt_begin_tok) {
    return std::nullopt;
  }

  // Start walking down the begin token's derivation tree
  for (auto begin_tok = std::optional(stmt_begin_tok); begin_tok;
       begin_tok = begin_tok->DerivedLocation()) {
    // If the begin token maps to a macro token, then we can check if this macro
    // token was expanded from an argument.
    std::optional<Macro> begin_macro = begin_tok->MacroLocation();
    if (!begin_macro) {
      continue;
    }

    // The macro token that the begin token is associated with may have in turn
    // been expanded from another macro invocation. We handle this case by
    // walking up this macro token's expansion tree until we reach a macro
    // argument.
    for (auto begin_parent = begin_macro->Parent(); begin_parent;
         begin_parent = begin_parent->Parent()) {
      if (auto begin_subst = MacroSubstitution::From(*begin_parent)) {
        // If the macro token's parent is a macro substitution, then we need
        // to check that this macro substitution's first replacement child is
        // this macro token; otherwise this macro token is not front-aligned
        // with its parent.
        auto first_child = begin_subst->ReplacementChildren().Front();
        if (first_child != begin_macro) {
          // This macro token is not front-aligned.
          break;
        }
        // If this macro token is front-aligned with its parent, then
        // continue walking up the tree by setting the current begin token
        // to its parent.
        begin_macro = begin_parent;
        continue;
      }

      // If the front macro token was not expanded from a macro substitution, it
      // may have been expanded from another kind of macro. In order for it to
      // be front-aligned with a non-substituion macro, the front macro token
      // must align with the first token in the macro's regular children (i.e.,
      // its body).
      if (begin_macro != begin_parent->Children().Front()) {
        break;
      }

      // If this macro token was expanded from an argument, then we can now
      // check for back-alignment by following similar logic to front-alignment.
      auto begin_arg = MacroArgument::From(*begin_parent);
      if (!begin_arg) {
        continue;
      }

      for (auto end_tok = std::optional(stmt_end_tok); end_tok;
           end_tok = end_tok->DerivedLocation()) {
        // Here's the rub: If the begin and end tokens ever converge to the same
        // derived token, then their derivation trees have started mixing. This
        // can happen if two separate arguments of the macro are invocations of
        // the same macro definition. To see an example, print the macro graph
        // of the following invocation code snippet:
        //
        // #define ONE 1
        // #define ADD(x, y) x + y
        // ADD(ONE, ONE)
        //
        // This isn't a problem if the begin and end tokens were the same tokens
        // to begin with (then of course their derivation trees would be the
        // same). Otherwise we should exit early, since this mixing might cause
        // us to return a false positive.

        // NOTE(bpappas): I am fairly certain that returning here will prevent
        // false positives, but I am not sure if it will create false negatives.
        if (begin_tok == end_tok && stmt_begin_tok != stmt_end_tok) {
          break;
        }
        std::optional<Macro> end_macro = end_tok->MacroLocation();
        if (!end_macro) {
          continue;
        }

        for (auto end_parent = end_macro->Parent(); end_parent;
             end_parent = end_parent->Parent()) {

          if (auto end_subst = MacroSubstitution::From(*end_parent)) {
            auto last_child = end_subst->ReplacementChildren().Back();
            if (last_child != end_macro) {
              break;
            }
            end_macro = end_parent;
            continue;
          }

          // Check that the end macro is the final macro in this parent's body
          if (end_macro != end_parent->Children().Back()) {
            break;
          }

          // Check that the parent is an argument
          auto end_arg = MacroArgument::From(*end_parent);
          if (!end_arg) {
            continue;
          }

          // Check that the argument that the beginning token aligns with the
          // back of the macro argument
          if (begin_arg == end_arg) {
            return begin_arg;
          }
        }
      }
    }
  }

  return std::nullopt;
}

// Returns the lowest macro substitution that covers this Stmt, if any.
// TODO(bpappas): This does not work if the Stmt's lowest covering substitution
// is a macro invocation passed to another macro invocation as an argument.
std::optional<Macro> Stmt::LowestCoveringSubstitution(void) const noexcept {
  const Token begin_tok = BeginToken(), end_tok = EndToken();
  const std::optional<pasta::MacroToken>
    begin_macro_tok = begin_tok.MacroLocation(),
    end_macro_tok = end_tok.MacroLocation();
  std::optional<Macro> begin_macro = std::nullopt, end_macro = std::nullopt;

  // Walk up the beginning token's expansion tree until we either reach the root
  // of the tree, or the macro that the first token was expanded from is equal
  // to the macro that the last token was expanded from.
  for (begin_macro = begin_macro_tok ? begin_macro_tok->Parent() : std::nullopt;
       begin_macro; begin_macro = begin_macro->Parent()) {
    auto begin_sub = (begin_macro
                      ? MacroSubstitution::From(*begin_macro)
                      : std::nullopt);
    auto begin_sub_first_tok = (begin_sub
                                ? begin_sub->FirstFullySubstitutedToken()
                                : std::nullopt);
    // Front alignment: Check that the first token of the substitution that that
    // the first token in the Stmt was expanded from is the first token in the
    // substitution.
    if (begin_sub_first_tok && begin_tok == *begin_sub_first_tok) {
    // Walk up the ending token's expansion tree
      for (end_macro = end_macro_tok ? end_macro_tok->Parent() : std::nullopt;
           end_macro; end_macro = end_macro->Parent()) {
        auto end_sub = (end_macro
                        ? MacroSubstitution::From(*end_macro)
                        : std::nullopt);
        auto end_sub_last_tok = (end_sub
                                 ? end_sub->LastFullySubstitutedToken()
                                 : std::nullopt);
        auto end_sub_last_tok_is_semicolon =
          end_sub_last_tok && end_sub_last_tok->Kind() == TokenKind::kSemi;

        // Back alignment: Check that the last token of the substitution that
        // that the last token in the Stmt was expanded from is the last token
        // in the substitution.
        if ((end_sub_last_tok && end_tok == *end_sub_last_tok) ||
            // Heuristic for aligning expansions that end with a semicolon
            end_sub_last_tok_is_semicolon) {
          // If the beginning and ending are aligned, then all that's left to do
          // is to check that they align with the same macro.
          if (begin_macro == end_macro) {
            return begin_macro;
          }
        }
      }
    }
  }

  // Otherwise, return std::nullopt.
  return std::nullopt;
}

// Is this a field designator?
bool Designator::IsFieldDesignator(void) const noexcept {
  // Cast the void pointers to `clang::DesignatedInitExpr::Designator`
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  return design->isFieldDesignator();
}

// Is this an array designator?
bool Designator::IsArrayDesignator(void) const noexcept {
  // Cast the void pointers to `clang::DesignatedInitExpr::Designator`
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  return design->isArrayDesignator();
}

// Is this an array range designator?
bool Designator::IsArrayRangeDesignator(void) const noexcept {
  // Cast the void pointers to `clang::DesignatedInitExpr::Designator`
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  return design->isArrayRangeDesignator();
}

// Returns the FieldDecl for the designator if it is field designator
std::optional<::pasta::FieldDecl> Designator::Field(void) const noexcept {

  // Cast the void pointers to `clang::DesignatedInitExpr::Designator`
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!design->isFieldDesignator()) {
    return std::nullopt;
  }
  return DeclBuilder::Create<pasta::FieldDecl>(ast, design->getField());
}

// Returns the TokenRange for the designator.
::pasta::TokenRange Designator::Tokens(void) const noexcept {
  // Cast the void pointers to `clang::DesignatedInitExpr::Designator`
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  return ast->TokenRangeFrom(design->getSourceRange());
}

// Get the token for dot location
::pasta::Token Designator::DotToken(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!design->isFieldDesignator()) {
    // If this is not field designator; it will return empty token
    return ast->TokenAt(clang::SourceLocation());
  }
  return ast->TokenAt(design->getDotLoc());
}

// Get the token for field location
::pasta::Token Designator::FieldToken(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!design->isFieldDesignator()) {
    // If this is not a field designator; it will return empty token
    return ast->TokenAt(clang::SourceLocation());
  }
  return ast->TokenAt(design->getFieldLoc());
}

// Get the token for l-bracket location
::pasta::Token Designator::LeftBracketToken(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!(design->isArrayDesignator() || design->isArrayRangeDesignator())) {
    // If this is field designator it will return empty token
    return ast->TokenAt(clang::SourceLocation());
  }
  return ast->TokenAt(design->getLBracketLoc());
}

// Get the token for r-bracket location
::pasta::Token Designator::RightBracketToken(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!(design->isArrayDesignator() || design->isArrayRangeDesignator())) {
    // if the designator is of field type and has no right braces, it will return empty token
    return ast->TokenAt(clang::SourceLocation());
  }
  return ast->TokenAt(design->getRBracketLoc());
}

// Get the token for ellipsis location
::pasta::Token Designator::EllipsisToken(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!design->isArrayRangeDesignator()) {
    // if the designator is not an array range; it will not have ellipsis. Return empty token
    return ast->TokenAt(clang::SourceLocation());
  }
  return ast->TokenAt(design->getEllipsisLoc());
}

// Get the index for first designator expression. It will be only valid for
std::optional<unsigned> Designator::FirstExpressionIndex(void) const noexcept {
  auto design = reinterpret_cast<const clang::DesignatedInitExpr::Designator *>(spec);
  assert(design != nullptr);
  if (!(design->isArrayDesignator() || design->isArrayRangeDesignator())) {
    return std::nullopt;
  }
  return design->getFirstExprIndex();
}

#endif  // PASTA_IN_BOOTSTRAP

}  // namespace pasta
