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

namespace pasta {
namespace {

// The decl bounds finder exists to find the beginning and ending of
// declarations. A lot of the best information comes from `clang::TypeLoc`s,
// and some from `Stmt`s.
class DeclBoundsFinder : public clang::DeclVisitor<DeclBoundsFinder>,
                         public clang::TypeLocVisitor<DeclBoundsFinder> {
 private:
  ASTImpl &ast;

  std::unordered_set<clang::Decl *> seen_decls;

  TokenImpl *lower_bound{nullptr};
  TokenImpl *upper_bound{nullptr};

 public:

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  TokenImpl *ScanForMatching(TokenImpl *tok, int64_t increment) {

    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());
    auto count = 0;

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      switch (tok->kind) {
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
      switch (tok->kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          return {tok, ScanForMatching(tok, 1)};
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          return {ScanForMatching(tok, -1), tok};
        default:
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

    if (begin && end) {
      if (begin->Kind() == open_kind && end->Kind() == close_kind) {
        return {begin, end};
      } else {
        return {};
      }
    } else if (begin) {
      end = ScanForMatching(begin, 1);
    } else if (end) {
      begin = ScanForMatching(end, -1);
    }

    if (begin && end) {
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

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(
      TokenImpl *tok, clang::tok::TokenKind kind, int64_t increment) {

    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      if (tok->Kind() == kind) {
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
    auto [it, added] = seen_decls.emplace(decl);
    if (added) {
      if (decl->hasAttrs()) {
        for (auto attr : decl->getAttrs()) {
          VisitAttribute(attr);
        }
      }
      this->DeclVisitor::Visit(decl);
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
    if (!attr) {
      return;
    }

    switch (attr->getSyntax()) {
      // __attribute__((...)).
      case clang::AttributeCommonInfo::AS_GNU: {
        if (auto kw = FindNext(attr->getLocation(),
                               clang::tok::TokenKind::kw___attribute, -1)) {
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
  }

  void VisitCommonFunctionDecl(clang::FunctionDecl *decl) {
    if (decl->getDescribedTemplate())
    Expand(decl->getLocation());
    Expand(decl->getSourceRange());
    Expand(decl->getEllipsisLoc());
    if (auto ftl = decl->getFunctionTypeLoc()) {
      this->TypeLocVisitor::Visit(ftl);
    }

    const clang::FunctionDecl *def = nullptr;
    auto body = decl->getBody(def);
    if (def == decl) {
      Expand(body->getSourceRange());
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
    Expand(decl->getDefaultArgRange());
  }

//  void VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *) {}
//
//  // TODO(pag): Find `typedef` keyword, `;`.
//  void VisitTypedefDecl(clang::TypedefDecl *decl) {
//    VisitTypedefNameDecl(decl);
//  }
//
//  void VisitTypeAliasDecl(clang::TypeAliasDecl *decl);

//  void VisitObjCTypeParamDecl(clang::ObjCTypeParamDecl *decl);
  void VisitTypedefNameDecl(clang::TypedefNameDecl *decl) {
    Expand(decl->getSourceRange());
    if (auto tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
  }
  void VisitTagDecl(clang::TagDecl *decl) {
    Expand(decl->getSourceRange());
    if (auto outer_typedef = decl->getTypedefNameForAnonDecl()) {
      Visit(outer_typedef);
    }
  }
//  void VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
//
//  }
//  void VisitClassTemplateSpecializationDecl(
//      clang::ClassTemplateSpecializationDecl *decl);
//  void VisitClassTemplatePartialSpecializationDecl(
//      clang::ClassTemplatePartialSpecializationDecl *decl);

  void VisitEnumConstantDecl(clang::EnumConstantDecl *decl) {
    Expand(decl->getSourceRange());
    if (auto expr = decl->getInitExpr()) {
      Expand(expr->getSourceRange());
    }
  }
  void VisitFieldDecl(clang::FieldDecl *decl) {
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
      : ast(ast_) {}

  std::pair<TokenImpl *, TokenImpl *> GetBounds(clang::Decl *decl) {
    lower_bound = upper_bound = ast.RawTokenAt(decl->getLocation());
    if (!lower_bound) {
      return {};  // Probably a builtin.
    }
    Visit(decl);
    return {lower_bound, upper_bound};
  }
};

}  // namespace

// Try to return the inclusive bounds of a given declaration in terms of
// parsed tokens. This doesn't not try to expand the range to the ending
// of macro expansions.
std::pair<TokenImpl *, TokenImpl *> ASTImpl::DeclBounds(clang::Decl *decl) {
  auto &ret = bounds[decl];
  if (ret.first) {
    return ret;
  }

  TokenImpl * const first_tok = &(tokens.front());
  TokenImpl * const last_tok = &((&(tokens.back()))[-1]);  // `.back()` is `eof`.

  // Handle this off-the-bat; it doesn't really conform to any other thing.
  if (clang::isa<clang::TranslationUnitDecl>(decl)) {
    ret.first = first_tok;
    ret.second = last_tok;
    return ret;
  }

  auto find_next = [=] (TokenImpl *tok, clang::tok::TokenKind kind,
                        int64_t increment) -> TokenImpl * {
    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      if (tok->Kind() == kind) {
        return tok;
      }
    }
    return nullptr;
  };

  auto find_leading_kw = [=] (auto *decl,
                              clang::tok::TokenKind kw) -> TokenImpl * {
    if (TokenImpl *start_tok = RawTokenAt(decl->getSourceRange().getBegin())) {
      if (TokenImpl *kw_loc = find_next(start_tok, kw, -1)) {
        return kw_loc;
      }
    }
    return nullptr;
  };

  auto find_trailing_punc = [=] (auto *decl,
                                 clang::tok::TokenKind punc) -> TokenImpl * {
    if (TokenImpl *end_tok = RawTokenAt(decl->getSourceRange().getEnd());
        end_tok && end_tok->Kind() == punc) {
      return end_tok;
    }
    return nullptr;
  };

  DeclBoundsFinder finder(*this);

  // NOTE(pag): Assign just in case our top-level scanning approach doesn't.
  ret = finder.GetBounds(decl);

  clang::DeclContext *dc = decl->getLexicalDeclContext();

  std::set<TokenImpl *> lower_bounds;
  std::set<TokenImpl *> upper_bounds;

  using DeclRange = std::tuple<clang::Decl *, TokenImpl *, TokenImpl *>;
  std::vector<DeclRange> tlds;

  for (clang::Decl *tld_decl : dc->decls()) {
    switch (tld_decl->getKind()) {

      // Namespace.
      case clang::Decl::Namespace: {
        auto dd = clang::dyn_cast<clang::NamespaceDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_namespace)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        // NOTE(pag): Not added to `tlds`.
        break;
      }
      case clang::Decl::LinkageSpec: {
        auto dd = clang::dyn_cast<clang::LinkageSpecDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_extern)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        // NOTE(pag): Not added to `tlds`.
        break;
      }
      case clang::Decl::ExternCContext: {
        auto dd = clang::dyn_cast<clang::ExternCContextDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_extern)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        // NOTE(pag): Not added to `tlds`.
        break;
      }

      case clang::Decl::Typedef: {
        auto dd = clang::dyn_cast<clang::TypedefDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_typedef)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::Using: {
        auto dd = clang::dyn_cast<clang::UsingDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_using)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::UsingDirective: {
        auto dd = clang::dyn_cast<clang::UsingDirectiveDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_using)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::UsingPack: {
        auto dd = clang::dyn_cast<clang::UsingPackDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_using)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::UsingShadow: {
        auto dd = clang::dyn_cast<clang::UsingShadowDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_using)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::Export: {
        auto dd = clang::dyn_cast<clang::ExportDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_export)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto semi_loc = find_trailing_punc(dd, clang::tok::semi)) {
          dd_bounds.second = std::max(semi_loc, dd_bounds.second);
          lower_bounds.insert(semi_loc);
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::ClassTemplate: {
        auto dd = clang::dyn_cast<clang::ClassTemplateDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_template)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::ClassTemplateSpecialization: {
        auto dd = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_template)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      case clang::Decl::VarTemplate: {
        auto dd = clang::dyn_cast<clang::VarTemplateDecl>(tld_decl);
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        if (auto kw_loc = find_leading_kw(dd, clang::tok::kw_template)) {
          dd_bounds.first = std::min(kw_loc, dd_bounds.first);
          upper_bounds.insert(kw_loc);
        }
        if (auto end_tok = RawTokenAt(dd->getEndLoc())) {
          if (end_tok->Kind() == clang::tok::semi ||
              end_tok->Kind() == clang::tok::r_brace) {
            lower_bounds.insert(end_tok);
            dd_bounds.second = std::max(end_tok, dd_bounds.second);
          }
        }
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }

      default: {
        auto &dd_bounds = bounds[tld_decl];
        dd_bounds = finder.GetBounds(tld_decl);
        tlds.emplace_back(tld_decl, dd_bounds.first, dd_bounds.second);
        break;
      }
    }
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(tlds.begin(), tlds.end(),
                   [] (const DeclRange &a, const DeclRange &b) {
                     TokenImpl *a_begin = std::get<1>(a);
                     TokenImpl *b_begin = std::get<1>(b);
                     if (a_begin < b_begin) {
                       return true;
                     } else if (a_begin > b_begin) {
                       return false;
                     } else {
                       return std::get<2>(a) < std::get<2>(b);
                     }
                   });

  for (size_t i = 0u, max_i = tlds.size(); i < max_i; ) {
    const auto curr_i = i;
    auto [decl, begin_tok, end_tok] = tlds[i++];

    // Enclose over nearby decls.
    while (i < max_i) {
      auto [next_decl, next_begin_tok, next_end_tok] = tlds[i];
      if (next_end_tok <= end_tok) {
        begin_tok = std::min(begin_tok, next_begin_tok);
        end_tok = std::max(begin_tok, next_end_tok);
        ++i;

      // Doesn't close over.
      } else {
        break;
      }
    }

    // Make sure that we capture matching parents/brackets/braces.
    for (auto t = begin_tok; t < end_tok; ++t) {
      auto [new_begin, new_end] = finder.GetMatching(t);
      if (new_begin && new_end) {
        if (new_begin < begin_tok) {
          begin_tok = new_begin;
        }
        if (new_end > end_tok) {
          end_tok = new_end;
        }
        t = new_end;
      }
    }

//    auto lb = lower_bounds.upper_bound(end_tok);
//    auto ub = upper_bounds.lower_bound(begin_tok);

    for (auto j = curr_i; j < i; ++j) {
      auto [j_decl, _b, _e] = tlds[j];
      auto &b = bounds[j_decl];
      b.first = begin_tok;
      b.second = end_tok;
      lexically_containing_decl.emplace(j_decl, decl);
    }

    // TODO(pag): Integrate upper/lower bounds.
  }

  return ret;
}

// Return a token range for the bounds of a declaration.
TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl) {
  auto [first, last] = DeclBounds(const_cast<clang::Decl *>(decl));
  return TokenRange(this->shared_from_this(), first, &(last[1]));
}

}  // namespace pasta
