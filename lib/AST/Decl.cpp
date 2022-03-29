/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#define PASTA_IN_DECL_CPP
#ifndef PASTA_IN_BOOTSTRAP
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
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

namespace {
// Return the PASTA `DeclKind` for a Clang `Decl`.
static DeclKind KindOfDecl(const clang::Decl *decl) {
  switch (decl->getKind()) {
#define ABSTRACT_DECL(DECL)
#define DECL(DERIVED, BASE) \
    case clang::Decl::DERIVED: \
      return DeclKind::k ## DERIVED;
#include <clang/AST/DeclNodes.inc>
  }
  __builtin_unreachable();
}

static const std::string_view kKindNames[] = {
  "AccessSpec",
  "BaseUsing",
  "Binding",
  "Block",
  "BuiltinTemplate",
  "CXXConstructor",
  "CXXConversion",
  "CXXDeductionGuide",
  "CXXDestructor",
  "CXXMethod",
  "CXXRecord",
  "Captured",
  "ClassScopeFunctionSpecialization",
  "ClassTemplate",
  "ClassTemplatePartialSpecialization",
  "ClassTemplateSpecialization",
  "Concept",
  "ConstructorUsingShadow",
  "Declarator",
  "Decomposition",
  "Empty",
  "EnumConstant",
  "Enum",
  "Export",
  "ExternCContext",
  "Field",
  "FileScopeAsm",
  "Friend",
  "FriendTemplate",
  "Function",
  "FunctionTemplate",
  "ImplicitParam",
  "Import",
  "IndirectField",
  "Label",
  "LifetimeExtendedTemporary",
  "LinkageSpec",
  "MSGuid",
  "MSProperty",
  "Named",
  "NamespaceAlias",
  "Namespace",
  "NonTypeTemplateParm",
  "OMPAllocate",
  "OMPCapturedExpr",
  "OMPDeclareMapper",
  "OMPDeclareReduction",
  "OMPRequires",
  "OMPThreadPrivate",
  "ObjCAtDefsField",
  "ObjCCategory",
  "ObjCCategoryImpl",
  "ObjCCompatibleAlias",
  "ObjCContainer",
  "ObjCImpl",
  "ObjCImplementation",
  "ObjCInterface",
  "ObjCIvar",
  "ObjCMethod",
  "ObjCProperty",
  "ObjCPropertyImpl",
  "ObjCProtocol",
  "ObjCTypeParam",
  "ParmVar",
  "PragmaComment",
  "PragmaDetectMismatch",
  "Record",
  "RedeclarableTemplate",
  "RequiresExprBody",
  "StaticAssert",
  "Tag",
  "Template",
  "TemplateParamObject",
  "TemplateTemplateParm",
  "TemplateTypeParm",
  "TranslationUnit",
  "TypeAlias",
  "TypeAliasTemplate",
  "Type",
  "Typedef",
  "TypedefName",
  "UnresolvedUsingIfExists",
  "UnresolvedUsingTypename",
  "UnresolvedUsingValue",
  "Using",
  "UsingDirective",
  "UsingEnum",
  "UsingPack",
  "UsingShadow",
  "Value",
  "Var",
  "VarTemplate",
  "VarTemplatePartialSpecialization",
  "VarTemplateSpecialization",
};
}  // namespace

std::string_view Decl::KindName(void) const noexcept {
  return kKindNames[static_cast<unsigned>(kind)];
}

::pasta::TokenRange Decl::TokenRange(void) const noexcept {
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
}

// 0: DeclContext::
// 0: DeclContext::
// 0: DeclContext::
::pasta::DeclKind DeclContext::DeclarationKind(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getDeclKind();
  return static_cast<::pasta::DeclKind>(val);
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
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::LinkageSpecDecl> DeclContext::ExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getExternCContext();
  if (val) {
    return DeclBuilder::Create<::pasta::LinkageSpecDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::BlockDecl> DeclContext::InnermostBlockDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getInnermostBlockDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::DeclContext> DeclContext::LexicalParent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLexicalParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::DeclContext> DeclContext::LookupParent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getLookupParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  return std::nullopt;
}

// 0: DeclContext::LookupPointer
std::optional<::pasta::Decl> DeclContext::NonClosureAncestor(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getNonClosureAncestor();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::RecordDecl> DeclContext::OuterLexicalRecordContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getOuterLexicalRecordContext();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::DeclContext> DeclContext::Parent(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.getParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  return std::nullopt;
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
}

bool DeclContext::HasExternalVisibleStorage(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.hasExternalVisibleStorage();
  return val;
}

bool DeclContext::IsClosure(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isClosure();
  return val;
}

// 1: DeclContext::IsDeclarationInLexicalTraversal
bool DeclContext::IsDependentContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isDependentContext();
  return val;
}

bool DeclContext::IsExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCContext();
  return val;
}

bool DeclContext::IsExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isExternCXXContext();
  return val;
}

bool DeclContext::IsFileContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFileContext();
  return val;
}

bool DeclContext::IsFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isFunctionOrMethod();
  return val;
}

bool DeclContext::IsInlineNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isInlineNamespace();
  return val;
}

bool DeclContext::IsLookupContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isLookupContext();
  return val;
}

bool DeclContext::IsNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isNamespace();
  return val;
}

bool DeclContext::IsObjCContainer(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isObjCContainer();
  return val;
}

bool DeclContext::IsRecord(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isRecord();
  return val;
}

bool DeclContext::IsStdNamespace(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isStdNamespace();
  return val;
}

bool DeclContext::IsTranslationUnit(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTranslationUnit();
  return val;
}

bool DeclContext::IsTransparentContext(void) const noexcept {
  auto &self = *const_cast<clang::DeclContext *>(u.DeclContext);
  decltype(auto) val = self.isTransparentContext();
  return val;
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
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TranslationUnitDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefNameDecl)
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
// 0: Decl::Attributes
// 1: Decl::CanBeWeakImported
// 0: Decl::ASTContext
enum AccessSpecifier Decl::Access(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAccess();
  return static_cast<::pasta::AccessSpecifier>(val);
}

enum AccessSpecifier Decl::AccessUnsafe(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAccessUnsafe();
  return static_cast<::pasta::AccessSpecifier>(val);
}

std::optional<::pasta::FunctionDecl> Decl::AsFunction(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAsFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  return std::nullopt;
}

// 0: Decl::Attributes
enum AvailabilityResult Decl::Availability(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getAvailability();
  return static_cast<::pasta::AvailabilityResult>(val);
}

::pasta::Token Decl::BeginToken(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token Decl::BodyRBrace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getBodyRBrace();
  return ast->TokenAt(val);
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

// 0: Decl::DefiningAttribute
std::optional<::pasta::TemplateDecl> Decl::DescribedTemplate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::TemplateParameterList> Decl::DescribedTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getDescribedTemplateParams();
  return ::pasta::TemplateParameterList(ast, val);
  return std::nullopt;
}

::pasta::Token Decl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: Decl::ExternalSourceSymbolAttribute
enum DeclFriendObjectKind Decl::FriendObjectKind(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFriendObjectKind();
  return static_cast<::pasta::DeclFriendObjectKind>(val);
}

::pasta::FunctionType Decl::FunctionType(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getFunctionType();
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionType>(ast, val);
  }
  assert(false && "Decl::FunctionType can return nullptr!");
  __builtin_unreachable();
}

uint32_t Decl::GlobalID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getGlobalID();
  return val;
}

int64_t Decl::ID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getID();
  return val;
}

uint32_t Decl::IdentifierNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getIdentifierNamespace();
  return val;
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
}

enum DeclModuleOwnershipKind Decl::ModuleOwnershipKind(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getModuleOwnershipKind();
  return static_cast<::pasta::DeclModuleOwnershipKind>(val);
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

::pasta::Decl Decl::NextDeclarationInContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNextDeclInContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NextDeclarationInContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::NonClosureContext(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getNonClosureContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NonClosureContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::OwningModule
// 0: Decl::OwningModuleForLinkage
uint32_t Decl::OwningModuleID(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getOwningModuleID();
  return val;
}

std::optional<::pasta::DeclContext> Decl::ParentFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getParentFunctionOrMethod();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  return std::nullopt;
}

::pasta::Decl Decl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::PreviousDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t Decl::TemplateDepth(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.getTemplateDepth();
  return val;
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
}

bool Decl::HasBody(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasBody();
  return val;
}

bool Decl::HasDefiningAttribute(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasDefiningAttr();
  return val;
}

bool Decl::HasOwningModule(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasOwningModule();
  return val;
}

bool Decl::HasTagIdentifierNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.hasTagIdentifierNamespace();
  return val;
}

bool Decl::IsCanonicalDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isCanonicalDecl();
  return val;
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDefinedOutsideFunctionOrMethod();
  return val;
}

bool Decl::IsDeprecated(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isDeprecated();
  return val;
}

bool Decl::IsFirstDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFirstDecl();
  return val;
}

bool Decl::IsFromASTFile(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFromASTFile();
  return val;
}

bool Decl::IsFunctionOrFunctionTemplate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isFunctionOrFunctionTemplate();
  return val;
}

bool Decl::IsImplicit(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isImplicit();
  return val;
}

bool Decl::IsInAnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInAnonymousNamespace();
  return val;
}

// 1: Decl::IsInIdentifierNamespace
bool Decl::IsInLocalScopeForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInLocalScopeForInstantiation();
  return val;
}

bool Decl::IsInStdNamespace(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInStdNamespace();
  return val;
}

bool Decl::IsInvalidDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isInvalidDecl();
  return val;
}

bool Decl::IsModulePrivate(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isModulePrivate();
  return val;
}

bool Decl::IsOutOfLine(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isOutOfLine();
  return val;
}

bool Decl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool Decl::IsReferenced(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isReferenced();
  return val;
}

bool Decl::IsTemplateDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateDecl();
  return val;
}

bool Decl::IsTemplateParameter(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameter();
  return val;
}

bool Decl::IsTemplateParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplateParameterPack();
  return val;
}

bool Decl::IsTemplated(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTemplated();
  return val;
}

bool Decl::IsThisDeclarationReferenced(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isThisDeclarationReferenced();
  return val;
}

bool Decl::IsTopLevelDeclarationInObjCContainer(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isTopLevelDeclInObjCContainer();
  return val;
}

bool Decl::IsUnavailable(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnavailable();
  return val;
}

bool Decl::IsUnconditionallyVisible(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUnconditionallyVisible();
  return val;
}

bool Decl::IsUsed(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isUsed();
  return val;
}

bool Decl::IsWeakImported(void) const noexcept {
  auto &self = *const_cast<clang::Decl *>(u.Decl);
  decltype(auto) val = self.isWeakImported();
  return val;
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
}

::pasta::Token ExportDecl::ExportToken(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getExportLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ExportDecl *>(u.ExportDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool ExportDecl::HasBraces(void) const noexcept {
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
::pasta::Token FileScopeAsmDecl::AssemblyToken(void) const noexcept {
  auto &self = *const_cast<clang::FileScopeAsmDecl *>(u.FileScopeAsmDecl);
  decltype(auto) val = self.getAsmLoc();
  return ast->TokenAt(val);
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
}

FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendDecl)
::pasta::NamedDecl FriendDecl::FriendDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendDecl::FriendDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendDecl::FriendToken(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendLoc();
  return ast->TokenAt(val);
}

::pasta::Type FriendDecl::FriendType(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendType();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "FriendDecl::FriendType can return nullptr!");
  __builtin_unreachable();
}

uint32_t FriendDecl::FriendTypeNumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.getFriendTypeNumTemplateParameterLists();
  return val;
}

// 1: FriendDecl::FriendTypeTemplateParameterList
bool FriendDecl::IsUnsupportedFriend(void) const noexcept {
  auto &self = *const_cast<clang::FriendDecl *>(u.FriendDecl);
  decltype(auto) val = self.isUnsupportedFriend();
  return val;
}

std::vector<::pasta::TemplateParameterList> FriendDecl::FriendTypeTemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

::pasta::Type FriendTemplateDecl::FriendType(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getFriendType();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "FriendTemplateDecl::FriendType can return nullptr!");
  __builtin_unreachable();
}

uint32_t FriendTemplateDecl::NumTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::FriendTemplateDecl *>(u.FriendTemplateDecl);
  decltype(auto) val = self.getNumTemplateParameters();
  return val;
}

// 1: FriendTemplateDecl::TemplateParameterList
std::vector<::pasta::TemplateParameterList> FriendTemplateDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.FriendTemplateDecl->getNumTemplateParameters();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FriendTemplateDecl->getTemplateParameterList(i)));
  }
  return ret;
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
}

// 0: ImportDecl::ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
std::vector<::pasta::Stmt> LifetimeExtendedTemporaryDecl::ChildrenExpression(void) const noexcept {
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
}

// 1: LifetimeExtendedTemporaryDecl::OrCreateValue
enum StorageDuration LifetimeExtendedTemporaryDecl::StorageDuration(void) const noexcept {
  auto &self = *const_cast<clang::LifetimeExtendedTemporaryDecl *>(u.LifetimeExtendedTemporaryDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
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
}

::pasta::Token LinkageSpecDecl::ExternToken(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getExternLoc();
  return ast->TokenAt(val);
}

enum LinkageSpecDeclLanguageIDs LinkageSpecDecl::Language(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getLanguage();
  return static_cast<::pasta::LinkageSpecDeclLanguageIDs>(val);
}

::pasta::Token LinkageSpecDecl::RBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::LinkageSpecDecl *>(u.LinkageSpecDecl);
  decltype(auto) val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

bool LinkageSpecDecl::HasBraces(void) const noexcept {
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
}

// 0: NamedDecl::Identifier
// 0: NamedDecl::LinkageAndVisibility
enum Linkage NamedDecl::LinkageInternal(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getLinkageInternal();
  return static_cast<::pasta::Linkage>(val);
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
}

enum ObjCStringFormatFamily NamedDecl::ObjCFStringFormattingFamily(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getObjCFStringFormattingFamily();
  return static_cast<::pasta::ObjCStringFormatFamily>(val);
}

std::string NamedDecl::QualifiedNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.getQualifiedNameAsString();
  return val;
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
}

bool NamedDecl::HasExternalFormalLinkage(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasExternalFormalLinkage();
  return val;
}

bool NamedDecl::HasLinkage(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkage();
  return val;
}

bool NamedDecl::HasLinkageBeenComputed(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.hasLinkageBeenComputed();
  return val;
}

bool NamedDecl::IsCXXClassMember(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXClassMember();
  return val;
}

bool NamedDecl::IsCXXInstanceMember(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isCXXInstanceMember();
  return val;
}

bool NamedDecl::IsExternallyDeclarable(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyDeclarable();
  return val;
}

bool NamedDecl::IsExternallyVisible(void) const noexcept {
  auto &self = *const_cast<clang::NamedDecl *>(u.NamedDecl);
  decltype(auto) val = self.isExternallyVisible();
  return val;
}

bool NamedDecl::IsLinkageValid(void) const noexcept {
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
::pasta::Token NamespaceAliasDecl::AliasToken(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceAliasDecl *>(u.NamespaceAliasDecl);
  decltype(auto) val = self.getAliasLoc();
  return ast->TokenAt(val);
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
}

// 0: NamespaceAliasDecl::Qualifier
// 0: NamespaceAliasDecl::QualifierToken
::pasta::Token NamespaceAliasDecl::TargetNameToken(void) const noexcept {
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
}

bool NamespaceDecl::IsAnonymousNamespace(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isAnonymousNamespace();
  return val;
}

bool NamespaceDecl::IsInline(void) const noexcept {
  auto &self = *const_cast<clang::NamespaceDecl *>(u.NamespaceDecl);
  decltype(auto) val = self.isInline();
  return val;
}

bool NamespaceDecl::IsOriginalNamespace(void) const noexcept {
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
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
::pasta::TokenRange ObjCContainerDecl::AtEndRange(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtEndRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token ObjCContainerDecl::AtStartToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCContainerDecl *>(u.ObjCContainerDecl);
  decltype(auto) val = self.getAtStartLoc();
  return ast->TokenAt(val);
}

// 1: ObjCContainerDecl::ClassMethod
// 1: ObjCContainerDecl::InstanceMethod
// 1: ObjCContainerDecl::InstanceVariableDeclaration
// 2: Method
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
}

::pasta::Token ObjCImplementationDecl::InstanceVariableRBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
}

std::string ObjCImplementationDecl::Name(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNameAsString();
  return val;
}

uint32_t ObjCImplementationDecl::NumInstanceVariableInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getNumIvarInitializers();
  return val;
}

std::string_view ObjCImplementationDecl::ObjCRuntimeNameAsString(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
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
}

bool ObjCImplementationDecl::HasDestructors(void) const noexcept {
  auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
  decltype(auto) val = self.hasDestructors();
  return val;
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const noexcept {
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
}

bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.declaresOrInheritsDesignatedInitializers();
  return val;
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
}

// 0: ObjCInterfaceDecl::ReferencedProtocols
::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::SuperClass(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::SuperClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::SuperClassToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassLoc();
  return ast->TokenAt(val);
}

::pasta::Type ObjCInterfaceDecl::SuperClassTInfo(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassTInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "ObjCInterfaceDecl::SuperClassTInfo can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCObjectType ObjCInterfaceDecl::SuperClassType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.getSuperClassType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::SuperClassType can return nullptr!");
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
}

bool ObjCInterfaceDecl::HasDesignatedInitializers(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.hasDesignatedInitializers();
  return val;
}

bool ObjCInterfaceDecl::IsArcWeakrefUnavailable(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isArcWeakrefUnavailable();
  return val;
}

// 1: ObjCInterfaceDecl::IsDesignatedInitializer
bool ObjCInterfaceDecl::IsImplicitInterfaceDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCInterfaceDecl *>(u.ObjCInterfaceDecl);
  decltype(auto) val = self.isImplicitInterfaceDecl();
  return val;
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

::pasta::ImplicitParamDecl ObjCMethodDecl::CmdDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getCmdDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CmdDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::DeclaratorEndToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getDeclaratorEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCMethodDecl::EndToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getEndLoc();
  return ast->TokenAt(val);
}

enum ObjCMethodDeclImplementationControl ObjCMethodDecl::ImplementationControl(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getImplementationControl();
  return static_cast<::pasta::ObjCMethodDeclImplementationControl>(val);
}

enum ObjCMethodFamily ObjCMethodDecl::MethodFamily(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(val);
}

uint32_t ObjCMethodDecl::NumSelectorTokens(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getNumSelectorLocs();
  return val;
}

enum DeclObjCDeclQualifier ObjCMethodDecl::ObjCDeclQualifier(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
}

// 1: ObjCMethodDecl::ParameterDeclaration
::pasta::Type ObjCMethodDecl::ReturnType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCMethodDecl::ReturnTypeSourceInfo(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "ObjCMethodDecl::ReturnTypeSourceInfo can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange ObjCMethodDecl::ReturnTypeSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCMethodDecl::Selector
// 1: ObjCMethodDecl::SelectorToken
::pasta::Token ObjCMethodDecl::SelectorStartToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
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
bool ObjCMethodDecl::HasRedeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRedeclaration();
  return val;
}

bool ObjCMethodDecl::HasRelatedResultType(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasRelatedResultType();
  return val;
}

bool ObjCMethodDecl::HasSkippedBody(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
}

bool ObjCMethodDecl::IsClassMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isClassMethod();
  return val;
}

bool ObjCMethodDecl::IsDefined(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDefined();
  return val;
}

bool ObjCMethodDecl::IsDesignatedInitializerForTheInterface(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDesignatedInitializerForTheInterface();
  return val;
}

bool ObjCMethodDecl::IsDirectMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isDirectMethod();
  return val;
}

bool ObjCMethodDecl::IsInstanceMethod(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isInstanceMethod();
  return val;
}

bool ObjCMethodDecl::IsOptional(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOptional();
  return val;
}

bool ObjCMethodDecl::IsOverriding(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isOverriding();
  return val;
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isPropertyAccessor();
  return val;
}

bool ObjCMethodDecl::IsRedeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isRedeclaration();
  return val;
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isSynthesizedAccessorStub();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADesignatedInitializer(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isThisDeclarationADesignatedInitializer();
  return val;
}

bool ObjCMethodDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::ObjCMethodDecl *>(u.ObjCMethodDecl);
  decltype(auto) val = self.isVariadic();
  return val;
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
}

// 0: ObjCMethodDecl::
std::vector<::pasta::Token> ObjCMethodDecl::SelectorTokens(void) const noexcept {
  auto convert_elem = [&] (clang::SourceLocation val) {
    return ast->TokenAt(val);
  };
  std::vector<::pasta::Token> ret;
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
}

::pasta::Token ObjCPropertyDecl::LParenToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyDecl::PropertyAttributes
// 0: ObjCPropertyDecl::PropertyAttributesAsWritten
enum ObjCPropertyDeclPropertyControl ObjCPropertyDecl::PropertyImplementation(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getPropertyImplementation();
  return static_cast<::pasta::ObjCPropertyDeclPropertyControl>(val);
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
}

enum ObjCPropertyDeclSetterKind ObjCPropertyDecl::SetterKind(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getSetterKind();
  return static_cast<::pasta::ObjCPropertyDeclSetterKind>(val);
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
}

::pasta::Type ObjCPropertyDecl::Type(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type ObjCPropertyDecl::TypeSourceInfo(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.getTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "ObjCPropertyDecl::TypeSourceInfo can return nullptr!");
  __builtin_unreachable();
}

// 1: ObjCPropertyDecl::UsageType
bool ObjCPropertyDecl::IsAtomic(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isAtomic();
  return val;
}

bool ObjCPropertyDecl::IsClassProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isClassProperty();
  return val;
}

bool ObjCPropertyDecl::IsDirectProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isDirectProperty();
  return val;
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isInstanceProperty();
  return val;
}

bool ObjCPropertyDecl::IsOptional(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isOptional();
  return val;
}

bool ObjCPropertyDecl::IsReadOnly(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isReadOnly();
  return val;
}

bool ObjCPropertyDecl::IsRetaining(void) const noexcept {
  auto &self = *const_cast<clang::ObjCPropertyDecl *>(u.ObjCPropertyDecl);
  decltype(auto) val = self.isRetaining();
  return val;
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
}

// 0: ObjCProtocolDecl::ReferencedProtocols
bool ObjCProtocolDecl::HasDefinition(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
}

bool ObjCProtocolDecl::IsNonRuntimeProtocol(void) const noexcept {
  auto &self = *const_cast<clang::ObjCProtocolDecl *>(u.ObjCProtocolDecl);
  decltype(auto) val = self.isNonRuntimeProtocol();
  return val;
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const noexcept {
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
}

enum PragmaMSCommentKind PragmaCommentDecl::CommentKind(void) const noexcept {
  auto &self = *const_cast<clang::PragmaCommentDecl *>(u.PragmaCommentDecl);
  decltype(auto) val = self.getCommentKind();
  return static_cast<::pasta::PragmaMSCommentKind>(val);
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
}

std::string_view PragmaDetectMismatchDecl::Value(void) const noexcept {
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
}

bool StaticAssertDecl::IsFailed(void) const noexcept {
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
}

// 0: TemplateTemplateParmDecl::DefaultArgumentStorage
// 0: TemplateTemplateParmDecl::DefaultArgument
::pasta::Token TemplateTemplateParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: TemplateTemplateParmDecl::ExpansionTemplateParameters
uint32_t TemplateTemplateParmDecl::NumExpansionTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.getNumExpansionTemplateParameters();
  return val;
}

bool TemplateTemplateParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTemplateParmDecl *>(u.TemplateTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
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
}

::pasta::Type TypeDecl::TypeForDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeDecl *>(u.TypeDecl);
  decltype(auto) val = self.getTypeForDecl();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "TypeDecl::TypeForDeclaration can return nullptr!");
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
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  return std::nullopt;
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

::pasta::Type TypedefNameDecl::TypeSourceInfo(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "TypedefNameDecl::TypeSourceInfo can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type TypedefNameDecl::UnderlyingType(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool TypedefNameDecl::IsModed(void) const noexcept {
  auto &self = *const_cast<clang::TypedefNameDecl *>(u.TypedefNameDecl);
  decltype(auto) val = self.isModed();
  return val;
}

bool TypedefNameDecl::IsTransparentTag(void) const noexcept {
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
}

// 0: UnresolvedUsingTypenameDecl::NameInfo
// 0: UnresolvedUsingTypenameDecl::Qualifier
// 0: UnresolvedUsingTypenameDecl::QualifierToken
::pasta::Token UnresolvedUsingTypenameDecl::TypenameToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getTypenameLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedUsingTypenameDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingTypenameDecl *>(u.UnresolvedUsingTypenameDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const noexcept {
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
}

::pasta::Token UsingDirectiveDecl::NamespaceKeyToken(void) const noexcept {
  auto &self = *const_cast<clang::UsingDirectiveDecl *>(u.UsingDirectiveDecl);
  decltype(auto) val = self.getNamespaceKeyLocation();
  return ast->TokenAt(val);
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

::pasta::UsingShadowDecl UsingShadowDecl::NextUsingShadowDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UsingShadowDecl *>(u.UsingShadowDecl);
  decltype(auto) val = self.getNextUsingShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::NextUsingShadowDeclaration can return nullptr!");
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
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
::pasta::Type ValueDecl::Type(void) const noexcept {
  auto &self = *const_cast<clang::ValueDecl *>(u.ValueDecl);
  decltype(auto) val = self.getType();
  return TypeBuilder::Build(ast, val);
}

bool ValueDecl::IsWeak(void) const noexcept {
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
::pasta::Token AccessSpecDecl::AccessSpecifierToken(void) const noexcept {
  auto &self = *const_cast<clang::AccessSpecDecl *>(u.AccessSpecDecl);
  decltype(auto) val = self.getAccessSpecifierLoc();
  return ast->TokenAt(val);
}

::pasta::Token AccessSpecDecl::ColonToken(void) const noexcept {
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
}

bool BlockDecl::CanAvoidCopyToHeap(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.canAvoidCopyToHeap();
  return val;
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::Captures
bool BlockDecl::CapturesCXXThis(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.capturesCXXThis();
  return val;
}

// 1: BlockDecl::CapturesVariable
bool BlockDecl::DoesNotEscape(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.doesNotEscape();
  return val;
}

::pasta::Decl BlockDecl::BlockManglingContextDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingContextDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "BlockDecl::BlockManglingContextDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t BlockDecl::BlockManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getBlockManglingNumber();
  return val;
}

::pasta::Token BlockDecl::CaretToken(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getCaretLocation();
  return ast->TokenAt(val);
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
}

uint32_t BlockDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

// 1: BlockDecl::ParameterDeclaration
::pasta::Type BlockDecl::SignatureAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.getSignatureAsWritten();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "BlockDecl::SignatureAsWritten can return nullptr!");
  __builtin_unreachable();
}

bool BlockDecl::HasCaptures(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.hasCaptures();
  return val;
}

bool BlockDecl::IsConversionFromLambda(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isConversionFromLambda();
  return val;
}

bool BlockDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::BlockDecl *>(u.BlockDecl);
  decltype(auto) val = self.isVariadic();
  return val;
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
}

std::vector<::pasta::ParmVarDecl> BlockDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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
}

uint32_t CapturedDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

// 1: CapturedDecl::Parameter
bool CapturedDecl::IsNothrow(void) const noexcept {
  auto &self = *const_cast<clang::CapturedDecl *>(u.CapturedDecl);
  decltype(auto) val = self.isNothrow();
  return val;
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
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  return std::nullopt;
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
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  return std::nullopt;
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
}

::pasta::Token DeclaratorDecl::InnerTokenStart(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

uint32_t DeclaratorDecl::NumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token DeclaratorDecl::OuterTokenStart(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: DeclaratorDecl::Qualifier
// 0: DeclaratorDecl::QualifierToken
// 1: DeclaratorDecl::TemplateParameterList
::pasta::Expr DeclaratorDecl::TrailingRequiresClause(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTrailingRequiresClause();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DeclaratorDecl::TrailingRequiresClause can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type DeclaratorDecl::TypeSourceInfo(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "DeclaratorDecl::TypeSourceInfo can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token DeclaratorDecl::TypeSpecEndToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::TypeSpecStartToken(void) const noexcept {
  auto &self = *const_cast<clang::DeclaratorDecl *>(u.DeclaratorDecl);
  decltype(auto) val = self.getTypeSpecStartLoc();
  return ast->TokenAt(val);
}

std::vector<::pasta::TemplateParameterList> DeclaratorDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
}

llvm::APSInt EnumConstantDecl::InitializerVal(void) const noexcept {
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
std::optional<::pasta::Expr> FieldDecl::BitWidth(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  if (!self.isBitField()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getBitWidth();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
}

uint32_t FieldDecl::BitWidthValue(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.getBitWidthValue(ast->ci->getASTContext());
  return val;
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

::pasta::VariableArrayType FieldDecl::CapturedVLAType(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getCapturedVLAType();
  if (val) {
    return TypeBuilder::Create<::pasta::VariableArrayType>(ast, val);
  }
  assert(false && "FieldDecl::CapturedVLAType can return nullptr!");
  __builtin_unreachable();
}

uint32_t FieldDecl::FieldIndex(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getFieldIndex();
  return val;
}

enum InClassInitStyle FieldDecl::InClassInitializerStyle(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitStyle();
  return static_cast<::pasta::InClassInitStyle>(val);
}

std::optional<::pasta::Expr> FieldDecl::InClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.getInClassInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
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
}

bool FieldDecl::HasInClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.hasInClassInitializer();
  return val;
}

bool FieldDecl::IsAnonymousStructOrUnion(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
}

bool FieldDecl::IsBitField(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isBitField();
  return val;
}

bool FieldDecl::IsMutable(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isMutable();
  return val;
}

bool FieldDecl::IsUnnamedBitfield(void) const noexcept {
  auto &self = *const_cast<clang::FieldDecl *>(u.FieldDecl);
  decltype(auto) val = self.isUnnamedBitfield();
  return val;
}

bool FieldDecl::IsZeroLengthBitField(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroLengthBitField(ast->ci->getASTContext());
  return val;
}

bool FieldDecl::IsZeroSize(void) const noexcept {
  auto &self = *(u.FieldDecl);
  decltype(auto) val = self.isZeroSize(ast->ci->getASTContext());
  return val;
}

std::vector<::pasta::TemplateParameterList> FieldDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
std::optional<bool> FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (!self.doesThisDeclarationHaveABody()) {
    return std::nullopt;
  } else {
    return self.doesDeclarationForceExternallyVisibleDefinition();
  }
  decltype(auto) val = self.doesDeclarationForceExternallyVisibleDefinition();
  return val;
}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.doesThisDeclarationHaveABody();
  return val;
}

uint32_t FunctionDecl::BuiltinID(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getBuiltinID();
  return val;
}

::pasta::Type FunctionDecl::CallResultType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getCallResultType();
  return TypeBuilder::Build(ast, val);
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
}

::pasta::Type FunctionDecl::DeclaredReturnType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDeclaredReturnType();
  return TypeBuilder::Build(ast, val);
}

// 0: FunctionDecl::DefaultedFunctionInfo
std::optional<::pasta::FunctionDecl> FunctionDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  return std::nullopt;
}

// 0: FunctionDecl::DependentSpecializationInfo
std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::DescribedFunctionTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getDescribedFunctionTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  return std::nullopt;
}

::pasta::Token FunctionDecl::EllipsisToken(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange FunctionDecl::ExceptionSpecSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecSourceRange();
  return ast->TokenRangeFrom(val);
}

enum ExceptionSpecificationType FunctionDecl::ExceptionSpecType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(val);
}

// 0: FunctionDecl::FunctionTypeToken
std::optional<::pasta::FunctionDecl> FunctionDecl::InstantiatedFromMemberFunction(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getInstantiatedFromMemberFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  return std::nullopt;
}

enum LanguageLinkage FunctionDecl::LanguageLinkage(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
}

// 0: FunctionDecl::LiteralIdentifier
// 0: FunctionDecl::MemberSpecializationInfo
uint32_t FunctionDecl::MemoryFunctionKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMemoryFunctionKind();
  return val;
}

uint32_t FunctionDecl::MinRequiredArguments(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMinRequiredArguments();
  return val;
}

enum MultiVersionKind FunctionDecl::MultiVersionKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getMultiVersionKind();
  return static_cast<::pasta::MultiVersionKind>(val);
}

// 0: FunctionDecl::NameInfo
uint32_t FunctionDecl::NumParameters(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getNumParams();
  return val;
}

uint32_t FunctionDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getODRHash();
  return val;
}

enum OverloadedOperatorKind FunctionDecl::OverloadedOperator(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getOverloadedOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(val);
}

// 1: FunctionDecl::ParameterDeclaration
::pasta::TokenRange FunctionDecl::ParametersSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getParametersSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token FunctionDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

std::optional<::pasta::FunctionTemplateDecl> FunctionDecl::PrimaryTemplate(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getPrimaryTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  return std::nullopt;
}

::pasta::Type FunctionDecl::ReturnType(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange FunctionDecl::ReturnTypeSourceRange(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

enum StorageClass FunctionDecl::StorageClass(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
}

std::optional<::pasta::FunctionDecl> FunctionDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  return std::nullopt;
}

// 0: FunctionDecl::TemplateSpecializationArguments
// 0: FunctionDecl::TemplateSpecializationArgumentsAsWritten
// 0: FunctionDecl::TemplateSpecializationInfo
enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKindForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum FunctionDeclTemplatedKind FunctionDecl::TemplatedKind(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.getTemplatedKind();
  return static_cast<::pasta::FunctionDeclTemplatedKind>(val);
}

bool FunctionDecl::HasImplicitReturnZero(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasImplicitReturnZero();
  return val;
}

bool FunctionDecl::HasInheritedPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasInheritedPrototype();
  return val;
}

bool FunctionDecl::HasOneParameterOrDefaultArguments(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasOneParamOrDefaultArgs();
  return val;
}

bool FunctionDecl::HasPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasPrototype();
  return val;
}

bool FunctionDecl::HasSkippedBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasSkippedBody();
  return val;
}

bool FunctionDecl::HasTrivialBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasTrivialBody();
  return val;
}

bool FunctionDecl::HasWrittenPrototype(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.hasWrittenPrototype();
  return val;
}

bool FunctionDecl::InstantiationIsPending(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.instantiationIsPending();
  return val;
}

bool FunctionDecl::IsCPUDispatchMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUDispatchMultiVersion();
  return val;
}

bool FunctionDecl::IsCPUSpecificMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isCPUSpecificMultiVersion();
  return val;
}

bool FunctionDecl::IsConsteval(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConsteval();
  return val;
}

bool FunctionDecl::IsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
}

bool FunctionDecl::IsConstexprSpecified(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isConstexprSpecified();
  return val;
}

bool FunctionDecl::IsDefaulted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDefaulted();
  return val;
}

bool FunctionDecl::IsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeleted();
  return val;
}

bool FunctionDecl::IsDeletedAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDeletedAsWritten();
  return val;
}

bool FunctionDecl::IsDestroyingOperatorDelete(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isDestroyingOperatorDelete();
  return val;
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExplicitlyDefaulted();
  return val;
}

bool FunctionDecl::IsExternC(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isExternC();
  return val;
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isFunctionTemplateSpecialization();
  return val;
}

bool FunctionDecl::IsGlobal(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isGlobal();
  return val;
}

bool FunctionDecl::IsImplicitlyInstantiable(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isImplicitlyInstantiable();
  return val;
}

bool FunctionDecl::IsInExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
}

bool FunctionDecl::IsInExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
}

bool FunctionDecl::IsInlineBuiltinDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineBuiltinDeclaration();
  return val;
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
}

bool FunctionDecl::IsInlineSpecified(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
}

bool FunctionDecl::IsInlined(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isInlined();
  return val;
}

bool FunctionDecl::IsLateTemplateParsed(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isLateTemplateParsed();
  return val;
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
}

bool FunctionDecl::IsMSVCRTEntryPoint(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMSVCRTEntryPoint();
  return val;
}

bool FunctionDecl::IsMain(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMain();
  return val;
}

bool FunctionDecl::IsMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isMultiVersion();
  return val;
}

bool FunctionDecl::IsNoReturn(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isNoReturn();
  return val;
}

bool FunctionDecl::IsOverloadedOperator(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isOverloadedOperator();
  return val;
}

bool FunctionDecl::IsPure(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isPure();
  return val;
}

bool FunctionDecl::IsReplaceableGlobalAllocationFunction(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isReplaceableGlobalAllocationFunction();
  return val;
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
}

bool FunctionDecl::IsStatic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isStatic();
  return val;
}

bool FunctionDecl::IsTargetMultiVersion(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTargetMultiVersion();
  return val;
}

bool FunctionDecl::IsTemplateInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTemplateInstantiation();
  return val;
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isThisDeclarationInstantiatedFromAFriendDefinition();
  return val;
}

bool FunctionDecl::IsTrivial(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivial();
  return val;
}

bool FunctionDecl::IsTrivialForCall(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isTrivialForCall();
  return val;
}

bool FunctionDecl::IsUserProvided(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isUserProvided();
  return val;
}

bool FunctionDecl::IsVariadic(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVariadic();
  return val;
}

bool FunctionDecl::IsVirtualAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.isVirtualAsWritten();
  return val;
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
}

bool FunctionDecl::UsesSEHTry(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.usesSEHTry();
  return val;
}

bool FunctionDecl::WillHaveBody(void) const noexcept {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  decltype(auto) val = self.willHaveBody();
  return val;
}

std::vector<::pasta::TemplateParameterList> FunctionDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.FunctionDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.FunctionDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> FunctionDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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
}

// 0: IndirectFieldDecl::
// 0: IndirectFieldDecl::
std::optional<::pasta::FieldDecl> IndirectFieldDecl::AnonymousField(void) const noexcept {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  if (self.chain().size() < 2) {
    return std::nullopt;
  }
  decltype(auto) val = self.getAnonField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  return std::nullopt;
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
}

std::optional<::pasta::VarDecl> IndirectFieldDecl::VariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::IndirectFieldDecl *>(u.IndirectFieldDecl);
  if (self.chain().size() < 2) {
    return std::nullopt;
  }
  decltype(auto) val = self.getVarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  return std::nullopt;
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
}

bool LabelDecl::IsMSAssemblyLabel(void) const noexcept {
  auto &self = *const_cast<clang::LabelDecl *>(u.LabelDecl);
  decltype(auto) val = self.isMSAsmLabel();
  return val;
}

bool LabelDecl::IsResolvedMSAssemblyLabel(void) const noexcept {
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
bool MSPropertyDecl::HasGetter(void) const noexcept {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasGetter();
  return val;
}

bool MSPropertyDecl::HasSetter(void) const noexcept {
  auto &self = *const_cast<clang::MSPropertyDecl *>(u.MSPropertyDecl);
  decltype(auto) val = self.hasSetter();
  return val;
}

std::vector<::pasta::TemplateParameterList> MSPropertyDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

// 0: NonTypeTemplateParmDecl::DefaultArgumentStorage
::pasta::Expr NonTypeTemplateParmDecl::DefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "NonTypeTemplateParmDecl::DefaultArgument can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NonTypeTemplateParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: NonTypeTemplateParmDecl::ExpansionType
// 1: NonTypeTemplateParmDecl::ExpansionTypeSourceInfo
uint32_t NonTypeTemplateParmDecl::NumExpansionTypes(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getNumExpansionTypes();
  return val;
}

::pasta::Expr NonTypeTemplateParmDecl::PlaceholderTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.getPlaceholderTypeConstraint();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "NonTypeTemplateParmDecl::PlaceholderTypeConstraint can return nullptr!");
  __builtin_unreachable();
}

bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.hasPlaceholderTypeConstraint();
  return val;
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::NonTypeTemplateParmDecl *>(u.NonTypeTemplateParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

std::vector<::pasta::TemplateParameterList> NonTypeTemplateParmDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.NonTypeTemplateParmDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.NonTypeTemplateParmDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::Type> NonTypeTemplateParmDecl::ExpansionTypes(void) const noexcept {
  auto convert_elem = [&] (clang::QualType val) {
    return TypeBuilder::Build(ast, val);
  };
  std::vector<::pasta::Type> ret;
  auto count = u.NonTypeTemplateParmDecl->getNumExpansionTypes();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.NonTypeTemplateParmDecl->getExpansionType(i)));
  }
  return ret;
}

std::vector<::pasta::Type> NonTypeTemplateParmDecl::ExpansionTypeSourceInfos(void) const noexcept {
  auto convert_elem = [&] (clang::TypeSourceInfo * val) {
    return TypeBuilder::Build(ast, val->getType());
  };
  std::vector<::pasta::Type> ret;
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
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

::pasta::Token ObjCCategoryDecl::CategoryNameToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
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
}

::pasta::Token ObjCCategoryDecl::InstanceVariableRBraceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCCategoryDecl *>(u.ObjCCategoryDecl);
  decltype(auto) val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
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
}

enum ObjCIvarDeclAccessControl ObjCIvarDecl::CanonicalAccessControl(void) const noexcept {
  auto &self = *const_cast<clang::ObjCIvarDecl *>(u.ObjCIvarDecl);
  decltype(auto) val = self.getCanonicalAccessControl();
  return static_cast<::pasta::ObjCIvarDeclAccessControl>(val);
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
}

// 1: ObjCIvarDecl::UsageType
std::vector<::pasta::TemplateParameterList> ObjCIvarDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

uint32_t ObjCTypeParamDecl::Index(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getIndex();
  return val;
}

enum ObjCTypeParamVariance ObjCTypeParamDecl::Variance(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVariance();
  return static_cast<::pasta::ObjCTypeParamVariance>(val);
}

::pasta::Token ObjCTypeParamDecl::VarianceToken(void) const noexcept {
  auto &self = *const_cast<clang::ObjCTypeParamDecl *>(u.ObjCTypeParamDecl);
  decltype(auto) val = self.getVarianceLoc();
  return ast->TokenAt(val);
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const noexcept {
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
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  return std::nullopt;
}

::pasta::Token TagDecl::InnerTokenStart(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

std::string_view TagDecl::KindName(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t TagDecl::NumTemplateParameterLists(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token TagDecl::OuterTokenStart(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: TagDecl::Qualifier
// 0: TagDecl::QualifierToken
enum TagTypeKind TagDecl::TagKind(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTagKind();
  return static_cast<::pasta::TagTypeKind>(val);
}

// 1: TagDecl::TemplateParameterList
std::optional<::pasta::TypedefNameDecl> TagDecl::TypedefNameForAnonymousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.getTypedefNameForAnonDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  return std::nullopt;
}

bool TagDecl::HasNameForLinkage(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.hasNameForLinkage();
  return val;
}

bool TagDecl::IsBeingDefined(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isBeingDefined();
  return val;
}

bool TagDecl::IsClass(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isClass();
  return val;
}

bool TagDecl::IsCompleteDefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinition();
  return val;
}

bool TagDecl::IsCompleteDefinitionRequired(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isCompleteDefinitionRequired();
  return val;
}

bool TagDecl::IsDependentType(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isDependentType();
  return val;
}

bool TagDecl::IsEmbeddedInDeclarator(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEmbeddedInDeclarator();
  return val;
}

bool TagDecl::IsEnum(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isEnum();
  return val;
}

bool TagDecl::IsFreeStanding(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isFreeStanding();
  return val;
}

bool TagDecl::IsInterface(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isInterface();
  return val;
}

bool TagDecl::IsStruct(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isStruct();
  return val;
}

bool TagDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
}

bool TagDecl::IsUnion(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.isUnion();
  return val;
}

bool TagDecl::MayHaveOutOfDateDefinition(void) const noexcept {
  auto &self = *const_cast<clang::TagDecl *>(u.TagDecl);
  decltype(auto) val = self.mayHaveOutOfDateDef();
  return val;
}

std::vector<::pasta::TemplateParameterList> TagDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

// 0: TemplateTypeParmDecl::DefaultArgumentStorage
::pasta::Type TemplateTypeParmDecl::DefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgument();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type TemplateTypeParmDecl::DefaultArgumentInfo(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "TemplateTypeParmDecl::DefaultArgumentInfo can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token TemplateTypeParmDecl::DefaultArgumentToken(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

uint32_t TemplateTypeParmDecl::Depth(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getDepth();
  return val;
}

uint32_t TemplateTypeParmDecl::Index(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getIndex();
  return val;
}

uint32_t TemplateTypeParmDecl::NumExpansionParameters(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.getNumExpansionParameters();
  return val;
}

// 0: TemplateTypeParmDecl::TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasDefaultArgument();
  return val;
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.hasTypeConstraint();
  return val;
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isPackExpansion();
  return val;
}

bool TemplateTypeParmDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::TemplateTypeParmDecl *>(u.TemplateTypeParmDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const noexcept {
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
std::optional<::pasta::TypeAliasTemplateDecl> TypeAliasDecl::DescribedAliasTemplate(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasDecl *>(u.TypeAliasDecl);
  decltype(auto) val = self.getDescribedAliasTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  return std::nullopt;
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

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::InstantiatedFromMemberTemplate(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::TypeAliasTemplateDecl *>(u.TypeAliasTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::PreviousDeclaration can return nullptr!");
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
}

// 0: UnresolvedUsingValueDecl::NameInfo
// 0: UnresolvedUsingValueDecl::Qualifier
// 0: UnresolvedUsingValueDecl::QualifierToken
::pasta::Token UnresolvedUsingValueDecl::UsingToken(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::UnresolvedUsingValueDecl *>(u.UnresolvedUsingValueDecl);
  decltype(auto) val = self.isAccessDeclaration();
  return val;
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const noexcept {
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
}

bool UsingDecl::HasTypename(void) const noexcept {
  auto &self = *const_cast<clang::UsingDecl *>(u.UsingDecl);
  decltype(auto) val = self.hasTypename();
  return val;
}

bool UsingDecl::IsAccessDeclaration(void) const noexcept {
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
}

::pasta::Token UsingEnumDecl::UsingToken(void) const noexcept {
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
std::optional<::pasta::VarDecl> VarDecl::ActingDefinition(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getActingDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  return std::nullopt;
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
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  return std::nullopt;
}

// 0: VarDecl::EvaluatedStatement
// 0: VarDecl::EvaluatedValue
std::optional<::pasta::Expr> VarDecl::Initializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
}

enum VarDeclInitializationStyle VarDecl::InitializerStyle(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitStyle();
  return static_cast<::pasta::VarDeclInitializationStyle>(val);
}

std::optional<::pasta::VarDecl> VarDecl::InitializingDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInitializingDeclaration();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::VarDecl> VarDecl::InstantiatedFromStaticDataMember(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getInstantiatedFromStaticDataMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  return std::nullopt;
}

enum LanguageLinkage VarDecl::LanguageLinkage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(val);
}

// 0: VarDecl::MemberSpecializationInfo
::pasta::Token VarDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum StorageClass VarDecl::StorageClass(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(val);
}

enum StorageDuration VarDecl::StorageDuration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(val);
}

enum VarDeclTLSKind VarDecl::TLSKind(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTLSKind();
  return static_cast<::pasta::VarDeclTLSKind>(val);
}

enum ThreadStorageClassSpecifier VarDecl::TSCSpec(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTSCSpec();
  return static_cast<::pasta::ThreadStorageClassSpecifier>(val);
}

std::optional<::pasta::VarDecl> VarDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  return std::nullopt;
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKindForInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

bool VarDecl::HasConstantInitialization(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasConstantInitialization();
  return val;
}

bool VarDecl::HasDependentAlignment(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasDependentAlignment();
  return val;
}

bool VarDecl::HasExternalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasExternalStorage();
  return val;
}

bool VarDecl::HasGlobalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasGlobalStorage();
  return val;
}

std::optional<bool> VarDecl::HasICEInitializer(void) const noexcept {
  auto &self = *(u.VarDecl);
  if (!self.getInit()) {
    return std::nullopt;
  } else {
    return self.hasICEInitializer(self.getASTContext());
  }
  decltype(auto) val = self.hasICEInitializer(ast->ci->getASTContext());
  return val;
}

bool VarDecl::HasInitializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasInit();
  return val;
}

bool VarDecl::HasLocalStorage(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.hasLocalStorage();
  return val;
}

bool VarDecl::IsARCPseudoStrong(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isARCPseudoStrong();
  return val;
}

bool VarDecl::IsCXXForRangeDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isCXXForRangeDecl();
  return val;
}

bool VarDecl::IsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isConstexpr();
  return val;
}

bool VarDecl::IsDirectInitializer(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isDirectInit();
  return val;
}

bool VarDecl::IsEscapingByref(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isEscapingByref();
  return val;
}

bool VarDecl::IsExceptionVariable(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExceptionVariable();
  return val;
}

bool VarDecl::IsExternC(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isExternC();
  return val;
}

bool VarDecl::IsFileVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFileVarDecl();
  return val;
}

bool VarDecl::IsFunctionOrMethodVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isFunctionOrMethodVarDecl();
  return val;
}

bool VarDecl::IsInExternCContext(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCContext();
  return val;
}

bool VarDecl::IsInExternCXXContext(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInExternCXXContext();
  return val;
}

bool VarDecl::IsInitializerCapture(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInitCapture();
  return val;
}

bool VarDecl::IsInline(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInline();
  return val;
}

bool VarDecl::IsInlineSpecified(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isInlineSpecified();
  return val;
}

bool VarDecl::IsKnownToBeDefined(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isKnownToBeDefined();
  return val;
}

bool VarDecl::IsLocalVariableDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDecl();
  return val;
}

bool VarDecl::IsLocalVariableDeclarationOrParm(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isLocalVarDeclOrParm();
  return val;
}

bool VarDecl::IsNRVOVariable(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNRVOVariable();
  return val;
}

bool VarDecl::IsNoDestroy(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isNoDestroy(ast->ci->getASTContext());
  return val;
}

bool VarDecl::IsNonEscapingByref(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isNonEscapingByref();
  return val;
}

bool VarDecl::IsObjCForDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isObjCForDecl();
  return val;
}

bool VarDecl::IsParameterPack(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isParameterPack();
  return val;
}

bool VarDecl::IsPreviousDeclarationInSameBlockScope(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isPreviousDeclInSameBlockScope();
  return val;
}

bool VarDecl::IsStaticDataMember(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticDataMember();
  return val;
}

bool VarDecl::IsStaticLocal(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isStaticLocal();
  return val;
}

bool VarDecl::IsThisDeclarationADemotedDefinition(void) const noexcept {
  auto &self = *const_cast<clang::VarDecl *>(u.VarDecl);
  decltype(auto) val = self.isThisDeclarationADemotedDefinition();
  return val;
}

bool VarDecl::IsUsableInConstantExpressions(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

bool VarDecl::MightBeUsableInConstantExpressions(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.mightBeUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

enum QualTypeDestructionKind VarDecl::NeedsDestruction(void) const noexcept {
  auto &self = *(u.VarDecl);
  decltype(auto) val = self.needsDestruction(ast->ci->getASTContext());
  return static_cast<::pasta::QualTypeDestructionKind>(val);
}

std::vector<::pasta::TemplateParameterList> VarDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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

::pasta::VarTemplateDecl VarTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateDecl *>(u.VarTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::PreviousDeclaration can return nullptr!");
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
}

::pasta::Token VarTemplateSpecializationDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum TemplateSpecializationKind VarTemplateSpecializationDecl::SpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
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
}

::pasta::Token VarTemplateSpecializationDecl::TemplateKeywordToken(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Type VarTemplateSpecializationDecl::TypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "VarTemplateSpecializationDecl::TypeAsWritten can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::VarTemplateSpecializationDecl *>(u.VarTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
}

std::vector<::pasta::TemplateParameterList> VarTemplateSpecializationDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

bool CXXDeductionGuideDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXDeductionGuideDecl *>(u.CXXDeductionGuideDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXDeductionGuideDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.CXXDeductionGuideDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDeductionGuideDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXDeductionGuideDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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
}

::pasta::Type CXXMethodDecl::ThisObjectType(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getThisObjectType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CXXMethodDecl::ThisType(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.getThisType();
  return TypeBuilder::Build(ast, val);
}

bool CXXMethodDecl::HasInlineBody(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.hasInlineBody();
  return val;
}

bool CXXMethodDecl::IsConst(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isConst();
  return val;
}

bool CXXMethodDecl::IsCopyAssignmentOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isCopyAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsInstance(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isInstance();
  return val;
}

bool CXXMethodDecl::IsLambdaStaticInvoker(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isLambdaStaticInvoker();
  return val;
}

bool CXXMethodDecl::IsMoveAssignmentOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isMoveAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsStatic(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isStatic();
  return val;
}

// 1: CXXMethodDecl::IsUsualDeallocationFunction
bool CXXMethodDecl::IsVirtual(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVirtual();
  return val;
}

bool CXXMethodDecl::IsVolatile(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.isVolatile();
  return val;
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
}

uint32_t CXXMethodDecl::SizeOverriddenMethods(void) const noexcept {
  auto &self = *const_cast<clang::CXXMethodDecl *>(u.CXXMethodDecl);
  decltype(auto) val = self.size_overridden_methods();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXMethodDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.CXXMethodDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXMethodDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXMethodDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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

::pasta::ClassTemplateDecl ClassTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateDecl *>(u.ClassTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::PreviousDeclaration can return nullptr!");
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
}

std::vector<::pasta::TemplateParameterList> DecompositionDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  return std::nullopt;
}

::pasta::Type EnumDecl::IntegerType(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getIntegerType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange EnumDecl::IntegerTypeRange(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getIntegerTypeRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type EnumDecl::IntegerTypeSourceInfo(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getIntegerTypeSourceInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "EnumDecl::IntegerTypeSourceInfo can return nullptr!");
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
}

uint32_t EnumDecl::NumPositiveBits(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getNumPositiveBits();
  return val;
}

uint32_t EnumDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getODRHash();
  return val;
}

::pasta::EnumDecl EnumDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::PreviousDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type EnumDecl::PromotionType(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getPromotionType();
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::EnumDecl> EnumDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  return std::nullopt;
}

enum TemplateSpecializationKind EnumDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

bool EnumDecl::IsClosed(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosed();
  return val;
}

bool EnumDecl::IsClosedFlag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedFlag();
  return val;
}

bool EnumDecl::IsClosedNonFlag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isClosedNonFlag();
  return val;
}

bool EnumDecl::IsComplete(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isComplete();
  return val;
}

bool EnumDecl::IsFixed(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isFixed();
  return val;
}

bool EnumDecl::IsScoped(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScoped();
  return val;
}

bool EnumDecl::IsScopedUsingClassTag(void) const noexcept {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  decltype(auto) val = self.isScopedUsingClassTag();
  return val;
}

std::vector<::pasta::TemplateParameterList> EnumDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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

::pasta::FunctionTemplateDecl FunctionTemplateDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::PreviousDeclaration can return nullptr!");
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
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const noexcept {
  auto &self = *const_cast<clang::FunctionTemplateDecl *>(u.FunctionTemplateDecl);
  decltype(auto) val = self.isThisDeclarationADefinition();
  return val;
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
}

std::vector<::pasta::TemplateParameterList> ImplicitParamDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
}

::pasta::TokenRange ParmVarDecl::DefaultArgumentRange(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getDefaultArgRange();
  return ast->TokenRangeFrom(val);
}

uint32_t ParmVarDecl::FunctionScopeDepth(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeDepth();
  return val;
}

uint32_t ParmVarDecl::FunctionScopeIndex(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getFunctionScopeIndex();
  return val;
}

enum DeclObjCDeclQualifier ParmVarDecl::ObjCDeclQualifier(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getObjCDeclQualifier();
  return static_cast<::pasta::DeclObjCDeclQualifier>(val);
}

::pasta::Type ParmVarDecl::OriginalType(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.getOriginalType();
  return TypeBuilder::Build(ast, val);
}

std::optional<::pasta::Expr> ParmVarDecl::UninstantiatedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  if (!HasUninstantiatedDefaultArgument()) {
    return std::nullopt;
  }
  decltype(auto) val = self.getUninstantiatedDefaultArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  return std::nullopt;
}

bool ParmVarDecl::HasDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasDefaultArg();
  return val;
}

bool ParmVarDecl::HasInheritedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasInheritedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUninstantiatedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUninstantiatedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUnparsedDefaultArgument(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.hasUnparsedDefaultArg();
  return val;
}

bool ParmVarDecl::IsDestroyedInCallee(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isDestroyedInCallee();
  return val;
}

bool ParmVarDecl::IsKNRPromoted(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isKNRPromoted();
  return val;
}

bool ParmVarDecl::IsObjCMethodParameter(void) const noexcept {
  auto &self = *const_cast<clang::ParmVarDecl *>(u.ParmVarDecl);
  decltype(auto) val = self.isObjCMethodParameter();
  return val;
}

std::vector<::pasta::TemplateParameterList> ParmVarDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

std::optional<::pasta::FieldDecl> RecordDecl::FindFirstNamedDataMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.findFirstNamedDataMember();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  return std::nullopt;
}

enum RecordDeclArgPassingKind RecordDecl::ArgumentPassingRestrictions(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getArgPassingRestrictions();
  return static_cast<::pasta::RecordDeclArgPassingKind>(val);
}

std::optional<::pasta::RecordDecl> RecordDecl::Definition(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  return std::nullopt;
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

::pasta::RecordDecl RecordDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::PreviousDeclaration can return nullptr!");
  __builtin_unreachable();
}

bool RecordDecl::HasFlexibleArrayMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasFlexibleArrayMember();
  return val;
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasLoadedFieldsFromExternalStorage();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool RecordDecl::HasObjectMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasObjectMember();
  return val;
}

bool RecordDecl::HasVolatileMember(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.hasVolatileMember();
  return val;
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isAnonymousStructOrUnion();
  return val;
}

bool RecordDecl::IsCapturedRecord(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isCapturedRecord();
  return val;
}

bool RecordDecl::IsInjectedClassName(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isInjectedClassName();
  return val;
}

bool RecordDecl::IsLambda(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
}

bool RecordDecl::IsMsStruct(void) const noexcept {
  auto &self = *(u.RecordDecl);
  decltype(auto) val = self.isMsStruct(ast->ci->getASTContext());
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveCopy();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isNonTrivialToPrimitiveDestroy();
  return val;
}

bool RecordDecl::IsOrContainsUnion(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isOrContainsUnion();
  return val;
}

bool RecordDecl::IsParameterDestroyedInCallee(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.isParamDestroyedInCallee();
  return val;
}

bool RecordDecl::MayInsertExtraPadding(void) const noexcept {
  auto &self = *const_cast<clang::RecordDecl *>(u.RecordDecl);
  decltype(auto) val = self.mayInsertExtraPadding();
  return val;
}

std::vector<::pasta::TemplateParameterList> RecordDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

std::vector<::pasta::TemplateParameterList> VarTemplatePartialSpecializationDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

::pasta::CXXConstructorDecl CXXConstructorDecl::TargetConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.getTargetConstructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXConstructorDecl::TargetConstructor can return nullptr!");
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
}

bool CXXConstructorDecl::IsDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDefaultConstructor();
  return val;
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isDelegatingConstructor();
  return val;
}

bool CXXConstructorDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isInheritingConstructor();
  return val;
}

bool CXXConstructorDecl::IsSpecializationCopyingObject(void) const noexcept {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  decltype(auto) val = self.isSpecializationCopyingObject();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXConstructorDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.CXXConstructorDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConstructorDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXConstructorDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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
  return TypeBuilder::Build(ast, val);
}

// 0: CXXConversionDecl::ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isExplicit();
  return val;
}

bool CXXConversionDecl::IsLambdaToBlockPointerConversion(void) const noexcept {
  auto &self = *const_cast<clang::CXXConversionDecl *>(u.CXXConversionDecl);
  decltype(auto) val = self.isLambdaToBlockPointerConversion();
  return val;
}

std::vector<::pasta::TemplateParameterList> CXXConversionDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.CXXConversionDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXConversionDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXConversionDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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

::pasta::FunctionDecl CXXDestructorDecl::OperatorDelete(void) const noexcept {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDelete();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::OperatorDelete can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CXXDestructorDecl::OperatorDeleteThisArgument(void) const noexcept {
  auto &self = *const_cast<clang::CXXDestructorDecl *>(u.CXXDestructorDecl);
  decltype(auto) val = self.getOperatorDeleteThisArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDestructorDecl::OperatorDeleteThisArgument can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::TemplateParameterList> CXXDestructorDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.CXXDestructorDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CXXDestructorDecl->getTemplateParameterList(i)));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> CXXDestructorDecl::ParameterDeclarations(void) const noexcept {
  auto convert_elem = [&] (const clang::ParmVarDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ParmVarDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ParmVarDecl> ret;
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
bool CXXRecordDecl::AllowConstDefaultInitializer(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.allowConstDefaultInit();
  return val;
}

std::vector<::pasta::CXXBaseSpecifier> CXXRecordDecl::Bases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.bases();
  std::vector<::pasta::CXXBaseSpecifier> ret;
  for (const auto &bs : val) {
    ret.emplace_back(ast, bs);
  }
  return ret;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
enum MSInheritanceModel CXXRecordDecl::CalculateInheritanceModel(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
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
}

bool CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.defaultedCopyConstructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.defaultedDefaultConstructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.defaultedDestructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.defaultedDestructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.defaultedMoveConstructorIsDeleted();
  return val;
}

// 1: CXXRecordDecl::ForallBases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::FriendDecl> CXXRecordDecl::Friends(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.friends();
  std::vector<::pasta::FriendDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::FriendDecl>(ast, decl_ptr));
    }
  }
  return ret;
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
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::FunctionTemplateDecl> CXXRecordDecl::DependentLambdaCallOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDependentLambdaCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::ClassTemplateDecl> CXXRecordDecl::DescribedClassTemplate(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDescribedClassTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::CXXDestructorDecl> CXXRecordDecl::Destructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDestructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  return std::nullopt;
}

uint32_t CXXRecordDecl::DeviceLambdaManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getDeviceLambdaManglingNumber();
  return val;
}

std::optional<::pasta::TemplateParameterList> CXXRecordDecl::GenericLambdaTemplateParameterList(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getGenericLambdaTemplateParameterList();
  return ::pasta::TemplateParameterList(ast, val);
  return std::nullopt;
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::InstantiatedFromMemberClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getInstantiatedFromMemberClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  return std::nullopt;
}

std::optional<::pasta::CXXMethodDecl> CXXRecordDecl::LambdaCallOperator(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  return std::nullopt;
}

enum LambdaCaptureDefault CXXRecordDecl::LambdaCaptureDefault(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(val);
}

::pasta::Decl CXXRecordDecl::LambdaContextDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaContextDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "CXXRecordDecl::LambdaContextDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::NamedDecl> CXXRecordDecl::LambdaExplicitTemplateParameters(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaExplicitTemplateParameters();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

uint32_t CXXRecordDecl::LambdaManglingNumber(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaManglingNumber();
  return val;
}

::pasta::Type CXXRecordDecl::LambdaTypeInfo(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getLambdaTypeInfo();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "CXXRecordDecl::LambdaTypeInfo can return nullptr!");
  __builtin_unreachable();
}

enum MSInheritanceModel CXXRecordDecl::MSInheritanceModel(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMSInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(val);
}

enum MSVtorDispMode CXXRecordDecl::MSVtorDispMode(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMSVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(val);
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

::pasta::CXXRecordDecl CXXRecordDecl::MostRecentNonInjectedDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getMostRecentNonInjectedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentNonInjectedDeclaration can return nullptr!");
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::NumBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getNumBases();
  return val;
}

uint32_t CXXRecordDecl::NumVirtualBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getNumVBases();
  return val;
}

uint32_t CXXRecordDecl::ODRHash(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getODRHash();
  return val;
}

::pasta::CXXRecordDecl CXXRecordDecl::PreviousDeclaration(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::PreviousDeclaration can return nullptr!");
  __builtin_unreachable();
}

std::optional<::pasta::CXXRecordDecl> CXXRecordDecl::TemplateInstantiationPattern(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  if (!clang::isTemplateInstantiation(self.getTemplateSpecializationKind())) {
    return std::nullopt;
  }
  decltype(auto) val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  return std::nullopt;
}

enum TemplateSpecializationKind CXXRecordDecl::TemplateSpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
}

// 0: CXXRecordDecl::VisibleConversionFunctions
bool CXXRecordDecl::HasAnyDependentBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasAnyDependentBases();
  return val;
}

bool CXXRecordDecl::HasConstexprDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasConstexprDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasConstexprDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasConstexprDestructor();
  return val;
}

bool CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasConstexprNonCopyMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasCopyAssignmentWithConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasCopyAssignmentWithConstParam();
  return val;
}

bool CXXRecordDecl::HasCopyConstructorWithConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasCopyConstructorWithConstParam();
  return val;
}

bool CXXRecordDecl::HasDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasDefinition(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasDefinition();
  return val;
}

bool CXXRecordDecl::HasDirectFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasDirectFields();
  return val;
}

bool CXXRecordDecl::HasFriends(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasFriends();
  return val;
}

bool CXXRecordDecl::HasInClassInitializer(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasInClassInitializer();
  return val;
}

bool CXXRecordDecl::HasInheritedAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasInheritedAssignment();
  return val;
}

bool CXXRecordDecl::HasInheritedConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasInheritedConstructor();
  return val;
}

bool CXXRecordDecl::HasIrrelevantDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasIrrelevantDestructor();
  return val;
}

bool CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasKnownLambdaInternalLinkage();
  return val;
}

// 1: CXXRecordDecl::HasMemberName
bool CXXRecordDecl::HasMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasMutableFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasMutableFields();
  return val;
}

bool CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonLiteralTypeFieldsOrBases();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasNonTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasPrivateFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasPrivateFields();
  return val;
}

bool CXXRecordDecl::HasProtectedFields(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasProtectedFields();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasSimpleCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasSimpleCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasSimpleDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasSimpleDestructor();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasSimpleMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasSimpleMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasUninitializedReferenceMember(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUninitializedReferenceMember();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredDestructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveOperation(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserDeclaredMoveOperation();
  return val;
}

bool CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasUserProvidedDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasVariantMembers(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.hasVariantMembers();
  return val;
}

bool CXXRecordDecl::ImplicitCopyAssignmentHasConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.implicitCopyAssignmentHasConstParam();
  return val;
}

bool CXXRecordDecl::ImplicitCopyConstructorHasConstParameter(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.implicitCopyConstructorHasConstParam();
  return val;
}

bool CXXRecordDecl::IsAbstract(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isAbstract();
  return val;
}

bool CXXRecordDecl::IsAggregate(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isAggregate();
  return val;
}

bool CXXRecordDecl::IsAnyDestructorNoReturn(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isAnyDestructorNoReturn();
  return val;
}

bool CXXRecordDecl::IsCLike(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isCLike();
  return val;
}

bool CXXRecordDecl::IsCXX11StandardLayout(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isCXX11StandardLayout();
  return val;
}

// 1: CXXRecordDecl::IsCurrentInstantiation
bool CXXRecordDecl::IsDependentLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isDependentLambda();
  return val;
}

bool CXXRecordDecl::IsDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isDynamicClass();
  return val;
}

bool CXXRecordDecl::IsEffectivelyFinal(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isEffectivelyFinal();
  return val;
}

bool CXXRecordDecl::IsEmpty(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isEmpty();
  return val;
}

bool CXXRecordDecl::IsGenericLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isGenericLambda();
  return val;
}

bool CXXRecordDecl::IsInterfaceLike(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isInterfaceLike();
  return val;
}

bool CXXRecordDecl::IsLambda(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isLambda();
  return val;
}

bool CXXRecordDecl::IsLiteral(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isLiteral();
  return val;
}

std::optional<::pasta::FunctionDecl> CXXRecordDecl::IsLocalClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isLocalClass();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  return std::nullopt;
}

bool CXXRecordDecl::IsPOD(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isPOD();
  return val;
}

bool CXXRecordDecl::IsParsingBaseSpecifiers(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isParsingBaseSpecifiers();
  return val;
}

bool CXXRecordDecl::IsPolymorphic(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isPolymorphic();
  return val;
}

// 1: CXXRecordDecl::IsProvablyNotDerivedFrom
bool CXXRecordDecl::IsStandardLayout(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isStandardLayout();
  return val;
}

bool CXXRecordDecl::IsStructural(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isStructural();
  return val;
}

bool CXXRecordDecl::IsTrivial(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isTrivial();
  return val;
}

bool CXXRecordDecl::IsTriviallyCopyable(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.isTriviallyCopyable();
  return val;
}

// 1: CXXRecordDecl::IsVirtuallyDerivedFrom
bool CXXRecordDecl::LambdaIsDefaultConstructibleAndAssignable(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.lambdaIsDefaultConstructibleAndAssignable();
  return val;
}

// 2: LookupInBases
bool CXXRecordDecl::MayBeAbstract(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.mayBeAbstract();
  return val;
}

bool CXXRecordDecl::MayBeDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.mayBeDynamicClass();
  return val;
}

bool CXXRecordDecl::MayBeNonDynamicClass(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.mayBeNonDynamicClass();
  return val;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::CXXMethodDecl> CXXRecordDecl::Methods(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

bool CXXRecordDecl::NeedsImplicitCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitDefaultConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitDestructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsImplicitMoveConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsOverloadResolutionForCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsOverloadResolutionForCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsOverloadResolutionForDestructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsOverloadResolutionForMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.needsOverloadResolutionForMoveConstructor();
  return val;
}

bool CXXRecordDecl::NullFieldOffsetIsZero(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.nullFieldOffsetIsZero();
  return val;
}

std::vector<::pasta::CXXBaseSpecifier> CXXRecordDecl::VirtualBases(void) const noexcept {
  auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
  decltype(auto) val = self.vbases();
  std::vector<::pasta::CXXBaseSpecifier> ret;
  for (const auto &bs : val) {
    ret.emplace_back(ast, bs);
  }
  return ret;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::TemplateParameterList> CXXRecordDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
}

::pasta::Token ClassTemplateSpecializationDecl::PointOfInstantiation(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum TemplateSpecializationKind ClassTemplateSpecializationDecl::SpecializationKind(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(val);
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
}

::pasta::Token ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

::pasta::Type ClassTemplateSpecializationDecl::TypeAsWritten(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.getTypeAsWritten();
  return TypeBuilder::Build(ast, val->getType());  assert(false && "ClassTemplateSpecializationDecl::TypeAsWritten can return nullptr!");
  __builtin_unreachable();
}

bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const noexcept {
  auto &self = *const_cast<clang::ClassTemplateSpecializationDecl *>(u.ClassTemplateSpecializationDecl);
  decltype(auto) val = self.isExplicitSpecialization();
  return val;
}

std::vector<::pasta::TemplateParameterList> ClassTemplateSpecializationDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
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
  return TypeBuilder::Build(ast, val);
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
}

std::vector<::pasta::TemplateParameterList> ClassTemplatePartialSpecializationDecl::TemplateParameterLists(void) const noexcept {
  auto convert_elem = [&] (clang::TemplateParameterList * val) {
    return ::pasta::TemplateParameterList(ast, val);
  };
  std::vector<::pasta::TemplateParameterList> ret;
  auto count = u.ClassTemplatePartialSpecializationDecl->getNumTemplateParameterLists();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.ClassTemplatePartialSpecializationDecl->getTemplateParameterList(i)));
  }
  return ret;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
