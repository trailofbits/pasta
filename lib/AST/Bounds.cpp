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

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  TokenImpl *ScanForMatching(TokenImpl *tok, int64_t increment) {
    auto count = 0;

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      switch (auto tok_kind = tok->Kind()) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          ++count;
          break;
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          --count;
          break;
        default:

          // NOTE(pag): This is a heuristic for detecting when things go
          //            "too far."
          if (tok_kind == clang::tok::kw_namespace) {
            assert(tok[-1].Kind() == clang::tok::kw_using);
          }
          continue;
      }

      if (!count) {
        return tok;
      }
    }

    return nullptr;
  }

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  std::pair<TokenImpl *, TokenImpl *> GetMatching(TokenImpl *tok) {
    if (tok) {
      switch (auto tok_kind = tok->Kind()) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square: {
          auto &matching_tok = ast.matching[tok];
          if (!matching_tok) {
            matching_tok = ScanForMatching(tok, 1);
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
            matching_tok = ScanForMatching(tok, -1);
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
    } else {
      return {};
    }
  }

  std::pair<TokenImpl *, TokenImpl *> GetMatching(clang::SourceRange range) {
    TokenImpl *begin = ast.RawTokenAt(range.getBegin());
    TokenImpl *end = ast.RawTokenAt(range.getEnd());

    clang::tok::TokenKind open_kind = clang::tok::unknown;
    clang::tok::TokenKind close_kind = clang::tok::unknown;

    if (begin) {
      const auto begin_kind = begin->Kind();
      if (begin_kind == clang::tok::l_paren) {
        close_kind = clang::tok::r_paren;
      } else if (begin_kind == clang::tok::l_brace) {
        close_kind = clang::tok::r_brace;
      } else if (begin_kind == clang::tok::l_square) {
        close_kind = clang::tok::r_square;
      } else {
        begin = nullptr;
      }
    }

    if (end) {
      const auto end_kind = end->Kind();
      if (end_kind == clang::tok::r_paren) {
        open_kind = clang::tok::l_paren;
      } else if (end_kind == clang::tok::r_brace) {
        open_kind = clang::tok::l_brace;
      } else if (end_kind == clang::tok::r_square) {
        open_kind = clang::tok::l_square;
      } else {
        end = nullptr;
      }
    }

    if (begin && !end) {
      end = GetMatching(begin).second;
    } else if (end && !begin) {
      begin = GetMatching(end).first;
    }

    if (begin && end && begin->Kind() == open_kind && end->Kind() == close_kind) {
      assert(GetMatching(begin).second == end);
      assert(GetMatching(end).first == begin);
      return {begin, end};
    }

    return {};
  }

  // Scans forward or backward, starting at `loc` and tries to identify the
  // next balanced paren, brace, or square.
  TokenImpl *ScanForMatching(clang::SourceLocation loc, int64_t increment) {
    if (auto tok = ast.RawTokenAt(loc)) {
      return ScanForMatching(tok, increment);
    } else {
      return nullptr;
    }
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `TagDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  TokenImpl *FindEndOfTag(TokenImpl *tok) {
    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());
    TokenImpl *r_brace = nullptr;
    TokenImpl *prev_tok = nullptr;
    int64_t nesting = 0;
    for (; first_tok <= tok && tok <= last_tok;
         prev_tok = tok, tok = &(tok[1])) {
      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          if (auto matching_tok = GetMatching(tok).second) {
            tok = matching_tok;
          } else {
            nesting += 1;
          }
          break;
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          nesting -= 1;
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
  TokenImpl *FindEndOfFunction(TokenImpl *tok) {
    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());
    TokenImpl *prev_tok = nullptr;
    int64_t nesting = 0;
    for (; first_tok <= tok && tok <= last_tok;
         prev_tok = tok, tok = &(tok[1])) {
      const auto tok_kind = tok->Kind();
      switch (tok_kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          if (auto matching_tok = GetMatching(tok).second) {
            tok = matching_tok;
            if (!nesting && tok->Kind() == clang::tok::r_brace) {
              return tok;
            }
          } else {
            nesting += 1;
          }
          break;
        case clang::tok::r_paren:
        case clang::tok::r_square:
          nesting -= 1;
          break;

        case clang::tok::r_brace:
          nesting -= 1;
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

  void ExpandLeadingKeyword(clang::tok::TokenKind kind) {
    auto first_tok = &(ast.tokens.front());
    auto i = 0;
    if (!lower_bound) {
      return;
    } else if (lower_bound->Kind() == kind) {
      return;
    }

    for (auto tok = &(lower_bound[-1]); first_tok <= tok && i < 2; --tok) {
      const auto tok_kind = tok->Kind();
      if (tok_kind == kind) {
        lower_bound = tok;
      } else if (tok_kind == clang::tok::string_literal) {
        ++i;
      } else if (tok_kind == clang::tok::unknown ||
                 tok_kind == clang::tok::eof ||
                 tok_kind == clang::tok::eod ||
                 tok_kind == clang::tok::comment) {
        continue;
      } else {
        return;
      }
    }
  }

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(
      TokenImpl *tok, clang::tok::TokenKind kind, int64_t increment) {

    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());
    int64_t nesting = 0;
    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
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
    }

    return nullptr;
  }

  // Scans forward or backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(clang::SourceLocation loc,
                      clang::tok::TokenKind kind, int64_t increment) {

    if (auto tok = ast.RawTokenAt(loc)) {
      return FindNext(tok, kind, increment);
    } else {
      return nullptr;
    }
  }

  void Expand(TokenImpl *tok) {
    if (tok) {
      lower_bound = std::min(tok, lower_bound);
      upper_bound = std::max(tok, upper_bound);
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
        if (auto kw = FindNext(attr->getLocation(), kw_kind, -1)) {
          Expand(kw);
        }
        break;
      }
      // [[...]]
      case clang::AttributeCommonInfo::AS_CXX11:
      case clang::AttributeCommonInfo::AS_C2x: {
        if (auto punc = FindNext(attr->getLocation(),
                                 clang::tok::TokenKind::l_square, -1)) {
          Expand(punc);
          if (punc[-1].Kind() == clang::tok::TokenKind::l_square) {
            Expand(&(punc[-1]));
          }
        }
        break;
      }
      // __declspec(...).
      case clang::AttributeCommonInfo::AS_Declspec: {
        if (auto kw = FindNext(attr->getLocation(),
                               clang::tok::TokenKind::kw___declspec, -1)) {
          Expand(kw);
        }
        break;
      }
      // [uuid("...")] class Foo
      case clang::AttributeCommonInfo::AS_Microsoft: {
        if (auto punc = FindNext(attr->getLocation(),
                                 clang::tok::TokenKind::l_square, -1)) {
          Expand(punc);
        }
        break;
      }
      default:
        break;
    }

    Expand(attr->getScopeLoc());
  }

  void VisitCommonFunctionDecl(clang::FunctionDecl *decl) {
    if (auto ftl = decl->getFunctionTypeLoc()) {
      this->TypeLocVisitor::Visit(ftl);
    }

    switch (decl->getStorageClass()) {
      case clang::StorageClass::SC_Static:
        ExpandLeadingKeyword(clang::tok::kw_static);
        break;
      case clang::StorageClass::SC_Extern:
        ExpandLeadingKeyword(clang::tok::kw_extern);
        break;
      default:
        break;
    }

    TokenImpl *tok_loc = ast.RawTokenAt(decl->getLocation());
    if (tok_loc) {
      if (auto end_tok = FindEndOfFunction(tok_loc)) {
        upper_bound = end_tok;
        return;
      }
    }

    const clang::FunctionDecl *def = nullptr;
    auto body = decl->getBody(def);
    if (def == decl) {
      Expand(body->getSourceRange());

    } else if (decl->isExplicitlyDefaulted() || decl->isDeletedAsWritten() ||
               decl->isPure() || decl->hasDefiningAttr()) {

      ExpandToTrailingToken(tok_loc, clang::tok::semi);

    } else if (decl->hasSkippedBody() || decl->willHaveBody()) {

    } else if (!decl->doesThisDeclarationHaveABody()) {
      ExpandToTrailingToken(tok_loc, clang::tok::semi);
    }
  }

  void VisitVarDecl(clang::VarDecl *decl) {
    Expand(decl->getSourceRange());
    if (decl->hasInit()) {
      Expand(decl->getInit()->getSourceRange());
    }
  }

  // TODO(pag): Handle parameters from the canonical decl being injected into
  //            out-of-line methods on class templates.
  void VisitParmVarDecl(clang::ParmVarDecl *decl) {
    Expand(decl->getSourceRange());
    if (!decl->hasInheritedDefaultArg()) {
      Expand(decl->getDefaultArgRange());
    }
  }


  TokenImpl *ExpandToLeadingToken(TokenImpl *name_tok,
                                  clang::tok::TokenKind kind) {
    if (name_tok) {
      Expand(name_tok);
      auto semi_tok = FindNext(name_tok, kind, -1);
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

  void ExpandToLeadingToken(clang::SourceLocation loc, clang::tok::TokenKind kind) {
    ExpandToLeadingToken(ast.RawTokenAt(loc), kind);
  }

  void ExpandToTrailingToken(TokenImpl *name_tok, clang::tok::TokenKind kind) {
    if (name_tok) {
      Expand(name_tok);
      auto semi_tok = FindNext(name_tok, kind, 1);
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
  }

  void VisitTypedefDecl(clang::TypedefDecl *decl) {
    VisitTypedefNameDecl(decl);
    ExpandToLeadingToken(decl->getLocation(), clang::tok::kw_typedef);
    ExpandToTrailingToken(decl->getLocation(), clang::tok::semi);
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
        if (auto tag_end = FindEndOfTag(introducer_loc)) {
          upper_bound = tag_end;
          return;
        }
      }
    }

//    // NOTE(pag): Need to handle the case of a structure defined inside of
//    //            a parameter list, or as the return type of a function, or
//    //            inside of a `sizeof`.
//    FindNextOrUnbalanced(name_loc, clang::tok::semi, 1);

    //    VisitTypeDecl(decl);
    Expand(decl->getSourceRange());
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
//    auto X = decl->getNameAsString() == "basic_streambuf";
//    auto D = [=] (const char * d) {
//      if (X) {
//        std::cerr
//            << "--------------------------- " << d << " decl="
//            << reinterpret_cast<void *>(decl) << " lower_bound="
//            << reinterpret_cast<void *>(lower_bound) << " upper_bound="
//            << reinterpret_cast<void *>(upper_bound) << '\n' ;
//        for (auto t = lower_bound; t && t <= upper_bound; ++t) {
//          std::cerr << ' ' << t->Data(ast);
//        }
//        std::cerr << "\n\n";
//      }
//    };

//    D("a");
//    D("b");
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
    seen_decls.clear();
    lower_bound = upper_bound = ast.RawTokenAt(decl->getLocation());
    if (!lower_bound) {
      return {};  // Probably a builtin.
    }

    Visit(decl);

//    for (auto t = lower_bound; t <= upper_bound; ++t) {
//      switch (t->Kind()) {
//        case clang::tok::l_paren:
//        case clang::tok::l_square:
//        case clang::tok::l_brace:
//          if (auto [_, new_end] = GetMatching(t);new_end) {
//            upper_bound = std::max(upper_bound, new_end);
//            t = new_end;
//          }
//          break;
//        default:
//          break;
//      }
//    }

    const auto orig_lower_bound = lower_bound;
    const auto orig_upper_bound = upper_bound;

    // Make sure that we capture matching parens/brackets/braces.
    for (auto t = lower_bound; t <= upper_bound; ++t) {
      if (auto [new_begin, new_end] = GetMatching(t); new_begin && new_end) {
        lower_bound = std::min(new_begin, lower_bound);
        upper_bound = std::max(new_end, upper_bound);
        t = new_end;
      }
    }

    assert(lower_bound <= orig_lower_bound);
    assert(orig_upper_bound <= upper_bound);
    (void) orig_lower_bound;
    (void) orig_upper_bound;
    return {lower_bound, upper_bound};
  }
};

}  // namespace

// Try to return the inclusive bounds of a given declaration in terms of
// parsed tokens. This doesn't not try to expand the range to the ending
// of macro expansions.
std::pair<TokenImpl *, TokenImpl *> ASTImpl::DeclBounds(clang::Decl *decl) {
  auto &ret = bounds[decl];
  if (ret.first || decl->isImplicit()) {
    return ret;
  }

  TokenImpl *first_tok = &(tokens.front());
  TokenImpl *last_tok = &((&(tokens.back()))[-1]);  // `.back()` is `eof`.

  // Handle this off-the-bat; it doesn't really conform to any other thing.
  if (clang::isa<clang::TranslationUnitDecl>(decl)) {
    ret.first = first_tok;
    ret.second = last_tok;
    return ret;
  }

  // Go from specializations back to templates.
  if (auto remap_it = remapped_decls.find(decl);
      remap_it != remapped_decls.end() &&
      decl != remap_it->second) {
    ret = DeclBounds(remap_it->second);
    return ret;
  }

  // Ask our lexical parent for their bounds.
  clang::DeclContext *dc = decl->getLexicalDeclContext();
  if (auto dc_decl = clang::dyn_cast<clang::Decl>(dc)) {

    // E.g. structure fields inside of `__va_list_tag`.
    if (dc_decl->isImplicit()) {
      return ret;
    }

    std::tie(first_tok, last_tok) = DeclBounds(dc_decl);
  }

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

  DeclBoundsFinder finder(*this);

  for (auto &[tld_decl, tld_begin, tld_end] : tlds) {
    clang::Decl *remapped_decl = tld_decl;
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
//
//  assert(ret.first <= old_bounds.first);
//  assert(old_bounds.second <= ret.second);
//  (void) old_bounds;

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

}  // namespace pasta
