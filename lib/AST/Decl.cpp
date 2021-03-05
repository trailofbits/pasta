/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/Decl.h>

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
#pragma clang diagnostic pop

#include "AST.h"

namespace pasta {
namespace {
// Return the PASTA `DeclKind` for a Clang `Decl`.
static DeclKind KindOfDecl(const clang::Decl *decl) {
  switch (decl->getKind()) {
#define ABSTRACT_DECL(DECL)
#define DECL(DERIVED, BASE) \
    case clang::Decl::DERIVED: \
      return DeclKind::k ## DERIVED ## Decl;
#include <clang/AST/DeclNodes.inc>
  }
  __builtin_unreachable();
}

}  // namespace

const char *Decl::KindName(void) const {
  switch (kind) {
    case DeclKind::kAccessSpecDecl: return "AccessSpecDecl";
    case DeclKind::kBindingDecl: return "BindingDecl";
    case DeclKind::kBlockDecl: return "BlockDecl";
    case DeclKind::kBuiltinTemplateDecl: return "BuiltinTemplateDecl";
    case DeclKind::kCXXConstructorDecl: return "CXXConstructorDecl";
    case DeclKind::kCXXConversionDecl: return "CXXConversionDecl";
    case DeclKind::kCXXDeductionGuideDecl: return "CXXDeductionGuideDecl";
    case DeclKind::kCXXDestructorDecl: return "CXXDestructorDecl";
    case DeclKind::kCXXMethodDecl: return "CXXMethodDecl";
    case DeclKind::kCXXRecordDecl: return "CXXRecordDecl";
    case DeclKind::kCapturedDecl: return "CapturedDecl";
    case DeclKind::kClassScopeFunctionSpecializationDecl: return "ClassScopeFunctionSpecializationDecl";
    case DeclKind::kClassTemplateDecl: return "ClassTemplateDecl";
    case DeclKind::kClassTemplatePartialSpecializationDecl: return "ClassTemplatePartialSpecializationDecl";
    case DeclKind::kClassTemplateSpecializationDecl: return "ClassTemplateSpecializationDecl";
    case DeclKind::kConceptDecl: return "ConceptDecl";
    case DeclKind::kConstructorUsingShadowDecl: return "ConstructorUsingShadowDecl";
    case DeclKind::kDeclaratorDecl: return "DeclaratorDecl";
    case DeclKind::kDecompositionDecl: return "DecompositionDecl";
    case DeclKind::kEmptyDecl: return "EmptyDecl";
    case DeclKind::kEnumConstantDecl: return "EnumConstantDecl";
    case DeclKind::kEnumDecl: return "EnumDecl";
    case DeclKind::kExportDecl: return "ExportDecl";
    case DeclKind::kExternCContextDecl: return "ExternCContextDecl";
    case DeclKind::kFieldDecl: return "FieldDecl";
    case DeclKind::kFileScopeAsmDecl: return "FileScopeAsmDecl";
    case DeclKind::kFriendDecl: return "FriendDecl";
    case DeclKind::kFriendTemplateDecl: return "FriendTemplateDecl";
    case DeclKind::kFunctionDecl: return "FunctionDecl";
    case DeclKind::kFunctionTemplateDecl: return "FunctionTemplateDecl";
    case DeclKind::kImplicitParamDecl: return "ImplicitParamDecl";
    case DeclKind::kImportDecl: return "ImportDecl";
    case DeclKind::kIndirectFieldDecl: return "IndirectFieldDecl";
    case DeclKind::kLabelDecl: return "LabelDecl";
    case DeclKind::kLifetimeExtendedTemporaryDecl: return "LifetimeExtendedTemporaryDecl";
    case DeclKind::kLinkageSpecDecl: return "LinkageSpecDecl";
    case DeclKind::kMSGuidDecl: return "MSGuidDecl";
    case DeclKind::kMSPropertyDecl: return "MSPropertyDecl";
    case DeclKind::kNamedDecl: return "NamedDecl";
    case DeclKind::kNamespaceAliasDecl: return "NamespaceAliasDecl";
    case DeclKind::kNamespaceDecl: return "NamespaceDecl";
    case DeclKind::kNonTypeTemplateParmDecl: return "NonTypeTemplateParmDecl";
    case DeclKind::kOMPAllocateDecl: return "OMPAllocateDecl";
    case DeclKind::kOMPCapturedExprDecl: return "OMPCapturedExprDecl";
    case DeclKind::kOMPDeclareMapperDecl: return "OMPDeclareMapperDecl";
    case DeclKind::kOMPDeclareReductionDecl: return "OMPDeclareReductionDecl";
    case DeclKind::kOMPRequiresDecl: return "OMPRequiresDecl";
    case DeclKind::kOMPThreadPrivateDecl: return "OMPThreadPrivateDecl";
    case DeclKind::kObjCAtDefsFieldDecl: return "ObjCAtDefsFieldDecl";
    case DeclKind::kObjCCategoryDecl: return "ObjCCategoryDecl";
    case DeclKind::kObjCCategoryImplDecl: return "ObjCCategoryImplDecl";
    case DeclKind::kObjCCompatibleAliasDecl: return "ObjCCompatibleAliasDecl";
    case DeclKind::kObjCContainerDecl: return "ObjCContainerDecl";
    case DeclKind::kObjCImplDecl: return "ObjCImplDecl";
    case DeclKind::kObjCImplementationDecl: return "ObjCImplementationDecl";
    case DeclKind::kObjCInterfaceDecl: return "ObjCInterfaceDecl";
    case DeclKind::kObjCIvarDecl: return "ObjCIvarDecl";
    case DeclKind::kObjCMethodDecl: return "ObjCMethodDecl";
    case DeclKind::kObjCPropertyDecl: return "ObjCPropertyDecl";
    case DeclKind::kObjCPropertyImplDecl: return "ObjCPropertyImplDecl";
    case DeclKind::kObjCProtocolDecl: return "ObjCProtocolDecl";
    case DeclKind::kObjCTypeParamDecl: return "ObjCTypeParamDecl";
    case DeclKind::kParmVarDecl: return "ParmVarDecl";
    case DeclKind::kPragmaCommentDecl: return "PragmaCommentDecl";
    case DeclKind::kPragmaDetectMismatchDecl: return "PragmaDetectMismatchDecl";
    case DeclKind::kRecordDecl: return "RecordDecl";
    case DeclKind::kRedeclarableTemplateDecl: return "RedeclarableTemplateDecl";
    case DeclKind::kRequiresExprBodyDecl: return "RequiresExprBodyDecl";
    case DeclKind::kStaticAssertDecl: return "StaticAssertDecl";
    case DeclKind::kTagDecl: return "TagDecl";
    case DeclKind::kTemplateDecl: return "TemplateDecl";
    case DeclKind::kTemplateTemplateParmDecl: return "TemplateTemplateParmDecl";
    case DeclKind::kTemplateTypeParmDecl: return "TemplateTypeParmDecl";
    case DeclKind::kTranslationUnitDecl: return "TranslationUnitDecl";
    case DeclKind::kTypeAliasDecl: return "TypeAliasDecl";
    case DeclKind::kTypeAliasTemplateDecl: return "TypeAliasTemplateDecl";
    case DeclKind::kTypeDecl: return "TypeDecl";
    case DeclKind::kTypedefDecl: return "TypedefDecl";
    case DeclKind::kTypedefNameDecl: return "TypedefNameDecl";
    case DeclKind::kUnresolvedUsingTypenameDecl: return "UnresolvedUsingTypenameDecl";
    case DeclKind::kUnresolvedUsingValueDecl: return "UnresolvedUsingValueDecl";
    case DeclKind::kUsingDecl: return "UsingDecl";
    case DeclKind::kUsingDirectiveDecl: return "UsingDirectiveDecl";
    case DeclKind::kUsingPackDecl: return "UsingPackDecl";
    case DeclKind::kUsingShadowDecl: return "UsingShadowDecl";
    case DeclKind::kValueDecl: return "ValueDecl";
    case DeclKind::kVarDecl: return "VarDecl";
    case DeclKind::kVarTemplateDecl: return "VarTemplateDecl";
    case DeclKind::kVarTemplatePartialSpecializationDecl: return "VarTemplatePartialSpecializationDecl";
    case DeclKind::kVarTemplateSpecializationDecl: return "VarTemplateSpecializationDecl";
  }
}

Decl::Decl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}
  // Attrs
  // Access
  // AccessUnsafe
  // AsFunction
std::optional<::pasta::Token> Decl::BeginToken(void) const {
  return ast->TokenAt(u.Decl->getBeginLoc());
}

  // Body
  // CanonicalDecl
  // DeclContext
std::optional<::pasta::Token> Decl::EndToken(void) const {
  return ast->TokenAt(u.Decl->getEndLoc());
}

  // FriendObjectKind
  // GlobalID
  // IdentifierNamespace
  // ImportedOwningModule
  // LexicalDeclContext
  // LocalOwningModule
std::optional<::pasta::Token> Decl::Token(void) const {
  return ast->TokenAt(u.Decl->getLocation());
}

  // ModuleOwnershipKind
  // MostRecentDecl
  // NextDeclInContext
  // NonClosureContext
  // OwningModule
  // OwningModuleID
  // PreviousDecl
  // TokenRange
  // TranslationUnitDecl
bool Decl::HasAttrs(void) const {
  return u.Decl->hasAttrs();
}

bool Decl::HasBody(void) const {
  return u.Decl->hasBody();
}

bool Decl::HasOwningModule(void) const {
  return u.Decl->hasOwningModule();
}

bool Decl::HasTagIdentifierNamespace(void) const {
  return u.Decl->hasTagIdentifierNamespace();
}

bool Decl::IsCanonicalDecl(void) const {
  return u.Decl->isCanonicalDecl();
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const {
  return u.Decl->isDefinedOutsideFunctionOrMethod();
}

bool Decl::IsDeprecated(void) const {
  return u.Decl->isDeprecated();
}

bool Decl::IsFirstDecl(void) const {
  return u.Decl->isFirstDecl();
}

bool Decl::IsFromASTFile(void) const {
  return u.Decl->isFromASTFile();
}

bool Decl::IsFunctionOrFunctionTemplate(void) const {
  return u.Decl->isFunctionOrFunctionTemplate();
}

bool Decl::IsImplicit(void) const {
  return u.Decl->isImplicit();
}

  // IsInIdentifierNamespace
bool Decl::IsInvalidDecl(void) const {
  return u.Decl->isInvalidDecl();
}

bool Decl::IsModulePrivate(void) const {
  return u.Decl->isModulePrivate();
}

bool Decl::IsTemplateParameter(void) const {
  return u.Decl->isTemplateParameter();
}

bool Decl::IsThisDeclarationReferenced(void) const {
  return u.Decl->isThisDeclarationReferenced();
}

bool Decl::IsTopLevelDeclInObjCContainer(void) const {
  return u.Decl->isTopLevelDeclInObjCContainer();
}

bool Decl::IsUnavailable(void) const {
  return u.Decl->isUnavailable();
}

bool Decl::IsUnconditionallyVisible(void) const {
  return u.Decl->isUnconditionallyVisible();
}

  // Redecls
EmptyDecl::EmptyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::EmptyDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

ExportDecl::ExportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ExportDecl *decl_)
    : Decl(ast_, decl_) {}

std::optional<::pasta::Token> ExportDecl::EndToken(void) const {
  return ast->TokenAt(u.ExportDecl->getEndLoc());
}

std::optional<::pasta::Token> ExportDecl::ExportToken(void) const {
  return ast->TokenAt(u.ExportDecl->getExportLoc());
}

std::optional<::pasta::Token> ExportDecl::RBraceToken(void) const {
  return ast->TokenAt(u.ExportDecl->getRBraceLoc());
}

  // TokenRange
bool ExportDecl::HasBraces(void) const {
  return u.ExportDecl->hasBraces();
}

ExternCContextDecl::ExternCContextDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ExternCContextDecl *decl_)
    : Decl(ast_, decl_) {}

FileScopeAsmDecl::FileScopeAsmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FileScopeAsmDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> FileScopeAsmDecl::AsmToken(void) const {
  return ast->TokenAt(u.FileScopeAsmDecl->getAsmLoc());
}

  // AsmString
std::optional<::pasta::Token> FileScopeAsmDecl::RParenToken(void) const {
  return ast->TokenAt(u.FileScopeAsmDecl->getRParenLoc());
}

  // TokenRange
FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FriendDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // FriendDecl
std::optional<::pasta::Token> FriendDecl::FriendToken(void) const {
  return ast->TokenAt(u.FriendDecl->getFriendLoc());
}

  // FriendType
  // FriendTypeNumTemplateParameterLists
  // FriendTypeTemplateParameterList
  // TokenRange
bool FriendDecl::IsUnsupportedFriend(void) const {
  return u.FriendDecl->isUnsupportedFriend();
}

FriendTemplateDecl::FriendTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FriendTemplateDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // FriendDecl
std::optional<::pasta::Token> FriendTemplateDecl::FriendToken(void) const {
  return ast->TokenAt(u.FriendTemplateDecl->getFriendLoc());
}

  // FriendType
  // NumTemplateParameters
  // TemplateParameterList
ImportDecl::ImportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ImportDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::LifetimeExtendedTemporaryDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // ChildrenExpr
  // ExtendingDecl
  // ManglingNumber
  // TemporaryExpr
  // Value
LinkageSpecDecl::LinkageSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::LinkageSpecDecl *decl_)
    : Decl(ast_, decl_) {}

std::optional<::pasta::Token> LinkageSpecDecl::EndToken(void) const {
  return ast->TokenAt(u.LinkageSpecDecl->getEndLoc());
}

std::optional<::pasta::Token> LinkageSpecDecl::ExternToken(void) const {
  return ast->TokenAt(u.LinkageSpecDecl->getExternLoc());
}

  // Language
std::optional<::pasta::Token> LinkageSpecDecl::RBraceToken(void) const {
  return ast->TokenAt(u.LinkageSpecDecl->getRBraceLoc());
}

  // TokenRange
bool LinkageSpecDecl::HasBraces(void) const {
  return u.LinkageSpecDecl->hasBraces();
}

NamedDecl::NamedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::NamedDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // DeclName
  // FormalLinkage
  // Identifier
  // MostRecentDecl
  // Name
  // NameAsString
  // UnderlyingDecl
  // Visibility
bool NamedDecl::HasExternalFormalLinkage(void) const {
  return u.NamedDecl->hasExternalFormalLinkage();
}

bool NamedDecl::HasLinkageBeenComputed(void) const {
  return u.NamedDecl->hasLinkageBeenComputed();
}

bool NamedDecl::IsCXXClassMember(void) const {
  return u.NamedDecl->isCXXClassMember();
}

bool NamedDecl::IsExternallyDeclarable(void) const {
  return u.NamedDecl->isExternallyDeclarable();
}

bool NamedDecl::IsExternallyVisible(void) const {
  return u.NamedDecl->isExternallyVisible();
}

NamespaceAliasDecl::NamespaceAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::NamespaceAliasDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> NamespaceAliasDecl::AliasToken(void) const {
  return ast->TokenAt(u.NamespaceAliasDecl->getAliasLoc());
}

  // AliasedNamespace
  // CanonicalDecl
  // Namespace
std::optional<::pasta::Token> NamespaceAliasDecl::NamespaceToken(void) const {
  return ast->TokenAt(u.NamespaceAliasDecl->getNamespaceLoc());
}

  // Qualifier
  // QualifierToken
  // TokenRange
std::optional<::pasta::Token> NamespaceAliasDecl::TargetNameToken(void) const {
  return ast->TokenAt(u.NamespaceAliasDecl->getTargetNameLoc());
}

NamespaceDecl::NamespaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::NamespaceDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // AnonymousNamespace
std::optional<::pasta::Token> NamespaceDecl::BeginToken(void) const {
  return ast->TokenAt(u.NamespaceDecl->getBeginLoc());
}

  // CanonicalDecl
std::optional<::pasta::Token> NamespaceDecl::RBraceToken(void) const {
  return ast->TokenAt(u.NamespaceDecl->getRBraceLoc());
}

  // TokenRange
bool NamespaceDecl::IsAnonymousNamespace(void) const {
  return u.NamespaceDecl->isAnonymousNamespace();
}

bool NamespaceDecl::IsInline(void) const {
  return u.NamespaceDecl->isInline();
}

OMPAllocateDecl::OMPAllocateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPAllocateDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Clauselists
  // Varlists
OMPRequiresDecl::OMPRequiresDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPRequiresDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Clauselists
OMPThreadPrivateDecl::OMPThreadPrivateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPThreadPrivateDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Varlists
ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCCompatibleAliasDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // ClassInterface
ObjCContainerDecl::ObjCContainerDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCContainerDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // Class_methods
  // Class_properties
  // CollectPropertiesToImplement
  // AtEndRange
std::optional<::pasta::Token> ObjCContainerDecl::AtStartToken(void) const {
  return ast->TokenAt(u.ObjCContainerDecl->getAtStartLoc());
}

  // ClassMethod
  // InstanceMethod
  // TokenRange
  // Instance_methods
  // Instance_properties
  // Methods
  // Properties
ObjCImplDecl::ObjCImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCImplDecl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

  // ClassInterface
  // Property_impls
ObjCImplementationDecl::ObjCImplementationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCImplementationDecl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

  // Identifier
std::optional<::pasta::Token> ObjCImplementationDecl::IvarLBraceToken(void) const {
  return ast->TokenAt(u.ObjCImplementationDecl->getIvarLBraceLoc());
}

std::optional<::pasta::Token> ObjCImplementationDecl::IvarRBraceToken(void) const {
  return ast->TokenAt(u.ObjCImplementationDecl->getIvarRBraceLoc());
}

  // Name
  // NameAsString
  // NumIvarInitializers
  // SuperClass
std::optional<::pasta::Token> ObjCImplementationDecl::SuperClassToken(void) const {
  return ast->TokenAt(u.ObjCImplementationDecl->getSuperClassLoc());
}

bool ObjCImplementationDecl::HasDestructors(void) const {
  return u.ObjCImplementationDecl->hasDestructors();
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const {
  return u.ObjCImplementationDecl->hasNonZeroConstructors();
}

  // Inits
  // Ivars
ObjCInterfaceDecl::ObjCInterfaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCInterfaceDecl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

  // All_referenced_protocols
bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const {
  return u.ObjCInterfaceDecl->declaresOrInheritsDesignatedInitializers();
}

  // CanonicalDecl
  // CategoryListRaw
  // CategoryMethod
  // Definition
std::optional<::pasta::Token> ObjCInterfaceDecl::EndOfDefinitionToken(void) const {
  return ast->TokenAt(u.ObjCInterfaceDecl->getEndOfDefinitionLoc());
}

  // ReferencedProtocols
  // TokenRange
  // SuperClassTInfo
  // SuperClassType
  // TypeForDecl
  // TypeParamListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const {
  return u.ObjCInterfaceDecl->hasDefinition();
}

bool ObjCInterfaceDecl::IsImplicitInterfaceDecl(void) const {
  return u.ObjCInterfaceDecl->isImplicitInterfaceDecl();
}

  // IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const {
  return u.ObjCInterfaceDecl->isThisDeclarationADefinition();
}

  // Ivars
  // Known_categories
  // Known_extensions
  // LookupClassMethod
  // LookupInstanceMethod
  // LookupPropertyAccessor
  // Protocol_locs
  // Protocols
  // Visible_categories
  // Visible_extensions
ObjCMethodDecl::ObjCMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCMethodDecl *decl_)
    : NamedDecl(ast_, decl_) {}

std::optional<::pasta::Token> ObjCMethodDecl::BeginToken(void) const {
  return ast->TokenAt(u.ObjCMethodDecl->getBeginLoc());
}

  // CanonicalDecl
  // ClassInterface
  // CmdDecl
std::optional<::pasta::Token> ObjCMethodDecl::DeclaratorEndToken(void) const {
  return ast->TokenAt(u.ObjCMethodDecl->getDeclaratorEndLoc());
}

  // ImplementationControl
  // NumSelectorLocs
  // ObjCDeclQualifier
  // ParamDecl
  // ReturnType
  // ReturnTypeSourceInfo
  // Selector
  // SelectorToken
std::optional<::pasta::Token> ObjCMethodDecl::SelectorStartToken(void) const {
  return ast->TokenAt(u.ObjCMethodDecl->getSelectorStartLoc());
}

  // SelfDecl
  // TokenRange
bool ObjCMethodDecl::HasBody(void) const {
  return u.ObjCMethodDecl->hasBody();
}

bool ObjCMethodDecl::HasRedeclaration(void) const {
  return u.ObjCMethodDecl->hasRedeclaration();
}

bool ObjCMethodDecl::HasRelatedResultType(void) const {
  return u.ObjCMethodDecl->hasRelatedResultType();
}

bool ObjCMethodDecl::HasSkippedBody(void) const {
  return u.ObjCMethodDecl->hasSkippedBody();
}

bool ObjCMethodDecl::IsClassMethod(void) const {
  return u.ObjCMethodDecl->isClassMethod();
}

bool ObjCMethodDecl::IsDefined(void) const {
  return u.ObjCMethodDecl->isDefined();
}

bool ObjCMethodDecl::IsInstanceMethod(void) const {
  return u.ObjCMethodDecl->isInstanceMethod();
}

bool ObjCMethodDecl::IsOptional(void) const {
  return u.ObjCMethodDecl->isOptional();
}

bool ObjCMethodDecl::IsOverriding(void) const {
  return u.ObjCMethodDecl->isOverriding();
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const {
  return u.ObjCMethodDecl->isPropertyAccessor();
}

bool ObjCMethodDecl::IsRedeclaration(void) const {
  return u.ObjCMethodDecl->isRedeclaration();
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const {
  return u.ObjCMethodDecl->isSynthesizedAccessorStub();
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const {
  return u.ObjCMethodDecl->isThisDeclarationADefinition();
}

bool ObjCMethodDecl::IsVariadic(void) const {
  return u.ObjCMethodDecl->isVariadic();
}

  // Parameters
ObjCPropertyDecl::ObjCPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCPropertyDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> ObjCPropertyDecl::AtToken(void) const {
  return ast->TokenAt(u.ObjCPropertyDecl->getAtLoc());
}

  // GetterMethodDecl
  // GetterName
std::optional<::pasta::Token> ObjCPropertyDecl::GetterNameToken(void) const {
  return ast->TokenAt(u.ObjCPropertyDecl->getGetterNameLoc());
}

std::optional<::pasta::Token> ObjCPropertyDecl::LParenToken(void) const {
  return ast->TokenAt(u.ObjCPropertyDecl->getLParenLoc());
}

  // PropertyAttributes
  // PropertyAttributesAsWritten
  // PropertyImplementation
  // PropertyIvarDecl
  // QueryKind
  // SetterKind
  // SetterMethodDecl
  // SetterName
std::optional<::pasta::Token> ObjCPropertyDecl::SetterNameToken(void) const {
  return ast->TokenAt(u.ObjCPropertyDecl->getSetterNameLoc());
}

  // TokenRange
  // Type
  // TypeSourceInfo
bool ObjCPropertyDecl::IsAtomic(void) const {
  return u.ObjCPropertyDecl->isAtomic();
}

bool ObjCPropertyDecl::IsClassProperty(void) const {
  return u.ObjCPropertyDecl->isClassProperty();
}

bool ObjCPropertyDecl::IsDirectProperty(void) const {
  return u.ObjCPropertyDecl->isDirectProperty();
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const {
  return u.ObjCPropertyDecl->isInstanceProperty();
}

bool ObjCPropertyDecl::IsOptional(void) const {
  return u.ObjCPropertyDecl->isOptional();
}

bool ObjCPropertyDecl::IsReadOnly(void) const {
  return u.ObjCPropertyDecl->isReadOnly();
}

bool ObjCPropertyDecl::IsRetaining(void) const {
  return u.ObjCPropertyDecl->isRetaining();
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCPropertyImplDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> ObjCPropertyImplDecl::BeginToken(void) const {
  return ast->TokenAt(u.ObjCPropertyImplDecl->getBeginLoc());
}

  // GetterCXXConstructor
  // GetterMethodDecl
  // PropertyDecl
  // PropertyImplementation
  // PropertyIvarDecl
std::optional<::pasta::Token> ObjCPropertyImplDecl::PropertyIvarDeclToken(void) const {
  return ast->TokenAt(u.ObjCPropertyImplDecl->getPropertyIvarDeclLoc());
}

  // SetterCXXAssignment
  // SetterMethodDecl
bool ObjCPropertyImplDecl::IsIvarNameSpecified(void) const {
  return u.ObjCPropertyImplDecl->isIvarNameSpecified();
}

ObjCProtocolDecl::ObjCProtocolDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCProtocolDecl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // Definition
  // ReferencedProtocols
  // TokenRange
bool ObjCProtocolDecl::HasDefinition(void) const {
  return u.ObjCProtocolDecl->hasDefinition();
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const {
  return u.ObjCProtocolDecl->isThisDeclarationADefinition();
}

  // LookupClassMethod
  // LookupInstanceMethod
  // Protocol_locs
  // Protocols
PragmaCommentDecl::PragmaCommentDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::PragmaCommentDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Arg
  // CommentKind
PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::PragmaDetectMismatchDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Name
  // Value
RequiresExprBodyDecl::RequiresExprBodyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::RequiresExprBodyDecl *decl_)
    : Decl(ast_, decl_) {}

StaticAssertDecl::StaticAssertDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::StaticAssertDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // AssertExpr
  // Message
std::optional<::pasta::Token> StaticAssertDecl::RParenToken(void) const {
  return ast->TokenAt(u.StaticAssertDecl->getRParenLoc());
}

  // TokenRange
bool StaticAssertDecl::IsFailed(void) const {
  return u.StaticAssertDecl->isFailed();
}

TemplateDecl::TemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TemplateDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // TokenRange
  // TemplateParameters
  // TemplatedDecl
TemplateTemplateParmDecl::TemplateTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TemplateTemplateParmDecl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

bool TemplateTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  return u.TemplateTemplateParmDecl->defaultArgumentWasInherited();
}

  // DefaultArgStorage
  // DefaultArgument
  // ExpansionTemplateParameters
  // NumExpansionTemplateParameters
  // TokenRange
bool TemplateTemplateParmDecl::HasDefaultArgument(void) const {
  return u.TemplateTemplateParmDecl->hasDefaultArgument();
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const {
  return u.TemplateTemplateParmDecl->isExpandedParameterPack();
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const {
  return u.TemplateTemplateParmDecl->isPackExpansion();
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const {
  return u.TemplateTemplateParmDecl->isParameterPack();
}

TranslationUnitDecl::TranslationUnitDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TranslationUnitDecl *decl_)
    : Decl(ast_, decl_) {}

  // ASTContext
  // AnonymousNamespace
TypeDecl::TypeDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TypeDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> TypeDecl::BeginToken(void) const {
  return ast->TokenAt(u.TypeDecl->getBeginLoc());
}

  // TokenRange
  // TypeForDecl
TypedefNameDecl::TypedefNameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TypedefNameDecl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // TypeSourceInfo
  // UnderlyingType
bool TypedefNameDecl::IsModed(void) const {
  return u.TypedefNameDecl->isModed();
}

bool TypedefNameDecl::IsTransparentTag(void) const {
  return u.TypedefNameDecl->isTransparentTag();
}

UnresolvedUsingTypenameDecl::UnresolvedUsingTypenameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UnresolvedUsingTypenameDecl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
std::optional<::pasta::Token> UnresolvedUsingTypenameDecl::EllipsisToken(void) const {
  return ast->TokenAt(u.UnresolvedUsingTypenameDecl->getEllipsisLoc());
}

  // NameInfo
  // Qualifier
  // QualifierToken
std::optional<::pasta::Token> UnresolvedUsingTypenameDecl::TypenameToken(void) const {
  return ast->TokenAt(u.UnresolvedUsingTypenameDecl->getTypenameLoc());
}

std::optional<::pasta::Token> UnresolvedUsingTypenameDecl::UsingToken(void) const {
  return ast->TokenAt(u.UnresolvedUsingTypenameDecl->getUsingLoc());
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const {
  return u.UnresolvedUsingTypenameDecl->isPackExpansion();
}

UsingDecl::UsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UsingDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // NameInfo
  // Qualifier
  // QualifierToken
std::optional<::pasta::Token> UsingDecl::UsingToken(void) const {
  return ast->TokenAt(u.UsingDecl->getUsingLoc());
}

bool UsingDecl::HasTypename(void) const {
  return u.UsingDecl->hasTypename();
}

bool UsingDecl::IsAccessDeclaration(void) const {
  return u.UsingDecl->isAccessDeclaration();
}

  // Shadows
UsingDirectiveDecl::UsingDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UsingDirectiveDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // CommonAncestor
std::optional<::pasta::Token> UsingDirectiveDecl::IdentLocation(void) const {
  return ast->TokenAt(u.UsingDirectiveDecl->getIdentLocation());
}

std::optional<::pasta::Token> UsingDirectiveDecl::NamespaceKeyLocation(void) const {
  return ast->TokenAt(u.UsingDirectiveDecl->getNamespaceKeyLocation());
}

  // NominatedNamespace
  // NominatedNamespaceAsWritten
  // Qualifier
  // QualifierToken
  // TokenRange
std::optional<::pasta::Token> UsingDirectiveDecl::UsingToken(void) const {
  return ast->TokenAt(u.UsingDirectiveDecl->getUsingLoc());
}

UsingPackDecl::UsingPackDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UsingPackDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // Expansions
  // CanonicalDecl
  // InstantiatedFromUsingDecl
  // TokenRange
UsingShadowDecl::UsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UsingShadowDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // NextUsingShadowDecl
  // TargetDecl
ValueDecl::ValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ValueDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // Type
AccessSpecDecl::AccessSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::AccessSpecDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> AccessSpecDecl::AccessSpecifierToken(void) const {
  return ast->TokenAt(u.AccessSpecDecl->getAccessSpecifierLoc());
}

std::optional<::pasta::Token> AccessSpecDecl::ColonToken(void) const {
  return ast->TokenAt(u.AccessSpecDecl->getColonLoc());
}

  // TokenRange
BindingDecl::BindingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::BindingDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

  // Binding
BlockDecl::BlockDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::BlockDecl *decl_)
    : Decl(ast_, decl_) {}

bool BlockDecl::BlockMissingReturnType(void) const {
  return u.BlockDecl->blockMissingReturnType();
}

bool BlockDecl::CanAvoidCopyToHeap(void) const {
  return u.BlockDecl->canAvoidCopyToHeap();
}

  // Captures
bool BlockDecl::CapturesCXXThis(void) const {
  return u.BlockDecl->capturesCXXThis();
}

bool BlockDecl::DoesNotEscape(void) const {
  return u.BlockDecl->doesNotEscape();
}

  // BlockManglingContextDecl
  // BlockManglingNumber
  // Body
std::optional<::pasta::Token> BlockDecl::CaretLocation(void) const {
  return ast->TokenAt(u.BlockDecl->getCaretLocation());
}

  // CompoundBody
  // NumCaptures
  // NumParams
  // ParamDecl
  // SignatureAsWritten
bool BlockDecl::HasCaptures(void) const {
  return u.BlockDecl->hasCaptures();
}

bool BlockDecl::IsConversionFromLambda(void) const {
  return u.BlockDecl->isConversionFromLambda();
}

bool BlockDecl::IsVariadic(void) const {
  return u.BlockDecl->isVariadic();
}

  // Parameters
BuiltinTemplateDecl::BuiltinTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::BuiltinTemplateDecl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

  // BuiltinTemplateKind
  // TokenRange
CapturedDecl::CapturedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CapturedDecl *decl_)
    : Decl(ast_, decl_) {}

  // ContextParam
  // ContextParamPosition
  // NumParams
  // Param
  // Parameters
ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ClassScopeFunctionSpecializationDecl *decl_)
    : Decl(std::move(ast_), decl_) {}

  // Specialization
  // TemplateArgsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArgs(void) const {
  return u.ClassScopeFunctionSpecializationDecl->hasExplicitTemplateArgs();
}

ConceptDecl::ConceptDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ConceptDecl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

  // ConstraintExpr
  // TokenRange
bool ConceptDecl::IsTypeConcept(void) const {
  return u.ConceptDecl->isTypeConcept();
}

ConstructorUsingShadowDecl::ConstructorUsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ConstructorUsingShadowDecl *decl_)
    : UsingShadowDecl(std::move(ast_), decl_) {}

bool ConstructorUsingShadowDecl::ConstructsVirtualBase(void) const {
  return u.ConstructorUsingShadowDecl->constructsVirtualBase();
}

  // ConstructedBaseClass
  // ConstructedBaseClassShadowDecl
  // NominatedBaseClassShadowDecl
  // Parent
DeclaratorDecl::DeclaratorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::DeclaratorDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> DeclaratorDecl::BeginToken(void) const {
  return ast->TokenAt(u.DeclaratorDecl->getBeginLoc());
}

std::optional<::pasta::Token> DeclaratorDecl::InnerLocStart(void) const {
  return ast->TokenAt(u.DeclaratorDecl->getInnerLocStart());
}

  // NumTemplateParameterLists
  // Qualifier
  // QualifierToken
  // TemplateParameterList
  // TrailingRequiresClause
  // TypeSourceInfo
EnumConstantDecl::EnumConstantDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::EnumConstantDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InitExpr
  // InitVal
FieldDecl::FieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FieldDecl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

  // BitWidth
  // CanonicalDecl
  // CapturedVLAType
  // InClassInitStyle
  // InClassInitializer
  // Parent
bool FieldDecl::HasCapturedVLAType(void) const {
  return u.FieldDecl->hasCapturedVLAType();
}

bool FieldDecl::HasInClassInitializer(void) const {
  return u.FieldDecl->hasInClassInitializer();
}

bool FieldDecl::IsBitField(void) const {
  return u.FieldDecl->isBitField();
}

bool FieldDecl::IsMutable(void) const {
  return u.FieldDecl->isMutable();
}

bool FieldDecl::IsUnnamedBitfield(void) const {
  return u.FieldDecl->isUnnamedBitfield();
}

FunctionDecl::FunctionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FunctionDecl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const {
  return u.FunctionDecl->doesThisDeclarationHaveABody();
}

  // AssociatedConstraints
  // Body
  // CallResultType
  // CanonicalDecl
  // ConstexprKind
  // DeclaredReturnType
  // Definition
std::optional<::pasta::Token> FunctionDecl::EllipsisToken(void) const {
  return ast->TokenAt(u.FunctionDecl->getEllipsisLoc());
}

  // ExceptionSpecType
  // NameInfo
  // ParamDecl
  // ReturnType
  // StorageClass
bool FunctionDecl::HasBody(void) const {
  return u.FunctionDecl->hasBody();
}

bool FunctionDecl::HasImplicitReturnZero(void) const {
  return u.FunctionDecl->hasImplicitReturnZero();
}

bool FunctionDecl::HasInheritedPrototype(void) const {
  return u.FunctionDecl->hasInheritedPrototype();
}

bool FunctionDecl::HasPrototype(void) const {
  return u.FunctionDecl->hasPrototype();
}

bool FunctionDecl::HasSkippedBody(void) const {
  return u.FunctionDecl->hasSkippedBody();
}

bool FunctionDecl::HasWrittenPrototype(void) const {
  return u.FunctionDecl->hasWrittenPrototype();
}

bool FunctionDecl::InstantiationIsPending(void) const {
  return u.FunctionDecl->instantiationIsPending();
}

bool FunctionDecl::IsConsteval(void) const {
  return u.FunctionDecl->isConsteval();
}

bool FunctionDecl::IsConstexpr(void) const {
  return u.FunctionDecl->isConstexpr();
}

bool FunctionDecl::IsConstexprSpecified(void) const {
  return u.FunctionDecl->isConstexprSpecified();
}

bool FunctionDecl::IsDefaulted(void) const {
  return u.FunctionDecl->isDefaulted();
}

bool FunctionDecl::IsDefined(void) const {
  return u.FunctionDecl->isDefined();
}

bool FunctionDecl::IsDeleted(void) const {
  return u.FunctionDecl->isDeleted();
}

bool FunctionDecl::IsDeletedAsWritten(void) const {
  return u.FunctionDecl->isDeletedAsWritten();
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const {
  return u.FunctionDecl->isExplicitlyDefaulted();
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const {
  return u.FunctionDecl->isFunctionTemplateSpecialization();
}

bool FunctionDecl::IsInlineSpecified(void) const {
  return u.FunctionDecl->isInlineSpecified();
}

bool FunctionDecl::IsInlined(void) const {
  return u.FunctionDecl->isInlined();
}

bool FunctionDecl::IsLateTemplateParsed(void) const {
  return u.FunctionDecl->isLateTemplateParsed();
}

bool FunctionDecl::IsMultiVersion(void) const {
  return u.FunctionDecl->isMultiVersion();
}

bool FunctionDecl::IsOverloadedOperator(void) const {
  return u.FunctionDecl->isOverloadedOperator();
}

bool FunctionDecl::IsPure(void) const {
  return u.FunctionDecl->isPure();
}

bool FunctionDecl::IsStatic(void) const {
  return u.FunctionDecl->isStatic();
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const {
  return u.FunctionDecl->isThisDeclarationADefinition();
}

bool FunctionDecl::IsTrivial(void) const {
  return u.FunctionDecl->isTrivial();
}

bool FunctionDecl::IsTrivialForCall(void) const {
  return u.FunctionDecl->isTrivialForCall();
}

bool FunctionDecl::IsUserProvided(void) const {
  return u.FunctionDecl->isUserProvided();
}

bool FunctionDecl::IsVirtualAsWritten(void) const {
  return u.FunctionDecl->isVirtualAsWritten();
}

  // Parameters
bool FunctionDecl::UsesFPIntrin(void) const {
  return u.FunctionDecl->usesFPIntrin();
}

bool FunctionDecl::UsesSEHTry(void) const {
  return u.FunctionDecl->usesSEHTry();
}

bool FunctionDecl::WillHaveBody(void) const {
  return u.FunctionDecl->willHaveBody();
}

IndirectFieldDecl::IndirectFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::IndirectFieldDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

  // Chain
  // AnonField
  // CanonicalDecl
  // ChainingSize
  // VarDecl
LabelDecl::LabelDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::LabelDecl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

  // MSAsmLabel
  // TokenRange
  // Stmt
bool LabelDecl::IsGnuLocal(void) const {
  return u.LabelDecl->isGnuLocal();
}

bool LabelDecl::IsMSAsmLabel(void) const {
  return u.LabelDecl->isMSAsmLabel();
}

bool LabelDecl::IsResolvedMSAsmLabel(void) const {
  return u.LabelDecl->isResolvedMSAsmLabel();
}

MSGuidDecl::MSGuidDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::MSGuidDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

  // Parts
MSPropertyDecl::MSPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::MSPropertyDecl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

  // GetterId
  // SetterId
bool MSPropertyDecl::HasGetter(void) const {
  return u.MSPropertyDecl->hasGetter();
}

bool MSPropertyDecl::HasSetter(void) const {
  return u.MSPropertyDecl->hasSetter();
}

NonTypeTemplateParmDecl::NonTypeTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::NonTypeTemplateParmDecl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

bool NonTypeTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  return u.NonTypeTemplateParmDecl->defaultArgumentWasInherited();
}

  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionType
  // ExpansionTypeSourceInfo
  // NumExpansionTypes
  // PlaceholderTypeConstraint
bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const {
  return u.NonTypeTemplateParmDecl->hasDefaultArgument();
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const {
  return u.NonTypeTemplateParmDecl->hasPlaceholderTypeConstraint();
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const {
  return u.NonTypeTemplateParmDecl->isExpandedParameterPack();
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const {
  return u.NonTypeTemplateParmDecl->isPackExpansion();
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const {
  return u.NonTypeTemplateParmDecl->isParameterPack();
}

OMPDeclareMapperDecl::OMPDeclareMapperDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPDeclareMapperDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // Clauselists
  // MapperVarRef
OMPDeclareReductionDecl::OMPDeclareReductionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPDeclareReductionDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // Combiner
  // CombinerIn
  // CombinerOut
  // InitOrig
  // InitPriv
  // Initializer
  // InitializerKind
ObjCAtDefsFieldDecl::ObjCAtDefsFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCAtDefsFieldDecl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

ObjCCategoryDecl::ObjCCategoryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCCategoryDecl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

bool ObjCCategoryDecl::IsClassExtension(void) const {
  return u.ObjCCategoryDecl->IsClassExtension();
}

std::optional<::pasta::Token> ObjCCategoryDecl::CategoryNameToken(void) const {
  return ast->TokenAt(u.ObjCCategoryDecl->getCategoryNameLoc());
}

  // ClassInterface
std::optional<::pasta::Token> ObjCCategoryDecl::IvarLBraceToken(void) const {
  return ast->TokenAt(u.ObjCCategoryDecl->getIvarLBraceLoc());
}

std::optional<::pasta::Token> ObjCCategoryDecl::IvarRBraceToken(void) const {
  return ast->TokenAt(u.ObjCCategoryDecl->getIvarRBraceLoc());
}

  // NextClassCategory
  // NextClassCategoryRaw
  // ReferencedProtocols
  // TypeParamList
  // Ivars
  // Protocol_locs
  // Protocols
ObjCCategoryImplDecl::ObjCCategoryImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCCategoryImplDecl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> ObjCCategoryImplDecl::CategoryNameToken(void) const {
  return ast->TokenAt(u.ObjCCategoryImplDecl->getCategoryNameLoc());
}

ObjCIvarDecl::ObjCIvarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCIvarDecl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

  // AccessControl
  // CanonicalAccessControl
  // NextIvar
bool ObjCIvarDecl::Synthesize(void) const {
  return u.ObjCIvarDecl->getSynthesize();
}

ObjCTypeParamDecl::ObjCTypeParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ObjCTypeParamDecl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

std::optional<::pasta::Token> ObjCTypeParamDecl::ColonToken(void) const {
  return ast->TokenAt(u.ObjCTypeParamDecl->getColonLoc());
}

  // Index
  // Variance
std::optional<::pasta::Token> ObjCTypeParamDecl::VarianceToken(void) const {
  return ast->TokenAt(u.ObjCTypeParamDecl->getVarianceLoc());
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const {
  return u.ObjCTypeParamDecl->hasExplicitBound();
}

RedeclarableTemplateDecl::RedeclarableTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::RedeclarableTemplateDecl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const {
  return u.RedeclarableTemplateDecl->isMemberSpecialization();
}

TagDecl::TagDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TagDecl *decl_)
    : TypeDecl(ast_, decl_) {}

  // BraceRange
  // CanonicalDecl
std::optional<::pasta::Token> TagDecl::InnerLocStart(void) const {
  return ast->TokenAt(u.TagDecl->getInnerLocStart());
}

  // KindName
  // NumTemplateParameterLists
  // Qualifier
  // QualifierToken
  // TagKind
  // TemplateParameterList
  // TypedefNameForAnonDecl
bool TagDecl::HasNameForLinkage(void) const {
  return u.TagDecl->hasNameForLinkage();
}

bool TagDecl::IsBeingDefined(void) const {
  return u.TagDecl->isBeingDefined();
}

bool TagDecl::IsClass(void) const {
  return u.TagDecl->isClass();
}

bool TagDecl::IsCompleteDefinition(void) const {
  return u.TagDecl->isCompleteDefinition();
}

bool TagDecl::IsCompleteDefinitionRequired(void) const {
  return u.TagDecl->isCompleteDefinitionRequired();
}

bool TagDecl::IsDependentType(void) const {
  return u.TagDecl->isDependentType();
}

bool TagDecl::IsEmbeddedInDeclarator(void) const {
  return u.TagDecl->isEmbeddedInDeclarator();
}

bool TagDecl::IsEnum(void) const {
  return u.TagDecl->isEnum();
}

bool TagDecl::IsFreeStanding(void) const {
  return u.TagDecl->isFreeStanding();
}

bool TagDecl::IsInterface(void) const {
  return u.TagDecl->isInterface();
}

bool TagDecl::IsStruct(void) const {
  return u.TagDecl->isStruct();
}

bool TagDecl::IsThisDeclarationADefinition(void) const {
  return u.TagDecl->isThisDeclarationADefinition();
}

bool TagDecl::IsUnion(void) const {
  return u.TagDecl->isUnion();
}

bool TagDecl::MayHaveOutOfDateDef(void) const {
  return u.TagDecl->mayHaveOutOfDateDef();
}

TemplateTypeParmDecl::TemplateTypeParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TemplateTypeParmDecl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const {
  return u.TemplateTypeParmDecl->defaultArgumentWasInherited();
}

  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // DefaultArgumentInfo
  // NumExpansionParameters
  // TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const {
  return u.TemplateTypeParmDecl->hasDefaultArgument();
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const {
  return u.TemplateTypeParmDecl->hasTypeConstraint();
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const {
  return u.TemplateTypeParmDecl->isExpandedParameterPack();
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const {
  return u.TemplateTypeParmDecl->isPackExpansion();
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const {
  return u.TemplateTypeParmDecl->wasDeclaredWithTypename();
}

TypeAliasDecl::TypeAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TypeAliasDecl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

  // DescribedAliasTemplate
TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TypeAliasTemplateDecl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // PreviousDecl
  // TemplatedDecl
TypedefDecl::TypedefDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::TypedefDecl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

UnresolvedUsingValueDecl::UnresolvedUsingValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::UnresolvedUsingValueDecl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
std::optional<::pasta::Token> UnresolvedUsingValueDecl::EllipsisToken(void) const {
  return ast->TokenAt(u.UnresolvedUsingValueDecl->getEllipsisLoc());
}

  // NameInfo
  // Qualifier
  // QualifierToken
std::optional<::pasta::Token> UnresolvedUsingValueDecl::UsingToken(void) const {
  return ast->TokenAt(u.UnresolvedUsingValueDecl->getUsingLoc());
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const {
  return u.UnresolvedUsingValueDecl->isAccessDeclaration();
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const {
  return u.UnresolvedUsingValueDecl->isPackExpansion();
}

VarDecl::VarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::VarDecl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

  // ActingDefinition
  // AnyInitializer
  // CanonicalDecl
  // Init
  // InitStyle
  // InitializingDeclaration
  // StorageClass
  // StorageDuration
  // TSCSpec
  // HasDefinition
bool VarDecl::HasExternalStorage(void) const {
  return u.VarDecl->hasExternalStorage();
}

bool VarDecl::HasGlobalStorage(void) const {
  return u.VarDecl->hasGlobalStorage();
}

bool VarDecl::HasLocalStorage(void) const {
  return u.VarDecl->hasLocalStorage();
}

bool VarDecl::IsARCPseudoStrong(void) const {
  return u.VarDecl->isARCPseudoStrong();
}

bool VarDecl::IsCXXForRangeDecl(void) const {
  return u.VarDecl->isCXXForRangeDecl();
}

bool VarDecl::IsConstexpr(void) const {
  return u.VarDecl->isConstexpr();
}

bool VarDecl::IsDirectInit(void) const {
  return u.VarDecl->isDirectInit();
}

bool VarDecl::IsExceptionVariable(void) const {
  return u.VarDecl->isExceptionVariable();
}

bool VarDecl::IsFileVarDecl(void) const {
  return u.VarDecl->isFileVarDecl();
}

bool VarDecl::IsFunctionOrMethodVarDecl(void) const {
  return u.VarDecl->isFunctionOrMethodVarDecl();
}

bool VarDecl::IsInitCapture(void) const {
  return u.VarDecl->isInitCapture();
}

bool VarDecl::IsInline(void) const {
  return u.VarDecl->isInline();
}

bool VarDecl::IsInlineSpecified(void) const {
  return u.VarDecl->isInlineSpecified();
}

bool VarDecl::IsLocalVarDecl(void) const {
  return u.VarDecl->isLocalVarDecl();
}

bool VarDecl::IsLocalVarDeclOrParm(void) const {
  return u.VarDecl->isLocalVarDeclOrParm();
}

bool VarDecl::IsNRVOVariable(void) const {
  return u.VarDecl->isNRVOVariable();
}

bool VarDecl::IsObjCForDecl(void) const {
  return u.VarDecl->isObjCForDecl();
}

bool VarDecl::IsPreviousDeclInSameBlockScope(void) const {
  return u.VarDecl->isPreviousDeclInSameBlockScope();
}

bool VarDecl::IsStaticDataMember(void) const {
  return u.VarDecl->isStaticDataMember();
}

bool VarDecl::IsStaticLocal(void) const {
  return u.VarDecl->isStaticLocal();
}

  // IsThisDeclarationADefinition
bool VarDecl::IsThisDeclarationADemotedDefinition(void) const {
  return u.VarDecl->isThisDeclarationADemotedDefinition();
}

VarTemplateDecl::VarTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::VarTemplateDecl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool VarTemplateDecl::IsThisDeclarationADefinition(void) const {
  return u.VarTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
VarTemplateSpecializationDecl::VarTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::VarTemplateSpecializationDecl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

  // Profile
std::optional<::pasta::Token> VarTemplateSpecializationDecl::ExternToken(void) const {
  return ast->TokenAt(u.VarTemplateSpecializationDecl->getExternLoc());
}

  // InstantiatedFrom
std::optional<::pasta::Token> VarTemplateSpecializationDecl::PointOfInstantiation(void) const {
  return ast->TokenAt(u.VarTemplateSpecializationDecl->getPointOfInstantiation());
}

  // SpecializationKind
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateArgsInfo
  // TemplateInstantiationArgs
std::optional<::pasta::Token> VarTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  return ast->TokenAt(u.VarTemplateSpecializationDecl->getTemplateKeywordLoc());
}

  // TypeAsWritten
bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  return u.VarTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  return u.VarTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  return u.VarTemplateSpecializationDecl->isExplicitSpecialization();
}

CXXDeductionGuideDecl::CXXDeductionGuideDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXDeductionGuideDecl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

  // DeducedTemplate
  // ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const {
  return u.CXXDeductionGuideDecl->isCopyDeductionCandidate();
}

bool CXXDeductionGuideDecl::IsExplicit(void) const {
  return u.CXXDeductionGuideDecl->isExplicit();
}

CXXMethodDecl::CXXMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXMethodDecl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // CorrespondingMethodDeclaredInClass
  // CorrespondingMethodInClass
  // DevirtualizedMethod
  // MethodQualifiers
  // MostRecentDecl
  // Parent
  // RefQualifier
bool CXXMethodDecl::IsConst(void) const {
  return u.CXXMethodDecl->isConst();
}

bool CXXMethodDecl::IsInstance(void) const {
  return u.CXXMethodDecl->isInstance();
}

bool CXXMethodDecl::IsVirtual(void) const {
  return u.CXXMethodDecl->isVirtual();
}

bool CXXMethodDecl::IsVolatile(void) const {
  return u.CXXMethodDecl->isVolatile();
}

ClassTemplateDecl::ClassTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ClassTemplateDecl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const {
  return u.ClassTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
DecompositionDecl::DecompositionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::DecompositionDecl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

  // Bindings
EnumDecl::EnumDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::EnumDecl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

  // Enumerators
  // CanonicalDecl
  // Definition
  // IntegerType
  // IntegerTypeSourceInfo
  // MemberSpecializationInfo
  // MostRecentDecl
  // NumNegativeBits
  // NumPositiveBits
  // PreviousDecl
  // PromotionType
bool EnumDecl::IsComplete(void) const {
  return u.EnumDecl->isComplete();
}

bool EnumDecl::IsFixed(void) const {
  return u.EnumDecl->isFixed();
}

bool EnumDecl::IsScoped(void) const {
  return u.EnumDecl->isScoped();
}

bool EnumDecl::IsScopedUsingClassTag(void) const {
  return u.EnumDecl->isScopedUsingClassTag();
}

FunctionTemplateDecl::FunctionTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::FunctionTemplateDecl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool FunctionTemplateDecl::IsAbbreviated(void) const {
  return u.FunctionTemplateDecl->isAbbreviated();
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const {
  return u.FunctionTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
ImplicitParamDecl::ImplicitParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ImplicitParamDecl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

  // ParameterKind
OMPCapturedExprDecl::OMPCapturedExprDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::OMPCapturedExprDecl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

ParmVarDecl::ParmVarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ParmVarDecl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

  // DefaultArg
  // FunctionScopeDepth
  // FunctionScopeIndex
  // ObjCDeclQualifier
  // UninstantiatedDefaultArg
bool ParmVarDecl::HasInheritedDefaultArg(void) const {
  return u.ParmVarDecl->hasInheritedDefaultArg();
}

bool ParmVarDecl::HasUninstantiatedDefaultArg(void) const {
  return u.ParmVarDecl->hasUninstantiatedDefaultArg();
}

bool ParmVarDecl::HasUnparsedDefaultArg(void) const {
  return u.ParmVarDecl->hasUnparsedDefaultArg();
}

bool ParmVarDecl::IsKNRPromoted(void) const {
  return u.ParmVarDecl->isKNRPromoted();
}

bool ParmVarDecl::IsObjCMethodParameter(void) const {
  return u.ParmVarDecl->isObjCMethodParameter();
}

RecordDecl::RecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::RecordDecl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

bool RecordDecl::CanPassInRegisters(void) const {
  return u.RecordDecl->canPassInRegisters();
}

  // Fields
  // ArgPassingRestrictions
  // Definition
  // MostRecentDecl
  // PreviousDecl
bool RecordDecl::HasFlexibleArrayMember(void) const {
  return u.RecordDecl->hasFlexibleArrayMember();
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const {
  return u.RecordDecl->hasLoadedFieldsFromExternalStorage();
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  return u.RecordDecl->hasNonTrivialToPrimitiveCopyCUnion();
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  return u.RecordDecl->hasNonTrivialToPrimitiveDefaultInitializeCUnion();
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  return u.RecordDecl->hasNonTrivialToPrimitiveDestructCUnion();
}

bool RecordDecl::HasObjectMember(void) const {
  return u.RecordDecl->hasObjectMember();
}

bool RecordDecl::HasVolatileMember(void) const {
  return u.RecordDecl->hasVolatileMember();
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const {
  return u.RecordDecl->isAnonymousStructOrUnion();
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const {
  return u.RecordDecl->isNonTrivialToPrimitiveCopy();
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  return u.RecordDecl->isNonTrivialToPrimitiveDefaultInitialize();
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const {
  return u.RecordDecl->isNonTrivialToPrimitiveDestroy();
}

bool RecordDecl::IsParamDestroyedInCallee(void) const {
  return u.RecordDecl->isParamDestroyedInCallee();
}

VarTemplatePartialSpecializationDecl::VarTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::VarTemplatePartialSpecializationDecl *decl_)
    : VarTemplateSpecializationDecl(std::move(ast_), decl_) {}

  // Profile
  // AssociatedConstraints
  // InstantiatedFromMember
  // TemplateArgsAsWritten
  // TemplateParameters
bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  return u.VarTemplatePartialSpecializationDecl->hasAssociatedConstraints();
}

CXXConstructorDecl::CXXConstructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXConstructorDecl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // ExplicitSpecifier
  // InheritedConstructor
  // NumCtorInitializers
  // Inits
bool CXXConstructorDecl::IsCopyConstructor(void) const {
  return u.CXXConstructorDecl->isCopyConstructor();
}

bool CXXConstructorDecl::IsCopyOrMoveConstructor(void) const {
  return u.CXXConstructorDecl->isCopyOrMoveConstructor();
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const {
  return u.CXXConstructorDecl->isDelegatingConstructor();
}

bool CXXConstructorDecl::IsExplicit(void) const {
  return u.CXXConstructorDecl->isExplicit();
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const {
  return u.CXXConstructorDecl->isInheritingConstructor();
}

bool CXXConstructorDecl::IsMoveConstructor(void) const {
  return u.CXXConstructorDecl->isMoveConstructor();
}

CXXConversionDecl::CXXConversionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXConversionDecl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // ConversionType
  // ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const {
  return u.CXXConversionDecl->isExplicit();
}

CXXDestructorDecl::CXXDestructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXDestructorDecl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

  // CanonicalDecl
  // OperatorDelete
  // OperatorDeleteThisArg
CXXRecordDecl::CXXRecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::CXXRecordDecl *decl_)
    : RecordDecl(std::move(ast_), decl_) {}

bool CXXRecordDecl::AllowConstDefaultInit(void) const {
  return u.CXXRecordDecl->allowConstDefaultInit();
}

  // Bases
  // Captures
  // Constructors
bool CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const {
  return u.CXXRecordDecl->defaultedCopyConstructorIsDeleted();
}

bool CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const {
  return u.CXXRecordDecl->defaultedDefaultConstructorIsConstexpr();
}

bool CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const {
  return u.CXXRecordDecl->defaultedDestructorIsConstexpr();
}

bool CXXRecordDecl::DefaultedDestructorIsDeleted(void) const {
  return u.CXXRecordDecl->defaultedDestructorIsDeleted();
}

bool CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const {
  return u.CXXRecordDecl->defaultedMoveConstructorIsDeleted();
}

  // Friends
  // CanonicalDecl
  // Definition
  // LambdaCaptureDefault
  // LambdaManglingNumber
  // LambdaTypeInfo
  // MostRecentDecl
  // MostRecentNonInjectedDecl
  // NumBases
  // NumVBases
  // PreviousDecl
bool CXXRecordDecl::HasConstexprDefaultConstructor(void) const {
  return u.CXXRecordDecl->hasConstexprDefaultConstructor();
}

bool CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const {
  return u.CXXRecordDecl->hasConstexprNonCopyMoveConstructor();
}

bool CXXRecordDecl::HasCopyAssignmentWithConstParam(void) const {
  return u.CXXRecordDecl->hasCopyAssignmentWithConstParam();
}

bool CXXRecordDecl::HasCopyConstructorWithConstParam(void) const {
  return u.CXXRecordDecl->hasCopyConstructorWithConstParam();
}

bool CXXRecordDecl::HasDefaultConstructor(void) const {
  return u.CXXRecordDecl->hasDefaultConstructor();
}

bool CXXRecordDecl::HasDefinition(void) const {
  return u.CXXRecordDecl->hasDefinition();
}

bool CXXRecordDecl::HasDirectFields(void) const {
  return u.CXXRecordDecl->hasDirectFields();
}

bool CXXRecordDecl::HasFriends(void) const {
  return u.CXXRecordDecl->hasFriends();
}

bool CXXRecordDecl::HasInClassInitializer(void) const {
  return u.CXXRecordDecl->hasInClassInitializer();
}

bool CXXRecordDecl::HasInheritedAssignment(void) const {
  return u.CXXRecordDecl->hasInheritedAssignment();
}

bool CXXRecordDecl::HasInheritedConstructor(void) const {
  return u.CXXRecordDecl->hasInheritedConstructor();
}

bool CXXRecordDecl::HasIrrelevantDestructor(void) const {
  return u.CXXRecordDecl->hasIrrelevantDestructor();
}

bool CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const {
  return u.CXXRecordDecl->hasKnownLambdaInternalLinkage();
}

bool CXXRecordDecl::HasMoveAssignment(void) const {
  return u.CXXRecordDecl->hasMoveAssignment();
}

bool CXXRecordDecl::HasMoveConstructor(void) const {
  return u.CXXRecordDecl->hasMoveConstructor();
}

bool CXXRecordDecl::HasMutableFields(void) const {
  return u.CXXRecordDecl->hasMutableFields();
}

bool CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const {
  return u.CXXRecordDecl->hasNonLiteralTypeFieldsOrBases();
}

bool CXXRecordDecl::HasNonTrivialCopyAssignment(void) const {
  return u.CXXRecordDecl->hasNonTrivialCopyAssignment();
}

bool CXXRecordDecl::HasNonTrivialCopyConstructor(void) const {
  return u.CXXRecordDecl->hasNonTrivialCopyConstructor();
}

bool CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const {
  return u.CXXRecordDecl->hasNonTrivialCopyConstructorForCall();
}

bool CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const {
  return u.CXXRecordDecl->hasNonTrivialDefaultConstructor();
}

bool CXXRecordDecl::HasNonTrivialDestructor(void) const {
  return u.CXXRecordDecl->hasNonTrivialDestructor();
}

bool CXXRecordDecl::HasNonTrivialDestructorForCall(void) const {
  return u.CXXRecordDecl->hasNonTrivialDestructorForCall();
}

bool CXXRecordDecl::HasNonTrivialMoveAssignment(void) const {
  return u.CXXRecordDecl->hasNonTrivialMoveAssignment();
}

bool CXXRecordDecl::HasNonTrivialMoveConstructor(void) const {
  return u.CXXRecordDecl->hasNonTrivialMoveConstructor();
}

bool CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const {
  return u.CXXRecordDecl->hasNonTrivialMoveConstructorForCall();
}

bool CXXRecordDecl::HasPrivateFields(void) const {
  return u.CXXRecordDecl->hasPrivateFields();
}

bool CXXRecordDecl::HasProtectedFields(void) const {
  return u.CXXRecordDecl->hasProtectedFields();
}

bool CXXRecordDecl::HasSimpleCopyAssignment(void) const {
  return u.CXXRecordDecl->hasSimpleCopyAssignment();
}

bool CXXRecordDecl::HasSimpleCopyConstructor(void) const {
  return u.CXXRecordDecl->hasSimpleCopyConstructor();
}

bool CXXRecordDecl::HasSimpleDestructor(void) const {
  return u.CXXRecordDecl->hasSimpleDestructor();
}

bool CXXRecordDecl::HasSimpleMoveAssignment(void) const {
  return u.CXXRecordDecl->hasSimpleMoveAssignment();
}

bool CXXRecordDecl::HasSimpleMoveConstructor(void) const {
  return u.CXXRecordDecl->hasSimpleMoveConstructor();
}

bool CXXRecordDecl::HasTrivialCopyAssignment(void) const {
  return u.CXXRecordDecl->hasTrivialCopyAssignment();
}

bool CXXRecordDecl::HasTrivialCopyConstructor(void) const {
  return u.CXXRecordDecl->hasTrivialCopyConstructor();
}

bool CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const {
  return u.CXXRecordDecl->hasTrivialCopyConstructorForCall();
}

bool CXXRecordDecl::HasTrivialDefaultConstructor(void) const {
  return u.CXXRecordDecl->hasTrivialDefaultConstructor();
}

bool CXXRecordDecl::HasTrivialDestructor(void) const {
  return u.CXXRecordDecl->hasTrivialDestructor();
}

bool CXXRecordDecl::HasTrivialDestructorForCall(void) const {
  return u.CXXRecordDecl->hasTrivialDestructorForCall();
}

bool CXXRecordDecl::HasTrivialMoveAssignment(void) const {
  return u.CXXRecordDecl->hasTrivialMoveAssignment();
}

bool CXXRecordDecl::HasTrivialMoveConstructor(void) const {
  return u.CXXRecordDecl->hasTrivialMoveConstructor();
}

bool CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const {
  return u.CXXRecordDecl->hasTrivialMoveConstructorForCall();
}

bool CXXRecordDecl::HasUninitializedReferenceMember(void) const {
  return u.CXXRecordDecl->hasUninitializedReferenceMember();
}

bool CXXRecordDecl::HasUserDeclaredConstructor(void) const {
  return u.CXXRecordDecl->hasUserDeclaredConstructor();
}

bool CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const {
  return u.CXXRecordDecl->hasUserDeclaredCopyAssignment();
}

bool CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const {
  return u.CXXRecordDecl->hasUserDeclaredCopyConstructor();
}

bool CXXRecordDecl::HasUserDeclaredDestructor(void) const {
  return u.CXXRecordDecl->hasUserDeclaredDestructor();
}

bool CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const {
  return u.CXXRecordDecl->hasUserDeclaredMoveAssignment();
}

bool CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const {
  return u.CXXRecordDecl->hasUserDeclaredMoveConstructor();
}

bool CXXRecordDecl::HasUserDeclaredMoveOperation(void) const {
  return u.CXXRecordDecl->hasUserDeclaredMoveOperation();
}

bool CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const {
  return u.CXXRecordDecl->hasUserProvidedDefaultConstructor();
}

bool CXXRecordDecl::HasVariantMembers(void) const {
  return u.CXXRecordDecl->hasVariantMembers();
}

bool CXXRecordDecl::ImplicitCopyAssignmentHasConstParam(void) const {
  return u.CXXRecordDecl->implicitCopyAssignmentHasConstParam();
}

bool CXXRecordDecl::ImplicitCopyConstructorHasConstParam(void) const {
  return u.CXXRecordDecl->implicitCopyConstructorHasConstParam();
}

bool CXXRecordDecl::IsAbstract(void) const {
  return u.CXXRecordDecl->isAbstract();
}

bool CXXRecordDecl::IsAggregate(void) const {
  return u.CXXRecordDecl->isAggregate();
}

bool CXXRecordDecl::IsCXX11StandardLayout(void) const {
  return u.CXXRecordDecl->isCXX11StandardLayout();
}

bool CXXRecordDecl::IsDependentLambda(void) const {
  return u.CXXRecordDecl->isDependentLambda();
}

bool CXXRecordDecl::IsDynamicClass(void) const {
  return u.CXXRecordDecl->isDynamicClass();
}

bool CXXRecordDecl::IsEmpty(void) const {
  return u.CXXRecordDecl->isEmpty();
}

bool CXXRecordDecl::IsLambda(void) const {
  return u.CXXRecordDecl->isLambda();
}

bool CXXRecordDecl::IsLiteral(void) const {
  return u.CXXRecordDecl->isLiteral();
}

  // IsLocalClass
bool CXXRecordDecl::IsPOD(void) const {
  return u.CXXRecordDecl->isPOD();
}

bool CXXRecordDecl::IsParsingBaseSpecifiers(void) const {
  return u.CXXRecordDecl->isParsingBaseSpecifiers();
}

bool CXXRecordDecl::IsPolymorphic(void) const {
  return u.CXXRecordDecl->isPolymorphic();
}

bool CXXRecordDecl::IsStandardLayout(void) const {
  return u.CXXRecordDecl->isStandardLayout();
}

bool CXXRecordDecl::IsTrivial(void) const {
  return u.CXXRecordDecl->isTrivial();
}

bool CXXRecordDecl::MayBeDynamicClass(void) const {
  return u.CXXRecordDecl->mayBeDynamicClass();
}

bool CXXRecordDecl::MayBeNonDynamicClass(void) const {
  return u.CXXRecordDecl->mayBeNonDynamicClass();
}

  // Methods
bool CXXRecordDecl::NeedsImplicitCopyAssignment(void) const {
  return u.CXXRecordDecl->needsImplicitCopyAssignment();
}

bool CXXRecordDecl::NeedsImplicitCopyConstructor(void) const {
  return u.CXXRecordDecl->needsImplicitCopyConstructor();
}

bool CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const {
  return u.CXXRecordDecl->needsImplicitDefaultConstructor();
}

bool CXXRecordDecl::NeedsImplicitDestructor(void) const {
  return u.CXXRecordDecl->needsImplicitDestructor();
}

bool CXXRecordDecl::NeedsImplicitMoveAssignment(void) const {
  return u.CXXRecordDecl->needsImplicitMoveAssignment();
}

bool CXXRecordDecl::NeedsImplicitMoveConstructor(void) const {
  return u.CXXRecordDecl->needsImplicitMoveConstructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const {
  return u.CXXRecordDecl->needsOverloadResolutionForCopyAssignment();
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const {
  return u.CXXRecordDecl->needsOverloadResolutionForCopyConstructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const {
  return u.CXXRecordDecl->needsOverloadResolutionForDestructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const {
  return u.CXXRecordDecl->needsOverloadResolutionForMoveAssignment();
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const {
  return u.CXXRecordDecl->needsOverloadResolutionForMoveConstructor();
}

  // VirtualBases
ClassTemplateSpecializationDecl::ClassTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ClassTemplateSpecializationDecl *decl_)
    : CXXRecordDecl(std::move(ast_), decl_) {}

  // Profile
std::optional<::pasta::Token> ClassTemplateSpecializationDecl::ExternToken(void) const {
  return ast->TokenAt(u.ClassTemplateSpecializationDecl->getExternLoc());
}

  // InstantiatedFrom
std::optional<::pasta::Token> ClassTemplateSpecializationDecl::PointOfInstantiation(void) const {
  return ast->TokenAt(u.ClassTemplateSpecializationDecl->getPointOfInstantiation());
}

  // SpecializationKind
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateInstantiationArgs
std::optional<::pasta::Token> ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  return ast->TokenAt(u.ClassTemplateSpecializationDecl->getTemplateKeywordLoc());
}

  // TypeAsWritten
bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  return u.ClassTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  return u.ClassTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  return u.ClassTemplateSpecializationDecl->isExplicitSpecialization();
}

ClassTemplatePartialSpecializationDecl::ClassTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::ClassTemplatePartialSpecializationDecl *decl_)
    : ClassTemplateSpecializationDecl(std::move(ast_), decl_) {}

  // Profile
  // AssociatedConstraints
  // InjectedSpecializationType
  // InstantiatedFromMember
  // InstantiatedFromMemberTemplate
  // TemplateArgsAsWritten
  // TemplateParameters
bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  return u.ClassTemplatePartialSpecializationDecl->hasAssociatedConstraints();
}

}  // namespace pasta
