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
      if (auto decl_ptr = clang::dyn_cast<clang::derived>(that.u.base)) { \
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
      if (this != &that) { \
        ast = std::move(that.ast); \
        u.Decl = that.u.Decl; \
        kind = that.kind; \
      } \
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

void DeclVisitor::VisitUnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &decl) {
  VisitTypeDecl(decl);
}

void DeclVisitor::VisitUsingDecl(const UsingDecl &decl) {
  VisitNamedDecl(decl);
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
  "UnresolvedUsingTypename",
  "UnresolvedUsingValue",
  "Using",
  "UsingDirective",
  "UsingPack",
  "UsingShadow",
  "Value",
  "Var",
  "VarTemplate",
  "VarTemplatePartialSpecialization",
  "VarTemplateSpecialization",
};
}  // namespace

std::string_view Decl::KindName(void) const {
  return kKindNames[static_cast<unsigned>(kind)];
}

// 1: DeclContext::Encloses
// 1: DeclContext::Equals
// 1: DeclContext::InEnclosingNamespaceSetOf
// 1: DeclContext::ContainsDecl
// 1: DeclContext::ContainsDeclAndLoad
// 0: DeclContext::Ddiags
std::vector<::pasta::Decl> DeclContext::Declarations(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
  }
  return ret;
}

// 0: DeclContext::
// 0: DeclContext::
// 0: DeclContext::
::pasta::DeclKind DeclContext::DeclKind(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getDeclKind();
  return static_cast<::pasta::DeclKind>(val);
}

// 0: DeclContext::
::pasta::DeclContext DeclContext::EnclosingNamespaceContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getEnclosingNamespaceContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::EnclosingNamespaceContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::LinkageSpecDecl DeclContext::ExternCContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getExternCContext();
  if (val) {
    return DeclBuilder::Create<::pasta::LinkageSpecDecl>(ast, val);
  }
  assert(false && "DeclContext::ExternCContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::BlockDecl DeclContext::InnermostBlockDecl(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getInnermostBlockDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::BlockDecl>(ast, val);
  }
  assert(false && "DeclContext::InnermostBlockDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::LexicalParent(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getLexicalParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::LexicalParent can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::LookupParent(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getLookupParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::LookupParent can return nullptr!");
  __builtin_unreachable();
}

// 0: DeclContext::LookupPtr
::pasta::Decl DeclContext::NonClosureAncestor(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getNonClosureAncestor();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "DeclContext::NonClosureAncestor can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl DeclContext::OuterLexicalRecordContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getOuterLexicalRecordContext();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "DeclContext::OuterLexicalRecordContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::Parent(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::Parent can return nullptr!");
  __builtin_unreachable();
}

// 0: DeclContext::ParentASTContext
::pasta::DeclContext DeclContext::PrimaryContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getPrimaryContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::PrimaryContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::RedeclContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.getRedeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::RedeclContext can return nullptr!");
  __builtin_unreachable();
}

bool DeclContext::HasExternalLexicalStorage(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.hasExternalLexicalStorage();
  return val;
}

bool DeclContext::HasExternalVisibleStorage(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.hasExternalVisibleStorage();
  return val;
}

bool DeclContext::IsClosure(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isClosure();
  return val;
}

// 1: DeclContext::IsDeclInLexicalTraversal
bool DeclContext::IsDependentContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isDependentContext();
  return val;
}

bool DeclContext::IsExternCContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isExternCContext();
  return val;
}

bool DeclContext::IsExternCXXContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isExternCXXContext();
  return val;
}

bool DeclContext::IsFileContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isFileContext();
  return val;
}

bool DeclContext::IsFunctionOrMethod(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isFunctionOrMethod();
  return val;
}

bool DeclContext::IsInlineNamespace(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isInlineNamespace();
  return val;
}

bool DeclContext::IsLookupContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isLookupContext();
  return val;
}

bool DeclContext::IsNamespace(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isNamespace();
  return val;
}

bool DeclContext::IsObjCContainer(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isObjCContainer();
  return val;
}

bool DeclContext::IsRecord(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isRecord();
  return val;
}

bool DeclContext::IsStdNamespace(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isStdNamespace();
  return val;
}

bool DeclContext::IsTranslationUnit(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isTranslationUnit();
  return val;
}

bool DeclContext::IsTransparentContext(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.isTransparentContext();
  return val;
}

// 1: DeclContext::Lookup
// 0: DeclContext::Lookups
// 0: DeclContext::
// 0: DeclContext::
std::vector<::pasta::Decl> DeclContext::AlreadyLoadedDecls(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.noload_decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
  }
  return ret;
}

// 0: DeclContext::
// 0: DeclContext::
// 1: DeclContext::Noload_lookups
// 0: DeclContext::
// 0: DeclContext::
bool DeclContext::ShouldUseQualifiedLookup(void) const {
  auto &self = *(u.DeclContext);
  auto val = self.shouldUseQualifiedLookup();
  return val;
}

// 0: DeclContext::Using_directives
Decl::Decl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}
PASTA_DEFINE_DERIVED_OPERATORS(Decl, AccessSpecDecl)
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
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDirectiveDecl)
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
enum AccessSpecifier Decl::Access(void) const {
  auto &self = *(u.Decl);
  auto val = self.getAccess();
  return static_cast<::pasta::AccessSpecifier>(static_cast<unsigned int>(val));
}

enum AccessSpecifier Decl::AccessUnsafe(void) const {
  auto &self = *(u.Decl);
  auto val = self.getAccessUnsafe();
  return static_cast<::pasta::AccessSpecifier>(static_cast<unsigned int>(val));
}

::pasta::FunctionDecl Decl::AsFunction(void) const {
  auto &self = *(u.Decl);
  auto val = self.getAsFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "Decl::AsFunction can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::Attributes
enum AvailabilityResult Decl::Availability(void) const {
  auto &self = *(u.Decl);
  auto val = self.getAvailability();
  return static_cast<::pasta::AvailabilityResult>(static_cast<unsigned int>(val));
}

::pasta::Token Decl::BeginToken(void) const {
  auto &self = *(u.Decl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt Decl::Body(void) const {
  auto &self = *(u.Decl);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "Decl::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token Decl::BodyRBrace(void) const {
  auto &self = *(u.Decl);
  auto val = self.getBodyRBrace();
  return ast->TokenAt(val);
}

::pasta::Decl Decl::CanonicalDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext Decl::DeclContext(void) const {
  auto &self = *(u.Decl);
  auto val = self.getDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::DeclContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::
// 0: Decl::DefiningAttr
::pasta::TemplateDecl Decl::DescribedTemplate(void) const {
  auto &self = *(u.Decl);
  auto val = self.getDescribedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  assert(false && "Decl::DescribedTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::DescribedTemplateParams
::pasta::Token Decl::EndToken(void) const {
  auto &self = *(u.Decl);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

// 0: Decl::ExternalSourceSymbolAttr
::pasta::FriendObjectKind Decl::FriendObjectKind(void) const {
  auto &self = *(u.Decl);
  auto val = self.getFriendObjectKind();
  return static_cast<::pasta::FriendObjectKind>(val);
}

::pasta::FunctionType Decl::FunctionType(void) const {
  auto &self = *(u.Decl);
  auto val = self.getFunctionType();
  if (val) {
    return TypeBuilder::Create<::pasta::FunctionType>(ast, val);
  }
  assert(false && "Decl::FunctionType can return nullptr!");
  __builtin_unreachable();
}

uint32_t Decl::GlobalID(void) const {
  auto &self = *(u.Decl);
  auto val = self.getGlobalID();
  return val;
}

int64_t Decl::ID(void) const {
  auto &self = *(u.Decl);
  auto val = self.getID();
  return val;
}

uint32_t Decl::IdentifierNamespace(void) const {
  auto &self = *(u.Decl);
  auto val = self.getIdentifierNamespace();
  return val;
}

// 0: Decl::ImportedOwningModule
// 0: Decl::
// 0: Decl::LangOpts
::pasta::DeclContext Decl::LexicalDeclContext(void) const {
  auto &self = *(u.Decl);
  auto val = self.getLexicalDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::LexicalDeclContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::LocalOwningModule
::pasta::Token Decl::Token(void) const {
  auto &self = *(u.Decl);
  auto val = self.getLocation();
  return ast->TokenAt(val);
}

uint32_t Decl::MaxAlignment(void) const {
  auto &self = *(u.Decl);
  auto val = self.getMaxAlignment();
  return val;
}

::pasta::ModuleOwnershipKind Decl::ModuleOwnershipKind(void) const {
  auto &self = *(u.Decl);
  auto val = self.getModuleOwnershipKind();
  return static_cast<::pasta::ModuleOwnershipKind>(val);
}

::pasta::Decl Decl::MostRecentDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::NextDeclInContext(void) const {
  auto &self = *(u.Decl);
  auto val = self.getNextDeclInContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NextDeclInContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::NonClosureContext(void) const {
  auto &self = *(u.Decl);
  auto val = self.getNonClosureContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NonClosureContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::OwningModule
// 0: Decl::OwningModuleForLinkage
uint32_t Decl::OwningModuleID(void) const {
  auto &self = *(u.Decl);
  auto val = self.getOwningModuleID();
  return val;
}

::pasta::DeclContext Decl::ParentFunctionOrMethod(void) const {
  auto &self = *(u.Decl);
  auto val = self.getParentFunctionOrMethod();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::ParentFunctionOrMethod can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::PreviousDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange Decl::TokenRange(void) const {
  auto &self = *(u.Decl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

uint32_t Decl::TemplateDepth(void) const {
  auto &self = *(u.Decl);
  auto val = self.getTemplateDepth();
  return val;
}

::pasta::TranslationUnitDecl Decl::TranslationUnitDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.getTranslationUnitDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TranslationUnitDecl>(ast, val);
  }
  assert(false && "Decl::TranslationUnitDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::VersionIntroduced
bool Decl::HasAttributes(void) const {
  auto &self = *(u.Decl);
  auto val = self.hasAttrs();
  return val;
}

bool Decl::HasBody(void) const {
  auto &self = *(u.Decl);
  auto val = self.hasBody();
  return val;
}

bool Decl::HasDefiningAttr(void) const {
  auto &self = *(u.Decl);
  auto val = self.hasDefiningAttr();
  return val;
}

bool Decl::HasOwningModule(void) const {
  auto &self = *(u.Decl);
  auto val = self.hasOwningModule();
  return val;
}

bool Decl::HasTagIdentifierNamespace(void) const {
  auto &self = *(u.Decl);
  auto val = self.hasTagIdentifierNamespace();
  return val;
}

bool Decl::IsCanonicalDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.isCanonicalDecl();
  return val;
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const {
  auto &self = *(u.Decl);
  auto val = self.isDefinedOutsideFunctionOrMethod();
  return val;
}

bool Decl::IsDeprecated(void) const {
  auto &self = *(u.Decl);
  auto val = self.isDeprecated();
  return val;
}

bool Decl::IsFirstDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.isFirstDecl();
  return val;
}

bool Decl::IsFromASTFile(void) const {
  auto &self = *(u.Decl);
  auto val = self.isFromASTFile();
  return val;
}

bool Decl::IsFunctionOrFunctionTemplate(void) const {
  auto &self = *(u.Decl);
  auto val = self.isFunctionOrFunctionTemplate();
  return val;
}

bool Decl::IsImplicit(void) const {
  auto &self = *(u.Decl);
  auto val = self.isImplicit();
  return val;
}

bool Decl::IsInAnonymousNamespace(void) const {
  auto &self = *(u.Decl);
  auto val = self.isInAnonymousNamespace();
  return val;
}

// 1: Decl::IsInIdentifierNamespace
bool Decl::IsInLocalScopeForInstantiation(void) const {
  auto &self = *(u.Decl);
  auto val = self.isInLocalScopeForInstantiation();
  return val;
}

bool Decl::IsInStdNamespace(void) const {
  auto &self = *(u.Decl);
  auto val = self.isInStdNamespace();
  return val;
}

bool Decl::IsInvalidDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.isInvalidDecl();
  return val;
}

bool Decl::IsModulePrivate(void) const {
  auto &self = *(u.Decl);
  auto val = self.isModulePrivate();
  return val;
}

bool Decl::IsOutOfLine(void) const {
  auto &self = *(u.Decl);
  auto val = self.isOutOfLine();
  return val;
}

bool Decl::IsParameterPack(void) const {
  auto &self = *(u.Decl);
  auto val = self.isParameterPack();
  return val;
}

bool Decl::IsReferenced(void) const {
  auto &self = *(u.Decl);
  auto val = self.isReferenced();
  return val;
}

bool Decl::IsTemplateDecl(void) const {
  auto &self = *(u.Decl);
  auto val = self.isTemplateDecl();
  return val;
}

bool Decl::IsTemplateParameter(void) const {
  auto &self = *(u.Decl);
  auto val = self.isTemplateParameter();
  return val;
}

bool Decl::IsTemplateParameterPack(void) const {
  auto &self = *(u.Decl);
  auto val = self.isTemplateParameterPack();
  return val;
}

bool Decl::IsTemplated(void) const {
  auto &self = *(u.Decl);
  auto val = self.isTemplated();
  return val;
}

bool Decl::IsThisDeclarationReferenced(void) const {
  auto &self = *(u.Decl);
  auto val = self.isThisDeclarationReferenced();
  return val;
}

bool Decl::IsTopLevelDeclInObjCContainer(void) const {
  auto &self = *(u.Decl);
  auto val = self.isTopLevelDeclInObjCContainer();
  return val;
}

bool Decl::IsUnavailable(void) const {
  auto &self = *(u.Decl);
  auto val = self.isUnavailable();
  return val;
}

bool Decl::IsUnconditionallyVisible(void) const {
  auto &self = *(u.Decl);
  auto val = self.isUnconditionallyVisible();
  return val;
}

bool Decl::IsUsed(void) const {
  auto &self = *(u.Decl);
  auto val = self.isUsed();
  return val;
}

bool Decl::IsWeakImported(void) const {
  auto &self = *(u.Decl);
  auto val = self.isWeakImported();
  return val;
}

std::vector<::pasta::Decl> Decl::Redeclarations(void) const {
  auto &self = *(u.Decl);
  auto val = self.redecls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
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
  auto &self = *(u.ExportDecl);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::ExportToken(void) const {
  auto &self = *(u.ExportDecl);
  auto val = self.getExportLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::RBraceToken(void) const {
  auto &self = *(u.ExportDecl);
  auto val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ExportDecl::TokenRange(void) const {
  auto &self = *(u.ExportDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ExportDecl::HasBraces(void) const {
  auto &self = *(u.ExportDecl);
  auto val = self.hasBraces();
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
::pasta::Token FileScopeAsmDecl::AsmToken(void) const {
  auto &self = *(u.FileScopeAsmDecl);
  auto val = self.getAsmLoc();
  return ast->TokenAt(val);
}

::pasta::StringLiteral FileScopeAsmDecl::AsmString(void) const {
  auto &self = *(u.FileScopeAsmDecl);
  auto val = self.getAsmString();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "FileScopeAsmDecl::AsmString can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FileScopeAsmDecl::RParenToken(void) const {
  auto &self = *(u.FileScopeAsmDecl);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange FileScopeAsmDecl::TokenRange(void) const {
  auto &self = *(u.FileScopeAsmDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendDecl)
::pasta::NamedDecl FriendDecl::FindFriendDecl(void) const {
  auto &self = *(u.FriendDecl);
  auto val = self.getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendDecl::FindFriendDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendDecl::FriendToken(void) const {
  auto &self = *(u.FriendDecl);
  auto val = self.getFriendLoc();
  return ast->TokenAt(val);
}

// 0: FriendDecl::FriendType
uint32_t FriendDecl::FriendTypeNumTemplateParameterLists(void) const {
  auto &self = *(u.FriendDecl);
  auto val = self.getFriendTypeNumTemplateParameterLists();
  return val;
}

// 1: FriendDecl::FriendTypeTemplateParameterList
::pasta::TokenRange FriendDecl::TokenRange(void) const {
  auto &self = *(u.FriendDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool FriendDecl::IsUnsupportedFriend(void) const {
  auto &self = *(u.FriendDecl);
  auto val = self.isUnsupportedFriend();
  return val;
}

FriendTemplateDecl::FriendTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FriendTemplateDecl)
::pasta::NamedDecl FriendTemplateDecl::FindFriendDecl(void) const {
  auto &self = *(u.FriendTemplateDecl);
  auto val = self.getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendTemplateDecl::FindFriendDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendTemplateDecl::FriendToken(void) const {
  auto &self = *(u.FriendTemplateDecl);
  auto val = self.getFriendLoc();
  return ast->TokenAt(val);
}

// 0: FriendTemplateDecl::FriendType
uint32_t FriendTemplateDecl::NumTemplateParameters(void) const {
  auto &self = *(u.FriendTemplateDecl);
  auto val = self.getNumTemplateParameters();
  return val;
}

// 1: FriendTemplateDecl::TemplateParameterList
ImportDecl::ImportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ImportDecl)
std::vector<::pasta::Token> ImportDecl::IdentifierLocs(void) const {
  auto &self = *(u.ImportDecl);
  auto val = self.getIdentifierLocs();
  std::vector<::pasta::Token> ret;
  for (auto sl : val) {
    ret.emplace_back(ast->TokenAt(sl));
  }
  return ret;
}

// 0: ImportDecl::ImportedModule
::pasta::TokenRange ImportDecl::TokenRange(void) const {
  auto &self = *(u.ImportDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
std::vector<::pasta::Stmt> LifetimeExtendedTemporaryDecl::ChildrenExpr(void) const {
  auto &self = *(u.LifetimeExtendedTemporaryDecl);
  auto val = self.childrenExpr();
  std::vector<::pasta::Stmt> ret;
  for (auto stmt_ptr : val) {
    ret.emplace_back(StmtBuilder::Create<::pasta::Stmt>(ast, stmt_ptr));
  }
  return ret;
}

::pasta::ValueDecl LifetimeExtendedTemporaryDecl::ExtendingDecl(void) const {
  auto &self = *(u.LifetimeExtendedTemporaryDecl);
  auto val = self.getExtendingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "LifetimeExtendedTemporaryDecl::ExtendingDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t LifetimeExtendedTemporaryDecl::ManglingNumber(void) const {
  auto &self = *(u.LifetimeExtendedTemporaryDecl);
  auto val = self.getManglingNumber();
  return val;
}

// 1: LifetimeExtendedTemporaryDecl::OrCreateValue
enum StorageDuration LifetimeExtendedTemporaryDecl::StorageDuration(void) const {
  auto &self = *(u.LifetimeExtendedTemporaryDecl);
  auto val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(static_cast<unsigned int>(val));
}

::pasta::Expr LifetimeExtendedTemporaryDecl::TemporaryExpr(void) const {
  auto &self = *(u.LifetimeExtendedTemporaryDecl);
  auto val = self.getTemporaryExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "LifetimeExtendedTemporaryDecl::TemporaryExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: LifetimeExtendedTemporaryDecl::Value
LinkageSpecDecl::LinkageSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, LinkageSpecDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, LinkageSpecDecl)
::pasta::Token LinkageSpecDecl::EndToken(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token LinkageSpecDecl::ExternToken(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.getExternLoc();
  return ast->TokenAt(val);
}

::pasta::LanguageIDs LinkageSpecDecl::Language(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.getLanguage();
  return static_cast<::pasta::LanguageIDs>(val);
}

::pasta::Token LinkageSpecDecl::RBraceToken(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange LinkageSpecDecl::TokenRange(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool LinkageSpecDecl::HasBraces(void) const {
  auto &self = *(u.LinkageSpecDecl);
  auto val = self.hasBraces();
  return val;
}

NamedDecl::NamedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NamedDecl)
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
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingPackDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
// 1: NamedDecl::DeclarationReplaces
// 0: NamedDecl::DeclName
// 1: NamedDecl::ExplicitVisibility
enum Linkage NamedDecl::FormalLinkage(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getFormalLinkage();
  return static_cast<::pasta::Linkage>(static_cast<unsigned char>(val));
}

// 0: NamedDecl::Identifier
// 0: NamedDecl::LinkageAndVisibility
enum Linkage NamedDecl::LinkageInternal(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getLinkageInternal();
  return static_cast<::pasta::Linkage>(static_cast<unsigned char>(val));
}

::pasta::NamedDecl NamedDecl::MostRecentDecl(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

std::string_view NamedDecl::Name(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string NamedDecl::NameAsString(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getNameAsString();
  return val;
}

enum ObjCStringFormatFamily NamedDecl::ObjCFStringFormattingFamily(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getObjCFStringFormattingFamily();
  return static_cast<::pasta::ObjCStringFormatFamily>(static_cast<unsigned int>(val));
}

std::string NamedDecl::QualifiedNameAsString(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getQualifiedNameAsString();
  return val;
}

::pasta::NamedDecl NamedDecl::UnderlyingDecl(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getUnderlyingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::UnderlyingDecl can return nullptr!");
  __builtin_unreachable();
}

enum Visibility NamedDecl::Visibility(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.getVisibility();
  return static_cast<::pasta::Visibility>(static_cast<unsigned int>(val));
}

bool NamedDecl::HasExternalFormalLinkage(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.hasExternalFormalLinkage();
  return val;
}

bool NamedDecl::HasLinkage(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.hasLinkage();
  return val;
}

bool NamedDecl::HasLinkageBeenComputed(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.hasLinkageBeenComputed();
  return val;
}

bool NamedDecl::IsCXXClassMember(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.isCXXClassMember();
  return val;
}

bool NamedDecl::IsCXXInstanceMember(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.isCXXInstanceMember();
  return val;
}

bool NamedDecl::IsExternallyDeclarable(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.isExternallyDeclarable();
  return val;
}

bool NamedDecl::IsExternallyVisible(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.isExternallyVisible();
  return val;
}

bool NamedDecl::IsLinkageValid(void) const {
  auto &self = *(u.NamedDecl);
  auto val = self.isLinkageValid();
  return val;
}

NamespaceAliasDecl::NamespaceAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceAliasDecl)
::pasta::Token NamespaceAliasDecl::AliasToken(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getAliasLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl NamespaceAliasDecl::AliasedNamespace(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getAliasedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::AliasedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceAliasDecl NamespaceAliasDecl::CanonicalDecl(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceAliasDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceAliasDecl::Namespace(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::Namespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceAliasDecl::NamespaceToken(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getNamespaceLoc();
  return ast->TokenAt(val);
}

// 0: NamespaceAliasDecl::Qualifier
// 0: NamespaceAliasDecl::QualifierToken
::pasta::TokenRange NamespaceAliasDecl::TokenRange(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token NamespaceAliasDecl::TargetNameToken(void) const {
  auto &self = *(u.NamespaceAliasDecl);
  auto val = self.getTargetNameLoc();
  return ast->TokenAt(val);
}

NamespaceDecl::NamespaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, NamespaceDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, NamespaceDecl)
::pasta::NamespaceDecl NamespaceDecl::AnonymousNamespace(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getAnonymousNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::AnonymousNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::BeginToken(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl NamespaceDecl::CanonicalDecl(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceDecl::OriginalNamespace(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getOriginalNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::OriginalNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::RBraceToken(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange NamespaceDecl::TokenRange(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool NamespaceDecl::IsAnonymousNamespace(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.isAnonymousNamespace();
  return val;
}

bool NamespaceDecl::IsInline(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.isInline();
  return val;
}

bool NamespaceDecl::IsOriginalNamespace(void) const {
  auto &self = *(u.NamespaceDecl);
  auto val = self.isOriginalNamespace();
  return val;
}

ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
::pasta::ObjCInterfaceDecl ObjCCompatibleAliasDecl::ClassInterface(void) const {
  auto &self = *(u.ObjCCompatibleAliasDecl);
  auto val = self.getClassInterface();
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
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::ClassMethods(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.class_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::ClassProperties(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.class_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
::pasta::TokenRange ObjCContainerDecl::AtEndRange(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.getAtEndRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token ObjCContainerDecl::AtStartToken(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.getAtStartLoc();
  return ast->TokenAt(val);
}

// 1: ObjCContainerDecl::ClassMethod
// 1: ObjCContainerDecl::InstanceMethod
// 1: ObjCContainerDecl::IvarDecl
// 2: Method
::pasta::TokenRange ObjCContainerDecl::TokenRange(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::InstanceMethods(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.instance_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::InstanceProperties(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.instance_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
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
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCContainerDecl::
// 0: ObjCContainerDecl::
std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::Properties(void) const {
  auto &self = *(u.ObjCContainerDecl);
  auto val = self.properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
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
// 2: FindPropertyImplDecl
// 1: ObjCImplDecl::FindPropertyImplIvarDecl
::pasta::ObjCInterfaceDecl ObjCImplDecl::ClassInterface(void) const {
  auto &self = *(u.ObjCImplDecl);
  auto val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::ObjCPropertyImplDecl> ObjCImplDecl::PropertyImplementations(void) const {
  auto &self = *(u.ObjCImplDecl);
  auto val = self.property_impls();
  std::vector<::pasta::ObjCPropertyImplDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyImplDecl>(ast, decl_ptr));
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
::pasta::Token ObjCImplementationDecl::IvarLBraceToken(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCImplementationDecl::IvarRBraceToken(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
}

std::string_view ObjCImplementationDecl::Name(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string ObjCImplementationDecl::NameAsString(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getNameAsString();
  return val;
}

uint32_t ObjCImplementationDecl::NumIvarInitializers(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getNumIvarInitializers();
  return val;
}

std::string_view ObjCImplementationDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::ObjCInterfaceDecl ObjCImplementationDecl::SuperClass(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplementationDecl::SuperClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCImplementationDecl::SuperClassToken(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.getSuperClassLoc();
  return ast->TokenAt(val);
}

bool ObjCImplementationDecl::HasDestructors(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.hasDestructors();
  return val;
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const {
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.hasNonZeroConstructors();
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
  auto &self = *(u.ObjCImplementationDecl);
  auto val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
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
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.all_referenced_protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.declaresOrInheritsDesignatedInitializers();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::CanonicalDecl(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 1: ObjCInterfaceDecl::CategoryClassMethod
// 1: ObjCInterfaceDecl::CategoryInstanceMethod
::pasta::ObjCCategoryDecl ObjCInterfaceDecl::CategoryListRaw(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getCategoryListRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CategoryListRaw can return nullptr!");
  __builtin_unreachable();
}

// 2: CategoryMethod
::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::Definition(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::EndOfDefinitionToken(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getEndOfDefinitionLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCImplementationDecl ObjCInterfaceDecl::Implementation(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCImplementationDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::Implementation can return nullptr!");
  __builtin_unreachable();
}

std::string_view ObjCInterfaceDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

// 0: ObjCInterfaceDecl::ReferencedProtocols
::pasta::TokenRange ObjCInterfaceDecl::TokenRange(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::SuperClass(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::SuperClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::SuperClassToken(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getSuperClassLoc();
  return ast->TokenAt(val);
}

// 0: ObjCInterfaceDecl::SuperClassTInfo
::pasta::ObjCObjectType ObjCInterfaceDecl::SuperClassType(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getSuperClassType();
  if (val) {
    return TypeBuilder::Create<::pasta::ObjCObjectType>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::SuperClassType can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type ObjCInterfaceDecl::TypeForDecl(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.getTypeForDecl();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::TypeForDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCInterfaceDecl::TypeParamList
// 0: ObjCInterfaceDecl::TypeParamListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.hasDefinition();
  return val;
}

bool ObjCInterfaceDecl::HasDesignatedInitializers(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.hasDesignatedInitializers();
  return val;
}

bool ObjCInterfaceDecl::IsArcWeakrefUnavailable(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.isArcWeakrefUnavailable();
  return val;
}

// 1: ObjCInterfaceDecl::IsDesignatedInitializer
bool ObjCInterfaceDecl::IsImplicitInterfaceDecl(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.isImplicitInterfaceDecl();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::IsObjCRequiresPropertyDefs(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.isObjCRequiresPropertyDefs();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::IsObjCRequiresPropertyDefs can return nullptr!");
  __builtin_unreachable();
}

// 1: ObjCInterfaceDecl::IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCInterfaceDecl::InstanceVariables(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownCategories(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.known_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownExtensions(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.known_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
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
std::vector<::pasta::Token> ObjCInterfaceDecl::ProtocolLocations(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::Protocols(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleCategories(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.visible_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
// 0: ObjCInterfaceDecl::
std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleExtensions(void) const {
  auto &self = *(u.ObjCInterfaceDecl);
  auto val = self.visible_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
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
  auto val = self.definedInNSObject(ast->ci->getASTContext());
  return val;
}

::pasta::ObjCPropertyDecl ObjCMethodDecl::FindPropertyDecl(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.findPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::FindPropertyDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::BeginToken(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Stmt ObjCMethodDecl::Body(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "ObjCMethodDecl::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCMethodDecl::CanonicalDecl(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCMethodDecl::Category(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::Category can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCMethodDecl::ClassInterface(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ImplicitParamDecl ObjCMethodDecl::CmdDecl(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getCmdDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CmdDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::DeclaratorEndToken(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getDeclaratorEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCMethodDecl::EndToken(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getEndLoc();
  return ast->TokenAt(val);
}

::pasta::ImplementationControl ObjCMethodDecl::ImplementationControl(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getImplementationControl();
  return static_cast<::pasta::ImplementationControl>(val);
}

enum ObjCMethodFamily ObjCMethodDecl::MethodFamily(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getMethodFamily();
  return static_cast<::pasta::ObjCMethodFamily>(static_cast<unsigned int>(val));
}

uint32_t ObjCMethodDecl::NumSelectorLocs(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getNumSelectorLocs();
  return val;
}

// 0: ObjCMethodDecl::ObjCDeclQualifier
// 1: ObjCMethodDecl::ParamDecl
::pasta::Type ObjCMethodDecl::ReturnType(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getReturnType();
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCMethodDecl::ReturnTypeSourceInfo
::pasta::TokenRange ObjCMethodDecl::ReturnTypeSourceRange(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCMethodDecl::Selector
// 1: ObjCMethodDecl::SelectorToken
::pasta::Token ObjCMethodDecl::SelectorStartToken(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getSelectorStartLoc();
  return ast->TokenAt(val);
}

::pasta::ImplicitParamDecl ObjCMethodDecl::SelfDecl(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getSelfDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::SelfDecl can return nullptr!");
  __builtin_unreachable();
}

// 4: ObjCMethodDecl::SelfType
::pasta::TokenRange ObjCMethodDecl::TokenRange(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCMethodDecl::HasBody(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.hasBody();
  return val;
}

bool ObjCMethodDecl::HasRedeclaration(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.hasRedeclaration();
  return val;
}

bool ObjCMethodDecl::HasRelatedResultType(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.hasRelatedResultType();
  return val;
}

bool ObjCMethodDecl::HasSkippedBody(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.hasSkippedBody();
  return val;
}

bool ObjCMethodDecl::IsClassMethod(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isClassMethod();
  return val;
}

bool ObjCMethodDecl::IsDefined(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isDefined();
  return val;
}

bool ObjCMethodDecl::IsDesignatedInitializerForTheInterface(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isDesignatedInitializerForTheInterface();
  return val;
}

bool ObjCMethodDecl::IsDirectMethod(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isDirectMethod();
  return val;
}

bool ObjCMethodDecl::IsInstanceMethod(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isInstanceMethod();
  return val;
}

bool ObjCMethodDecl::IsOptional(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isOptional();
  return val;
}

bool ObjCMethodDecl::IsOverriding(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isOverriding();
  return val;
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isPropertyAccessor();
  return val;
}

bool ObjCMethodDecl::IsRedeclaration(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isRedeclaration();
  return val;
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isSynthesizedAccessorStub();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADesignatedInitializer(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isThisDeclarationADesignatedInitializer();
  return val;
}

bool ObjCMethodDecl::IsVariadic(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.isVariadic();
  return val;
}

// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
// 0: ObjCMethodDecl::
std::vector<::pasta::ParmVarDecl> ObjCMethodDecl::Parameters(void) const {
  auto &self = *(u.ObjCMethodDecl);
  auto val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCMethodDecl::
std::vector<::pasta::Token> ObjCMethodDecl::SelectorTokens(void) const {
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
::pasta::Token ObjCPropertyDecl::AtToken(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getAtLoc();
  return ast->TokenAt(val);
}

// 1: ObjCPropertyDecl::DefaultSynthIvarName
::pasta::ObjCMethodDecl ObjCPropertyDecl::GetterMethodDecl(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::GetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::GetterName
::pasta::Token ObjCPropertyDecl::GetterNameToken(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getGetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCPropertyDecl::LParenToken(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getLParenLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyDecl::PropertyAttributes
// 0: ObjCPropertyDecl::PropertyAttributesAsWritten
::pasta::PropertyControl ObjCPropertyDecl::PropertyImplementation(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getPropertyImplementation();
  return static_cast<::pasta::PropertyControl>(val);
}

::pasta::ObjCIvarDecl ObjCPropertyDecl::PropertyIvarDecl(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::PropertyIvarDecl can return nullptr!");
  __builtin_unreachable();
}

enum ObjCPropertyQueryKind ObjCPropertyDecl::QueryKind(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getQueryKind();
  return static_cast<::pasta::ObjCPropertyQueryKind>(static_cast<unsigned char>(val));
}

::pasta::SetterKind ObjCPropertyDecl::SetterKind(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getSetterKind();
  return static_cast<::pasta::SetterKind>(val);
}

::pasta::ObjCMethodDecl ObjCPropertyDecl::SetterMethodDecl(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::SetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::SetterName
::pasta::Token ObjCPropertyDecl::SetterNameToken(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getSetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCPropertyDecl::TokenRange(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type ObjCPropertyDecl::Type(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.getType();
  return TypeBuilder::Build(ast, val);
}

// 0: ObjCPropertyDecl::TypeSourceInfo
// 1: ObjCPropertyDecl::UsageType
bool ObjCPropertyDecl::IsAtomic(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isAtomic();
  return val;
}

bool ObjCPropertyDecl::IsClassProperty(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isClassProperty();
  return val;
}

bool ObjCPropertyDecl::IsDirectProperty(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isDirectProperty();
  return val;
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isInstanceProperty();
  return val;
}

bool ObjCPropertyDecl::IsOptional(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isOptional();
  return val;
}

bool ObjCPropertyDecl::IsReadOnly(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isReadOnly();
  return val;
}

bool ObjCPropertyDecl::IsRetaining(void) const {
  auto &self = *(u.ObjCPropertyDecl);
  auto val = self.isRetaining();
  return val;
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCPropertyImplDecl)
::pasta::Token ObjCPropertyImplDecl::BeginToken(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCPropertyImplDecl::GetterCXXConstructor(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getGetterCXXConstructor();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::GetterCXXConstructor can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::GetterMethodDecl(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::GetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCPropertyDecl ObjCPropertyImplDecl::PropertyDecl(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyImplDecl::PropertyImplementation
::pasta::ObjCIvarDecl ObjCPropertyImplDecl::PropertyIvarDecl(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyIvarDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyImplDecl::PropertyIvarDeclToken(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getPropertyIvarDeclLoc();
  return ast->TokenAt(val);
}

::pasta::Expr ObjCPropertyImplDecl::SetterCXXAssignment(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getSetterCXXAssignment();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::SetterCXXAssignment can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCMethodDecl ObjCPropertyImplDecl::SetterMethodDecl(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::SetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange ObjCPropertyImplDecl::TokenRange(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCPropertyImplDecl::IsIvarNameSpecified(void) const {
  auto &self = *(u.ObjCPropertyImplDecl);
  auto val = self.isIvarNameSpecified();
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
::pasta::ObjCProtocolDecl ObjCProtocolDecl::CanonicalDecl(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCProtocolDecl ObjCProtocolDecl::Definition(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

std::string_view ObjCProtocolDecl::ObjCRuntimeNameAsString(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.getObjCRuntimeNameAsString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

// 0: ObjCProtocolDecl::ReferencedProtocols
::pasta::TokenRange ObjCProtocolDecl::TokenRange(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCProtocolDecl::HasDefinition(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.hasDefinition();
  return val;
}

bool ObjCProtocolDecl::IsNonRuntimeProtocol(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.isNonRuntimeProtocol();
  return val;
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

// 1: ObjCProtocolDecl::LookupClassMethod
// 1: ObjCProtocolDecl::LookupInstanceMethod
// 2: LookupMethod
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
// 0: ObjCProtocolDecl::
std::vector<::pasta::Token> ObjCProtocolDecl::ProtocolLocations(void) const {
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.protocol_locs();
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
  auto &self = *(u.ObjCProtocolDecl);
  auto val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

PragmaCommentDecl::PragmaCommentDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaCommentDecl)
std::string_view PragmaCommentDecl::Arg(void) const {
  auto &self = *(u.PragmaCommentDecl);
  auto val = self.getArg();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

enum PragmaMSCommentKind PragmaCommentDecl::CommentKind(void) const {
  auto &self = *(u.PragmaCommentDecl);
  auto val = self.getCommentKind();
  return static_cast<::pasta::PragmaMSCommentKind>(static_cast<unsigned int>(val));
}

PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, PragmaDetectMismatchDecl)
std::string_view PragmaDetectMismatchDecl::Name(void) const {
  auto &self = *(u.PragmaDetectMismatchDecl);
  auto val = self.getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string_view PragmaDetectMismatchDecl::Value(void) const {
  auto &self = *(u.PragmaDetectMismatchDecl);
  auto val = self.getValue();
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
::pasta::Expr StaticAssertDecl::AssertExpr(void) const {
  auto &self = *(u.StaticAssertDecl);
  auto val = self.getAssertExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "StaticAssertDecl::AssertExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::StringLiteral StaticAssertDecl::Message(void) const {
  auto &self = *(u.StaticAssertDecl);
  auto val = self.getMessage();
  if (val) {
    return StmtBuilder::Create<::pasta::StringLiteral>(ast, val);
  }
  assert(false && "StaticAssertDecl::Message can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token StaticAssertDecl::RParenToken(void) const {
  auto &self = *(u.StaticAssertDecl);
  auto val = self.getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange StaticAssertDecl::TokenRange(void) const {
  auto &self = *(u.StaticAssertDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool StaticAssertDecl::IsFailed(void) const {
  auto &self = *(u.StaticAssertDecl);
  auto val = self.isFailed();
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
::pasta::TokenRange TemplateDecl::TokenRange(void) const {
  auto &self = *(u.TemplateDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: TemplateDecl::TemplateParameters
::pasta::NamedDecl TemplateDecl::TemplatedDecl(void) const {
  auto &self = *(u.TemplateDecl);
  auto val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "TemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool TemplateDecl::HasAssociatedConstraints(void) const {
  auto &self = *(u.TemplateDecl);
  auto val = self.hasAssociatedConstraints();
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
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.defaultArgumentWasInherited();
  return val;
}

// 0: TemplateTemplateParmDecl::DefaultArgStorage
// 0: TemplateTemplateParmDecl::DefaultArgument
::pasta::Token TemplateTemplateParmDecl::DefaultArgumentToken(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: TemplateTemplateParmDecl::ExpansionTemplateParameters
uint32_t TemplateTemplateParmDecl::NumExpansionTemplateParameters(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.getNumExpansionTemplateParameters();
  return val;
}

::pasta::TokenRange TemplateTemplateParmDecl::TokenRange(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool TemplateTemplateParmDecl::HasDefaultArgument(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.hasDefaultArgument();
  return val;
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.isPackExpansion();
  return val;
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const {
  auto &self = *(u.TemplateTemplateParmDecl);
  auto val = self.isParameterPack();
  return val;
}

TranslationUnitDecl::TranslationUnitDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, TranslationUnitDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, TranslationUnitDecl)
// 0: TranslationUnitDecl::ASTContext
::pasta::NamespaceDecl TranslationUnitDecl::AnonymousNamespace(void) const {
  auto &self = *(u.TranslationUnitDecl);
  auto val = self.getAnonymousNamespace();
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
::pasta::Token TypeDecl::BeginToken(void) const {
  auto &self = *(u.TypeDecl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange TypeDecl::TokenRange(void) const {
  auto &self = *(u.TypeDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Type TypeDecl::TypeForDecl(void) const {
  auto &self = *(u.TypeDecl);
  auto val = self.getTypeForDecl();
  if (val) {
    return TypeBuilder::Create<::pasta::Type>(ast, val);
  }
  assert(false && "TypeDecl::TypeForDecl can return nullptr!");
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
::pasta::TagDecl TypedefNameDecl::AnonDeclWithTypedefName(void) const {
  auto &self = *(u.TypedefNameDecl);
  auto val = self.getAnonDeclWithTypedefName();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TypedefNameDecl::AnonDeclWithTypedefName can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypedefNameDecl TypedefNameDecl::CanonicalDecl(void) const {
  auto &self = *(u.TypedefNameDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TypedefNameDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: TypedefNameDecl::TypeSourceInfo
::pasta::Type TypedefNameDecl::UnderlyingType(void) const {
  auto &self = *(u.TypedefNameDecl);
  auto val = self.getUnderlyingType();
  return TypeBuilder::Build(ast, val);
}

bool TypedefNameDecl::IsModed(void) const {
  auto &self = *(u.TypedefNameDecl);
  auto val = self.isModed();
  return val;
}

bool TypedefNameDecl::IsTransparentTag(void) const {
  auto &self = *(u.TypedefNameDecl);
  auto val = self.isTransparentTag();
  return val;
}

UnresolvedUsingTypenameDecl::UnresolvedUsingTypenameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::CanonicalDecl(void) const {
  auto &self = *(u.UnresolvedUsingTypenameDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingTypenameDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingTypenameDecl::EllipsisToken(void) const {
  auto &self = *(u.UnresolvedUsingTypenameDecl);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingTypenameDecl::NameInfo
// 0: UnresolvedUsingTypenameDecl::Qualifier
// 0: UnresolvedUsingTypenameDecl::QualifierToken
::pasta::Token UnresolvedUsingTypenameDecl::TypenameToken(void) const {
  auto &self = *(u.UnresolvedUsingTypenameDecl);
  auto val = self.getTypenameLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedUsingTypenameDecl::UsingToken(void) const {
  auto &self = *(u.UnresolvedUsingTypenameDecl);
  auto val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const {
  auto &self = *(u.UnresolvedUsingTypenameDecl);
  auto val = self.isPackExpansion();
  return val;
}

UsingDecl::UsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDecl)
::pasta::UsingDecl UsingDecl::CanonicalDecl(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  assert(false && "UsingDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDecl::NameInfo
// 0: UsingDecl::Qualifier
// 0: UsingDecl::QualifierToken
::pasta::TokenRange UsingDecl::TokenRange(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token UsingDecl::UsingToken(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UsingDecl::HasTypename(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.hasTypename();
  return val;
}

bool UsingDecl::IsAccessDeclaration(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.isAccessDeclaration();
  return val;
}

// 0: UsingDecl::
// 0: UsingDecl::
// 0: UsingDecl::
std::vector<::pasta::UsingShadowDecl> UsingDecl::Shadows(void) const {
  auto &self = *(u.UsingDecl);
  auto val = self.shadows();
  std::vector<::pasta::UsingShadowDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, decl_ptr));
  }
  return ret;
}

UsingDirectiveDecl::UsingDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingDirectiveDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingDirectiveDecl)
::pasta::DeclContext UsingDirectiveDecl::CommonAncestor(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getCommonAncestor();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "UsingDirectiveDecl::CommonAncestor can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UsingDirectiveDecl::IdentLocation(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getIdentLocation();
  return ast->TokenAt(val);
}

::pasta::Token UsingDirectiveDecl::NamespaceKeyLocation(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getNamespaceKeyLocation();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl UsingDirectiveDecl::NominatedNamespace(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getNominatedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingDirectiveDecl::NominatedNamespaceAsWritten(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getNominatedNamespaceAsWritten();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespaceAsWritten can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDirectiveDecl::Qualifier
// 0: UsingDirectiveDecl::QualifierToken
::pasta::TokenRange UsingDirectiveDecl::TokenRange(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token UsingDirectiveDecl::UsingToken(void) const {
  auto &self = *(u.UsingDirectiveDecl);
  auto val = self.getUsingLoc();
  return ast->TokenAt(val);
}

UsingPackDecl::UsingPackDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingPackDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingPackDecl)
std::vector<::pasta::NamedDecl> UsingPackDecl::Expansions(void) const {
  auto &self = *(u.UsingPackDecl);
  auto val = self.expansions();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::UsingPackDecl UsingPackDecl::CanonicalDecl(void) const {
  auto &self = *(u.UsingPackDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingPackDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingPackDecl::InstantiatedFromUsingDecl(void) const {
  auto &self = *(u.UsingPackDecl);
  auto val = self.getInstantiatedFromUsingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::InstantiatedFromUsingDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange UsingPackDecl::TokenRange(void) const {
  auto &self = *(u.UsingPackDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

UsingShadowDecl::UsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UsingShadowDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
::pasta::UsingShadowDecl UsingShadowDecl::CanonicalDecl(void) const {
  auto &self = *(u.UsingShadowDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::UsingShadowDecl UsingShadowDecl::NextUsingShadowDecl(void) const {
  auto &self = *(u.UsingShadowDecl);
  auto val = self.getNextUsingShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::NextUsingShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingShadowDecl::TargetDecl(void) const {
  auto &self = *(u.UsingShadowDecl);
  auto val = self.getTargetDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::TargetDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::UsingDecl UsingShadowDecl::UsingDecl(void) const {
  auto &self = *(u.UsingShadowDecl);
  auto val = self.getUsingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::UsingDecl can return nullptr!");
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
::pasta::Type ValueDecl::Type(void) const {
  auto &self = *(u.ValueDecl);
  auto val = self.getType();
  return TypeBuilder::Build(ast, val);
}

bool ValueDecl::IsWeak(void) const {
  auto &self = *(u.ValueDecl);
  auto val = self.isWeak();
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
  auto &self = *(u.AccessSpecDecl);
  auto val = self.getAccessSpecifierLoc();
  return ast->TokenAt(val);
}

::pasta::Token AccessSpecDecl::ColonToken(void) const {
  auto &self = *(u.AccessSpecDecl);
  auto val = self.getColonLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange AccessSpecDecl::TokenRange(void) const {
  auto &self = *(u.AccessSpecDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

BindingDecl::BindingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, BindingDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, BindingDecl)
::pasta::Expr BindingDecl::Binding(void) const {
  auto &self = *(u.BindingDecl);
  auto val = self.getBinding();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "BindingDecl::Binding can return nullptr!");
  __builtin_unreachable();
}

::pasta::ValueDecl BindingDecl::DecomposedDecl(void) const {
  auto &self = *(u.BindingDecl);
  auto val = self.getDecomposedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "BindingDecl::DecomposedDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl BindingDecl::HoldingVar(void) const {
  auto &self = *(u.BindingDecl);
  auto val = self.getHoldingVar();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "BindingDecl::HoldingVar can return nullptr!");
  __builtin_unreachable();
}

BlockDecl::BlockDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, BlockDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, BlockDecl)
bool BlockDecl::BlockMissingReturnType(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.blockMissingReturnType();
  return val;
}

bool BlockDecl::CanAvoidCopyToHeap(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.canAvoidCopyToHeap();
  return val;
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::Captures
bool BlockDecl::CapturesCXXThis(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.capturesCXXThis();
  return val;
}

// 1: BlockDecl::CapturesVariable
bool BlockDecl::DoesNotEscape(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.doesNotEscape();
  return val;
}

::pasta::Decl BlockDecl::BlockManglingContextDecl(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getBlockManglingContextDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "BlockDecl::BlockManglingContextDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t BlockDecl::BlockManglingNumber(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getBlockManglingNumber();
  return val;
}

::pasta::Stmt BlockDecl::Body(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "BlockDecl::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token BlockDecl::CaretLocation(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getCaretLocation();
  return ast->TokenAt(val);
}

::pasta::CompoundStmt BlockDecl::CompoundBody(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getCompoundBody();
  if (val) {
    return StmtBuilder::Create<::pasta::CompoundStmt>(ast, val);
  }
  assert(false && "BlockDecl::CompoundBody can return nullptr!");
  __builtin_unreachable();
}

uint32_t BlockDecl::NumCaptures(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getNumCaptures();
  return val;
}

uint32_t BlockDecl::NumParams(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getNumParams();
  return val;
}

// 1: BlockDecl::ParamDecl
// 0: BlockDecl::SignatureAsWritten
::pasta::TokenRange BlockDecl::TokenRange(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool BlockDecl::HasCaptures(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.hasCaptures();
  return val;
}

bool BlockDecl::IsConversionFromLambda(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.isConversionFromLambda();
  return val;
}

bool BlockDecl::IsVariadic(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.isVariadic();
  return val;
}

// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
// 0: BlockDecl::
std::vector<::pasta::ParmVarDecl> BlockDecl::Parameters(void) const {
  auto &self = *(u.BlockDecl);
  auto val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ParmVarDecl> BlockDecl::ParamDecls(void) const {
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
::pasta::TokenRange BuiltinTemplateDecl::TokenRange(void) const {
  auto &self = *(u.BuiltinTemplateDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

CapturedDecl::CapturedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, CapturedDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, CapturedDecl)
::pasta::Stmt CapturedDecl::Body(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.getBody();
  if (val) {
    return StmtBuilder::Create<::pasta::Stmt>(ast, val);
  }
  assert(false && "CapturedDecl::Body can return nullptr!");
  __builtin_unreachable();
}

::pasta::ImplicitParamDecl CapturedDecl::ContextParam(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.getContextParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "CapturedDecl::ContextParam can return nullptr!");
  __builtin_unreachable();
}

uint32_t CapturedDecl::ContextParamPosition(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.getContextParamPosition();
  return val;
}

uint32_t CapturedDecl::NumParams(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.getNumParams();
  return val;
}

// 1: CapturedDecl::Param
bool CapturedDecl::IsNothrow(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.isNothrow();
  return val;
}

// 0: CapturedDecl::
// 0: CapturedDecl::
std::vector<::pasta::ImplicitParamDecl> CapturedDecl::Parameters(void) const {
  auto &self = *(u.CapturedDecl);
  auto val = self.parameters();
  std::vector<::pasta::ImplicitParamDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ImplicitParamDecl> CapturedDecl::Params(void) const {
  auto convert_elem = [&] (clang::ImplicitParamDecl * val) {
    if (val) {
      return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
    }
    __builtin_unreachable();
  };
  std::vector<::pasta::ImplicitParamDecl> ret;
  auto count = u.CapturedDecl->getNumParams();
  decltype(count) i = 0;
  for (; i < count; ++i) {
    ret.emplace_back(convert_elem(u.CapturedDecl->getParam(i)));
  }
  return ret;
}

ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
::pasta::CXXMethodDecl ClassScopeFunctionSpecializationDecl::Specialization(void) const {
  auto &self = *(u.ClassScopeFunctionSpecializationDecl);
  auto val = self.getSpecialization();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "ClassScopeFunctionSpecializationDecl::Specialization can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassScopeFunctionSpecializationDecl::TemplateArgsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArgs(void) const {
  auto &self = *(u.ClassScopeFunctionSpecializationDecl);
  auto val = self.hasExplicitTemplateArgs();
  return val;
}

ConceptDecl::ConceptDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ConceptDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, ConceptDecl)
::pasta::ConceptDecl ConceptDecl::CanonicalDecl(void) const {
  auto &self = *(u.ConceptDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  assert(false && "ConceptDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr ConceptDecl::ConstraintExpr(void) const {
  auto &self = *(u.ConceptDecl);
  auto val = self.getConstraintExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ConceptDecl::ConstraintExpr can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange ConceptDecl::TokenRange(void) const {
  auto &self = *(u.ConceptDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ConceptDecl::IsTypeConcept(void) const {
  auto &self = *(u.ConceptDecl);
  auto val = self.isTypeConcept();
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
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.constructsVirtualBase();
  return val;
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::ConstructedBaseClass(void) const {
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.getConstructedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::ConstructedBaseClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::ConstructorUsingShadowDecl ConstructorUsingShadowDecl::ConstructedBaseClassShadowDecl(void) const {
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.getConstructedBaseClassShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::ConstructedBaseClassShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::NominatedBaseClass(void) const {
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.getNominatedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::NominatedBaseClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::ConstructorUsingShadowDecl ConstructorUsingShadowDecl::NominatedBaseClassShadowDecl(void) const {
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.getNominatedBaseClassShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::NominatedBaseClassShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::Parent(void) const {
  auto &self = *(u.ConstructorUsingShadowDecl);
  auto val = self.getParent();
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
::pasta::Token DeclaratorDecl::BeginToken(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::InnerLocStart(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

uint32_t DeclaratorDecl::NumTemplateParameterLists(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token DeclaratorDecl::OuterLocStart(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: DeclaratorDecl::Qualifier
// 0: DeclaratorDecl::QualifierToken
::pasta::TokenRange DeclaratorDecl::TokenRange(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 1: DeclaratorDecl::TemplateParameterList
::pasta::Expr DeclaratorDecl::TrailingRequiresClause(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getTrailingRequiresClause();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "DeclaratorDecl::TrailingRequiresClause can return nullptr!");
  __builtin_unreachable();
}

// 0: DeclaratorDecl::TypeSourceInfo
::pasta::Token DeclaratorDecl::TypeSpecEndToken(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getTypeSpecEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::TypeSpecStartToken(void) const {
  auto &self = *(u.DeclaratorDecl);
  auto val = self.getTypeSpecStartLoc();
  return ast->TokenAt(val);
}

EnumConstantDecl::EnumConstantDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, EnumConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, EnumConstantDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, EnumConstantDecl)
::pasta::EnumConstantDecl EnumConstantDecl::CanonicalDecl(void) const {
  auto &self = *(u.EnumConstantDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, val);
  }
  assert(false && "EnumConstantDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr EnumConstantDecl::InitExpr(void) const {
  auto &self = *(u.EnumConstantDecl);
  auto val = self.getInitExpr();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "EnumConstantDecl::InitExpr can return nullptr!");
  __builtin_unreachable();
}

// 0: EnumConstantDecl::InitVal
::pasta::TokenRange EnumConstantDecl::TokenRange(void) const {
  auto &self = *(u.EnumConstantDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
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
::pasta::Expr FieldDecl::BitWidth(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getBitWidth();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "FieldDecl::BitWidth can return nullptr!");
  __builtin_unreachable();
}

uint32_t FieldDecl::BitWidthValue(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getBitWidthValue(ast->ci->getASTContext());
  return val;
}

::pasta::FieldDecl FieldDecl::CanonicalDecl(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "FieldDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VariableArrayType FieldDecl::CapturedVLAType(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getCapturedVLAType();
  if (val) {
    return TypeBuilder::Create<::pasta::VariableArrayType>(ast, val);
  }
  assert(false && "FieldDecl::CapturedVLAType can return nullptr!");
  __builtin_unreachable();
}

uint32_t FieldDecl::FieldIndex(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getFieldIndex();
  return val;
}

enum InClassInitStyle FieldDecl::InClassInitStyle(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getInClassInitStyle();
  return static_cast<::pasta::InClassInitStyle>(static_cast<unsigned int>(val));
}

::pasta::Expr FieldDecl::InClassInitializer(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getInClassInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "FieldDecl::InClassInitializer can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl FieldDecl::Parent(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "FieldDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange FieldDecl::TokenRange(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool FieldDecl::HasCapturedVLAType(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.hasCapturedVLAType();
  return val;
}

bool FieldDecl::HasInClassInitializer(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.hasInClassInitializer();
  return val;
}

bool FieldDecl::IsAnonymousStructOrUnion(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isAnonymousStructOrUnion();
  return val;
}

bool FieldDecl::IsBitField(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isBitField();
  return val;
}

bool FieldDecl::IsMutable(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isMutable();
  return val;
}

bool FieldDecl::IsUnnamedBitfield(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isUnnamedBitfield();
  return val;
}

bool FieldDecl::IsZeroLengthBitField(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isZeroLengthBitField(ast->ci->getASTContext());
  return val;
}

bool FieldDecl::IsZeroSize(void) const {
  auto &self = *(u.FieldDecl);
  auto val = self.isZeroSize(ast->ci->getASTContext());
  return val;
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
bool FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.doesDeclarationForceExternallyVisibleDefinition();
  return val;
}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.doesThisDeclarationHaveABody();
  return val;
}

uint32_t FunctionDecl::BuiltinID(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getBuiltinID();
  return val;
}

::pasta::Type FunctionDecl::CallResultType(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getCallResultType();
  return TypeBuilder::Build(ast, val);
}

::pasta::FunctionDecl FunctionDecl::CanonicalDecl(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

enum ConstexprSpecKind FunctionDecl::ConstexprKind(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getConstexprKind();
  return static_cast<::pasta::ConstexprSpecKind>(static_cast<int>(val));
}

::pasta::Type FunctionDecl::DeclaredReturnType(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getDeclaredReturnType();
  return TypeBuilder::Build(ast, val);
}

// 0: FunctionDecl::DefaultedFunctionInfo
::pasta::FunctionDecl FunctionDecl::Definition(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

// 0: FunctionDecl::DependentSpecializationInfo
::pasta::FunctionTemplateDecl FunctionDecl::DescribedFunctionTemplate(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getDescribedFunctionTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionDecl::DescribedFunctionTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FunctionDecl::EllipsisToken(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange FunctionDecl::ExceptionSpecSourceRange(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getExceptionSpecSourceRange();
  return ast->TokenRangeFrom(val);
}

enum ExceptionSpecificationType FunctionDecl::ExceptionSpecType(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(static_cast<unsigned int>(val));
}

// 0: FunctionDecl::FunctionTypeToken
::pasta::FunctionDecl FunctionDecl::InstantiatedFromMemberFunction(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getInstantiatedFromMemberFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::InstantiatedFromMemberFunction can return nullptr!");
  __builtin_unreachable();
}

enum LanguageLinkage FunctionDecl::LanguageLinkage(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(static_cast<unsigned int>(val));
}

// 0: FunctionDecl::LiteralIdentifier
// 0: FunctionDecl::MemberSpecializationInfo
uint32_t FunctionDecl::MemoryFunctionKind(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getMemoryFunctionKind();
  return val;
}

uint32_t FunctionDecl::MinRequiredArguments(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getMinRequiredArguments();
  return val;
}

enum MultiVersionKind FunctionDecl::MultiVersionKind(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getMultiVersionKind();
  return static_cast<::pasta::MultiVersionKind>(static_cast<int>(val));
}

// 0: FunctionDecl::NameInfo
uint32_t FunctionDecl::NumParams(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getNumParams();
  return val;
}

uint32_t FunctionDecl::ODRHash(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getODRHash();
  return val;
}

enum OverloadedOperatorKind FunctionDecl::OverloadedOperator(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getOverloadedOperator();
  return static_cast<::pasta::OverloadedOperatorKind>(static_cast<int>(val));
}

// 1: FunctionDecl::ParamDecl
::pasta::TokenRange FunctionDecl::ParametersSourceRange(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getParametersSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token FunctionDecl::PointOfInstantiation(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

::pasta::FunctionTemplateDecl FunctionDecl::PrimaryTemplate(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getPrimaryTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionDecl::PrimaryTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type FunctionDecl::ReturnType(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getReturnType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange FunctionDecl::ReturnTypeSourceRange(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getReturnTypeSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TokenRange FunctionDecl::TokenRange(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

enum StorageClass FunctionDecl::StorageClass(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(static_cast<unsigned int>(val));
}

::pasta::FunctionDecl FunctionDecl::TemplateInstantiationPattern(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::TemplateInstantiationPattern can return nullptr!");
  __builtin_unreachable();
}

// 0: FunctionDecl::TemplateSpecializationArgs
// 0: FunctionDecl::TemplateSpecializationArgsAsWritten
// 0: FunctionDecl::TemplateSpecializationInfo
enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKind(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

enum TemplateSpecializationKind FunctionDecl::TemplateSpecializationKindForInstantiation(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

// 0: FunctionDecl::TemplatedKind
bool FunctionDecl::HasImplicitReturnZero(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasImplicitReturnZero();
  return val;
}

bool FunctionDecl::HasInheritedPrototype(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasInheritedPrototype();
  return val;
}

bool FunctionDecl::HasOneParamOrDefaultArgs(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasOneParamOrDefaultArgs();
  return val;
}

bool FunctionDecl::HasPrototype(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasPrototype();
  return val;
}

bool FunctionDecl::HasSkippedBody(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasSkippedBody();
  return val;
}

bool FunctionDecl::HasTrivialBody(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasTrivialBody();
  return val;
}

bool FunctionDecl::HasWrittenPrototype(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.hasWrittenPrototype();
  return val;
}

bool FunctionDecl::InstantiationIsPending(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.instantiationIsPending();
  return val;
}

bool FunctionDecl::IsCPUDispatchMultiVersion(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isCPUDispatchMultiVersion();
  return val;
}

bool FunctionDecl::IsCPUSpecificMultiVersion(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isCPUSpecificMultiVersion();
  return val;
}

bool FunctionDecl::IsConsteval(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isConsteval();
  return val;
}

bool FunctionDecl::IsConstexpr(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isConstexpr();
  return val;
}

bool FunctionDecl::IsConstexprSpecified(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isConstexprSpecified();
  return val;
}

bool FunctionDecl::IsDefaulted(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isDefaulted();
  return val;
}

bool FunctionDecl::IsDeleted(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isDeleted();
  return val;
}

bool FunctionDecl::IsDeletedAsWritten(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isDeletedAsWritten();
  return val;
}

bool FunctionDecl::IsDestroyingOperatorDelete(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isDestroyingOperatorDelete();
  return val;
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isExplicitlyDefaulted();
  return val;
}

bool FunctionDecl::IsExternC(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isExternC();
  return val;
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isFunctionTemplateSpecialization();
  return val;
}

bool FunctionDecl::IsGlobal(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isGlobal();
  return val;
}

bool FunctionDecl::IsImplicitlyInstantiable(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isImplicitlyInstantiable();
  return val;
}

bool FunctionDecl::IsInExternCContext(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInExternCContext();
  return val;
}

bool FunctionDecl::IsInExternCXXContext(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInExternCXXContext();
  return val;
}

bool FunctionDecl::IsInlineBuiltinDeclaration(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInlineBuiltinDeclaration();
  return val;
}

bool FunctionDecl::IsInlineDefinitionExternallyVisible(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInlineDefinitionExternallyVisible();
  return val;
}

bool FunctionDecl::IsInlineSpecified(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInlineSpecified();
  return val;
}

bool FunctionDecl::IsInlined(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isInlined();
  return val;
}

bool FunctionDecl::IsLateTemplateParsed(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isLateTemplateParsed();
  return val;
}

bool FunctionDecl::IsMSExternInline(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isMSExternInline();
  return val;
}

bool FunctionDecl::IsMSVCRTEntryPoint(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isMSVCRTEntryPoint();
  return val;
}

bool FunctionDecl::IsMain(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isMain();
  return val;
}

bool FunctionDecl::IsMultiVersion(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isMultiVersion();
  return val;
}

bool FunctionDecl::IsNoReturn(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isNoReturn();
  return val;
}

bool FunctionDecl::IsOutOfLine(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isOutOfLine();
  return val;
}

bool FunctionDecl::IsOverloadedOperator(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isOverloadedOperator();
  return val;
}

bool FunctionDecl::IsPure(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isPure();
  return val;
}

bool FunctionDecl::IsReplaceableGlobalAllocationFunction(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isReplaceableGlobalAllocationFunction();
  return val;
}

bool FunctionDecl::IsReservedGlobalPlacementOperator(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isReservedGlobalPlacementOperator();
  return val;
}

bool FunctionDecl::IsStatic(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isStatic();
  return val;
}

bool FunctionDecl::IsTargetMultiVersion(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isTargetMultiVersion();
  return val;
}

bool FunctionDecl::IsTemplateInstantiation(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isTemplateInstantiation();
  return val;
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

bool FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isThisDeclarationInstantiatedFromAFriendDefinition();
  return val;
}

bool FunctionDecl::IsTrivial(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isTrivial();
  return val;
}

bool FunctionDecl::IsTrivialForCall(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isTrivialForCall();
  return val;
}

bool FunctionDecl::IsUserProvided(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isUserProvided();
  return val;
}

bool FunctionDecl::IsVariadic(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isVariadic();
  return val;
}

bool FunctionDecl::IsVirtualAsWritten(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.isVirtualAsWritten();
  return val;
}

// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
// 0: FunctionDecl::
std::vector<::pasta::ParmVarDecl> FunctionDecl::Parameters(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

bool FunctionDecl::UsesSEHTry(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.usesSEHTry();
  return val;
}

bool FunctionDecl::WillHaveBody(void) const {
  auto &self = *(u.FunctionDecl);
  auto val = self.willHaveBody();
  return val;
}

std::vector<::pasta::ParmVarDecl> FunctionDecl::ParamDecls(void) const {
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

IndirectFieldDecl::IndirectFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, IndirectFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, IndirectFieldDecl)
std::vector<::pasta::NamedDecl> IndirectFieldDecl::Chain(void) const {
  auto &self = *(u.IndirectFieldDecl);
  auto val = self.chain();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: IndirectFieldDecl::
// 0: IndirectFieldDecl::
::pasta::FieldDecl IndirectFieldDecl::AnonField(void) const {
  auto &self = *(u.IndirectFieldDecl);
  auto val = self.getAnonField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::AnonField can return nullptr!");
  __builtin_unreachable();
}

::pasta::IndirectFieldDecl IndirectFieldDecl::CanonicalDecl(void) const {
  auto &self = *(u.IndirectFieldDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::IndirectFieldDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t IndirectFieldDecl::ChainingSize(void) const {
  auto &self = *(u.IndirectFieldDecl);
  auto val = self.getChainingSize();
  return val;
}

::pasta::VarDecl IndirectFieldDecl::VarDecl(void) const {
  auto &self = *(u.IndirectFieldDecl);
  auto val = self.getVarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::VarDecl can return nullptr!");
  __builtin_unreachable();
}

LabelDecl::LabelDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, LabelDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, LabelDecl)
std::string_view LabelDecl::MSAsmLabel(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.getMSAsmLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::TokenRange LabelDecl::TokenRange(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::LabelStmt LabelDecl::Stmt(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.getStmt();
  if (val) {
    return StmtBuilder::Create<::pasta::LabelStmt>(ast, val);
  }
  assert(false && "LabelDecl::Stmt can return nullptr!");
  __builtin_unreachable();
}

bool LabelDecl::IsGnuLocal(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.isGnuLocal();
  return val;
}

bool LabelDecl::IsMSAsmLabel(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.isMSAsmLabel();
  return val;
}

bool LabelDecl::IsResolvedMSAsmLabel(void) const {
  auto &self = *(u.LabelDecl);
  auto val = self.isResolvedMSAsmLabel();
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
  auto &self = *(u.MSPropertyDecl);
  auto val = self.hasGetter();
  return val;
}

bool MSPropertyDecl::HasSetter(void) const {
  auto &self = *(u.MSPropertyDecl);
  auto val = self.hasSetter();
  return val;
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
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.defaultArgumentWasInherited();
  return val;
}

// 0: NonTypeTemplateParmDecl::DefaultArgStorage
::pasta::Expr NonTypeTemplateParmDecl::DefaultArgument(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.getDefaultArgument();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "NonTypeTemplateParmDecl::DefaultArgument can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NonTypeTemplateParmDecl::DefaultArgumentToken(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

// 1: NonTypeTemplateParmDecl::ExpansionType
// 1: NonTypeTemplateParmDecl::ExpansionTypeSourceInfo
uint32_t NonTypeTemplateParmDecl::NumExpansionTypes(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.getNumExpansionTypes();
  return val;
}

::pasta::Expr NonTypeTemplateParmDecl::PlaceholderTypeConstraint(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.getPlaceholderTypeConstraint();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "NonTypeTemplateParmDecl::PlaceholderTypeConstraint can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange NonTypeTemplateParmDecl::TokenRange(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.hasDefaultArgument();
  return val;
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.hasPlaceholderTypeConstraint();
  return val;
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.isExpandedParameterPack();
  return val;
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.isPackExpansion();
  return val;
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const {
  auto &self = *(u.NonTypeTemplateParmDecl);
  auto val = self.isParameterPack();
  return val;
}

std::vector<::pasta::Type> NonTypeTemplateParmDecl::ExpansionTypes(void) const {
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
// 0: OMPAllocateDecl::Varlists
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
::pasta::Expr OMPDeclareMapperDecl::MapperVarRef(void) const {
  auto &self = *(u.OMPDeclareMapperDecl);
  auto val = self.getMapperVarRef();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareMapperDecl::MapperVarRef can return nullptr!");
  __builtin_unreachable();
}

::pasta::OMPDeclareMapperDecl OMPDeclareMapperDecl::PrevDeclInScope(void) const {
  auto &self = *(u.OMPDeclareMapperDecl);
  auto val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareMapperDecl>(ast, val);
  }
  assert(false && "OMPDeclareMapperDecl::PrevDeclInScope can return nullptr!");
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
::pasta::Expr OMPDeclareReductionDecl::Combiner(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getCombiner();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::Combiner can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::CombinerIn(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getCombinerIn();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::CombinerIn can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::CombinerOut(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getCombinerOut();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::CombinerOut can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::InitOrig(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getInitOrig();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::InitOrig can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::InitPriv(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getInitPriv();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::InitPriv can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr OMPDeclareReductionDecl::Initializer(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getInitializer();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::Initializer can return nullptr!");
  __builtin_unreachable();
}

// 0: OMPDeclareReductionDecl::InitializerKind
::pasta::OMPDeclareReductionDecl OMPDeclareReductionDecl::PrevDeclInScope(void) const {
  auto &self = *(u.OMPDeclareReductionDecl);
  auto val = self.getPrevDeclInScope();
  if (val) {
    return DeclBuilder::Create<::pasta::OMPDeclareReductionDecl>(ast, val);
  }
  assert(false && "OMPDeclareReductionDecl::PrevDeclInScope can return nullptr!");
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
// 0: OMPThreadPrivateDecl::Varlists
ObjCAtDefsFieldDecl::ObjCAtDefsFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
ObjCCategoryDecl::ObjCCategoryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(DeclContext, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCCategoryDecl)
PASTA_DEFINE_BASE_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
bool ObjCCategoryDecl::IsClassExtension(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.IsClassExtension();
  return val;
}

::pasta::Token ObjCCategoryDecl::CategoryNameToken(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getCategoryNameLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCInterfaceDecl ObjCCategoryDecl::ClassInterface(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryImplDecl ObjCCategoryDecl::Implementation(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getImplementation();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryImplDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::Implementation can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryDecl::IvarLBraceToken(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCCategoryDecl::IvarRBraceToken(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getIvarRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategory(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getNextClassCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategory can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategoryRaw(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.getNextClassCategoryRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategoryRaw can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCCategoryDecl::ReferencedProtocols
// 0: ObjCCategoryDecl::TypeParamList
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::ObjCIvarDecl> ObjCCategoryDecl::InstanceVariables(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
  }
  return ret;
}

// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
// 0: ObjCCategoryDecl::
std::vector<::pasta::Token> ObjCCategoryDecl::ProtocolLocations(void) const {
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.protocol_locs();
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
  auto &self = *(u.ObjCCategoryDecl);
  auto val = self.protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
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
::pasta::ObjCCategoryDecl ObjCCategoryImplDecl::CategoryDecl(void) const {
  auto &self = *(u.ObjCCategoryImplDecl);
  auto val = self.getCategoryDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryImplDecl::CategoryDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryImplDecl::CategoryNameToken(void) const {
  auto &self = *(u.ObjCCategoryImplDecl);
  auto val = self.getCategoryNameLoc();
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
// 0: ObjCIvarDecl::AccessControl
// 0: ObjCIvarDecl::CanonicalAccessControl
::pasta::ObjCInterfaceDecl ObjCIvarDecl::ContainingInterface(void) const {
  auto &self = *(u.ObjCIvarDecl);
  auto val = self.getContainingInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::ContainingInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCIvarDecl ObjCIvarDecl::NextIvar(void) const {
  auto &self = *(u.ObjCIvarDecl);
  auto val = self.getNextIvar();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::NextIvar can return nullptr!");
  __builtin_unreachable();
}

bool ObjCIvarDecl::Synthesize(void) const {
  auto &self = *(u.ObjCIvarDecl);
  auto val = self.getSynthesize();
  return val;
}

// 1: ObjCIvarDecl::UsageType
ObjCTypeParamDecl::ObjCTypeParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(TypeDecl, ObjCTypeParamDecl)
PASTA_DEFINE_BASE_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
::pasta::Token ObjCTypeParamDecl::ColonToken(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.getColonLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCTypeParamDecl::Index(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.getIndex();
  return val;
}

::pasta::TokenRange ObjCTypeParamDecl::TokenRange(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

enum ObjCTypeParamVariance ObjCTypeParamDecl::Variance(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.getVariance();
  return static_cast<::pasta::ObjCTypeParamVariance>(static_cast<unsigned char>(val));
}

::pasta::Token ObjCTypeParamDecl::VarianceToken(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.getVarianceLoc();
  return ast->TokenAt(val);
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const {
  auto &self = *(u.ObjCTypeParamDecl);
  auto val = self.hasExplicitBound();
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
::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::CanonicalDecl(void) const {
  auto &self = *(u.RedeclarableTemplateDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.RedeclarableTemplateDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const {
  auto &self = *(u.RedeclarableTemplateDecl);
  auto val = self.isMemberSpecialization();
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
  auto &self = *(u.TagDecl);
  auto val = self.getBraceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TagDecl TagDecl::CanonicalDecl(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TagDecl TagDecl::Definition(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token TagDecl::InnerLocStart(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getInnerLocStart();
  return ast->TokenAt(val);
}

std::string_view TagDecl::KindName(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t TagDecl::NumTemplateParameterLists(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getNumTemplateParameterLists();
  return val;
}

::pasta::Token TagDecl::OuterLocStart(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getOuterLocStart();
  return ast->TokenAt(val);
}

// 0: TagDecl::Qualifier
// 0: TagDecl::QualifierToken
::pasta::TokenRange TagDecl::TokenRange(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

enum TagTypeKind TagDecl::TagKind(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getTagKind();
  return static_cast<::pasta::TagTypeKind>(static_cast<unsigned int>(val));
}

// 1: TagDecl::TemplateParameterList
::pasta::TypedefNameDecl TagDecl::TypedefNameForAnonDecl(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.getTypedefNameForAnonDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TagDecl::TypedefNameForAnonDecl can return nullptr!");
  __builtin_unreachable();
}

bool TagDecl::HasNameForLinkage(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.hasNameForLinkage();
  return val;
}

bool TagDecl::IsBeingDefined(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isBeingDefined();
  return val;
}

bool TagDecl::IsClass(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isClass();
  return val;
}

bool TagDecl::IsCompleteDefinition(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isCompleteDefinition();
  return val;
}

bool TagDecl::IsCompleteDefinitionRequired(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isCompleteDefinitionRequired();
  return val;
}

bool TagDecl::IsDependentType(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isDependentType();
  return val;
}

bool TagDecl::IsEmbeddedInDeclarator(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isEmbeddedInDeclarator();
  return val;
}

bool TagDecl::IsEnum(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isEnum();
  return val;
}

bool TagDecl::IsFreeStanding(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isFreeStanding();
  return val;
}

bool TagDecl::IsInterface(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isInterface();
  return val;
}

bool TagDecl::IsStruct(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isStruct();
  return val;
}

bool TagDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

bool TagDecl::IsUnion(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.isUnion();
  return val;
}

bool TagDecl::MayHaveOutOfDateDef(void) const {
  auto &self = *(u.TagDecl);
  auto val = self.mayHaveOutOfDateDef();
  return val;
}

TemplateParamObjectDecl::TemplateParamObjectDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TemplateParamObjectDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TemplateParamObjectDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, TemplateParamObjectDecl)
::pasta::TemplateParamObjectDecl TemplateParamObjectDecl::CanonicalDecl(void) const {
  auto &self = *(u.TemplateParamObjectDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateParamObjectDecl>(ast, val);
  }
  assert(false && "TemplateParamObjectDecl::CanonicalDecl can return nullptr!");
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
bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.defaultArgumentWasInherited();
  return val;
}

// 0: TemplateTypeParmDecl::DefaultArgStorage
::pasta::Type TemplateTypeParmDecl::DefaultArgument(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getDefaultArgument();
  return TypeBuilder::Build(ast, val);
}

// 0: TemplateTypeParmDecl::DefaultArgumentInfo
::pasta::Token TemplateTypeParmDecl::DefaultArgumentToken(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getDefaultArgumentLoc();
  return ast->TokenAt(val);
}

uint32_t TemplateTypeParmDecl::Depth(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getDepth();
  return val;
}

uint32_t TemplateTypeParmDecl::Index(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getIndex();
  return val;
}

uint32_t TemplateTypeParmDecl::NumExpansionParameters(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getNumExpansionParameters();
  return val;
}

::pasta::TokenRange TemplateTypeParmDecl::TokenRange(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: TemplateTypeParmDecl::TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.hasDefaultArgument();
  return val;
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.hasTypeConstraint();
  return val;
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.isExpandedParameterPack();
  return val;
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.isPackExpansion();
  return val;
}

bool TemplateTypeParmDecl::IsParameterPack(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.isParameterPack();
  return val;
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const {
  auto &self = *(u.TemplateTypeParmDecl);
  auto val = self.wasDeclaredWithTypename();
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
::pasta::TypeAliasTemplateDecl TypeAliasDecl::DescribedAliasTemplate(void) const {
  auto &self = *(u.TypeAliasDecl);
  auto val = self.getDescribedAliasTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasDecl::DescribedAliasTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange TypeAliasDecl::TokenRange(void) const {
  auto &self = *(u.TypeAliasDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::CanonicalDecl(void) const {
  auto &self = *(u.TypeAliasTemplateDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.TypeAliasTemplateDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::PreviousDecl(void) const {
  auto &self = *(u.TypeAliasTemplateDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasDecl TypeAliasTemplateDecl::TemplatedDecl(void) const {
  auto &self = *(u.TypeAliasTemplateDecl);
  auto val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::TemplatedDecl can return nullptr!");
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
::pasta::TokenRange TypedefDecl::TokenRange(void) const {
  auto &self = *(u.TypedefDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

UnresolvedUsingValueDecl::UnresolvedUsingValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, UnresolvedUsingValueDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_BASE_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
::pasta::UnresolvedUsingValueDecl UnresolvedUsingValueDecl::CanonicalDecl(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingValueDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingValueDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingValueDecl::EllipsisToken(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingValueDecl::NameInfo
// 0: UnresolvedUsingValueDecl::Qualifier
// 0: UnresolvedUsingValueDecl::QualifierToken
::pasta::TokenRange UnresolvedUsingValueDecl::TokenRange(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token UnresolvedUsingValueDecl::UsingToken(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.isAccessDeclaration();
  return val;
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const {
  auto &self = *(u.UnresolvedUsingValueDecl);
  auto val = self.isPackExpansion();
  return val;
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
// 0: VarDecl::EnsureEvaluatedStmt
// 1: VarDecl::EvaluateDestruction
// 0: VarDecl::EvaluateValue
::pasta::VarDecl VarDecl::ActingDefinition(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getActingDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::ActingDefinition can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl VarDecl::CanonicalDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarDecl::DescribedVarTemplate(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getDescribedVarTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarDecl::DescribedVarTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: VarDecl::EvaluatedStmt
// 0: VarDecl::EvaluatedValue
::pasta::Expr VarDecl::Init(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getInit();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "VarDecl::Init can return nullptr!");
  __builtin_unreachable();
}

// 0: VarDecl::InitStyle
::pasta::VarDecl VarDecl::InitializingDeclaration(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getInitializingDeclaration();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::InitializingDeclaration can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl VarDecl::InstantiatedFromStaticDataMember(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getInstantiatedFromStaticDataMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::InstantiatedFromStaticDataMember can return nullptr!");
  __builtin_unreachable();
}

enum LanguageLinkage VarDecl::LanguageLinkage(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getLanguageLinkage();
  return static_cast<::pasta::LanguageLinkage>(static_cast<unsigned int>(val));
}

// 0: VarDecl::MemberSpecializationInfo
::pasta::Token VarDecl::PointOfInstantiation(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

::pasta::TokenRange VarDecl::TokenRange(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

enum StorageClass VarDecl::StorageClass(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getStorageClass();
  return static_cast<::pasta::StorageClass>(static_cast<unsigned int>(val));
}

enum StorageDuration VarDecl::StorageDuration(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getStorageDuration();
  return static_cast<::pasta::StorageDuration>(static_cast<unsigned int>(val));
}

// 0: VarDecl::TLSKind
enum ThreadStorageClassSpecifier VarDecl::TSCSpec(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getTSCSpec();
  return static_cast<::pasta::ThreadStorageClassSpecifier>(static_cast<unsigned int>(val));
}

::pasta::VarDecl VarDecl::TemplateInstantiationPattern(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::TemplateInstantiationPattern can return nullptr!");
  __builtin_unreachable();
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKind(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

enum TemplateSpecializationKind VarDecl::TemplateSpecializationKindForInstantiation(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.getTemplateSpecializationKindForInstantiation();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

bool VarDecl::HasConstantInitialization(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasConstantInitialization();
  return val;
}

bool VarDecl::HasExternalStorage(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasExternalStorage();
  return val;
}

bool VarDecl::HasGlobalStorage(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasGlobalStorage();
  return val;
}

bool VarDecl::HasICEInitializer(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasICEInitializer(ast->ci->getASTContext());
  return val;
}

bool VarDecl::HasInit(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasInit();
  return val;
}

bool VarDecl::HasLocalStorage(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.hasLocalStorage();
  return val;
}

bool VarDecl::IsARCPseudoStrong(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isARCPseudoStrong();
  return val;
}

bool VarDecl::IsCXXForRangeDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isCXXForRangeDecl();
  return val;
}

bool VarDecl::IsConstexpr(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isConstexpr();
  return val;
}

bool VarDecl::IsDirectInit(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isDirectInit();
  return val;
}

bool VarDecl::IsEscapingByref(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isEscapingByref();
  return val;
}

bool VarDecl::IsExceptionVariable(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isExceptionVariable();
  return val;
}

bool VarDecl::IsExternC(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isExternC();
  return val;
}

bool VarDecl::IsFileVarDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isFileVarDecl();
  return val;
}

bool VarDecl::IsFunctionOrMethodVarDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isFunctionOrMethodVarDecl();
  return val;
}

bool VarDecl::IsInExternCContext(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isInExternCContext();
  return val;
}

bool VarDecl::IsInExternCXXContext(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isInExternCXXContext();
  return val;
}

bool VarDecl::IsInitCapture(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isInitCapture();
  return val;
}

bool VarDecl::IsInline(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isInline();
  return val;
}

bool VarDecl::IsInlineSpecified(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isInlineSpecified();
  return val;
}

bool VarDecl::IsKnownToBeDefined(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isKnownToBeDefined();
  return val;
}

bool VarDecl::IsLocalVarDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isLocalVarDecl();
  return val;
}

bool VarDecl::IsLocalVarDeclOrParm(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isLocalVarDeclOrParm();
  return val;
}

bool VarDecl::IsNRVOVariable(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isNRVOVariable();
  return val;
}

bool VarDecl::IsNoDestroy(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isNoDestroy(ast->ci->getASTContext());
  return val;
}

bool VarDecl::IsNonEscapingByref(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isNonEscapingByref();
  return val;
}

bool VarDecl::IsObjCForDecl(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isObjCForDecl();
  return val;
}

bool VarDecl::IsOutOfLine(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isOutOfLine();
  return val;
}

bool VarDecl::IsParameterPack(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isParameterPack();
  return val;
}

bool VarDecl::IsPreviousDeclInSameBlockScope(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isPreviousDeclInSameBlockScope();
  return val;
}

bool VarDecl::IsStaticDataMember(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isStaticDataMember();
  return val;
}

bool VarDecl::IsStaticLocal(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isStaticLocal();
  return val;
}

bool VarDecl::IsThisDeclarationADemotedDefinition(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isThisDeclarationADemotedDefinition();
  return val;
}

bool VarDecl::IsUsableInConstantExpressions(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.isUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

bool VarDecl::MightBeUsableInConstantExpressions(void) const {
  auto &self = *(u.VarDecl);
  auto val = self.mightBeUsableInConstantExpressions(ast->ci->getASTContext());
  return val;
}

// 1: VarDecl::NeedsDestruction
VarTemplateDecl::VarTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, VarTemplateDecl)
::pasta::VarTemplateDecl VarTemplateDecl::CanonicalDecl(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::MostRecentDecl(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::PreviousDecl(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl VarTemplateDecl::TemplatedDecl(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

// 0: VarTemplateDecl::
// 0: VarTemplateDecl::
std::vector<::pasta::VarTemplateSpecializationDecl> VarTemplateDecl::Specializations(void) const {
  auto &self = *(u.VarTemplateDecl);
  auto val = self.specializations();
  std::vector<::pasta::VarTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::VarTemplateSpecializationDecl>(ast, decl_ptr));
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
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getInstantiatedFrom();
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
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

enum TemplateSpecializationKind VarTemplateSpecializationDecl::SpecializationKind(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

::pasta::VarTemplateDecl VarTemplateSpecializationDecl::SpecializedTemplate(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getSpecializedTemplateOrPartial();
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

// 0: VarTemplateSpecializationDecl::TemplateArgs
// 0: VarTemplateSpecializationDecl::TemplateArgsInfo
// 0: VarTemplateSpecializationDecl::TemplateInstantiationArgs
::pasta::Token VarTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

// 0: VarTemplateSpecializationDecl::TypeAsWritten
bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto &self = *(u.VarTemplateSpecializationDecl);
  auto val = self.isExplicitSpecialization();
  return val;
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
::pasta::TemplateDecl CXXDeductionGuideDecl::DeducedTemplate(void) const {
  auto &self = *(u.CXXDeductionGuideDecl);
  auto val = self.getDeducedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  assert(false && "CXXDeductionGuideDecl::DeducedTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXDeductionGuideDecl::ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const {
  auto &self = *(u.CXXDeductionGuideDecl);
  auto val = self.isCopyDeductionCandidate();
  return val;
}

bool CXXDeductionGuideDecl::IsExplicit(void) const {
  auto &self = *(u.CXXDeductionGuideDecl);
  auto val = self.isExplicit();
  return val;
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
::pasta::CXXMethodDecl CXXMethodDecl::CanonicalDecl(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 1: CXXMethodDecl::CorrespondingMethodDeclaredInClass
// 1: CXXMethodDecl::CorrespondingMethodInClass
// 2: DevirtualizedMethod
// 0: CXXMethodDecl::MethodQualifiers
::pasta::CXXMethodDecl CXXMethodDecl::MostRecentDecl(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXMethodDecl::Parent(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

enum RefQualifierKind CXXMethodDecl::RefQualifier(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(static_cast<unsigned int>(val));
}

::pasta::Type CXXMethodDecl::ThisObjectType(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getThisObjectType();
  return TypeBuilder::Build(ast, val);
}

::pasta::Type CXXMethodDecl::ThisType(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.getThisType();
  return TypeBuilder::Build(ast, val);
}

bool CXXMethodDecl::HasInlineBody(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.hasInlineBody();
  return val;
}

bool CXXMethodDecl::IsConst(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isConst();
  return val;
}

bool CXXMethodDecl::IsCopyAssignmentOperator(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isCopyAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsInstance(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isInstance();
  return val;
}

bool CXXMethodDecl::IsLambdaStaticInvoker(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isLambdaStaticInvoker();
  return val;
}

bool CXXMethodDecl::IsMoveAssignmentOperator(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isMoveAssignmentOperator();
  return val;
}

bool CXXMethodDecl::IsStatic(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isStatic();
  return val;
}

// 1: CXXMethodDecl::IsUsualDeallocationFunction
bool CXXMethodDecl::IsVirtual(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isVirtual();
  return val;
}

bool CXXMethodDecl::IsVolatile(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.isVolatile();
  return val;
}

// 0: CXXMethodDecl::Overridden_methods
uint32_t CXXMethodDecl::Size_overridden_methods(void) const {
  auto &self = *(u.CXXMethodDecl);
  auto val = self.size_overridden_methods();
  return val;
}

ClassTemplateDecl::ClassTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, ClassTemplateDecl)
::pasta::ClassTemplateDecl ClassTemplateDecl::CanonicalDecl(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::MostRecentDecl(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::PreviousDecl(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ClassTemplateDecl::TemplatedDecl(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

// 0: ClassTemplateDecl::
// 0: ClassTemplateDecl::
std::vector<::pasta::ClassTemplateSpecializationDecl> ClassTemplateDecl::Specializations(void) const {
  auto &self = *(u.ClassTemplateDecl);
  auto val = self.specializations();
  std::vector<::pasta::ClassTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ClassTemplateSpecializationDecl>(ast, decl_ptr));
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
  auto &self = *(u.DecompositionDecl);
  auto val = self.bindings();
  std::vector<::pasta::BindingDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::BindingDecl>(ast, decl_ptr));
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
  auto &self = *(u.EnumDecl);
  auto val = self.enumerators();
  std::vector<::pasta::EnumConstantDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::EnumDecl EnumDecl::CanonicalDecl(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::EnumDecl EnumDecl::Definition(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::EnumDecl EnumDecl::InstantiatedFromMemberEnum(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getInstantiatedFromMemberEnum();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::InstantiatedFromMemberEnum can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type EnumDecl::IntegerType(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getIntegerType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange EnumDecl::IntegerTypeRange(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getIntegerTypeRange();
  return ast->TokenRangeFrom(val);
}

// 0: EnumDecl::IntegerTypeSourceInfo
// 0: EnumDecl::MemberSpecializationInfo
::pasta::EnumDecl EnumDecl::MostRecentDecl(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t EnumDecl::NumNegativeBits(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getNumNegativeBits();
  return val;
}

uint32_t EnumDecl::NumPositiveBits(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getNumPositiveBits();
  return val;
}

::pasta::EnumDecl EnumDecl::PreviousDecl(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type EnumDecl::PromotionType(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getPromotionType();
  return TypeBuilder::Build(ast, val);
}

::pasta::EnumDecl EnumDecl::TemplateInstantiationPattern(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::TemplateInstantiationPattern can return nullptr!");
  __builtin_unreachable();
}

enum TemplateSpecializationKind EnumDecl::TemplateSpecializationKind(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

bool EnumDecl::IsClosed(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isClosed();
  return val;
}

bool EnumDecl::IsClosedFlag(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isClosedFlag();
  return val;
}

bool EnumDecl::IsClosedNonFlag(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isClosedNonFlag();
  return val;
}

bool EnumDecl::IsComplete(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isComplete();
  return val;
}

bool EnumDecl::IsFixed(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isFixed();
  return val;
}

bool EnumDecl::IsScoped(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isScoped();
  return val;
}

bool EnumDecl::IsScopedUsingClassTag(void) const {
  auto &self = *(u.EnumDecl);
  auto val = self.isScopedUsingClassTag();
  return val;
}

FunctionTemplateDecl::FunctionTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_BASE_OPERATORS(Decl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(NamedDecl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_BASE_OPERATORS(TemplateDecl, FunctionTemplateDecl)
::pasta::FunctionTemplateDecl FunctionTemplateDecl::CanonicalDecl(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::MostRecentDecl(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::PreviousDecl(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl FunctionTemplateDecl::TemplatedDecl(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool FunctionTemplateDecl::IsAbbreviated(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.isAbbreviated();
  return val;
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.isThisDeclarationADefinition();
  return val;
}

// 0: FunctionTemplateDecl::
// 0: FunctionTemplateDecl::
std::vector<::pasta::FunctionDecl> FunctionTemplateDecl::Specializations(void) const {
  auto &self = *(u.FunctionTemplateDecl);
  auto val = self.specializations();
  std::vector<::pasta::FunctionDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::FunctionDecl>(ast, decl_ptr));
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
::pasta::ImplicitParamKind ImplicitParamDecl::ParameterKind(void) const {
  auto &self = *(u.ImplicitParamDecl);
  auto val = self.getParameterKind();
  return static_cast<::pasta::ImplicitParamKind>(val);
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
::pasta::TokenRange OMPCapturedExprDecl::TokenRange(void) const {
  auto &self = *(u.OMPCapturedExprDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
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
::pasta::Expr ParmVarDecl::DefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getDefaultArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ParmVarDecl::DefaultArg can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange ParmVarDecl::DefaultArgRange(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getDefaultArgRange();
  return ast->TokenRangeFrom(val);
}

uint32_t ParmVarDecl::FunctionScopeDepth(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getFunctionScopeDepth();
  return val;
}

uint32_t ParmVarDecl::FunctionScopeIndex(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getFunctionScopeIndex();
  return val;
}

// 0: ParmVarDecl::ObjCDeclQualifier
::pasta::Type ParmVarDecl::OriginalType(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getOriginalType();
  return TypeBuilder::Build(ast, val);
}

::pasta::TokenRange ParmVarDecl::TokenRange(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Expr ParmVarDecl::UninstantiatedDefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.getUninstantiatedDefaultArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "ParmVarDecl::UninstantiatedDefaultArg can return nullptr!");
  __builtin_unreachable();
}

bool ParmVarDecl::HasDefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.hasDefaultArg();
  return val;
}

bool ParmVarDecl::HasInheritedDefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.hasInheritedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUninstantiatedDefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.hasUninstantiatedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUnparsedDefaultArg(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.hasUnparsedDefaultArg();
  return val;
}

bool ParmVarDecl::IsDestroyedInCallee(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.isDestroyedInCallee();
  return val;
}

bool ParmVarDecl::IsKNRPromoted(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.isKNRPromoted();
  return val;
}

bool ParmVarDecl::IsObjCMethodParameter(void) const {
  auto &self = *(u.ParmVarDecl);
  auto val = self.isObjCMethodParameter();
  return val;
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
  auto &self = *(u.RecordDecl);
  auto val = self.canPassInRegisters();
  return val;
}

// 0: RecordDecl::
// 0: RecordDecl::
// 0: RecordDecl::
std::vector<::pasta::FieldDecl> RecordDecl::Fields(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.fields();
  std::vector<::pasta::FieldDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::FieldDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::FieldDecl RecordDecl::FindFirstNamedDataMember(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.findFirstNamedDataMember();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "RecordDecl::FindFirstNamedDataMember can return nullptr!");
  __builtin_unreachable();
}

::pasta::ArgPassingKind RecordDecl::ArgPassingRestrictions(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.getArgPassingRestrictions();
  return static_cast<::pasta::ArgPassingKind>(val);
}

::pasta::RecordDecl RecordDecl::Definition(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl RecordDecl::MostRecentDecl(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl RecordDecl::PreviousDecl(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

bool RecordDecl::HasFlexibleArrayMember(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasFlexibleArrayMember();
  return val;
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasLoadedFieldsFromExternalStorage();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool RecordDecl::HasObjectMember(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasObjectMember();
  return val;
}

bool RecordDecl::HasVolatileMember(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.hasVolatileMember();
  return val;
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isAnonymousStructOrUnion();
  return val;
}

bool RecordDecl::IsCapturedRecord(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isCapturedRecord();
  return val;
}

bool RecordDecl::IsInjectedClassName(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isInjectedClassName();
  return val;
}

bool RecordDecl::IsLambda(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isLambda();
  return val;
}

bool RecordDecl::IsMsStruct(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isMsStruct(ast->ci->getASTContext());
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isNonTrivialToPrimitiveCopy();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isNonTrivialToPrimitiveDefaultInitialize();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isNonTrivialToPrimitiveDestroy();
  return val;
}

bool RecordDecl::IsOrContainsUnion(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isOrContainsUnion();
  return val;
}

bool RecordDecl::IsParamDestroyedInCallee(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.isParamDestroyedInCallee();
  return val;
}

bool RecordDecl::MayInsertExtraPadding(void) const {
  auto &self = *(u.RecordDecl);
  auto val = self.mayInsertExtraPadding();
  return val;
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
  auto &self = *(u.VarTemplatePartialSpecializationDecl);
  auto val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "VarTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

// 0: VarTemplatePartialSpecializationDecl::TemplateArgsAsWritten
// 0: VarTemplatePartialSpecializationDecl::TemplateParameters
bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto &self = *(u.VarTemplatePartialSpecializationDecl);
  auto val = self.hasAssociatedConstraints();
  return val;
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
::pasta::CXXConstructorDecl CXXConstructorDecl::CanonicalDecl(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXConstructorDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXConstructorDecl::ExplicitSpecifier
// 0: CXXConstructorDecl::InheritedConstructor
uint32_t CXXConstructorDecl::NumCtorInitializers(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.getNumCtorInitializers();
  return val;
}

::pasta::CXXConstructorDecl CXXConstructorDecl::TargetConstructor(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.getTargetConstructor();
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
// 1: CXXConstructorDecl::IsConvertingConstructor
bool CXXConstructorDecl::IsDefaultConstructor(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.isDefaultConstructor();
  return val;
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.isDelegatingConstructor();
  return val;
}

bool CXXConstructorDecl::IsExplicit(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.isExplicit();
  return val;
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.isInheritingConstructor();
  return val;
}

bool CXXConstructorDecl::IsSpecializationCopyingObject(void) const {
  auto &self = *(u.CXXConstructorDecl);
  auto val = self.isSpecializationCopyingObject();
  return val;
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
::pasta::CXXConversionDecl CXXConversionDecl::CanonicalDecl(void) const {
  auto &self = *(u.CXXConversionDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConversionDecl>(ast, val);
  }
  assert(false && "CXXConversionDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Type CXXConversionDecl::ConversionType(void) const {
  auto &self = *(u.CXXConversionDecl);
  auto val = self.getConversionType();
  return TypeBuilder::Build(ast, val);
}

// 0: CXXConversionDecl::ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const {
  auto &self = *(u.CXXConversionDecl);
  auto val = self.isExplicit();
  return val;
}

bool CXXConversionDecl::IsLambdaToBlockPointerConversion(void) const {
  auto &self = *(u.CXXConversionDecl);
  auto val = self.isLambdaToBlockPointerConversion();
  return val;
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
::pasta::CXXDestructorDecl CXXDestructorDecl::CanonicalDecl(void) const {
  auto &self = *(u.CXXDestructorDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl CXXDestructorDecl::OperatorDelete(void) const {
  auto &self = *(u.CXXDestructorDecl);
  auto val = self.getOperatorDelete();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::OperatorDelete can return nullptr!");
  __builtin_unreachable();
}

::pasta::Expr CXXDestructorDecl::OperatorDeleteThisArg(void) const {
  auto &self = *(u.CXXDestructorDecl);
  auto val = self.getOperatorDeleteThisArg();
  if (val) {
    return StmtBuilder::Create<::pasta::Expr>(ast, val);
  }
  assert(false && "CXXDestructorDecl::OperatorDeleteThisArg can return nullptr!");
  __builtin_unreachable();
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
bool CXXRecordDecl::AllowConstDefaultInit(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.allowConstDefaultInit();
  return val;
}

// 0: CXXRecordDecl::Bases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
enum MSInheritanceModel CXXRecordDecl::CalculateInheritanceModel(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.calculateInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(static_cast<int>(val));
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
  auto &self = *(u.CXXRecordDecl);
  auto val = self.ctors();
  std::vector<::pasta::CXXConstructorDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, decl_ptr));
  }
  return ret;
}

bool CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.defaultedCopyConstructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.defaultedDefaultConstructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.defaultedDestructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsDeleted(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.defaultedDestructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.defaultedMoveConstructorIsDeleted();
  return val;
}

// 1: CXXRecordDecl::ForallBases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::FriendDecl> CXXRecordDecl::Friends(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.friends();
  std::vector<::pasta::FriendDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::FriendDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::CXXRecordDecl CXXRecordDecl::CanonicalDecl(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::Definition(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl CXXRecordDecl::DependentLambdaCallOperator(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getDependentLambdaCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::DependentLambdaCallOperator can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl CXXRecordDecl::DescribedClassTemplate(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getDescribedClassTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::DescribedClassTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXDestructorDecl CXXRecordDecl::Destructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getDestructor();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::Destructor can return nullptr!");
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::DeviceLambdaManglingNumber(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getDeviceLambdaManglingNumber();
  return val;
}

// 0: CXXRecordDecl::GenericLambdaTemplateParameterList
::pasta::CXXRecordDecl CXXRecordDecl::InstantiatedFromMemberClass(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getInstantiatedFromMemberClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::InstantiatedFromMemberClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXMethodDecl CXXRecordDecl::LambdaCallOperator(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getLambdaCallOperator();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::LambdaCallOperator can return nullptr!");
  __builtin_unreachable();
}

enum LambdaCaptureDefault CXXRecordDecl::LambdaCaptureDefault(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getLambdaCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(static_cast<unsigned int>(val));
}

::pasta::Decl CXXRecordDecl::LambdaContextDecl(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getLambdaContextDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "CXXRecordDecl::LambdaContextDecl can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::NamedDecl> CXXRecordDecl::LambdaExplicitTemplateParameters(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getLambdaExplicitTemplateParameters();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

uint32_t CXXRecordDecl::LambdaManglingNumber(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getLambdaManglingNumber();
  return val;
}

// 0: CXXRecordDecl::LambdaTypeInfo
enum MSInheritanceModel CXXRecordDecl::MSInheritanceModel(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getMSInheritanceModel();
  return static_cast<::pasta::MSInheritanceModel>(static_cast<int>(val));
}

enum MSVtorDispMode CXXRecordDecl::MSVtorDispMode(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getMSVtorDispMode();
  return static_cast<::pasta::MSVtorDispMode>(static_cast<int>(val));
}

// 0: CXXRecordDecl::MemberSpecializationInfo
::pasta::CXXRecordDecl CXXRecordDecl::MostRecentDecl(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::MostRecentNonInjectedDecl(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getMostRecentNonInjectedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentNonInjectedDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::NumBases(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getNumBases();
  return val;
}

uint32_t CXXRecordDecl::NumVBases(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getNumVBases();
  return val;
}

uint32_t CXXRecordDecl::ODRHash(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getODRHash();
  return val;
}

::pasta::CXXRecordDecl CXXRecordDecl::PreviousDecl(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::TemplateInstantiationPattern(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getTemplateInstantiationPattern();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::TemplateInstantiationPattern can return nullptr!");
  __builtin_unreachable();
}

enum TemplateSpecializationKind CXXRecordDecl::TemplateSpecializationKind(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.getTemplateSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

// 0: CXXRecordDecl::VisibleConversionFunctions
bool CXXRecordDecl::HasAnyDependentBases(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasAnyDependentBases();
  return val;
}

bool CXXRecordDecl::HasConstexprDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasConstexprDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasConstexprDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasConstexprDestructor();
  return val;
}

bool CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasConstexprNonCopyMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasCopyAssignmentWithConstParam(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasCopyAssignmentWithConstParam();
  return val;
}

bool CXXRecordDecl::HasCopyConstructorWithConstParam(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasCopyConstructorWithConstParam();
  return val;
}

bool CXXRecordDecl::HasDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasDefinition(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasDefinition();
  return val;
}

bool CXXRecordDecl::HasDirectFields(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasDirectFields();
  return val;
}

bool CXXRecordDecl::HasFriends(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasFriends();
  return val;
}

bool CXXRecordDecl::HasInClassInitializer(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasInClassInitializer();
  return val;
}

bool CXXRecordDecl::HasInheritedAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasInheritedAssignment();
  return val;
}

bool CXXRecordDecl::HasInheritedConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasInheritedConstructor();
  return val;
}

bool CXXRecordDecl::HasIrrelevantDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasIrrelevantDestructor();
  return val;
}

bool CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasKnownLambdaInternalLinkage();
  return val;
}

// 1: CXXRecordDecl::HasMemberName
bool CXXRecordDecl::HasMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasMutableFields(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasMutableFields();
  return val;
}

bool CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonLiteralTypeFieldsOrBases();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasNonTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasPrivateFields(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasPrivateFields();
  return val;
}

bool CXXRecordDecl::HasProtectedFields(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasProtectedFields();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasSimpleCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasSimpleCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasSimpleDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasSimpleDestructor();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasSimpleMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasSimpleMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasUninitializedReferenceMember(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUninitializedReferenceMember();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredDestructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveOperation(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserDeclaredMoveOperation();
  return val;
}

bool CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasUserProvidedDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasVariantMembers(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.hasVariantMembers();
  return val;
}

bool CXXRecordDecl::ImplicitCopyAssignmentHasConstParam(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.implicitCopyAssignmentHasConstParam();
  return val;
}

bool CXXRecordDecl::ImplicitCopyConstructorHasConstParam(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.implicitCopyConstructorHasConstParam();
  return val;
}

bool CXXRecordDecl::IsAbstract(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isAbstract();
  return val;
}

bool CXXRecordDecl::IsAggregate(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isAggregate();
  return val;
}

bool CXXRecordDecl::IsAnyDestructorNoReturn(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isAnyDestructorNoReturn();
  return val;
}

bool CXXRecordDecl::IsCLike(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isCLike();
  return val;
}

bool CXXRecordDecl::IsCXX11StandardLayout(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isCXX11StandardLayout();
  return val;
}

// 1: CXXRecordDecl::IsCurrentInstantiation
bool CXXRecordDecl::IsDependentLambda(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isDependentLambda();
  return val;
}

bool CXXRecordDecl::IsDynamicClass(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isDynamicClass();
  return val;
}

bool CXXRecordDecl::IsEffectivelyFinal(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isEffectivelyFinal();
  return val;
}

bool CXXRecordDecl::IsEmpty(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isEmpty();
  return val;
}

bool CXXRecordDecl::IsGenericLambda(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isGenericLambda();
  return val;
}

bool CXXRecordDecl::IsInterfaceLike(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isInterfaceLike();
  return val;
}

bool CXXRecordDecl::IsLambda(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isLambda();
  return val;
}

bool CXXRecordDecl::IsLiteral(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isLiteral();
  return val;
}

::pasta::FunctionDecl CXXRecordDecl::IsLocalClass(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isLocalClass();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::IsLocalClass can return nullptr!");
  __builtin_unreachable();
}

bool CXXRecordDecl::IsPOD(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isPOD();
  return val;
}

bool CXXRecordDecl::IsParsingBaseSpecifiers(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isParsingBaseSpecifiers();
  return val;
}

bool CXXRecordDecl::IsPolymorphic(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isPolymorphic();
  return val;
}

// 1: CXXRecordDecl::IsProvablyNotDerivedFrom
bool CXXRecordDecl::IsStandardLayout(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isStandardLayout();
  return val;
}

bool CXXRecordDecl::IsStructural(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isStructural();
  return val;
}

bool CXXRecordDecl::IsTrivial(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isTrivial();
  return val;
}

bool CXXRecordDecl::IsTriviallyCopyable(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.isTriviallyCopyable();
  return val;
}

// 1: CXXRecordDecl::IsVirtuallyDerivedFrom
bool CXXRecordDecl::LambdaIsDefaultConstructibleAndAssignable(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.lambdaIsDefaultConstructibleAndAssignable();
  return val;
}

// 2: LookupInBases
bool CXXRecordDecl::MayBeAbstract(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.mayBeAbstract();
  return val;
}

bool CXXRecordDecl::MayBeDynamicClass(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.mayBeDynamicClass();
  return val;
}

bool CXXRecordDecl::MayBeNonDynamicClass(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.mayBeNonDynamicClass();
  return val;
}

// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
std::vector<::pasta::CXXMethodDecl> CXXRecordDecl::Methods(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

bool CXXRecordDecl::NeedsImplicitCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitDefaultConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitDestructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsImplicitMoveConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsOverloadResolutionForCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsOverloadResolutionForCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsOverloadResolutionForDestructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsOverloadResolutionForMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.needsOverloadResolutionForMoveConstructor();
  return val;
}

bool CXXRecordDecl::NullFieldOffsetIsZero(void) const {
  auto &self = *(u.CXXRecordDecl);
  auto val = self.nullFieldOffsetIsZero();
  return val;
}

// 0: CXXRecordDecl::VirtualBases
// 0: CXXRecordDecl::
// 0: CXXRecordDecl::
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
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getInstantiatedFrom();
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
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getPointOfInstantiation();
  return ast->TokenAt(val);
}

::pasta::TokenRange ClassTemplateSpecializationDecl::TokenRange(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getSourceRange();
  return ast->TokenRangeFrom(val);
}

enum TemplateSpecializationKind ClassTemplateSpecializationDecl::SpecializationKind(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

::pasta::ClassTemplateDecl ClassTemplateSpecializationDecl::SpecializedTemplate(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getSpecializedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateSpecializationDecl::SpecializedTemplate can return nullptr!");
  __builtin_unreachable();
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getSpecializedTemplateOrPartial();
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

// 0: ClassTemplateSpecializationDecl::TemplateArgs
// 0: ClassTemplateSpecializationDecl::TemplateInstantiationArgs
::pasta::Token ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

// 0: ClassTemplateSpecializationDecl::TypeAsWritten
bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.isClassScopeExplicitSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.isExplicitInstantiationOrSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto &self = *(u.ClassTemplateSpecializationDecl);
  auto val = self.isExplicitSpecialization();
  return val;
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
  auto &self = *(u.ClassTemplatePartialSpecializationDecl);
  auto val = self.getInjectedSpecializationType();
  return TypeBuilder::Build(ast, val);
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const {
  auto &self = *(u.ClassTemplatePartialSpecializationDecl);
  auto val = self.getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate(void) const {
  auto &self = *(u.ClassTemplatePartialSpecializationDecl);
  auto val = self.getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassTemplatePartialSpecializationDecl::TemplateArgsAsWritten
// 0: ClassTemplatePartialSpecializationDecl::TemplateParameters
bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto &self = *(u.ClassTemplatePartialSpecializationDecl);
  auto val = self.hasAssociatedConstraints();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
