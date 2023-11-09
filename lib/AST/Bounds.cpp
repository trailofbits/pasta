/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "AST.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtVisitor.h>
#include <clang/AST/TypeLoc.h>
#include <clang/AST/TypeLocVisitor.h>
#include <clang/Lex/Token.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include <algorithm>
#include <set>
#include <tuple>
#include <unordered_set>

#include "Util.h"

namespace pasta {
namespace {

// NOTE(pag): This logic needs to be kept in sync with `ASTImpl::AlignTokens`
//            and `ASTImpl::DeclBounds`.
static clang::Decl *RemapDecl(clang::Decl *decl) {
  auto end_loc = decl->getSourceRange().getEnd();
  if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl);
      cspec && cspec->getSpecializationKind() != clang::TSK_ExplicitSpecialization) {
    auto ret = cspec->getSpecializedTemplateOrPartial();
    if (ret.is<clang::ClassTemplateDecl *>()) {
      clang::RedeclarableTemplateDecl *remapped =
          ret.get<clang::ClassTemplateDecl *>();
      for (clang::RedeclarableTemplateDecl *redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
    clang::TagDecl *remapped =
        ret.get<clang::ClassTemplatePartialSpecializationDecl *>();
    for (clang::TagDecl *redecl : remapped->redecls()) {
      if (redecl->getSourceRange().getEnd() == end_loc) {
        remapped = redecl;
      }
    }
    return RemapDecl(remapped);

  }

  if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl);
      vspec && vspec->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
    auto ret = vspec->getSpecializedTemplateOrPartial();
    if (ret.is<clang::VarTemplateDecl *>()) {
      clang::RedeclarableTemplateDecl *remapped =
          ret.get<clang::VarTemplateDecl *>();
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }

    clang::VarDecl *remapped =
        ret.get<clang::VarTemplatePartialSpecializationDecl *>();
    for (auto redecl : remapped->redecls()) {
      if (redecl->getSourceRange().getEnd() == end_loc) {
        remapped = redecl;
      }
    }
    return RemapDecl(remapped);
  }

  if (auto fd = clang::dyn_cast<clang::FunctionDecl>(decl)) {
    if (clang::RedeclarableTemplateDecl *remapped =
            fd->getDescribedFunctionTemplate()) {
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
    return decl;
  }

  if (auto vd = clang::dyn_cast<clang::VarDecl>(decl)) {
    if (clang::RedeclarableTemplateDecl *remapped =
            vd->getDescribedVarTemplate()) {
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
    return decl;
  }

  if (auto ta = clang::dyn_cast<clang::TypeAliasDecl>(decl)) {
    if (clang::RedeclarableTemplateDecl *remapped =
            ta->getDescribedAliasTemplate()) {
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
  }

  return decl;
}

// The decl bounds finder exists to find the beginning and ending of
// declarations. A lot of the best information comes from `clang::TypeLoc`s,
// and some from `Stmt`s.
class DeclBoundsFinder : public clang::DeclVisitor<DeclBoundsFinder>,
                         public clang::TypeLocVisitor<DeclBoundsFinder> {
 private:
  ASTImpl &ast;
  TokenImpl * const first_tok;
  TokenImpl * const last_tok;

  std::unordered_set<clang::Decl *> seen_decls;

  TokenImpl *lower_bound{nullptr};
  TokenImpl *upper_bound{nullptr};

  clang::Decl *attr_decl{nullptr};

 public:

  TokenImpl *ScanForwardForMatching(TokenImpl *tok,
                                    clang::tok::TokenKind close_tok) {
    auto count = 0;

    for (; first_tok <= tok && tok <= last_tok; ++tok) {
      if (!tok->IsParsed()) {
        continue;
      }
      switch (auto tok_kind = tok->Kind()) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          ++count;
          break;
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          if (count) {
            --count;
          }
          if (!count) {
            if (tok_kind == close_tok) {
              return tok;
            }
          }
          break;
        default:
          break;
      }
    }

    return nullptr;
  }

  TokenImpl *ScanBackwardForMatching(TokenImpl *tok,
                                      clang::tok::TokenKind open_tok) {
    auto count = 0;

    for (; first_tok <= tok && tok <= last_tok; --tok) {
      if (!tok->IsParsed()) {
        continue;
      }
      switch (auto tok_kind = tok->Kind()) {
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          ++count;
          break;
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          if (count) {
            --count;
          }
          if (!count) {
            if (tok_kind == open_tok) {
              return tok;
            }
          }
          break;
        default:
          break;
      }
    }

    return nullptr;
  }

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  std::pair<TokenImpl *, TokenImpl *> GetMatching(TokenImpl *tok) {
    if (!tok || !tok->IsParsed()) {
      return {};
    }
    switch (auto tok_kind = tok->Kind()) {
      case clang::tok::l_paren:
      case clang::tok::l_brace:
      case clang::tok::l_square: {
        auto &matching_tok = ast.matching[tok];
        if (!matching_tok) {
          matching_tok = ScanForwardForMatching(
              tok, static_cast<clang::tok::TokenKind>(tok_kind + 1));
          assert(matching_tok->Kind() ==
                 static_cast<clang::tok::TokenKind>(tok_kind + 1));
          ast.matching.emplace(matching_tok, tok);
        }
        return {tok, matching_tok};
      }
      case clang::tok::r_paren:
      case clang::tok::r_brace:
      case clang::tok::r_square: {
        auto &matching_tok = ast.matching[tok];
        if (!matching_tok) {
          matching_tok = ScanBackwardForMatching(
              tok, static_cast<clang::tok::TokenKind>(tok_kind - 1));
          assert(matching_tok->Kind() ==
                 static_cast<clang::tok::TokenKind>(tok_kind - 1));
          ast.matching.emplace(matching_tok, tok);
        }
        return {matching_tok, tok};
      }
      default:
        (void) tok_kind;
        return {};
    }
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `TagDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  //
  // NOTE(pag): This is pretty important for pulling in trailing attributes on
  //            `TagDecl`s. We have logic in `VisitAttribute` that omits tags,
  //            so this helps.
  //
  // TODO(pag): One corner case could be a tag forward declaration, embedded in
  //            a declarator, that has a declarator. E.g. embedding the tag in
  //            a parameter declaration. I'm not sure if attributes on the tag
  //            there bind to the tag or the param, though.
  TokenImpl *FindEndOfTag(clang::TagDecl *decl, TokenImpl *tok) {

    auto can_have_l_brace = decl->isCompleteDefinition();
    auto can_have_semi = !decl->isEmbeddedInDeclarator();

    if (!can_have_l_brace && !can_have_semi) {
      return nullptr;
    }

    TokenImpl *r_brace = nullptr;
    int64_t nesting = 0;

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[1])) {
      if (!tok->IsParsed()) {
        continue;
      }
      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_brace:
          if (!can_have_l_brace) {
            return nullptr;
          }
          [[clang::fallthrough]];
        case clang::tok::l_paren:
        case clang::tok::l_square:
          ++nesting;
          break;
        case clang::tok::r_brace:
          if (!can_have_l_brace) {
            return nullptr;
          }
          --nesting;

          if (0 > nesting) {
            return r_brace;

          } else if (!nesting) {
            if (can_have_semi) {
              r_brace = tok;

            } else {
              return tok;
            }
          }
          break;

        case clang::tok::r_paren:
        case clang::tok::r_square:
          --nesting;
          if (0 > nesting) {
            return r_brace;
          }
          break;
        case clang::tok::semi:
          if (!can_have_semi) {
            return r_brace;
          } else if (!nesting) {
            return tok;
          }
          break;

        default:
          break;
      }
    }

    return r_brace;
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `FunctionDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  TokenImpl *FindEndOfFunction(clang::FunctionDecl *decl, TokenImpl *tok) {

    int64_t nesting = 0;

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[1])) {
      if (!tok->IsParsed()) {
        continue;
      }

      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_brace:
        case clang::tok::l_paren:
        case clang::tok::l_square:
          ++nesting;
          break;

        case clang::tok::r_paren:
          --nesting;
          if (0 > nesting) {
            nesting = 0;  // E.g. function returning a function pointer.
          }
          break;
        case clang::tok::r_square:
          --nesting;
          assert(0 <= nesting);
          break;

        case clang::tok::r_brace:
          --nesting;

          // TODO(pag): Check for C++ functions with try/catch bodies.
          if (!nesting) {
            return tok;
          }

          // Should have seen a semicolon first. Might have a declaration within
          // a declarator, e.g. `void foo(struct bar {} param) { body }`. We
          // start from `foo`.
          assert(0 <= nesting);
          break;

        case clang::tok::semi:
          if (!nesting) {
            return tok;
          }
          break;
        default:
          break;
      }
    }

    return tok;
  }

  bool ExpandLeadingKeyword(clang::tok::TokenKind kind,
                            bool allow_string_literal=false) {
    auto i = 0;
    if (!lower_bound) {
      return false;
    }

    if (lower_bound->Kind() == kind) {
      return false;
    }

    for (auto tok = &(lower_bound[-1]); first_tok <= tok && i < 2; --tok) {

      // Skip past unparsed tokens, without modifying our budget, `i`.
      if (!tok->IsParsed()) {
        continue;
      }

      const auto tok_kind = tok->Kind();
      if (tok_kind == kind) {
        lower_bound = tok;
        return true;
      }

      // `"C"` in `extern "C"`.
      if (allow_string_literal && tok_kind == clang::tok::string_literal) {
        ++i;
        continue;
      }

      // Whitespace / comments / end of macros.
      if (tok_kind == clang::tok::unknown || tok_kind == clang::tok::eof ||
          tok_kind == clang::tok::eod || tok_kind == clang::tok::comment) {
        continue;
      }

      // Attributes.
      if (tok_kind == clang::tok::r_paren || tok_kind == clang::tok::r_square) {
        TokenImpl *matched_end = nullptr;
        std::tie(tok, matched_end) = GetMatching(tok);
        continue;
      }

      break;
    }
    return false;
  }

  static constexpr int64_t kDefaultFindNextLimit = -1;

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *Find(
      TokenImpl *tok, clang::tok::TokenKind kind, int64_t increment,
      int64_t limit=kDefaultFindNextLimit) {

    int64_t nesting = 0;
    uint64_t real_limit = ~0u;
    if (0 < limit) {
      real_limit = static_cast<unsigned>(limit);
    }

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      if (!tok->IsParsed()) {
        continue;
      }

      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          nesting += increment;
          break;
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          nesting -= increment;
          break;
        default:
          break;
      }

      // NOTE(pag): This is a heuristic for detecting when things go "too far."
      if (tok_kind == clang::tok::kw_namespace) {
        assert(kind == clang::tok::kw_namespace ||
               tok[-1].Kind() == clang::tok::kw_using);
      }
      if (tok_kind == kind && 0 >= nesting) {
        return tok;
      }

      if (!real_limit) {
        return nullptr;
      }
      --real_limit;
    }

    return nullptr;
  }

  // Scans backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindPrev(TokenImpl *tok,
                      clang::tok::TokenKind kind,
                      int64_t limit=kDefaultFindNextLimit) {
    if (tok) {
      return Find(tok, kind, -1, limit);
    }
    return nullptr;
  }

  // Scans backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindPrev(clang::SourceLocation loc,
                      clang::tok::TokenKind kind,
                      int64_t limit=kDefaultFindNextLimit) {
    return FindPrev(ast.RawTokenAt(loc), kind, limit);
  }

  // Scans forward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(TokenImpl *tok, clang::tok::TokenKind kind,
                      int64_t limit=kDefaultFindNextLimit) {
    if (tok) {
      return Find(tok, kind, 1, limit);
    }
    return nullptr;
  }

  // Scans forward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(clang::SourceLocation loc,
                      clang::tok::TokenKind kind,
                      int64_t limit=kDefaultFindNextLimit) {
    return FindNext(ast.RawTokenAt(loc), kind, limit);
  }

  void Expand(TokenImpl *tok) {
    // Clang supports the following:
    //
    //    #pragma attribute push(__attribute__((....)), apply_to = (...))
    //    ...
    //
    // In this case, we don't want to let the locations of any of these
    // attributes influence the locations of the declarations enclosed by
    // this pragma.
    if (tok && !tok->is_in_pragma_directive) {
      lower_bound = lower_bound ? std::min(tok, lower_bound) : tok;
      upper_bound = upper_bound ? std::max(tok, upper_bound) : tok;
    }
  }

  inline void Expand(clang::SourceLocation loc) {
    if (loc.isValid()) {
      Expand(ast.RawTokenAt(loc));
    }
  }

  inline void Expand(clang::SourceRange loc) {
    Expand(loc.getBegin());
    Expand(loc.getEnd());
  }

 public:

  clang::Decl *curr_decl{nullptr};

  void Visit(clang::Decl *decl) {
    if (!seen_decls.emplace(decl).second) {
      return;
    }

    const auto tok = ast.RawTokenAt(decl->getLocation());
    if (!tok) {
      return;
    }

    const auto prev_decl = curr_decl;
    const auto prev_attr_decl = attr_decl;
    const auto prev_lower_bound = lower_bound;
    const auto prev_upper_bound = upper_bound;

    curr_decl = decl;
    lower_bound = upper_bound = tok;
    attr_decl = decl;

    if (decl->hasAttrs()) {
      for (clang::Attr *attr : decl->getAttrs()) {
        VisitAttribute(attr);
      }
    }

    this->DeclVisitor::Visit(decl);

    curr_decl = prev_decl;
    attr_decl = prev_attr_decl;

    // Reset in case we are visiting a nested decl, e.g. by way of type source
    // info. Can happen when calculating the bounds of a function whose
    // parameter or return type declarators contain another declaration.
    if (prev_lower_bound) {
      if (!lower_bound || lower_bound > prev_lower_bound) {
        lower_bound = prev_lower_bound;
      }
    }

    if (prev_upper_bound) {
      if (!upper_bound || upper_bound < prev_upper_bound) {
        upper_bound = prev_upper_bound;
      }
    }
  }

  void VisitDecl(clang::Decl *decl) {
    Expand(decl->getSourceRange());
  }

//  void VisitTranslationUnitDecl(clang::TranslationUnitDecl *) {}
//  void VisitNamespaceDecl(clang::NamespaceDecl *) {}
//  void VisitExternCContextDecl(clang::ExternCContextDecl *) {}

//  void VisitBlockDecl(clang::BlockDecl *decl) {
//    Expand(decl->getSourceRange());
//  }
//
//  void VisitObjCMethodDecl(clang::ObjCMethodDecl *decl) {
//    Expand(decl->getSourceRange());
//  }

  // TODO(pag): Deal with out-of-line methods and template shenanigans.
  void VisitCXXMethodDecl(clang::CXXMethodDecl *decl) {
    VisitCommonFunctionDecl(decl);
  }

  void VisitFunctionDecl(clang::FunctionDecl *decl) {
    VisitCommonFunctionDecl(decl);
  }

  void VisitAttribute(const clang::Attr *attr) {

    // NOTE(pag): Inherited attributes are copied from decls to redecls, so we
    //            don't want to look for a decl attribute's location from one of
    //            its redecls, as that could be very far away.
    if (!attr || attr->isImplicit() || attr->isInherited()) {
      return;
    }

    // E.g. `class [[gsl::Pointer]] StringRef`; these attributes need to
    // be after the keyword and get copied around to all / most redecls,
    // and lead to bad expansions.
    if (attr_decl && clang::isa<clang::TagDecl>(attr_decl)) {
      return;
    }

//    llvm::errs() << "syntax: " << int(attr->getSyntax()) << "\n\t";
//    attr->printPretty(llvm::errs(), *ast.printing_policy);
//    llvm::errs() << '\n';

    TokenImpl *tok = ast.RawTokenAt(attr->getLocation());
    TokenImpl *scope_tok = ast.RawTokenAt(attr->getScopeLoc());

    // Clang supports the following:
    //
    //    #pragma attribute push(__attribute__((....)), apply_to = (...))
    //    ...
    //
    // In this case, we don't want to let the locations of any of these
    // attributes influence the locations of the declarations enclosed by
    // this pragma.
    if (tok && tok->is_in_pragma_directive) {
      return;
    }
    if (scope_tok && scope_tok->is_in_pragma_directive) {
      return;
    }

    switch (attr->getSyntax()) {
      // __attribute__((...)).
      case clang::AttributeCommonInfo::AS_GNU: {
        auto kw_kind = clang::tok::TokenKind::kw___attribute;
        switch (attr->getKind()) {
          case clang::attr::AsmLabel:
            kw_kind = clang::tok::TokenKind::kw_asm;
            break;
          default:
            break;
        }
        if (auto kw = FindPrev(tok, kw_kind)) {
          Expand(kw);
        }
        break;
      }
      // [[...]]
      case clang::AttributeCommonInfo::AS_CXX11:
      case clang::AttributeCommonInfo::AS_C23: {
        if (auto punc = FindPrev(tok, clang::tok::TokenKind::l_square)) {
          Expand(punc);
          if (punc[-1].Kind() == clang::tok::TokenKind::l_square) {
            Expand(&(punc[-1]));
          }
        }
        break;
      }
      // __declspec(...).
      case clang::AttributeCommonInfo::AS_Declspec: {
        if (auto kw = FindPrev(tok, clang::tok::TokenKind::kw___declspec)) {
          Expand(kw);
        }
        break;
      }
      // [uuid("...")] class Foo
      case clang::AttributeCommonInfo::AS_Microsoft: {
        if (auto punc = FindPrev(tok, clang::tok::TokenKind::l_square)) {
          Expand(punc);
        }
        break;
      }
      // `__ptr32`, ...
      case clang::AttributeCommonInfo::AS_Keyword: {
        auto kw_kind = clang::tok::TokenKind::unknown;
        switch (attr->getKind()) {
          case clang::attr::AsmLabel:
            kw_kind = clang::tok::TokenKind::kw_asm;
            break;
          case clang::attr::Ptr32:
            kw_kind = clang::tok::TokenKind::kw___ptr32;
            break;
          case clang::attr::Ptr64:
            kw_kind = clang::tok::TokenKind::kw___ptr64;
            break;
          case clang::attr::FastCall:
            kw_kind = clang::tok::TokenKind::kw___fastcall;
            break;
          case clang::attr::StdCall:
            kw_kind = clang::tok::TokenKind::kw___stdcall;
            break;
          case clang::attr::ThisCall:
            kw_kind = clang::tok::TokenKind::kw___thiscall;
            break;
          case clang::attr::VectorCall:
            kw_kind = clang::tok::TokenKind::kw___vectorcall;
            break;
          case clang::attr::CDecl:
            kw_kind = clang::tok::TokenKind::kw___cdecl;
            break;
          case clang::attr::TypeNonNull:
            kw_kind = clang::tok::TokenKind::kw__Nonnull;
            break;
          case clang::attr::TypeNullable:
            kw_kind = clang::tok::TokenKind::kw__Nullable;
            break;
          case clang::attr::TypeNullUnspecified:
            kw_kind = clang::tok::TokenKind::kw__Null_unspecified;
            break;
          case clang::attr::TypeNullableResult:
            kw_kind = clang::tok::TokenKind::kw__Nullable_result;
            break;
          default:
            break;
        }

        // Clang supports the following:
        //
        //    _Pragma("clang assume_nonnull begin")
        //
        // It can be enabled or disabled with a feature. Keeping it enabled is
        // desirable from a static analysis perspective, because then we can
        // observe what pointers shouldn't be null. But it's a big pain from the
        // perspective of figuring out if we've found the attribute.
        int64_t find_limit = -1;
        if (kw_kind == clang::tok::TokenKind::kw__Nonnull &&
            tok && !scope_tok) {

          // We've observed that the token location at this point for parameters
          // tends to be the `*` of the pointer, so detect that.
          if (tok->Kind() == clang::tok::star) {
            break;
          }

          // For return values, e.g. typedef `pthread_t`, we don't have much to
          // go on so we invent this fudge factor of `16` as a limit for
          // finding `_Nonnull`.
          find_limit = 16;
        }

        if (auto kw = FindPrev(tok, kw_kind, find_limit)) {
          Expand(kw);
        }
        break;
      }
      default:
        break;
    }

    Expand(scope_tok);
  }

  void VisitCommonDeclaratorDecl(clang::DeclaratorDecl *) {
    // Expand to handle things like: `static const char *` or
    // `inline static constexpr`.
    for (auto changed = true; lower_bound && changed; ) {
      changed = false;
      changed = ExpandLeadingKeyword(clang::tok::kw_typeof) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_typeof_unqual) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Accum) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Fract) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Sat) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Complex) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Imaginary) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___thread) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Thread_local) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_auto) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_static) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___attribute) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___declspec) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__ExtInt) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__BitInt) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_extern, true) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_unsigned) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_signed) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_short) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_long) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_volatile) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_inline) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_const) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_constexpr) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__Noreturn) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___cdecl) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___stdcall) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___fastcall) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___thiscall) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___regcall) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___vectorcall) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___forceinline) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___kernel) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___noinline__) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___private_extern__, true) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___module_private__, true) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw___extension__, true) || changed;

      if (lower_bound <= first_tok) {
        break;
      }

      // If the previous token is a `]` or a `)`, then go find the matching one.
      // This helps us expand past leading attributes when we fail to find them.
      auto prev_tok = &(lower_bound[-1]);
      if (prev_tok->Kind() == clang::tok::r_paren ||
          prev_tok->Kind() == clang::tok::r_square) {

        // NOTE(pag): This may fail if `prev_tok` is a macro token, e.g. the
        //            `)` of a macro function call.
        if (auto matching_tok = GetMatching(prev_tok).first) {
          lower_bound = matching_tok;
          changed = true;
        }
      }
    }
  }

  void VisitCommonFunctionDecl(clang::FunctionDecl *decl) {

    if (clang::FunctionTypeLoc ftl = decl->getFunctionTypeLoc()) {
      this->TypeLocVisitor::Visit(ftl);

    } else if (clang::TypeSourceInfo *tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }

    VisitCommonDeclaratorDecl(decl);

    TokenImpl *tok_loc = ast.RawTokenAt(decl->getLocation());

    const clang::FunctionDecl *def = nullptr;
    auto body = decl->getBody(def);
    if (def == decl) {
      Expand(body->getSourceRange());

    } else if (decl->isExplicitlyDefaulted() || decl->isDeletedAsWritten() ||
               decl->isPure() || decl->hasDefiningAttr()) {

      ExpandToTrailingToken(tok_loc, clang::tok::semi);

    } else if (decl->hasSkippedBody() || decl->willHaveBody()) {
      if (tok_loc) {
        if (auto end_tok = FindEndOfFunction(decl, tok_loc);
            end_tok > upper_bound) {
          upper_bound = end_tok;
        }
      }

    } else if (!decl->doesThisDeclarationHaveABody()) {
      ExpandToTrailingToken(tok_loc, clang::tok::semi);
    }

    const ASTImpl::FunctionProto *proto = FunctionProtoFor(decl);
    if (!proto) {
      return;
    }

    if (proto->l_paren) {
      assert(lower_bound < proto->l_paren);
      assert(proto->r_paren < upper_bound);
    }
  }

  void VisitVarDecl(clang::VarDecl *decl) {
    Expand(decl->getSourceRange());

    if (decl->hasInit()) {
      Expand(decl->getInit()->getSourceRange());
    }

    // If this is an actual variable decl and not a derived type then go
    // searching for a semicolon.
    TokenImpl *tok_loc = ast.RawTokenAt(decl->getLocation());
    if (tok_loc && !decl->isImplicit() &&
        decl->getKind() == clang::Decl::Kind::Var) {
      ExpandToTrailingToken(tok_loc, clang::tok::semi);
    }

    // If it's an array then we need to expand to include the `[]`, but those
    // are only known in the `TypeLoc`.
    if (clang::TypeSourceInfo *tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        Expand(tl.getSourceRange());
      }
    }

    VisitCommonDeclaratorDecl(decl);
  }

  std::pair<TokenImpl *, TokenImpl *> SourceRangeTokens(
      clang::SourceRange range) {
    return {ast.RawTokenAt(range.getBegin()), ast.RawTokenAt(range.getEnd())};
  }

  // Get or create location information about the syntactic function prototype
  // for `func`.
  const ASTImpl::FunctionProto *FunctionProtoFor(clang::FunctionDecl *func) {
    if (auto it = ast.func_proto.find(func); it != ast.func_proto.end()) {
      return std::addressof(it->second);
    }

    ASTImpl::FunctionProto &proto = ast.func_proto[func];

    // Try to detect something like `foo_t func;` forward declarations. These
    // are present in the linux kernel. When this happens, we'll usually observe
    // a `TypedefNameType` wrapping around a `FunctionProtoType`, rather than
    // directly seeing a `FunctionProtoType`. The typedef type will be present
    // on function definitions as well, where the prototypes are fully spelled
    // out, but we want to know if this specific `func` represents the variable
    // form.
    proto.has_variable_form =
        !func->isThisDeclarationADefinition() &&
        !clang::isa<clang::FunctionProtoType>(func->getType().getTypePtr());

    auto [params_begin, params_end] =
        SourceRangeTokens(func->getParametersSourceRange());

    // If there's an ellipsis loc, then that will have influenced the parameter
    // source range, but we should never trust it, as the ellipsis location is
    // taken from the function type itself, which is subject to deduplication,
    // and thus may point to some other place.
    auto has_ellipsis = func->getEllipsisLoc().isValid();
    if (has_ellipsis) {
      params_end = nullptr;
    }

    // Get the range of the parameter list. We might need to convert these to be
    // sane.
    //
    // NOTE(pag): We use `ExpandToLeadingToken` instead of `params_begin[-1]`
    //            because we might have a macro there, e.g. `__unused` in
    //
    //                  __unused const char *msg
    //
    //            in `_os_log_verify_format_str` from XNU.
    if (params_begin && params_begin->Kind() != clang::tok::l_paren) {
      params_begin = FindPrev(params_begin, clang::tok::l_paren);
    }

    if (params_end && params_end->Kind() != clang::tok::r_paren) {
      params_end = FindNext(params_end, clang::tok::r_paren);
    }

    if (params_begin && !params_end) {
      std::tie(params_begin, params_end) = GetMatching(params_begin);
    } else if (params_end && !params_begin) {
      std::tie(params_begin, params_end) = GetMatching(params_end);
    }

    // This happens with the following code extracted from cURL:
    //
    //    struct Curl_easy {};
    //    void Curl_infof(struct Curl_easy *, const char *fmt, ...);
    //    void Curl_failf(struct Curl_easy *, const char *fmt, ...);
    //
    // The general issue ends up being the `...`, which is stored in the
    // `FunctionProtoType`, which is subject to type-based deduplication.
    if (params_begin && params_end && params_end < params_begin) {
      params_begin = nullptr;
      params_end = nullptr;
    }

    TokenImpl *func_name_tok = ast.RawTokenAt(func->getLocation());
    if (func_name_tok) {
      if (!params_begin || params_begin < func_name_tok) {
        auto next_semicolon = FindNext(func_name_tok, clang::tok::semi);
        params_begin = FindNext(func_name_tok, clang::tok::l_paren);

        // Watch out for `foo_t foo; int bar() {}`, that we don't find
        // `(` from `bar` and associate it with `foo`.
        if (next_semicolon && next_semicolon < params_begin) {
          proto.has_variable_form = true;
          params_begin = nullptr;
        }
      }
    }

    // NOTE(pag): In the XNU kernel, we've observed cases where the parameter
    //            source range is completely crazy, where the closing paren
    //            for `_os_log_verify_format_str` ends up being the closing
    //            paren for `panic`.
    TokenImpl *nearer_params_end = nullptr;
    std::tie(params_begin, nearer_params_end) = GetMatching(params_begin);
    if (nearer_params_end < params_end || !params_end) {
      params_end = nearer_params_end;
    }

    assert(!params_begin == !params_end);

    proto.l_paren = params_begin;
    proto.r_paren = params_end;

    // The ellipsis can be on its own after a comma, or directly after
    // the variable, e.g. `a, ...` vs. `a...`.
    if (has_ellipsis && params_end) {
      proto.ellipsis = FindPrev(&(params_end[-1]), clang::tok::ellipsis);
      assert(params_begin < proto.ellipsis);
    }

    auto begin_tok = params_begin;
    auto end_tok = params_begin;

    unsigned num_params = func->getNumParams();
    for (clang::ParmVarDecl *param : func->parameters()) {
      ASTImpl::BoundingTokens &param_proto = ast.bounds[param];
      proto.params.emplace_back(&param_proto);

      unsigned i = param->getFunctionScopeIndex();

      if (end_tok >= params_end) {
        continue;  // Also handles `nullptr` case.
      }

      begin_tok = &(end_tok[1]);  // Skip the `(` or the `,`.
      if ((i + 1) == num_params) {

        // The ellipsis can be on its own after a comma, or directly after
        // the variable, e.g. `a, ...` vs. `a...`.
        if (has_ellipsis) {
          assert(proto.ellipsis == FindNext(begin_tok, clang::tok::ellipsis));
          end_tok = proto.ellipsis;

        } else {
          end_tok = params_end;
        }
      } else {
        end_tok = FindNext(begin_tok, clang::tok::comma);
      }

      if (begin_tok < end_tok) {
        param_proto.first = begin_tok;
        param_proto.second = &(end_tok[-1]);
      }
    }

    return &proto;
  }

  // TODO(pag): Handle parameters from the canonical decl being injected into
  //            out-of-line methods on class templates.
  void VisitParmVarDecl(clang::ParmVarDecl *decl) {

    clang::FunctionDecl *func =
        clang::dyn_cast<clang::FunctionDecl>(decl->getDeclContext());
    if (!func) {
      return;
    }

    const ASTImpl::FunctionProto *proto = FunctionProtoFor(func);
    if (!proto) {
      return;
    }

    unsigned param_index = decl->getFunctionScopeIndex();
    assert(param_index < proto->params.size());

    // This just ends up re-reading the bounds back out of the AST.
    const ASTImpl::BoundingTokens *param_proto = proto->params[param_index];
    lower_bound = param_proto->first;
    upper_bound = param_proto->second;
  }

  TokenImpl *ExpandToLeadingToken(TokenImpl *name_tok,
                                  clang::tok::TokenKind kind) {
    if (name_tok) {
      Expand(name_tok);
      if (auto semi_tok = FindPrev(name_tok, kind)) {
        assert(semi_tok <= name_tok);
        Expand(semi_tok);
        return semi_tok;
      }
    }
    assert(false);
    return nullptr;
  }

  void ExpandToLeadingToken(clang::SourceLocation loc,
                            clang::tok::TokenKind kind) {
    ExpandToLeadingToken(ast.RawTokenAt(loc), kind);
  }

  void ExpandToTrailingToken(TokenImpl *name_tok, clang::tok::TokenKind kind) {
    if (name_tok) {
      Expand(name_tok);
      auto semi_tok = FindNext(name_tok, kind);
      if (semi_tok) {
        assert(semi_tok >= name_tok);
        Expand(semi_tok);
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }

  void ExpandToTrailingToken(clang::SourceLocation loc, clang::tok::TokenKind kind) {
    ExpandToTrailingToken(ast.RawTokenAt(loc), kind);
  }

  void VisitNamespaceDecl(clang::NamespaceDecl *decl) {
    Expand(decl->getSourceRange());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_namespace);
  }

  void VisitLinkageSpecDecl(clang::LinkageSpecDecl *decl) {
    Expand(decl->getSourceRange());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_extern);
  }

  void VisitExternCContextDecl(clang::ExternCContextDecl *decl) {
    Expand(decl->getSourceRange());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_extern);
  }

  void VisitExportDecl(clang::ExportDecl *decl) {
    Expand(decl->getSourceRange());
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_export);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }

  void VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange());
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_namespace);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }

  void VisitBaseUsingDecl(clang::BaseUsingDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange());
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_using);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }
  void VisitUsingPackDecl(clang::UsingPackDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange());
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_using);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }
  void VisitUsingDirectiveDecl(clang::UsingDirectiveDecl *decl) {
//    VisitNamedDecl(decl);
//    Expand(decl->getSourceRange());

    ExpandToLeadingToken(decl->getUsingLoc(), clang::tok::kw_using);
    ExpandToLeadingToken(decl->getNamespaceKeyLocation(), clang::tok::kw_using);
    assert(lower_bound->Kind() == clang::tok::kw_using);

    ExpandToTrailingToken(lower_bound, clang::tok::semi);
    assert(upper_bound->Kind() == clang::tok::semi);
  }

  void VisitUsingShadowDecl(clang::UsingShadowDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange());
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_using);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }

  void VisitTypedefNameDecl(clang::TypedefNameDecl *decl) {
    VisitTypeDecl(decl);
    Expand(decl->getSourceRange());
    if (auto tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
  }

  void VisitTypeAliasDecl(clang::TypeAliasDecl *decl) {
    VisitTypedefNameDecl(decl);
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_using);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);

    // Happens in `int-ll64.h` in Linux kernel. This is used to suppress
    // the `-ansi` flag with things like `unsigned long long`.
    ExpandLeadingKeyword(clang::tok::kw___extension__);
  }

  void VisitTypedefDecl(clang::TypedefDecl *decl) {
    VisitTypedefNameDecl(decl);
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_typedef);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);

    // Happens in `int-ll64.h` in Linux kernel. This is used to suppress
    // the `-ansi` flag with things like `unsigned long long`.
    ExpandLeadingKeyword(clang::tok::kw___extension__);
  }

  inline static clang::tok::TokenKind IntroducerTokenKind(
      clang::TagDecl::TagKind tk) {
    switch (tk) {
      case clang::TTK_Struct:
        return clang::tok::kw_struct;
      case clang::TTK_Interface:
        return clang::tok::kw___interface;
      case clang::TTK_Union:
        return clang::tok::kw_union;
      case clang::TTK_Class:
        return clang::tok::kw_class;
      case clang::TTK_Enum:
        return clang::tok::kw_enum;
      default:
        return {};
    }
  }

  void VisitTagDecl(clang::TagDecl *decl) {

    // Implicit classes are for things like C++ lambdas, and builtin structures
    // for things like variadic argument storage.
    if (!decl->isImplicit()) {
      auto introducer_kind = IntroducerTokenKind(decl->getTagKind());
      if (introducer_kind != clang::tok::TokenKind{}) {

        auto name_loc = ast.RawTokenAt(decl->getLocation());
        auto introducer_loc = ExpandToLeadingToken(name_loc, introducer_kind);

        if (lower_bound && introducer_loc) {
          if (lower_bound < introducer_loc && decl->isEmbeddedInDeclarator()) {
            lower_bound = introducer_loc;
          }
        } else if (introducer_loc) {
          lower_bound = introducer_loc;
        }
      }
    }

    Expand(decl->getSourceRange());

    if (auto tag_end = FindEndOfTag(decl, lower_bound)) {
      upper_bound = tag_end;
    }
  }

  void VisitTemplateDecl(clang::TemplateDecl *decl) {
    VisitNamedDecl(decl);
    if (auto templated_decl = decl->getTemplatedDecl()) {
      this->Visit(templated_decl);
    }

    if (clang::isa<clang::VarTemplateDecl>(decl) ||
        clang::isa<clang::ClassTemplateDecl>(decl)) {
      ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
    }
  }

  void VisitClassScopeFunctionSpecializationDecl(
      clang::ClassScopeFunctionSpecializationDecl *decl) {
    Expand(decl->getSourceRange());
    if (auto args = decl->getTemplateArgsAsWritten()) {
      ExpandToLeadingToken(args->getLAngleLoc(), clang::tok::kw_template);

    } else if (auto params = decl->getDescribedTemplateParams()) {
      Expand(params->getTemplateLoc());

    } else {
      ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_template);
    }
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }

  void VisitClassTemplateSpecializationDecl(
      clang::ClassTemplateSpecializationDecl *decl) {

    // One annoying thing with clang is that often the `decl->getLocation()`
    // be for a canonical decl, but the rest of the info will be for the
    // definition, so go through and try to fix up the location of this decl.

    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
    }

    VisitCXXRecordDecl(decl);
  }

  void VisitVarTemplateSpecializationDecl(
      clang::VarTemplateSpecializationDecl *decl) {
    VisitVarDecl(decl);
    Expand(decl->getSourceRange());
    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
      ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
    }
  }

  void VisitEnumConstantDecl(clang::EnumConstantDecl *decl) {
    VisitValueDecl(decl);
    Expand(decl->getSourceRange());
    if (auto expr = decl->getInitExpr()) {
      Expand(expr->getSourceRange());
    }
  }

  void VisitFieldDecl(clang::FieldDecl *decl) {
    VisitDeclaratorDecl(decl);
    Expand(decl->getSourceRange());
    if (auto init = decl->getInClassInitializer()) {
      Expand(init->getSourceRange());
    }
    if (auto bf = decl->getBitWidth()) {
      Expand(bf->getSourceRange());
    }
    if (auto tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
    VisitCommonDeclaratorDecl(decl);
  }

  void VisitTypeLoc(clang::TypeLoc loc) {
    if (auto next_loc = loc.getNextTypeLoc()) {
      this->TypeLocVisitor::Visit(next_loc);
    }
  }

  void VisitAutoTypeLoc(clang::AutoTypeLoc loc) {
    Expand(loc.getNameLoc());
    if (loc.isDecltypeAuto()) {
      Expand(loc.getRParenLoc());
    }
  }

  void VisitDecltypeTypeLoc(clang::DecltypeTypeLoc loc) {
    Expand(loc.getDecltypeLoc());
    Expand(loc.getRParenLoc());
  }

  // NOTE(pag): Don't enter the referenced expression.
  void VisitTypeOfExprTypeLoc(clang::TypeOfExprTypeLoc loc) {
    Expand(loc.getTypeofLoc());
    Expand(loc.getLParenLoc());
    Expand(loc.getRParenLoc());
  }

  // NOTE(pag): Don't enter the referenced type.
  void VisitTypeOfTypeLoc(clang::TypeOfTypeLoc loc) {
    Expand(loc.getTypeofLoc());
    Expand(loc.getLParenLoc());
    Expand(loc.getRParenLoc());
  }

  void VisitBuiltinTypeLoc(clang::BuiltinTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
  }

  void VisitTypedefTypeLoc(clang::TypedefTypeLoc loc) {
    Expand(loc.getNameLoc());
  }

  void VisitAdjustedTypeLoc(clang::AdjustedTypeLoc loc) {
    if (auto ol = loc.getOriginalLoc()) {
      this->TypeLocVisitor::Visit(ol);
    }
  }

  void VisitMacroQualifiedTypeLoc(clang::MacroQualifiedTypeLoc loc) {
    Expand(loc.getExpansionLoc());
    if (auto il = loc.getInnerLoc()) {
      this->TypeLocVisitor::Visit(il);
    }
  }

  void VisitDecayedTypeLoc(clang::DecayedTypeLoc loc) {
    if (auto ol = loc.getOriginalLoc()) {
      this->TypeLocVisitor::Visit(ol);
    }
  }

  void VisitElaboratedTypeLoc(clang::ElaboratedTypeLoc loc) {
    Expand(loc.getElaboratedKeywordLoc());
    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
    if (auto named_loc = loc.getNamedTypeLoc()) {
      this->TypeLocVisitor::Visit(named_loc);
    }
  }

  void VisitAttributedTypeLoc(clang::AttributedTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    VisitAttribute(loc.getAttr());
    if (auto ml = loc.getModifiedLoc()) {
      this->TypeLocVisitor::Visit(ml);
    }
  }

  void VisitTagTypeLoc(clang::TagTypeLoc loc) {
    Expand(loc.getNameLoc());
  }

  void VisitEnumTypeLoc(clang::EnumTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }

  void VisitRecordTypeLoc(clang::RecordTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }

  void VisitFunctionTypeLoc(clang::FunctionTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    Expand(loc.getParensRange());
    Expand(loc.getExceptionSpecRange());
    if (auto rl = loc.getReturnLoc()) {
      this->TypeLocVisitor::Visit(rl);
    }
    for (auto param : loc.getParams()) {
      if (param) {
        if (auto param_info = param->getTypeSourceInfo()) {
          if (auto pl = param_info->getTypeLoc()) {
            this->TypeLocVisitor::Visit(pl);
          }
        }
      }
    }
  }

  void VisitFunctionProtoTypeLoc(clang::FunctionProtoTypeLoc loc) {
    VisitFunctionTypeLoc(loc);
  }

  void VisitFunctionNoProtoTypeLoc(clang::FunctionNoProtoTypeLoc loc) {
    VisitFunctionTypeLoc(loc);
  }

  void VisitPointerTypeLoc(clang::PointerTypeLoc loc) {
    Expand(loc.getStarLoc());
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
  }

  void VisitMemberPointerTypeLoc(clang::MemberPointerTypeLoc loc) {
    if (auto type_info = loc.getClassTInfo()) {
      if (auto tl = type_info->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitReferenceTypeLoc(clang::ReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitLValueReferenceTypeLoc(clang::LValueReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitRValueReferenceTypeLoc(clang::RValueReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitArrayTypeLoc(clang::ArrayTypeLoc loc) {
    if (clang::Expr *size_expr = loc.getSizeExpr()) {
      Expand(size_expr->getSourceRange());
    }
    if (auto el = loc.getElementLoc()) {
      this->TypeLocVisitor::Visit(el);
    }
    Expand(loc.getBracketsRange());
  }

  void VisitConstantArrayTypeLoc(clang::ConstantArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitIncompleteArrayTypeLoc(clang::IncompleteArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitVariableArrayTypeLoc(clang::VariableArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitParenTypeLoc(clang::ParenTypeLoc loc) {
    if (auto il = loc.getInnerLoc()) {
      this->TypeLocVisitor::Visit(il);
    }
    Expand(loc.getLocalSourceRange());
  }

  void VisitInjectedClassNameTypeLoc(clang::InjectedClassNameTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
  }

  void VisitDependentNameTypeLoc(clang::DependentNameTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
  }

  void VisitDependentTemplateSpecializationTypeLoc(
      clang::DependentTemplateSpecializationTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    Expand(loc.getTemplateNameLoc());
    Expand(loc.getLAngleLoc());
    Expand(loc.getRAngleLoc());

    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
  }

  void VisitTemplateSpecializationTypeLoc(
      clang::TemplateSpecializationTypeLoc loc) {

    Expand(loc.getLocalSourceRange());
    Expand(loc.getTemplateNameLoc());
    Expand(loc.getLAngleLoc());
    Expand(loc.getRAngleLoc());
  }

  void VisitBlockPointerTypeLoc(clang::BlockPointerTypeLoc loc) {
    Expand(loc.getCaretLoc());
    this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  }

  void VisitNestedNameSpecifierLoc(clang::NestedNameSpecifierLoc loc) {

    Expand(loc.getBeginLoc());

    if (auto type_loc = loc.getTypeLoc()) {
      this->TypeLocVisitor::Visit(type_loc);
    }
  }

  DeclBoundsFinder(ASTImpl &ast_)
      : ast(ast_),
        first_tok(&(ast.tokens.front())),
        last_tok(&(ast.tokens.back())) {}

  inline void ResetState(void) {
    seen_decls.clear();
    curr_decl = nullptr;
    attr_decl = nullptr;
    lower_bound = upper_bound = nullptr;
  }

  std::pair<TokenImpl *, TokenImpl *> GetBounds(clang::Decl *decl) {
    ResetState();
    Visit(decl);
    if (!lower_bound) {
      return {};  // Probably a builtin.
    }

    for (auto t = lower_bound; t && t <= upper_bound; ++t) {
      switch (t->Kind()) {
        case clang::tok::l_paren:
        case clang::tok::l_square:
        case clang::tok::l_brace:
          if (auto [new_begin, new_end] = GetMatching(t);
             new_begin && new_end) {
            lower_bound = lower_bound ? std::min(lower_bound, new_begin) : new_begin;
            upper_bound = upper_bound ? std::max(upper_bound, new_end) : new_end;
            t = new_end;
          }
          break;
        default:
          break;
      }
    }

    while (!lower_bound->IsParsed() && lower_bound < upper_bound) {
      lower_bound = &(lower_bound[1]);
    }

    while (!upper_bound->IsParsed() && lower_bound < upper_bound) {
      upper_bound = &(upper_bound[-1]);
    }

    assert(lower_bound->IsParsed());
    assert(upper_bound->IsParsed());
    assert(lower_bound <= upper_bound);
    return {lower_bound, upper_bound};
  }
};

}  // namespace

std::pair<TokenImpl *, TokenImpl *> ASTImpl::PartitionDeclContext(
    clang::DeclContext *dc) {
  // TODO(pag): We used to have old/weird logic from early PASTA. The remapping
  //            in particular is relevant to trying to find the "original code"
  //            for some template instantiation. We are pursuing patches to
  //            obviate the need for this, so when those materialize, we can
  //            eliminate this code.
  return {&(tokens.front()), &((&(tokens.back()))[-1])};
}

// Try to return the inclusive bounds of a given declaration in terms of
// parsed tokens. This doesn't not try to expand the range to the ending
// of macro expansions.
std::pair<TokenImpl *, TokenImpl *> ASTImpl::DeclBounds(clang::Decl *decl) {
  auto &ret = bounds[decl];
  if (ret.first || decl->isImplicit()) {
    return ret;
  }

  // Handle this off-the-bat; it doesn't really conform to any other thing.
  if (clang::isa<clang::TranslationUnitDecl>(decl)) {
    ret.first = &(tokens.front());
    ret.second = &((&(tokens.back()))[-1]);  // `.back()` is `eof`.
    return ret;
  }

  // Go from specializations back to templates.
  if (auto remap_it = remapped_decls.find(decl);
      remap_it != remapped_decls.end() &&
      decl != remap_it->second) {
    ret = DeclBounds(remap_it->second);
    return ret;
  }

  ret = DeclBoundsFinder(*this).GetBounds(decl);
  return ret;
}

TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl_,
                                   std::unique_lock<std::mutex> locker) {
  auto decl = const_cast<clang::Decl *>(decl_);
  if (auto [first, last] = DeclBounds(decl); first && first <= last) {
    return TokenRange(this->shared_from_this(), first, &(last[1]));
  }

  // We might be asking for the bounds of a template specialization, so go
  // and try to find the bounds of the template itself.
  if (auto remapped_decl = RemapDecl(decl);
      remapped_decl && remapped_decl != decl) {
    bounds[decl] = DeclBounds(remapped_decl);
    return DeclTokenRange(remapped_decl, std::move(locker));
  }

  return TokenRange(this->shared_from_this());
}

// Return a token range for the bounds of a declaration.
TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl_) {
  return DeclTokenRange(decl_, std::unique_lock<std::mutex>(bounds_mutex));
}

// Figure out lexical parentage. This is an important pre-processing step
// prior to bounds calculation.
void ASTImpl::PreprocessLexicalParentage(void) {
  // TODO(pag): Lexical parentage also seems to be computed within `DeclBounds`.
  //            I moved this code over here from `AlignTokens`, as it used to
  //            be relevant to doing the whole-program alignment. Now, we do
  //            alignment at smaller granularities, and it's not clear if this
  //            matters.
}

}  // namespace pasta