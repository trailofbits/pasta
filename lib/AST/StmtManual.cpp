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
#include <vector>

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

// Returns the lowest macro that covers this Stmt, if any.
std::optional<Macro> Stmt::LowestCoveringMacro(MacroKind kind) const noexcept {
  // The big idea is that we want to find the lowest macro of the specifed kind
  // that aligns in the front and back with the given statement. The catch is
  // that a macro might contain nested substitutions, e.g. argument expansions
  // or nested expansions. Also, we should match statements which were expanded
  // from macros containing a trailing semicolon.

  // Algorithm:
  // 1. To get the lowest macro, we first walk the first token's derived token
  //    chain from the initial macro use token to the final expansion token.
  // 2. Now walk up this token's expansion tree. If we encounter a macro
  //    substitution, check that this token is the first in the macro's
  //    replacement list; otherwise check if this token is the first token in
  //    the macro's body. Whichever check we do, if it fails then we keep
  //    walking up the token derivation chain, and repeat this step. If it
  //    succeeds, then we can continue to the next step.
  // 3. Walk up the last token's derived token chain from the initial macro use
  //    token to the final macro expansion token.
  // 4. Walk up the last derived token's derivation tree. If the last token is
  //    ever derived from the same token that the first token is derived from,
  //    then exit this iteration early to avoid false positives. If we encounter
  //    a macro substitution, check that this token is the last in the macro's
  //    replacement list; otherwise check if this token is the last token in the
  //    macro's body. Whichever check we do, if it fails then we keep walking up
  //    the token derivation chain, and repeat this step. To heuristically match
  //    macro substitutions containing trailing semicolons, also pass this check
  //    if the next final expansion or file token after the last token is a
  //    semicolon, and the last token in the macro's replacement list is that
  //    same semicolon. If the check succeeds, and the macro substitution that
  //    the statement's firsts token aligns with is the same as the one that the
  //    statement's last token aligns with, then return that substitution.
  // 5. If we have walked the first token's entire derivation chain and not yet
  //    found a match, then return std::nullopt.

  // Get the first (begin) token's derivation chain
  Token b_tok = BeginToken();
  if (!b_tok) {
    return std::nullopt;
  }
  auto b_tok_deriv_chain = b_tok.DerivationChain();
  std::reverse(b_tok_deriv_chain.begin(), b_tok_deriv_chain.end());

  // Get the last (end) token's derivation chain
  Token e_tok = EndToken();
  auto e_tok_deriv_chain = e_tok.DerivationChain();
  std::reverse(e_tok_deriv_chain.begin(), e_tok_deriv_chain.end());

  // Get the token after the last token for the heuristic check
  auto tok_after_e_tok = e_tok.NextFinalExpansionOrFileToken();
  bool semi = tok_after_e_tok && tok_after_e_tok->Kind() == TokenKind::kSemi;

  // Walk the first token's derivation chain
  for (auto b_deriv : b_tok_deriv_chain) {
    std::optional<Macro> b_macro = b_deriv.MacroLocation();
    // Check that the first token was expanded from a macro
    if (!b_macro) {
      continue;
    }
    // Walk up the first token's expansion tree
    for (auto b_parent = b_macro->Parent(); b_parent;
         b_macro = *b_parent, b_parent = b_parent->Parent()) {
      if (auto b_parent_sub = MacroSubstitution::From(*b_parent)) {
        // If the first token was expanded from a macro substitution, check if
        // this token is the first in its parent's replacement list
        if (b_macro != b_parent_sub->ReplacementChildren().Front()) {
          break;
        }
      } else if (b_macro != b_parent->Children().Front()) {
        // If the first token was not expanded from a macro substitution, check
        // if this token is the first in its parent's body
        break;
      }

      // Check that this substitution is the kind of substitution we are looking
      // for
      if (b_parent->Kind() != kind) {
        continue;
      }

      // By this point we can be sure that the token front-aligns with its
      // immediate parent substitution, and can start walking the end token's
      // derivation chain. We follow similar logic as when walking the front
      // token's derivation chain.
      for (auto e_deriv : e_tok_deriv_chain) {
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
        if (b_deriv == e_deriv && b_tok != e_tok) {
          break;
        }
        std::optional<Macro> e_macro = e_deriv.MacroLocation();
        if (!e_macro) {
          continue;
        }
        for (auto e_parent = e_macro->Parent(); e_parent;
             e_macro = *e_parent, e_parent = e_parent->Parent()) {
          if (auto e_parent_sub = MacroSubstitution::From(*e_parent)) {
            // Check for back alignment with a substitution
            auto parent_sub_last_tok = e_parent_sub->LastFullySubstitutedToken();
            if (!(e_macro == e_parent_sub->ReplacementChildren().Back()
                  // Heuristic check
                  || (semi && tok_after_e_tok == parent_sub_last_tok))) {
              break;
            }
          } else if (e_macro != e_parent->Children().Back()) {
            // Check for back alignment with a non-substitution
            break;
          }

          // By this point we cna be sure that the token back-aligns with its
          // immediate parent substitution. All that's left to check is if the
          // first and last tokens in the statement align with the same
          // substitution
          if (b_parent == e_parent) {
            return b_parent;
          }
        }
      }
    }
  }

  return std::nullopt;
}

// Returns a list of macros that cover this Stmt, if any.
std::vector<Macro> Stmt::CoveringMacros(void) const noexcept {
  std::vector<Macro> result;
  Token b_tok = BeginToken();
  if (!b_tok) {
    return result;
  }
  auto b_tok_deriv_chain = b_tok.DerivationChain();
  std::reverse(b_tok_deriv_chain.begin(), b_tok_deriv_chain.end());

  Token e_tok = EndToken();
  auto e_tok_deriv_chain = e_tok.DerivationChain();
  std::reverse(e_tok_deriv_chain.begin(), e_tok_deriv_chain.end());

  auto tok_after_e_tok = e_tok.NextFinalExpansionOrFileToken();
  bool semi = tok_after_e_tok && tok_after_e_tok->Kind() == TokenKind::kSemi;

  for (auto b_deriv : b_tok_deriv_chain) {
    std::optional<Macro> b_macro = b_deriv.MacroLocation();
    if (!b_macro) {
      continue;
    }
    for (auto b_parent = b_macro->Parent(); b_parent;
         b_macro = *b_parent, b_parent = b_parent->Parent()) {
      if (auto b_parent_sub = MacroSubstitution::From(*b_parent)) {
        if (b_macro != b_parent_sub->ReplacementChildren().Front()) {
          break;
        }
      } else if (b_macro != b_parent->Children().Front()) {
        break;
      }

      for (auto e_deriv : e_tok_deriv_chain) {
        if (b_deriv == e_deriv && b_tok != e_tok) {
          break;
        }
        std::optional<Macro> e_macro = e_deriv.MacroLocation();
        if (!e_macro) {
          continue;
        }
        for (auto e_parent = e_macro->Parent(); e_parent;
             e_macro = *e_parent, e_parent = e_parent->Parent()) {
          if (auto e_parent_sub = MacroSubstitution::From(*e_parent)) {
            auto parent_sub_last_tok = e_parent_sub->LastFullySubstitutedToken();
            if (!(e_macro == e_parent_sub->ReplacementChildren().Back()
                  || (semi && tok_after_e_tok == parent_sub_last_tok))) {
              break;
            }
          } else if (e_macro != e_parent->Children().Back()) {
            break;
          }

          if (b_parent == e_parent) {
            result.push_back(*b_parent);
          }
        }
      }
    }
  }

  return result;
}

// Returns true if the given macro covers this Stmt, false otherwise.
bool Stmt::CoveredBy(Macro &macro) const noexcept {
  Token b_tok = BeginToken();
  if (!b_tok) {
    return false;
  }
  auto b_tok_deriv_chain = b_tok.DerivationChain();
  std::reverse(b_tok_deriv_chain.begin(), b_tok_deriv_chain.end());

  Token e_tok = EndToken();
  auto e_tok_deriv_chain = e_tok.DerivationChain();
  std::reverse(e_tok_deriv_chain.begin(), e_tok_deriv_chain.end());

  auto tok_after_e_tok = e_tok.NextFinalExpansionOrFileToken();
  bool semi = tok_after_e_tok && tok_after_e_tok->Kind() == TokenKind::kSemi;

  for (auto b_deriv : b_tok_deriv_chain) {
    std::optional<Macro> b_macro = b_deriv.MacroLocation();
    if (!b_macro) {
      continue;
    }
    for (auto b_parent = b_macro->Parent(); b_parent;
         b_macro = *b_parent, b_parent = b_parent->Parent()) {
      if (auto b_parent_sub = MacroSubstitution::From(*b_parent)) {
        if (b_macro != b_parent_sub->ReplacementChildren().Front()) {
          break;
        }
      } else if (b_macro != b_parent->Children().Front()) {
        break;
      }

      if (*b_parent != macro) {
        continue;
      }

      for (auto e_deriv : e_tok_deriv_chain) {
        if (b_deriv == e_deriv && b_tok != e_tok) {
          break;
        }
        std::optional<Macro> e_macro = e_deriv.MacroLocation();
        if (!e_macro) {
          continue;
        }
        for (auto e_parent = e_macro->Parent(); e_parent;
             e_macro = *e_parent, e_parent = e_parent->Parent()) {
          if (auto e_parent_sub = MacroSubstitution::From(*e_parent)) {
            auto parent_sub_last_tok = e_parent_sub->LastFullySubstitutedToken();
            if (!(e_macro == e_parent_sub->ReplacementChildren().Back()
                  || (semi && tok_after_e_tok == parent_sub_last_tok))) {
              break;
            }
          } else if (e_macro != e_parent->Children().Back()) {
            break;
          }

          if (b_parent == e_parent) {
            return true;
          }
        }
      }
    }
  }

  return false;
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
