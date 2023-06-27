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

// Returns a list of macros that align with this Stmt, if any.
std::vector<MacroSubstitution> Stmt::AlignedSubstitutions(void) const noexcept {
  // The big idea is that we want to find the all macros that aligns in the
  // front and back with the given statement. The catch is that a macro might
  // contain nested substitutions, e.g. argument expansions or nested
  // expansions. Also, we should match statements which were expanded from
  // macros containing a trailing semicolon.

  // Algorithm:
  // 1. Walk the first token's derived token chain from final expansion token to
  //    the initial macro use token.
  // 2. Walk up this token's expansion tree. If we encounter a non-substitution
  //    macro, stop traversing the expansion tree and ascend the derivation
  //    tree. If we encounter a macro substitution, check that this token is the
  //    first in the macro's replacement list. If so, the continue to the next
  //    step; otherwise keep ascending the token derivation tree. There is also
  //    an edge-case to check for: If the current token is the first token in
  //    the macro's intermediate expansion children, then we must immediately
  //    return early, because otherwise we might erroneously match a macro with
  //    one of its arguments if they share a derivation tree. For example:
  //      #define ADD(X, Y)
  //      int x = ADD(ADD(1, 2), 3)
  //    This check prevents 1 + 2 + 3 from aligning with both invocations of
  //    ADD(), and ensures that it will only align with the top-level
  //    invocation.
  // 3. Walk up the last token's derived token chain from the initial macro use
  //    token to the final macro expansion token.
  // 4. Walk up the last derived token's derivation tree. If the last token is
  //    ever derived from the same token that the first token is derived from,
  //    then exit this iteration early to avoid false positives. If we encounter
  //    a macro substitution, check that this token is the last in the macro's
  //    replacement list. Follow similar logic as when checking for
  //    front-alignment. This also where we incorporate the heuristic for
  //    aligning macros that contain semicolons. If this check succeeds, then we
  //    have found an aligned invocation.
  // 5. The algorithm ends once we have walked the first token's entire
  //    derivation chain.

  std::vector<MacroSubstitution> result;
  Token b_tok = BeginToken();
  if (!b_tok) {
    return result;
  }

  auto b_tok_deriv_chain = b_tok.DerivationChain();

  Token e_tok = EndToken();
  auto e_tok_deriv_chain = e_tok.DerivationChain();

  auto tok_after_e_tok = e_tok.NextFinalExpansionOrFileToken();
  bool semi = tok_after_e_tok && tok_after_e_tok->Kind() == TokenKind::kSemi;

  for (auto b_deriv : b_tok_deriv_chain) {
    std::optional<Macro> b_macro = b_deriv.MacroLocation();
    if (!b_macro) {
      continue;
    }

    for (auto b_parent = b_macro->Parent(); b_parent;
         b_macro = *b_parent, b_parent = b_parent->Parent()) {
      auto b_parent_sub = MacroSubstitution::From(*b_parent);
      if (!b_parent_sub) {
        break;
      }

      // Here is the first edge-case. We only allow a macro token to be the
      // first child in its parent's intermediate replacement list if the macro
      // token is a parameter substitution.
      if (auto b_parent_exp = MacroExpansion::From(*b_parent_sub)) {
        MacroRange body = b_parent_exp->IntermediateChildren();
        bool is_psub = b_macro->Kind() == MacroKind::kParameterSubstitution;
        if (b_macro == body.Front() && !is_psub) {
          return result;
        }
      }

      auto b_parent_replacement = b_parent_sub->ReplacementChildren();
      bool front_aligned = (b_macro == b_parent_replacement.Front());
      if (!front_aligned) {
        break;
      }

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
          auto e_parent_sub = MacroSubstitution::From(*e_parent);
          if (!e_parent_sub) {
            break;
          }

          if (auto e_parent_exp = MacroExpansion::From(*e_parent_sub)) {
            MacroRange body = e_parent_exp->IntermediateChildren();
            bool is_psub = e_macro->Kind() == MacroKind::kParameterSubstitution;
            if (e_macro == body.Back() && !is_psub) {
              break;
            }
          }

          auto psub_last_tok = e_parent_sub->LastFullySubstitutedToken();
          auto e_parent_replacement = e_parent_sub->ReplacementChildren();
          bool back_aligned = ((e_macro == e_parent_replacement.Back()) ||
                               (semi && tok_after_e_tok == psub_last_tok));

          if (!back_aligned) {
            break;
          }

          if (b_parent == e_parent) {
            result.push_back(*b_parent_sub);
          }
        }
      }
    }
  }

  return result;
}

bool Stmt::AlignsWith(Macro &macro) const noexcept {
  auto aligned_substitutions = AlignedSubstitutions();
  return std::any_of(aligned_substitutions.begin(), aligned_substitutions.end(),
                     [&](MacroSubstitution &sub) { return macro == sub; });
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
