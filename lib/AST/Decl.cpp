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
  __builtin_unreachable();
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
std::vector<::pasta::Decl> DeclContext::Declarations(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: DeclContext::
// 0: DeclContext::
// 0: DeclContext::
enum ::pasta::DeclKind DeclContext::DeclarationKind(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getDeclKind();
  return static_cast<enum ::pasta::DeclKind>(val);
  __builtin_unreachable();
}

std::string_view DeclContext::DeclarationKindName(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getDeclKindName();
  if (val) {
    return std::string_view(val);
  } else {
    return std::string_view();
  }
  assert(false && "DeclContext::DeclarationKindName can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::DeclContext> DeclContext::EnclosingNamespaceContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getEnclosingNamespaceContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::LinkageSpecDecl> DeclContext::ExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getExternCContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::LinkageSpecDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::BlockDecl> DeclContext::InnermostBlockDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getInnermostBlockDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::DeclContext> DeclContext::LexicalParent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLexicalParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::DeclContext> DeclContext::LookupParent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLookupParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  __builtin_unreachable();
}

// 0: DeclContext::LookupPointer
std::optional<::pasta::Decl> DeclContext::NonClosureAncestor(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getNonClosureAncestor();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::NonTransparentContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getNonTransparentContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::NonTransparentContext can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::RecordDecl> DeclContext::OuterLexicalRecordContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getOuterLexicalRecordContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::DeclContext> DeclContext::Parent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getParent();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  __builtin_unreachable();
}

// 0: DeclContext::ParentASTContext
::pasta::DeclContext DeclContext::PrimaryContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getPrimaryContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::PrimaryContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::RedeclarationContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getRedeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::RedeclarationContext can return nullptr!");
  __builtin_unreachable();
}

bool DeclContext::HasExternalLexicalStorage(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasExternalLexicalStorage();
  return val;
  __builtin_unreachable();
}

bool DeclContext::HasExternalVisibleStorage(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasExternalVisibleStorage();
  return val;
  __builtin_unreachable();
}

bool DeclContext::HasValidDeclarationKind(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasValidDeclKind();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsClosure(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isClosure();
  return val;
  __builtin_unreachable();
}

// 1: DeclContext::IsDeclarationInLexicalTraversal
bool DeclContext::IsDependentContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isDependentContext();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCContext();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCXXContext();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsFileContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFileContext();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFunctionOrMethod();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsInlineNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isInlineNamespace();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsLookupContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isLookupContext();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isNamespace();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsObjCContainer(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isObjCContainer();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsRecord(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isRecord();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsStdNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isStdNamespace();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsTranslationUnit(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTranslationUnit();
  return val;
  __builtin_unreachable();
}

bool DeclContext::IsTransparentContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTransparentContext();
  return val;
  __builtin_unreachable();
}

// 1: DeclContext::Lookup
// 0: DeclContext::Lookups
// 0: DeclContext::
// 0: DeclContext::
std::vector<::pasta::Decl> DeclContext::AlreadyLoadedDeclarations(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.noload_decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: DeclContext::
// 0: DeclContext::
// 1: DeclContext::NoloadLookups
// 0: DeclContext::
// 0: DeclContext::
bool DeclContext::ShouldUseQualifiedLookup(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.shouldUseQualifiedLookup();
  return val;
  __builtin_unreachable();
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
std::vector<::pasta::Attr> Decl::Attributes(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.attrs();
  std::vector<::pasta::Attr> ret;
  for (auto attr_ptr : val) {
    if (attr_ptr) {
      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 1: Decl::CanBeWeakImported
// 0: Decl::ASTContext
enum AccessSpecifier Decl::Access(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAccess();
  return static_cast<::pasta::AccessSpecifier>(val);
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> Decl::AsFunction(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAsFunction();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: Decl::Attributes
enum AvailabilityResult Decl::Availability(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAvailability();
  return static_cast<::pasta::AvailabilityResult>(val);
  __builtin_unreachable();
}

::pasta::Token Decl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Decl Decl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext Decl::DeclarationContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::DeclarationContext can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::Attr> Decl::DefiningAttribute(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDefiningAttr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::Attr>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::TemplateDecl> Decl::DescribedTemplate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::TemplateParameterList> Decl::DescribedTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplateParams();
  if (!val) {
    return std::nullopt;
  }
  return ::pasta::TemplateParameterList(ast, val);
  __builtin_unreachable();
}

::pasta::Token Decl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::ExternalSourceSymbolAttr> Decl::ExternalSourceSymbolAttribute(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getExternalSourceSymbolAttr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return AttrBuilder::Create<::pasta::ExternalSourceSymbolAttr>(ast, val);
  }
  __builtin_unreachable();
}

enum DeclFriendObjectKind Decl::FriendObjectKind(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFriendObjectKind();
  return static_cast<::pasta::DeclFriendObjectKind>(val);
  __builtin_unreachable();
}

std::optional<::pasta::FunctionType> Decl::FunctionType(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFunctionType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionType>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t Decl::GlobalID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getGlobalID();
  return val;
  __builtin_unreachable();
}

int64_t Decl::ID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getID();
  return val;
  __builtin_unreachable();
}

uint32_t Decl::IdentifierNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getIdentifierNamespace();
  return val;
  __builtin_unreachable();
}

// 0: Decl::ImportedOwningModule
// 0: Decl::LangOpts
::pasta::DeclContext Decl::LexicalDeclarationContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getLexicalDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::LexicalDeclarationContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::LocalOwningModule
uint32_t Decl::MaxAlignment(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getMaxAlignment();
  return val;
  __builtin_unreachable();
}

enum DeclModuleOwnershipKind Decl::ModuleOwnershipKind(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getModuleOwnershipKind();
  return static_cast<::pasta::DeclModuleOwnershipKind>(val);
  __builtin_unreachable();
}

::pasta::Decl Decl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::Decl> Decl::NextDeclarationInContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNextDeclInContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Decl> Decl::NonClosureContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNonClosureContext();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::DeclContext Decl::NonTransparentDeclarationContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNonTransparentDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::NonTransparentDeclarationContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::OwningModule
// 0: Decl::OwningModuleForLinkage
uint32_t Decl::OwningModuleID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getOwningModuleID();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::DeclContext> Decl::ParentFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getParentFunctionOrMethod();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Decl> Decl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t Decl::TemplateDepth(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getTemplateDepth();
  return val;
  __builtin_unreachable();
}

::pasta::TranslationUnitDecl Decl::TranslationUnitDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getTranslationUnitDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TranslationUnitDecl>(ast, val);
  }
  assert(false && "Decl::TranslationUnitDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::VersionIntroduced
bool Decl::HasAttributes(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasAttrs();
  return val;
  __builtin_unreachable();
}

bool Decl::HasBody(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasBody();
  return val;
  __builtin_unreachable();
}

bool Decl::HasDefiningAttribute(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasDefiningAttr();
  return val;
  __builtin_unreachable();
}

bool Decl::HasOwningModule(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasOwningModule();
  return val;
  __builtin_unreachable();
}

bool Decl::HasTagIdentifierNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasTagIdentifierNamespace();
  return val;
  __builtin_unreachable();
}

bool Decl::IsCanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isCanonicalDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDefinedOutsideFunctionOrMethod();
  return val;
  __builtin_unreachable();
}

bool Decl::IsDeprecated(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDeprecated();
  return val;
  __builtin_unreachable();
}

bool Decl::IsDiscardedInGlobalModuleFragment(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDiscardedInGlobalModuleFragment();
  return val;
  __builtin_unreachable();
}

bool Decl::IsFileContextDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFileContextDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsFirstDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFirstDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsFromASTFile(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFromASTFile();
  return val;
  __builtin_unreachable();
}

bool Decl::IsFunctionOrFunctionTemplate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFunctionOrFunctionTemplate();
  return val;
  __builtin_unreachable();
}

bool Decl::IsInAnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInAnonymousNamespace();
  return val;
  __builtin_unreachable();
}

bool Decl::IsInExportDeclarationContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInExportDeclContext();
  return val;
  __builtin_unreachable();
}

// 1: Decl::IsInIdentifierNamespace
bool Decl::IsInLocalScopeForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInLocalScopeForInstantiation();
  return val;
  __builtin_unreachable();
}

bool Decl::IsInStdNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInStdNamespace();
  return val;
  __builtin_unreachable();
}

bool Decl::IsInvalidDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInvalidDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsInvisibleOutsideTheOwningModule(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInvisibleOutsideTheOwningModule();
  return val;
  __builtin_unreachable();
}

bool Decl::IsLocalExternDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isLocalExternDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsModulePrivate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isModulePrivate();
  return val;
  __builtin_unreachable();
}

bool Decl::IsOutOfLine(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isOutOfLine();
  return val;
  __builtin_unreachable();
}

bool Decl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

bool Decl::IsReachable(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isReachable();
  return val;
  __builtin_unreachable();
}

bool Decl::IsReferenced(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isReferenced();
  return val;
  __builtin_unreachable();
}

bool Decl::IsTemplateDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateDecl();
  return val;
  __builtin_unreachable();
}

bool Decl::IsTemplateParameter(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameter();
  return val;
  __builtin_unreachable();
}

bool Decl::IsTemplateParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameterPack();
  return val;
  __builtin_unreachable();
}

bool Decl::IsTemplated(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplated();
  return val;
  __builtin_unreachable();
}

bool Decl::IsThisDeclarationReferenced(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isThisDeclarationReferenced();
  return val;
  __builtin_unreachable();
}

bool Decl::IsTopLevelDeclarationInObjCContainer(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTopLevelDeclInObjCContainer();
  return val;
  __builtin_unreachable();
}

bool Decl::IsUnavailable(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnavailable();
  return val;
  __builtin_unreachable();
}

bool Decl::IsUnconditionallyVisible(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnconditionallyVisible();
  return val;
  __builtin_unreachable();
}

bool Decl::IsUsed(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUsed();
  return val;
  __builtin_unreachable();
}

bool Decl::IsWeakImported(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isWeakImported();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::Decl> Decl::Redeclarations(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.redecls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::Token ExportDecl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ExportDecl::ExportToken(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getExportLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ExportDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool ExportDecl::HasBraces(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.hasBraces();
  return val;
  __builtin_unreachable();
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
::pasta::Token FileScopeAsmDecl::AssemblyToken(void) const noexcept {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getAsmLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::StringLiteral FileScopeAsmDecl::AssemblyString(void) const noexcept {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getAsmString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "FileScopeAsmDecl::AssemblyString can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FileScopeAsmDecl::RParenToken(void) const noexcept {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendDecl)
std::optional<::pasta::NamedDecl> FriendDecl::FriendDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Token FriendDecl::FriendToken(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> FriendDecl::FriendType(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  if (!self.getFriendType()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getFriendType();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  __builtin_unreachable();
}

uint32_t FriendDecl::FriendTypeNumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendTypeNumTemplateParameterLists();
  return val;
  __builtin_unreachable();
}

// 1: FriendDecl::FriendTypeTemplateParameterList
bool FriendDecl::IsUnsupportedFriend(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.isUnsupportedFriend();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> FriendDecl::FriendTypeTemplateParameterLists(void) const noexcept {
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
::pasta::NamedDecl FriendTemplateDecl::FriendDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendTemplateDecl::FriendDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendTemplateDecl::FriendToken(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type FriendTemplateDecl::FriendType(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendType();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "FriendTemplateDecl::FriendType can return nullptr!");
  __builtin_unreachable();
}

uint32_t FriendTemplateDecl::NumTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getNumTemplateParameters();
  return val;
  __builtin_unreachable();
}

// 1: FriendTemplateDecl::TemplateParameterList
std::vector<::pasta::TemplateParameterList> FriendTemplateDecl::TemplateParameterLists(void) const noexcept {
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
std::vector<::pasta::TemplateArgument> ImplicitConceptSpecializationDecl::TemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::ImplicitConceptSpecializationDecl *>(u.ImplicitConceptSpecializationDecl);
  decltype(auto) val = self.getTemplateArguments();
  std::vector<::pasta::TemplateArgument> ret;
  for (const auto &arg : val) {
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

ImportDecl::ImportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ImportDecl)
std::vector<::pasta::Token> ImportDecl::IdentifierTokens(void) const noexcept {
  auto &self = *const_cast<clang::ImportDecl *>(u.ImportDecl);
  decltype(auto) val = self.getIdentifierLocs();
  std::vector<::pasta::Token> ret;
  for (auto sl : val) {
    ret.emplace_back(ast->TokenAt(sl));
  }
  return ret;
  __builtin_unreachable();
}

// 0: ImportDecl::ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
std::vector<::pasta::Stmt> LifetimeExtendedTemporaryDecl::Children(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.childrenExpr();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

::pasta::ValueDecl LifetimeExtendedTemporaryDecl::ExtendingDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getExtendingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "LifetimeExtendedTemporaryDecl::ExtendingDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t LifetimeExtendedTemporaryDecl::ManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getManglingNumber();
  return val;
  __builtin_unreachable();
}

// 1: LifetimeExtendedTemporaryDecl::OrCreateValue
enum StorageDuration LifetimeExtendedTemporaryDecl::StorageDuration(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
  __builtin_unreachable();
}

::pasta::Expr LifetimeExtendedTemporaryDecl::TemporaryExpression(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getTemporaryExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LifetimeExtendedTemporaryDecl::TemporaryExpression can return nullptr!");
  __builtin_unreachable();
}

// 0: LifetimeExtendedTemporaryDecl::Value
LinkageSpecDecl::LinkageSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, LinkageSpecDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, LinkageSpecDecl)
::pasta::Token LinkageSpecDecl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token LinkageSpecDecl::ExternToken(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

enum LinkageSpecDeclLanguageIDs LinkageSpecDecl::Language(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getLanguage();
  return static_cast<::pasta::LinkageSpecDeclLanguageIDs>(val);
  __builtin_unreachable();
}

::pasta::Token LinkageSpecDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool LinkageSpecDecl::HasBraces(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.hasBraces();
  return val;
  __builtin_unreachable();
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
enum Linkage NamedDecl::FormalLinkage(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getFormalLinkage();
  return static_cast<::pasta::Linkage>(val);
  __builtin_unreachable();
}

// 0: NamedDecl::Identifier
// 0: NamedDecl::LinkageAndVisibility
enum Linkage NamedDecl::LinkageInternal(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getLinkageInternal();
  return static_cast<::pasta::Linkage>(val);
  __builtin_unreachable();
}

::pasta::NamedDecl NamedDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::string NamedDecl::Name(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getNameAsString();
  return val;
  __builtin_unreachable();
}

std::optional<enum ObjCStringFormatFamily> NamedDecl::ObjCFStringFormattingFamily(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  if (!self.getIdentifier()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getObjCFStringFormattingFamily();
  return static_cast<::pasta::ObjCStringFormatFamily>(val);
  __builtin_unreachable();
}

std::string NamedDecl::QualifiedNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getQualifiedNameAsString();
  return val;
  __builtin_unreachable();
}

::pasta::NamedDecl NamedDecl::UnderlyingDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getUnderlyingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::UnderlyingDeclaration can return nullptr!");
  __builtin_unreachable();
}

enum Visibility NamedDecl::Visibility(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getVisibility();
  return static_cast<::pasta::Visibility>(val);
  __builtin_unreachable();
}

bool NamedDecl::HasExternalFormalLinkage(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasExternalFormalLinkage();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::HasLinkage(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkage();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::HasLinkageBeenComputed(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkageBeenComputed();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::IsCXXClassMember(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXClassMember();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::IsCXXInstanceMember(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXInstanceMember();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::IsExternallyDeclarable(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyDeclarable();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::IsExternallyVisible(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyVisible();
  return val;
  __builtin_unreachable();
}

bool NamedDecl::IsLinkageValid(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isLinkageValid();
  return val;
  __builtin_unreachable();
}

// 1: NamedDecl::IsReserved
NamespaceAliasDecl::NamespaceAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceAliasDecl)
::pasta::Token NamespaceAliasDecl::AliasToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getAliasLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::NamedDecl NamespaceAliasDecl::AliasedNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getAliasedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::AliasedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceAliasDecl NamespaceAliasDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceAliasDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceAliasDecl::Namespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::Namespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceAliasDecl::NamespaceToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getNamespaceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: NamespaceAliasDecl::Qualifier
// 0: NamespaceAliasDecl::QualifierToken
::pasta::Token NamespaceAliasDecl::TargetNameToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getTargetNameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

NamespaceDecl::NamespaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceDecl)
::pasta::NamespaceDecl NamespaceDecl::AnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getAnonymousNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::AnonymousNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceDecl::OriginalNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getOriginalNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::OriginalNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool NamespaceDecl::IsAnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isAnonymousNamespace();
  return val;
  __builtin_unreachable();
}

bool NamespaceDecl::IsInline(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isInline();
  return val;
  __builtin_unreachable();
}

bool NamespaceDecl::IsNested(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isNested();
  return val;
  __builtin_unreachable();
}

bool NamespaceDecl::IsOriginalNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isOriginalNamespace();
  return val;
  __builtin_unreachable();
}

// 1: NamespaceDecl::IsRedundantInlineQualifierFor
ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
::pasta::ObjCInterfaceDecl ObjCCompatibleAliasDecl::ClassInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCompatibleAliasDecl *>(u.ObjCCompatibleAliasDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCCompatibleAliasDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
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
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::ClassMethods(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.class_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::ClassProperties(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.class_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
::pasta::TokenRange ObjCContainerDecl::AtEndRange(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtEndRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

::pasta::Token ObjCContainerDecl::AtStartToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtStartLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 1: ObjCContainerDecl::ClassMethod
// 1: ObjCContainerDecl::InstanceMethod
// 1: ObjCContainerDecl::InstanceVariableDeclaration
// 2: Method
// 2: Property
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::InstanceMethods(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.instance_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::InstanceProperties(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.instance_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::Methods(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::Properties(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::ObjCInterfaceDecl ObjCImplDecl::ClassInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplDecl *>(u.ObjCImplDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::ObjCPropertyImplDecl> ObjCImplDecl::PropertyImplementations(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplDecl *>(u.ObjCImplDecl);
  decltype(auto) val = self.property_impls();
  std::vector<::pasta::ObjCPropertyImplDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyImplDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::Token ObjCImplementationDecl::InstanceVariableLBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ObjCImplementationDecl::InstanceVariableRBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::string ObjCImplementationDecl::Name(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNameAsString();
  return val;
  __builtin_unreachable();
}

uint32_t ObjCImplementationDecl::NumInstanceVariableInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNumIvarInitializers();
  return val;
  __builtin_unreachable();
}

std::string_view ObjCImplementationDecl::ObjCRuntimeNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCImplementationDecl::SuperClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplementationDecl::SuperClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCImplementationDecl::SuperClassToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getSuperClassLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool ObjCImplementationDecl::HasDestructors(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.hasDestructors();
  return val;
  __builtin_unreachable();
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.hasNonZeroConstructors();
  return val;
  __builtin_unreachable();
}

// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::Initializers
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
// 0: ObjCImplementationDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCImplementationDecl::InstanceVariables(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::AllReferencedProtocols(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.all_referenced_protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.declaresOrInheritsDesignatedInitializers();
  return val;
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 1: ObjCInterfaceDecl::CategoryClassMethod
// 1: ObjCInterfaceDecl::CategoryInstanceMethod
::pasta::ObjCCategoryDecl ObjCInterfaceDecl::CategoryListRaw(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getCategoryListRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CategoryListRaw can return nullptr!");
  __builtin_unreachable();
}

// 2: CategoryMethod
::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::EndOfDefinitionToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getEndOfDefinitionLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::ObjCImplementationDecl ObjCInterfaceDecl::Implementation(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCImplementationDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::Implementation can return nullptr!");
  __builtin_unreachable();
}

std::string_view ObjCInterfaceDecl::ObjCRuntimeNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::ReferencedProtocols
std::optional<::pasta::ObjCInterfaceDecl> ObjCInterfaceDecl::SuperClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::SuperClassToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> ObjCInterfaceDecl::SuperClassTypeInfo(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassTInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  __builtin_unreachable();
}

std::optional<::pasta::ObjCObjectType> ObjCInterfaceDecl::SuperClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Type ObjCInterfaceDecl::TypeForDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getTypeForDecl();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::TypeForDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::TypeParameterList
// 0: ObjCInterfaceDecl::TypeParameterListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
  __builtin_unreachable();
}

bool ObjCInterfaceDecl::HasDesignatedInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.hasDesignatedInitializers();
  return val;
  __builtin_unreachable();
}

bool ObjCInterfaceDecl::IsArcWeakrefUnavailable(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isArcWeakrefUnavailable();
  return val;
  __builtin_unreachable();
}

// 1: ObjCInterfaceDecl::IsDesignatedInitializer
bool ObjCInterfaceDecl::IsImplicitInterfaceDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isImplicitInterfaceDecl();
  return val;
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isObjCRequiresPropertyDefs();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions can return nullptr!");
  __builtin_unreachable();
}

// 1: ObjCInterfaceDecl::IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCInterfaceDecl::InstanceVariables(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownCategories(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.known_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownExtensions(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.known_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
std::vector<::pasta::Token> ObjCInterfaceDecl::ProtocolTokens(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::Protocols(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleCategories(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.visible_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleExtensions(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.visible_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
bool ObjCMethodDecl::DefinedInNSObject(void) const noexcept {
  auto &self = *(u.ObjCMethodDecl);
  decltype(auto) val = self.definedInNSObject(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

::pasta::ObjCPropertyDecl ObjCMethodDecl::FindPropertyDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.findPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::FindPropertyDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCMethodDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCMethodDecl::Category(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::Category can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCMethodDecl::ClassInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ImplicitParamDecl ObjCMethodDecl::CommandDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCmdDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CommandDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::DeclaratorEndToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getDeclaratorEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

enum ObjCMethodDeclImplementationControl ObjCMethodDecl::ImplementationControl(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getImplementationControl();
  return static_cast<::pasta::ObjCMethodDeclImplementationControl>(val);
  __builtin_unreachable();
}

enum ObjCMethodFamily ObjCMethodDecl::MethodFamily(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(val);
  __builtin_unreachable();
}

uint32_t ObjCMethodDecl::NumSelectorTokens(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getNumSelectorLocs();
  return val;
  __builtin_unreachable();
}

enum DeclObjCDeclQualifier ObjCMethodDecl::ObjCDeclQualifier(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
  __builtin_unreachable();
}

// 1: ObjCMethodDecl::ParameterDeclaration
::pasta::Type ObjCMethodDecl::ReturnType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TokenRange ObjCMethodDecl::ReturnTypeSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

// 0: ObjCMethodDecl::Selector
// 1: ObjCMethodDecl::SelectorToken
::pasta::Token ObjCMethodDecl::SelectorStartToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::ImplicitParamDecl ObjCMethodDecl::SelfDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getSelfDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::SelfDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 4: ObjCMethodDecl::SelfType
bool ObjCMethodDecl::HasParameterDestroyedInCallee(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasParamDestroyedInCallee();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::HasRedeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRedeclaration();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::HasRelatedResultType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRelatedResultType();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::HasSkippedBody(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsClassMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isClassMethod();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsDefined(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDefined();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsDesignatedInitializerForTheInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDesignatedInitializerForTheInterface();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsDirectMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDirectMethod();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsInstanceMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isInstanceMethod();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsOptional(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOptional();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsOverriding(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOverriding();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isPropertyAccessor();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsRedeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isRedeclaration();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isSynthesizedAccessorStub();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsThisDeclarationADesignatedInitializer(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADesignatedInitializer();
  return val;
  __builtin_unreachable();
}

bool ObjCMethodDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isVariadic();
  return val;
  __builtin_unreachable();
}

// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
std::vector<::pasta::ParmVarDecl> ObjCMethodDecl::Parameters(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCMethodDecl::
std::vector<::pasta::Token> ObjCMethodDecl::SelectorTokens(void) const noexcept {
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
::pasta::Token ObjCPropertyDecl::AtToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getAtLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 1: ObjCPropertyDecl::DefaultSynthInstanceVariableName
::pasta::ObjCMethodDecl ObjCPropertyDecl::GetterMethodDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::GetterMethodDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::GetterName
::pasta::Token ObjCPropertyDecl::GetterNameToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getGetterNameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyDecl::LParenToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::PropertyAttributes
// 0: ObjCPropertyDecl::PropertyAttributesAsWritten
enum ObjCPropertyDeclPropertyControl ObjCPropertyDecl::PropertyImplementation(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getPropertyImplementation();
  return static_cast<::pasta::ObjCPropertyDeclPropertyControl>(val);
  __builtin_unreachable();
}

::pasta::ObjCIvarDecl ObjCPropertyDecl::PropertyInstanceVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::PropertyInstanceVariableDeclaration can return nullptr!");
  __builtin_unreachable();
}

enum ObjCPropertyQueryKind ObjCPropertyDecl::QueryKind(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getQueryKind();
  return static_cast<::pasta::ObjCPropertyQueryKind>(val);
  __builtin_unreachable();
}

enum ObjCPropertyDeclSetterKind ObjCPropertyDecl::SetterKind(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterKind();
  return static_cast<::pasta::ObjCPropertyDeclSetterKind>(val);
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyDecl::SetterMethodDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::SetterMethodDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::SetterName
::pasta::Token ObjCPropertyDecl::SetterNameToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterNameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type ObjCPropertyDecl::Type(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::
// 1: ObjCPropertyDecl::UsageType
bool ObjCPropertyDecl::IsAtomic(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isAtomic();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsClassProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isClassProperty();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsDirectProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isDirectProperty();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isInstanceProperty();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsOptional(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isOptional();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsReadOnly(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isReadOnly();
  return val;
  __builtin_unreachable();
}

bool ObjCPropertyDecl::IsRetaining(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isRetaining();
  return val;
  __builtin_unreachable();
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCPropertyImplDecl)
::pasta::Token ObjCPropertyImplDecl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Expr ObjCPropertyImplDecl::GetterCXXConstructor(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getGetterCXXConstructor();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::GetterCXXConstructor can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::GetterMethodDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::GetterMethodDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCPropertyDecl ObjCPropertyImplDecl::PropertyDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyDeclaration can return nullptr!");
  __builtin_unreachable();
}

enum ObjCPropertyImplDeclKind ObjCPropertyImplDecl::PropertyImplementation(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyImplementation();
  return static_cast<::pasta::ObjCPropertyImplDeclKind>(val);
  __builtin_unreachable();
}

::pasta::ObjCIvarDecl ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyImplDecl::PropertyInstanceVariableDeclarationToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getPropertyIvarDeclLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Expr ObjCPropertyImplDecl::SetterCXXAssignment(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getSetterCXXAssignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::SetterCXXAssignment can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::SetterMethodDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::SetterMethodDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool ObjCPropertyImplDecl::IsInstanceVariableNameSpecified(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyImplDecl *>(u.ObjCPropertyImplDecl);
  decltype(auto) val = self.isIvarNameSpecified();
  return val;
  __builtin_unreachable();
}

ObjCProtocolDecl::ObjCProtocolDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCProtocolDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
::pasta::ObjCProtocolDecl ObjCProtocolDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCProtocolDecl ObjCProtocolDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

std::string_view ObjCProtocolDecl::ObjCRuntimeNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

// 0: ObjCProtocolDecl::ReferencedProtocols
bool ObjCProtocolDecl::HasDefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
  __builtin_unreachable();
}

bool ObjCProtocolDecl::IsNonRuntimeProtocol(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.isNonRuntimeProtocol();
  return val;
  __builtin_unreachable();
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

// 1: ObjCProtocolDecl::LookupClassMethod
// 1: ObjCProtocolDecl::LookupInstanceMethod
// 2: LookupMethod
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
std::vector<::pasta::Token> ObjCProtocolDecl::ProtocolTokens(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCProtocolDecl::
std::vector<::pasta::ObjCProtocolDecl> ObjCProtocolDecl::Protocols(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

PragmaCommentDecl::PragmaCommentDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaCommentDecl)
std::string_view PragmaCommentDecl::Argument(void) const noexcept {
  auto &self = *const_cast<clang::PragmaCommentDecl *>(u.PragmaCommentDecl);
  decltype(auto) val = self.getArg();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

enum PragmaMSCommentKind PragmaCommentDecl::CommentKind(void) const noexcept {
  auto &self = *const_cast<clang::PragmaCommentDecl *>(u.PragmaCommentDecl);
  decltype(auto) val = self.getCommentKind();
  return static_cast<::pasta::PragmaMSCommentKind>(val);
  __builtin_unreachable();
}

PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaDetectMismatchDecl)
std::string_view PragmaDetectMismatchDecl::Name(void) const noexcept {
  auto &self = *const_cast<clang::PragmaDetectMismatchDecl *>(u.PragmaDetectMismatchDecl);
  decltype(auto) val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

std::string_view PragmaDetectMismatchDecl::Value(void) const noexcept {
  auto &self = *const_cast<clang::PragmaDetectMismatchDecl *>(u.PragmaDetectMismatchDecl);
  decltype(auto) val = self.getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
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
::pasta::Expr StaticAssertDecl::AssertExpression(void) const noexcept {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getAssertExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "StaticAssertDecl::AssertExpression can return nullptr!");
  __builtin_unreachable();
}

::pasta::StringLiteral StaticAssertDecl::Message(void) const noexcept {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getMessage();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "StaticAssertDecl::Message can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token StaticAssertDecl::RParenToken(void) const noexcept {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.getRParenLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool StaticAssertDecl::IsFailed(void) const noexcept {
  auto &self = *const_cast<clang::StaticAssertDecl *>(u.StaticAssertDecl);
  decltype(auto) val = self.isFailed();
  return val;
  __builtin_unreachable();
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
::pasta::TemplateParameterList TemplateDecl::TemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  assert(false && "TemplateDecl::TemplateParameters can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl TemplateDecl::TemplatedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "TemplateDecl::TemplatedDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool TemplateDecl::HasAssociatedConstraints(void) const noexcept {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
  __builtin_unreachable();
}

bool TemplateDecl::IsTypeAlias(void) const noexcept {
  auto &self = *const_cast<clang::TemplateDecl *>(u.TemplateDecl);
  decltype(auto) val = self.isTypeAlias();
  return val;
  __builtin_unreachable();
}

TemplateTemplateParmDecl::TemplateTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
bool TemplateTemplateParmDecl::DefaultArgumentWasInherited(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
  __builtin_unreachable();
}

// 0: TemplateTemplateParmDecl::DefaultArgumentStorage
// 0: TemplateTemplateParmDecl::DefaultArgument
::pasta::Token TemplateTemplateParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 1: TemplateTemplateParmDecl::ExpansionTemplateParameters
uint32_t TemplateTemplateParmDecl::NumExpansionTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getNumExpansionTemplateParameters();
  return val;
  __builtin_unreachable();
}

bool TemplateTemplateParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
  __builtin_unreachable();
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
  __builtin_unreachable();
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

TopLevelStmtDecl::TopLevelStmtDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TopLevelStmtDecl)
::pasta::Stmt TopLevelStmtDecl::Statement(void) const noexcept {
  auto &self = *const_cast<clang::TopLevelStmtDecl *>(u.TopLevelStmtDecl);
  decltype(auto) val = self.getStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "TopLevelStmtDecl::Statement can return nullptr!");
  __builtin_unreachable();
}

TranslationUnitDecl::TranslationUnitDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, TranslationUnitDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, TranslationUnitDecl)
// 0: TranslationUnitDecl::ASTContext
::pasta::NamespaceDecl TranslationUnitDecl::AnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::TranslationUnitDecl *>(u.TranslationUnitDecl);
  decltype(auto) val = self.getAnonymousNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "TranslationUnitDecl::AnonymousNamespace can return nullptr!");
  __builtin_unreachable();
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
::pasta::Token TypeDecl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::TypeDecl *>(u.TypeDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> TypeDecl::TypeForDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeDecl *>(u.TypeDecl);
  decltype(auto) val = self.getTypeForDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  __builtin_unreachable();
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
std::optional<::pasta::TagDecl> TypedefNameDecl::AnonymousDeclarationWithTypedefName(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getAnonDeclWithTypedefName();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::TypedefNameDecl TypedefNameDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TypedefNameDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: TypedefNameDecl::
::pasta::Type TypedefNameDecl::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getUnderlyingType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool TypedefNameDecl::IsModed(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.isModed();
  return val;
  __builtin_unreachable();
}

bool TypedefNameDecl::IsTransparentTag(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.isTransparentTag();
  return val;
  __builtin_unreachable();
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
::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingTypenameDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingTypenameDecl::EllipsisToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: UnresolvedUsingTypenameDecl::NameInfo
// 0: UnresolvedUsingTypenameDecl::Qualifier
// 0: UnresolvedUsingTypenameDecl::QualifierToken
::pasta::Token UnresolvedUsingTypenameDecl::TypenameToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getTypenameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingTypenameDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

UsingDirectiveDecl::UsingDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDirectiveDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDirectiveDecl)
::pasta::DeclContext UsingDirectiveDecl::CommonAncestor(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getCommonAncestor();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "UsingDirectiveDecl::CommonAncestor can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UsingDirectiveDecl::IdentifierToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getIdentLocation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token UsingDirectiveDecl::NamespaceKeyToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNamespaceKeyLocation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::NamespaceDecl UsingDirectiveDecl::NominatedNamespace(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNominatedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingDirectiveDecl::NominatedNamespaceAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNominatedNamespaceAsWritten();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespaceAsWritten can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDirectiveDecl::Qualifier
// 0: UsingDirectiveDecl::QualifierToken
::pasta::Token UsingDirectiveDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

UsingPackDecl::UsingPackDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingPackDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingPackDecl)
std::vector<::pasta::NamedDecl> UsingPackDecl::Expansions(void) const noexcept {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.expansions();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

::pasta::UsingPackDecl UsingPackDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingPackDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingPackDecl::InstantiatedFromUsingDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingPackDecl *>(u.UsingPackDecl);
  decltype(auto) val = self.getInstantiatedFromUsingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::InstantiatedFromUsingDeclaration can return nullptr!");
  __builtin_unreachable();
}

UsingShadowDecl::UsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
::pasta::UsingShadowDecl UsingShadowDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::BaseUsingDecl UsingShadowDecl::Introducer(void) const noexcept {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getIntroducer();
  if (val) {
    return DeclBuilder::Create<::pasta::BaseUsingDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::Introducer can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::UsingShadowDecl> UsingShadowDecl::NextUsingShadowDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getNextUsingShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::NamedDecl UsingShadowDecl::TargetDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getTargetDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::TargetDeclaration can return nullptr!");
  __builtin_unreachable();
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
::pasta::VarDecl ValueDecl::PotentiallyDecomposedVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.getPotentiallyDecomposedVarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "ValueDecl::PotentiallyDecomposedVariableDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type ValueDecl::Type(void) const noexcept {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.getType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool ValueDecl::IsInitializerCapture(void) const noexcept {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.isInitCapture();
  return val;
  __builtin_unreachable();
}

bool ValueDecl::IsWeak(void) const noexcept {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.isWeak();
  return val;
  __builtin_unreachable();
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
::pasta::Token AccessSpecDecl::AccessSpecifierToken(void) const noexcept {
  auto &self = *const_cast<clang::AccessSpecDecl *>(u.AccessSpecDecl);
  decltype(auto) val = self.getAccessSpecifierLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token AccessSpecDecl::ColonToken(void) const noexcept {
  auto &self = *const_cast<clang::AccessSpecDecl *>(u.AccessSpecDecl);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
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
std::vector<::pasta::UsingShadowDecl> BaseUsingDecl::Shadows(void) const noexcept {
  auto &self = *const_cast<clang::BaseUsingDecl *>(u.BaseUsingDecl);
  decltype(auto) val = self.shadows();
  std::vector<::pasta::UsingShadowDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

BindingDecl::BindingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, BindingDecl)
::pasta::Expr BindingDecl::Binding(void) const noexcept {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getBinding();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BindingDecl::Binding can return nullptr!");
  __builtin_unreachable();
}

::pasta::ValueDecl BindingDecl::DecomposedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getDecomposedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "BindingDecl::DecomposedDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl BindingDecl::HoldingVariable(void) const noexcept {
  auto &self = *const_cast<clang::BindingDecl *>(u.BindingDecl);
  decltype(auto) val = self.getHoldingVar();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "BindingDecl::HoldingVariable can return nullptr!");
  __builtin_unreachable();
}

BlockDecl::BlockDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, BlockDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, BlockDecl)
bool BlockDecl::BlockMissingReturnType(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.blockMissingReturnType();
  return val;
  __builtin_unreachable();
}

bool BlockDecl::CanAvoidCopyToHeap(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.canAvoidCopyToHeap();
  return val;
  __builtin_unreachable();
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::Captures
bool BlockDecl::CapturesCXXThis(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.capturesCXXThis();
  return val;
  __builtin_unreachable();
}

// 1: BlockDecl::CapturesVariable
bool BlockDecl::DoesNotEscape(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.doesNotEscape();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::Decl> BlockDecl::BlockManglingContextDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingContextDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t BlockDecl::BlockManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingNumber();
  return val;
  __builtin_unreachable();
}

::pasta::Token BlockDecl::CaretToken(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getCaretLocation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::CompoundStmt BlockDecl::CompoundBody(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getCompoundBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "BlockDecl::CompoundBody can return nullptr!");
  __builtin_unreachable();
}

uint32_t BlockDecl::NumCaptures(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getNumCaptures();
  return val;
  __builtin_unreachable();
}

uint32_t BlockDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getNumParams();
  return val;
  __builtin_unreachable();
}

// 1: BlockDecl::ParameterDeclaration
::pasta::Type BlockDecl::SignatureAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getSignatureAsWritten();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "BlockDecl::SignatureAsWritten can return nullptr!");
  __builtin_unreachable();
}

bool BlockDecl::HasCaptures(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.hasCaptures();
  return val;
  __builtin_unreachable();
}

bool BlockDecl::IsConversionFromLambda(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isConversionFromLambda();
  return val;
  __builtin_unreachable();
}

bool BlockDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isVariadic();
  return val;
  __builtin_unreachable();
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
std::vector<::pasta::ParmVarDecl> BlockDecl::Parameters(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::ParmVarDecl> BlockDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
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
::pasta::ImplicitParamDecl CapturedDecl::ContextParameter(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getContextParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "CapturedDecl::ContextParameter can return nullptr!");
  __builtin_unreachable();
}

uint32_t CapturedDecl::ContextParameterPosition(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getContextParamPosition();
  return val;
  __builtin_unreachable();
}

uint32_t CapturedDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getNumParams();
  return val;
  __builtin_unreachable();
}

// 1: CapturedDecl::Parameter
bool CapturedDecl::IsNothrow(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.isNothrow();
  return val;
  __builtin_unreachable();
}

// 0: CapturedDecl::
// 0: CapturedDecl::
std::vector<::pasta::ImplicitParamDecl> CapturedDecl::Parameters(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ImplicitParamDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
::pasta::CXXMethodDecl ClassScopeFunctionSpecializationDecl::Specialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassScopeFunctionSpecializationDecl *>(u.ClassScopeFunctionSpecializationDecl);
  decltype(auto) val = self.getSpecialization();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "ClassScopeFunctionSpecializationDecl::Specialization can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassScopeFunctionSpecializationDecl::TemplateArgumentsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::ClassScopeFunctionSpecializationDecl *>(u.ClassScopeFunctionSpecializationDecl);
  decltype(auto) val = self.hasExplicitTemplateArgs();
  return val;
  __builtin_unreachable();
}

ConceptDecl::ConceptDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, ConceptDecl)
::pasta::ConceptDecl ConceptDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  assert(false && "ConceptDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ConceptDecl::ConstraintExpression(void) const noexcept {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.getConstraintExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConceptDecl::ConstraintExpression can return nullptr!");
  __builtin_unreachable();
}

bool ConceptDecl::IsTypeConcept(void) const noexcept {
  auto &self = *const_cast<clang::ConceptDecl *>(u.ConceptDecl);
  decltype(auto) val = self.isTypeConcept();
  return val;
  __builtin_unreachable();
}

ConstructorUsingShadowDecl::ConstructorUsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : UsingShadowDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ConstructorUsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
bool ConstructorUsingShadowDecl::ConstructsVirtualBase(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.constructsVirtualBase();
  return val;
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::ConstructedBaseClass(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getConstructedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::ConstructedBaseClass can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::ConstructedBaseClassShadowDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getConstructedBaseClassShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::UsingDecl ConstructorUsingShadowDecl::Introducer(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getIntroducer();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::Introducer can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::NominatedBaseClass(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getNominatedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::NominatedBaseClass can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::NominatedBaseClassShadowDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getNominatedBaseClassShadowDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::Parent(void) const noexcept {
  auto &self = *const_cast<clang::ConstructorUsingShadowDecl *>(u.ConstructorUsingShadowDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::Parent can return nullptr!");
  __builtin_unreachable();
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
::pasta::Token DeclaratorDecl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token DeclaratorDecl::FirstInnerToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

uint32_t DeclaratorDecl::NumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
  __builtin_unreachable();
}

::pasta::Token DeclaratorDecl::FirstOuterToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: DeclaratorDecl::Qualifier
// 0: DeclaratorDecl::QualifierToken
// 1: DeclaratorDecl::TemplateParameterList
std::optional<::pasta::Expr> DeclaratorDecl::TrailingRequiresClause(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTrailingRequiresClause();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

// 0: DeclaratorDecl::
::pasta::Token DeclaratorDecl::TypeSpecEndToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecEndLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token DeclaratorDecl::TypeSpecStartToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecStartLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> DeclaratorDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::EnumConstantDecl EnumConstantDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, val);
  }
  assert(false && "EnumConstantDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::Expr> EnumConstantDecl::InitializerExpression(void) const noexcept {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getInitExpr();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

llvm::APSInt EnumConstantDecl::InitializerValue(void) const noexcept {
  auto &self = *const_cast<clang::EnumConstantDecl *>(u.EnumConstantDecl);
  decltype(auto) val = self.getInitVal();
  return val;
  __builtin_unreachable();
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
std::optional<::pasta::Expr> FieldDecl::BitWidth(void) const noexcept {
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
  __builtin_unreachable();
}

uint32_t FieldDecl::BitWidthValue(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.getBitWidthValue(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

::pasta::FieldDecl FieldDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "FieldDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::VariableArrayType> FieldDecl::CapturedVLAType(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getCapturedVLAType();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return TypeBuilder::Create<::pasta::VariableArrayType>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t FieldDecl::FieldIndex(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getFieldIndex();
  return val;
  __builtin_unreachable();
}

enum InClassInitStyle FieldDecl::InClassInitializerStyle(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitStyle();
  return static_cast<::pasta::InClassInitStyle>(val);
  __builtin_unreachable();
}

std::optional<::pasta::Expr> FieldDecl::InClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitializer();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::RecordDecl FieldDecl::Parent(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "FieldDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

bool FieldDecl::HasCapturedVLAType(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.hasCapturedVLAType();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::HasInClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.hasInClassInitializer();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsAnonymousStructOrUnion(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsBitField(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isBitField();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsMutable(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isMutable();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsUnnamedBitfield(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isUnnamedBitfield();
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsZeroLengthBitField(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroLengthBitField(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool FieldDecl::IsZeroSize(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroSize(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> FieldDecl::TemplateParameterLists(void) const noexcept {
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
bool FunctionDecl::FriendConstraintRefersToEnclosingTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.FriendConstraintRefersToEnclosingTemplate();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::UsesFPIntrin(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.UsesFPIntrin();
  return val;
  __builtin_unreachable();
}

std::optional<bool> FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (self.doesThisDeclarationHaveABody()) {
    return std::nullopt;
  } else {
    return self.doesDeclarationForceExternallyVisibleDefinition();
  }
  decltype(auto) val = self.doesDeclarationForceExternallyVisibleDefinition();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.doesThisDeclarationHaveABody();
  return val;
  __builtin_unreachable();
}

uint32_t FunctionDecl::BuiltinID(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getBuiltinID();
  return val;
  __builtin_unreachable();
}

::pasta::Type FunctionDecl::CallResultType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getCallResultType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::FunctionDecl FunctionDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

enum ConstexprSpecKind FunctionDecl::ConstexprKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getConstexprKind();
  return static_cast<::pasta::ConstexprSpecKind>(val);
  __builtin_unreachable();
}

::pasta::Type FunctionDecl::DeclaredReturnType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDeclaredReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::Token FunctionDecl::DefaultToken(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDefaultLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: FunctionDecl::DefaultedFunctionInfo
std::optional<::pasta::FunctionDecl> FunctionDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: FunctionDecl::DependentSpecializationInfo
std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::DescribedFunctionTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDescribedFunctionTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Token FunctionDecl::EllipsisToken(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::TokenRange FunctionDecl::ExceptionSpecSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecSourceRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

enum ExceptionSpecificationType FunctionDecl::ExceptionSpecType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(val);
  __builtin_unreachable();
}

// 0: FunctionDecl::FunctionTypeToken
std::optional<::pasta::FunctionDecl> FunctionDecl::InstantiatedFromDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getInstantiatedFromDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> FunctionDecl::InstantiatedFromMemberFunction(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getInstantiatedFromMemberFunction();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum LanguageLinkage FunctionDecl::LanguageLinkage(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
  __builtin_unreachable();
}

// 0: FunctionDecl::LiteralIdentifier
// 0: FunctionDecl::MemberSpecializationInfo
uint32_t FunctionDecl::MemoryFunctionKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMemoryFunctionKind();
  return val;
  __builtin_unreachable();
}

uint32_t FunctionDecl::MinRequiredArguments(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMinRequiredArguments();
  return val;
  __builtin_unreachable();
}

enum MultiVersionKind FunctionDecl::MultiVersionKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMultiVersionKind();
  return static_cast<::pasta::MultiVersionKind>(val);
  __builtin_unreachable();
}

// 0: FunctionDecl::NameInfo
uint32_t FunctionDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getNumParams();
  return val;
  __builtin_unreachable();
}

std::optional<uint32_t> FunctionDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  auto def = const_cast<clang::FunctionDecl *>(self.getDefinition());
  if (!def) {
    return std::nullopt;
  } else {
    return def->getODRHash();
  }
  decltype(auto) val = self.getODRHash();
  return val;
  __builtin_unreachable();
}

enum OverloadedOperatorKind FunctionDecl::OverloadedOperator(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getOverloadedOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(val);
  __builtin_unreachable();
}

// 1: FunctionDecl::ParameterDeclaration
::pasta::TokenRange FunctionDecl::ParametersSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getParametersSourceRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

::pasta::Token FunctionDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::PrimaryTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPrimaryTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Type FunctionDecl::ReturnType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TokenRange FunctionDecl::ReturnTypeSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

enum StorageClass FunctionDecl::StorageClass(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> FunctionDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: FunctionDecl::TemplateSpecializationArguments
// 0: FunctionDecl::TemplateSpecializationArgumentsAsWritten
// 0: FunctionDecl::TemplateSpecializationInfo
enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKindForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

enum FunctionDeclTemplatedKind FunctionDecl::TemplatedKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplatedKind();
  return static_cast<::pasta::FunctionDeclTemplatedKind>(val);
  __builtin_unreachable();
}

bool FunctionDecl::HasImplicitReturnZero(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasImplicitReturnZero();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasInheritedPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasInheritedPrototype();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasOneParameterOrDefaultArguments(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasOneParamOrDefaultArgs();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasPrototype();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasSkippedBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasTrivialBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasTrivialBody();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::HasWrittenPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasWrittenPrototype();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::InstantiationIsPending(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.instantiationIsPending();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsCPUDispatchMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUDispatchMultiVersion();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsCPUSpecificMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUSpecificMultiVersion();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsConsteval(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConsteval();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsConstexprSpecified(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexprSpecified();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsDefaulted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDefaulted();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeleted();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsDeletedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeletedAsWritten();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsDestroyingOperatorDelete(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDestroyingOperatorDelete();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExplicitlyDefaulted();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsExternC(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExternC();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isFunctionTemplateSpecialization();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsGlobal(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isGlobal();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsImplicitlyInstantiable(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isImplicitlyInstantiable();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsInExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsInExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsIneligibleOrNotSelected(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isIneligibleOrNotSelected();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsInlineBuiltinDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineBuiltinDeclaration();
  return val;
  __builtin_unreachable();
}

std::optional<bool> FunctionDecl::IsInlineDefinitionExternallyVisible(void) const noexcept {
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
  __builtin_unreachable();
}

bool FunctionDecl::IsInlineSpecified(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsInlined(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlined();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsLateTemplateParsed(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isLateTemplateParsed();
  return val;
  __builtin_unreachable();
}

std::optional<bool> FunctionDecl::IsMSExternInline(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (!self.isInlined()) {
    return std::nullopt;
  } else {
    return self.isMSExternInline();
  }
  decltype(auto) val = self.isMSExternInline();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsMSVCRTEntryPoint(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMSVCRTEntryPoint();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsMain(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMain();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMultiVersion();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsNoReturn(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isNoReturn();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsOverloadedOperator(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isOverloadedOperator();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsPure(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isPure();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsReplaceableGlobalAllocationFunction(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isReplaceableGlobalAllocationFunction();
  return val;
  __builtin_unreachable();
}

std::optional<bool> FunctionDecl::IsReservedGlobalPlacementOperator(void) const noexcept {
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
  __builtin_unreachable();
}

bool FunctionDecl::IsStatic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isStatic();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsTargetClonesMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTargetClonesMultiVersion();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsTargetMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTargetMultiVersion();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsTemplateInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTemplateInstantiation();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationInstantiatedFromAFriendDefinition();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsTrivial(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivial();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsTrivialForCall(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivialForCall();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsUserProvided(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isUserProvided();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVariadic();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::IsVirtualAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVirtualAsWritten();
  return val;
  __builtin_unreachable();
}

// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
std::vector<::pasta::ParmVarDecl> FunctionDecl::Parameters(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

bool FunctionDecl::UsesSEHTry(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.usesSEHTry();
  return val;
  __builtin_unreachable();
}

bool FunctionDecl::WillHaveBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.willHaveBody();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> FunctionDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> FunctionDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
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
::pasta::Token HLSLBufferDecl::LBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getLBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token HLSLBufferDecl::TokenStart(void) const noexcept {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getLocStart();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token HLSLBufferDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool HLSLBufferDecl::IsCBuffer(void) const noexcept {
  auto &self = *const_cast<clang::HLSLBufferDecl *>(u.HLSLBufferDecl);
  decltype(auto) val = self.isCBuffer();
  return val;
  __builtin_unreachable();
}

IndirectFieldDecl::IndirectFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, IndirectFieldDecl)
std::vector<::pasta::NamedDecl> IndirectFieldDecl::Chain(void) const noexcept {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.chain();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: IndirectFieldDecl::
// 0: IndirectFieldDecl::
std::optional<::pasta::FieldDecl> IndirectFieldDecl::AnonymousField(void) const noexcept {
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
  __builtin_unreachable();
}

::pasta::IndirectFieldDecl IndirectFieldDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::IndirectFieldDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t IndirectFieldDecl::ChainingSize(void) const noexcept {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  decltype(auto) val = self.getChainingSize();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::VarDecl> IndirectFieldDecl::VariableDeclaration(void) const noexcept {
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
  __builtin_unreachable();
}

LabelDecl::LabelDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LabelDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, LabelDecl)
std::string_view LabelDecl::MSAssemblyLabel(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.getMSAsmLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

::pasta::LabelStmt LabelDecl::Statement(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.getStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::LabelStmt>(ast, val);
  }
  assert(false && "LabelDecl::Statement can return nullptr!");
  __builtin_unreachable();
}

bool LabelDecl::IsGnuLocal(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isGnuLocal();
  return val;
  __builtin_unreachable();
}

bool LabelDecl::IsMSAssemblyLabel(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isMSAsmLabel();
  return val;
  __builtin_unreachable();
}

bool LabelDecl::IsResolvedMSAssemblyLabel(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isResolvedMSAsmLabel();
  return val;
  __builtin_unreachable();
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
bool MSPropertyDecl::HasGetter(void) const noexcept {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasGetter();
  return val;
  __builtin_unreachable();
}

bool MSPropertyDecl::HasSetter(void) const noexcept {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasSetter();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> MSPropertyDecl::TemplateParameterLists(void) const noexcept {
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
bool NonTypeTemplateParmDecl::DefaultArgumentWasInherited(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
  __builtin_unreachable();
}

// 0: NonTypeTemplateParmDecl::DefaultArgumentStorage
std::optional<::pasta::Expr> NonTypeTemplateParmDecl::DefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgument();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Token NonTypeTemplateParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 1: NonTypeTemplateParmDecl::ExpansionType
// 1: NonTypeTemplateParmDecl::ExpansionType
std::optional<uint32_t> NonTypeTemplateParmDecl::NumExpansionTypes(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  if (!self.isExpandedParameterPack()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumExpansionTypes();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::Expr> NonTypeTemplateParmDecl::PlaceholderTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getPlaceholderTypeConstraint();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasPlaceholderTypeConstraint();
  return val;
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> NonTypeTemplateParmDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::Type> NonTypeTemplateParmDecl::ExpansionTypes(void) const noexcept {
  std::vector<::pasta::Type> ret;
  if (!u.NonTypeTemplateParmDecl->isExpandedParameterPack()) {
    return ret;
  }
  auto convert_elem = [&] (clang::QualType val) {
    return TypeBuilder::Build(ast, val);
  };
  auto count = u.NonTypeTemplateParmDecl->getNumExpansionTypes();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.NonTypeTemplateParmDecl->getExpansionType(i)));
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
std::vector<::pasta::Expr> OMPAllocateDecl::Varlists(void) const noexcept {
  auto &self = *const_cast<clang::OMPAllocateDecl *>(u.OMPAllocateDecl);
  decltype(auto) val = self.varlists();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::Expr OMPDeclareMapperDecl::MapperVariableReference(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareMapperDecl *>(u.OMPDeclareMapperDecl);
  decltype(auto) val = self.getMapperVarRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareMapperDecl::MapperVariableReference can return nullptr!");
  __builtin_unreachable();
}

::pasta::OMPDeclareMapperDecl OMPDeclareMapperDecl::PrevDeclarationInScope(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareMapperDecl *>(u.OMPDeclareMapperDecl);
  decltype(auto) val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareMapperDecl>(ast, val);
  }
  assert(false && "OMPDeclareMapperDecl::PrevDeclarationInScope can return nullptr!");
  __builtin_unreachable();
}

OMPDeclareReductionDecl::OMPDeclareReductionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
::pasta::Expr OMPDeclareReductionDecl::Combiner(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombiner();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::Combiner can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::CombinerIn(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombinerIn();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::CombinerIn can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::CombinerOut(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getCombinerOut();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::CombinerOut can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::InitializerOriginal(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitOrig();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::InitializerOriginal can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::InitializerPrivate(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitPriv();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::InitializerPrivate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::Initializer(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::Initializer can return nullptr!");
  __builtin_unreachable();
}

enum OMPDeclareReductionDeclInitKind OMPDeclareReductionDecl::InitializerKind(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getInitializerKind();
  return static_cast<::pasta::OMPDeclareReductionDeclInitKind>(val);
  __builtin_unreachable();
}

::pasta::OMPDeclareReductionDecl OMPDeclareReductionDecl::PrevDeclarationInScope(void) const noexcept {
  auto &self = *const_cast<clang::OMPDeclareReductionDecl *>(u.OMPDeclareReductionDecl);
  decltype(auto) val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareReductionDecl>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::PrevDeclarationInScope can return nullptr!");
  __builtin_unreachable();
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
std::vector<::pasta::Expr> OMPThreadPrivateDecl::Varlists(void) const noexcept {
  auto &self = *const_cast<clang::OMPThreadPrivateDecl *>(u.OMPThreadPrivateDecl);
  decltype(auto) val = self.varlists();
  std::vector<::pasta::Expr> ret;
  for (auto stmt_ptr : val) {
    if (stmt_ptr) {
      ret.emplace_back(StmtBuilder::Create<::pasta::Expr>(ast, stmt_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
std::vector<::pasta::TemplateParameterList> ObjCAtDefsFieldDecl::TemplateParameterLists(void) const noexcept {
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
bool ObjCCategoryDecl::IsClassExtension(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.IsClassExtension();
  return val;
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryDecl::CategoryNameToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCCategoryDecl::ClassInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryImplDecl ObjCCategoryDecl::Implementation(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryImplDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::Implementation can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryDecl::InstanceVariableLBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryDecl::InstanceVariableRBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategory(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getNextClassCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategory can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategoryRaw(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getNextClassCategoryRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategoryRaw can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCCategoryDecl::ReferencedProtocols
// 0: ObjCCategoryDecl::TypeParameterList
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCCategoryDecl::InstanceVariables(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::Token> ObjCCategoryDecl::ProtocolTokens(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
  __builtin_unreachable();
}

// 0: ObjCCategoryDecl::
std::vector<::pasta::ObjCProtocolDecl> ObjCCategoryDecl::Protocols(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::ObjCCategoryDecl ObjCCategoryImplDecl::CategoryDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryImplDecl *>(u.ObjCCategoryImplDecl);
  decltype(auto) val = self.getCategoryDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryImplDecl::CategoryDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryImplDecl::CategoryNameToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryImplDecl *>(u.ObjCCategoryImplDecl);
  decltype(auto) val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
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
enum ObjCIvarDeclAccessControl ObjCIvarDecl::AccessControl(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getAccessControl();
  return static_cast<::pasta::ObjCIvarDeclAccessControl>(val);
  __builtin_unreachable();
}

enum ObjCIvarDeclAccessControl ObjCIvarDecl::CanonicalAccessControl(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getCanonicalAccessControl();
  return static_cast<::pasta::ObjCIvarDeclAccessControl>(val);
  __builtin_unreachable();
}

::pasta::ObjCIvarDecl ObjCIvarDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCIvarDecl::ContainingInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getContainingInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::ContainingInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCIvarDecl ObjCIvarDecl::NextInstanceVariable(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getNextIvar();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::NextInstanceVariable can return nullptr!");
  __builtin_unreachable();
}

bool ObjCIvarDecl::Synthesize(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getSynthesize();
  return val;
  __builtin_unreachable();
}

// 1: ObjCIvarDecl::UsageType
std::vector<::pasta::TemplateParameterList> ObjCIvarDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::Token ObjCTypeParamDecl::ColonToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getColonLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

uint32_t ObjCTypeParamDecl::Index(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getIndex();
  return val;
  __builtin_unreachable();
}

enum ObjCTypeParamVariance ObjCTypeParamDecl::Variance(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVariance();
  return static_cast<::pasta::ObjCTypeParamVariance>(val);
  __builtin_unreachable();
}

::pasta::Token ObjCTypeParamDecl::VarianceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVarianceLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.hasExplicitBound();
  return val;
  __builtin_unreachable();
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
::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::RedeclarableTemplateDecl *>(u.RedeclarableTemplateDecl);
  decltype(auto) val = self.isMemberSpecialization();
  return val;
  __builtin_unreachable();
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
::pasta::TokenRange TagDecl::BraceRange(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getBraceRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

::pasta::TagDecl TagDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::TagDecl> TagDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::Token TagDecl::FirstInnerToken(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::string_view TagDecl::KindName(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
  __builtin_unreachable();
}

uint32_t TagDecl::NumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
  __builtin_unreachable();
}

::pasta::Token TagDecl::FirstOuterToken(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: TagDecl::Qualifier
// 0: TagDecl::QualifierToken
enum TagTypeKind TagDecl::TagKind(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTagKind();
  return static_cast<::pasta::TagTypeKind>(val);
  __builtin_unreachable();
}

// 1: TagDecl::TemplateParameterList
std::optional<::pasta::TypedefNameDecl> TagDecl::TypedefNameForAnonymousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTypedefNameForAnonDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  __builtin_unreachable();
}

bool TagDecl::HasNameForLinkage(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.hasNameForLinkage();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsBeingDefined(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isBeingDefined();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsClass(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isClass();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsCompleteDefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinition();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsCompleteDefinitionRequired(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinitionRequired();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsDependentType(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isDependentType();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsEmbeddedInDeclarator(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEmbeddedInDeclarator();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsEnum(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEnum();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsFreeStanding(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isFreeStanding();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsInterface(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isInterface();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsStruct(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isStruct();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsThisDeclarationADemotedDefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isThisDeclarationADemotedDefinition();
  return val;
  __builtin_unreachable();
}

bool TagDecl::IsUnion(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isUnion();
  return val;
  __builtin_unreachable();
}

bool TagDecl::MayHaveOutOfDateDefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.mayHaveOutOfDateDef();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> TagDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::TemplateParamObjectDecl TemplateParamObjectDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TemplateParamObjectDecl *>(u.TemplateParamObjectDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateParamObjectDecl>(ast, val);
  }
  assert(false && "TemplateParamObjectDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: TemplateParamObjectDecl::Value
TemplateTypeParmDecl::TemplateTypeParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateTypeParmDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateTypeParmDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TemplateTypeParmDecl)
bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.defaultArgumentWasInherited();
  return val;
  __builtin_unreachable();
}

// 0: TemplateTypeParmDecl::DefaultArgumentStorage
std::optional<::pasta::Type> TemplateTypeParmDecl::DefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  if (!self.getDefaultArgumentInfo()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getDefaultArgument();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> TemplateTypeParmDecl::DefaultArgumentInfo(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  __builtin_unreachable();
}

::pasta::Token TemplateTypeParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

uint32_t TemplateTypeParmDecl::Depth(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDepth();
  return val;
  __builtin_unreachable();
}

uint32_t TemplateTypeParmDecl::Index(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getIndex();
  return val;
  __builtin_unreachable();
}

uint32_t TemplateTypeParmDecl::NumExpansionParameters(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getNumExpansionParameters();
  return val;
  __builtin_unreachable();
}

// 0: TemplateTypeParmDecl::TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasTypeConstraint();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.wasDeclaredWithTypename();
  return val;
  __builtin_unreachable();
}

TypeAliasDecl::TypeAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, TypeAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(TypedefNameDecl, TypeAliasDecl)
std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasDecl::DescribedAliasTemplate(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasDecl *>(u.TypeAliasDecl);
  decltype(auto) val = self.getDescribedAliasTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::TypeAliasDecl TypeAliasTemplateDecl::TemplatedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::TemplatedDeclaration can return nullptr!");
  __builtin_unreachable();
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
::pasta::UnresolvedUsingValueDecl UnresolvedUsingValueDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingValueDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingValueDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingValueDecl::EllipsisToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

// 0: UnresolvedUsingValueDecl::NameInfo
// 0: UnresolvedUsingValueDecl::Qualifier
// 0: UnresolvedUsingValueDecl::QualifierToken
::pasta::Token UnresolvedUsingValueDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.isAccessDeclaration();
  return val;
  __builtin_unreachable();
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
  __builtin_unreachable();
}

UsingDecl::UsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : BaseUsingDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(BaseUsingDecl, UsingDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDecl)
::pasta::UsingDecl UsingDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  assert(false && "UsingDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDecl::NameInfo
// 0: UsingDecl::Qualifier
// 0: UsingDecl::QualifierToken
::pasta::Token UsingDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

bool UsingDecl::HasTypename(void) const noexcept {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.hasTypename();
  return val;
  __builtin_unreachable();
}

bool UsingDecl::IsAccessDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.isAccessDeclaration();
  return val;
  __builtin_unreachable();
}

UsingEnumDecl::UsingEnumDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : BaseUsingDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(BaseUsingDecl, UsingEnumDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, UsingEnumDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingEnumDecl)
::pasta::UsingEnumDecl UsingEnumDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingEnumDecl>(ast, val);
  }
  assert(false && "UsingEnumDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::EnumDecl UsingEnumDecl::EnumDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "UsingEnumDecl::EnumDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UsingEnumDecl::EnumToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type UsingEnumDecl::EnumType(void) const noexcept {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getEnumType();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "UsingEnumDecl::EnumType can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingEnumDecl::EnumTypeToken
// 0: UsingEnumDecl::Qualifier
// 0: UsingEnumDecl::QualifierToken
::pasta::Token UsingEnumDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingEnumDecl *>(u.UsingEnumDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
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
std::optional<::pasta::VarDecl> VarDecl::ActingDefinition(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getActingDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::VarDecl VarDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::VarTemplateDecl> VarDecl::DescribedVariableTemplate(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getDescribedVarTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

// 0: VarDecl::EvaluatedStatement
// 0: VarDecl::EvaluatedValue
// 1: VarDecl::FlexibleArrayInitializerCharacters
std::optional<::pasta::Expr> VarDecl::Initializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInit();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

enum VarDeclInitializationStyle VarDecl::InitializerStyle(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitStyle();
  return static_cast<::pasta::VarDeclInitializationStyle>(val);
  __builtin_unreachable();
}

std::optional<::pasta::VarDecl> VarDecl::InitializingDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitializingDeclaration();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::VarDecl> VarDecl::InstantiatedFromStaticDataMember(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInstantiatedFromStaticDataMember();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum LanguageLinkage VarDecl::LanguageLinkage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
  __builtin_unreachable();
}

// 0: VarDecl::MemberSpecializationInfo
::pasta::Token VarDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

enum StorageClass VarDecl::StorageClass(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
  __builtin_unreachable();
}

enum StorageDuration VarDecl::StorageDuration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
  __builtin_unreachable();
}

enum VarDeclTLSKind VarDecl::TLSKind(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTLSKind();
  return static_cast<::pasta::VarDeclTLSKind>(val);
  __builtin_unreachable();
}

enum ThreadStorageClassSpecifier VarDecl::TSCSpec(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTSCSpec();
  return static_cast<::pasta::ThreadStorageClassSpecifier>(val);
  __builtin_unreachable();
}

std::optional<::pasta::VarDecl> VarDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKindForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

bool VarDecl::HasConstantInitialization(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasConstantInitialization();
  return val;
  __builtin_unreachable();
}

bool VarDecl::HasDependentAlignment(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasDependentAlignment();
  return val;
  __builtin_unreachable();
}

bool VarDecl::HasExternalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasExternalStorage();
  return val;
  __builtin_unreachable();
}

std::optional<bool> VarDecl::HasFlexibleArrayInitializer(void) const noexcept {
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
  __builtin_unreachable();
}

bool VarDecl::HasGlobalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasGlobalStorage();
  return val;
  __builtin_unreachable();
}

std::optional<bool> VarDecl::HasICEInitializer(void) const noexcept {
  auto &self = *(u.VarDecl);
  if (auto init = self.getInit(); !init || init->isValueDependent()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasICEInitializer(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool VarDecl::HasInitializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasInit();
  return val;
  __builtin_unreachable();
}

bool VarDecl::HasLocalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasLocalStorage();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsARCPseudoStrong(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isARCPseudoStrong();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsCXXForRangeDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isCXXForRangeDecl();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsDirectInitializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isDirectInit();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsEscapingByref(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isEscapingByref();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsExceptionVariable(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExceptionVariable();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsExternC(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExternC();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsFileVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFileVarDecl();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsFunctionOrMethodVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFunctionOrMethodVarDecl();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsInExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsInExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsInitializerCapture(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInitCapture();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsInline(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInline();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsInlineSpecified(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsKnownToBeDefined(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isKnownToBeDefined();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsLocalVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDecl();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsLocalVariableDeclarationOrParm(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDeclOrParm();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsNRVOVariable(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNRVOVariable();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsNoDestroy(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isNoDestroy(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsNonEscapingByref(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNonEscapingByref();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsObjCForDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isObjCForDecl();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsPreviousDeclarationInSameBlockScope(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isPreviousDeclInSameBlockScope();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsStaticDataMember(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticDataMember();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsStaticLocal(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticLocal();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsThisDeclarationADemotedDefinition(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isThisDeclarationADemotedDefinition();
  return val;
  __builtin_unreachable();
}

bool VarDecl::IsUsableInConstantExpressions(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool VarDecl::MightBeUsableInConstantExpressions(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.mightBeUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

// 1: VarDecl::NeedsDestruction
std::vector<::pasta::TemplateParameterList> VarDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::VarTemplateDecl VarTemplateDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::VarTemplateDecl> VarTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::VarDecl VarTemplateDecl::TemplatedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::TemplatedDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplateDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

// 0: VarTemplateDecl::
// 0: VarTemplateDecl::
std::vector<::pasta::VarTemplateSpecializationDecl> VarTemplateDecl::Specializations(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::VarTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::VarTemplateSpecializationDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
::pasta::Token VarTemplateSpecializationDecl::ExternToken(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::InstantiatedFrom(void) const noexcept {
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
  __builtin_unreachable();
}

::pasta::Token VarTemplateSpecializationDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

enum TemplateSpecializationKind VarTemplateSpecializationDecl::SpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateSpecializationDecl::SpecializedTemplate(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const noexcept {
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
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> VarTemplateSpecializationDecl::TemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

// 0: VarTemplateSpecializationDecl::TemplateArgumentsInfo
std::vector<::pasta::TemplateArgument> VarTemplateSpecializationDecl::TemplateInstantiationArguments(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateInstantiationArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

::pasta::Token VarTemplateSpecializationDecl::TemplateKeywordToken(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

::pasta::Type VarTemplateSpecializationDecl::TypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val->getType());
  assert(false && "VarTemplateSpecializationDecl::TypeAsWritten can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
  __builtin_unreachable();
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
  __builtin_unreachable();
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> VarTemplateSpecializationDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::CXXConstructorDecl CXXDeductionGuideDecl::CorrespondingConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.getCorrespondingConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXDeductionGuideDecl::CorrespondingConstructor can return nullptr!");
  __builtin_unreachable();
}

::pasta::TemplateDecl CXXDeductionGuideDecl::DeducedTemplate(void) const noexcept {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.getDeducedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  assert(false && "CXXDeductionGuideDecl::DeducedTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXDeductionGuideDecl::ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const noexcept {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.isCopyDeductionCandidate();
  return val;
  __builtin_unreachable();
}

bool CXXDeductionGuideDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.isExplicit();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXDeductionGuideDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> CXXDeductionGuideDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  auto count = u.CXXDeductionGuideDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDeductionGuideDecl->getParamDecl(i)));
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
::pasta::CXXMethodDecl CXXMethodDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 1: CXXMethodDecl::CorrespondingMethodDeclaredInClass
// 1: CXXMethodDecl::CorrespondingMethodInClass
// 2: DevirtualizedMethod
// 0: CXXMethodDecl::MethodQualifiers
::pasta::CXXMethodDecl CXXMethodDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXMethodDecl::Parent(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

enum RefQualifierKind CXXMethodDecl::ReferenceQualifier(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> CXXMethodDecl::ThisObjectType(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  if (!self.isInstance()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getThisObjectType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> CXXMethodDecl::ThisType(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  if (!self.isInstance()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getThisType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

bool CXXMethodDecl::HasInlineBody(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.hasInlineBody();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsConst(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isConst();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsCopyAssignmentOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isCopyAssignmentOperator();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsInstance(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isInstance();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsLambdaStaticInvoker(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isLambdaStaticInvoker();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsMoveAssignmentOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isMoveAssignmentOperator();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsStatic(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isStatic();
  return val;
  __builtin_unreachable();
}

// 1: CXXMethodDecl::IsUsualDeallocationFunction
bool CXXMethodDecl::IsVirtual(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVirtual();
  return val;
  __builtin_unreachable();
}

bool CXXMethodDecl::IsVolatile(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVolatile();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::CXXMethodDecl> CXXMethodDecl::OverriddenMethods(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.overridden_methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

uint32_t CXXMethodDecl::SizeOverriddenMethods(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.size_overridden_methods();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXMethodDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> CXXMethodDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  auto count = u.CXXMethodDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXMethodDecl->getParamDecl(i)));
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
::pasta::ClassTemplateDecl ClassTemplateDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::ClassTemplateDecl> ClassTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ClassTemplateDecl::TemplatedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::TemplatedDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

// 0: ClassTemplateDecl::
// 0: ClassTemplateDecl::
std::vector<::pasta::ClassTemplateSpecializationDecl> ClassTemplateDecl::Specializations(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::ClassTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::ClassTemplateSpecializationDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
std::vector<::pasta::BindingDecl> DecompositionDecl::Bindings(void) const noexcept {
  auto &self = *const_cast<clang::DecompositionDecl *>(u.DecompositionDecl);
  decltype(auto) val = self.bindings();
  std::vector<::pasta::BindingDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::BindingDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> DecompositionDecl::TemplateParameterLists(void) const noexcept {
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
std::vector<::pasta::EnumConstantDecl> EnumDecl::Enumerators(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.enumerators();
  std::vector<::pasta::EnumConstantDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

::pasta::EnumDecl EnumDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::EnumDecl EnumDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::EnumDecl> EnumDecl::InstantiatedFromMemberEnum(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getInstantiatedFromMemberEnum();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Type> EnumDecl::IntegerType(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  if (self.getIntegerType().isNull()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getIntegerType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::TokenRange EnumDecl::IntegerTypeRange(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getIntegerTypeRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

// 0: EnumDecl::MemberSpecializationInfo
::pasta::EnumDecl EnumDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t EnumDecl::NumNegativeBits(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getNumNegativeBits();
  return val;
  __builtin_unreachable();
}

uint32_t EnumDecl::NumPositiveBits(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getNumPositiveBits();
  return val;
  __builtin_unreachable();
}

std::optional<uint32_t> EnumDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  auto def = const_cast<clang::EnumDecl *>(self.getDefinition());
  if (!def) {
    return std::nullopt;
  } else {
    return def->getODRHash();
  }
  decltype(auto) val = self.getODRHash();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::EnumDecl> EnumDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Type> EnumDecl::PromotionType(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPromotionType();
  if (val.isNull()) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::EnumDecl> EnumDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum TemplateSpecializationKind EnumDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

bool EnumDecl::IsClosed(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosed();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsClosedFlag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedFlag();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsClosedNonFlag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedNonFlag();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsComplete(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isComplete();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsFixed(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isFixed();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsScoped(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScoped();
  return val;
  __builtin_unreachable();
}

bool EnumDecl::IsScopedUsingClassTag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScopedUsingClassTag();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> EnumDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::FunctionTemplateDecl FunctionTemplateDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::FunctionTemplateDecl> FunctionTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::FunctionDecl FunctionTemplateDecl::TemplatedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::TemplatedDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool FunctionTemplateDecl::IsAbbreviated(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.isAbbreviated();
  return val;
  __builtin_unreachable();
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
  __builtin_unreachable();
}

// 0: FunctionTemplateDecl::
// 0: FunctionTemplateDecl::
std::vector<::pasta::FunctionDecl> FunctionTemplateDecl::Specializations(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.specializations();
  std::vector<::pasta::FunctionDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
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
enum ImplicitParamDeclImplicitParamKind ImplicitParamDecl::ParameterKind(void) const noexcept {
  auto &self = *const_cast<clang::ImplicitParamDecl *>(u.ImplicitParamDecl);
  decltype(auto) val = self.getParameterKind();
  return static_cast<::pasta::ImplicitParamDeclImplicitParamKind>(val);
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> ImplicitParamDecl::TemplateParameterLists(void) const noexcept {
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
std::vector<::pasta::TemplateParameterList> OMPCapturedExprDecl::TemplateParameterLists(void) const noexcept {
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
std::optional<::pasta::Expr> ParmVarDecl::DefaultArgument(void) const noexcept {
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
  __builtin_unreachable();
}

::pasta::TokenRange ParmVarDecl::DefaultArgumentRange(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getDefaultArgRange();
  return ast->TokenRangeFrom(val);
  __builtin_unreachable();
}

uint32_t ParmVarDecl::FunctionScopeDepth(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeDepth();
  return val;
  __builtin_unreachable();
}

uint32_t ParmVarDecl::FunctionScopeIndex(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeIndex();
  return val;
  __builtin_unreachable();
}

enum DeclObjCDeclQualifier ParmVarDecl::ObjCDeclQualifier(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
  __builtin_unreachable();
}

::pasta::Type ParmVarDecl::OriginalType(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getOriginalType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::Expr> ParmVarDecl::UninstantiatedDefaultArgument(void) const noexcept {
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
  __builtin_unreachable();
}

bool ParmVarDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasDefaultArg();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::HasInheritedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasInheritedDefaultArg();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::HasUninstantiatedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUninstantiatedDefaultArg();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::HasUnparsedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUnparsedDefaultArg();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::IsDestroyedInCallee(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isDestroyedInCallee();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::IsKNRPromoted(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isKNRPromoted();
  return val;
  __builtin_unreachable();
}

bool ParmVarDecl::IsObjCMethodParameter(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isObjCMethodParameter();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> ParmVarDecl::TemplateParameterLists(void) const noexcept {
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
bool RecordDecl::CanPassInRegisters(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.canPassInRegisters();
  return val;
  __builtin_unreachable();
}

// 0: RecordDecl::
// 0: RecordDecl::
// 0: RecordDecl::
std::vector<::pasta::FieldDecl> RecordDecl::Fields(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.fields();
  std::vector<::pasta::FieldDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FieldDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::optional<::pasta::FieldDecl> RecordDecl::FirstNamedDataMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.findFirstNamedDataMember();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  __builtin_unreachable();
}

enum RecordDeclArgPassingKind RecordDecl::ArgumentPassingRestrictions(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getArgPassingRestrictions();
  return static_cast<::pasta::RecordDeclArgPassingKind>(val);
  __builtin_unreachable();
}

std::optional<::pasta::RecordDecl> RecordDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

::pasta::RecordDecl RecordDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::RecordDecl> RecordDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

bool RecordDecl::HasFlexibleArrayMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasFlexibleArrayMember();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasLoadedFieldsFromExternalStorage();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasObjectMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasObjectMember();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::HasVolatileMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasVolatileMember();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsCapturedRecord(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isCapturedRecord();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsInjectedClassName(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isInjectedClassName();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsLambda(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsMsStruct(void) const noexcept {
  auto &self = *(u.RecordDecl);
  decltype(auto) val = self.isMsStruct(ast->ci->getASTContext());
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveCopy();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDestroy();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsOrContainsUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isOrContainsUnion();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsParameterDestroyedInCallee(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isParamDestroyedInCallee();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::IsRandomized(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isRandomized();
  return val;
  __builtin_unreachable();
}

bool RecordDecl::MayInsertExtraPadding(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.mayInsertExtraPadding();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> RecordDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::VarTemplatePartialSpecializationDecl VarTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "VarTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

// 0: VarTemplatePartialSpecializationDecl::TemplateArgumentsAsWritten
::pasta::TemplateParameterList VarTemplatePartialSpecializationDecl::TemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  assert(false && "VarTemplatePartialSpecializationDecl::TemplateParameters can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplatePartialSpecializationDecl *>(u.VarTemplatePartialSpecializationDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> VarTemplatePartialSpecializationDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::CXXConstructorDecl CXXConstructorDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXConstructorDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXConstructorDecl::ExplicitSpecifier
// 0: CXXConstructorDecl::InheritedConstructor
uint32_t CXXConstructorDecl::NumConstructorInitializers(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.getNumCtorInitializers();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::CXXConstructorDecl> CXXConstructorDecl::TargetConstructor(void) const noexcept {
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
  __builtin_unreachable();
}

// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::
// 0: CXXConstructorDecl::Initializers
bool CXXConstructorDecl::IsConvertingConstructor(bool b) const noexcept {
  auto &self = *(u.CXXConstructorDecl);
  decltype(auto) val = self.isConvertingConstructor(b);
  return val;
  __builtin_unreachable();
}

bool CXXConstructorDecl::IsDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDefaultConstructor();
  return val;
  __builtin_unreachable();
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDelegatingConstructor();
  return val;
  __builtin_unreachable();
}

bool CXXConstructorDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isExplicit();
  return val;
  __builtin_unreachable();
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isInheritingConstructor();
  return val;
  __builtin_unreachable();
}

bool CXXConstructorDecl::IsSpecializationCopyingObject(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isSpecializationCopyingObject();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXConstructorDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> CXXConstructorDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
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
::pasta::CXXConversionDecl CXXConversionDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConversionDecl>(ast, val);
  }
  assert(false && "CXXConversionDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type CXXConversionDecl::ConversionType(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.getConversionType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

// 0: CXXConversionDecl::ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isExplicit();
  return val;
  __builtin_unreachable();
}

bool CXXConversionDecl::IsLambdaToBlockPointerConversion(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isLambdaToBlockPointerConversion();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXConversionDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> CXXConversionDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
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
::pasta::CXXDestructorDecl CXXDestructorDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> CXXDestructorDecl::OperatorDelete(void) const noexcept {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDelete();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::Expr> CXXDestructorDecl::OperatorDeleteThisArgument(void) const noexcept {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDeleteThisArg();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXDestructorDecl::TemplateParameterLists(void) const noexcept {
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

std::vector<::pasta::ParmVarDecl> CXXDestructorDecl::ParameterDeclarations(void) const noexcept {
  std::vector<::pasta::ParmVarDecl> ret;
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
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
std::optional<bool> CXXRecordDecl::AllowConstDefaultInitializer(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.allowConstDefaultInit();
  return val;
  __builtin_unreachable();
}

std::optional<std::vector<::pasta::CXXBaseSpecifier>> CXXRecordDecl::Bases(void) const noexcept {
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
  __builtin_unreachable();
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<enum MSInheritanceModel> CXXRecordDecl::CalculateInheritanceModel(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.calculateInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
  __builtin_unreachable();
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::Captures
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::CXXConstructorDecl> CXXRecordDecl::Constructors(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.ctors();
  std::vector<::pasta::CXXConstructorDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, decl_ptr));
    }
  }
  return ret;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedCopyConstructorIsDeleted();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDefaultConstructorIsConstexpr();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDestructorIsConstexpr();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::DefaultedDestructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedDestructorIsDeleted();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.defaultedMoveConstructorIsDeleted();
  return val;
  __builtin_unreachable();
}

// 1: CXXRecordDecl::ForallBases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<std::vector<::pasta::FriendDecl>> CXXRecordDecl::Friends(void) const noexcept {
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
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::CanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::CanonicalDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDefinition();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::FunctionTemplateDecl> CXXRecordDecl::DependentLambdaCallOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDependentLambdaCallOperator();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::ClassTemplateDecl> CXXRecordDecl::DescribedClassTemplate(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDescribedClassTemplate();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::CXXDestructorDecl> CXXRecordDecl::Destructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDestructor();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::DeviceLambdaManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDeviceLambdaManglingNumber();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::TemplateParameterList> CXXRecordDecl::GenericLambdaTemplateParameterList(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isGenericLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getGenericLambdaTemplateParameterList();
  if (!val) {
    return std::nullopt;
  }
  return ::pasta::TemplateParameterList(ast, val);
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::InstantiatedFromMemberClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getInstantiatedFromMemberClass();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::CXXMethodDecl> CXXRecordDecl::LambdaCallOperator(void) const noexcept {
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
  __builtin_unreachable();
}

std::optional<enum LambdaCaptureDefault> CXXRecordDecl::LambdaCaptureDefault(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(val);
  __builtin_unreachable();
}

std::optional<::pasta::Decl> CXXRecordDecl::LambdaContextDeclaration(void) const noexcept {
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
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::LambdaDependencyKind(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaDependencyKind();
  return val;
  __builtin_unreachable();
}

std::optional<std::vector<::pasta::NamedDecl>> CXXRecordDecl::LambdaExplicitTemplateParameters(void) const noexcept {
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
  __builtin_unreachable();
}

std::optional<uint32_t> CXXRecordDecl::LambdaManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaManglingNumber();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::Type> CXXRecordDecl::LambdaType(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getLambdaTypeInfo();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  __builtin_unreachable();
}

std::optional<enum MSInheritanceModel> CXXRecordDecl::MSInheritanceModel(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getMSInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
  __builtin_unreachable();
}

enum MSVtorDispMode CXXRecordDecl::MSVtorDispMode(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMSVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(val);
  __builtin_unreachable();
}

// 0: CXXRecordDecl::MemberSpecializationInfo
::pasta::CXXRecordDecl CXXRecordDecl::MostRecentDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::MostRecentNonInjectedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMostRecentNonInjectedDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<uint32_t> CXXRecordDecl::NumBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumBases();
  return val;
  __builtin_unreachable();
}

std::optional<uint32_t> CXXRecordDecl::NumVirtualBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getNumVBases();
  return val;
  __builtin_unreachable();
}

std::optional<uint32_t> CXXRecordDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getODRHash();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (!val) {
    return std::nullopt;
  }
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::TemplateInstantiationPattern(void) const noexcept {
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
  __builtin_unreachable();
}

enum TemplateSpecializationKind CXXRecordDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

// 0: CXXRecordDecl::VisibleConversionFunctions
std::optional<bool> CXXRecordDecl::HasAnyDependentBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasAnyDependentBases();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasConstexprDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasConstexprDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasConstexprNonCopyMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasCopyAssignmentWithConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasCopyAssignmentWithConstParam();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasCopyConstructorWithConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasCopyConstructorWithConstParam();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasDefinition(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDefinition();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasDirectFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasDirectFields();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasFriends(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasFriends();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasInClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInClassInitializer();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasInheritedAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInheritedAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasInheritedConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInheritedConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasInitializerMethod(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasInitMethod();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasIrrelevantDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasIrrelevantDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasKnownLambdaInternalLinkage();
  return val;
  __builtin_unreachable();
}

// 1: CXXRecordDecl::HasMemberName
std::optional<bool> CXXRecordDecl::HasMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasMutableFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasMutableFields();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonLiteralTypeFieldsOrBases();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialCopyConstructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialDestructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialDestructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasNonTrivialMoveConstructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasPrivateFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasPrivateFields();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasProtectedFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasProtectedFields();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasSimpleCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasSimpleCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasSimpleDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasSimpleMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasSimpleMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasSimpleMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialCopyConstructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialDestructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialDestructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasTrivialMoveConstructorForCall();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUninitializedReferenceMember(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUninitializedReferenceMember();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserDeclaredMoveOperation(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserDeclaredMoveOperation();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasUserProvidedDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::HasVariantMembers(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.hasVariantMembers();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::ImplicitCopyAssignmentHasConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.implicitCopyAssignmentHasConstParam();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::ImplicitCopyConstructorHasConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.implicitCopyConstructorHasConstParam();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsAbstract(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAbstract();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsAggregate(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAggregate();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsAnyDestructorNoReturn(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isAnyDestructorNoReturn();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsCLike(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isCLike();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsCXX11StandardLayout(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isCXX11StandardLayout();
  return val;
  __builtin_unreachable();
}

// 1: CXXRecordDecl::IsCurrentInstantiation
bool CXXRecordDecl::IsDependentLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isDependentLambda();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isDynamicClass();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsEffectivelyFinal(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isEffectivelyFinal();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsEmpty(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isEmpty();
  return val;
  __builtin_unreachable();
}

bool CXXRecordDecl::IsGenericLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isGenericLambda();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsInterfaceLike(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isInterfaceLike();
  return val;
  __builtin_unreachable();
}

bool CXXRecordDecl::IsLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsLiteral(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isLiteral();
  return val;
  __builtin_unreachable();
}

std::optional<::pasta::FunctionDecl> CXXRecordDecl::IsLocalClass(void) const noexcept {
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
  __builtin_unreachable();
}

bool CXXRecordDecl::IsNeverDependentLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isNeverDependentLambda();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsPOD(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isPOD();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsParsingBaseSpecifiers(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isParsingBaseSpecifiers();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsPolymorphic(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isPolymorphic();
  return val;
  __builtin_unreachable();
}

// 1: CXXRecordDecl::IsProvablyNotDerivedFrom
std::optional<bool> CXXRecordDecl::IsStandardLayout(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStandardLayout();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsStructural(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isStructural();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsTrivial(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isTrivial();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::IsTriviallyCopyable(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.isTriviallyCopyable();
  return val;
  __builtin_unreachable();
}

// 1: CXXRecordDecl::IsVirtuallyDerivedFrom
std::optional<bool> CXXRecordDecl::LambdaIsDefaultConstructibleAndAssignable(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.isLambda()) {
    return std::nullopt;
  }
  decltype(auto) val = self.lambdaIsDefaultConstructibleAndAssignable();
  return val;
  __builtin_unreachable();
}

// 2: LookupInBases
std::optional<bool> CXXRecordDecl::MayBeAbstract(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeAbstract();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::MayBeDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeDynamicClass();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::MayBeNonDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.mayBeNonDynamicClass();
  return val;
  __builtin_unreachable();
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::optional<std::vector<::pasta::CXXMethodDecl>> CXXRecordDecl::Methods(void) const noexcept {
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
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitDefaultConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsImplicitMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsImplicitMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForCopyAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForCopyConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForDestructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForMoveAssignment();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getDefinition()) {
    return std::nullopt;
  }
  decltype(auto) val = self.needsOverloadResolutionForMoveConstructor();
  return val;
  __builtin_unreachable();
}

std::optional<bool> CXXRecordDecl::NullFieldOffsetIsZero(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!self.getAttr<clang::MSInheritanceAttr>()) {
    return std::nullopt;
  }
  decltype(auto) val = self.nullFieldOffsetIsZero();
  return val;
  __builtin_unreachable();
}

std::optional<std::vector<::pasta::CXXBaseSpecifier>> CXXRecordDecl::VirtualBases(void) const noexcept {
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
  __builtin_unreachable();
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::TemplateParameterList> CXXRecordDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::Token ClassTemplateSpecializationDecl::ExternToken(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::InstantiatedFrom(void) const noexcept {
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
  __builtin_unreachable();
}

::pasta::Token ClassTemplateSpecializationDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

enum TemplateSpecializationKind ClassTemplateSpecializationDecl::SpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateSpecializationDecl::SpecializedTemplate(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const noexcept {
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
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> ClassTemplateSpecializationDecl::TemplateArguments(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateArgument> ClassTemplateSpecializationDecl::TemplateInstantiationArguments(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateInstantiationArgs();
  std::vector<::pasta::TemplateArgument> ret;
  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {
    const auto &arg = val[i];
    ret.emplace_back(ast, arg);
  }
  return ret;
  __builtin_unreachable();
}

::pasta::Token ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
  __builtin_unreachable();
}

std::optional<::pasta::Type> ClassTemplateSpecializationDecl::TypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  if (!self.getTypeAsWritten()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTypeAsWritten();
  if (!val) {
    return std::nullopt;
  }
  return TypeBuilder::Build(ast, val->getType());
  __builtin_unreachable();
}

bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
  __builtin_unreachable();
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
  __builtin_unreachable();
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> ClassTemplateSpecializationDecl::TemplateParameterLists(void) const noexcept {
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
::pasta::Type ClassTemplatePartialSpecializationDecl::InjectedSpecializationType(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInjectedSpecializationType();
  assert(!val.isNull());
  return TypeBuilder::Build(ast, val);
  __builtin_unreachable();
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassTemplatePartialSpecializationDecl::TemplateArgumentsAsWritten
::pasta::TemplateParameterList ClassTemplatePartialSpecializationDecl::TemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.getTemplateParameters();
  return ::pasta::TemplateParameterList(ast, val);
  assert(false && "ClassTemplatePartialSpecializationDecl::TemplateParameters can return nullptr!");
  __builtin_unreachable();
}

bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplatePartialSpecializationDecl *>(u.ClassTemplatePartialSpecializationDecl);
  decltype(auto) val = self.hasAssociatedConstraints();
  return val;
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> ClassTemplatePartialSpecializationDecl::TemplateParameterLists(void) const noexcept {
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
