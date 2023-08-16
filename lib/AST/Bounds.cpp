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

#include <iostream>

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
    } else {
      clang::TagDecl *remapped =
          ret.get<clang::ClassTemplatePartialSpecializationDecl *>();
      for (clang::TagDecl *redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }

  } else if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl);
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
    } else {
      clang::VarDecl *remapped =
          ret.get<clang::VarTemplatePartialSpecializationDecl *>();
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }

  } else if (auto fd = clang::dyn_cast<clang::FunctionDecl>(decl)) {
    if (clang::RedeclarableTemplateDecl *remapped =
            fd->getDescribedFunctionTemplate()) {
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
  } else if (auto vd = clang::dyn_cast<clang::VarDecl>(decl)) {
    if (clang::RedeclarableTemplateDecl *remapped =
            vd->getDescribedVarTemplate()) {
      for (auto redecl : remapped->redecls()) {
        if (redecl->getSourceRange().getEnd() == end_loc) {
          remapped = redecl;
        }
      }
      return RemapDecl(remapped);
    }
  } else if (auto ta = clang::dyn_cast<clang::TypeAliasDecl>(decl)) {
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

//  // Scans forward or backward, starting at `tok` and tries to identify the
//  // next balanced paren, brace, or square.
//  TokenImpl *ScanForMatching(TokenImpl *tok, int64_t increment) {
//    auto count = 0;
//
//    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
//      if (!tok->IsParsed()) {
//        continue;
//      }
//      switch (auto tok_kind = tok->Kind()) {
//        case clang::tok::l_paren:
//        case clang::tok::l_brace:
//        case clang::tok::l_square:
//          ++count;
//          break;
//        case clang::tok::r_paren:
//        case clang::tok::r_brace:
//        case clang::tok::r_square:
//          --count;
//          break;
//        default:
//
//          // NOTE(pag): This is a heuristic for detecting when things go
//          //            "too far."
//          if (tok_kind == clang::tok::kw_namespace) {
//            assert(tok[-1].Kind() == clang::tok::kw_using);
//          }
//          continue;
//      }
//
//      if (!count) {
//        return tok;
//      }
//    }
//
//    return nullptr;
//  }

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
  TokenImpl *FindEndOfTag(clang::TagDecl *decl, TokenImpl *tok) {

    auto can_have_l_brace = decl->isCompleteDefinition();
    auto can_have_semi = !decl->isEmbeddedInDeclarator();

    TokenImpl *r_brace = nullptr;
    TokenImpl *prev_tok = nullptr;
    int64_t nesting = 0;
    bool seen_colon = false;
    for (; first_tok <= tok && tok <= last_tok;
         prev_tok = tok, tok = &(tok[1])) {
//      std::cerr << "nesting=" << nesting;
//      T(tok);
//      std::cerr << '\n';
      if (!tok->IsParsed()) {
        continue;
      }
      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        // If we get to another keyword like these without being nested then
        // we're probably in an elaborated type that is a forward declaration,
        // e.g. `struct foo` in `struct foo *x; struct bar { ... } ;` is trying
        // to walk into `struct bar`.
        case clang::tok::kw_struct:
        case clang::tok::kw_union:
        case clang::tok::kw_class:
        case clang::tok::kw_enum:
        case clang::tok::kw_const:
        case clang::tok::kw_volatile:
        case clang::tok::kw_restrict:
        case clang::tok::kw_friend:
        case clang::tok::comma:
        case clang::tok::period:
        case clang::tok::amp:
        case clang::tok::ampamp:
        case clang::tok::star:
          if (!nesting && !seen_colon) {
            return nullptr;
          }
          break;
        case clang::tok::l_brace:
          if (!can_have_l_brace) {
            return nullptr;
          }
          [[clang::fallthrough]];
        case clang::tok::l_paren:
        case clang::tok::l_square:
//          if (auto matching_tok = GetMatching(tok).second) {
//            tok = matching_tok;
//          } else {
          nesting += 1;
//          }
          break;
        case clang::tok::r_brace:
          if (!can_have_l_brace) {
            return nullptr;
          }

          if (nesting) {
            nesting -= 1;
          }

          if (!nesting) {
            if (can_have_semi) {
              r_brace = tok;
            } else {
              return tok;
            }
          }
          break;

        case clang::tok::r_paren:
        case clang::tok::r_square:
          if (nesting) {
            nesting -= 1;
          }

          if (!nesting && !can_have_semi) {
            return tok;
          }
          break;
        case clang::tok::semi:
          if (!can_have_semi) {
            return nullptr;
          } else if (!nesting) {
            return tok;
          }
          break;

        case clang::tok::colon:
          seen_colon = true;
          break;
        default:
          break;
      }

      if (0 > nesting) {
        return prev_tok;
      }

      if (!nesting && clang::tok::r_brace == tok_kind) {
        r_brace = tok;
      }
    }

    if (r_brace) {
      return r_brace;
    } else {
      return prev_tok;
    }
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `FunctionDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  TokenImpl *FindEndOfFunction(clang::FunctionDecl *decl, TokenImpl *tok) {

    TokenImpl *prev_tok = nullptr;
    int64_t nesting = 0;
    for (; first_tok <= tok && tok <= last_tok;
         prev_tok = tok, tok = &(tok[1])) {
      if (!tok->IsParsed()) {
        continue;
      }
      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
//          if (auto matching_tok = GetMatching(tok).second) {
//            tok = matching_tok;
//            if (!nesting && tok_kind == clang::tok::r_brace) {
//              return tok;
//            }
//          } else {
            nesting += 1;
//          }
          break;
        case clang::tok::r_paren:
        case clang::tok::r_square:
          if (nesting) {
            nesting -= 1;
          }
          break;
        case clang::tok::r_brace:
          if (nesting) {
            nesting -= 1;
          }
          if (!nesting) {
            return tok;
          }
          break;

        case clang::tok::semi:
          if (!nesting) {
            return tok;
          }
          break;
        default:
          break;
      }

      if (0 > nesting) {
        return prev_tok;
      }
    }

    return prev_tok;
  }

  bool ExpandLeadingKeyword(clang::tok::TokenKind kind,
                            bool allow_string_literal=false) {
    auto i = 0;
    if (!lower_bound) {
      return false;
    } else if (lower_bound->Kind() == kind) {
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

      } else if (allow_string_literal &&
                 tok_kind == clang::tok::string_literal) {
        ++i;
      } else if (tok_kind == clang::tok::unknown ||
                 tok_kind == clang::tok::eof ||
                 tok_kind == clang::tok::eod ||
                 tok_kind == clang::tok::comment) {
        continue;
      } else {
        return false;
      }
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
    } else {
      return nullptr;
    }
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
    } else {
      return nullptr;
    }
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

  void Visit(clang::Decl *decl) {
    const auto prev_attr_decl = attr_decl;
    attr_decl = decl;

    auto [it, added] = seen_decls.emplace(decl);
    if (added) {
      if (decl->hasAttrs()) {
        for (clang::Attr *attr : decl->getAttrs()) {
          VisitAttribute(attr);
        }
      }
      this->DeclVisitor::Visit(decl);
    }

    attr_decl = prev_attr_decl;
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
      case clang::AttributeCommonInfo::AS_C2x: {
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

          // For return values, e.g. typedef `pthread_t`, we don't have much to
          // go on so we invent this fudge factor of `16` as a limit for
          // finding `_Nonnull`.
          } else {
            find_limit = 16;
          }
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
      changed = ExpandLeadingKeyword(clang::tok::kw_auto) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_static) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw_extern, true) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__ExtInt) || changed;
      changed = ExpandLeadingKeyword(clang::tok::kw__BitInt) || changed;
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
    }
  }

  void VisitCommonFunctionDecl(clang::FunctionDecl *decl) {
//    auto X = false; // decl->getNameAsString() == "kvm_kick_many_cpus";
//    if (X) {
//      decl->dumpColor();
//    }
    auto X = false;
//    auto all_implicit = true;
//    for (clang::ParmVarDecl *param : decl->parameters()) {
//      if (!param->isImplicit()) {
//        all_implicit = false;
//        break;
//      }
//    }
//
//    // We can declare a function like `func_t func_name;`, where `func_t` is
//    // a typedef.
//    if (all_implicit && decl->getType().getTypePtr()->isTypedefNameType()) {
//      X = true;
//    }
    auto D = [=] (const char * d) {
      (void) d;
      if (X) {
//        std::cerr
//            << "--------- " << d << " decl="
//            << reinterpret_cast<void *>(decl) << " lower_bound="
//            << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//            << reinterpret_cast<void *>(upper_bound) << " prev_kind="
//            << clang::tok::getTokenName(lower_bound[-1].Kind())
//            << " prev_role=" << int(lower_bound[-1].Role())
//            << " next_kind="
//            << clang::tok::getTokenName(upper_bound[1].Kind())
//            << " next_role=" << int(upper_bound[1].Role())
//            << '\n';
//
//        for (auto t = &(lower_bound[-1]); first_tok <= t; --t) {
//          if (t->IsParsed()) {
//            std::cerr
//                << "--------- last_parsed: "
//                << clang::tok::getTokenName(t->Kind())
//                << " role=" << int(t->Role())
//                << ' ' << t->Data(ast) << '\n';
//            break;
//          }
//        }
//
//        for (auto t = lower_bound; t && t <= upper_bound; ++t) {
//          if (t->IsParsed()) {
//            std::cerr << ' ' << t->Data(ast);
//          }
//        }
//        std::cerr << "\n\n";
      }
    };

    D("a");
    if (clang::FunctionTypeLoc ftl = decl->getFunctionTypeLoc()) {
      this->TypeLocVisitor::Visit(ftl);

    } else if (clang::TypeSourceInfo *tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }

    D("b");
    VisitCommonDeclaratorDecl(decl);

    D("c");

    TokenImpl *tok_loc = ast.RawTokenAt(decl->getLocation());
    if (tok_loc) {
      if (auto end_tok = FindEndOfFunction(decl, tok_loc)) {
        upper_bound = end_tok;
        D("d");
        return;
      }
    }

    const clang::FunctionDecl *def = nullptr;
    auto body = decl->getBody(def);
    if (def == decl) {
      Expand(body->getSourceRange());
      D("e");

    } else if (decl->isExplicitlyDefaulted() || decl->isDeletedAsWritten() ||
               decl->isPure() || decl->hasDefiningAttr()) {

      ExpandToTrailingToken(tok_loc, clang::tok::semi);
      D("f");

    } else if (decl->hasSkippedBody() || decl->willHaveBody()) {

    } else if (!decl->doesThisDeclarationHaveABody()) {
      ExpandToTrailingToken(tok_loc, clang::tok::semi);
      D("g");
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

  // TODO(pag): Handle parameters from the canonical decl being injected into
  //            out-of-line methods on class templates.
  void VisitParmVarDecl(clang::ParmVarDecl *decl) {
    Expand(decl->getSourceRange());
    if (!decl->hasInheritedDefaultArg() && decl->hasDefaultArg()) {
      Expand(decl->getDefaultArgRange());
    }

    if (decl->getName().empty()) {
      Expand(decl->getOuterLocStart());
    }

    if (clang::TypeSourceInfo *tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }

    TokenImpl *tok = ast.RawTokenAt(decl->getLocation());
    Expand(tok);

    clang::FunctionDecl *func =
        clang::dyn_cast<clang::FunctionDecl>(decl->getDeclContext());
    if (!func) {
      return;
    }

//    std::cerr << "FUNC: " << func->getName().str() << '\n';

    clang::SourceRange param_range = func->getParametersSourceRange();
    TokenImpl *params_begin = ast.RawTokenAt(param_range.getBegin());
    TokenImpl *params_end = ast.RawTokenAt(param_range.getEnd());

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

    if (TokenImpl *func_name_tok = ast.RawTokenAt(func->getLocation())) {
      if (!params_begin || params_begin < func_name_tok) {
        params_begin = FindNext(func_name_tok, clang::tok::l_paren);
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

    // Force us in-range of the parens, hopefully.
    if (params_begin && lower_bound <= params_begin) {
      lower_bound = &(params_begin[1]);
    }
    if (params_end && upper_bound >= params_end) {
      upper_bound = &(params_end[-1]);
    }

    // Out-of-range; go to backup.
    if (!(params_begin < lower_bound && upper_bound < params_end &&
          lower_bound < upper_bound)) {
      lower_bound = tok;
      upper_bound = tok;
    }

    // Unreasonable backup, clear it. Leave `lower_bound` in place from above
    // check, even if wrong. We'll hopefully fix it up below.
    if (!(params_begin <= tok && tok <= params_end)) {
      tok = nullptr;
    }

    // Try to hop through one parameter at a time, finding the ranges of the
    // parameters, until we get to the parameter we care about.
    if (!params_begin || !params_end || decl->isImplicit()) {
      return;
    }

//    std::cerr << "NAME: " << decl->getName().str() << '\n';
//
//    for (auto t = params_begin; t <= params_end; ++t) {
//      std::cerr << t->Data(ast) << ' ';
//    }
//    std::cerr << '\n';

    unsigned param_index = decl->getFunctionScopeIndex();
    unsigned num_params = func->getNumParams();
    assert(param_index < num_params);

    auto i = 0u;
    auto begin_tok = params_begin;
    auto end_tok = params_begin;
    for (; i <= param_index; ++i) {
      begin_tok = &(end_tok[1]);  // Skip the `(` or the `,`.
      if ((i + 1) == num_params) {

        // The ellipsis can be on its own after a comma, or directly after
        // the variable, e.g. `a, ...` vs. `a...`.
        if (has_ellipsis) {
          end_tok = FindNext(begin_tok, clang::tok::ellipsis);
        } else {
          end_tok = params_end;
        }
      } else {
        end_tok = FindNext(begin_tok, clang::tok::comma);
      }
      if (!end_tok) {
        return;
      }
    }

    // These should be right.
    if (begin_tok && end_tok) {
      lower_bound = begin_tok;
      upper_bound = &(end_tok[-1]);

    // If we don't have both, then try to widen the range for whichever we have.
    } else {
      if (!lower_bound || begin_tok < lower_bound) {
        lower_bound = begin_tok;
      }
      if (!upper_bound || end_tok >= upper_bound) {
        upper_bound = &(end_tok[-1]);
      }
    }

//    for (auto t = lower_bound; t <= upper_bound; ++t) {
//      std::cerr << t->Data(ast) << ' ';
//    }
//    std::cerr << "\n\n";
  }

  TokenImpl *ExpandToLeadingToken(TokenImpl *name_tok,
                                  clang::tok::TokenKind kind) {
    if (name_tok) {
      Expand(name_tok);
      auto semi_tok = FindPrev(name_tok, kind);
      if (semi_tok) {
        assert(semi_tok <= name_tok);
        Expand(semi_tok);
        return semi_tok;
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
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

  void VisitTagDecl(clang::TagDecl *decl) {

    // Implicit classes are for things like C++ lambdas.
    if (!decl->isImplicit()) {
      TokenImpl *name_loc = ast.RawTokenAt(decl->getLocation());
      TokenImpl *introducer_loc = nullptr;
      switch (decl->getTagKind()) {
        case clang::TTK_Struct:
          introducer_loc = ExpandToLeadingToken(name_loc, clang::tok::kw_struct);
          break;
        case clang::TTK_Interface:
          introducer_loc = ExpandToLeadingToken(name_loc, clang::tok::kw___interface);
          break;
        case clang::TTK_Union:
          introducer_loc = ExpandToLeadingToken(name_loc, clang::tok::kw_union);
          break;
        case clang::TTK_Class:
          introducer_loc = ExpandToLeadingToken(name_loc, clang::tok::kw_class);
          break;
        case clang::TTK_Enum:
          introducer_loc = ExpandToLeadingToken(name_loc, clang::tok::kw_enum);
          break;
      }

      if (introducer_loc) {
        if (auto tag_end = FindEndOfTag(decl, name_loc)) {
          upper_bound = tag_end;

//          std::cerr
//              << "1) lower_bound="
//              << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//              << reinterpret_cast<void *>(upper_bound) << '\n' ;
          return;
        }
      }
    }

//    // NOTE(pag): Need to handle the case of a structure defined inside of
//    //            a parameter list, or as the return type of a function, or
//    //            inside of a `sizeof`.
//    FindNextOrUnbalanced(name_loc, clang::tok::semi, 1);
//
//    std::cerr
//        << "2) lower_bound="
//        << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//        << reinterpret_cast<void *>(upper_bound) << '\n' ;
    //    VisitTypeDecl(decl);
    Expand(decl->getSourceRange());
//    std::cerr
//        << "3) lower_bound="
//        << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//        << reinterpret_cast<void *>(upper_bound) << '\n' ;
//    if (auto outer_typedef = decl->getTypedefNameForAnonDecl()) {
//      Visit(outer_typedef);
//    }
  }

  void VisitTemplateDecl(clang::TemplateDecl *decl) {
    VisitNamedDecl(decl);
    if (auto templated_decl = decl->getTemplatedDecl()) {
      this->Visit(templated_decl);
    }
//    Expand(decl->getSourceRange());  // Includes `getTemplateLoc`.
//    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_template);

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
//    Expand(decl->getSourceRange());

    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
//      D("c");

    // One annoying thing with clang is that often the `decl->getLocation()`
    // be for a canonical decl, but the rest of the info will be for the
    // definition, so go through and try to fix up the location of this decl.
    }

    VisitCXXRecordDecl(decl);
//    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_template);
//    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
  }

  void VisitVarTemplateSpecializationDecl(
      clang::VarTemplateSpecializationDecl *decl) {
    VisitVarDecl(decl);
    Expand(decl->getSourceRange());
    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
      ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
    }
//    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_template);
//    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
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

//  void VisitTemplateDecl(clang::TemplateDecl *decl);
//  void VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *decl);
//  void VisitClassTemplateDecl(clang::ClassTemplateDecl *decl);
//  void VisitVarTemplateDecl(clang::VarTemplateDecl *decl);

//  void VisitLabelDecl(clang::LabelDecl *decl);


  void VisitTypeLoc(clang::TypeLoc loc) {
    if (auto next_loc = loc.getNextTypeLoc()) {
      this->TypeLocVisitor::Visit(next_loc);
    }
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
    if (auto decl = loc.getDecl(); decl && loc.isDefinition()) {
      Visit(decl);
    }
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

  std::pair<TokenImpl *, TokenImpl *> GetBounds(clang::Decl *decl) {

    // Reset state.
    seen_decls.clear();
    attr_decl = nullptr;
    lower_bound = upper_bound = ast.RawTokenAt(decl->getLocation());

    if (!lower_bound) {
      return {};  // Probably a builtin.
    }

//    std::cerr
//        << "--------------------------- " << " decl="
//        << reinterpret_cast<void *>(decl) << " lower_bound="
//        << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//        << reinterpret_cast<void *>(upper_bound) << '\n' ;

    Visit(decl);
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

//    if (auto debug_decl = decl) {
//      std::cerr
//          << "-----------------------------------------------------\n"
//          << "decl="
//          << reinterpret_cast<void *>(decl);
//
//      if (auto nd = clang::dyn_cast<clang::NamedDecl>(decl)) {
//        std::string name;
//        llvm::raw_string_ostream name_os(name);
//        nd->getDeclName().print(name_os, *ast.printing_policy);
//        std::cerr << " name=" << name;
//      }
//
//      std::cerr
//          << " lower_bound="
//          << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//          << reinterpret_cast<void *>(upper_bound) << '\n' ;
//
//      auto T = [=] (const TokenImpl * t) {
//        if (t->IsParsed()) {
//          std::cerr << ' ' << t->Data(ast);
//        }
//      };
//
//      for (auto t = lower_bound; debug_decl && t && t <= upper_bound; ++t) {
//        T(t);
//      }
//      std::cerr << "\n\n";
//    }

    while (!lower_bound->IsParsed() && lower_bound < upper_bound) {
      lower_bound = &(lower_bound[1]);
    }

    while (!upper_bound->IsParsed() && lower_bound < upper_bound) {
      upper_bound = &(upper_bound[-1]);
    }

    assert(lower_bound->IsParsed());
    assert(upper_bound->IsParsed());

//    // Make sure that we capture matching parens/brackets/braces.
//    for (auto t = lower_bound; t <= upper_bound; ++t) {
//      if (auto [new_begin, new_end] = GetMatching(t); new_begin && new_end) {
//        lower_bound = std::min(new_begin, lower_bound);
//        upper_bound = std::max(new_end, upper_bound);
//        t = new_end;
//      }
//    }

//    std::cerr
//        << "x) decl="
//        << reinterpret_cast<void *>(decl) << " lower_bound="
//        << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//        << reinterpret_cast<void *>(upper_bound) << '\n' ;

    assert(lower_bound <= upper_bound);
    return {lower_bound, upper_bound};
  }
};

}  // namespace

std::pair<TokenImpl *, TokenImpl *> ASTImpl::PartitionDeclContext(
    clang::DeclContext *dc) {
  if (!dc) {
    return {&(tokens.front()), &((&(tokens.back()))[-1])};
  }

  // Already figured out this decl context's bounds.
  auto &ret = bounds[dc];
  if (ret.first) {
    return ret;
  }

  ret.first = &(tokens.front());
  ret.second = &((&(tokens.back()))[-1]);  // `.back()` is `eof`.

  // Ask our lexical parent for their bounds.
  auto dc_decl = clang::dyn_cast<clang::Decl>(dc);
  if (dc_decl) {

    // E.g. structure fields inside of `__va_list_tag`.
    if (dc_decl->isImplicit()) {
      return ret;
    }

    std::tie(ret.first, ret.second) = DeclBounds(dc_decl);
  }

  DeclBoundsFinder finder(*this);
//  std::set<TokenImpl *> lower_bounds;
//  std::set<TokenImpl *> upper_bounds;

  using DeclRange = std::tuple<clang::Decl *, TokenImpl *, TokenImpl *>;
  std::vector<DeclRange> tlds;

  for (clang::Decl *tld_decl : dc->decls()) {
    switch (tld_decl->getKind()) {

      case clang::Decl::TranslationUnit:
      case clang::Decl::Namespace:
      case clang::Decl::LinkageSpec:
      case clang::Decl::ExternCContext:
        continue;  // NOTE(pag): Not added to `tlds`.

//      case clang::Decl::LinkageSpec:
//        if (auto lsp = llvm::dyn_cast<clang::LinkageSpecDecl>(tld_decl);
//            !lsp->hasBraces() && !lsp->isImplicit()) {
//          tlds.emplace_back(tld_decl, nullptr, nullptr);
//        }
//        continue;

//      case clang::Decl::Export:
//      case clang::Decl::TypeAlias:
//      case clang::Decl::Typedef:
//      case clang::Decl::Using:
//      case clang::Decl::UsingDirective:
//      case clang::Decl::UsingPack:
//      case clang::Decl::UsingShadow:
//      case clang::Decl::ClassTemplate:
//      case clang::Decl::FunctionTemplate:
//      case clang::Decl::TypeAliasTemplate:
//      case clang::Decl::VarTemplate:
//      case clang::Decl::ClassTemplateSpecialization:
//      case clang::Decl::ClassTemplatePartialSpecialization:
//      case clang::Decl::VarTemplateSpecialization:
//      case clang::Decl::VarTemplatePartialSpecialization:
//      case clang::Decl::ClassScopeFunctionSpecialization: {
//        auto &dd_bounds = bounds[tld_decl];
//        dd_bounds = finder.GetBounds(tld_decl);
//        upper_bounds.insert(dd_bounds.first);
//        lower_bounds.insert(dd_bounds.second);
//        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
//        break;
//      }

      // NOTE(pag): A lot of this logic is duplicated in `AlignTokens.cpp` and
      //            is kind of in flux.
      default: {
        if (auto ftpl = clang::dyn_cast<clang::FunctionTemplateDecl>(tld_decl)) {
          for (clang::FunctionDecl *spec : ftpl->specializations()) {
            auto tsk = spec->getTemplateSpecializationKind();
            if (!IsExplicitInstantiation(tsk, false)) {
              remapped_decls.emplace(spec, tld_decl);
            }
          }

        } else if (auto ctpl = clang::dyn_cast<clang::ClassTemplateDecl>(tld_decl)) {
          for (clang::ClassTemplateSpecializationDecl *spec : ctpl->specializations()) {
            auto tsk = spec->getSpecializationKind();
            auto has_spec_or_partial = !spec->getSpecializedTemplateOrPartial().isNull();
            if (!IsExplicitInstantiation(tsk, has_spec_or_partial)) {
              remapped_decls.emplace(spec, tld_decl);
            }
          }

        } else if (auto vtpl = clang::dyn_cast<clang::VarTemplateDecl>(tld_decl)) {
          for (clang::VarTemplateSpecializationDecl *spec : vtpl->specializations()) {
            auto tsk = spec->getSpecializationKind();
            auto has_spec_or_partial = !spec->getSpecializedTemplateOrPartial().isNull();
            if (!IsExplicitInstantiation(tsk, has_spec_or_partial)) {
              remapped_decls.emplace(spec, tld_decl);
            }
          }

        } else if (auto ta = clang::dyn_cast<clang::TypeAliasDecl>(tld_decl)) {
          if (auto tatpl = ta->getDescribedAliasTemplate()) {
            remapped_decls.emplace(tld_decl, tatpl);
          }
        }

//        // Top-level specializations are ones that are explicitly fully
//        // specialized with their own definitions.
//        if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(tld_decl);
//            cspec && !clang::isa<clang::ClassTemplatePartialSpecializationDecl>(cspec)) {
//          if (cspec->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
//            remapped_decls.erase(cspec);
//          } else {
//            break;
//          }
//
//        } else if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(tld_decl);
//                   vspec && !clang::isa<clang::VarTemplatePartialSpecializationDecl>(vspec)) {
//          if (vspec->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
//            remapped_decls.erase(vspec);
//          } else {
//            break;
//          }
//        }

        if (!tld_decl->isImplicit()) {
          tlds.emplace_back(tld_decl, nullptr, nullptr);
        }
        break;
      }
    }
  }

  for (auto &[tld_decl, tld_begin, tld_end] : tlds) {
    clang::Decl *remapped_decl = tld_decl;

    auto old_tld_begin = tld_begin;
    auto old_tld_end = tld_end;

    if (auto remap_it = remapped_decls.find(tld_decl);
        remap_it != remapped_decls.end()) {
      remapped_decl = remap_it->second;
    }

    auto &dd_bounds = bounds[tld_decl];
    assert(!dd_bounds.first == !dd_bounds.second);

    if (remapped_decl == tld_decl) {
      dd_bounds = finder.GetBounds(remapped_decl);

    // Only find the bounds of the remapped thing once.
    } else {
      auto &remapped_bounds = bounds[remapped_decl];
      if (!remapped_bounds.first) {
        remapped_bounds = finder.GetBounds(remapped_decl);
      }
      dd_bounds = remapped_bounds;
    }

//    if (!(tld_decl != decl || dd_bounds == old_bounds)) {
//      std::cerr << "---------------------------\n";
//      for (auto t = dd_bounds.first; t <= dd_bounds.second; ++t) {
//        std::cerr << ' ' << t->Data(*this);
//      }
//      std::cerr << "\n\n---------------------------\n";
//      for (auto t = old_bounds.first; t <= old_bounds.second; ++t) {
//
//        std::cerr << ' ' << t->Data(*this);
//      }
//      std::cerr << '\n';
//      assert(false);
//    }
//    assert(remapped_decl != decl || dd_bounds == old_bounds);
    tld_begin = dd_bounds.first;
    tld_end = dd_bounds.second;

    // NOTE(pag): This is a heuristic assert to try to find edge cases.
//    assert((tld_end - tld_begin) < 25000);

    // The `tld_decl->getLocation()` is often wrong for template
    // specializations, so try to fix it up here first.
    auto remapped_loc = remapped_decl->getLocation();
    auto remapped_tok = RawTokenAt(remapped_loc);
    if (tld_begin <= remapped_tok && remapped_tok <= tld_end) {
      tld_decl->setLocation(remapped_loc);
    }

#ifndef NDEBUG
    // Make sure `->getLocation()` is always in range, even in the presence
    // of remappings.
    auto tok = RawTokenAt(tld_decl->getLocation());
    assert(tld_begin <= tok && tok <= tld_end);
#endif

    (void) old_tld_begin;
    (void) old_tld_end;
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(
      tlds.begin(), tlds.end(),
      [] (const DeclRange &a, const DeclRange &b) {
        TokenImpl *a_begin = std::get<1>(a);
        TokenImpl *b_begin = std::get<1>(b);
        // If `a` starts first, put it first.
        if (a_begin < b_begin) {
          return true;

        } else if (a_begin > b_begin) {
          return false;
        }

        TokenImpl *a_end = std::get<2>(a);
        TokenImpl *b_end = std::get<2>(b);

        // If `b` encloses `a`, sort `b` first.
        if (a_end < b_end) {
          return false;

        // If `a` encloses `b`, then sort `a` first.
        } else if (a_end > b_end) {
          return true;

        // Keep the relative order from `tlds`.
        } else {
          return false;
        }
      });

  for (size_t i = 0u, max_i = tlds.size(); i < max_i; ) {
    const auto curr_i = i;
    auto [tld_decl, begin_tok, end_tok] = tlds[i++];
    assert(begin_tok <= end_tok);

    // This is an implicit declaration.
    if (!begin_tok) {
      assert(tld_decl->isImplicit());
      assert(!end_tok);
      continue;
    }

    // Enclose over nearby decls.
    while (i < max_i) {
      auto [next_tld_decl, next_begin_tok, next_end_tok] = tlds[i];
      assert(next_begin_tok <= next_end_tok);

      if (next_begin_tok <= end_tok) {
        assert(begin_tok <= next_begin_tok);
        end_tok = std::max(end_tok, next_end_tok);
        ++i;

      // Doesn't close over.
      } else {
        break;
      }
    }

//    auto lb = lower_bounds.upper_bound(end_tok);
//    auto ub = upper_bounds.lower_bound(begin_tok);

    auto num_tlds = 0;
    for (auto j = curr_i; j < i; ++j) {
      auto [next_tld_decl, _b, _e] = tlds[j];
      auto &b = bounds[next_tld_decl];
      assert(begin_tok <= b.first);
      assert(b.second <= end_tok);
      b.first = begin_tok;
      b.second = end_tok;

      // Make the remapped stuff enclose as well.
      if (auto remap_it = remapped_decls.find(next_tld_decl);
          remap_it != remapped_decls.end()) {
        auto &rb = bounds[next_tld_decl];
        assert(begin_tok <= rb.first);
        assert(rb.second <= end_tok);
        rb.first = begin_tok;
        rb.second = end_tok;
      }

      lexically_containing_decl.emplace(next_tld_decl, tld_decl);
      ++num_tlds;
    }

    (void) num_tlds;
//    // NOTE(pag): This is a bit of a heuristic check.
//    if (num_tlds > 5 && !clang::isa<clang::TemplateDecl>(tld_decl)) {
////      std::cerr << "---------------------------\n";
////      for (auto t = old_bounds.first; t && t <= old_bounds.second; ++t) {
////        std::cerr << ' ' << t->Data(*this);
////      }
//      std::cerr << "\n\n---------------------------\n";
//      for (auto t = ret.first; t && t <= ret.second; ++t) {
//        std::cerr << ' ' << t->Data(*this);
//      }
//      std::cerr << "\n\n";
////      assert(false);
//    }

    // TODO(pag): Integrate upper/lower bounds.
  }

  return ret;
//
//  assert(ret.first <= old_bounds.first);
//  assert(old_bounds.second <= ret.second);
//  (void) old_bounds;
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

  auto parent_bounds = PartitionDeclContext(decl->getLexicalDeclContext());

  // Go from specializations back to templates.
  if (auto remap_it = remapped_decls.find(decl);
      remap_it != remapped_decls.end() &&
      decl != remap_it->second) {
    ret = DeclBounds(remap_it->second);
    return ret;
  }

  DeclBoundsFinder finder(*this);

  ret = finder.GetBounds(decl);

  if (ret.first && parent_bounds.first && ret.first < parent_bounds.first) {
    ret.first = parent_bounds.first;
  }
  if (ret.second && parent_bounds.second && ret.second > parent_bounds.second) {
    ret.second = parent_bounds.second;
  }

  return ret;
}

// Return a token range for the bounds of a declaration.
TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl_) {
  std::unique_lock<std::mutex> locker(bounds_mutex);

  auto decl = const_cast<clang::Decl *>(decl_);
  if (auto [first, last] = DeclBounds(decl); first && first <= last) {
    return TokenRange(this->shared_from_this(), first, &(last[1]));
  }

  // We might be asking for the bounds of a template specialization, so go
  // and try to find the bounds of the template itself.
  if (auto remapped_decl = RemapDecl(decl);
      remapped_decl && remapped_decl != decl) {
    bounds[decl] = DeclBounds(remapped_decl);
    return DeclTokenRange(remapped_decl);
  }

  return TokenRange(this->shared_from_this());
}

// Figure out lexical parentage. This is an important pre-processing step
// prior to bounds calculation.
void ASTImpl::PreprocessLexicalParentage(void) {
  std::vector<clang::Decl *> work_list;
  std::vector<clang::Decl *> tlds;
  std::unordered_set<const clang::Decl *> ignore_decls;

  work_list.push_back(tu);
  while (!work_list.empty()) {
    clang::Decl * const decl = work_list.back();
    work_list.pop_back();
    switch (decl->getKind()) {
      case clang::Decl::TranslationUnit:
      case clang::Decl::LinkageSpec:
      case clang::Decl::ExternCContext:
      case clang::Decl::Namespace:
        for (auto sub_decl : clang::Decl::castToDeclContext(decl)->decls()) {
          work_list.push_back(sub_decl);
        }
        break;

//      // If it's something like `extern "C" int foo;` then we want to treat it
//      // as top-level, otherwise, it's more like `extern "C" { ... }` and so we
//      // want to find the top-level decls in the `...`.
//      case clang::Decl::LinkageSpec:
//        if (auto lsp = llvm::dyn_cast<clang::LinkageSpecDecl>(decl);
//            !lsp->hasBraces() && !lsp->isImplicit()) {
//
//          // Compute bounds of top-level decls. This will fill out
//          // `lexically_containing_decl`.
//          (void) DeclBounds(decl);
//          tlds.push_back(decl);
//
//        } else {
//          for (auto sub_decl : clang::Decl::castToDeclContext(decl)->decls()) {
//            work_list.push_back(sub_decl);
//          }
//        }
//        break;

      default:
        if (auto ftpl = clang::dyn_cast<clang::FunctionTemplateDecl>(decl)) {
          for (clang::Decl *spec : ftpl->specializations()) {
            ignore_decls.insert(Canonicalize(spec));
          }

        } else if (auto ctpl = clang::dyn_cast<clang::ClassTemplateDecl>(decl)) {
          for (clang::Decl *spec : ctpl->specializations()) {
            ignore_decls.insert(Canonicalize(spec));
          }

        } else if (auto vtpl = clang::dyn_cast<clang::VarTemplateDecl>(decl)) {
          for (clang::Decl *spec : vtpl->specializations()) {
            ignore_decls.insert(Canonicalize(spec));
          }
        }

        if (!decl->isImplicit()) {
          // Compute bounds of top-level decls. This will fill out
          // `lexically_containing_decl`.
          (void) DeclBounds(decl);
          tlds.push_back(decl);
        }
        break;
    }
  }

  // File explicit, user-written explicit template specializations, and ignore
  // all other specializations.
  auto should_keep = [&ignore_decls] (clang::Decl *decl) {
    auto tsk = clang::TSK_Undeclared;
    bool has_spec_or_partial = false;
    if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl);
        cspec && !clang::isa<clang::ClassTemplatePartialSpecializationDecl>(cspec)) {
      tsk = cspec->getSpecializationKind();
      has_spec_or_partial = !cspec->getSpecializedTemplateOrPartial().isNull();

    } else if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl);
               vspec && !clang::isa<clang::VarTemplatePartialSpecializationDecl>(vspec)) {
      tsk = vspec->getSpecializationKind();
      has_spec_or_partial = !vspec->getSpecializedTemplateOrPartial().isNull();

    } else if (auto fdecl = clang::dyn_cast<clang::FunctionDecl>(decl)) {
      tsk = fdecl->getTemplateSpecializationKind();

    } else if (auto vdecl = clang::dyn_cast<clang::VarDecl>(decl)) {
      tsk = vdecl->getTemplateSpecializationKind();

    } else if (auto ta = clang::dyn_cast<clang::TypeAliasDecl>(decl)) {
      if (ta->getDescribedAliasTemplate()) {
        tsk = clang::TSK_ImplicitInstantiation;  // Fake it.
      }

    } else {
      has_spec_or_partial = ignore_decls.count(Canonicalize(decl));
    }

    return IsExplicitInstantiation(tsk, has_spec_or_partial);
  };

  // Strip out template specializations.
  tlds.erase(
      std::partition(tlds.begin(), tlds.end(), should_keep),
      tlds.end());

  tlds.erase(std::unique(tlds.begin(), tlds.end()), tlds.end());

  std::stable_sort(
      tlds.begin(), tlds.end(),
      [this] (clang::Decl *a, clang::Decl *b) {
        auto a_bounds = DeclBounds(a);
        auto b_bounds = DeclBounds(b);

        // If `a` starts first, put it first.
        if (a_bounds.first < b_bounds.first) {
          return true;

        } else if (a_bounds.first > b_bounds.first) {
          return false;

        // If `b` encloses `a`, sort `b` first.
        } else if (a_bounds.second < b_bounds.second) {
          return false;

        // If `a` encloses `b`, then sort `a` first.
        } else if (a_bounds.second > b_bounds.second) {
          return true;

        // Keep the relative order from `tlds`.
        } else {
          return false;
        }
      });

  std::vector<clang::Decl *> tld_group;

  for (auto tld_it = tlds.begin(), tld_end = tlds.end(); tld_it != tld_end; ) {
    clang::Decl *decl = *tld_it;
    clang::Decl *&containing_decl = lexically_containing_decl[decl];
    if (!containing_decl) {
      containing_decl = decl;
    }

    tld_group.clear();
    tld_group.push_back(containing_decl);
    for (; tld_it != tld_end; ++tld_it) {
      clang::Decl *next_decl = *tld_it;
      if (containing_decl == lexically_containing_decl[next_decl]) {
        if (next_decl != containing_decl) {
          tld_group.push_back(next_decl);
        }
      } else {
        break;
      }
    }

    assert(1u <= tld_group.size());

    // Figure out the parsed bounds. If we don't have bounds then we are
    // probably dealing with something like a namespace / linkage spec /
    // extern C, or an implicit declaration.
    (void) DeclBounds(decl);
  }
}

}  // namespace pasta
