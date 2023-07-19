/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_DECL_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclFriend.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/Frontend/CompilerInstance.h>
#include <stdexcept>
#pragma clang diagnostic pop

namespace clang {
using OMPDeclarativeDirectiveDecl = OMPDeclarativeDirective<Decl>;
using OMPDeclarativeDirectiveValueDecl = OMPDeclarativeDirective<ValueDecl>;
}  // namespace clang

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include "AST.h"
#include "Builder.h"

#define PASTA_DEFINE_BASE_OPERATORS(base, derived) \
    std::optional<class derived> derived::From(const class base &that) { \
      if (auto decl_ptr = clang::dyn_cast_or_null<clang::derived>(that.u.base)) { \
        return DeclBuilder::Create<class derived>(that.ast, decl_ptr); \
      } else { \
        return std::nullopt; \
      } \
    }

#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, that.u.Decl) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), that.u.Decl) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.Decl = that.u.Decl; \
      kind = that.kind; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      class derived new_that(std::forward<class derived>(that)); \
      ast = std::move(new_that.ast); \
      u.Decl = new_that.u.Decl; \
      kind = new_that.kind; \
      return *this; \
    }

#define PASTA_DEFINE_DECLCONTEXT_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, clang::dyn_cast<clang::derived>(that.u.Decl)) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), clang::dyn_cast<clang::derived>(that.u.Decl)) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      ast = std::move(that.ast); \
      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \
      return *this; \
    }

namespace pasta {
namespace {
// Return the PASTA `DeclKind` for a Clang `Decl`.
static DeclKind KindOfDecl(const clang::Decl *decl) {
  switch (decl->getKind()) {
#define PASTA_DECL_CASE(name) \
    case clang::Decl::name: return DeclKind::k ## name;

PASTA_FOR_EACH_DECL_IMPL(PASTA_DECL_CASE, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DECL_CASE
    default: break;
  }
  throw std::runtime_error("The unreachable has been reached");
}

static const std::string_view kKindNames[] = {
#define PASTA_DECL_KIND_NAME(name) #name ,
PASTA_FOR_EACH_DECL_IMPL(PASTA_DECL_KIND_NAME, PASTA_IGNORE_ABSTRACT)
#undef PASTA_DECL_KIND_NAME
};
}  // namespace

DeclVisitor::~DeclVisitor(void) {}

void DeclVisitor::Accept(const Decl &decl) {
  switch (decl.Kind()) {
#define PASTA_VISIT_DECL(name) \
    case DeclKind::k ## name: \
      Visit ## name ## Decl(reinterpret_cast<const name ## Decl &>(decl)); \
      break;

    PASTA_FOR_EACH_DECL_IMPL(PASTA_VISIT_DECL, PASTA_IGNORE_ABSTRACT)
#undef PASTA_VISIT_DECL
  }
}

void DeclVisitor::VisitDecl(const Decl &decl) {
  (void) decl;
}

void DeclVisitor::VisitEmptyDecl(const EmptyDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitExportDecl(const ExportDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitExternCContextDecl(const ExternCContextDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitFileScopeAsmDecl(const FileScopeAsmDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitFriendDecl(const FriendDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitFriendTemplateDecl(const FriendTemplateDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitImplicitConceptSpecializationDecl(const ImplicitConceptSpecializationDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitImportDecl(const ImportDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitLifetimeExtendedTemporaryDecl(const LifetimeExtendedTemporaryDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitLinkageSpecDecl(const LinkageSpecDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitNamedDecl(const NamedDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitNamespaceAliasDecl(const NamespaceAliasDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitNamespaceDecl(const NamespaceDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitObjCCompatibleAliasDecl(const ObjCCompatibleAliasDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitObjCContainerDecl(const ObjCContainerDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitObjCImplDecl(const ObjCImplDecl &decl) {
  VisitObjCContainerDecl(decl);
}

void DeclVisitor::VisitObjCImplementationDecl(const ObjCImplementationDecl &decl) {
  VisitObjCImplDecl(decl);
}

void DeclVisitor::VisitObjCInterfaceDecl(const ObjCInterfaceDecl &decl) {
  VisitObjCContainerDecl(decl);
}

void DeclVisitor::VisitObjCMethodDecl(const ObjCMethodDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitObjCPropertyDecl(const ObjCPropertyDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitObjCPropertyImplDecl(const ObjCPropertyImplDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitObjCProtocolDecl(const ObjCProtocolDecl &decl) {
  VisitObjCContainerDecl(decl);
}

void DeclVisitor::VisitPragmaCommentDecl(const PragmaCommentDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitPragmaDetectMismatchDecl(const PragmaDetectMismatchDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitRequiresExprBodyDecl(const RequiresExprBodyDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitStaticAssertDecl(const StaticAssertDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitTemplateDecl(const TemplateDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitTemplateTemplateParmDecl(const TemplateTemplateParmDecl &decl) {
  VisitTemplateDecl(decl);
}

void DeclVisitor::VisitTopLevelStmtDecl(const TopLevelStmtDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitTranslationUnitDecl(const TranslationUnitDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitTypeDecl(const TypeDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitTypedefNameDecl(const TypedefNameDecl &decl) {
  VisitTypeDecl(decl);
}

void DeclVisitor::VisitUnresolvedUsingIfExistsDecl(const UnresolvedUsingIfExistsDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitUnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &decl) {
  VisitTypeDecl(decl);
}

void DeclVisitor::VisitUsingDirectiveDecl(const UsingDirectiveDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitUsingPackDecl(const UsingPackDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitUsingShadowDecl(const UsingShadowDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitValueDecl(const ValueDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitOMPDeclarativeDirectiveDecl(const OMPDeclarativeDirectiveDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitOMPDeclarativeDirectiveValueDecl(const OMPDeclarativeDirectiveValueDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitAccessSpecDecl(const AccessSpecDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitBaseUsingDecl(const BaseUsingDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitBindingDecl(const BindingDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitBlockDecl(const BlockDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitBuiltinTemplateDecl(const BuiltinTemplateDecl &decl) {
  VisitTemplateDecl(decl);
}

void DeclVisitor::VisitCapturedDecl(const CapturedDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitClassScopeFunctionSpecializationDecl(const ClassScopeFunctionSpecializationDecl &decl) {
  VisitDecl(decl);
}

void DeclVisitor::VisitConceptDecl(const ConceptDecl &decl) {
  VisitTemplateDecl(decl);
}

void DeclVisitor::VisitConstructorUsingShadowDecl(const ConstructorUsingShadowDecl &decl) {
  VisitUsingShadowDecl(decl);
}

void DeclVisitor::VisitDeclaratorDecl(const DeclaratorDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitEnumConstantDecl(const EnumConstantDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitFieldDecl(const FieldDecl &decl) {
  VisitDeclaratorDecl(decl);
}

void DeclVisitor::VisitFunctionDecl(const FunctionDecl &decl) {
  VisitDeclaratorDecl(decl);
}

void DeclVisitor::VisitHLSLBufferDecl(const HLSLBufferDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitIndirectFieldDecl(const IndirectFieldDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitLabelDecl(const LabelDecl &decl) {
  VisitNamedDecl(decl);
}

void DeclVisitor::VisitMSGuidDecl(const MSGuidDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitMSPropertyDecl(const MSPropertyDecl &decl) {
  VisitDeclaratorDecl(decl);
}

void DeclVisitor::VisitNonTypeTemplateParmDecl(const NonTypeTemplateParmDecl &decl) {
  VisitDeclaratorDecl(decl);
}

void DeclVisitor::VisitOMPAllocateDecl(const OMPAllocateDecl &decl) {
  VisitOMPDeclarativeDirectiveDecl(decl);
}

void DeclVisitor::VisitOMPDeclareMapperDecl(const OMPDeclareMapperDecl &decl) {
  VisitOMPDeclarativeDirectiveValueDecl(decl);
}

void DeclVisitor::VisitOMPDeclareReductionDecl(const OMPDeclareReductionDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitOMPRequiresDecl(const OMPRequiresDecl &decl) {
  VisitOMPDeclarativeDirectiveDecl(decl);
}

void DeclVisitor::VisitOMPThreadPrivateDecl(const OMPThreadPrivateDecl &decl) {
  VisitOMPDeclarativeDirectiveDecl(decl);
}

void DeclVisitor::VisitObjCAtDefsFieldDecl(const ObjCAtDefsFieldDecl &decl) {
  VisitFieldDecl(decl);
}

void DeclVisitor::VisitObjCCategoryDecl(const ObjCCategoryDecl &decl) {
  VisitObjCContainerDecl(decl);
}

void DeclVisitor::VisitObjCCategoryImplDecl(const ObjCCategoryImplDecl &decl) {
  VisitObjCImplDecl(decl);
}

void DeclVisitor::VisitObjCIvarDecl(const ObjCIvarDecl &decl) {
  VisitFieldDecl(decl);
}

void DeclVisitor::VisitObjCTypeParamDecl(const ObjCTypeParamDecl &decl) {
  VisitTypedefNameDecl(decl);
}

void DeclVisitor::VisitRedeclarableTemplateDecl(const RedeclarableTemplateDecl &decl) {
  VisitTemplateDecl(decl);
}

void DeclVisitor::VisitTagDecl(const TagDecl &decl) {
  VisitTypeDecl(decl);
}

void DeclVisitor::VisitTemplateParamObjectDecl(const TemplateParamObjectDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitTemplateTypeParmDecl(const TemplateTypeParmDecl &decl) {
  VisitTypeDecl(decl);
}

void DeclVisitor::VisitTypeAliasDecl(const TypeAliasDecl &decl) {
  VisitTypedefNameDecl(decl);
}

void DeclVisitor::VisitTypeAliasTemplateDecl(const TypeAliasTemplateDecl &decl) {
  VisitRedeclarableTemplateDecl(decl);
}

void DeclVisitor::VisitTypedefDecl(const TypedefDecl &decl) {
  VisitTypedefNameDecl(decl);
}

void DeclVisitor::VisitUnnamedGlobalConstantDecl(const UnnamedGlobalConstantDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitUnresolvedUsingValueDecl(const UnresolvedUsingValueDecl &decl) {
  VisitValueDecl(decl);
}

void DeclVisitor::VisitUsingDecl(const UsingDecl &decl) {
  VisitBaseUsingDecl(decl);
}

void DeclVisitor::VisitUsingEnumDecl(const UsingEnumDecl &decl) {
  VisitBaseUsingDecl(decl);
}

void DeclVisitor::VisitVarDecl(const VarDecl &decl) {
  VisitDeclaratorDecl(decl);
}

void DeclVisitor::VisitVarTemplateDecl(const VarTemplateDecl &decl) {
  VisitRedeclarableTemplateDecl(decl);
}

void DeclVisitor::VisitVarTemplateSpecializationDecl(const VarTemplateSpecializationDecl &decl) {
  VisitVarDecl(decl);
}

void DeclVisitor::VisitCXXDeductionGuideDecl(const CXXDeductionGuideDecl &decl) {
  VisitFunctionDecl(decl);
}

void DeclVisitor::VisitCXXMethodDecl(const CXXMethodDecl &decl) {
  VisitFunctionDecl(decl);
}

void DeclVisitor::VisitClassTemplateDecl(const ClassTemplateDecl &decl) {
  VisitRedeclarableTemplateDecl(decl);
}

void DeclVisitor::VisitDecompositionDecl(const DecompositionDecl &decl) {
  VisitVarDecl(decl);
}

void DeclVisitor::VisitEnumDecl(const EnumDecl &decl) {
  VisitTagDecl(decl);
}

void DeclVisitor::VisitFunctionTemplateDecl(const FunctionTemplateDecl &decl) {
  VisitRedeclarableTemplateDecl(decl);
}

void DeclVisitor::VisitImplicitParamDecl(const ImplicitParamDecl &decl) {
  VisitVarDecl(decl);
}

void DeclVisitor::VisitOMPCapturedExprDecl(const OMPCapturedExprDecl &decl) {
  VisitVarDecl(decl);
}

void DeclVisitor::VisitParmVarDecl(const ParmVarDecl &decl) {
  VisitVarDecl(decl);
}

void DeclVisitor::VisitRecordDecl(const RecordDecl &decl) {
  VisitTagDecl(decl);
}

void DeclVisitor::VisitVarTemplatePartialSpecializationDecl(const VarTemplatePartialSpecializationDecl &decl) {
  VisitVarTemplateSpecializationDecl(decl);
}

void DeclVisitor::VisitCXXConstructorDecl(const CXXConstructorDecl &decl) {
  VisitCXXMethodDecl(decl);
}

void DeclVisitor::VisitCXXConversionDecl(const CXXConversionDecl &decl) {
  VisitCXXMethodDecl(decl);
}

void DeclVisitor::VisitCXXDestructorDecl(const CXXDestructorDecl &decl) {
  VisitCXXMethodDecl(decl);
}

void DeclVisitor::VisitCXXRecordDecl(const CXXRecordDecl &decl) {
  VisitRecordDecl(decl);
}

void DeclVisitor::VisitClassTemplateSpecializationDecl(const ClassTemplateSpecializationDecl &decl) {
  VisitCXXRecordDecl(decl);
}

void DeclVisitor::VisitClassTemplatePartialSpecializationDecl(const ClassTemplatePartialSpecializationDecl &decl) {
  VisitClassTemplateSpecializationDecl(decl);
}

Decl::Decl(const class DeclContext &context)
   : Decl(context.ast, clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}

Decl::Decl(class DeclContext &&context) noexcept
   : Decl(std::move(context.ast), clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}

Decl &Decl::operator=(const class DeclContext &context) {
  if (ast != context.ast) {
    ast = context.ast;
  }
  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);
  return *this;
}

Decl &Decl::operator=(class DeclContext &&context) noexcept {
  if (ast != context.ast) {
    ast = std::move(context.ast);
  }
  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);
  return *this;
}

PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, BlockDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXConstructorDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXConversionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXDeductionGuideDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXDestructorDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXMethodDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXRecordDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CapturedDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, EnumDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ExportDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ExternCContextDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, FunctionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, HLSLBufferDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, LinkageSpecDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, NamespaceDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, OMPDeclareMapperDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, OMPDeclareReductionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCCategoryDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCCategoryImplDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCContainerDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCImplDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCImplementationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCInterfaceDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCMethodDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCProtocolDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, RecordDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, RequiresExprBodyDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, TagDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, TranslationUnitDecl)

std::string_view Decl::KindName(void) const noexcept {
  return kKindNames[static_cast<unsigned>(kind)];
}

::pasta::TokenRange Decl::Tokens(void) const noexcept {
  return ast->DeclTokenRange(u.Decl);
}

::pasta::Token Decl::Token(void) const noexcept {
  clang::SourceLocation loc;
  switch (u.Decl->getKind()) {
#define ABSTRACT_DECL(DECL)
#define DECL(DERIVED, BASE) \
    case clang::Decl::DERIVED: \
      loc = (u.DERIVED ## Decl)->getLocation(); \
      break;
#include <clang/AST/DeclNodes.inc>
  }
  return ast->TokenAt(loc);
}

// 1: DeclContext::Encloses
// 1: DeclContext::Equals
// 1: DeclContext::InEnclosingNamespaceSetOf
// 1: DeclContext::ContainsDeclaration
// 1: DeclContext::ContainsDeclarationAndLoad
// 0: DeclContext::Ddiags
std::vector<::pasta::Decl> DeclContext::Declarations(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: DeclContext::
// 0: DeclContext::
// 0: DeclContext::
enum ::pasta::DeclKind DeclContext::DeclarationKind(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getDeclKind();
  return static_cast<enum ::pasta::DeclKind>(val);
}

std::string_view DeclContext::DeclarationKindName(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getDeclKindName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  throw std::runtime_error("DeclContext::DeclarationKindName can return nullptr!");
}

std::optional<::pasta::DeclContext> DeclContext::EnclosingNamespaceContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getEnclosingNamespaceContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

std::optional<::pasta::LinkageSpecDecl> DeclContext::ExternCContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getExternCContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::LinkageSpecDecl>(ast, val);
  }
}

std::optional<::pasta::BlockDecl> DeclContext::InnermostBlockDeclaration(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getInnermostBlockDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
}

std::optional<::pasta::DeclContext> DeclContext::LexicalParent(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLexicalParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

std::optional<::pasta::DeclContext> DeclContext::LookupParent(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLookupParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

// 0: DeclContext::LookupPointer
std::optional<::pasta::Decl> DeclContext::NonClosureAncestor(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getNonClosureAncestor();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

::pasta::DeclContext DeclContext::NonTransparentContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getNonTransparentContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("DeclContext::NonTransparentContext can return nullptr!");
}

std::optional<::pasta::RecordDecl> DeclContext::OuterLexicalRecordContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getOuterLexicalRecordContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
}

std::optional<::pasta::DeclContext> DeclContext::Parent(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

// 0: DeclContext::ParentASTContext
::pasta::DeclContext DeclContext::PrimaryContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getPrimaryContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("DeclContext::PrimaryContext can return nullptr!");
}

::pasta::DeclContext DeclContext::RedeclarationContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getRedeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("DeclContext::RedeclarationContext can return nullptr!");
}

bool DeclContext::HasExternalLexicalStorage(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasExternalLexicalStorage();
  return val;
}

bool DeclContext::HasExternalVisibleStorage(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasExternalVisibleStorage();
  return val;
}

bool DeclContext::HasValidDeclarationKind(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasValidDeclKind();
  return val;
}

bool DeclContext::IsClosure(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isClosure();
  return val;
}

// 1: DeclContext::IsDeclarationInLexicalTraversal
bool DeclContext::IsDependentContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isDependentContext();
  return val;
}

bool DeclContext::IsExternCContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCContext();
  return val;
}

bool DeclContext::IsExternCXXContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCXXContext();
  return val;
}

bool DeclContext::IsFileContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFileContext();
  return val;
}

bool DeclContext::IsFunctionOrMethod(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFunctionOrMethod();
  return val;
}

bool DeclContext::IsInlineNamespace(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isInlineNamespace();
  return val;
}

bool DeclContext::IsLookupContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isLookupContext();
  return val;
}

bool DeclContext::IsNamespace(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isNamespace();
  return val;
}

bool DeclContext::IsObjCContainer(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isObjCContainer();
  return val;
}

bool DeclContext::IsRecord(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isRecord();
  return val;
}

bool DeclContext::IsStdNamespace(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isStdNamespace();
  return val;
}

bool DeclContext::IsTranslationUnit(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTranslationUnit();
  return val;
}

bool DeclContext::IsTransparentContext(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTransparentContext();
  return val;
}

// 1: DeclContext::Lookup
// 0: DeclContext::Lookups
// 0: DeclContext::
// 0: DeclContext::
std::vector<::pasta::Decl> DeclContext::AlreadyLoadedDeclarations(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.noload_decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: DeclContext::
// 0: DeclContext::
// 1: DeclContext::NoloadLookups
// 0: DeclContext::
// 0: DeclContext::
bool DeclContext::ShouldUseQualifiedLookup(void) const {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.shouldUseQualifiedLookup();
  return val;
}

// 0: DeclContext::UsingDirectives
Decl::Decl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}

PASTA_DEFINE_DERIVED_OPERATORS(Decl, AccessSpecDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BaseUsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BlockDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CapturedDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ConstructorUsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EmptyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ExportDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ExternCContextDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FileScopeAsmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FriendDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FriendTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, HLSLBufferDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ImplicitConceptSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ImportDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LabelDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LinkageSpecDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamedDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamespaceAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamespaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPAllocateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPRequiresDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPThreadPrivateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCContainerDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCPropertyImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCProtocolDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, PragmaCommentDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, PragmaDetectMismatchDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RequiresExprBodyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, StaticAssertDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TopLevelStmtDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TranslationUnitDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnnamedGlobalConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingIfExistsDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingEnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingPackDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplateSpecializationDecl)
// 0: Decl::
// 0: Decl::
std::vector<::pasta::Attr> Decl::Attributes(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.attrs();
  std::vector<::pasta::Attr> ret;
  for (auto attr_ptr : val) {
    if (attr_ptr) {
      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));
    }
  }
  return ret;
}

// 1: Decl::CanBeWeakImported
// 0: Decl::ASTContext
enum AccessSpecifier Decl::Access(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAccess();
  return static_cast<::pasta::AccessSpecifier>(val);
}

std::optional<::pasta::FunctionDecl> Decl::AsFunction(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAsFunction();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

enum AvailabilityResult Decl::Availability(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAvailability();
  return static_cast<::pasta::AvailabilityResult>(val);
}

::pasta::Token Decl::BeginToken(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Decl Decl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("Decl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::DeclContext> Decl::DeclarationContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDeclContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

std::optional<::pasta::Attr> Decl::DefiningAttribute(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDefiningAttr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::Attr>(ast, val);
  }
}

std::optional<::pasta::TemplateDecl> Decl::DescribedTemplate(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
}

std::optional<::pasta::TemplateParameterList> Decl::DescribedTemplateParameters(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplateParams();
  if (!val) {
    return std::nullopt;
  }
  return ::pasta::TemplateParameterList(ast, val);
}

::pasta::Token Decl::EndToken(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::ExternalSourceSymbolAttr> Decl::ExternalSourceSymbolAttribute(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  if (!self.getDeclContext()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getExternalSourceSymbolAttr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::ExternalSourceSymbolAttr>(ast, val);
  }
}

enum DeclFriendObjectKind Decl::FriendObjectKind(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFriendObjectKind();
  return static_cast<::pasta::DeclFriendObjectKind>(val);
}

std::optional<::pasta::FunctionType> Decl::FunctionType(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFunctionType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionType>(ast, val);
  }
}

uint32_t Decl::GlobalID(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getGlobalID();
  return val;
}

int64_t Decl::ID(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getID();
  return val;
}

uint32_t Decl::IdentifierNamespace(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getIdentifierNamespace();
  return val;
}

// 0: Decl::ImportedOwningModule
// 0: Decl::LangOpts
std::optional<::pasta::DeclContext> Decl::LexicalDeclarationContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getLexicalDeclContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

// 0: Decl::LocalOwningModule
std::optional<uint32_t> Decl::MaxAlignment(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  clang::specific_attr_iterator<clang::AlignedAttr> I(self.attr_begin()), E(self.attr_end());
  for (; I != E; ++I) {
    if (I->isAlignmentDependent()) {
      return std::nullopt;
    }
  }
  decltype(auto) val = self.getMaxAlignment();
  return val;
}

enum DeclModuleOwnershipKind Decl::ModuleOwnershipKind(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getModuleOwnershipKind();
  return static_cast<::pasta::DeclModuleOwnershipKind>(val);
}

::pasta::Decl Decl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  throw std::runtime_error("Decl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::Decl> Decl::NextDeclarationInContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNextDeclInContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

std::optional<::pasta::Decl> Decl::NonClosureContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNonClosureContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

std::optional<::pasta::DeclContext> Decl::NonTransparentDeclarationContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  if (!self.getDeclContext()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNonTransparentDeclContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

// 0: Decl::OwningModule
// 0: Decl::OwningModuleForLinkage
uint32_t Decl::OwningModuleID(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getOwningModuleID();
  return val;
}

std::optional<::pasta::DeclContext> Decl::ParentFunctionOrMethod(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getParentFunctionOrMethod();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
}

std::optional<::pasta::Decl> Decl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

uint32_t Decl::TemplateDepth(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getTemplateDepth();
  return val;
}

::pasta::TranslationUnitDecl Decl::TranslationUnitDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getTranslationUnitDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TranslationUnitDecl>(ast, val);
  }
  throw std::runtime_error("Decl::TranslationUnitDeclaration can return nullptr!");
}

// 0: Decl::VersionIntroduced
bool Decl::HasAttributes(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasAttrs();
  return val;
}

bool Decl::HasBody(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasBody();
  return val;
}

bool Decl::HasDefiningAttribute(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasDefiningAttr();
  return val;
}

bool Decl::HasOwningModule(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasOwningModule();
  return val;
}

bool Decl::HasTagIdentifierNamespace(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasTagIdentifierNamespace();
  return val;
}

bool Decl::IsCanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isCanonicalDecl();
  return val;
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDefinedOutsideFunctionOrMethod();
  return val;
}

bool Decl::IsDeprecated(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDeprecated();
  return val;
}

bool Decl::IsDiscardedInGlobalModuleFragment(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDiscardedInGlobalModuleFragment();
  return val;
}

bool Decl::IsFileContextDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFileContextDecl();
  return val;
}

bool Decl::IsFirstDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFirstDecl();
  return val;
}

bool Decl::IsFromASTFile(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFromASTFile();
  return val;
}

bool Decl::IsFunctionOrFunctionTemplate(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFunctionOrFunctionTemplate();
  return val;
}

bool Decl::IsInAnonymousNamespace(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInAnonymousNamespace();
  return val;
}

bool Decl::IsInExportDeclarationContext(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInExportDeclContext();
  return val;
}

// 1: Decl::IsInIdentifierNamespace
std::optional<bool> Decl::IsInLocalScopeForInstantiation(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  if (!self.getDeclContext()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isInLocalScopeForInstantiation();
  return val;
}

bool Decl::IsInStdNamespace(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInStdNamespace();
  return val;
}

bool Decl::IsInvalidDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInvalidDecl();
  return val;
}

bool Decl::IsInvisibleOutsideTheOwningModule(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInvisibleOutsideTheOwningModule();
  return val;
}

bool Decl::IsLocalExternDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isLocalExternDecl();
  return val;
}

bool Decl::IsModulePrivate(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isModulePrivate();
  return val;
}

bool Decl::IsOutOfLine(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isOutOfLine();
  return val;
}

bool Decl::IsParameterPack(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool Decl::IsReachable(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isReachable();
  return val;
}

bool Decl::IsReferenced(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isReferenced();
  return val;
}

bool Decl::IsTemplateDeclaration(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateDecl();
  return val;
}

bool Decl::IsTemplateParameter(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameter();
  return val;
}

bool Decl::IsTemplateParameterPack(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameterPack();
  return val;
}

bool Decl::IsTemplated(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplated();
  return val;
}

bool Decl::IsThisDeclarationReferenced(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isThisDeclarationReferenced();
  return val;
}

bool Decl::IsTopLevelDeclarationInObjCContainer(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTopLevelDeclInObjCContainer();
  return val;
}

bool Decl::IsUnavailable(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnavailable();
  return val;
}

bool Decl::IsUnconditionallyVisible(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnconditionallyVisible();
  return val;
}

bool Decl::IsUsed(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUsed();
  return val;
}

bool Decl::IsWeakImported(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isWeakImported();
  return val;
}

std::vector<::pasta::Decl> Decl::Redeclarations(void) const {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.redecls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: Decl::
// 0: Decl::
EmptyDecl::EmptyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, EmptyDecl)
ExportDecl::ExportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ExportDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ExportDecl)
::pasta::Token ExportDecl::EndToken(void) const {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::ExportToken(void) const {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getExportLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::RBraceToken(void) const {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool ExportDecl::HasBraces(void) const {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.hasBraces();
  return val;
}

ExternCContextDecl::ExternCContextDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ExternCContextDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ExternCContextDecl)
FileScopeAsmDecl::FileScopeAsmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FileScopeAsmDecl)
::pasta::Token FileScopeAsmDecl::AssemblyToken(void) const {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getAsmLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral FileScopeAsmDecl::AssemblyString(void) const {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getAsmString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  throw std::runtime_error("FileScopeAsmDecl::AssemblyString can return nullptr!");
}

::pasta::Token FileScopeAsmDecl::RParenToken(void) const {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendDecl)
std::optional<::pasta::NamedDecl> FriendDecl::FriendDeclaration(void) const {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
}

::pasta::Token FriendDecl::FriendToken(void) const {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> FriendDecl::FriendType(void) const {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  if (!self.getFriendType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getFriendType();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

uint32_t FriendDecl::FriendTypeNumTemplateParameterLists(void) const {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendTypeNumTemplateParameterLists();
  return val;
}

// 1: FriendDecl::FriendTypeTemplateParameterList
bool FriendDecl::IsUnsupportedFriend(void) const {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.isUnsupportedFriend();
  return val;
}

std::vector<::pasta::TemplateParameterList> FriendDecl::FriendTypeTemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.FriendDecl->getFriendTypeNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FriendDecl->getFriendTypeTemplateParameterList(i)));
  }
  return ret;
}

FriendTemplateDecl::FriendTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendTemplateDecl)
::pasta::NamedDecl FriendTemplateDecl::FriendDeclaration(void) const {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("FriendTemplateDecl::FriendDeclaration can return nullptr!");
}

::pasta::Token FriendTemplateDecl::FriendToken(void) const {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendLoc();
  return ast->TokenAt(val);
}

::pasta::Type FriendTemplateDecl::FriendType(void) const {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendType();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("FriendTemplateDecl::FriendType can return nullptr!");
}

uint32_t FriendTemplateDecl::NumTemplateParameters(void) const {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getNumTemplateParameters();
  return val;
}

// 1: FriendTemplateDecl::TemplateParameterList
std::vector<::pasta::TemplateParameterList> FriendTemplateDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.FriendTemplateDecl->getNumTemplateParameters();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FriendTemplateDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ImplicitConceptSpecializationDecl::ImplicitConceptSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ImplicitConceptSpecializationDecl)
std::vector<::pasta::TemplateArgument> ImplicitConceptSpecializationDecl::TemplateArguments(void) const {
  auto &self = *const_cast<clang::ImplicitConceptSpecializationDecl *>(u.ImplicitConceptSpecializationDecl);
  decltype(auto) val = self.getTemplateArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
}

ImportDecl::ImportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ImportDecl)
std::vector<::pasta::Token> ImportDecl::IdentifierTokens(void) const {
  auto &self = *const_cast<clang::ImportDecl *>(u.ImportDecl);
  decltype(auto) val = self.getIdentifierLocs();
  std::vector<::pasta::Token> ret;
  for (auto sl : val) {
    ret.emplace_back(ast->TokenAt(sl));
  }
  return ret;
}

// 0: ImportDecl::ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
std::vector<::pasta::Stmt> LifetimeExtendedTemporaryDecl::Children(void) const {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.childrenExpr();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
}

::pasta::ValueDecl LifetimeExtendedTemporaryDecl::ExtendingDeclaration(void) const {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getExtendingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  throw std::runtime_error("LifetimeExtendedTemporaryDecl::ExtendingDeclaration can return nullptr!");
}

uint32_t LifetimeExtendedTemporaryDecl::ManglingNumber(void) const {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getManglingNumber();
  return val;
}

// 1: LifetimeExtendedTemporaryDecl::OrCreateValue
enum StorageDuration LifetimeExtendedTemporaryDecl::StorageDuration(void) const {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
}

::pasta::Expr LifetimeExtendedTemporaryDecl::TemporaryExpression(void) const {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getTemporaryExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("LifetimeExtendedTemporaryDecl::TemporaryExpression can return nullptr!");
}

// 0: LifetimeExtendedTemporaryDecl::Value
LinkageSpecDecl::LinkageSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, LinkageSpecDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, LinkageSpecDecl)
::pasta::Token LinkageSpecDecl::EndToken(void) const {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token LinkageSpecDecl::ExternToken(void) const {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
}

enum LinkageSpecDeclLanguageIDs LinkageSpecDecl::Language(void) const {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getLanguage();
  return static_cast<::pasta::LinkageSpecDeclLanguageIDs>(val);
}

::pasta::Token LinkageSpecDecl::RBraceToken(void) const {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool LinkageSpecDecl::HasBraces(void) const {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.hasBraces();
  return val;
}

NamedDecl::NamedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NamedDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, BaseUsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, HLSLBufferDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, LabelDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NamespaceAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NamespaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCContainerDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCProtocolDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnnamedGlobalConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingIfExistsDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingEnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingPackDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
// 1: NamedDecl::DeclarationReplaces
// 0: NamedDecl::DeclarationName
// 1: NamedDecl::ExplicitVisibility
enum Linkage NamedDecl::FormalLinkage(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getFormalLinkage();
  return static_cast<::pasta::Linkage>(val);
}

// 0: NamedDecl::Identifier
// 0: NamedDecl::LinkageAndVisibility
enum Linkage NamedDecl::LinkageInternal(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getLinkageInternal();
  return static_cast<::pasta::Linkage>(val);
}

::pasta::NamedDecl NamedDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("NamedDecl::MostRecentDeclaration can return nullptr!");
}

std::string NamedDecl::Name(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getNameAsString();
  return val;
}

std::optional<enum ObjCStringFormatFamily> NamedDecl::ObjCFStringFormattingFamily(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  if (!self.getIdentifier()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getObjCFStringFormattingFamily();
  return static_cast<::pasta::ObjCStringFormatFamily>(val);
}

std::string NamedDecl::QualifiedNameAsString(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getQualifiedNameAsString();
  return val;
}

::pasta::NamedDecl NamedDecl::UnderlyingDeclaration(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getUnderlyingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("NamedDecl::UnderlyingDeclaration can return nullptr!");
}

enum Visibility NamedDecl::Visibility(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::Visibility>(val);
}

bool NamedDecl::HasExternalFormalLinkage(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasExternalFormalLinkage();
  return val;
}

bool NamedDecl::HasLinkage(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkage();
  return val;
}

bool NamedDecl::HasLinkageBeenComputed(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkageBeenComputed();
  return val;
}

bool NamedDecl::IsCXXClassMember(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXClassMember();
  return val;
}

bool NamedDecl::IsCXXInstanceMember(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXInstanceMember();
  return val;
}

bool NamedDecl::IsExternallyDeclarable(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyDeclarable();
  return val;
}

bool NamedDecl::IsExternallyVisible(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyVisible();
  return val;
}

bool NamedDecl::IsLinkageValid(void) const {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isLinkageValid();
  return val;
}

// 1: NamedDecl::IsReserved
NamespaceAliasDecl::NamespaceAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceAliasDecl)
::pasta::Token NamespaceAliasDecl::AliasToken(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getAliasLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl NamespaceAliasDecl::AliasedNamespace(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getAliasedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("NamespaceAliasDecl::AliasedNamespace can return nullptr!");
}

::pasta::NamespaceAliasDecl NamespaceAliasDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceAliasDecl>(ast, val);
  }
  throw std::runtime_error("NamespaceAliasDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::NamespaceDecl NamespaceAliasDecl::Namespace(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  throw std::runtime_error("NamespaceAliasDecl::Namespace can return nullptr!");
}

::pasta::Token NamespaceAliasDecl::NamespaceToken(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getNamespaceLoc();
  return ast->TokenAt(val);
}

// 0: NamespaceAliasDecl::Qualifier
// 0: NamespaceAliasDecl::QualifierToken
::pasta::Token NamespaceAliasDecl::TargetNameToken(void) const {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getTargetNameLoc();
  return ast->TokenAt(val);
}

NamespaceDecl::NamespaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceDecl)
std::optional<::pasta::NamespaceDecl> NamespaceDecl::AnonymousNamespace(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getAnonymousNamespace();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
}

::pasta::Token NamespaceDecl::BeginToken(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl NamespaceDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  throw std::runtime_error("NamespaceDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::NamespaceDecl NamespaceDecl::OriginalNamespace(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getOriginalNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  throw std::runtime_error("NamespaceDecl::OriginalNamespace can return nullptr!");
}

::pasta::Token NamespaceDecl::RBraceToken(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool NamespaceDecl::IsAnonymousNamespace(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isAnonymousNamespace();
  return val;
}

bool NamespaceDecl::IsInline(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isInline();
  return val;
}

bool NamespaceDecl::IsNested(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isNested();
  return val;
}

bool NamespaceDecl::IsOriginalNamespace(void) const {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isOriginalNamespace();
  return val;
}

// 1: NamespaceDecl::IsRedundantInlineQualifierFor
ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
::pasta::ObjCInterfaceDecl ObjCCompatibleAliasDecl::ClassInterface(void) const {
  auto &self = *const_cast<clang::ObjCCompatibleAliasDecl *>(u.ObjCCompatibleAliasDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCompatibleAliasDecl::ClassInterface can return nullptr!");
}

ObjCContainerDecl::ObjCContainerDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCContainerDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCContainerDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCContainerDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
// 2: FindPropertyDeclaration
// 1: ObjCContainerDecl::HasUserDeclaredSetterMethod
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::ClassMethods(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.class_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::ClassProperties(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.class_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
::pasta::TokenRange ObjCContainerDecl::AtEndRange(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtEndRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token ObjCContainerDecl::AtStartToken(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtStartLoc();
  return ast->TokenAt(val);
}

// 1: ObjCContainerDecl::ClassMethod
// 1: ObjCContainerDecl::InstanceMethod
// 1: ObjCContainerDecl::InstanceVariableDeclaration
// 2: Method
// 2: Property
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::InstanceMethods(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.instance_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::InstanceProperties(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.instance_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::Methods(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::Properties(void) const {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

ObjCImplDecl::ObjCImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCImplDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCImplDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCImplDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
// 2: FindPropertyImplementationDeclaration
// 1: ObjCImplDecl::FindPropertyImplementationInstanceVariableDeclaration
::pasta::ObjCInterfaceDecl ObjCImplDecl::ClassInterface(void) const {
  auto &self = *const_cast<clang::ObjCImplDecl *>(u.ObjCImplDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCImplDecl::ClassInterface can return nullptr!");
}

std::vector<::pasta::ObjCPropertyImplDecl> ObjCImplDecl::PropertyImplementations(void) const {
  auto &self = *const_cast<clang::ObjCImplDecl *>(u.ObjCImplDecl);
  decltype(auto) val = self.property_impls();
  std::vector<::pasta::ObjCPropertyImplDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyImplDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCImplDecl::
// 0: ObjCImplDecl::
ObjCImplementationDecl::ObjCImplementationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCImplementationDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCImplementationDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCImplementationDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
// 0: ObjCImplementationDecl::Identifier
::pasta::Token ObjCImplementationDecl::InstanceVariableLBraceToken(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCImplementationDecl::InstanceVariableRBraceToken(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
}

std::string ObjCImplementationDecl::Name(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNameAsString();
  return val;
}

uint32_t ObjCImplementationDecl::NumInstanceVariableInitializers(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNumIvarInitializers();
  return val;
}

std::string_view ObjCImplementationDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::ObjCInterfaceDecl ObjCImplementationDecl::SuperClass(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCImplementationDecl::SuperClass can return nullptr!");
}

::pasta::Token ObjCImplementationDecl::SuperClassToken(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getSuperClassLoc();
  return ast->TokenAt(val);
}

bool ObjCImplementationDecl::HasDestructors(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.hasDestructors();
  return val;
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.hasNonZeroConstructors();
  return val;
}

// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::Initializers
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCImplementationDecl::InstanceVariables(void) const {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

ObjCInterfaceDecl::ObjCInterfaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCInterfaceDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCInterfaceDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCInterfaceDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
// 1: ObjCInterfaceDecl::FindCategoryDeclaration
// 2: FindPropertyVisibleInPrimaryClass
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::AllReferencedProtocols(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.all_referenced_protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.declaresOrInheritsDesignatedInitializers();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::CanonicalDeclaration can return nullptr!");
}

// 1: ObjCInterfaceDecl::CategoryClassMethod
// 1: ObjCInterfaceDecl::CategoryInstanceMethod
::pasta::ObjCCategoryDecl ObjCInterfaceDecl::CategoryListRaw(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getCategoryListRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::CategoryListRaw can return nullptr!");
}

// 2: CategoryMethod
::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::Definition(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::Definition can return nullptr!");
}

::pasta::Token ObjCInterfaceDecl::EndOfDefinitionToken(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getEndOfDefinitionLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCImplementationDecl ObjCInterfaceDecl::Implementation(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCImplementationDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::Implementation can return nullptr!");
}

std::string_view ObjCInterfaceDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

// 0: ObjCInterfaceDecl::ReferencedProtocols
std::optional<::pasta::ObjCInterfaceDecl> ObjCInterfaceDecl::SuperClass(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
}

::pasta::Token ObjCInterfaceDecl::SuperClassToken(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> ObjCInterfaceDecl::SuperClassTypeInfo(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassTInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

std::optional<::pasta::ObjCObjectType> ObjCInterfaceDecl::SuperClassType(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
}

::pasta::Type ObjCInterfaceDecl::TypeForDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getTypeForDecl();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::TypeForDeclaration can return nullptr!");
}

// 0: ObjCInterfaceDecl::TypeParameterList
// 0: ObjCInterfaceDecl::TypeParameterListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
}

bool ObjCInterfaceDecl::HasDesignatedInitializers(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.hasDesignatedInitializers();
  return val;
}

bool ObjCInterfaceDecl::IsArcWeakrefUnavailable(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isArcWeakrefUnavailable();
  return val;
}

// 1: ObjCInterfaceDecl::IsDesignatedInitializer
bool ObjCInterfaceDecl::IsImplicitInterfaceDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isImplicitInterfaceDecl();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isObjCRequiresPropertyDefs();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions can return nullptr!");
}

// 1: ObjCInterfaceDecl::IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCInterfaceDecl::InstanceVariables(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownCategories(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.known_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownExtensions(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.known_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 1: ObjCInterfaceDecl::LookupClassMethod
// 1: ObjCInterfaceDecl::LookupInstanceMethod
// 2: LookupMethod
// 1: ObjCInterfaceDecl::LookupPrivateMethod
// 3: ObjCInterfaceDecl::LookupPropertyAccessor
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::Token> ObjCInterfaceDecl::ProtocolTokens(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::Protocols(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleCategories(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.visible_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleExtensions(void) const {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.visible_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
ObjCMethodDecl::ObjCMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCMethodDecl)
bool ObjCMethodDecl::DefinedInNSObject(void) const {
  auto &self = *(u.ObjCMethodDecl);
  decltype(auto) val = self.definedInNSObject(ast->ci->getASTContext());
  return val;
}

::pasta::ObjCPropertyDecl ObjCMethodDecl::FindPropertyDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.findPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::FindPropertyDeclaration can return nullptr!");
}

::pasta::Token ObjCMethodDecl::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCMethodDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::ObjCCategoryDecl ObjCMethodDecl::Category(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::Category can return nullptr!");
}

::pasta::ObjCInterfaceDecl ObjCMethodDecl::ClassInterface(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::ClassInterface can return nullptr!");
}

::pasta::ImplicitParamDecl ObjCMethodDecl::CommandDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCmdDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::CommandDeclaration can return nullptr!");
}

::pasta::Token ObjCMethodDecl::DeclaratorEndToken(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getDeclaratorEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCMethodDecl::EndToken(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum ObjCMethodDeclImplementationControl ObjCMethodDecl::ImplementationControl(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getImplementationControl();
  return static_cast<::pasta::ObjCMethodDeclImplementationControl>(val);
}

enum ObjCMethodFamily ObjCMethodDecl::MethodFamily(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(val);
}

uint32_t ObjCMethodDecl::NumSelectorTokens(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getNumSelectorLocs();
  return val;
}

enum DeclObjCDeclQualifier ObjCMethodDecl::ObjCDeclQualifier(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
}

// 1: ObjCMethodDecl::ParameterDeclaration
::pasta::Type ObjCMethodDecl::ReturnType(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange ObjCMethodDecl::ReturnTypeSourceRange(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCMethodDecl::Selector
// 1: ObjCMethodDecl::SelectorToken
::pasta::Token ObjCMethodDecl::SelectorStartToken(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
}

::pasta::ImplicitParamDecl ObjCMethodDecl::SelfDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getSelfDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  throw std::runtime_error("ObjCMethodDecl::SelfDeclaration can return nullptr!");
}

// 4: ObjCMethodDecl::SelfType
bool ObjCMethodDecl::HasParameterDestroyedInCallee(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasParamDestroyedInCallee();
  return val;
}

bool ObjCMethodDecl::HasRedeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRedeclaration();
  return val;
}

bool ObjCMethodDecl::HasRelatedResultType(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRelatedResultType();
  return val;
}

bool ObjCMethodDecl::HasSkippedBody(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
}

bool ObjCMethodDecl::IsClassMethod(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isClassMethod();
  return val;
}

bool ObjCMethodDecl::IsDefined(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDefined();
  return val;
}

bool ObjCMethodDecl::IsDesignatedInitializerForTheInterface(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDesignatedInitializerForTheInterface();
  return val;
}

bool ObjCMethodDecl::IsDirectMethod(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDirectMethod();
  return val;
}

bool ObjCMethodDecl::IsInstanceMethod(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isInstanceMethod();
  return val;
}

bool ObjCMethodDecl::IsOptional(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOptional();
  return val;
}

bool ObjCMethodDecl::IsOverriding(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOverriding();
  return val;
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isPropertyAccessor();
  return val;
}

bool ObjCMethodDecl::IsRedeclaration(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isRedeclaration();
  return val;
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isSynthesizedAccessorStub();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADesignatedInitializer(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADesignatedInitializer();
  return val;
}

bool ObjCMethodDecl::IsVariadic(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isVariadic();
  return val;
}

// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
std::vector<::pasta::ParmVarDecl> ObjCMethodDecl::Parameters(void) const {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCMethodDecl::
std::vector<::pasta::Token> ObjCMethodDecl::SelectorTokens(void) const {
  std::vector<::pasta::Token> ret;
  auto convert_elem = [&] (clang::SourceLocation val) {
    return ast->TokenAt(val);
  };
  auto count = u.ObjCMethodDecl->getNumSelectorLocs();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCMethodDecl->getSelectorLoc(i)));
  }
  return ret;
}

ObjCPropertyDecl::ObjCPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCPropertyDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCPropertyDecl)
::pasta::Token ObjCPropertyDecl::AtToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
}

// 1: ObjCPropertyDecl::DefaultSynthInstanceVariableName
::pasta::ObjCMethodDecl ObjCPropertyDecl::GetterMethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyDecl::GetterMethodDeclaration can return nullptr!");
}

// 0: ObjCPropertyDecl::GetterName
::pasta::Token ObjCPropertyDecl::GetterNameToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getGetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCPropertyDecl::LParenToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyDecl::PropertyAttributes
// 0: ObjCPropertyDecl::PropertyAttributesAsWritten
enum ObjCPropertyDeclPropertyControl ObjCPropertyDecl::PropertyImplementation(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getPropertyImplementation();
  return static_cast<::pasta::ObjCPropertyDeclPropertyControl>(val);
}

::pasta::ObjCIvarDecl ObjCPropertyDecl::PropertyInstanceVariableDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyDecl::PropertyInstanceVariableDeclaration can return nullptr!");
}

enum ObjCPropertyQueryKind ObjCPropertyDecl::QueryKind(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getQueryKind();
  return static_cast<::pasta::ObjCPropertyQueryKind>(val);
}

enum ObjCPropertyDeclSetterKind ObjCPropertyDecl::SetterKind(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterKind();
  return static_cast<::pasta::ObjCPropertyDeclSetterKind>(val);
}

::pasta::ObjCMethodDecl ObjCPropertyDecl::SetterMethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyDecl::SetterMethodDeclaration can return nullptr!");
}

// 0: ObjCPropertyDecl::SetterName
::pasta::Token ObjCPropertyDecl::SetterNameToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCPropertyDecl::Type(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 1: ObjCPropertyDecl::UsageType
bool ObjCPropertyDecl::IsAtomic(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isAtomic();
  return val;
}

bool ObjCPropertyDecl::IsClassProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isClassProperty();
  return val;
}

bool ObjCPropertyDecl::IsDirectProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isDirectProperty();
  return val;
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isInstanceProperty();
  return val;
}

bool ObjCPropertyDecl::IsOptional(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isOptional();
  return val;
}

bool ObjCPropertyDecl::IsReadOnly(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isReadOnly();
  return val;
}

bool ObjCPropertyDecl::IsRetaining(void) const {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isRetaining();
  return val;
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCPropertyImplDecl)
::pasta::Token ObjCPropertyImplDecl::BeginToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCPropertyImplDecl::GetterCXXConstructor(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getGetterCXXConstructor();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::GetterCXXConstructor can return nullptr!");
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::GetterMethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::GetterMethodDeclaration can return nullptr!");
}

::pasta::ObjCPropertyDecl ObjCPropertyImplDecl::PropertyDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::PropertyDeclaration can return nullptr!");
}

enum ObjCPropertyImplDeclKind ObjCPropertyImplDecl::PropertyImplementation(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyImplementation();
  return static_cast<::pasta::ObjCPropertyImplDeclKind>(val);
}

::pasta::ObjCIvarDecl ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration can return nullptr!");
}

::pasta::Token ObjCPropertyImplDecl::PropertyInstanceVariableDeclarationToken(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyIvarDeclLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCPropertyImplDecl::SetterCXXAssignment(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getSetterCXXAssignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::SetterCXXAssignment can return nullptr!");
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::SetterMethodDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  throw std::runtime_error("ObjCPropertyImplDecl::SetterMethodDeclaration can return nullptr!");
}

bool ObjCPropertyImplDecl::IsInstanceVariableNameSpecified(void) const {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.isIvarNameSpecified();
  return val;
}

ObjCProtocolDecl::ObjCProtocolDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
::pasta::ObjCProtocolDecl ObjCProtocolDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  throw std::runtime_error("ObjCProtocolDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::ObjCProtocolDecl ObjCProtocolDecl::Definition(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  throw std::runtime_error("ObjCProtocolDecl::Definition can return nullptr!");
}

std::string_view ObjCProtocolDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

// 0: ObjCProtocolDecl::ReferencedProtocols
bool ObjCProtocolDecl::HasDefinition(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
}

bool ObjCProtocolDecl::IsNonRuntimeProtocol(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.isNonRuntimeProtocol();
  return val;
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

// 1: ObjCProtocolDecl::LookupClassMethod
// 1: ObjCProtocolDecl::LookupInstanceMethod
// 2: LookupMethod
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
std::vector<::pasta::Token> ObjCProtocolDecl::ProtocolTokens(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

// 0: ObjCProtocolDecl::
std::vector<::pasta::ObjCProtocolDecl> ObjCProtocolDecl::Protocols(void) const {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

PragmaCommentDecl::PragmaCommentDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaCommentDecl)
std::string_view PragmaCommentDecl::Argument(void) const {
  auto &self = *const_cast<clang::PragmaCommentDecl *>(u.PragmaCommentDecl);
  decltype(auto) val = self.getArg();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

enum PragmaMSCommentKind PragmaCommentDecl::CommentKind(void) const {
  auto &self = *const_cast<clang::PragmaCommentDecl *>(u.PragmaCommentDecl);
  decltype(auto) val = self.getCommentKind();
  return static_cast<::pasta::PragmaMSCommentKind>(val);
}

PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaDetectMismatchDecl)
std::string_view PragmaDetectMismatchDecl::Name(void) const {
  auto &self = *const_cast<clang::PragmaDetectMismatchDecl *>(u.PragmaDetectMismatchDecl);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string_view PragmaDetectMismatchDecl::Value(void) const {
  auto &self = *const_cast<clang::PragmaDetectMismatchDecl *>(u.PragmaDetectMismatchDecl);
  decltype(auto) val = self.getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

RequiresExprBodyDecl::RequiresExprBodyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, RequiresExprBodyDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, RequiresExprBodyDecl)
StaticAssertDecl::StaticAssertDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, StaticAssertDecl)
::pasta::Expr StaticAssertDecl::AssertExpression(void) const {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getAssertExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("StaticAssertDecl::AssertExpression can return nullptr!");
}

::pasta::StringLiteral StaticAssertDecl::Message(void) const {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getMessage();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  throw std::runtime_error("StaticAssertDecl::Message can return nullptr!");
}

::pasta::Token StaticAssertDecl::RParenToken(void) const {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
}

bool StaticAssertDecl::IsFailed(void) const {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.isFailed();
  return val;
}

TemplateDecl::TemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, VarTemplateDecl)
::pasta::TemplateParameterList TemplateDecl::TemplateParameters(void) const {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  throw std::runtime_error("TemplateDecl::TemplateParameters can return nullptr!");
}

::pasta::NamedDecl TemplateDecl::TemplatedDeclaration(void) const {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("TemplateDecl::TemplatedDeclaration can return nullptr!");
}

bool TemplateDecl::HasAssociatedConstraints(void) const {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
}

bool TemplateDecl::IsTypeAlias(void) const {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.isTypeAlias();
  return val;
}

TemplateTemplateParmDecl::TemplateTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
bool TemplateTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
}

// 0: TemplateTemplateParmDecl::DefaultArgumentStorage
// 0: TemplateTemplateParmDecl::DefaultArgument
::pasta::Token TemplateTemplateParmDecl::DefaultArgumentToken(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: TemplateTemplateParmDecl::ExpansionTemplateParameters
uint32_t TemplateTemplateParmDecl::NumExpansionTemplateParameters(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getNumExpansionTemplateParameters();
  return val;
}

bool TemplateTemplateParmDecl::HasDefaultArgument(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

TopLevelStmtDecl::TopLevelStmtDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TopLevelStmtDecl)
::pasta::Stmt TopLevelStmtDecl::Statement(void) const {
  auto &self = *const_cast<clang::TopLevelStmtDecl *>(u.TopLevelStmtDecl);
  decltype(auto) val = self.getStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  throw std::runtime_error("TopLevelStmtDecl::Statement can return nullptr!");
}

TranslationUnitDecl::TranslationUnitDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, TranslationUnitDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, TranslationUnitDecl)
// 0: TranslationUnitDecl::ASTContext
std::optional<::pasta::NamespaceDecl> TranslationUnitDecl::AnonymousNamespace(void) const {
  auto &self = *const_cast<clang::TranslationUnitDecl *>(u.TranslationUnitDecl);
  decltype(auto) val = self.getAnonymousNamespace();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
}

TypeDecl::TypeDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
::pasta::Token TypeDecl::BeginToken(void) const {
  auto &self = *const_cast<clang::TypeDecl *>(u.TypeDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> TypeDecl::TypeForDeclaration(void) const {
  auto &self = *const_cast<clang::TypeDecl *>(u.TypeDecl);
  decltype(auto) val = self.getTypeForDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
}

TypedefNameDecl::TypedefNameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypedefNameDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypedefNameDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, TypedefDecl)
std::optional<::pasta::TagDecl> TypedefNameDecl::AnonymousDeclarationWithTypedefName(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getAnonDeclWithTypedefName();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
}

::pasta::TypedefNameDecl TypedefNameDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  throw std::runtime_error("TypedefNameDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::Type TypedefNameDecl::Type(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("TypedefNameDecl::Type can return nullptr!");
}

::pasta::Type TypedefNameDecl::UnderlyingType(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool TypedefNameDecl::IsModed(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.isModed();
  return val;
}

bool TypedefNameDecl::IsTransparentTag(void) const {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.isTransparentTag();
  return val;
}

UnresolvedUsingIfExistsDecl::UnresolvedUsingIfExistsDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnresolvedUsingIfExistsDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnresolvedUsingIfExistsDecl)
UnresolvedUsingTypenameDecl::UnresolvedUsingTypenameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  throw std::runtime_error("UnresolvedUsingTypenameDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::Token UnresolvedUsingTypenameDecl::EllipsisToken(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingTypenameDecl::NameInfo
// 0: UnresolvedUsingTypenameDecl::Qualifier
// 0: UnresolvedUsingTypenameDecl::QualifierToken
::pasta::Token UnresolvedUsingTypenameDecl::TypenameToken(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getTypenameLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedUsingTypenameDecl::UsingToken(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

UsingDirectiveDecl::UsingDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDirectiveDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDirectiveDecl)
::pasta::DeclContext UsingDirectiveDecl::CommonAncestor(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getCommonAncestor();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  throw std::runtime_error("UsingDirectiveDecl::CommonAncestor can return nullptr!");
}

::pasta::Token UsingDirectiveDecl::IdentifierToken(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getIdentLocation();
  return ast->TokenAt(val);
}

::pasta::Token UsingDirectiveDecl::NamespaceKeyToken(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNamespaceKeyLocation();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl UsingDirectiveDecl::NominatedNamespace(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNominatedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  throw std::runtime_error("UsingDirectiveDecl::NominatedNamespace can return nullptr!");
}

::pasta::NamedDecl UsingDirectiveDecl::NominatedNamespaceAsWritten(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNominatedNamespaceAsWritten();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("UsingDirectiveDecl::NominatedNamespaceAsWritten can return nullptr!");
}

// 0: UsingDirectiveDecl::Qualifier
// 0: UsingDirectiveDecl::QualifierToken
::pasta::Token UsingDirectiveDecl::UsingToken(void) const {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

UsingPackDecl::UsingPackDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingPackDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingPackDecl)
std::vector<::pasta::NamedDecl> UsingPackDecl::Expansions(void) const {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.expansions();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::UsingPackDecl UsingPackDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingPackDecl>(ast, val);
  }
  throw std::runtime_error("UsingPackDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::NamedDecl UsingPackDecl::InstantiatedFromUsingDeclaration(void) const {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.getInstantiatedFromUsingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("UsingPackDecl::InstantiatedFromUsingDeclaration can return nullptr!");
}

UsingShadowDecl::UsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
::pasta::UsingShadowDecl UsingShadowDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  throw std::runtime_error("UsingShadowDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::BaseUsingDecl UsingShadowDecl::Introducer(void) const {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getIntroducer();
  if (val) {
    return DeclBuilder::Create<::pasta::BaseUsingDecl>(ast, val);
  }
  throw std::runtime_error("UsingShadowDecl::Introducer can return nullptr!");
}

std::optional<::pasta::UsingShadowDecl> UsingShadowDecl::NextUsingShadowDeclaration(void) const {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getNextUsingShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
}

::pasta::NamedDecl UsingShadowDecl::TargetDeclaration(void) const {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getTargetDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  throw std::runtime_error("UsingShadowDecl::TargetDeclaration can return nullptr!");
}

ValueDecl::ValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ValueDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, UnnamedGlobalConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
std::optional<::pasta::VarDecl> ValueDecl::PotentiallyDecomposedVariableDeclaration(void) const {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  if (!clang::isa<clang::VarDecl>(&self) &&
      !clang::isa<clang::BindingDecl>(&self)) {
    return std::nullopt;
  }
  decltype(auto) val = self.getPotentiallyDecomposedVarDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

::pasta::Type ValueDecl::Type(void) const {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.getType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

bool ValueDecl::IsInitializerCapture(void) const {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.isInitCapture();
  return val;
}

bool ValueDecl::IsWeak(void) const {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.isWeak();
  return val;
}

OMPDeclarativeDirectiveDecl::OMPDeclarativeDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::From(const Decl &that) {
  if (false) {
    return std::nullopt;
  } else if (auto p_OMPAllocateDecl = clang::dyn_cast<clang::OMPAllocateDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveDecl>(that.ast, p_OMPAllocateDecl);
  } else if (auto p_OMPRequiresDecl = clang::dyn_cast<clang::OMPRequiresDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveDecl>(that.ast, p_OMPRequiresDecl);
  } else if (auto p_OMPThreadPrivateDecl = clang::dyn_cast<clang::OMPThreadPrivateDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveDecl>(that.ast, p_OMPThreadPrivateDecl);
  } else {
    return std::nullopt;
  }
}

PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
OMPDeclarativeDirectiveValueDecl::OMPDeclarativeDirectiveValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::From(const Decl &that) {
  if (false) {
    return std::nullopt;
  } else if (auto p_OMPDeclareMapperDecl = clang::dyn_cast<clang::OMPDeclareMapperDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveValueDecl>(that.ast, p_OMPDeclareMapperDecl);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::From(const NamedDecl &that) {
  if (false) {
    return std::nullopt;
  } else if (auto p_OMPDeclareMapperDecl = clang::dyn_cast<clang::OMPDeclareMapperDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveValueDecl>(that.ast, p_OMPDeclareMapperDecl);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::From(const ValueDecl &that) {
  if (false) {
    return std::nullopt;
  } else if (auto p_OMPDeclareMapperDecl = clang::dyn_cast<clang::OMPDeclareMapperDecl>(that.u.Decl)) {
    return DeclBuilder::Create<OMPDeclarativeDirectiveValueDecl>(that.ast, p_OMPDeclareMapperDecl);
  } else {
    return std::nullopt;
  }
}

PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
AccessSpecDecl::AccessSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, AccessSpecDecl)
::pasta::Token AccessSpecDecl::AccessSpecifierToken(void) const {
  auto &self = *const_cast<clang::AccessSpecDecl *>(u.AccessSpecDecl);
  decltype(auto) val = self.getAccessSpecifierLoc();
  return ast->TokenAt(val);
}

::pasta::Token AccessSpecDecl::ColonToken(void) const {
  auto &self = *const_cast<clang::AccessSpecDecl *>(u.AccessSpecDecl);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
}

BaseUsingDecl::BaseUsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, BaseUsingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, BaseUsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(BaseUsingDecl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(BaseUsingDecl, UsingEnumDecl)
// 0: BaseUsingDecl::
// 0: BaseUsingDecl::
// 0: BaseUsingDecl::
std::vector<::pasta::UsingShadowDecl> BaseUsingDecl::Shadows(void) const {
  auto &self = *const_cast<clang::BaseUsingDecl *>(u.BaseUsingDecl);
  decltype(auto) val = self.shadows();
  std::vector<::pasta::UsingShadowDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

BindingDecl::BindingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, BindingDecl)
::pasta::Expr BindingDecl::Binding(void) const {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getBinding();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("BindingDecl::Binding can return nullptr!");
}

::pasta::ValueDecl BindingDecl::DecomposedDeclaration(void) const {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getDecomposedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  throw std::runtime_error("BindingDecl::DecomposedDeclaration can return nullptr!");
}

::pasta::VarDecl BindingDecl::HoldingVariable(void) const {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getHoldingVar();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("BindingDecl::HoldingVariable can return nullptr!");
}

BlockDecl::BlockDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, BlockDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, BlockDecl)
bool BlockDecl::BlockMissingReturnType(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.blockMissingReturnType();
  return val;
}

bool BlockDecl::CanAvoidCopyToHeap(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.canAvoidCopyToHeap();
  return val;
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::Captures
bool BlockDecl::CapturesCXXThis(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.capturesCXXThis();
  return val;
}

// 1: BlockDecl::CapturesVariable
bool BlockDecl::DoesNotEscape(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.doesNotEscape();
  return val;
}

std::optional<::pasta::Decl> BlockDecl::BlockManglingContextDeclaration(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingContextDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

uint32_t BlockDecl::BlockManglingNumber(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingNumber();
  return val;
}

::pasta::Token BlockDecl::CaretToken(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getCaretLocation();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt BlockDecl::CompoundBody(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getCompoundBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  throw std::runtime_error("BlockDecl::CompoundBody can return nullptr!");
}

uint32_t BlockDecl::NumCaptures(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getNumCaptures();
  return val;
}

uint32_t BlockDecl::NumParameters(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

// 1: BlockDecl::ParameterDeclaration
::pasta::Type BlockDecl::SignatureAsWritten(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getSignatureAsWritten();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("BlockDecl::SignatureAsWritten can return nullptr!");
}

bool BlockDecl::HasCaptures(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.hasCaptures();
  return val;
}

bool BlockDecl::IsConversionFromLambda(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isConversionFromLambda();
  return val;
}

bool BlockDecl::IsVariadic(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isVariadic();
  return val;
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
std::vector<::pasta::ParmVarDecl> BlockDecl::Parameters(void) const {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> BlockDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.BlockDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.BlockDecl->getParamDecl(i)));
  }
  return ret;
}

BuiltinTemplateDecl::BuiltinTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, BuiltinTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, BuiltinTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, BuiltinTemplateDecl)
// 0: BuiltinTemplateDecl::BuiltinTemplateKind
CapturedDecl::CapturedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CapturedDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CapturedDecl)
::pasta::ImplicitParamDecl CapturedDecl::ContextParameter(void) const {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getContextParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  throw std::runtime_error("CapturedDecl::ContextParameter can return nullptr!");
}

uint32_t CapturedDecl::ContextParameterPosition(void) const {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getContextParamPosition();
  return val;
}

uint32_t CapturedDecl::NumParameters(void) const {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

// 1: CapturedDecl::Parameter
bool CapturedDecl::IsNothrow(void) const {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.isNothrow();
  return val;
}

// 0: CapturedDecl::
// 0: CapturedDecl::
std::vector<::pasta::ImplicitParamDecl> CapturedDecl::Parameters(void) const {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ImplicitParamDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
::pasta::CXXMethodDecl ClassScopeFunctionSpecializationDecl::Specialization(void) const {
  auto &self = *const_cast<clang::ClassScopeFunctionSpecializationDecl *>(u.ClassScopeFunctionSpecializationDecl);
  decltype(auto) val = self.getSpecialization();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  throw std::runtime_error("ClassScopeFunctionSpecializationDecl::Specialization can return nullptr!");
}

// 0: ClassScopeFunctionSpecializationDecl::TemplateArgumentsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArguments(void) const {
  auto &self = *const_cast<clang::ClassScopeFunctionSpecializationDecl *>(u.ClassScopeFunctionSpecializationDecl);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
}

ConceptDecl::ConceptDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, ConceptDecl)
::pasta::ConceptDecl ConceptDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  throw std::runtime_error("ConceptDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::Expr ConceptDecl::ConstraintExpression(void) const {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.getConstraintExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("ConceptDecl::ConstraintExpression can return nullptr!");
}

bool ConceptDecl::IsTypeConcept(void) const {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.isTypeConcept();
  return val;
}

ConstructorUsingShadowDecl::ConstructorUsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : UsingShadowDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ConstructorUsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
bool ConstructorUsingShadowDecl::ConstructsVirtualBase(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.constructsVirtualBase();
  return val;
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::ConstructedBaseClass(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getConstructedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("ConstructorUsingShadowDecl::ConstructedBaseClass can return nullptr!");
}

std::optional<::pasta::ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::ConstructedBaseClassShadowDeclaration(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getConstructedBaseClassShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
}

::pasta::UsingDecl ConstructorUsingShadowDecl::Introducer(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getIntroducer();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  throw std::runtime_error("ConstructorUsingShadowDecl::Introducer can return nullptr!");
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::NominatedBaseClass(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getNominatedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("ConstructorUsingShadowDecl::NominatedBaseClass can return nullptr!");
}

std::optional<::pasta::ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::NominatedBaseClassShadowDeclaration(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getNominatedBaseClassShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::Parent(void) const {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("ConstructorUsingShadowDecl::Parent can return nullptr!");
}

DeclaratorDecl::DeclaratorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, DeclaratorDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, DeclaratorDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplateSpecializationDecl)
::pasta::Token DeclaratorDecl::BeginToken(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::FirstInnerToken(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

uint32_t DeclaratorDecl::NumTemplateParameterLists(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token DeclaratorDecl::FirstOuterToken(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: DeclaratorDecl::Qualifier
// 0: DeclaratorDecl::QualifierToken
// 1: DeclaratorDecl::TemplateParameterList
std::optional<::pasta::Expr> DeclaratorDecl::TrailingRequiresClause(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTrailingRequiresClause();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::optional<::pasta::Type> DeclaratorDecl::Type(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSourceInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

::pasta::Token DeclaratorDecl::TypeSpecEndToken(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::TypeSpecStartToken(void) const {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecStartLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::TemplateParameterList> DeclaratorDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.DeclaratorDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.DeclaratorDecl->getTemplateParameterList(i)));
  }
  return ret;
}

EnumConstantDecl::EnumConstantDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, EnumConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, EnumConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, EnumConstantDecl)
::pasta::EnumConstantDecl EnumConstantDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, val);
  }
  throw std::runtime_error("EnumConstantDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::Expr> EnumConstantDecl::InitializerExpression(void) const {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getInitExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

llvm::APSInt EnumConstantDecl::InitializerValue(void) const {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getInitVal();
  return val;
}

FieldDecl::FieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FieldDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, FieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, FieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FieldDecl, ObjCIvarDecl)
std::optional<::pasta::Expr> FieldDecl::BitWidth(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  if (!self.isBitField()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getBitWidth();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

uint32_t FieldDecl::BitWidthValue(void) const {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.getBitWidthValue(ast->ci->getASTContext());
  return val;
}

::pasta::FieldDecl FieldDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  throw std::runtime_error("FieldDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::VariableArrayType> FieldDecl::CapturedVLAType(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getCapturedVLAType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::VariableArrayType>(ast, val);
  }
}

uint32_t FieldDecl::FieldIndex(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getFieldIndex();
  return val;
}

enum InClassInitStyle FieldDecl::InClassInitializerStyle(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitStyle();
  return static_cast<::pasta::InClassInitStyle>(val);
}

std::optional<::pasta::Expr> FieldDecl::InClassInitializer(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitializer();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::RecordDecl FieldDecl::Parent(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  throw std::runtime_error("FieldDecl::Parent can return nullptr!");
}

bool FieldDecl::HasCapturedVLAType(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.hasCapturedVLAType();
  return val;
}

bool FieldDecl::HasInClassInitializer(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.hasInClassInitializer();
  return val;
}

bool FieldDecl::IsAnonymousStructOrUnion(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
}

bool FieldDecl::IsBitField(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isBitField();
  return val;
}

bool FieldDecl::IsMutable(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isMutable();
  return val;
}

bool FieldDecl::IsUnnamedBitfield(void) const {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isUnnamedBitfield();
  return val;
}

bool FieldDecl::IsZeroLengthBitField(void) const {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroLengthBitField(ast->ci->getASTContext());
  return val;
}

bool FieldDecl::IsZeroSize(void) const {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroSize(ast->ci->getASTContext());
  return val;
}

std::vector<::pasta::TemplateParameterList> FieldDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.FieldDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FieldDecl->getTemplateParameterList(i)));
  }
  return ret;
}

FunctionDecl::FunctionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, FunctionDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, FunctionDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, FunctionDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, FunctionDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXMethodDecl)
bool FunctionDecl::FriendConstraintRefersToEnclosingTemplate(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.FriendConstraintRefersToEnclosingTemplate();
  return val;
}

bool FunctionDecl::UsesFPIntrin(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.UsesFPIntrin();
  return val;
}

std::optional<bool> FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (self.doesThisDeclarationHaveABody()) {
    return std::nullopt;
  } else {
    return self.doesDeclarationForceExternallyVisibleDefinition();
  }
  decltype(auto) val = self.doesDeclarationForceExternallyVisibleDefinition();
  return val;
}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.doesThisDeclarationHaveABody();
  return val;
}

uint32_t FunctionDecl::BuiltinID(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getBuiltinID();
  return val;
}

::pasta::Type FunctionDecl::CallResultType(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getCallResultType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::FunctionDecl FunctionDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  throw std::runtime_error("FunctionDecl::CanonicalDeclaration can return nullptr!");
}

enum ConstexprSpecKind FunctionDecl::ConstexprKind(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getConstexprKind();
  return static_cast<::pasta::ConstexprSpecKind>(val);
}

::pasta::Type FunctionDecl::DeclaredReturnType(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDeclaredReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::Token FunctionDecl::DefaultToken(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDefaultLoc();
  return ast->TokenAt(val);
}

// 0: FunctionDecl::DefaultedFunctionInfo
std::optional<::pasta::FunctionDecl> FunctionDecl::Definition(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

// 0: FunctionDecl::DependentSpecializationInfo
std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::DescribedFunctionTemplate(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDescribedFunctionTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
}

::pasta::Token FunctionDecl::EllipsisToken(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange FunctionDecl::ExceptionSpecSourceRange(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecSourceRange();
  return ast->TokenRangeFrom(val);
}

enum ExceptionSpecificationType FunctionDecl::ExceptionSpecType(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(val);
}

// 0: FunctionDecl::FunctionTypeToken
std::optional<::pasta::FunctionDecl> FunctionDecl::InstantiatedFromDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getInstantiatedFromDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

std::optional<::pasta::FunctionDecl> FunctionDecl::InstantiatedFromMemberFunction(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getInstantiatedFromMemberFunction();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

enum LanguageLinkage FunctionDecl::LanguageLinkage(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
}

// 0: FunctionDecl::LiteralIdentifier
// 0: FunctionDecl::MemberSpecializationInfo
uint32_t FunctionDecl::MemoryFunctionKind(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMemoryFunctionKind();
  return val;
}

uint32_t FunctionDecl::MinRequiredArguments(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMinRequiredArguments();
  return val;
}

enum MultiVersionKind FunctionDecl::MultiVersionKind(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMultiVersionKind();
  return static_cast<::pasta::MultiVersionKind>(val);
}

// 0: FunctionDecl::NameInfo
uint32_t FunctionDecl::NumParameters(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

std::optional<uint32_t> FunctionDecl::ODRHash(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  auto def = const_cast<clang::FunctionDecl *>(self.getDefinition());
  if (!def) {
    return std::nullopt;
  } else {
    return def->getODRHash();
  }
  decltype(auto) val = self.getODRHash();
  return val;
}

enum OverloadedOperatorKind FunctionDecl::OverloadedOperator(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getOverloadedOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(val);
}

// 1: FunctionDecl::ParameterDeclaration
::pasta::TokenRange FunctionDecl::ParametersSourceRange(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getParametersSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token FunctionDecl::PointOfInstantiation(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::PrimaryTemplate(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPrimaryTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
}

::pasta::Type FunctionDecl::ReturnType(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange FunctionDecl::ReturnTypeSourceRange(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

enum StorageClass FunctionDecl::StorageClass(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
}

std::optional<::pasta::FunctionDecl> FunctionDecl::TemplateInstantiationPattern(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

// 0: FunctionDecl::TemplateSpecializationArguments
// 0: FunctionDecl::TemplateSpecializationArgumentsAsWritten
// 0: FunctionDecl::TemplateSpecializationInfo
enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKind(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKindForInstantiation(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum FunctionDeclTemplatedKind FunctionDecl::TemplatedKind(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplatedKind();
  return static_cast<::pasta::FunctionDeclTemplatedKind>(val);
}

bool FunctionDecl::HasImplicitReturnZero(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasImplicitReturnZero();
  return val;
}

bool FunctionDecl::HasInheritedPrototype(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasInheritedPrototype();
  return val;
}

bool FunctionDecl::HasOneParameterOrDefaultArguments(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasOneParamOrDefaultArgs();
  return val;
}

bool FunctionDecl::HasPrototype(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasPrototype();
  return val;
}

bool FunctionDecl::HasSkippedBody(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
}

bool FunctionDecl::HasTrivialBody(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasTrivialBody();
  return val;
}

bool FunctionDecl::HasWrittenPrototype(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasWrittenPrototype();
  return val;
}

bool FunctionDecl::InstantiationIsPending(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.instantiationIsPending();
  return val;
}

bool FunctionDecl::IsCPUDispatchMultiVersion(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUDispatchMultiVersion();
  return val;
}

bool FunctionDecl::IsCPUSpecificMultiVersion(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUSpecificMultiVersion();
  return val;
}

bool FunctionDecl::IsConsteval(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConsteval();
  return val;
}

bool FunctionDecl::IsConstexpr(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
}

bool FunctionDecl::IsConstexprSpecified(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexprSpecified();
  return val;
}

bool FunctionDecl::IsDefaulted(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDefaulted();
  return val;
}

bool FunctionDecl::IsDeleted(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeleted();
  return val;
}

bool FunctionDecl::IsDeletedAsWritten(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeletedAsWritten();
  return val;
}

bool FunctionDecl::IsDestroyingOperatorDelete(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDestroyingOperatorDelete();
  return val;
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExplicitlyDefaulted();
  return val;
}

bool FunctionDecl::IsExternC(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExternC();
  return val;
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isFunctionTemplateSpecialization();
  return val;
}

bool FunctionDecl::IsGlobal(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isGlobal();
  return val;
}

bool FunctionDecl::IsImplicitlyInstantiable(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isImplicitlyInstantiable();
  return val;
}

bool FunctionDecl::IsInExternCContext(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
}

bool FunctionDecl::IsInExternCXXContext(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
}

bool FunctionDecl::IsIneligibleOrNotSelected(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isIneligibleOrNotSelected();
  return val;
}

bool FunctionDecl::IsInlineBuiltinDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineBuiltinDeclaration();
  return val;
}

std::optional<bool> FunctionDecl::IsInlineDefinitionExternallyVisible(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (!self.doesThisDeclarationHaveABody() &&
      !self.willHaveBody() && !self.hasAttr<clang::AliasAttr>()) {
    return std::nullopt;
  } else if (!self.isInlined()) {
    return std::nullopt;
  }
  clang::ASTContext &ac = self.getASTContext();
  if (ac.getLangOpts().GNUInline || self.hasAttr<clang::GNUInlineAttr>()) {
    return self.isInlineDefinitionExternallyVisible();
  } else if (ac.getLangOpts().CPlusPlus) {
    return std::nullopt;
  } else {
    return self.isInlineDefinitionExternallyVisible();
  }
  decltype(auto) val = self.isInlineDefinitionExternallyVisible();
  return val;
}

bool FunctionDecl::IsInlineSpecified(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
}

bool FunctionDecl::IsInlined(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlined();
  return val;
}

bool FunctionDecl::IsLateTemplateParsed(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isLateTemplateParsed();
  return val;
}

std::optional<bool> FunctionDecl::IsMSExternInline(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (!self.isInlined()) {
    return std::nullopt;
  } else {
    return self.isMSExternInline();
  }
  decltype(auto) val = self.isMSExternInline();
  return val;
}

bool FunctionDecl::IsMSVCRTEntryPoint(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMSVCRTEntryPoint();
  return val;
}

bool FunctionDecl::IsMain(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMain();
  return val;
}

bool FunctionDecl::IsMultiVersion(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMultiVersion();
  return val;
}

bool FunctionDecl::IsNoReturn(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isNoReturn();
  return val;
}

bool FunctionDecl::IsOverloadedOperator(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isOverloadedOperator();
  return val;
}

bool FunctionDecl::IsPure(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isPure();
  return val;
}

bool FunctionDecl::IsReplaceableGlobalAllocationFunction(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isReplaceableGlobalAllocationFunction();
  return val;
}

std::optional<bool> FunctionDecl::IsReservedGlobalPlacementOperator(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) dname = self.getDeclName();
  if (dname.getNameKind() != clang::DeclarationName::CXXOperatorName) {
    return std::nullopt;
  }
  auto oo = dname.getCXXOverloadedOperator();
  if (oo == clang::OO_New || oo == clang::OO_Delete ||
      oo == clang::OO_Array_New || oo == clang::OO_Array_Delete) {
    return self.isReservedGlobalPlacementOperator();
  } else {
    return std::nullopt;
  }
  decltype(auto) val = self.isReservedGlobalPlacementOperator();
  return val;
}

bool FunctionDecl::IsStatic(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isStatic();
  return val;
}

bool FunctionDecl::IsTargetClonesMultiVersion(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTargetClonesMultiVersion();
  return val;
}

bool FunctionDecl::IsTargetMultiVersion(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTargetMultiVersion();
  return val;
}

bool FunctionDecl::IsTemplateInstantiation(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTemplateInstantiation();
  return val;
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationInstantiatedFromAFriendDefinition();
  return val;
}

bool FunctionDecl::IsTrivial(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivial();
  return val;
}

bool FunctionDecl::IsTrivialForCall(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivialForCall();
  return val;
}

bool FunctionDecl::IsUserProvided(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isUserProvided();
  return val;
}

bool FunctionDecl::IsVariadic(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVariadic();
  return val;
}

bool FunctionDecl::IsVirtualAsWritten(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVirtualAsWritten();
  return val;
}

// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
std::vector<::pasta::ParmVarDecl> FunctionDecl::Parameters(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

bool FunctionDecl::UsesSEHTry(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.usesSEHTry();
  return val;
}

bool FunctionDecl::WillHaveBody(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.willHaveBody();
  return val;
}

std::vector<::pasta::TemplateParameterList> FunctionDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.FunctionDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FunctionDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> FunctionDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.FunctionDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FunctionDecl->getParamDecl(i)));
  }
  return ret;
}

std::optional<::pasta::Stmt> FunctionDecl::Body(void) const noexcept {
  const clang::FunctionDecl *decl = u.FunctionDecl;
  const clang::FunctionDecl *def = nullptr;
  if (!decl->hasBody(def) || decl != def) {
    return std::nullopt;
  } else if (def->getDefaultedFunctionInfo()) {
    return std::nullopt;
  } else if (auto body = def->getBody()) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, body);
  } else {
    return std::nullopt;
  }
}

HLSLBufferDecl::HLSLBufferDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, HLSLBufferDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, HLSLBufferDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, HLSLBufferDecl)
::pasta::Token HLSLBufferDecl::LBraceToken(void) const {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token HLSLBufferDecl::TokenStart(void) const {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getLocStart();
  return ast->TokenAt(val);
}

::pasta::Token HLSLBufferDecl::RBraceToken(void) const {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool HLSLBufferDecl::IsCBuffer(void) const {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.isCBuffer();
  return val;
}

IndirectFieldDecl::IndirectFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, IndirectFieldDecl)
std::vector<::pasta::NamedDecl> IndirectFieldDecl::Chain(void) const {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.chain();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: IndirectFieldDecl::
// 0: IndirectFieldDecl::
std::optional<::pasta::FieldDecl> IndirectFieldDecl::AnonymousField(void) const {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  if (self.chain().size() < 2) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAnonField();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
}

::pasta::IndirectFieldDecl IndirectFieldDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::IndirectFieldDecl>(ast, val);
  }
  throw std::runtime_error("IndirectFieldDecl::CanonicalDeclaration can return nullptr!");
}

uint32_t IndirectFieldDecl::ChainingSize(void) const {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.getChainingSize();
  return val;
}

std::optional<::pasta::VarDecl> IndirectFieldDecl::VariableDeclaration(void) const {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  if (self.chain().size() < 2) {
    return std::nullopt;
  }
  decltype(auto) val = self.getVarDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

LabelDecl::LabelDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LabelDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, LabelDecl)
std::string_view LabelDecl::MSAssemblyLabel(void) const {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.getMSAsmLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::LabelStmt LabelDecl::Statement(void) const {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.getStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::LabelStmt>(ast, val);
  }
  throw std::runtime_error("LabelDecl::Statement can return nullptr!");
}

bool LabelDecl::IsGnuLocal(void) const {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isGnuLocal();
  return val;
}

bool LabelDecl::IsMSAssemblyLabel(void) const {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isMSAsmLabel();
  return val;
}

bool LabelDecl::IsResolvedMSAssemblyLabel(void) const {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isResolvedMSAsmLabel();
  return val;
}

MSGuidDecl::MSGuidDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, MSGuidDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, MSGuidDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, MSGuidDecl)
// 0: MSGuidDecl::AsAPValue
// 0: MSGuidDecl::Parts
MSPropertyDecl::MSPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, MSPropertyDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, MSPropertyDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, MSPropertyDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, MSPropertyDecl)
// 0: MSPropertyDecl::GetterId
// 0: MSPropertyDecl::SetterId
bool MSPropertyDecl::HasGetter(void) const {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasGetter();
  return val;
}

bool MSPropertyDecl::HasSetter(void) const {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasSetter();
  return val;
}

std::vector<::pasta::TemplateParameterList> MSPropertyDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.MSPropertyDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.MSPropertyDecl->getTemplateParameterList(i)));
  }
  return ret;
}

NonTypeTemplateParmDecl::NonTypeTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NonTypeTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, NonTypeTemplateParmDecl)
bool NonTypeTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
}

// 0: NonTypeTemplateParmDecl::DefaultArgumentStorage
std::optional<::pasta::Expr> NonTypeTemplateParmDecl::DefaultArgument(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgument();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::Token NonTypeTemplateParmDecl::DefaultArgumentToken(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: NonTypeTemplateParmDecl::ExpansionType
// 1: NonTypeTemplateParmDecl::ExpansionType
std::optional<uint32_t> NonTypeTemplateParmDecl::NumExpansionTypes(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  if (!self.isExpandedParameterPack()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumExpansionTypes();
  return val;
}

std::optional<::pasta::Expr> NonTypeTemplateParmDecl::PlaceholderTypeConstraint(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getPlaceholderTypeConstraint();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasPlaceholderTypeConstraint();
  return val;
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

std::vector<::pasta::TemplateParameterList> NonTypeTemplateParmDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.NonTypeTemplateParmDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.NonTypeTemplateParmDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::Type> NonTypeTemplateParmDecl::ExpansionTypes(void) const {
  std::vector<::pasta::Type> ret;
  if (!u.NonTypeTemplateParmDecl->isExpandedParameterPack()) {
    return ret;
  }
  auto convert_elem = [&] (clang::TypeSourceInfo * val) {
    return TypeBuilder::Build(ast, val->getType());
  };
  auto count = u.NonTypeTemplateParmDecl->getNumExpansionTypes();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.NonTypeTemplateParmDecl->getExpansionTypeSourceInfo(i)));
  }
  return ret;
}

OMPAllocateDecl::OMPAllocateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, OMPAllocateDecl)
PASTA_DEFINE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::Clauses
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
// 0: OMPAllocateDecl::
std::vector<::pasta::Expr> OMPAllocateDecl::Varlists(void) const {
  auto &self = *const_cast<clang::OMPAllocateDecl *>(u.OMPAllocateDecl);
  decltype(auto) val = self.varlists();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

OMPDeclareMapperDecl::OMPDeclareMapperDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveValueDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, OMPDeclareMapperDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, OMPDeclareMapperDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_BASE_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, OMPDeclareMapperDecl)
// 0: OMPDeclareMapperDecl::
// 0: OMPDeclareMapperDecl::
// 0: OMPDeclareMapperDecl::
// 0: OMPDeclareMapperDecl::
// 0: OMPDeclareMapperDecl::Clauses
::pasta::Expr OMPDeclareMapperDecl::MapperVariableReference(void) const {
  auto &self = *const_cast<clang::OMPDeclareMapperDecl *>(u.OMPDeclareMapperDecl);
  decltype(auto) val = self.getMapperVarRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareMapperDecl::MapperVariableReference can return nullptr!");
}

::pasta::OMPDeclareMapperDecl OMPDeclareMapperDecl::PrevDeclarationInScope(void) const {
  auto &self = *const_cast<clang::OMPDeclareMapperDecl *>(u.OMPDeclareMapperDecl);
  decltype(auto) val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareMapperDecl>(ast, val);
  }
  throw std::runtime_error("OMPDeclareMapperDecl::PrevDeclarationInScope can return nullptr!");
}

OMPDeclareReductionDecl::OMPDeclareReductionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
::pasta::Expr OMPDeclareReductionDecl::Combiner(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombiner();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::Combiner can return nullptr!");
}

::pasta::Expr OMPDeclareReductionDecl::CombinerIn(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombinerIn();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::CombinerIn can return nullptr!");
}

::pasta::Expr OMPDeclareReductionDecl::CombinerOut(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombinerOut();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::CombinerOut can return nullptr!");
}

::pasta::Expr OMPDeclareReductionDecl::InitializerOriginal(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitOrig();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::InitializerOriginal can return nullptr!");
}

::pasta::Expr OMPDeclareReductionDecl::InitializerPrivate(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitPriv();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::InitializerPrivate can return nullptr!");
}

::pasta::Expr OMPDeclareReductionDecl::Initializer(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::Initializer can return nullptr!");
}

enum OMPDeclareReductionDeclInitKind OMPDeclareReductionDecl::InitializerKind(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitializerKind();
  return static_cast<::pasta::OMPDeclareReductionDeclInitKind>(val);
}

::pasta::OMPDeclareReductionDecl OMPDeclareReductionDecl::PrevDeclarationInScope(void) const {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareReductionDecl>(ast, val);
  }
  throw std::runtime_error("OMPDeclareReductionDecl::PrevDeclarationInScope can return nullptr!");
}

OMPRequiresDecl::OMPRequiresDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, OMPRequiresDecl)
PASTA_DEFINE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
// 0: OMPRequiresDecl::
// 0: OMPRequiresDecl::
// 0: OMPRequiresDecl::
// 0: OMPRequiresDecl::
// 0: OMPRequiresDecl::Clauses
OMPThreadPrivateDecl::OMPThreadPrivateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, OMPThreadPrivateDecl)
PASTA_DEFINE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
// 0: OMPThreadPrivateDecl::
// 0: OMPThreadPrivateDecl::
// 0: OMPThreadPrivateDecl::
// 0: OMPThreadPrivateDecl::
std::vector<::pasta::Expr> OMPThreadPrivateDecl::Varlists(void) const {
  auto &self = *const_cast<clang::OMPThreadPrivateDecl *>(u.OMPThreadPrivateDecl);
  decltype(auto) val = self.varlists();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
}

ObjCAtDefsFieldDecl::ObjCAtDefsFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
std::vector<::pasta::TemplateParameterList> ObjCAtDefsFieldDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ObjCAtDefsFieldDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCAtDefsFieldDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ObjCCategoryDecl::ObjCCategoryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
bool ObjCCategoryDecl::IsClassExtension(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.IsClassExtension();
  return val;
}

::pasta::Token ObjCCategoryDecl::CategoryNameToken(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCInterfaceDecl ObjCCategoryDecl::ClassInterface(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCategoryDecl::ClassInterface can return nullptr!");
}

::pasta::ObjCCategoryImplDecl ObjCCategoryDecl::Implementation(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryImplDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCategoryDecl::Implementation can return nullptr!");
}

::pasta::Token ObjCCategoryDecl::InstanceVariableLBraceToken(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCCategoryDecl::InstanceVariableRBraceToken(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategory(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getNextClassCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCategoryDecl::NextClassCategory can return nullptr!");
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategoryRaw(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getNextClassCategoryRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCategoryDecl::NextClassCategoryRaw can return nullptr!");
}

// 0: ObjCCategoryDecl::ReferencedProtocols
// 0: ObjCCategoryDecl::TypeParameterList
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCCategoryDecl::InstanceVariables(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::Token> ObjCCategoryDecl::ProtocolTokens(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

// 0: ObjCCategoryDecl::
std::vector<::pasta::ObjCProtocolDecl> ObjCCategoryDecl::Protocols(void) const {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

ObjCCategoryImplDecl::ObjCCategoryImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCCategoryImplDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCategoryImplDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
::pasta::ObjCCategoryDecl ObjCCategoryImplDecl::CategoryDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCCategoryImplDecl *>(u.ObjCCategoryImplDecl);
  decltype(auto) val = self.getCategoryDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  throw std::runtime_error("ObjCCategoryImplDecl::CategoryDeclaration can return nullptr!");
}

::pasta::Token ObjCCategoryImplDecl::CategoryNameToken(void) const {
  auto &self = *const_cast<clang::ObjCCategoryImplDecl *>(u.ObjCCategoryImplDecl);
  decltype(auto) val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
}

ObjCIvarDecl::ObjCIvarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCIvarDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, ObjCIvarDecl)
PASTA_DEFINE_BASE_OPERATORS(FieldDecl, ObjCIvarDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCIvarDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, ObjCIvarDecl)
enum ObjCIvarDeclAccessControl ObjCIvarDecl::AccessControl(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getAccessControl();
  return static_cast<::pasta::ObjCIvarDeclAccessControl>(val);
}

enum ObjCIvarDeclAccessControl ObjCIvarDecl::CanonicalAccessControl(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getCanonicalAccessControl();
  return static_cast<::pasta::ObjCIvarDeclAccessControl>(val);
}

::pasta::ObjCIvarDecl ObjCIvarDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCIvarDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::ObjCInterfaceDecl ObjCIvarDecl::ContainingInterface(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getContainingInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  throw std::runtime_error("ObjCIvarDecl::ContainingInterface can return nullptr!");
}

::pasta::ObjCIvarDecl ObjCIvarDecl::NextInstanceVariable(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getNextIvar();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  throw std::runtime_error("ObjCIvarDecl::NextInstanceVariable can return nullptr!");
}

bool ObjCIvarDecl::Synthesize(void) const {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getSynthesize();
  return val;
}

// 1: ObjCIvarDecl::UsageType
std::vector<::pasta::TemplateParameterList> ObjCIvarDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ObjCIvarDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ObjCIvarDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ObjCTypeParamDecl::ObjCTypeParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
::pasta::Token ObjCTypeParamDecl::ColonToken(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCTypeParamDecl::Index(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getIndex();
  return val;
}

enum ObjCTypeParamVariance ObjCTypeParamDecl::Variance(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVariance();
  return static_cast<::pasta::ObjCTypeParamVariance>(val);
}

::pasta::Token ObjCTypeParamDecl::VarianceToken(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVarianceLoc();
  return ast->TokenAt(val);
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.hasExplicitBound();
  return val;
}

RedeclarableTemplateDecl::RedeclarableTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, RedeclarableTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  throw std::runtime_error("RedeclarableTemplateDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  throw std::runtime_error("RedeclarableTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
}

bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.isMemberSpecialization();
  return val;
}

TagDecl::TagDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, TagDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, TagDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TagDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, RecordDecl)
::pasta::TokenRange TagDecl::BraceRange(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getBraceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TagDecl TagDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  throw std::runtime_error("TagDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::TagDecl> TagDecl::Definition(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
}

::pasta::Token TagDecl::FirstInnerToken(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

std::string_view TagDecl::KindName(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t TagDecl::NumTemplateParameterLists(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token TagDecl::FirstOuterToken(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: TagDecl::Qualifier
// 0: TagDecl::QualifierToken
enum TagTypeKind TagDecl::TagKind(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTagKind();
  return static_cast<::pasta::TagTypeKind>(val);
}

// 1: TagDecl::TemplateParameterList
std::optional<::pasta::TypedefNameDecl> TagDecl::TypedefNameForAnonymousDeclaration(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTypedefNameForAnonDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
}

bool TagDecl::HasNameForLinkage(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.hasNameForLinkage();
  return val;
}

bool TagDecl::IsBeingDefined(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isBeingDefined();
  return val;
}

bool TagDecl::IsClass(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isClass();
  return val;
}

bool TagDecl::IsCompleteDefinition(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinition();
  return val;
}

bool TagDecl::IsCompleteDefinitionRequired(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinitionRequired();
  return val;
}

bool TagDecl::IsDependentType(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isDependentType();
  return val;
}

bool TagDecl::IsEmbeddedInDeclarator(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEmbeddedInDeclarator();
  return val;
}

bool TagDecl::IsEnum(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEnum();
  return val;
}

bool TagDecl::IsFreeStanding(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isFreeStanding();
  return val;
}

bool TagDecl::IsInterface(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isInterface();
  return val;
}

bool TagDecl::IsStruct(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isStruct();
  return val;
}

bool TagDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool TagDecl::IsThisDeclarationADemotedDefinition(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isThisDeclarationADemotedDefinition();
  return val;
}

bool TagDecl::IsUnion(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isUnion();
  return val;
}

bool TagDecl::MayHaveOutOfDateDefinition(void) const {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.mayHaveOutOfDateDef();
  return val;
}

std::vector<::pasta::TemplateParameterList> TagDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.TagDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.TagDecl->getTemplateParameterList(i)));
  }
  return ret;
}

TemplateParamObjectDecl::TemplateParamObjectDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateParamObjectDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateParamObjectDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, TemplateParamObjectDecl)
::pasta::TemplateParamObjectDecl TemplateParamObjectDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::TemplateParamObjectDecl *>(u.TemplateParamObjectDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateParamObjectDecl>(ast, val);
  }
  throw std::runtime_error("TemplateParamObjectDecl::CanonicalDeclaration can return nullptr!");
}

// 0: TemplateParamObjectDecl::Value
TemplateTypeParmDecl::TemplateTypeParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateTypeParmDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateTypeParmDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TemplateTypeParmDecl)
bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
}

// 0: TemplateTypeParmDecl::DefaultArgumentStorage
std::optional<::pasta::Type> TemplateTypeParmDecl::DefaultArgument(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  if (!self.getDefaultArgumentInfo()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getDefaultArgument();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> TemplateTypeParmDecl::DefaultArgumentInfo(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

::pasta::Token TemplateTypeParmDecl::DefaultArgumentToken(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

uint32_t TemplateTypeParmDecl::Depth(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDepth();
  return val;
}

uint32_t TemplateTypeParmDecl::Index(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getIndex();
  return val;
}

uint32_t TemplateTypeParmDecl::NumExpansionParameters(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getNumExpansionParameters();
  return val;
}

// 0: TemplateTypeParmDecl::TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasTypeConstraint();
  return val;
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool TemplateTypeParmDecl::IsParameterPack(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.wasDeclaredWithTypename();
  return val;
}

TypeAliasDecl::TypeAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(TypedefNameDecl, TypeAliasDecl)
std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasDecl::DescribedAliasTemplate(void) const {
  auto &self = *const_cast<clang::TypeAliasDecl *>(u.TypeAliasDecl);
  decltype(auto) val = self.getDescribedAliasTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
}

TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  throw std::runtime_error("TypeAliasTemplateDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
}

std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasTemplateDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
}

::pasta::TypeAliasDecl TypeAliasTemplateDecl::TemplatedDeclaration(void) const {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasDecl>(ast, val);
  }
  throw std::runtime_error("TypeAliasTemplateDecl::TemplatedDeclaration can return nullptr!");
}

TypedefDecl::TypedefDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypedefDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypedefDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TypedefDecl)
PASTA_DEFINE_BASE_OPERATORS(TypedefNameDecl, TypedefDecl)
UnnamedGlobalConstantDecl::UnnamedGlobalConstantDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnnamedGlobalConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnnamedGlobalConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, UnnamedGlobalConstantDecl)
// 0: UnnamedGlobalConstantDecl::Value
UnresolvedUsingValueDecl::UnresolvedUsingValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnresolvedUsingValueDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
::pasta::UnresolvedUsingValueDecl UnresolvedUsingValueDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingValueDecl>(ast, val);
  }
  throw std::runtime_error("UnresolvedUsingValueDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::Token UnresolvedUsingValueDecl::EllipsisToken(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingValueDecl::NameInfo
// 0: UnresolvedUsingValueDecl::Qualifier
// 0: UnresolvedUsingValueDecl::QualifierToken
::pasta::Token UnresolvedUsingValueDecl::UsingToken(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.isAccessDeclaration();
  return val;
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

UsingDecl::UsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : BaseUsingDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(BaseUsingDecl, UsingDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDecl)
::pasta::UsingDecl UsingDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  throw std::runtime_error("UsingDecl::CanonicalDeclaration can return nullptr!");
}

// 0: UsingDecl::NameInfo
// 0: UsingDecl::Qualifier
// 0: UsingDecl::QualifierToken
::pasta::Token UsingDecl::UsingToken(void) const {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UsingDecl::HasTypename(void) const {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.hasTypename();
  return val;
}

bool UsingDecl::IsAccessDeclaration(void) const {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.isAccessDeclaration();
  return val;
}

UsingEnumDecl::UsingEnumDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : BaseUsingDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(BaseUsingDecl, UsingEnumDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, UsingEnumDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingEnumDecl)
::pasta::UsingEnumDecl UsingEnumDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingEnumDecl>(ast, val);
  }
  throw std::runtime_error("UsingEnumDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::EnumDecl UsingEnumDecl::EnumDeclaration(void) const {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  throw std::runtime_error("UsingEnumDecl::EnumDeclaration can return nullptr!");
}

::pasta::Token UsingEnumDecl::EnumToken(void) const {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumLoc();
  return ast->TokenAt(val);
}

::pasta::Type UsingEnumDecl::EnumType(void) const {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumType();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("UsingEnumDecl::EnumType can return nullptr!");
}

// 0: UsingEnumDecl::EnumTypeToken
// 0: UsingEnumDecl::Qualifier
// 0: UsingEnumDecl::QualifierToken
::pasta::Token UsingEnumDecl::UsingToken(void) const {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

VarDecl::VarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, VarDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, VarDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, VarDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
// 1: VarDecl::CheckForConstantInitialization
// 0: VarDecl::EnsureEvaluatedStatement
// 1: VarDecl::EvaluateDestruction
// 0: VarDecl::EvaluateValue
std::optional<::pasta::VarDecl> VarDecl::ActingDefinition(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getActingDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

::pasta::VarDecl VarDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("VarDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::VarTemplateDecl> VarDecl::DescribedVariableTemplate(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getDescribedVarTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
}

// 0: VarDecl::EvaluatedStatement
// 0: VarDecl::EvaluatedValue
// 1: VarDecl::FlexibleArrayInitializerCharacters
std::optional<::pasta::Expr> VarDecl::Initializer(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

enum VarDeclInitializationStyle VarDecl::InitializerStyle(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitStyle();
  return static_cast<::pasta::VarDeclInitializationStyle>(val);
}

std::optional<::pasta::VarDecl> VarDecl::InitializingDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitializingDeclaration();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

std::optional<::pasta::VarDecl> VarDecl::InstantiatedFromStaticDataMember(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInstantiatedFromStaticDataMember();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

enum LanguageLinkage VarDecl::LanguageLinkage(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
}

// 0: VarDecl::MemberSpecializationInfo
::pasta::Token VarDecl::PointOfInstantiation(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum StorageClass VarDecl::StorageClass(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
}

enum StorageDuration VarDecl::StorageDuration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
}

enum VarDeclTLSKind VarDecl::TLSKind(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTLSKind();
  return static_cast<::pasta::VarDeclTLSKind>(val);
}

enum ThreadStorageClassSpecifier VarDecl::TSCSpec(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTSCSpec();
  return static_cast<::pasta::ThreadStorageClassSpecifier>(val);
}

std::optional<::pasta::VarDecl> VarDecl::TemplateInstantiationPattern(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKind(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKindForInstantiation(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

bool VarDecl::HasConstantInitialization(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasConstantInitialization();
  return val;
}

bool VarDecl::HasDependentAlignment(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasDependentAlignment();
  return val;
}

bool VarDecl::HasExternalStorage(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasExternalStorage();
  return val;
}

std::optional<bool> VarDecl::HasFlexibleArrayInitializer(void) const {
  auto &self = *(u.VarDecl);
  if (!self.hasInit()) {
    return std::nullopt;
  }
  auto *init_list = clang::dyn_cast<clang::InitListExpr>(
      self.getInit()->IgnoreParens());
  if (!init_list || !init_list->getNumInits()) {
    return false;
  }
  decltype(auto) val = self.hasFlexibleArrayInit(ast->ci->getASTContext());
  return val;
}

bool VarDecl::HasGlobalStorage(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasGlobalStorage();
  return val;
}

std::optional<bool> VarDecl::HasICEInitializer(void) const {
  auto &self = *(u.VarDecl);
  if (auto init = self.getInit(); !init || init->isValueDependent()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasICEInitializer(ast->ci->getASTContext());
  return val;
}

bool VarDecl::HasInitializer(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasInit();
  return val;
}

bool VarDecl::HasLocalStorage(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasLocalStorage();
  return val;
}

bool VarDecl::IsARCPseudoStrong(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isARCPseudoStrong();
  return val;
}

bool VarDecl::IsCXXForRangeDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isCXXForRangeDecl();
  return val;
}

bool VarDecl::IsConstexpr(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
}

bool VarDecl::IsDirectInitializer(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isDirectInit();
  return val;
}

bool VarDecl::IsEscapingByref(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isEscapingByref();
  return val;
}

bool VarDecl::IsExceptionVariable(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExceptionVariable();
  return val;
}

bool VarDecl::IsExternC(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExternC();
  return val;
}

bool VarDecl::IsFileVariableDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFileVarDecl();
  return val;
}

bool VarDecl::IsFunctionOrMethodVariableDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFunctionOrMethodVarDecl();
  return val;
}

bool VarDecl::IsInExternCContext(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
}

bool VarDecl::IsInExternCXXContext(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
}

bool VarDecl::IsInitializerCapture(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInitCapture();
  return val;
}

bool VarDecl::IsInline(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInline();
  return val;
}

bool VarDecl::IsInlineSpecified(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
}

bool VarDecl::IsKnownToBeDefined(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isKnownToBeDefined();
  return val;
}

bool VarDecl::IsLocalVariableDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDecl();
  return val;
}

bool VarDecl::IsLocalVariableDeclarationOrParm(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDeclOrParm();
  return val;
}

bool VarDecl::IsNRVOVariable(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNRVOVariable();
  return val;
}

bool VarDecl::IsNoDestroy(void) const {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isNoDestroy(ast->ci->getASTContext());
  return val;
}

bool VarDecl::IsNonEscapingByref(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNonEscapingByref();
  return val;
}

bool VarDecl::IsObjCForDeclaration(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isObjCForDecl();
  return val;
}

bool VarDecl::IsParameterPack(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool VarDecl::IsPreviousDeclarationInSameBlockScope(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isPreviousDeclInSameBlockScope();
  return val;
}

bool VarDecl::IsStaticDataMember(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticDataMember();
  return val;
}

bool VarDecl::IsStaticLocal(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticLocal();
  return val;
}

bool VarDecl::IsThisDeclarationADemotedDefinition(void) const {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isThisDeclarationADemotedDefinition();
  return val;
}

bool VarDecl::IsUsableInConstantExpressions(void) const {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

bool VarDecl::MightBeUsableInConstantExpressions(void) const {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.mightBeUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

// 1: VarDecl::NeedsDestruction
std::vector<::pasta::TemplateParameterList> VarDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.VarDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.VarDecl->getTemplateParameterList(i)));
  }
  return ret;
}

VarTemplateDecl::VarTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, VarTemplateDecl)
::pasta::VarTemplateDecl VarTemplateDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplateDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::VarTemplateDecl VarTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
}

::pasta::VarTemplateDecl VarTemplateDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplateDecl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::VarTemplateDecl> VarTemplateDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
}

::pasta::VarDecl VarTemplateDecl::TemplatedDeclaration(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplateDecl::TemplatedDeclaration can return nullptr!");
}

bool VarTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

// 0: VarTemplateDecl::
// 0: VarTemplateDecl::
std::vector<::pasta::VarTemplateSpecializationDecl> VarTemplateDecl::Specializations(void) const {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::VarTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::VarTemplateSpecializationDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

VarTemplateSpecializationDecl::VarTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, VarTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, VarTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
::pasta::Token VarTemplateSpecializationDecl::ExternToken(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFrom();
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::VarTemplateDecl *>()) {
      ret = DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::VarTemplatePartialSpecializationDecl *>()) {
      ret = DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, b_ptr);
    } else {
      ret = {};
    }
  } else {
    ret = {};
  }
  return ret;
}

::pasta::Token VarTemplateSpecializationDecl::PointOfInstantiation(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum TemplateSpecializationKind VarTemplateSpecializationDecl::SpecializationKind(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

::pasta::VarTemplateDecl VarTemplateSpecializationDecl::SpecializedTemplate(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplateOrPartial();
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::VarTemplateDecl *>()) {
      ret = DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::VarTemplatePartialSpecializationDecl *>()) {
      ret = DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, b_ptr);
    } else {
      ret = {};
    }
  } else {
    ret = {};
  }
  return ret;
}

std::vector<::pasta::TemplateArgument> VarTemplateSpecializationDecl::TemplateArguments(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
}

// 0: VarTemplateSpecializationDecl::TemplateArgumentsInfo
std::vector<::pasta::TemplateArgument> VarTemplateSpecializationDecl::TemplateInstantiationArguments(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateInstantiationArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
}

::pasta::Token VarTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Type VarTemplateSpecializationDecl::TypeAsWritten(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val->getType());
  throw std::runtime_error("VarTemplateSpecializationDecl::TypeAsWritten can return nullptr!");
}

bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
}

std::vector<::pasta::TemplateParameterList> VarTemplateSpecializationDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.VarTemplateSpecializationDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.VarTemplateSpecializationDecl->getTemplateParameterList(i)));
  }
  return ret;
}

CXXDeductionGuideDecl::CXXDeductionGuideDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXDeductionGuideDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXDeductionGuideDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_BASE_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, CXXDeductionGuideDecl)
::pasta::CXXConstructorDecl CXXDeductionGuideDecl::CorrespondingConstructor(void) const {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.getCorrespondingConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  throw std::runtime_error("CXXDeductionGuideDecl::CorrespondingConstructor can return nullptr!");
}

::pasta::TemplateDecl CXXDeductionGuideDecl::DeducedTemplate(void) const {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.getDeducedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  throw std::runtime_error("CXXDeductionGuideDecl::DeducedTemplate can return nullptr!");
}

// 0: CXXDeductionGuideDecl::ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.isCopyDeductionCandidate();
  return val;
}

bool CXXDeductionGuideDecl::IsExplicit(void) const {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

std::vector<::pasta::ParmVarDecl> CXXDeductionGuideDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXDeductionGuideDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDeductionGuideDecl->getParamDecl(i)));
  }
  return ret;
}

std::vector<::pasta::TemplateParameterList> CXXDeductionGuideDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXDeductionGuideDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDeductionGuideDecl->getTemplateParameterList(i)));
  }
  return ret;
}

CXXMethodDecl::CXXMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, CXXMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(FunctionDecl, CXXMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXMethodDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
// 0: CXXMethodDecl::
// 0: CXXMethodDecl::
::pasta::CXXMethodDecl CXXMethodDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  throw std::runtime_error("CXXMethodDecl::CanonicalDeclaration can return nullptr!");
}

// 1: CXXMethodDecl::CorrespondingMethodDeclaredInClass
// 1: CXXMethodDecl::CorrespondingMethodInClass
// 2: DevirtualizedMethod
// 0: CXXMethodDecl::MethodQualifiers
::pasta::CXXMethodDecl CXXMethodDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  throw std::runtime_error("CXXMethodDecl::MostRecentDeclaration can return nullptr!");
}

::pasta::CXXRecordDecl CXXMethodDecl::Parent(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("CXXMethodDecl::Parent can return nullptr!");
}

enum RefQualifierKind CXXMethodDecl::ReferenceQualifier(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(val);
}

std::optional<::pasta::Type> CXXMethodDecl::ThisObjectType(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  if (!self.isInstance()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getThisObjectType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Type> CXXMethodDecl::ThisType(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  if (!self.isInstance()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getThisType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

bool CXXMethodDecl::HasInlineBody(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.hasInlineBody();
  return val;
}

bool CXXMethodDecl::IsConst(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isConst();
  return val;
}

bool CXXMethodDecl::IsCopyAssignmentOperator(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isCopyAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsInstance(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isInstance();
  return val;
}

bool CXXMethodDecl::IsLambdaStaticInvoker(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isLambdaStaticInvoker();
  return val;
}

bool CXXMethodDecl::IsMoveAssignmentOperator(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isMoveAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsStatic(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isStatic();
  return val;
}

// 1: CXXMethodDecl::IsUsualDeallocationFunction
bool CXXMethodDecl::IsVirtual(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVirtual();
  return val;
}

bool CXXMethodDecl::IsVolatile(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVolatile();
  return val;
}

std::vector<::pasta::CXXMethodDecl> CXXMethodDecl::OverriddenMethods(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.overridden_methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

uint32_t CXXMethodDecl::SizeOverriddenMethods(void) const {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.size_overridden_methods();
  return val;
}

std::vector<::pasta::ParmVarDecl> CXXMethodDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXMethodDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXMethodDecl->getParamDecl(i)));
  }
  return ret;
}

std::vector<::pasta::TemplateParameterList> CXXMethodDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXMethodDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXMethodDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ClassTemplateDecl::ClassTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, ClassTemplateDecl)
::pasta::ClassTemplateDecl ClassTemplateDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplateDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::ClassTemplateDecl ClassTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
}

::pasta::ClassTemplateDecl ClassTemplateDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplateDecl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::ClassTemplateDecl> ClassTemplateDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
}

::pasta::CXXRecordDecl ClassTemplateDecl::TemplatedDeclaration(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplateDecl::TemplatedDeclaration can return nullptr!");
}

bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

// 0: ClassTemplateDecl::
// 0: ClassTemplateDecl::
std::vector<::pasta::ClassTemplateSpecializationDecl> ClassTemplateDecl::Specializations(void) const {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::ClassTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ClassTemplateSpecializationDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

DecompositionDecl::DecompositionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, DecompositionDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, DecompositionDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, DecompositionDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, DecompositionDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, DecompositionDecl)
std::vector<::pasta::BindingDecl> DecompositionDecl::Bindings(void) const {
  auto &self = *const_cast<clang::DecompositionDecl *>(u.DecompositionDecl);
  decltype(auto) val = self.bindings();
  std::vector<::pasta::BindingDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::BindingDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::TemplateParameterList> DecompositionDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.DecompositionDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.DecompositionDecl->getTemplateParameterList(i)));
  }
  return ret;
}

EnumDecl::EnumDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, EnumDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, EnumDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, EnumDecl)
PASTA_DEFINE_BASE_OPERATORS(TagDecl, EnumDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, EnumDecl)
// 0: EnumDecl::
// 0: EnumDecl::
std::vector<::pasta::EnumConstantDecl> EnumDecl::Enumerators(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.enumerators();
  std::vector<::pasta::EnumConstantDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::EnumDecl EnumDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  throw std::runtime_error("EnumDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::EnumDecl EnumDecl::Definition(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  throw std::runtime_error("EnumDecl::Definition can return nullptr!");
}

std::optional<::pasta::EnumDecl> EnumDecl::InstantiatedFromMemberEnum(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getInstantiatedFromMemberEnum();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
}

std::optional<::pasta::Type> EnumDecl::IntegerType(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  if (self.getIntegerType().isNull()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getIntegerType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange EnumDecl::IntegerTypeRange(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getIntegerTypeRange();
  return ast->TokenRangeFrom(val);
}

// 0: EnumDecl::MemberSpecializationInfo
::pasta::EnumDecl EnumDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  throw std::runtime_error("EnumDecl::MostRecentDeclaration can return nullptr!");
}

uint32_t EnumDecl::NumNegativeBits(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getNumNegativeBits();
  return val;
}

uint32_t EnumDecl::NumPositiveBits(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getNumPositiveBits();
  return val;
}

std::optional<uint32_t> EnumDecl::ODRHash(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  auto def = const_cast<clang::EnumDecl *>(self.getDefinition());
  if (!def) {
    return std::nullopt;
  } else {
    return def->getODRHash();
  }
  decltype(auto) val = self.getODRHash();
  return val;
}

std::optional<::pasta::EnumDecl> EnumDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
}

std::optional<::pasta::Type> EnumDecl::PromotionType(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPromotionType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::EnumDecl> EnumDecl::TemplateInstantiationPattern(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
}

enum TemplateSpecializationKind EnumDecl::TemplateSpecializationKind(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

bool EnumDecl::IsClosed(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosed();
  return val;
}

bool EnumDecl::IsClosedFlag(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedFlag();
  return val;
}

bool EnumDecl::IsClosedNonFlag(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedNonFlag();
  return val;
}

bool EnumDecl::IsComplete(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isComplete();
  return val;
}

bool EnumDecl::IsFixed(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isFixed();
  return val;
}

bool EnumDecl::IsScoped(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScoped();
  return val;
}

bool EnumDecl::IsScopedUsingClassTag(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScopedUsingClassTag();
  return val;
}

std::vector<::pasta::TemplateParameterList> EnumDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.EnumDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.EnumDecl->getTemplateParameterList(i)));
  }
  return ret;
}

FunctionTemplateDecl::FunctionTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, FunctionTemplateDecl)
::pasta::FunctionTemplateDecl FunctionTemplateDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  throw std::runtime_error("FunctionTemplateDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  throw std::runtime_error("FunctionTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  throw std::runtime_error("FunctionTemplateDecl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::FunctionTemplateDecl> FunctionTemplateDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
}

::pasta::FunctionDecl FunctionTemplateDecl::TemplatedDeclaration(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  throw std::runtime_error("FunctionTemplateDecl::TemplatedDeclaration can return nullptr!");
}

bool FunctionTemplateDecl::IsAbbreviated(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.isAbbreviated();
  return val;
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

// 0: FunctionTemplateDecl::
// 0: FunctionTemplateDecl::
std::vector<::pasta::FunctionDecl> FunctionTemplateDecl::Specializations(void) const {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::FunctionDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

ImplicitParamDecl::ImplicitParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ImplicitParamDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, ImplicitParamDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ImplicitParamDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, ImplicitParamDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, ImplicitParamDecl)
enum ImplicitParamDeclImplicitParamKind ImplicitParamDecl::ParameterKind(void) const {
  auto &self = *const_cast<clang::ImplicitParamDecl *>(u.ImplicitParamDecl);
  decltype(auto) val = self.getParameterKind();
  return static_cast<::pasta::ImplicitParamDeclImplicitParamKind>(val);
}

std::vector<::pasta::TemplateParameterList> ImplicitParamDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ImplicitParamDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ImplicitParamDecl->getTemplateParameterList(i)));
  }
  return ret;
}

OMPCapturedExprDecl::OMPCapturedExprDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, OMPCapturedExprDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, OMPCapturedExprDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, OMPCapturedExprDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, OMPCapturedExprDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, OMPCapturedExprDecl)
std::vector<::pasta::TemplateParameterList> OMPCapturedExprDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.OMPCapturedExprDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.OMPCapturedExprDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ParmVarDecl::ParmVarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ParmVarDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, ParmVarDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ParmVarDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, ParmVarDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, ParmVarDecl)
std::optional<::pasta::Expr> ParmVarDecl::DefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  if (HasUninstantiatedDefaultArgument() ||
      HasUnparsedDefaultArgument()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getDefaultArg();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

::pasta::TokenRange ParmVarDecl::DefaultArgumentRange(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getDefaultArgRange();
  return ast->TokenRangeFrom(val);
}

uint32_t ParmVarDecl::FunctionScopeDepth(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeDepth();
  return val;
}

uint32_t ParmVarDecl::FunctionScopeIndex(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeIndex();
  return val;
}

enum DeclObjCDeclQualifier ParmVarDecl::ObjCDeclQualifier(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
}

::pasta::Type ParmVarDecl::OriginalType(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getOriginalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Expr> ParmVarDecl::UninstantiatedDefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  if (!HasUninstantiatedDefaultArgument()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getUninstantiatedDefaultArg();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

bool ParmVarDecl::HasDefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasDefaultArg();
  return val;
}

bool ParmVarDecl::HasInheritedDefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasInheritedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUninstantiatedDefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUninstantiatedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUnparsedDefaultArgument(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUnparsedDefaultArg();
  return val;
}

bool ParmVarDecl::IsDestroyedInCallee(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isDestroyedInCallee();
  return val;
}

bool ParmVarDecl::IsKNRPromoted(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isKNRPromoted();
  return val;
}

bool ParmVarDecl::IsObjCMethodParameter(void) const {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isObjCMethodParameter();
  return val;
}

std::vector<::pasta::TemplateParameterList> ParmVarDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ParmVarDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ParmVarDecl->getTemplateParameterList(i)));
  }
  return ret;
}

RecordDecl::RecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, RecordDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, RecordDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, RecordDecl)
PASTA_DEFINE_BASE_OPERATORS(TagDecl, RecordDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
bool RecordDecl::CanPassInRegisters(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.canPassInRegisters();
  return val;
}

// 0: RecordDecl::
// 0: RecordDecl::
// 0: RecordDecl::
std::vector<::pasta::FieldDecl> RecordDecl::Fields(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.fields();
  std::vector<::pasta::FieldDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FieldDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::optional<::pasta::FieldDecl> RecordDecl::FirstNamedDataMember(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.findFirstNamedDataMember();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
}

enum RecordDeclArgPassingKind RecordDecl::ArgumentPassingRestrictions(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getArgPassingRestrictions();
  return static_cast<::pasta::RecordDeclArgPassingKind>(val);
}

std::optional<::pasta::RecordDecl> RecordDecl::Definition(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
}

::pasta::RecordDecl RecordDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  throw std::runtime_error("RecordDecl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::RecordDecl> RecordDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
}

bool RecordDecl::HasFlexibleArrayMember(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasFlexibleArrayMember();
  return val;
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasLoadedFieldsFromExternalStorage();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool RecordDecl::HasObjectMember(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasObjectMember();
  return val;
}

bool RecordDecl::HasVolatileMember(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasVolatileMember();
  return val;
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
}

bool RecordDecl::IsCapturedRecord(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isCapturedRecord();
  return val;
}

bool RecordDecl::IsInjectedClassName(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isInjectedClassName();
  return val;
}

bool RecordDecl::IsLambda(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
}

bool RecordDecl::IsMsStruct(void) const {
  auto &self = *(u.RecordDecl);
  decltype(auto) val = self.isMsStruct(ast->ci->getASTContext());
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveCopy();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDestroy();
  return val;
}

bool RecordDecl::IsOrContainsUnion(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isOrContainsUnion();
  return val;
}

bool RecordDecl::IsParameterDestroyedInCallee(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isParamDestroyedInCallee();
  return val;
}

bool RecordDecl::IsRandomized(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isRandomized();
  return val;
}

bool RecordDecl::MayInsertExtraPadding(void) const {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.mayInsertExtraPadding();
  return val;
}

std::vector<::pasta::TemplateParameterList> RecordDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.RecordDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.RecordDecl->getTemplateParameterList(i)));
  }
  return ret;
}

VarTemplatePartialSpecializationDecl::VarTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarTemplateSpecializationDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
::pasta::VarTemplatePartialSpecializationDecl VarTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, val);
  }
  throw std::runtime_error("VarTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
}

// 0: VarTemplatePartialSpecializationDecl::TemplateArgumentsAsWritten
::pasta::TemplateParameterList VarTemplatePartialSpecializationDecl::TemplateParameters(void) const {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  throw std::runtime_error("VarTemplatePartialSpecializationDecl::TemplateParameters can return nullptr!");
}

bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
}

std::vector<::pasta::TemplateParameterList> VarTemplatePartialSpecializationDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.VarTemplatePartialSpecializationDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.VarTemplatePartialSpecializationDecl->getTemplateParameterList(i)));
  }
  return ret;
}

CXXConstructorDecl::CXXConstructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(FunctionDecl, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXConstructorDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, CXXConstructorDecl)
::pasta::CXXConstructorDecl CXXConstructorDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  throw std::runtime_error("CXXConstructorDecl::CanonicalDeclaration can return nullptr!");
}

// 0: CXXConstructorDecl::ExplicitSpecifier
// 0: CXXConstructorDecl::InheritedConstructor
uint32_t CXXConstructorDecl::NumConstructorInitializers(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.getNumCtorInitializers();
  return val;
}

std::optional<::pasta::CXXConstructorDecl> CXXConstructorDecl::TargetConstructor(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  if (!self.isDelegatingConstructor()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTargetConstructor();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
}

// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::Initializers
bool CXXConstructorDecl::IsConvertingConstructor(bool b) const {
  auto &self = *(u.CXXConstructorDecl);
  decltype(auto) val = self.isConvertingConstructor(b);
  return val;
}

bool CXXConstructorDecl::IsDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDefaultConstructor();
  return val;
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDelegatingConstructor();
  return val;
}

bool CXXConstructorDecl::IsExplicit(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isInheritingConstructor();
  return val;
}

bool CXXConstructorDecl::IsSpecializationCopyingObject(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isSpecializationCopyingObject();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXConstructorDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXConstructorDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConstructorDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXConstructorDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXConstructorDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConstructorDecl->getParamDecl(i)));
  }
  return ret;
}

CXXConversionDecl::CXXConversionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(CXXMethodDecl, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(FunctionDecl, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXConversionDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, CXXConversionDecl)
::pasta::CXXConversionDecl CXXConversionDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConversionDecl>(ast, val);
  }
  throw std::runtime_error("CXXConversionDecl::CanonicalDeclaration can return nullptr!");
}

::pasta::Type CXXConversionDecl::ConversionType(void) const {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.getConversionType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

// 0: CXXConversionDecl::ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

bool CXXConversionDecl::IsLambdaToBlockPointerConversion(void) const {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isLambdaToBlockPointerConversion();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXConversionDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXConversionDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConversionDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXConversionDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXConversionDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConversionDecl->getParamDecl(i)));
  }
  return ret;
}

CXXDestructorDecl::CXXDestructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(FunctionDecl, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXDestructorDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, CXXDestructorDecl)
::pasta::CXXDestructorDecl CXXDestructorDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  throw std::runtime_error("CXXDestructorDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::FunctionDecl> CXXDestructorDecl::OperatorDelete(void) const {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDelete();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

std::optional<::pasta::Expr> CXXDestructorDecl::OperatorDeleteThisArgument(void) const {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDeleteThisArg();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
}

std::vector<::pasta::TemplateParameterList> CXXDestructorDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXDestructorDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDestructorDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXDestructorDecl::ParameterDeclarations(void) const {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    throw std::runtime_error("The unreachable has been reached");
  };
  auto count = u.CXXDestructorDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDestructorDecl->getParamDecl(i)));
  }
  return ret;
}

CXXRecordDecl::CXXRecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RecordDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CXXRecordDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CXXRecordDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, CXXRecordDecl)
PASTA_DEFINE_BASE_OPERATORS(RecordDecl, CXXRecordDecl)
PASTA_DEFINE_BASE_OPERATORS(TagDecl, CXXRecordDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
std::optional<bool> CXXRecordDecl::AllowConstDefaultInitializer(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.allowConstDefaultInit();
  return val;
}

std::optional<std::vector<::pasta::CXXBaseSpecifier>> CXXRecordDecl::Bases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.bases();
  std::vector<::pasta::CXXBaseSpecifier> ret;
  for (const auto &bs : val) {
    ret.emplace_back(ast, bs);
  }
  return ret;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<enum MSInheritanceModel> CXXRecordDecl::CalculateInheritanceModel(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.calculateInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::Captures
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::CXXConstructorDecl> CXXRecordDecl::Constructors(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.ctors();
  std::vector<::pasta::CXXConstructorDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::optional<bool> CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedCopyConstructorIsDeleted();
  return val;
}

std::optional<bool> CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDefaultConstructorIsConstexpr();
  return val;
}

std::optional<bool> CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDestructorIsConstexpr();
  return val;
}

std::optional<bool> CXXRecordDecl::DefaultedDestructorIsDeleted(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDestructorIsDeleted();
  return val;
}

std::optional<bool> CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedMoveConstructorIsDeleted();
  return val;
}

// 1: CXXRecordDecl::ForallBases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<std::vector<::pasta::FriendDecl>> CXXRecordDecl::Friends(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.friends();
  std::vector<::pasta::FriendDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FriendDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

::pasta::CXXRecordDecl CXXRecordDecl::CanonicalDeclaration(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("CXXRecordDecl::CanonicalDeclaration can return nullptr!");
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::Definition(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<::pasta::FunctionTemplateDecl> CXXRecordDecl::DependentLambdaCallOperator(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDependentLambdaCallOperator();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
}

std::optional<::pasta::ClassTemplateDecl> CXXRecordDecl::DescribedClassTemplate(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDescribedClassTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
}

std::optional<::pasta::CXXDestructorDecl> CXXRecordDecl::Destructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDestructor();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
}

uint32_t CXXRecordDecl::DeviceLambdaManglingNumber(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDeviceLambdaManglingNumber();
  return val;
}

std::optional<::pasta::TemplateParameterList> CXXRecordDecl::GenericLambdaTemplateParameterList(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isGenericLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getGenericLambdaTemplateParameterList();
  if (!val) {
    return std::nullopt;
  }
  return ::pasta::TemplateParameterList(ast, val);
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::InstantiatedFromMemberClass(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getInstantiatedFromMemberClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<::pasta::CXXMethodDecl> CXXRecordDecl::LambdaCallOperator(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaCallOperator();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
}

std::optional<enum LambdaCaptureDefault> CXXRecordDecl::LambdaCaptureDefault(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(val);
}

std::optional<::pasta::Decl> CXXRecordDecl::LambdaContextDeclaration(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaContextDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
}

uint32_t CXXRecordDecl::LambdaDependencyKind(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaDependencyKind();
  return val;
}

std::optional<std::vector<::pasta::NamedDecl>> CXXRecordDecl::LambdaExplicitTemplateParameters(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getGenericLambdaTemplateParameterList()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaExplicitTemplateParameters();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::optional<uint32_t> CXXRecordDecl::LambdaManglingNumber(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaManglingNumber();
  return val;
}

std::optional<::pasta::Type> CXXRecordDecl::LambdaType(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaTypeInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

std::optional<enum MSInheritanceModel> CXXRecordDecl::MSInheritanceModel(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getMSInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
}

enum MSVtorDispMode CXXRecordDecl::MSVtorDispMode(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMSVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(val);
}

// 0: CXXRecordDecl::MemberSpecializationInfo
::pasta::CXXRecordDecl CXXRecordDecl::MostRecentDeclaration(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  throw std::runtime_error("CXXRecordDecl::MostRecentDeclaration can return nullptr!");
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::MostRecentNonInjectedDeclaration(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMostRecentNonInjectedDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<uint32_t> CXXRecordDecl::NumBases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumBases();
  return val;
}

std::optional<uint32_t> CXXRecordDecl::NumVirtualBases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumVBases();
  return val;
}

std::optional<uint32_t> CXXRecordDecl::ODRHash(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getODRHash();
  return val;
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::PreviousDeclaration(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::TemplateInstantiationPattern(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!clang::isTemplateInstantiation(self.getTemplateSpecializationKind())) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
}

enum TemplateSpecializationKind CXXRecordDecl::TemplateSpecializationKind(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

// 0: CXXRecordDecl::VisibleConversionFunctions
std::optional<bool> CXXRecordDecl::HasAnyDependentBases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasAnyDependentBases();
  return val;
}

std::optional<bool> CXXRecordDecl::HasConstexprDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasConstexprDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprNonCopyMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasCopyAssignmentWithConstParameter(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasCopyAssignmentWithConstParam();
  return val;
}

std::optional<bool> CXXRecordDecl::HasCopyConstructorWithConstParameter(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasCopyConstructorWithConstParam();
  return val;
}

std::optional<bool> CXXRecordDecl::HasDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasDefinition(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDefinition();
  return val;
}

std::optional<bool> CXXRecordDecl::HasDirectFields(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDirectFields();
  return val;
}

std::optional<bool> CXXRecordDecl::HasFriends(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasFriends();
  return val;
}

std::optional<bool> CXXRecordDecl::HasInClassInitializer(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInClassInitializer();
  return val;
}

std::optional<bool> CXXRecordDecl::HasInheritedAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInheritedAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasInheritedConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInheritedConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasInitializerMethod(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInitMethod();
  return val;
}

std::optional<bool> CXXRecordDecl::HasIrrelevantDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasIrrelevantDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasKnownLambdaInternalLinkage();
  return val;
}

// 1: CXXRecordDecl::HasMemberName
std::optional<bool> CXXRecordDecl::HasMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasMutableFields(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMutableFields();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonLiteralTypeFieldsOrBases();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyConstructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDestructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDestructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveConstructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasPrivateFields(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasPrivateFields();
  return val;
}

std::optional<bool> CXXRecordDecl::HasProtectedFields(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasProtectedFields();
  return val;
}

std::optional<bool> CXXRecordDecl::HasSimpleCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasSimpleCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasSimpleDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasSimpleMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasSimpleMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyConstructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialDestructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDestructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveConstructorForCall();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUninitializedReferenceMember(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUninitializedReferenceMember();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveOperation(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveOperation();
  return val;
}

std::optional<bool> CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserProvidedDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::HasVariantMembers(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasVariantMembers();
  return val;
}

std::optional<bool> CXXRecordDecl::ImplicitCopyAssignmentHasConstParameter(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.implicitCopyAssignmentHasConstParam();
  return val;
}

std::optional<bool> CXXRecordDecl::ImplicitCopyConstructorHasConstParameter(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.implicitCopyConstructorHasConstParam();
  return val;
}

std::optional<bool> CXXRecordDecl::IsAbstract(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAbstract();
  return val;
}

std::optional<bool> CXXRecordDecl::IsAggregate(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAggregate();
  return val;
}

std::optional<bool> CXXRecordDecl::IsAnyDestructorNoReturn(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAnyDestructorNoReturn();
  return val;
}

std::optional<bool> CXXRecordDecl::IsCLike(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isCLike();
  return val;
}

std::optional<bool> CXXRecordDecl::IsCXX11StandardLayout(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isCXX11StandardLayout();
  return val;
}

// 1: CXXRecordDecl::IsCurrentInstantiation
bool CXXRecordDecl::IsDependentLambda(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isDependentLambda();
  return val;
}

std::optional<bool> CXXRecordDecl::IsDynamicClass(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isDynamicClass();
  return val;
}

std::optional<bool> CXXRecordDecl::IsEffectivelyFinal(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isEffectivelyFinal();
  return val;
}

std::optional<bool> CXXRecordDecl::IsEmpty(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isEmpty();
  return val;
}

bool CXXRecordDecl::IsGenericLambda(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isGenericLambda();
  return val;
}

std::optional<bool> CXXRecordDecl::IsInterfaceLike(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isInterfaceLike();
  return val;
}

bool CXXRecordDecl::IsLambda(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
}

std::optional<bool> CXXRecordDecl::IsLiteral(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isLiteral();
  return val;
}

std::optional<::pasta::FunctionDecl> CXXRecordDecl::IsLocalClass(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isLocalClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
}

bool CXXRecordDecl::IsNeverDependentLambda(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isNeverDependentLambda();
  return val;
}

std::optional<bool> CXXRecordDecl::IsPOD(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isPOD();
  return val;
}

std::optional<bool> CXXRecordDecl::IsParsingBaseSpecifiers(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isParsingBaseSpecifiers();
  return val;
}

std::optional<bool> CXXRecordDecl::IsPolymorphic(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isPolymorphic();
  return val;
}

// 1: CXXRecordDecl::IsProvablyNotDerivedFrom
std::optional<bool> CXXRecordDecl::IsStandardLayout(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStandardLayout();
  return val;
}

std::optional<bool> CXXRecordDecl::IsStructural(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStructural();
  return val;
}

std::optional<bool> CXXRecordDecl::IsTrivial(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isTrivial();
  return val;
}

std::optional<bool> CXXRecordDecl::IsTriviallyCopyable(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isTriviallyCopyable();
  return val;
}

// 1: CXXRecordDecl::IsVirtuallyDerivedFrom
std::optional<bool> CXXRecordDecl::LambdaIsDefaultConstructibleAndAssignable(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.lambdaIsDefaultConstructibleAndAssignable();
  return val;
}

// 2: LookupInBases
std::optional<bool> CXXRecordDecl::MayBeAbstract(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeAbstract();
  return val;
}

std::optional<bool> CXXRecordDecl::MayBeDynamicClass(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeDynamicClass();
  return val;
}

std::optional<bool> CXXRecordDecl::MayBeNonDynamicClass(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeNonDynamicClass();
  return val;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<std::vector<::pasta::CXXMethodDecl>> CXXRecordDecl::Methods(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitDefaultConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsImplicitMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForCopyAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForCopyConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForDestructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForMoveAssignment();
  return val;
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForMoveConstructor();
  return val;
}

std::optional<bool> CXXRecordDecl::NullFieldOffsetIsZero(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.nullFieldOffsetIsZero();
  return val;
}

std::optional<std::vector<::pasta::CXXBaseSpecifier>> CXXRecordDecl::VirtualBases(void) const {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.vbases();
  std::vector<::pasta::CXXBaseSpecifier> ret;
  for (const auto &bs : val) {
    ret.emplace_back(ast, bs);
  }
  return ret;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::TemplateParameterList> CXXRecordDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.CXXRecordDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXRecordDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ClassTemplateSpecializationDecl::ClassTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXRecordDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
::pasta::Token ClassTemplateSpecializationDecl::ExternToken(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFrom();
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::ClassTemplateDecl *>()) {
      ret = DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::ClassTemplatePartialSpecializationDecl *>()) {
      ret = DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, b_ptr);
    } else {
      ret = {};
    }
  } else {
    ret = {};
  }
  return ret;
}

::pasta::Token ClassTemplateSpecializationDecl::PointOfInstantiation(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum TemplateSpecializationKind ClassTemplateSpecializationDecl::SpecializationKind(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

::pasta::ClassTemplateDecl ClassTemplateSpecializationDecl::SpecializedTemplate(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplateOrPartial();
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::ClassTemplateDecl *>()) {
      ret = DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::ClassTemplatePartialSpecializationDecl *>()) {
      ret = DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, b_ptr);
    } else {
      ret = {};
    }
  } else {
    ret = {};
  }
  return ret;
}

std::vector<::pasta::TemplateArgument> ClassTemplateSpecializationDecl::TemplateArguments(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
}

std::vector<::pasta::TemplateArgument> ClassTemplateSpecializationDecl::TemplateInstantiationArguments(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateInstantiationArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
}

::pasta::Token ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

std::optional<::pasta::Type> ClassTemplateSpecializationDecl::TypeAsWritten(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  if (!self.getTypeAsWritten()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTypeAsWritten();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
}

bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
}

std::vector<::pasta::TemplateParameterList> ClassTemplateSpecializationDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ClassTemplateSpecializationDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ClassTemplateSpecializationDecl->getTemplateParameterList(i)));
  }
  return ret;
}

ClassTemplatePartialSpecializationDecl::ClassTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ClassTemplateSpecializationDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, ClassTemplatePartialSpecializationDecl)
::pasta::Type ClassTemplatePartialSpecializationDecl::InjectedSpecializationType(void) const {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInjectedSpecializationType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  throw std::runtime_error("ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate can return nullptr!");
}

// 0: ClassTemplatePartialSpecializationDecl::TemplateArgumentsAsWritten
::pasta::TemplateParameterList ClassTemplatePartialSpecializationDecl::TemplateParameters(void) const {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  throw std::runtime_error("ClassTemplatePartialSpecializationDecl::TemplateParameters can return nullptr!");
}

bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
}

std::vector<::pasta::TemplateParameterList> ClassTemplatePartialSpecializationDecl::TemplateParameterLists(void) const {
  std::vector<::pasta::TemplateParameterList> ret;
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  auto count = u.ClassTemplatePartialSpecializationDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ClassTemplatePartialSpecializationDecl->getTemplateParameterList(i)));
  }
  return ret;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
