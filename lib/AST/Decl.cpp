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
Decl::Decl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::Decl *decl_)
    : DeclBase(ast_, decl_) {}
  // Attrs
  // Access
  // AccessUnsafe
  // AsFunction
  // BeginToken
  // Body
  // CanonicalDecl
  // DeclContext
  // EndToken
  // FriendObjectKind
  // GlobalID
  // IdentifierNamespace
  // ImportedOwningModule
  // Kind
  // LexicalDeclContext
  // LocalOwningModule
  // Token
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
  return this->Decl::u.Decl->hasAttrs();
}

bool Decl::HasBody(void) const {
  return this->Decl::u.Decl->hasBody();
}

bool Decl::HasOwningModule(void) const {
  return this->Decl::u.Decl->hasOwningModule();
}

bool Decl::HasTagIdentifierNamespace(void) const {
  return this->Decl::u.Decl->hasTagIdentifierNamespace();
}

bool Decl::IsCanonicalDecl(void) const {
  return this->Decl::u.Decl->isCanonicalDecl();
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const {
  return this->Decl::u.Decl->isDefinedOutsideFunctionOrMethod();
}

bool Decl::IsDeprecated(void) const {
  return this->Decl::u.Decl->isDeprecated();
}

bool Decl::IsFirstDecl(void) const {
  return this->Decl::u.Decl->isFirstDecl();
}

bool Decl::IsFromASTFile(void) const {
  return this->Decl::u.Decl->isFromASTFile();
}

bool Decl::IsFunctionOrFunctionTemplate(void) const {
  return this->Decl::u.Decl->isFunctionOrFunctionTemplate();
}

bool Decl::IsImplicit(void) const {
  return this->Decl::u.Decl->isImplicit();
}

  // IsInIdentifierNamespace
bool Decl::IsInvalidDecl(void) const {
  return this->Decl::u.Decl->isInvalidDecl();
}

bool Decl::IsModulePrivate(void) const {
  return this->Decl::u.Decl->isModulePrivate();
}

bool Decl::IsTemplateParameter(void) const {
  return this->Decl::u.Decl->isTemplateParameter();
}

bool Decl::IsThisDeclarationReferenced(void) const {
  return this->Decl::u.Decl->isThisDeclarationReferenced();
}

bool Decl::IsTopLevelDeclInObjCContainer(void) const {
  return this->Decl::u.Decl->isTopLevelDeclInObjCContainer();
}

bool Decl::IsUnavailable(void) const {
  return this->Decl::u.Decl->isUnavailable();
}

bool Decl::IsUnconditionallyVisible(void) const {
  return this->Decl::u.Decl->isUnconditionallyVisible();
}

  // Redecls
DeclContext::DeclContext(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::DeclContext *decl_)
    : DeclBase(ast_, decl_, 0) {}
  // Equals
  // Decls
  // DeclKind
  // EnclosingNamespaceContext
  // LexicalParent
  // LookupParent
  // LookupPtr
  // NonClosureAncestor
  // OuterLexicalRecordContext
  // Parent
  // ParentASTContext
  // PrimaryContext
  // RedeclContext
bool DeclContext::HasExternalLexicalStorage(void) const {
  return this->DeclBase::u.DeclContext->hasExternalLexicalStorage();
}

bool DeclContext::HasExternalVisibleStorage(void) const {
  return this->DeclBase::u.DeclContext->hasExternalVisibleStorage();
}

bool DeclContext::IsClosure(void) const {
  return this->DeclBase::u.DeclContext->isClosure();
}

  // IsDeclInLexicalTraversal
bool DeclContext::IsFileContext(void) const {
  return this->DeclBase::u.DeclContext->isFileContext();
}

bool DeclContext::IsFunctionOrMethod(void) const {
  return this->DeclBase::u.DeclContext->isFunctionOrMethod();
}

bool DeclContext::IsLookupContext(void) const {
  return this->DeclBase::u.DeclContext->isLookupContext();
}

bool DeclContext::IsNamespace(void) const {
  return this->DeclBase::u.DeclContext->isNamespace();
}

bool DeclContext::IsObjCContainer(void) const {
  return this->DeclBase::u.DeclContext->isObjCContainer();
}

bool DeclContext::IsRecord(void) const {
  return this->DeclBase::u.DeclContext->isRecord();
}

bool DeclContext::IsTranslationUnit(void) const {
  return this->DeclBase::u.DeclContext->isTranslationUnit();
}

  // Noload_decls
bool DeclContext::ShouldUseQualifiedLookup(void) const {
  return this->DeclBase::u.DeclContext->shouldUseQualifiedLookup();
}

EmptyDecl::EmptyDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::EmptyDecl *decl_)
    : Decl(ast_, decl_) {}

ExportDecl::ExportDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ExportDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // EndToken
  // ExportToken
  // RBraceToken
  // TokenRange
bool ExportDecl::HasBraces(void) const {
  return this->Decl::u.ExportDecl->hasBraces();
}

ExternCContextDecl::ExternCContextDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ExternCContextDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

FileScopeAsmDecl::FileScopeAsmDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FileScopeAsmDecl *decl_)
    : Decl(ast_, decl_) {}

  // AsmToken
  // AsmString
  // RParenToken
  // TokenRange
FriendDecl::FriendDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FriendDecl *decl_)
    : Decl(ast_, decl_) {}

  // FriendDecl
  // FriendToken
  // FriendType
  // FriendTypeNumTemplateParameterLists
  // FriendTypeTemplateParameterList
  // TokenRange
bool FriendDecl::IsUnsupportedFriend(void) const {
  return this->Decl::u.FriendDecl->isUnsupportedFriend();
}

FriendTemplateDecl::FriendTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FriendTemplateDecl *decl_)
    : Decl(ast_, decl_) {}

  // FriendDecl
  // FriendToken
  // FriendType
  // NumTemplateParameters
  // TemplateParameterList
ImportDecl::ImportDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ImportDecl *decl_)
    : Decl(ast_, decl_) {}

  // ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::LifetimeExtendedTemporaryDecl *decl_)
    : Decl(ast_, decl_) {}

  // ChildrenExpr
  // ExtendingDecl
  // ManglingNumber
  // TemporaryExpr
  // Value
LinkageSpecDecl::LinkageSpecDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::LinkageSpecDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // EndToken
  // ExternToken
  // Language
  // RBraceToken
  // TokenRange
bool LinkageSpecDecl::HasBraces(void) const {
  return this->Decl::u.LinkageSpecDecl->hasBraces();
}

NamedDecl::NamedDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::NamedDecl *decl_)
    : Decl(ast_, decl_) {}

  // DeclName
  // FormalLinkage
  // Identifier
  // MostRecentDecl
  // Name
  // NameAsString
  // UnderlyingDecl
  // Visibility
bool NamedDecl::HasExternalFormalLinkage(void) const {
  return this->Decl::u.NamedDecl->hasExternalFormalLinkage();
}

bool NamedDecl::HasLinkageBeenComputed(void) const {
  return this->Decl::u.NamedDecl->hasLinkageBeenComputed();
}

bool NamedDecl::IsCXXClassMember(void) const {
  return this->Decl::u.NamedDecl->isCXXClassMember();
}

bool NamedDecl::IsExternallyDeclarable(void) const {
  return this->Decl::u.NamedDecl->isExternallyDeclarable();
}

bool NamedDecl::IsExternallyVisible(void) const {
  return this->Decl::u.NamedDecl->isExternallyVisible();
}

NamespaceAliasDecl::NamespaceAliasDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::NamespaceAliasDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // AliasToken
  // AliasedNamespace
  // CanonicalDecl
  // Namespace
  // NamespaceToken
  // Qualifier
  // QualifierToken
  // TokenRange
  // TargetNameToken
NamespaceDecl::NamespaceDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::NamespaceDecl *decl_)
    : NamedDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // AnonymousNamespace
  // BeginToken
  // CanonicalDecl
  // RBraceToken
  // TokenRange
bool NamespaceDecl::IsAnonymousNamespace(void) const {
  return this->Decl::u.NamespaceDecl->isAnonymousNamespace();
}

bool NamespaceDecl::IsInline(void) const {
  return this->Decl::u.NamespaceDecl->isInline();
}

OMPAllocateDecl::OMPAllocateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPAllocateDecl *decl_)
    : Decl(ast_, decl_) {}

  // Clauselists
  // Varlists
OMPRequiresDecl::OMPRequiresDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPRequiresDecl *decl_)
    : Decl(ast_, decl_) {}

  // Clauselists
OMPThreadPrivateDecl::OMPThreadPrivateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPThreadPrivateDecl *decl_)
    : Decl(ast_, decl_) {}

  // Varlists
ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCCompatibleAliasDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // ClassInterface
ObjCContainerDecl::ObjCContainerDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCContainerDecl *decl_)
    : NamedDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // Class_methods
  // Class_properties
  // CollectPropertiesToImplement
  // AtEndRange
  // AtStartToken
  // ClassMethod
  // InstanceMethod
  // TokenRange
  // Instance_methods
  // Instance_properties
  // Methods
  // Properties
ObjCImplDecl::ObjCImplDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCImplDecl *decl_)
    : ObjCContainerDecl(ast_, decl_) {}

  // ClassInterface
  // Property_impls
ObjCImplementationDecl::ObjCImplementationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCImplementationDecl *decl_)
    : ObjCImplDecl(ast_, decl_) {}

  // Identifier
  // IvarLBraceToken
  // IvarRBraceToken
  // Name
  // NameAsString
  // NumIvarInitializers
  // SuperClass
  // SuperClassToken
bool ObjCImplementationDecl::HasDestructors(void) const {
  return this->Decl::u.ObjCImplementationDecl->hasDestructors();
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const {
  return this->Decl::u.ObjCImplementationDecl->hasNonZeroConstructors();
}

  // Inits
  // Ivars
ObjCInterfaceDecl::ObjCInterfaceDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCInterfaceDecl *decl_)
    : ObjCContainerDecl(ast_, decl_) {}

  // All_referenced_protocols
bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const {
  return this->Decl::u.ObjCInterfaceDecl->declaresOrInheritsDesignatedInitializers();
}

  // CanonicalDecl
  // CategoryListRaw
  // CategoryMethod
  // Definition
  // EndOfDefinitionToken
  // ReferencedProtocols
  // TokenRange
  // SuperClassTInfo
  // SuperClassType
  // TypeForDecl
  // TypeParamListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const {
  return this->Decl::u.ObjCInterfaceDecl->hasDefinition();
}

bool ObjCInterfaceDecl::IsImplicitInterfaceDecl(void) const {
  return this->Decl::u.ObjCInterfaceDecl->isImplicitInterfaceDecl();
}

  // IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.ObjCInterfaceDecl->isThisDeclarationADefinition();
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
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCMethodDecl *decl_)
    : NamedDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // BeginToken
  // CanonicalDecl
  // ClassInterface
  // CmdDecl
  // DeclaratorEndToken
  // ImplementationControl
  // NumSelectorLocs
  // ObjCDeclQualifier
  // ParamDecl
  // ReturnType
  // ReturnTypeSourceInfo
  // Selector
  // SelectorToken
  // SelectorStartToken
  // SelfDecl
  // TokenRange
bool ObjCMethodDecl::HasBody(void) const {
  return this->Decl::u.ObjCMethodDecl->hasBody();
}

bool ObjCMethodDecl::HasRedeclaration(void) const {
  return this->Decl::u.ObjCMethodDecl->hasRedeclaration();
}

bool ObjCMethodDecl::HasRelatedResultType(void) const {
  return this->Decl::u.ObjCMethodDecl->hasRelatedResultType();
}

bool ObjCMethodDecl::HasSkippedBody(void) const {
  return this->Decl::u.ObjCMethodDecl->hasSkippedBody();
}

bool ObjCMethodDecl::IsClassMethod(void) const {
  return this->Decl::u.ObjCMethodDecl->isClassMethod();
}

bool ObjCMethodDecl::IsDefined(void) const {
  return this->Decl::u.ObjCMethodDecl->isDefined();
}

bool ObjCMethodDecl::IsInstanceMethod(void) const {
  return this->Decl::u.ObjCMethodDecl->isInstanceMethod();
}

bool ObjCMethodDecl::IsOptional(void) const {
  return this->Decl::u.ObjCMethodDecl->isOptional();
}

bool ObjCMethodDecl::IsOverriding(void) const {
  return this->Decl::u.ObjCMethodDecl->isOverriding();
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const {
  return this->Decl::u.ObjCMethodDecl->isPropertyAccessor();
}

bool ObjCMethodDecl::IsRedeclaration(void) const {
  return this->Decl::u.ObjCMethodDecl->isRedeclaration();
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const {
  return this->Decl::u.ObjCMethodDecl->isSynthesizedAccessorStub();
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.ObjCMethodDecl->isThisDeclarationADefinition();
}

bool ObjCMethodDecl::IsVariadic(void) const {
  return this->Decl::u.ObjCMethodDecl->isVariadic();
}

  // Parameters
ObjCPropertyDecl::ObjCPropertyDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCPropertyDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // AtToken
  // GetterMethodDecl
  // GetterName
  // GetterNameToken
  // LParenToken
  // PropertyAttributes
  // PropertyAttributesAsWritten
  // PropertyImplementation
  // PropertyIvarDecl
  // QueryKind
  // SetterKind
  // SetterMethodDecl
  // SetterName
  // SetterNameToken
  // TokenRange
  // Type
  // TypeSourceInfo
bool ObjCPropertyDecl::IsAtomic(void) const {
  return this->Decl::u.ObjCPropertyDecl->isAtomic();
}

bool ObjCPropertyDecl::IsClassProperty(void) const {
  return this->Decl::u.ObjCPropertyDecl->isClassProperty();
}

bool ObjCPropertyDecl::IsDirectProperty(void) const {
  return this->Decl::u.ObjCPropertyDecl->isDirectProperty();
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const {
  return this->Decl::u.ObjCPropertyDecl->isInstanceProperty();
}

bool ObjCPropertyDecl::IsOptional(void) const {
  return this->Decl::u.ObjCPropertyDecl->isOptional();
}

bool ObjCPropertyDecl::IsReadOnly(void) const {
  return this->Decl::u.ObjCPropertyDecl->isReadOnly();
}

bool ObjCPropertyDecl::IsRetaining(void) const {
  return this->Decl::u.ObjCPropertyDecl->isRetaining();
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCPropertyImplDecl *decl_)
    : Decl(ast_, decl_) {}

  // BeginToken
  // GetterCXXConstructor
  // GetterMethodDecl
  // PropertyDecl
  // PropertyImplementation
  // PropertyIvarDecl
  // PropertyIvarDeclToken
  // SetterCXXAssignment
  // SetterMethodDecl
bool ObjCPropertyImplDecl::IsIvarNameSpecified(void) const {
  return this->Decl::u.ObjCPropertyImplDecl->isIvarNameSpecified();
}

ObjCProtocolDecl::ObjCProtocolDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCProtocolDecl *decl_)
    : ObjCContainerDecl(ast_, decl_) {}

  // CanonicalDecl
  // Definition
  // ReferencedProtocols
  // TokenRange
bool ObjCProtocolDecl::HasDefinition(void) const {
  return this->Decl::u.ObjCProtocolDecl->hasDefinition();
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.ObjCProtocolDecl->isThisDeclarationADefinition();
}

  // LookupClassMethod
  // LookupInstanceMethod
  // Protocol_locs
  // Protocols
PragmaCommentDecl::PragmaCommentDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::PragmaCommentDecl *decl_)
    : Decl(ast_, decl_) {}

  // Arg
  // CommentKind
PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::PragmaDetectMismatchDecl *decl_)
    : Decl(ast_, decl_) {}

  // Name
  // Value
RequiresExprBodyDecl::RequiresExprBodyDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::RequiresExprBodyDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

StaticAssertDecl::StaticAssertDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::StaticAssertDecl *decl_)
    : Decl(ast_, decl_) {}

  // AssertExpr
  // Message
  // RParenToken
  // TokenRange
bool StaticAssertDecl::IsFailed(void) const {
  return this->Decl::u.StaticAssertDecl->isFailed();
}

TemplateDecl::TemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TemplateDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // TokenRange
  // TemplateParameters
  // TemplatedDecl
TemplateTemplateParmDecl::TemplateTemplateParmDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TemplateTemplateParmDecl *decl_)
    : TemplateDecl(ast_, decl_) {}

bool TemplateTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  return this->Decl::u.TemplateTemplateParmDecl->defaultArgumentWasInherited();
}

  // DefaultArgStorage
  // DefaultArgument
  // ExpansionTemplateParameters
  // NumExpansionTemplateParameters
  // TokenRange
bool TemplateTemplateParmDecl::HasDefaultArgument(void) const {
  return this->Decl::u.TemplateTemplateParmDecl->hasDefaultArgument();
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const {
  return this->Decl::u.TemplateTemplateParmDecl->isExpandedParameterPack();
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const {
  return this->Decl::u.TemplateTemplateParmDecl->isPackExpansion();
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const {
  return this->Decl::u.TemplateTemplateParmDecl->isParameterPack();
}

TranslationUnitDecl::TranslationUnitDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TranslationUnitDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // ASTContext
  // AnonymousNamespace
TypeDecl::TypeDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TypeDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // BeginToken
  // TokenRange
  // TypeForDecl
TypedefNameDecl::TypedefNameDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TypedefNameDecl *decl_)
    : TypeDecl(ast_, decl_) {}

  // CanonicalDecl
  // TypeSourceInfo
  // UnderlyingType
bool TypedefNameDecl::IsModed(void) const {
  return this->Decl::u.TypedefNameDecl->isModed();
}

bool TypedefNameDecl::IsTransparentTag(void) const {
  return this->Decl::u.TypedefNameDecl->isTransparentTag();
}

UnresolvedUsingTypenameDecl::UnresolvedUsingTypenameDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UnresolvedUsingTypenameDecl *decl_)
    : TypeDecl(ast_, decl_) {}

  // CanonicalDecl
  // EllipsisToken
  // NameInfo
  // Qualifier
  // QualifierToken
  // TypenameToken
  // UsingToken
bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const {
  return this->Decl::u.UnresolvedUsingTypenameDecl->isPackExpansion();
}

UsingDecl::UsingDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UsingDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // CanonicalDecl
  // NameInfo
  // Qualifier
  // QualifierToken
  // UsingToken
bool UsingDecl::HasTypename(void) const {
  return this->Decl::u.UsingDecl->hasTypename();
}

bool UsingDecl::IsAccessDeclaration(void) const {
  return this->Decl::u.UsingDecl->isAccessDeclaration();
}

  // Shadows
UsingDirectiveDecl::UsingDirectiveDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UsingDirectiveDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // CommonAncestor
  // IdentLocation
  // NamespaceKeyLocation
  // NominatedNamespace
  // NominatedNamespaceAsWritten
  // Qualifier
  // QualifierToken
  // TokenRange
  // UsingToken
UsingPackDecl::UsingPackDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UsingPackDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // Expansions
  // CanonicalDecl
  // InstantiatedFromUsingDecl
  // TokenRange
UsingShadowDecl::UsingShadowDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UsingShadowDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // CanonicalDecl
  // NextUsingShadowDecl
  // TargetDecl
ValueDecl::ValueDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ValueDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // Type
AccessSpecDecl::AccessSpecDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::AccessSpecDecl *decl_)
    : Decl(ast_, decl_) {}

  // AccessSpecifierToken
  // ColonToken
  // TokenRange
BindingDecl::BindingDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::BindingDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // Binding
BlockDecl::BlockDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::BlockDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

bool BlockDecl::BlockMissingReturnType(void) const {
  return this->Decl::u.BlockDecl->blockMissingReturnType();
}

bool BlockDecl::CanAvoidCopyToHeap(void) const {
  return this->Decl::u.BlockDecl->canAvoidCopyToHeap();
}

  // Captures
bool BlockDecl::CapturesCXXThis(void) const {
  return this->Decl::u.BlockDecl->capturesCXXThis();
}

bool BlockDecl::DoesNotEscape(void) const {
  return this->Decl::u.BlockDecl->doesNotEscape();
}

  // BlockManglingContextDecl
  // BlockManglingNumber
  // Body
  // CaretLocation
  // CompoundBody
  // NumCaptures
  // NumParams
  // ParamDecl
  // SignatureAsWritten
bool BlockDecl::HasCaptures(void) const {
  return this->Decl::u.BlockDecl->hasCaptures();
}

bool BlockDecl::IsConversionFromLambda(void) const {
  return this->Decl::u.BlockDecl->isConversionFromLambda();
}

bool BlockDecl::IsVariadic(void) const {
  return this->Decl::u.BlockDecl->isVariadic();
}

  // Parameters
BuiltinTemplateDecl::BuiltinTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::BuiltinTemplateDecl *decl_)
    : TemplateDecl(ast_, decl_) {}

  // BuiltinTemplateKind
  // TokenRange
CapturedDecl::CapturedDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CapturedDecl *decl_)
    : Decl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // ContextParam
  // ContextParamPosition
  // NumParams
  // Param
  // Parameters
ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ClassScopeFunctionSpecializationDecl *decl_)
    : Decl(ast_, decl_) {}

  // Specialization
  // TemplateArgsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArgs(void) const {
  return this->Decl::u.ClassScopeFunctionSpecializationDecl->hasExplicitTemplateArgs();
}

ConceptDecl::ConceptDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ConceptDecl *decl_)
    : TemplateDecl(ast_, decl_) {}

  // ConstraintExpr
  // TokenRange
bool ConceptDecl::IsTypeConcept(void) const {
  return this->Decl::u.ConceptDecl->isTypeConcept();
}

ConstructorUsingShadowDecl::ConstructorUsingShadowDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ConstructorUsingShadowDecl *decl_)
    : UsingShadowDecl(ast_, decl_) {}

bool ConstructorUsingShadowDecl::ConstructsVirtualBase(void) const {
  return this->Decl::u.ConstructorUsingShadowDecl->constructsVirtualBase();
}

  // ConstructedBaseClass
  // ConstructedBaseClassShadowDecl
  // NominatedBaseClassShadowDecl
  // Parent
DeclaratorDecl::DeclaratorDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::DeclaratorDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // BeginToken
  // InnerLocStart
  // NumTemplateParameterLists
  // Qualifier
  // QualifierToken
  // TemplateParameterList
  // TrailingRequiresClause
  // TypeSourceInfo
EnumConstantDecl::EnumConstantDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::EnumConstantDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // CanonicalDecl
  // InitExpr
  // InitVal
FieldDecl::FieldDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FieldDecl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

  // BitWidth
  // CanonicalDecl
  // CapturedVLAType
  // InClassInitStyle
  // InClassInitializer
  // Parent
bool FieldDecl::HasCapturedVLAType(void) const {
  return this->Decl::u.FieldDecl->hasCapturedVLAType();
}

bool FieldDecl::HasInClassInitializer(void) const {
  return this->Decl::u.FieldDecl->hasInClassInitializer();
}

bool FieldDecl::IsBitField(void) const {
  return this->Decl::u.FieldDecl->isBitField();
}

bool FieldDecl::IsMutable(void) const {
  return this->Decl::u.FieldDecl->isMutable();
}

bool FieldDecl::IsUnnamedBitfield(void) const {
  return this->Decl::u.FieldDecl->isUnnamedBitfield();
}

FunctionDecl::FunctionDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FunctionDecl *decl_)
    : DeclaratorDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

bool FunctionDecl::DoesThisDeclarationHaveABody(void) const {
  return this->Decl::u.FunctionDecl->doesThisDeclarationHaveABody();
}

  // AssociatedConstraints
  // Body
  // CallResultType
  // CanonicalDecl
  // ConstexprKind
  // DeclaredReturnType
  // Definition
  // EllipsisToken
  // ExceptionSpecType
  // NameInfo
  // ParamDecl
  // ReturnType
  // StorageClass
bool FunctionDecl::HasBody(void) const {
  return this->Decl::u.FunctionDecl->hasBody();
}

bool FunctionDecl::HasImplicitReturnZero(void) const {
  return this->Decl::u.FunctionDecl->hasImplicitReturnZero();
}

bool FunctionDecl::HasInheritedPrototype(void) const {
  return this->Decl::u.FunctionDecl->hasInheritedPrototype();
}

bool FunctionDecl::HasPrototype(void) const {
  return this->Decl::u.FunctionDecl->hasPrototype();
}

bool FunctionDecl::HasSkippedBody(void) const {
  return this->Decl::u.FunctionDecl->hasSkippedBody();
}

bool FunctionDecl::HasWrittenPrototype(void) const {
  return this->Decl::u.FunctionDecl->hasWrittenPrototype();
}

bool FunctionDecl::InstantiationIsPending(void) const {
  return this->Decl::u.FunctionDecl->instantiationIsPending();
}

bool FunctionDecl::IsConsteval(void) const {
  return this->Decl::u.FunctionDecl->isConsteval();
}

bool FunctionDecl::IsConstexpr(void) const {
  return this->Decl::u.FunctionDecl->isConstexpr();
}

bool FunctionDecl::IsConstexprSpecified(void) const {
  return this->Decl::u.FunctionDecl->isConstexprSpecified();
}

bool FunctionDecl::IsDefaulted(void) const {
  return this->Decl::u.FunctionDecl->isDefaulted();
}

bool FunctionDecl::IsDefined(void) const {
  return this->Decl::u.FunctionDecl->isDefined();
}

bool FunctionDecl::IsDeleted(void) const {
  return this->Decl::u.FunctionDecl->isDeleted();
}

bool FunctionDecl::IsDeletedAsWritten(void) const {
  return this->Decl::u.FunctionDecl->isDeletedAsWritten();
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const {
  return this->Decl::u.FunctionDecl->isExplicitlyDefaulted();
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const {
  return this->Decl::u.FunctionDecl->isFunctionTemplateSpecialization();
}

bool FunctionDecl::IsInlineSpecified(void) const {
  return this->Decl::u.FunctionDecl->isInlineSpecified();
}

bool FunctionDecl::IsInlined(void) const {
  return this->Decl::u.FunctionDecl->isInlined();
}

bool FunctionDecl::IsLateTemplateParsed(void) const {
  return this->Decl::u.FunctionDecl->isLateTemplateParsed();
}

bool FunctionDecl::IsMultiVersion(void) const {
  return this->Decl::u.FunctionDecl->isMultiVersion();
}

bool FunctionDecl::IsOverloadedOperator(void) const {
  return this->Decl::u.FunctionDecl->isOverloadedOperator();
}

bool FunctionDecl::IsPure(void) const {
  return this->Decl::u.FunctionDecl->isPure();
}

bool FunctionDecl::IsStatic(void) const {
  return this->Decl::u.FunctionDecl->isStatic();
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.FunctionDecl->isThisDeclarationADefinition();
}

bool FunctionDecl::IsTrivial(void) const {
  return this->Decl::u.FunctionDecl->isTrivial();
}

bool FunctionDecl::IsTrivialForCall(void) const {
  return this->Decl::u.FunctionDecl->isTrivialForCall();
}

bool FunctionDecl::IsUserProvided(void) const {
  return this->Decl::u.FunctionDecl->isUserProvided();
}

bool FunctionDecl::IsVirtualAsWritten(void) const {
  return this->Decl::u.FunctionDecl->isVirtualAsWritten();
}

  // Parameters
bool FunctionDecl::UsesFPIntrin(void) const {
  return this->Decl::u.FunctionDecl->usesFPIntrin();
}

bool FunctionDecl::UsesSEHTry(void) const {
  return this->Decl::u.FunctionDecl->usesSEHTry();
}

bool FunctionDecl::WillHaveBody(void) const {
  return this->Decl::u.FunctionDecl->willHaveBody();
}

IndirectFieldDecl::IndirectFieldDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::IndirectFieldDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // Chain
  // AnonField
  // CanonicalDecl
  // ChainingSize
  // VarDecl
LabelDecl::LabelDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::LabelDecl *decl_)
    : NamedDecl(ast_, decl_) {}

  // MSAsmLabel
  // TokenRange
  // Stmt
bool LabelDecl::IsGnuLocal(void) const {
  return this->Decl::u.LabelDecl->isGnuLocal();
}

bool LabelDecl::IsMSAsmLabel(void) const {
  return this->Decl::u.LabelDecl->isMSAsmLabel();
}

bool LabelDecl::IsResolvedMSAsmLabel(void) const {
  return this->Decl::u.LabelDecl->isResolvedMSAsmLabel();
}

MSGuidDecl::MSGuidDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::MSGuidDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // Parts
MSPropertyDecl::MSPropertyDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::MSPropertyDecl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

  // GetterId
  // SetterId
bool MSPropertyDecl::HasGetter(void) const {
  return this->Decl::u.MSPropertyDecl->hasGetter();
}

bool MSPropertyDecl::HasSetter(void) const {
  return this->Decl::u.MSPropertyDecl->hasSetter();
}

NonTypeTemplateParmDecl::NonTypeTemplateParmDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::NonTypeTemplateParmDecl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

bool NonTypeTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->defaultArgumentWasInherited();
}

  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionType
  // ExpansionTypeSourceInfo
  // NumExpansionTypes
  // PlaceholderTypeConstraint
bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->hasDefaultArgument();
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->hasPlaceholderTypeConstraint();
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->isExpandedParameterPack();
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->isPackExpansion();
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const {
  return this->Decl::u.NonTypeTemplateParmDecl->isParameterPack();
}

OMPDeclareMapperDecl::OMPDeclareMapperDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPDeclareMapperDecl *decl_)
    : ValueDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // Clauselists
  // MapperVarRef
OMPDeclareReductionDecl::OMPDeclareReductionDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPDeclareReductionDecl *decl_)
    : ValueDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // Combiner
  // CombinerIn
  // CombinerOut
  // InitOrig
  // InitPriv
  // Initializer
  // InitializerKind
ObjCAtDefsFieldDecl::ObjCAtDefsFieldDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCAtDefsFieldDecl *decl_)
    : FieldDecl(ast_, decl_) {}

ObjCCategoryDecl::ObjCCategoryDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCCategoryDecl *decl_)
    : ObjCContainerDecl(ast_, decl_) {}

bool ObjCCategoryDecl::IsClassExtension(void) const {
  return this->Decl::u.ObjCCategoryDecl->IsClassExtension();
}

  // CategoryNameToken
  // ClassInterface
  // IvarLBraceToken
  // IvarRBraceToken
  // NextClassCategory
  // NextClassCategoryRaw
  // ReferencedProtocols
  // TypeParamList
  // Ivars
  // Protocol_locs
  // Protocols
ObjCCategoryImplDecl::ObjCCategoryImplDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCCategoryImplDecl *decl_)
    : ObjCImplDecl(ast_, decl_) {}

  // CategoryNameToken
ObjCIvarDecl::ObjCIvarDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCIvarDecl *decl_)
    : FieldDecl(ast_, decl_) {}

  // AccessControl
  // CanonicalAccessControl
  // NextIvar
bool ObjCIvarDecl::Synthesize(void) const {
  return this->Decl::u.ObjCIvarDecl->getSynthesize();
}

ObjCTypeParamDecl::ObjCTypeParamDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ObjCTypeParamDecl *decl_)
    : TypedefNameDecl(ast_, decl_) {}

  // ColonToken
  // Index
  // Variance
  // VarianceToken
bool ObjCTypeParamDecl::HasExplicitBound(void) const {
  return this->Decl::u.ObjCTypeParamDecl->hasExplicitBound();
}

RedeclarableTemplateDecl::RedeclarableTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::RedeclarableTemplateDecl *decl_)
    : TemplateDecl(ast_, decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const {
  return this->Decl::u.RedeclarableTemplateDecl->isMemberSpecialization();
}

TagDecl::TagDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TagDecl *decl_)
    : TypeDecl(ast_, decl_),
      DeclContext(ast_, decl_) {}

  // BraceRange
  // CanonicalDecl
  // InnerLocStart
  // KindName
  // NumTemplateParameterLists
  // Qualifier
  // QualifierToken
  // TagKind
  // TemplateParameterList
  // TypedefNameForAnonDecl
bool TagDecl::HasNameForLinkage(void) const {
  return this->Decl::u.TagDecl->hasNameForLinkage();
}

bool TagDecl::IsBeingDefined(void) const {
  return this->Decl::u.TagDecl->isBeingDefined();
}

bool TagDecl::IsClass(void) const {
  return this->Decl::u.TagDecl->isClass();
}

bool TagDecl::IsCompleteDefinition(void) const {
  return this->Decl::u.TagDecl->isCompleteDefinition();
}

bool TagDecl::IsCompleteDefinitionRequired(void) const {
  return this->Decl::u.TagDecl->isCompleteDefinitionRequired();
}

bool TagDecl::IsDependentType(void) const {
  return this->Decl::u.TagDecl->isDependentType();
}

bool TagDecl::IsEmbeddedInDeclarator(void) const {
  return this->Decl::u.TagDecl->isEmbeddedInDeclarator();
}

bool TagDecl::IsEnum(void) const {
  return this->Decl::u.TagDecl->isEnum();
}

bool TagDecl::IsFreeStanding(void) const {
  return this->Decl::u.TagDecl->isFreeStanding();
}

bool TagDecl::IsInterface(void) const {
  return this->Decl::u.TagDecl->isInterface();
}

bool TagDecl::IsStruct(void) const {
  return this->Decl::u.TagDecl->isStruct();
}

bool TagDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.TagDecl->isThisDeclarationADefinition();
}

bool TagDecl::IsUnion(void) const {
  return this->Decl::u.TagDecl->isUnion();
}

bool TagDecl::MayHaveOutOfDateDef(void) const {
  return this->Decl::u.TagDecl->mayHaveOutOfDateDef();
}

TemplateTypeParmDecl::TemplateTypeParmDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TemplateTypeParmDecl *decl_)
    : TypeDecl(ast_, decl_) {}

bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const {
  return this->Decl::u.TemplateTypeParmDecl->defaultArgumentWasInherited();
}

  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // DefaultArgumentInfo
  // NumExpansionParameters
  // TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const {
  return this->Decl::u.TemplateTypeParmDecl->hasDefaultArgument();
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const {
  return this->Decl::u.TemplateTypeParmDecl->hasTypeConstraint();
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const {
  return this->Decl::u.TemplateTypeParmDecl->isExpandedParameterPack();
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const {
  return this->Decl::u.TemplateTypeParmDecl->isPackExpansion();
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const {
  return this->Decl::u.TemplateTypeParmDecl->wasDeclaredWithTypename();
}

TypeAliasDecl::TypeAliasDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TypeAliasDecl *decl_)
    : TypedefNameDecl(ast_, decl_) {}

  // DescribedAliasTemplate
TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TypeAliasTemplateDecl *decl_)
    : RedeclarableTemplateDecl(ast_, decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // PreviousDecl
  // TemplatedDecl
TypedefDecl::TypedefDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::TypedefDecl *decl_)
    : TypedefNameDecl(ast_, decl_) {}

UnresolvedUsingValueDecl::UnresolvedUsingValueDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::UnresolvedUsingValueDecl *decl_)
    : ValueDecl(ast_, decl_) {}

  // CanonicalDecl
  // EllipsisToken
  // NameInfo
  // Qualifier
  // QualifierToken
  // UsingToken
bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const {
  return this->Decl::u.UnresolvedUsingValueDecl->isAccessDeclaration();
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const {
  return this->Decl::u.UnresolvedUsingValueDecl->isPackExpansion();
}

VarDecl::VarDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::VarDecl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

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
  return this->Decl::u.VarDecl->hasExternalStorage();
}

bool VarDecl::HasGlobalStorage(void) const {
  return this->Decl::u.VarDecl->hasGlobalStorage();
}

bool VarDecl::HasLocalStorage(void) const {
  return this->Decl::u.VarDecl->hasLocalStorage();
}

bool VarDecl::IsARCPseudoStrong(void) const {
  return this->Decl::u.VarDecl->isARCPseudoStrong();
}

bool VarDecl::IsCXXForRangeDecl(void) const {
  return this->Decl::u.VarDecl->isCXXForRangeDecl();
}

bool VarDecl::IsConstexpr(void) const {
  return this->Decl::u.VarDecl->isConstexpr();
}

bool VarDecl::IsDirectInit(void) const {
  return this->Decl::u.VarDecl->isDirectInit();
}

bool VarDecl::IsExceptionVariable(void) const {
  return this->Decl::u.VarDecl->isExceptionVariable();
}

bool VarDecl::IsFileVarDecl(void) const {
  return this->Decl::u.VarDecl->isFileVarDecl();
}

bool VarDecl::IsFunctionOrMethodVarDecl(void) const {
  return this->Decl::u.VarDecl->isFunctionOrMethodVarDecl();
}

bool VarDecl::IsInitCapture(void) const {
  return this->Decl::u.VarDecl->isInitCapture();
}

bool VarDecl::IsInline(void) const {
  return this->Decl::u.VarDecl->isInline();
}

bool VarDecl::IsInlineSpecified(void) const {
  return this->Decl::u.VarDecl->isInlineSpecified();
}

bool VarDecl::IsLocalVarDecl(void) const {
  return this->Decl::u.VarDecl->isLocalVarDecl();
}

bool VarDecl::IsLocalVarDeclOrParm(void) const {
  return this->Decl::u.VarDecl->isLocalVarDeclOrParm();
}

bool VarDecl::IsNRVOVariable(void) const {
  return this->Decl::u.VarDecl->isNRVOVariable();
}

bool VarDecl::IsObjCForDecl(void) const {
  return this->Decl::u.VarDecl->isObjCForDecl();
}

bool VarDecl::IsPreviousDeclInSameBlockScope(void) const {
  return this->Decl::u.VarDecl->isPreviousDeclInSameBlockScope();
}

bool VarDecl::IsStaticDataMember(void) const {
  return this->Decl::u.VarDecl->isStaticDataMember();
}

bool VarDecl::IsStaticLocal(void) const {
  return this->Decl::u.VarDecl->isStaticLocal();
}

  // IsThisDeclarationADefinition
bool VarDecl::IsThisDeclarationADemotedDefinition(void) const {
  return this->Decl::u.VarDecl->isThisDeclarationADemotedDefinition();
}

VarTemplateDecl::VarTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::VarTemplateDecl *decl_)
    : RedeclarableTemplateDecl(ast_, decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool VarTemplateDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.VarTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
VarTemplateSpecializationDecl::VarTemplateSpecializationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::VarTemplateSpecializationDecl *decl_)
    : VarDecl(ast_, decl_) {}

  // Profile
  // ExternToken
  // InstantiatedFrom
  // PointOfInstantiation
  // SpecializationKind
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateArgsInfo
  // TemplateInstantiationArgs
  // TemplateKeywordToken
  // TypeAsWritten
bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  return this->Decl::u.VarTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  return this->Decl::u.VarTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  return this->Decl::u.VarTemplateSpecializationDecl->isExplicitSpecialization();
}

CXXDeductionGuideDecl::CXXDeductionGuideDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXDeductionGuideDecl *decl_)
    : FunctionDecl(ast_, decl_) {}

  // DeducedTemplate
  // ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const {
  return this->Decl::u.CXXDeductionGuideDecl->isCopyDeductionCandidate();
}

bool CXXDeductionGuideDecl::IsExplicit(void) const {
  return this->Decl::u.CXXDeductionGuideDecl->isExplicit();
}

CXXMethodDecl::CXXMethodDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXMethodDecl *decl_)
    : FunctionDecl(ast_, decl_) {}

  // CanonicalDecl
  // CorrespondingMethodDeclaredInClass
  // CorrespondingMethodInClass
  // DevirtualizedMethod
  // MethodQualifiers
  // MostRecentDecl
  // Parent
  // RefQualifier
bool CXXMethodDecl::IsConst(void) const {
  return this->Decl::u.CXXMethodDecl->isConst();
}

bool CXXMethodDecl::IsInstance(void) const {
  return this->Decl::u.CXXMethodDecl->isInstance();
}

bool CXXMethodDecl::IsVirtual(void) const {
  return this->Decl::u.CXXMethodDecl->isVirtual();
}

bool CXXMethodDecl::IsVolatile(void) const {
  return this->Decl::u.CXXMethodDecl->isVolatile();
}

ClassTemplateDecl::ClassTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ClassTemplateDecl *decl_)
    : RedeclarableTemplateDecl(ast_, decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.ClassTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
DecompositionDecl::DecompositionDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::DecompositionDecl *decl_)
    : VarDecl(ast_, decl_) {}

  // Bindings
EnumDecl::EnumDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::EnumDecl *decl_)
    : TagDecl(ast_, decl_) {}

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
  return this->Decl::u.EnumDecl->isComplete();
}

bool EnumDecl::IsFixed(void) const {
  return this->Decl::u.EnumDecl->isFixed();
}

bool EnumDecl::IsScoped(void) const {
  return this->Decl::u.EnumDecl->isScoped();
}

bool EnumDecl::IsScopedUsingClassTag(void) const {
  return this->Decl::u.EnumDecl->isScopedUsingClassTag();
}

FunctionTemplateDecl::FunctionTemplateDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::FunctionTemplateDecl *decl_)
    : RedeclarableTemplateDecl(ast_, decl_) {}

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
bool FunctionTemplateDecl::IsAbbreviated(void) const {
  return this->Decl::u.FunctionTemplateDecl->isAbbreviated();
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const {
  return this->Decl::u.FunctionTemplateDecl->isThisDeclarationADefinition();
}

  // Specializations
ImplicitParamDecl::ImplicitParamDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ImplicitParamDecl *decl_)
    : VarDecl(ast_, decl_) {}

  // ParameterKind
OMPCapturedExprDecl::OMPCapturedExprDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::OMPCapturedExprDecl *decl_)
    : VarDecl(ast_, decl_) {}

ParmVarDecl::ParmVarDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ParmVarDecl *decl_)
    : VarDecl(ast_, decl_) {}

  // DefaultArg
  // FunctionScopeDepth
  // FunctionScopeIndex
  // ObjCDeclQualifier
  // UninstantiatedDefaultArg
bool ParmVarDecl::HasInheritedDefaultArg(void) const {
  return this->Decl::u.ParmVarDecl->hasInheritedDefaultArg();
}

bool ParmVarDecl::HasUninstantiatedDefaultArg(void) const {
  return this->Decl::u.ParmVarDecl->hasUninstantiatedDefaultArg();
}

bool ParmVarDecl::HasUnparsedDefaultArg(void) const {
  return this->Decl::u.ParmVarDecl->hasUnparsedDefaultArg();
}

bool ParmVarDecl::IsKNRPromoted(void) const {
  return this->Decl::u.ParmVarDecl->isKNRPromoted();
}

bool ParmVarDecl::IsObjCMethodParameter(void) const {
  return this->Decl::u.ParmVarDecl->isObjCMethodParameter();
}

RecordDecl::RecordDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::RecordDecl *decl_)
    : TagDecl(ast_, decl_) {}

bool RecordDecl::CanPassInRegisters(void) const {
  return this->Decl::u.RecordDecl->canPassInRegisters();
}

  // Fields
  // ArgPassingRestrictions
  // Definition
  // MostRecentDecl
  // PreviousDecl
bool RecordDecl::HasFlexibleArrayMember(void) const {
  return this->Decl::u.RecordDecl->hasFlexibleArrayMember();
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const {
  return this->Decl::u.RecordDecl->hasLoadedFieldsFromExternalStorage();
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  return this->Decl::u.RecordDecl->hasNonTrivialToPrimitiveCopyCUnion();
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  return this->Decl::u.RecordDecl->hasNonTrivialToPrimitiveDefaultInitializeCUnion();
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  return this->Decl::u.RecordDecl->hasNonTrivialToPrimitiveDestructCUnion();
}

bool RecordDecl::HasObjectMember(void) const {
  return this->Decl::u.RecordDecl->hasObjectMember();
}

bool RecordDecl::HasVolatileMember(void) const {
  return this->Decl::u.RecordDecl->hasVolatileMember();
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const {
  return this->Decl::u.RecordDecl->isAnonymousStructOrUnion();
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const {
  return this->Decl::u.RecordDecl->isNonTrivialToPrimitiveCopy();
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  return this->Decl::u.RecordDecl->isNonTrivialToPrimitiveDefaultInitialize();
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const {
  return this->Decl::u.RecordDecl->isNonTrivialToPrimitiveDestroy();
}

bool RecordDecl::IsParamDestroyedInCallee(void) const {
  return this->Decl::u.RecordDecl->isParamDestroyedInCallee();
}

VarTemplatePartialSpecializationDecl::VarTemplatePartialSpecializationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::VarTemplatePartialSpecializationDecl *decl_)
    : VarTemplateSpecializationDecl(ast_, decl_) {}

  // Profile
  // AssociatedConstraints
  // InstantiatedFromMember
  // TemplateArgsAsWritten
  // TemplateParameters
bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  return this->Decl::u.VarTemplatePartialSpecializationDecl->hasAssociatedConstraints();
}

CXXConstructorDecl::CXXConstructorDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXConstructorDecl *decl_)
    : CXXMethodDecl(ast_, decl_) {}

  // CanonicalDecl
  // ExplicitSpecifier
  // InheritedConstructor
  // NumCtorInitializers
  // Inits
bool CXXConstructorDecl::IsCopyConstructor(void) const {
  return this->Decl::u.CXXConstructorDecl->isCopyConstructor();
}

bool CXXConstructorDecl::IsCopyOrMoveConstructor(void) const {
  return this->Decl::u.CXXConstructorDecl->isCopyOrMoveConstructor();
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const {
  return this->Decl::u.CXXConstructorDecl->isDelegatingConstructor();
}

bool CXXConstructorDecl::IsExplicit(void) const {
  return this->Decl::u.CXXConstructorDecl->isExplicit();
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const {
  return this->Decl::u.CXXConstructorDecl->isInheritingConstructor();
}

bool CXXConstructorDecl::IsMoveConstructor(void) const {
  return this->Decl::u.CXXConstructorDecl->isMoveConstructor();
}

CXXConversionDecl::CXXConversionDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXConversionDecl *decl_)
    : CXXMethodDecl(ast_, decl_) {}

  // CanonicalDecl
  // ConversionType
  // ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const {
  return this->Decl::u.CXXConversionDecl->isExplicit();
}

CXXDestructorDecl::CXXDestructorDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXDestructorDecl *decl_)
    : CXXMethodDecl(ast_, decl_) {}

  // CanonicalDecl
  // OperatorDelete
  // OperatorDeleteThisArg
CXXRecordDecl::CXXRecordDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::CXXRecordDecl *decl_)
    : RecordDecl(ast_, decl_) {}

bool CXXRecordDecl::AllowConstDefaultInit(void) const {
  return this->Decl::u.CXXRecordDecl->allowConstDefaultInit();
}

  // Bases
  // Captures
  // Constructors
bool CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const {
  return this->Decl::u.CXXRecordDecl->defaultedCopyConstructorIsDeleted();
}

bool CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const {
  return this->Decl::u.CXXRecordDecl->defaultedDefaultConstructorIsConstexpr();
}

bool CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const {
  return this->Decl::u.CXXRecordDecl->defaultedDestructorIsConstexpr();
}

bool CXXRecordDecl::DefaultedDestructorIsDeleted(void) const {
  return this->Decl::u.CXXRecordDecl->defaultedDestructorIsDeleted();
}

bool CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const {
  return this->Decl::u.CXXRecordDecl->defaultedMoveConstructorIsDeleted();
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
  return this->Decl::u.CXXRecordDecl->hasConstexprDefaultConstructor();
}

bool CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasConstexprNonCopyMoveConstructor();
}

bool CXXRecordDecl::HasCopyAssignmentWithConstParam(void) const {
  return this->Decl::u.CXXRecordDecl->hasCopyAssignmentWithConstParam();
}

bool CXXRecordDecl::HasCopyConstructorWithConstParam(void) const {
  return this->Decl::u.CXXRecordDecl->hasCopyConstructorWithConstParam();
}

bool CXXRecordDecl::HasDefaultConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasDefaultConstructor();
}

bool CXXRecordDecl::HasDefinition(void) const {
  return this->Decl::u.CXXRecordDecl->hasDefinition();
}

bool CXXRecordDecl::HasDirectFields(void) const {
  return this->Decl::u.CXXRecordDecl->hasDirectFields();
}

bool CXXRecordDecl::HasFriends(void) const {
  return this->Decl::u.CXXRecordDecl->hasFriends();
}

bool CXXRecordDecl::HasInClassInitializer(void) const {
  return this->Decl::u.CXXRecordDecl->hasInClassInitializer();
}

bool CXXRecordDecl::HasInheritedAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasInheritedAssignment();
}

bool CXXRecordDecl::HasInheritedConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasInheritedConstructor();
}

bool CXXRecordDecl::HasIrrelevantDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasIrrelevantDestructor();
}

bool CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const {
  return this->Decl::u.CXXRecordDecl->hasKnownLambdaInternalLinkage();
}

bool CXXRecordDecl::HasMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasMoveAssignment();
}

bool CXXRecordDecl::HasMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasMoveConstructor();
}

bool CXXRecordDecl::HasMutableFields(void) const {
  return this->Decl::u.CXXRecordDecl->hasMutableFields();
}

bool CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonLiteralTypeFieldsOrBases();
}

bool CXXRecordDecl::HasNonTrivialCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialCopyAssignment();
}

bool CXXRecordDecl::HasNonTrivialCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialCopyConstructor();
}

bool CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialCopyConstructorForCall();
}

bool CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialDefaultConstructor();
}

bool CXXRecordDecl::HasNonTrivialDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialDestructor();
}

bool CXXRecordDecl::HasNonTrivialDestructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialDestructorForCall();
}

bool CXXRecordDecl::HasNonTrivialMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialMoveAssignment();
}

bool CXXRecordDecl::HasNonTrivialMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialMoveConstructor();
}

bool CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasNonTrivialMoveConstructorForCall();
}

bool CXXRecordDecl::HasPrivateFields(void) const {
  return this->Decl::u.CXXRecordDecl->hasPrivateFields();
}

bool CXXRecordDecl::HasProtectedFields(void) const {
  return this->Decl::u.CXXRecordDecl->hasProtectedFields();
}

bool CXXRecordDecl::HasSimpleCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasSimpleCopyAssignment();
}

bool CXXRecordDecl::HasSimpleCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasSimpleCopyConstructor();
}

bool CXXRecordDecl::HasSimpleDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasSimpleDestructor();
}

bool CXXRecordDecl::HasSimpleMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasSimpleMoveAssignment();
}

bool CXXRecordDecl::HasSimpleMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasSimpleMoveConstructor();
}

bool CXXRecordDecl::HasTrivialCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialCopyAssignment();
}

bool CXXRecordDecl::HasTrivialCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialCopyConstructor();
}

bool CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialCopyConstructorForCall();
}

bool CXXRecordDecl::HasTrivialDefaultConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialDefaultConstructor();
}

bool CXXRecordDecl::HasTrivialDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialDestructor();
}

bool CXXRecordDecl::HasTrivialDestructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialDestructorForCall();
}

bool CXXRecordDecl::HasTrivialMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialMoveAssignment();
}

bool CXXRecordDecl::HasTrivialMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialMoveConstructor();
}

bool CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const {
  return this->Decl::u.CXXRecordDecl->hasTrivialMoveConstructorForCall();
}

bool CXXRecordDecl::HasUninitializedReferenceMember(void) const {
  return this->Decl::u.CXXRecordDecl->hasUninitializedReferenceMember();
}

bool CXXRecordDecl::HasUserDeclaredConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredConstructor();
}

bool CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredCopyAssignment();
}

bool CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredCopyConstructor();
}

bool CXXRecordDecl::HasUserDeclaredDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredDestructor();
}

bool CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredMoveAssignment();
}

bool CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredMoveConstructor();
}

bool CXXRecordDecl::HasUserDeclaredMoveOperation(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserDeclaredMoveOperation();
}

bool CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->hasUserProvidedDefaultConstructor();
}

bool CXXRecordDecl::HasVariantMembers(void) const {
  return this->Decl::u.CXXRecordDecl->hasVariantMembers();
}

bool CXXRecordDecl::ImplicitCopyAssignmentHasConstParam(void) const {
  return this->Decl::u.CXXRecordDecl->implicitCopyAssignmentHasConstParam();
}

bool CXXRecordDecl::ImplicitCopyConstructorHasConstParam(void) const {
  return this->Decl::u.CXXRecordDecl->implicitCopyConstructorHasConstParam();
}

bool CXXRecordDecl::IsAbstract(void) const {
  return this->Decl::u.CXXRecordDecl->isAbstract();
}

bool CXXRecordDecl::IsAggregate(void) const {
  return this->Decl::u.CXXRecordDecl->isAggregate();
}

bool CXXRecordDecl::IsCXX11StandardLayout(void) const {
  return this->Decl::u.CXXRecordDecl->isCXX11StandardLayout();
}

bool CXXRecordDecl::IsDependentLambda(void) const {
  return this->Decl::u.CXXRecordDecl->isDependentLambda();
}

bool CXXRecordDecl::IsDynamicClass(void) const {
  return this->Decl::u.CXXRecordDecl->isDynamicClass();
}

bool CXXRecordDecl::IsEmpty(void) const {
  return this->Decl::u.CXXRecordDecl->isEmpty();
}

bool CXXRecordDecl::IsLambda(void) const {
  return this->Decl::u.CXXRecordDecl->isLambda();
}

bool CXXRecordDecl::IsLiteral(void) const {
  return this->Decl::u.CXXRecordDecl->isLiteral();
}

  // IsLocalClass
bool CXXRecordDecl::IsPOD(void) const {
  return this->Decl::u.CXXRecordDecl->isPOD();
}

bool CXXRecordDecl::IsParsingBaseSpecifiers(void) const {
  return this->Decl::u.CXXRecordDecl->isParsingBaseSpecifiers();
}

bool CXXRecordDecl::IsPolymorphic(void) const {
  return this->Decl::u.CXXRecordDecl->isPolymorphic();
}

bool CXXRecordDecl::IsStandardLayout(void) const {
  return this->Decl::u.CXXRecordDecl->isStandardLayout();
}

bool CXXRecordDecl::IsTrivial(void) const {
  return this->Decl::u.CXXRecordDecl->isTrivial();
}

bool CXXRecordDecl::MayBeDynamicClass(void) const {
  return this->Decl::u.CXXRecordDecl->mayBeDynamicClass();
}

bool CXXRecordDecl::MayBeNonDynamicClass(void) const {
  return this->Decl::u.CXXRecordDecl->mayBeNonDynamicClass();
}

  // Methods
bool CXXRecordDecl::NeedsImplicitCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitCopyAssignment();
}

bool CXXRecordDecl::NeedsImplicitCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitCopyConstructor();
}

bool CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitDefaultConstructor();
}

bool CXXRecordDecl::NeedsImplicitDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitDestructor();
}

bool CXXRecordDecl::NeedsImplicitMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitMoveAssignment();
}

bool CXXRecordDecl::NeedsImplicitMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsImplicitMoveConstructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->needsOverloadResolutionForCopyAssignment();
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsOverloadResolutionForCopyConstructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsOverloadResolutionForDestructor();
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const {
  return this->Decl::u.CXXRecordDecl->needsOverloadResolutionForMoveAssignment();
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const {
  return this->Decl::u.CXXRecordDecl->needsOverloadResolutionForMoveConstructor();
}

  // VirtualBases
ClassTemplateSpecializationDecl::ClassTemplateSpecializationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ClassTemplateSpecializationDecl *decl_)
    : CXXRecordDecl(ast_, decl_) {}

  // Profile
  // ExternToken
  // InstantiatedFrom
  // PointOfInstantiation
  // SpecializationKind
  // SpecializedTemplateOrPartial
  // TemplateArgs
  // TemplateInstantiationArgs
  // TemplateKeywordToken
  // TypeAsWritten
bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  return this->Decl::u.ClassTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  return this->Decl::u.ClassTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  return this->Decl::u.ClassTemplateSpecializationDecl->isExplicitSpecialization();
}

ClassTemplatePartialSpecializationDecl::ClassTemplatePartialSpecializationDecl(
    const std::shared_ptr<ASTImpl> &ast_,
    const ::clang::ClassTemplatePartialSpecializationDecl *decl_)
    : ClassTemplateSpecializationDecl(ast_, decl_) {}

  // Profile
  // AssociatedConstraints
  // InjectedSpecializationType
  // InstantiatedFromMember
  // InstantiatedFromMemberTemplate
  // TemplateArgsAsWritten
  // TemplateParameters
bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  return this->Decl::u.ClassTemplatePartialSpecializationDecl->hasAssociatedConstraints();
}

}  // namespace pasta
