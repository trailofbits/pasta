/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#ifdef PASTA_IN_BOOTSTRAP
#  include "DeclBootstrap.h"
#else
#include <variant>
#include <vector>
#include <pasta/Util/Compiler.h>
#include "Forward.h"

#include "Attr.h"
#include "DeclHead.h"

#define PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class DeclBuilder; \
    friend class DeclVisitor; \
    friend class PrintedTokenRange; \
    base(void) = delete; \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::Decl *decl_); \
   public: \
    inline const clang::base *RawDecl(void) const noexcept { \
      return u.base; \
    }

namespace pasta {
class DeclVisitor {
 public:
  virtual ~DeclVisitor(void);
  void Accept(const Decl &);
  virtual void VisitDecl(const Decl &);
  virtual void VisitEmptyDecl(const EmptyDecl &);
  virtual void VisitExportDecl(const ExportDecl &);
  virtual void VisitExternCContextDecl(const ExternCContextDecl &);
  virtual void VisitFileScopeAsmDecl(const FileScopeAsmDecl &);
  virtual void VisitFriendDecl(const FriendDecl &);
  virtual void VisitFriendTemplateDecl(const FriendTemplateDecl &);
  virtual void VisitImplicitConceptSpecializationDecl(const ImplicitConceptSpecializationDecl &);
  virtual void VisitImportDecl(const ImportDecl &);
  virtual void VisitLifetimeExtendedTemporaryDecl(const LifetimeExtendedTemporaryDecl &);
  virtual void VisitLinkageSpecDecl(const LinkageSpecDecl &);
  virtual void VisitNamedDecl(const NamedDecl &);
  virtual void VisitNamespaceAliasDecl(const NamespaceAliasDecl &);
  virtual void VisitNamespaceDecl(const NamespaceDecl &);
  virtual void VisitObjCCompatibleAliasDecl(const ObjCCompatibleAliasDecl &);
  virtual void VisitObjCContainerDecl(const ObjCContainerDecl &);
  virtual void VisitObjCImplDecl(const ObjCImplDecl &);
  virtual void VisitObjCImplementationDecl(const ObjCImplementationDecl &);
  virtual void VisitObjCInterfaceDecl(const ObjCInterfaceDecl &);
  virtual void VisitObjCMethodDecl(const ObjCMethodDecl &);
  virtual void VisitObjCPropertyDecl(const ObjCPropertyDecl &);
  virtual void VisitObjCPropertyImplDecl(const ObjCPropertyImplDecl &);
  virtual void VisitObjCProtocolDecl(const ObjCProtocolDecl &);
  virtual void VisitPragmaCommentDecl(const PragmaCommentDecl &);
  virtual void VisitPragmaDetectMismatchDecl(const PragmaDetectMismatchDecl &);
  virtual void VisitRequiresExprBodyDecl(const RequiresExprBodyDecl &);
  virtual void VisitStaticAssertDecl(const StaticAssertDecl &);
  virtual void VisitTemplateDecl(const TemplateDecl &);
  virtual void VisitTemplateTemplateParmDecl(const TemplateTemplateParmDecl &);
  virtual void VisitTopLevelStmtDecl(const TopLevelStmtDecl &);
  virtual void VisitTranslationUnitDecl(const TranslationUnitDecl &);
  virtual void VisitTypeDecl(const TypeDecl &);
  virtual void VisitTypedefNameDecl(const TypedefNameDecl &);
  virtual void VisitUnresolvedUsingIfExistsDecl(const UnresolvedUsingIfExistsDecl &);
  virtual void VisitUnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &);
  virtual void VisitUsingDirectiveDecl(const UsingDirectiveDecl &);
  virtual void VisitUsingPackDecl(const UsingPackDecl &);
  virtual void VisitUsingShadowDecl(const UsingShadowDecl &);
  virtual void VisitValueDecl(const ValueDecl &);
  virtual void VisitOMPDeclarativeDirectiveDecl(const OMPDeclarativeDirectiveDecl &);
  virtual void VisitOMPDeclarativeDirectiveValueDecl(const OMPDeclarativeDirectiveValueDecl &);
  virtual void VisitAccessSpecDecl(const AccessSpecDecl &);
  virtual void VisitBaseUsingDecl(const BaseUsingDecl &);
  virtual void VisitBindingDecl(const BindingDecl &);
  virtual void VisitBlockDecl(const BlockDecl &);
  virtual void VisitBuiltinTemplateDecl(const BuiltinTemplateDecl &);
  virtual void VisitCapturedDecl(const CapturedDecl &);
  virtual void VisitClassScopeFunctionSpecializationDecl(const ClassScopeFunctionSpecializationDecl &);
  virtual void VisitConceptDecl(const ConceptDecl &);
  virtual void VisitConstructorUsingShadowDecl(const ConstructorUsingShadowDecl &);
  virtual void VisitDeclaratorDecl(const DeclaratorDecl &);
  virtual void VisitEnumConstantDecl(const EnumConstantDecl &);
  virtual void VisitFieldDecl(const FieldDecl &);
  virtual void VisitFunctionDecl(const FunctionDecl &);
  virtual void VisitHLSLBufferDecl(const HLSLBufferDecl &);
  virtual void VisitIndirectFieldDecl(const IndirectFieldDecl &);
  virtual void VisitLabelDecl(const LabelDecl &);
  virtual void VisitMSGuidDecl(const MSGuidDecl &);
  virtual void VisitMSPropertyDecl(const MSPropertyDecl &);
  virtual void VisitNonTypeTemplateParmDecl(const NonTypeTemplateParmDecl &);
  virtual void VisitOMPAllocateDecl(const OMPAllocateDecl &);
  virtual void VisitOMPDeclareMapperDecl(const OMPDeclareMapperDecl &);
  virtual void VisitOMPDeclareReductionDecl(const OMPDeclareReductionDecl &);
  virtual void VisitOMPRequiresDecl(const OMPRequiresDecl &);
  virtual void VisitOMPThreadPrivateDecl(const OMPThreadPrivateDecl &);
  virtual void VisitObjCAtDefsFieldDecl(const ObjCAtDefsFieldDecl &);
  virtual void VisitObjCCategoryDecl(const ObjCCategoryDecl &);
  virtual void VisitObjCCategoryImplDecl(const ObjCCategoryImplDecl &);
  virtual void VisitObjCIvarDecl(const ObjCIvarDecl &);
  virtual void VisitObjCTypeParamDecl(const ObjCTypeParamDecl &);
  virtual void VisitRedeclarableTemplateDecl(const RedeclarableTemplateDecl &);
  virtual void VisitTagDecl(const TagDecl &);
  virtual void VisitTemplateParamObjectDecl(const TemplateParamObjectDecl &);
  virtual void VisitTemplateTypeParmDecl(const TemplateTypeParmDecl &);
  virtual void VisitTypeAliasDecl(const TypeAliasDecl &);
  virtual void VisitTypeAliasTemplateDecl(const TypeAliasTemplateDecl &);
  virtual void VisitTypedefDecl(const TypedefDecl &);
  virtual void VisitUnnamedGlobalConstantDecl(const UnnamedGlobalConstantDecl &);
  virtual void VisitUnresolvedUsingValueDecl(const UnresolvedUsingValueDecl &);
  virtual void VisitUsingDecl(const UsingDecl &);
  virtual void VisitUsingEnumDecl(const UsingEnumDecl &);
  virtual void VisitVarDecl(const VarDecl &);
  virtual void VisitVarTemplateDecl(const VarTemplateDecl &);
  virtual void VisitVarTemplateSpecializationDecl(const VarTemplateSpecializationDecl &);
  virtual void VisitCXXDeductionGuideDecl(const CXXDeductionGuideDecl &);
  virtual void VisitCXXMethodDecl(const CXXMethodDecl &);
  virtual void VisitClassTemplateDecl(const ClassTemplateDecl &);
  virtual void VisitDecompositionDecl(const DecompositionDecl &);
  virtual void VisitEnumDecl(const EnumDecl &);
  virtual void VisitFunctionTemplateDecl(const FunctionTemplateDecl &);
  virtual void VisitImplicitParamDecl(const ImplicitParamDecl &);
  virtual void VisitOMPCapturedExprDecl(const OMPCapturedExprDecl &);
  virtual void VisitParmVarDecl(const ParmVarDecl &);
  virtual void VisitRecordDecl(const RecordDecl &);
  virtual void VisitVarTemplatePartialSpecializationDecl(const VarTemplatePartialSpecializationDecl &);
  virtual void VisitCXXConstructorDecl(const CXXConstructorDecl &);
  virtual void VisitCXXConversionDecl(const CXXConversionDecl &);
  virtual void VisitCXXDestructorDecl(const CXXDestructorDecl &);
  virtual void VisitCXXRecordDecl(const CXXRecordDecl &);
  virtual void VisitClassTemplateSpecializationDecl(const ClassTemplateSpecializationDecl &);
  virtual void VisitClassTemplatePartialSpecializationDecl(const ClassTemplatePartialSpecializationDecl &);
};

class DeclContext {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclContext)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, BlockDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, CapturedDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ExportDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ExternCContextDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, HLSLBufferDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, LinkageSpecDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, NamespaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, OMPDeclareMapperDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, OMPDeclareReductionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCCategoryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCContainerDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCImplementationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCInterfaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, ObjCProtocolDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, RequiresExprBodyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclContext, TranslationUnitDecl)

  const ::clang::DeclContext *RawDeclContext(void) const noexcept {
    return u.DeclContext;
  }

  // Encloses: (bool)
  // Equals: (bool)
  // InEnclosingNamespaceSetOf: (bool)
  // ContainsDeclaration: (bool)
  // ContainsDeclarationAndLoad: (bool)
  // Ddiags: (llvm::iterator_range<clang::DeclContext::ddiag_iterator>)
  std::vector<::pasta::Decl> Declarations(void) const;
  enum ::pasta::DeclKind DeclarationKind(void) const;
  std::string_view DeclarationKindName(void) const;
  std::optional<::pasta::DeclContext> EnclosingNamespaceContext(void) const;
  std::optional<::pasta::LinkageSpecDecl> ExternCContext(void) const;
  std::optional<::pasta::BlockDecl> InnermostBlockDeclaration(void) const;
  std::optional<::pasta::DeclContext> LexicalParent(void) const;
  std::optional<::pasta::DeclContext> LookupParent(void) const;
  // LookupPointer: (clang::StoredDeclsMap *)
  std::optional<::pasta::Decl> NonClosureAncestor(void) const;
  ::pasta::DeclContext NonTransparentContext(void) const;
  std::optional<::pasta::RecordDecl> OuterLexicalRecordContext(void) const;
  std::optional<::pasta::DeclContext> Parent(void) const;
  // ParentASTContext: (clang::ASTContext &)
  ::pasta::DeclContext PrimaryContext(void) const;
  ::pasta::DeclContext RedeclarationContext(void) const;
  bool HasExternalLexicalStorage(void) const;
  bool HasExternalVisibleStorage(void) const;
  bool HasValidDeclarationKind(void) const;
  bool IsClosure(void) const;
  // IsDeclarationInLexicalTraversal: (bool)
  bool IsDependentContext(void) const;
  bool IsExternCContext(void) const;
  bool IsExternCXXContext(void) const;
  bool IsFileContext(void) const;
  bool IsFunctionOrMethod(void) const;
  bool IsInlineNamespace(void) const;
  bool IsLookupContext(void) const;
  bool IsNamespace(void) const;
  bool IsObjCContainer(void) const;
  bool IsRecord(void) const;
  bool IsStdNamespace(void) const;
  bool IsTranslationUnit(void) const;
  bool IsTransparentContext(void) const;
  // Lookup: (clang::DeclContextLookupResult)
  // Lookups: (llvm::iterator_range<clang::DeclContext::all_lookups_iterator>)
  std::vector<::pasta::Decl> AlreadyLoadedDeclarations(void) const;
  // NoloadLookups: (llvm::iterator_range<clang::DeclContext::all_lookups_iterator>)
  bool ShouldUseQualifiedLookup(void) const;
  // UsingDirectives: (llvm::iterator_range<clang::DeclContext::udir_iterator>)
 private:
  friend class Decl;
  friend class DeclVisitor;
  friend class UsingDirectiveDecl;
  friend class SourceLocExpr;
  friend class CXXDefaultArgExpr;
  friend class CXXDefaultInitExpr;
  std::shared_ptr<ASTImpl> ast;
  union {
    void *opaque;
    const ::clang::DeclContext *DeclContext;
  } u;
  inline DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *context_)
      : ast(std::move(ast_)) {
    assert(ast.get() != nullptr);
    u.DeclContext = context_;
  }
};

class Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Decl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, AccessSpecDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, BaseUsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, BindingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, BlockDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, BuiltinTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, CapturedDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ClassTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ConceptDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ConstructorUsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, DeclaratorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, EmptyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, EnumConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ExportDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ExternCContextDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FileScopeAsmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FriendDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FriendTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, FunctionTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, HLSLBufferDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ImplicitConceptSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ImportDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, IndirectFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, LabelDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, LinkageSpecDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, MSGuidDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, MSPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, NamedDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, NamespaceAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, NamespaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPAllocateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPDeclareMapperDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPDeclareReductionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPRequiresDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, OMPThreadPrivateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCCategoryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCCompatibleAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCContainerDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCImplementationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCInterfaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCIvarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCPropertyImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCProtocolDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ObjCTypeParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, PragmaCommentDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, PragmaDetectMismatchDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, RedeclarableTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, RequiresExprBodyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, StaticAssertDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TemplateParamObjectDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TemplateTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TemplateTypeParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TopLevelStmtDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TranslationUnitDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypedefDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypedefNameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnnamedGlobalConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnresolvedUsingIfExistsDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingEnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingPackDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplateSpecializationDecl)
  std::vector<::pasta::Attr> Attributes(void) const;
  // CanBeWeakImported: (bool)
  // ASTContext: (clang::ASTContext &)
  enum AccessSpecifier Access(void) const;
  std::optional<::pasta::FunctionDecl> AsFunction(void) const;
  enum AvailabilityResult Availability(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::Decl CanonicalDeclaration(void) const;
  std::optional<::pasta::DeclContext> DeclarationContext(void) const;
  std::optional<::pasta::Attr> DefiningAttribute(void) const;
  std::optional<::pasta::TemplateDecl> DescribedTemplate(void) const;
  std::optional<::pasta::TemplateParameterList> DescribedTemplateParameters(void) const;
  ::pasta::Token EndToken(void) const;
  std::optional<::pasta::ExternalSourceSymbolAttr> ExternalSourceSymbolAttribute(void) const;
  enum DeclFriendObjectKind FriendObjectKind(void) const;
  std::optional<::pasta::FunctionType> FunctionType(void) const;
  uint32_t GlobalID(void) const;
  int64_t ID(void) const;
  uint32_t IdentifierNamespace(void) const;
  // ImportedOwningModule: (clang::Module *)
  // LangOpts: (const clang::LangOptions &)
  std::optional<::pasta::DeclContext> LexicalDeclarationContext(void) const;
  // LocalOwningModule: (clang::Module *)
  std::optional<uint32_t> MaxAlignment(void) const;
  enum DeclModuleOwnershipKind ModuleOwnershipKind(void) const;
  ::pasta::Decl MostRecentDeclaration(void) const;
  std::optional<::pasta::Decl> NextDeclarationInContext(void) const;
  std::optional<::pasta::Decl> NonClosureContext(void) const;
  std::optional<::pasta::DeclContext> NonTransparentDeclarationContext(void) const;
  // OwningModule: (clang::Module *)
  // OwningModuleForLinkage: (clang::Module *)
  uint32_t OwningModuleID(void) const;
  std::optional<::pasta::DeclContext> ParentFunctionOrMethod(void) const;
  std::optional<::pasta::Decl> PreviousDeclaration(void) const;
  uint32_t TemplateDepth(void) const;
  ::pasta::TranslationUnitDecl TranslationUnitDeclaration(void) const;
  // VersionIntroduced: (llvm::VersionTuple)
  bool HasAttributes(void) const;
  bool HasBody(void) const;
  bool HasDefiningAttribute(void) const;
  bool HasOwningModule(void) const;
  bool HasTagIdentifierNamespace(void) const;
  bool IsCanonicalDeclaration(void) const;
  bool IsDefinedOutsideFunctionOrMethod(void) const;
  bool IsDeprecated(void) const;
  bool IsDiscardedInGlobalModuleFragment(void) const;
  bool IsFileContextDeclaration(void) const;
  bool IsFirstDeclaration(void) const;
  bool IsFromASTFile(void) const;
  bool IsFunctionOrFunctionTemplate(void) const;
  bool IsFunctionPointerType(void) const;
  bool IsImplicit(void) const;
  bool IsInAnonymousNamespace(void) const;
  bool IsInAnotherModuleUnit(void) const;
  bool IsInExportDeclarationContext(void) const;
  // IsInIdentifierNamespace: (bool)
  std::optional<bool> IsInLocalScopeForInstantiation(void) const;
  bool IsInStdNamespace(void) const;
  bool IsInvalidDeclaration(void) const;
  bool IsInvisibleOutsideTheOwningModule(void) const;
  bool IsLocalExternDeclaration(void) const;
  bool IsModulePrivate(void) const;
  bool IsOutOfLine(void) const;
  bool IsParameterPack(void) const;
  bool IsReachable(void) const;
  bool IsReferenced(void) const;
  bool IsTemplateDeclaration(void) const;
  bool IsTemplateParameter(void) const;
  bool IsTemplateParameterPack(void) const;
  bool IsTemplated(void) const;
  bool IsThisDeclarationReferenced(void) const;
  bool IsTopLevelDeclarationInObjCContainer(void) const;
  bool IsUnavailable(void) const;
  bool IsUnconditionallyVisible(void) const;
  bool IsUsed(void) const;
  bool IsWeakImported(void) const;
  std::vector<::pasta::Decl> Redeclarations(void) const;
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, DeclContext)

  inline DeclKind Kind(void) const {
    return kind;
  }

  ::pasta::DeclCategory Category(void) const noexcept;
  std::string_view KindName(void) const noexcept;
  ::pasta::Token Token(void) const noexcept;
  ::pasta::TokenRange Tokens(void) const noexcept;

  inline bool operator==(const Decl &that) const noexcept {
    return u.opaque == that.u.opaque;
  }
  static std::optional<::pasta::Decl> From(const TokenContext &);
  static std::optional<::pasta::Decl> From(const DeclContext &);
 protected:
  friend class TokenContext;

  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::OMPDeclarativeDirectiveDecl *OMPDeclarativeDirectiveDecl;
    const ::clang::OMPDeclarativeDirectiveValueDecl *OMPDeclarativeDirectiveValueDecl;
    const ::clang::AccessSpecDecl *AccessSpecDecl;
    const ::clang::BaseUsingDecl *BaseUsingDecl;
    const ::clang::BindingDecl *BindingDecl;
    const ::clang::BlockDecl *BlockDecl;
    const ::clang::BuiltinTemplateDecl *BuiltinTemplateDecl;
    const ::clang::CXXConstructorDecl *CXXConstructorDecl;
    const ::clang::CXXConversionDecl *CXXConversionDecl;
    const ::clang::CXXDeductionGuideDecl *CXXDeductionGuideDecl;
    const ::clang::CXXDestructorDecl *CXXDestructorDecl;
    const ::clang::CXXMethodDecl *CXXMethodDecl;
    const ::clang::CXXRecordDecl *CXXRecordDecl;
    const ::clang::CapturedDecl *CapturedDecl;
    const ::clang::ClassScopeFunctionSpecializationDecl *ClassScopeFunctionSpecializationDecl;
    const ::clang::ClassTemplateDecl *ClassTemplateDecl;
    const ::clang::ClassTemplatePartialSpecializationDecl *ClassTemplatePartialSpecializationDecl;
    const ::clang::ClassTemplateSpecializationDecl *ClassTemplateSpecializationDecl;
    const ::clang::ConceptDecl *ConceptDecl;
    const ::clang::ConstructorUsingShadowDecl *ConstructorUsingShadowDecl;
    const ::clang::Decl *Decl;
    const ::clang::DeclaratorDecl *DeclaratorDecl;
    const ::clang::DecompositionDecl *DecompositionDecl;
    const ::clang::EmptyDecl *EmptyDecl;
    const ::clang::EnumConstantDecl *EnumConstantDecl;
    const ::clang::EnumDecl *EnumDecl;
    const ::clang::ExportDecl *ExportDecl;
    const ::clang::ExternCContextDecl *ExternCContextDecl;
    const ::clang::FieldDecl *FieldDecl;
    const ::clang::FileScopeAsmDecl *FileScopeAsmDecl;
    const ::clang::FriendDecl *FriendDecl;
    const ::clang::FriendTemplateDecl *FriendTemplateDecl;
    const ::clang::FunctionDecl *FunctionDecl;
    const ::clang::FunctionTemplateDecl *FunctionTemplateDecl;
    const ::clang::HLSLBufferDecl *HLSLBufferDecl;
    const ::clang::ImplicitConceptSpecializationDecl *ImplicitConceptSpecializationDecl;
    const ::clang::ImplicitParamDecl *ImplicitParamDecl;
    const ::clang::ImportDecl *ImportDecl;
    const ::clang::IndirectFieldDecl *IndirectFieldDecl;
    const ::clang::LabelDecl *LabelDecl;
    const ::clang::LifetimeExtendedTemporaryDecl *LifetimeExtendedTemporaryDecl;
    const ::clang::LinkageSpecDecl *LinkageSpecDecl;
    const ::clang::MSGuidDecl *MSGuidDecl;
    const ::clang::MSPropertyDecl *MSPropertyDecl;
    const ::clang::NamedDecl *NamedDecl;
    const ::clang::NamespaceAliasDecl *NamespaceAliasDecl;
    const ::clang::NamespaceDecl *NamespaceDecl;
    const ::clang::NonTypeTemplateParmDecl *NonTypeTemplateParmDecl;
    const ::clang::OMPAllocateDecl *OMPAllocateDecl;
    const ::clang::OMPCapturedExprDecl *OMPCapturedExprDecl;
    const ::clang::OMPDeclareMapperDecl *OMPDeclareMapperDecl;
    const ::clang::OMPDeclareReductionDecl *OMPDeclareReductionDecl;
    const ::clang::OMPRequiresDecl *OMPRequiresDecl;
    const ::clang::OMPThreadPrivateDecl *OMPThreadPrivateDecl;
    const ::clang::ObjCAtDefsFieldDecl *ObjCAtDefsFieldDecl;
    const ::clang::ObjCCategoryDecl *ObjCCategoryDecl;
    const ::clang::ObjCCategoryImplDecl *ObjCCategoryImplDecl;
    const ::clang::ObjCCompatibleAliasDecl *ObjCCompatibleAliasDecl;
    const ::clang::ObjCContainerDecl *ObjCContainerDecl;
    const ::clang::ObjCImplDecl *ObjCImplDecl;
    const ::clang::ObjCImplementationDecl *ObjCImplementationDecl;
    const ::clang::ObjCInterfaceDecl *ObjCInterfaceDecl;
    const ::clang::ObjCIvarDecl *ObjCIvarDecl;
    const ::clang::ObjCMethodDecl *ObjCMethodDecl;
    const ::clang::ObjCPropertyDecl *ObjCPropertyDecl;
    const ::clang::ObjCPropertyImplDecl *ObjCPropertyImplDecl;
    const ::clang::ObjCProtocolDecl *ObjCProtocolDecl;
    const ::clang::ObjCTypeParamDecl *ObjCTypeParamDecl;
    const ::clang::ParmVarDecl *ParmVarDecl;
    const ::clang::PragmaCommentDecl *PragmaCommentDecl;
    const ::clang::PragmaDetectMismatchDecl *PragmaDetectMismatchDecl;
    const ::clang::RecordDecl *RecordDecl;
    const ::clang::RedeclarableTemplateDecl *RedeclarableTemplateDecl;
    const ::clang::RequiresExprBodyDecl *RequiresExprBodyDecl;
    const ::clang::StaticAssertDecl *StaticAssertDecl;
    const ::clang::TagDecl *TagDecl;
    const ::clang::TemplateDecl *TemplateDecl;
    const ::clang::TemplateParamObjectDecl *TemplateParamObjectDecl;
    const ::clang::TemplateTemplateParmDecl *TemplateTemplateParmDecl;
    const ::clang::TemplateTypeParmDecl *TemplateTypeParmDecl;
    const ::clang::TopLevelStmtDecl *TopLevelStmtDecl;
    const ::clang::TranslationUnitDecl *TranslationUnitDecl;
    const ::clang::TypeAliasDecl *TypeAliasDecl;
    const ::clang::TypeAliasTemplateDecl *TypeAliasTemplateDecl;
    const ::clang::TypeDecl *TypeDecl;
    const ::clang::TypedefDecl *TypedefDecl;
    const ::clang::TypedefNameDecl *TypedefNameDecl;
    const ::clang::UnnamedGlobalConstantDecl *UnnamedGlobalConstantDecl;
    const ::clang::UnresolvedUsingIfExistsDecl *UnresolvedUsingIfExistsDecl;
    const ::clang::UnresolvedUsingTypenameDecl *UnresolvedUsingTypenameDecl;
    const ::clang::UnresolvedUsingValueDecl *UnresolvedUsingValueDecl;
    const ::clang::UsingDecl *UsingDecl;
    const ::clang::UsingDirectiveDecl *UsingDirectiveDecl;
    const ::clang::UsingEnumDecl *UsingEnumDecl;
    const ::clang::UsingPackDecl *UsingPackDecl;
    const ::clang::UsingShadowDecl *UsingShadowDecl;
    const ::clang::ValueDecl *ValueDecl;
    const ::clang::VarDecl *VarDecl;
    const ::clang::VarTemplateDecl *VarTemplateDecl;
    const ::clang::VarTemplatePartialSpecializationDecl *VarTemplatePartialSpecializationDecl;
    const ::clang::VarTemplateSpecializationDecl *VarTemplateSpecializationDecl;
    const void *opaque;
  } u;
  DeclKind kind;

  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Decl *decl_,
                       DeclKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
    assert(ast.get() != nullptr);
    u.Decl = decl_;
  }

 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(Decl)
};

class EmptyDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EmptyDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, EmptyDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(EmptyDecl)
};

static_assert(sizeof(Decl) == sizeof(EmptyDecl));

class ExportDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExportDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ExportDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ExportDecl)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExportToken(void) const;
  ::pasta::Token RBraceToken(void) const;
  bool HasBraces(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ExportDecl)
};

static_assert(sizeof(Decl) == sizeof(ExportDecl));

class ExternCContextDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExternCContextDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ExternCContextDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ExternCContextDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ExternCContextDecl)
};

static_assert(sizeof(Decl) == sizeof(ExternCContextDecl));

class FileScopeAsmDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FileScopeAsmDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FileScopeAsmDecl)
  ::pasta::Token AssemblyToken(void) const;
  ::pasta::StringLiteral AssemblyString(void) const;
  ::pasta::Token RParenToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FileScopeAsmDecl)
};

static_assert(sizeof(Decl) == sizeof(FileScopeAsmDecl));

class FriendDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendDecl)
  std::optional<::pasta::NamedDecl> FriendDeclaration(void) const;
  ::pasta::Token FriendToken(void) const;
  std::optional<::pasta::Type> FriendType(void) const;
  uint32_t FriendTypeNumTemplateParameterLists(void) const;
  // FriendTypeTemplateParameterList: (clang::TemplateParameterList *)
  bool IsUnsupportedFriend(void) const;
  std::vector<::pasta::TemplateParameterList> FriendTypeTemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendDecl));

class FriendTemplateDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendTemplateDecl)
  ::pasta::NamedDecl FriendDeclaration(void) const;
  ::pasta::Token FriendToken(void) const;
  ::pasta::Type FriendType(void) const;
  uint32_t NumTemplateParameters(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendTemplateDecl));

class ImplicitConceptSpecializationDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImplicitConceptSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ImplicitConceptSpecializationDecl)
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ImplicitConceptSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ImplicitConceptSpecializationDecl));

class ImportDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImportDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ImportDecl)
  std::vector<::pasta::Token> IdentifierTokens(void) const;
  // ImportedModule: (clang::Module *)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ImportDecl)
};

static_assert(sizeof(Decl) == sizeof(ImportDecl));

class LifetimeExtendedTemporaryDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LifetimeExtendedTemporaryDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
  std::vector<::pasta::Stmt> Children(void) const;
  ::pasta::ValueDecl ExtendingDeclaration(void) const;
  uint32_t ManglingNumber(void) const;
  // OrCreateValue: (clang::APValue *)
  enum StorageDuration StorageDuration(void) const;
  ::pasta::Expr TemporaryExpression(void) const;
  // Value: (clang::APValue *)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(LifetimeExtendedTemporaryDecl)
};

static_assert(sizeof(Decl) == sizeof(LifetimeExtendedTemporaryDecl));

class LinkageSpecDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LinkageSpecDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, LinkageSpecDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, LinkageSpecDecl)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExternToken(void) const;
  enum LinkageSpecDeclLanguageIDs Language(void) const;
  ::pasta::Token RBraceToken(void) const;
  bool HasBraces(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(LinkageSpecDecl)
};

static_assert(sizeof(Decl) == sizeof(LinkageSpecDecl));

class NamedDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamedDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, NamedDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, BaseUsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, BindingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, BuiltinTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ClassTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ConceptDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, DeclaratorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, EnumConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, FunctionTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, HLSLBufferDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, IndirectFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, LabelDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, MSGuidDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, MSPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, NamespaceAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, NamespaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, OMPDeclareMapperDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCContainerDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCImplementationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCInterfaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCIvarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCProtocolDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, RedeclarableTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TemplateParamObjectDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TemplateTypeParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TypeDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TypedefDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, TypedefNameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnnamedGlobalConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingIfExistsDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingEnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingPackDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
  // DeclarationReplaces: (bool)
  // DeclarationName: (clang::DeclarationName)
  // ExplicitVisibility: (std::optional<clang::Visibility>)
  enum Linkage FormalLinkage(void) const;
  // Identifier: (clang::IdentifierInfo *)
  // LinkageAndVisibility: (clang::LinkageInfo)
  enum Linkage LinkageInternal(void) const;
  ::pasta::NamedDecl MostRecentDeclaration(void) const;
  std::string Name(void) const;
  std::optional<enum ObjCStringFormatFamily> ObjCFStringFormattingFamily(void) const;
  std::string QualifiedNameAsString(void) const;
  ::pasta::NamedDecl UnderlyingDeclaration(void) const;
  enum Visibility Visibility(void) const;
  bool HasExternalFormalLinkage(void) const;
  bool HasLinkage(void) const;
  bool HasLinkageBeenComputed(void) const;
  bool IsCXXClassMember(void) const;
  bool IsCXXInstanceMember(void) const;
  bool IsExternallyDeclarable(void) const;
  bool IsExternallyVisible(void) const;
  bool IsLinkageValid(void) const;
  // IsReserved: (clang::ReservedIdentifierStatus)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(NamedDecl)
};

static_assert(sizeof(Decl) == sizeof(NamedDecl));

class NamespaceAliasDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamespaceAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, NamespaceAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, NamespaceAliasDecl)
  ::pasta::Token AliasToken(void) const;
  ::pasta::NamedDecl AliasedNamespace(void) const;
  ::pasta::NamespaceAliasDecl CanonicalDeclaration(void) const;
  ::pasta::NamespaceDecl Namespace(void) const;
  ::pasta::Token NamespaceToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token TargetNameToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(NamespaceAliasDecl)
};

static_assert(sizeof(Decl) == sizeof(NamespaceAliasDecl));

class NamespaceDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamespaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, NamespaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, NamespaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, NamespaceDecl)
  std::optional<::pasta::NamespaceDecl> AnonymousNamespace(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::NamespaceDecl CanonicalDeclaration(void) const;
  ::pasta::NamespaceDecl OriginalNamespace(void) const;
  ::pasta::Token RBraceToken(void) const;
  bool IsAnonymousNamespace(void) const;
  bool IsInline(void) const;
  bool IsNested(void) const;
  bool IsOriginalNamespace(void) const;
  // IsRedundantInlineQualifierFor: (bool)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(NamespaceDecl)
};

static_assert(sizeof(Decl) == sizeof(NamespaceDecl));

class ObjCCompatibleAliasDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCompatibleAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCCompatibleAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCCompatibleAliasDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCCompatibleAliasDecl));

class ObjCContainerDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCContainerDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCContainerDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCContainerDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCContainerDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
  // FindPropertyDeclaration: (clang::ObjCPropertyDecl *)
  // HasUserDeclaredSetterMethod: (bool)
  std::vector<::pasta::ObjCMethodDecl> ClassMethods(void) const;
  std::vector<::pasta::ObjCPropertyDecl> ClassProperties(void) const;
  ::pasta::TokenRange AtEndRange(void) const;
  ::pasta::Token AtStartToken(void) const;
  // ClassMethod: (clang::ObjCMethodDecl *)
  // InstanceMethod: (clang::ObjCMethodDecl *)
  // InstanceVariableDeclaration: (clang::ObjCIvarDecl *)
  // Method: (clang::ObjCMethodDecl *)
  // Property: (clang::ObjCPropertyDecl *)
  std::vector<::pasta::ObjCMethodDecl> InstanceMethods(void) const;
  std::vector<::pasta::ObjCPropertyDecl> InstanceProperties(void) const;
  std::vector<::pasta::ObjCMethodDecl> Methods(void) const;
  std::vector<::pasta::ObjCPropertyDecl> Properties(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCContainerDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCContainerDecl));

class ObjCImplDecl : public ObjCContainerDecl {
 private:
  using ObjCContainerDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
  // FindPropertyImplementationDeclaration: (clang::ObjCPropertyImplDecl *)
  // FindPropertyImplementationInstanceVariableDeclaration: (clang::ObjCPropertyImplDecl *)
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  std::vector<::pasta::ObjCPropertyImplDecl> PropertyImplementations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCImplDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCImplDecl));

class ObjCImplementationDecl : public ObjCImplDecl {
 private:
  using ObjCImplDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCImplementationDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCImplementationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCImplementationDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCImplementationDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
  // Identifier: (clang::IdentifierInfo *)
  ::pasta::Token InstanceVariableLBraceToken(void) const;
  ::pasta::Token InstanceVariableRBraceToken(void) const;
  std::string Name(void) const;
  uint32_t NumInstanceVariableInitializers(void) const;
  std::string_view ObjCRuntimeNameAsString(void) const;
  ::pasta::ObjCInterfaceDecl SuperClass(void) const;
  ::pasta::Token SuperClassToken(void) const;
  bool HasDestructors(void) const;
  bool HasNonZeroConstructors(void) const;
  // Initializers: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCImplementationDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCImplementationDecl));

class ObjCInterfaceDecl : public ObjCContainerDecl {
 private:
  using ObjCContainerDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCInterfaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCInterfaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCInterfaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCInterfaceDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
  // FindCategoryDeclaration: (clang::ObjCCategoryDecl *)
  // FindPropertyVisibleInPrimaryClass: (clang::ObjCPropertyDecl *)
  std::vector<::pasta::ObjCProtocolDecl> AllReferencedProtocols(void) const;
  bool DeclaresOrInheritsDesignatedInitializers(void) const;
  ::pasta::ObjCInterfaceDecl CanonicalDeclaration(void) const;
  // CategoryClassMethod: (clang::ObjCMethodDecl *)
  // CategoryInstanceMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCCategoryDecl CategoryListRaw(void) const;
  // CategoryMethod: (clang::ObjCMethodDecl *)
  std::optional<::pasta::ObjCInterfaceDecl> Definition(void) const;
  ::pasta::Token EndOfDefinitionToken(void) const;
  ::pasta::ObjCImplementationDecl Implementation(void) const;
  std::string_view ObjCRuntimeNameAsString(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  std::optional<::pasta::ObjCInterfaceDecl> SuperClass(void) const;
  ::pasta::Token SuperClassToken(void) const;
  std::optional<::pasta::Type> SuperClassTypeInfo(void) const;
  std::optional<::pasta::ObjCObjectType> SuperClassType(void) const;
  ::pasta::Type TypeForDeclaration(void) const;
  // TypeParameterList: (clang::ObjCTypeParamList *)
  // TypeParameterListAsWritten: (clang::ObjCTypeParamList *)
  bool HasDefinition(void) const;
  bool HasDesignatedInitializers(void) const;
  bool IsArcWeakrefUnavailable(void) const;
  // IsDesignatedInitializer: (bool)
  bool IsImplicitInterfaceDeclaration(void) const;
  ::pasta::ObjCInterfaceDecl IsObjCRequiresPropertyDefinitions(void) const;
  // IsSuperClassOf: (bool)
  bool IsThisDeclarationADefinition(void) const;
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const;
  std::vector<::pasta::ObjCCategoryDecl> KnownCategories(void) const;
  std::vector<::pasta::ObjCCategoryDecl> KnownExtensions(void) const;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupMethod: (clang::ObjCMethodDecl *)
  // LookupPrivateMethod: (clang::ObjCMethodDecl *)
  // LookupPropertyAccessor: (clang::ObjCMethodDecl *)
  std::vector<::pasta::Token> ProtocolTokens(void) const;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const;
  std::vector<::pasta::ObjCCategoryDecl> VisibleCategories(void) const;
  std::vector<::pasta::ObjCCategoryDecl> VisibleExtensions(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCInterfaceDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCInterfaceDecl));

class ObjCMethodDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCMethodDecl)
  bool DefinedInNSObject(void) const;
  ::pasta::ObjCPropertyDecl FindPropertyDeclaration(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCMethodDecl CanonicalDeclaration(void) const;
  ::pasta::ObjCCategoryDecl Category(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::ImplicitParamDecl CommandDeclaration(void) const;
  ::pasta::Token DeclaratorEndToken(void) const;
  ::pasta::Token EndToken(void) const;
  enum ObjCMethodDeclImplementationControl ImplementationControl(void) const;
  enum ObjCMethodFamily MethodFamily(void) const;
  uint32_t NumSelectorTokens(void) const;
  enum DeclObjCDeclQualifier ObjCDeclQualifier(void) const;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::Type ReturnType(void) const;
  ::pasta::TokenRange ReturnTypeTokens(void) const;
  // Selector: (clang::Selector)
  // SelectorToken: (clang::SourceLocation)
  ::pasta::Token SelectorStartToken(void) const;
  ::pasta::ImplicitParamDecl SelfDeclaration(void) const;
  // SelfType: (clang::QualType)
  bool HasParameterDestroyedInCallee(void) const;
  bool HasRedeclaration(void) const;
  bool HasRelatedResultType(void) const;
  bool HasSkippedBody(void) const;
  bool IsClassMethod(void) const;
  bool IsDefined(void) const;
  bool IsDesignatedInitializerForTheInterface(void) const;
  bool IsDirectMethod(void) const;
  bool IsInstanceMethod(void) const;
  bool IsOptional(void) const;
  bool IsOverriding(void) const;
  bool IsPropertyAccessor(void) const;
  bool IsRedeclaration(void) const;
  bool IsSynthesizedAccessorStub(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsThisDeclarationADesignatedInitializer(void) const;
  bool IsVariadic(void) const;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const;
  std::vector<::pasta::Token> SelectorTokens(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCMethodDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCMethodDecl));

class ObjCPropertyDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCPropertyDecl)
  ::pasta::Token AtToken(void) const;
  // DefaultSynthInstanceVariableName: (clang::IdentifierInfo *)
  ::pasta::ObjCMethodDecl GetterMethodDeclaration(void) const;
  // GetterName: (clang::Selector)
  ::pasta::Token GetterNameToken(void) const;
  ::pasta::Token LParenToken(void) const;
  // PropertyAttributes: (clang::ObjCPropertyAttribute::Kind)
  // PropertyAttributesAsWritten: (clang::ObjCPropertyAttribute::Kind)
  enum ObjCPropertyDeclPropertyControl PropertyImplementation(void) const;
  ::pasta::ObjCIvarDecl PropertyInstanceVariableDeclaration(void) const;
  enum ObjCPropertyQueryKind QueryKind(void) const;
  enum ObjCPropertyDeclSetterKind SetterKind(void) const;
  ::pasta::ObjCMethodDecl SetterMethodDeclaration(void) const;
  // SetterName: (clang::Selector)
  ::pasta::Token SetterNameToken(void) const;
  ::pasta::Type Type(void) const;
  // UsageType: (clang::QualType)
  bool IsAtomic(void) const;
  bool IsClassProperty(void) const;
  bool IsDirectProperty(void) const;
  bool IsInstanceProperty(void) const;
  bool IsOptional(void) const;
  bool IsReadOnly(void) const;
  bool IsRetaining(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCPropertyDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyDecl));

class ObjCPropertyImplDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCPropertyImplDecl)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Expr GetterCXXConstructor(void) const;
  ::pasta::ObjCMethodDecl GetterMethodDeclaration(void) const;
  ::pasta::ObjCPropertyDecl PropertyDeclaration(void) const;
  enum ObjCPropertyImplDeclKind PropertyImplementation(void) const;
  ::pasta::ObjCIvarDecl PropertyInstanceVariableDeclaration(void) const;
  ::pasta::Token PropertyInstanceVariableDeclarationToken(void) const;
  ::pasta::Expr SetterCXXAssignment(void) const;
  ::pasta::ObjCMethodDecl SetterMethodDeclaration(void) const;
  bool IsInstanceVariableNameSpecified(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCPropertyImplDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyImplDecl));

class ObjCProtocolDecl : public ObjCContainerDecl {
 private:
  using ObjCContainerDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCProtocolDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCProtocolDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCProtocolDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCProtocolDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
  ::pasta::ObjCProtocolDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::ObjCProtocolDecl> Definition(void) const;
  std::string_view ObjCRuntimeNameAsString(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  bool HasDefinition(void) const;
  bool IsNonRuntimeProtocol(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupMethod: (clang::ObjCMethodDecl *)
  std::vector<::pasta::Token> ProtocolTokens(void) const;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCProtocolDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCProtocolDecl));

class PragmaCommentDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaCommentDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, PragmaCommentDecl)
  std::string_view Argument(void) const;
  enum PragmaMSCommentKind CommentKind(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(PragmaCommentDecl)
};

static_assert(sizeof(Decl) == sizeof(PragmaCommentDecl));

class PragmaDetectMismatchDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaDetectMismatchDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, PragmaDetectMismatchDecl)
  std::string_view Name(void) const;
  std::string_view Value(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(PragmaDetectMismatchDecl)
};

static_assert(sizeof(Decl) == sizeof(PragmaDetectMismatchDecl));

class RequiresExprBodyDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RequiresExprBodyDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, RequiresExprBodyDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, RequiresExprBodyDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(RequiresExprBodyDecl)
};

static_assert(sizeof(Decl) == sizeof(RequiresExprBodyDecl));

class StaticAssertDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StaticAssertDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, StaticAssertDecl)
  ::pasta::Expr AssertExpression(void) const;
  std::optional<::pasta::Expr> Message(void) const;
  ::pasta::Token RParenToken(void) const;
  bool IsFailed(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(StaticAssertDecl)
};

static_assert(sizeof(Decl) == sizeof(StaticAssertDecl));

class TemplateDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, BuiltinTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, ClassTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, ConceptDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, FunctionTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, RedeclarableTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TemplateDecl, VarTemplateDecl)
  ::pasta::TemplateParameterList TemplateParameters(void) const;
  ::pasta::NamedDecl TemplatedDeclaration(void) const;
  bool HasAssociatedConstraints(void) const;
  bool IsTypeAlias(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(TemplateDecl));

class TemplateTemplateParmDecl : public TemplateDecl {
 private:
  using TemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TemplateTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::TemplateTemplateParmDecl, clang::TemplateArgumentLoc *> &)
  // DefaultArgument: (const clang::TemplateArgumentLoc &)
  ::pasta::Token DefaultArgumentToken(void) const;
  // ExpansionTemplateParameters: (clang::TemplateParameterList *)
  uint32_t NumExpansionTemplateParameters(void) const;
  bool HasDefaultArgument(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TemplateTemplateParmDecl)
};

static_assert(sizeof(Decl) == sizeof(TemplateTemplateParmDecl));

class TopLevelStmtDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TopLevelStmtDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TopLevelStmtDecl)
  ::pasta::Stmt Statement(void) const;
  bool IsSemiMissing(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TopLevelStmtDecl)
};

static_assert(sizeof(Decl) == sizeof(TopLevelStmtDecl));

class TranslationUnitDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TranslationUnitDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, TranslationUnitDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TranslationUnitDecl)
  // ASTContext: (clang::ASTContext &)
  std::optional<::pasta::NamespaceDecl> AnonymousNamespace(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TranslationUnitDecl)
};

static_assert(sizeof(Decl) == sizeof(TranslationUnitDecl));

class TypeDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TypeDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TypeDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, TemplateTypeParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, TypedefDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, TypedefNameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
  ::pasta::Token BeginToken(void) const;
  std::optional<::pasta::Type> TypeForDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypeDecl)
};

static_assert(sizeof(Decl) == sizeof(TypeDecl));

class TypedefNameDecl : public TypeDecl {
 private:
  using TypeDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypedefNameDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TypedefNameDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TypedefNameDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, TypedefNameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, TypedefDecl)
  std::optional<::pasta::TagDecl> AnonymousDeclarationWithTypedefName(void) const;
  ::pasta::TypedefNameDecl CanonicalDeclaration(void) const;
  ::pasta::Type UnderlyingType(void) const;
  bool IsModed(void) const;
  bool IsTransparentTag(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypedefNameDecl)
};

static_assert(sizeof(Decl) == sizeof(TypedefNameDecl));

class UnresolvedUsingIfExistsDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingIfExistsDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnresolvedUsingIfExistsDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnresolvedUsingIfExistsDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UnresolvedUsingIfExistsDecl)
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingIfExistsDecl));

class UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  using TypeDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
  ::pasta::UnresolvedUsingTypenameDecl CanonicalDeclaration(void) const;
  ::pasta::Token EllipsisToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token TypenameToken(void) const;
  ::pasta::Token UsingToken(void) const;
  bool IsPackExpansion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UnresolvedUsingTypenameDecl)
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingTypenameDecl));

class UsingDirectiveDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDirectiveDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingDirectiveDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingDirectiveDecl)
  ::pasta::DeclContext CommonAncestor(void) const;
  ::pasta::Token IdentifierToken(void) const;
  ::pasta::Token NamespaceKeyToken(void) const;
  ::pasta::NamespaceDecl NominatedNamespace(void) const;
  ::pasta::NamedDecl NominatedNamespaceAsWritten(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingDirectiveDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingDirectiveDecl));

class UsingPackDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingPackDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingPackDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingPackDecl)
  std::vector<::pasta::NamedDecl> Expansions(void) const;
  ::pasta::UsingPackDecl CanonicalDeclaration(void) const;
  ::pasta::NamedDecl InstantiatedFromUsingDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingPackDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingPackDecl));

class UsingShadowDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingShadowDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingShadowDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
  ::pasta::UsingShadowDecl CanonicalDeclaration(void) const;
  ::pasta::BaseUsingDecl Introducer(void) const;
  std::optional<::pasta::UsingShadowDecl> NextUsingShadowDeclaration(void) const;
  ::pasta::NamedDecl TargetDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingShadowDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingShadowDecl));

class ValueDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, BindingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, DeclaratorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, EnumConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, IndirectFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, MSGuidDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, MSPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, OMPDeclareMapperDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, ObjCIvarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, TemplateParamObjectDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, UnnamedGlobalConstantDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
  std::optional<::pasta::VarDecl> PotentiallyDecomposedVariableDeclaration(void) const;
  ::pasta::Type Type(void) const;
  bool IsInitializerCapture(void) const;
  bool IsWeak(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ValueDecl)
};

static_assert(sizeof(Decl) == sizeof(ValueDecl));

class OMPDeclarativeDirectiveDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclarativeDirectiveDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPDeclarativeDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPDeclarativeDirectiveDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPDeclarativeDirectiveDecl));

class OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPDeclarativeDirectiveValueDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPDeclarativeDirectiveValueDecl));

class AccessSpecDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AccessSpecDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, AccessSpecDecl)
  ::pasta::Token AccessSpecifierToken(void) const;
  ::pasta::Token ColonToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(AccessSpecDecl)
};

static_assert(sizeof(Decl) == sizeof(AccessSpecDecl));

class BaseUsingDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BaseUsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, BaseUsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, BaseUsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(BaseUsingDecl, UsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(BaseUsingDecl, UsingEnumDecl)
  std::vector<::pasta::UsingShadowDecl> Shadows(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(BaseUsingDecl)
};

static_assert(sizeof(Decl) == sizeof(BaseUsingDecl));

class BindingDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, BindingDecl)
  ::pasta::Expr Binding(void) const;
  ::pasta::ValueDecl DecomposedDeclaration(void) const;
  ::pasta::VarDecl HoldingVariable(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(BindingDecl)
};

static_assert(sizeof(Decl) == sizeof(BindingDecl));

class BlockDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlockDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, BlockDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, BlockDecl)
  bool BlockMissingReturnType(void) const;
  bool CanAvoidCopyToHeap(void) const;
  // Captures: (llvm::ArrayRef<clang::BlockDecl::Capture>)
  bool CapturesCXXThis(void) const;
  // CapturesVariable: (bool)
  bool DoesNotEscape(void) const;
  std::optional<::pasta::Decl> BlockManglingContextDeclaration(void) const;
  uint32_t BlockManglingNumber(void) const;
  ::pasta::Token CaretToken(void) const;
  ::pasta::CompoundStmt CompoundBody(void) const;
  uint32_t NumCaptures(void) const;
  uint32_t NumParameters(void) const;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::Type SignatureAsWritten(void) const;
  bool HasCaptures(void) const;
  bool IsConversionFromLambda(void) const;
  bool IsVariadic(void) const;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(BlockDecl)
};

static_assert(sizeof(Decl) == sizeof(BlockDecl));

class BuiltinTemplateDecl : public TemplateDecl {
 private:
  using TemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, BuiltinTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, BuiltinTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, BuiltinTemplateDecl)
  // BuiltinTemplateKind: (clang::BuiltinTemplateKind)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(BuiltinTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(BuiltinTemplateDecl));

class CapturedDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapturedDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CapturedDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CapturedDecl)
  ::pasta::ImplicitParamDecl ContextParameter(void) const;
  uint32_t ContextParameterPosition(void) const;
  uint32_t NumParameters(void) const;
  // Parameter: (clang::ImplicitParamDecl *)
  bool IsNothrow(void) const;
  std::vector<::pasta::ImplicitParamDecl> Parameters(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CapturedDecl)
};

static_assert(sizeof(Decl) == sizeof(CapturedDecl));

class ClassScopeFunctionSpecializationDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassScopeFunctionSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
  ::pasta::CXXMethodDecl Specialization(void) const;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  bool HasExplicitTemplateArguments(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassScopeFunctionSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassScopeFunctionSpecializationDecl));

class ConceptDecl : public TemplateDecl {
 private:
  using TemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConceptDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ConceptDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ConceptDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, ConceptDecl)
  ::pasta::ConceptDecl CanonicalDeclaration(void) const;
  ::pasta::Expr ConstraintExpression(void) const;
  bool IsTypeConcept(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ConceptDecl)
};

static_assert(sizeof(Decl) == sizeof(ConceptDecl));

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 private:
  using UsingShadowDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstructorUsingShadowDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ConstructorUsingShadowDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
  PASTA_DECLARE_BASE_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
  bool ConstructsVirtualBase(void) const;
  ::pasta::CXXRecordDecl ConstructedBaseClass(void) const;
  std::optional<::pasta::ConstructorUsingShadowDecl> ConstructedBaseClassShadowDeclaration(void) const;
  ::pasta::UsingDecl Introducer(void) const;
  ::pasta::CXXRecordDecl NominatedBaseClass(void) const;
  std::optional<::pasta::ConstructorUsingShadowDecl> NominatedBaseClassShadowDeclaration(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ConstructorUsingShadowDecl)
};

static_assert(sizeof(Decl) == sizeof(ConstructorUsingShadowDecl));

class DeclaratorDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclaratorDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, DeclaratorDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, DeclaratorDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, DeclaratorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, MSPropertyDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, ObjCIvarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplateSpecializationDecl)
  ::pasta::Token BeginToken(void) const;
  ::pasta::Token FirstInnerToken(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  ::pasta::Token FirstOuterToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::optional<::pasta::Expr> TrailingRequiresClause(void) const;
  ::pasta::Token TypeSpecEndToken(void) const;
  ::pasta::Token TypeSpecStartToken(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(DeclaratorDecl)
};

static_assert(sizeof(Decl) == sizeof(DeclaratorDecl));

class EnumConstantDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, EnumConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, EnumConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, EnumConstantDecl)
  ::pasta::EnumConstantDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::Expr> InitializerExpression(void) const;
  llvm::APSInt InitializerValue(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(EnumConstantDecl)
};

static_assert(sizeof(Decl) == sizeof(EnumConstantDecl));

class FieldDecl : public DeclaratorDecl {
 private:
  using DeclaratorDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, FieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, FieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FieldDecl, ObjCIvarDecl)
  std::optional<::pasta::Expr> BitWidth(void) const;
  uint32_t BitWidthValue(void) const;
  ::pasta::FieldDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::VariableArrayType> CapturedVLAType(void) const;
  uint32_t FieldIndex(void) const;
  enum InClassInitStyle InClassInitializerStyle(void) const;
  std::optional<::pasta::Expr> InClassInitializer(void) const;
  ::pasta::RecordDecl Parent(void) const;
  bool HasCapturedVLAType(void) const;
  bool HasInClassInitializer(void) const;
  bool HasNonNullInClassInitializer(void) const;
  bool IsAnonymousStructOrUnion(void) const;
  bool IsBitField(void) const;
  bool IsMutable(void) const;
  bool IsPotentiallyOverlapping(void) const;
  bool IsUnnamedBitfield(void) const;
  bool IsZeroLengthBitField(void) const;
  bool IsZeroSize(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::optional<uint64_t> OffsetInBits(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FieldDecl)
};

static_assert(sizeof(Decl) == sizeof(FieldDecl));

class FunctionDecl : public DeclaratorDecl {
 private:
  using DeclaratorDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, FunctionDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FunctionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, FunctionDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, FunctionDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXMethodDecl)
  bool BodyContainsImmediateEscalatingExpressions(void) const;
  bool FriendConstraintRefersToEnclosingTemplate(void) const;
  bool UsesFPIntrin(void) const;
  std::optional<bool> DoesDeclarationForceExternallyVisibleDefinition(void) const;
  bool DoesThisDeclarationHaveABody(void) const;
  uint32_t BuiltinID(void) const;
  ::pasta::Type CallResultType(void) const;
  ::pasta::FunctionDecl CanonicalDeclaration(void) const;
  enum ConstexprSpecKind ConstexprKind(void) const;
  ::pasta::Type DeclaredReturnType(void) const;
  ::pasta::Token DefaultToken(void) const;
  // DefaultedFunctionInfo: (clang::FunctionDecl::DefaultedFunctionInfo *)
  std::optional<::pasta::FunctionDecl> Definition(void) const;
  // DependentSpecializationInfo: (clang::DependentFunctionTemplateSpecializationInfo *)
  std::optional<::pasta::FunctionTemplateDecl> DescribedFunctionTemplate(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::TokenRange ExceptionSpecTokens(void) const;
  enum ExceptionSpecificationType ExceptionSpecType(void) const;
  // FunctionTypeToken: (clang::FunctionTypeLoc)
  std::optional<::pasta::FunctionDecl> InstantiatedFromDeclaration(void) const;
  std::optional<::pasta::FunctionDecl> InstantiatedFromMemberFunction(void) const;
  enum LanguageLinkage LanguageLinkage(void) const;
  // LiteralIdentifier: (const clang::IdentifierInfo *)
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  uint32_t MemoryFunctionKind(void) const;
  uint32_t MinRequiredArguments(void) const;
  enum MultiVersionKind MultiVersionKind(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  uint32_t NumParameters(void) const;
  std::optional<uint32_t> ODRHash(void) const;
  enum OverloadedOperatorKind OverloadedOperator(void) const;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::TokenRange ParametersTokens(void) const;
  ::pasta::Token PointOfInstantiation(void) const;
  std::optional<::pasta::FunctionTemplateDecl> PrimaryTemplate(void) const;
  ::pasta::Type ReturnType(void) const;
  enum StorageClass StorageClass(void) const;
  std::optional<::pasta::FunctionDecl> TemplateInstantiationPattern(void) const;
  // TemplateSpecializationArguments: (const clang::TemplateArgumentList *)
  // TemplateSpecializationArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateSpecializationInfo: (clang::FunctionTemplateSpecializationInfo *)
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const;
  enum FunctionDeclTemplatedKind TemplatedKind(void) const;
  bool HasImplicitReturnZero(void) const;
  bool HasInheritedPrototype(void) const;
  bool HasOneParameterOrDefaultArguments(void) const;
  bool HasPrototype(void) const;
  bool HasSkippedBody(void) const;
  bool HasTrivialBody(void) const;
  bool HasWrittenPrototype(void) const;
  bool InstantiationIsPending(void) const;
  bool IsCPUDispatchMultiVersion(void) const;
  bool IsCPUSpecificMultiVersion(void) const;
  bool IsConsteval(void) const;
  bool IsConstexpr(void) const;
  bool IsConstexprSpecified(void) const;
  bool IsDefaulted(void) const;
  bool IsDeleted(void) const;
  bool IsDeletedAsWritten(void) const;
  bool IsDestroyingOperatorDelete(void) const;
  bool IsExplicitlyDefaulted(void) const;
  bool IsExternC(void) const;
  bool IsFunctionTemplateSpecialization(void) const;
  bool IsGlobal(void) const;
  bool IsImmediateEscalating(void) const;
  bool IsImmediateFunction(void) const;
  bool IsImplicitlyInstantiable(void) const;
  bool IsInExternCContext(void) const;
  bool IsInExternCXXContext(void) const;
  bool IsIneligibleOrNotSelected(void) const;
  bool IsInlineBuiltinDeclaration(void) const;
  std::optional<bool> IsInlineDefinitionExternallyVisible(void) const;
  bool IsInlineSpecified(void) const;
  bool IsInlined(void) const;
  bool IsLateTemplateParsed(void) const;
  std::optional<bool> IsMSExternInline(void) const;
  bool IsMSVCRTEntryPoint(void) const;
  bool IsMain(void) const;
  bool IsMemberLikeConstrainedFriend(void) const;
  bool IsMultiVersion(void) const;
  bool IsNoReturn(void) const;
  bool IsOverloadedOperator(void) const;
  bool IsPure(void) const;
  bool IsReplaceableGlobalAllocationFunction(void) const;
  std::optional<bool> IsReservedGlobalPlacementOperator(void) const;
  bool IsStatic(void) const;
  bool IsTargetClonesMultiVersion(void) const;
  bool IsTargetMultiVersion(void) const;
  bool IsTemplateInstantiation(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsThisDeclarationInstantiatedFromAFriendDefinition(void) const;
  bool IsTrivial(void) const;
  bool IsTrivialForCall(void) const;
  bool IsUserProvided(void) const;
  bool IsVariadic(void) const;
  bool IsVirtualAsWritten(void) const;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const;
  bool UsesSEHTry(void) const;
  bool WillHaveBody(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
  std::optional<::pasta::Stmt> Body(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FunctionDecl)
};

static_assert(sizeof(Decl) == sizeof(FunctionDecl));

class HLSLBufferDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(HLSLBufferDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, HLSLBufferDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, HLSLBufferDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, HLSLBufferDecl)
  ::pasta::Token LBraceToken(void) const;
  ::pasta::Token TokenStart(void) const;
  ::pasta::Token RBraceToken(void) const;
  bool IsCBuffer(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(HLSLBufferDecl)
};

static_assert(sizeof(Decl) == sizeof(HLSLBufferDecl));

class IndirectFieldDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, IndirectFieldDecl)
  std::vector<::pasta::NamedDecl> Chain(void) const;
  std::optional<::pasta::FieldDecl> AnonymousField(void) const;
  ::pasta::IndirectFieldDecl CanonicalDeclaration(void) const;
  uint32_t ChainingSize(void) const;
  std::optional<::pasta::VarDecl> VariableDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(IndirectFieldDecl)
};

static_assert(sizeof(Decl) == sizeof(IndirectFieldDecl));

class LabelDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LabelDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, LabelDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, LabelDecl)
  std::string_view MSAssemblyLabel(void) const;
  ::pasta::LabelStmt Statement(void) const;
  bool IsGnuLocal(void) const;
  bool IsMSAssemblyLabel(void) const;
  bool IsResolvedMSAssemblyLabel(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(LabelDecl)
};

static_assert(sizeof(Decl) == sizeof(LabelDecl));

class MSGuidDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSGuidDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, MSGuidDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, MSGuidDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, MSGuidDecl)
  // AsAPValue: (clang::APValue &)
  // Parts: (clang::MSGuidDeclParts)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(MSGuidDecl)
};

static_assert(sizeof(Decl) == sizeof(MSGuidDecl));

class MSPropertyDecl : public DeclaratorDecl {
 private:
  using DeclaratorDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, MSPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, MSPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, MSPropertyDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, MSPropertyDecl)
  // GetterId: (clang::IdentifierInfo *)
  // SetterId: (clang::IdentifierInfo *)
  bool HasGetter(void) const;
  bool HasSetter(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(MSPropertyDecl)
};

static_assert(sizeof(Decl) == sizeof(MSPropertyDecl));

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 private:
  using DeclaratorDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NonTypeTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, NonTypeTemplateParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, NonTypeTemplateParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::NonTypeTemplateParmDecl, clang::Expr *> &)
  std::optional<::pasta::Expr> DefaultArgument(void) const;
  ::pasta::Token DefaultArgumentToken(void) const;
  // ExpansionType: (clang::QualType)
  std::optional<uint32_t> NumExpansionTypes(void) const;
  std::optional<::pasta::Expr> PlaceholderTypeConstraint(void) const;
  bool HasDefaultArgument(void) const;
  bool HasPlaceholderTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  // !!! ExpansionType getNumExpansionTypes getExpansionTypeSourceInfo (bad CxxName)
  std::vector<::pasta::Type> ExpansionTypes(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(NonTypeTemplateParmDecl)
};

static_assert(sizeof(Decl) == sizeof(NonTypeTemplateParmDecl));

class OMPAllocateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  using OMPDeclarativeDirectiveDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPAllocateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPAllocateDecl)
  PASTA_DECLARE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
  std::vector<::pasta::Expr> Varlists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPAllocateDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPAllocateDecl));

class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 private:
  using OMPDeclarativeDirectiveValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareMapperDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, OMPDeclareMapperDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPDeclareMapperDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, OMPDeclareMapperDecl)
  PASTA_DECLARE_BASE_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, OMPDeclareMapperDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
  ::pasta::Expr MapperVariableReference(void) const;
  ::pasta::OMPDeclareMapperDecl PrevDeclarationInScope(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPDeclareMapperDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareMapperDecl));

class OMPDeclareReductionDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareReductionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, OMPDeclareReductionDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPDeclareReductionDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
  ::pasta::Expr Combiner(void) const;
  ::pasta::Expr CombinerIn(void) const;
  ::pasta::Expr CombinerOut(void) const;
  ::pasta::Expr InitializerOriginal(void) const;
  ::pasta::Expr InitializerPrivate(void) const;
  ::pasta::Expr Initializer(void) const;
  enum OMPDeclareReductionDeclInitKind InitializerKind(void) const;
  ::pasta::OMPDeclareReductionDecl PrevDeclarationInScope(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPDeclareReductionDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareReductionDecl));

class OMPRequiresDecl : public OMPDeclarativeDirectiveDecl {
 private:
  using OMPDeclarativeDirectiveDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPRequiresDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPRequiresDecl)
  PASTA_DECLARE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPRequiresDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPRequiresDecl));

class OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  using OMPDeclarativeDirectiveDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPThreadPrivateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPThreadPrivateDecl)
  PASTA_DECLARE_BASE_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
  std::vector<::pasta::Expr> Varlists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPThreadPrivateDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPThreadPrivateDecl));

class ObjCAtDefsFieldDecl : public FieldDecl {
 private:
  using FieldDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtDefsFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCAtDefsFieldDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCAtDefsFieldDecl));

class ObjCCategoryDecl : public ObjCContainerDecl {
 private:
  using ObjCContainerDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCategoryDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCCategoryDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCCategoryDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCCategoryDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
  bool IsClassExtension(void) const;
  ::pasta::Token CategoryNameToken(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::ObjCCategoryImplDecl Implementation(void) const;
  ::pasta::Token InstanceVariableLBraceToken(void) const;
  ::pasta::Token InstanceVariableRBraceToken(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategory(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategoryRaw(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  // TypeParameterList: (clang::ObjCTypeParamList *)
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const;
  std::vector<::pasta::Token> ProtocolTokens(void) const;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCCategoryDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryDecl));

class ObjCCategoryImplDecl : public ObjCImplDecl {
 private:
  using ObjCImplDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCategoryImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ObjCCategoryImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCCategoryImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
  ::pasta::ObjCCategoryDecl CategoryDeclaration(void) const;
  ::pasta::Token CategoryNameToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCCategoryImplDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryImplDecl));

class ObjCIvarDecl : public FieldDecl {
 private:
  using FieldDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIvarDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCIvarDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, ObjCIvarDecl)
  PASTA_DECLARE_BASE_OPERATORS(FieldDecl, ObjCIvarDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCIvarDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, ObjCIvarDecl)
  enum ObjCIvarDeclAccessControl AccessControl(void) const;
  enum ObjCIvarDeclAccessControl CanonicalAccessControl(void) const;
  ::pasta::ObjCIvarDecl CanonicalDeclaration(void) const;
  ::pasta::ObjCInterfaceDecl ContainingInterface(void) const;
  ::pasta::ObjCIvarDecl NextInstanceVariable(void) const;
  bool Synthesize(void) const;
  // UsageType: (clang::QualType)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCIvarDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCIvarDecl));

class ObjCTypeParamDecl : public TypedefNameDecl {
 private:
  using TypedefNameDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCTypeParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCTypeParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
  ::pasta::Token ColonToken(void) const;
  uint32_t Index(void) const;
  enum ObjCTypeParamVariance Variance(void) const;
  ::pasta::Token VarianceToken(void) const;
  bool HasExplicitBound(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCTypeParamDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCTypeParamDecl));

class RedeclarableTemplateDecl : public TemplateDecl {
 private:
  using TemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RedeclarableTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, RedeclarableTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, RedeclarableTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, RedeclarableTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
  ::pasta::RedeclarableTemplateDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::RedeclarableTemplateDecl> InstantiatedFromMemberTemplate(void) const;
  bool IsMemberSpecialization(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(RedeclarableTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(RedeclarableTemplateDecl));

class TagDecl : public TypeDecl {
 private:
  using TypeDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TagDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, TagDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TagDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TagDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, RecordDecl)
  ::pasta::TokenRange BraceRange(void) const;
  ::pasta::TagDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::TagDecl> Definition(void) const;
  ::pasta::Token FirstInnerToken(void) const;
  std::string_view KindName(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  ::pasta::Token FirstOuterToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  enum TagTypeKind TagKind(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::optional<::pasta::TypedefNameDecl> TypedefNameForAnonymousDeclaration(void) const;
  bool HasNameForLinkage(void) const;
  bool IsBeingDefined(void) const;
  bool IsClass(void) const;
  bool IsCompleteDefinition(void) const;
  bool IsCompleteDefinitionRequired(void) const;
  bool IsDependentType(void) const;
  bool IsEmbeddedInDeclarator(void) const;
  bool IsEnum(void) const;
  bool IsFreeStanding(void) const;
  bool IsInterface(void) const;
  bool IsStruct(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsThisDeclarationADemotedDefinition(void) const;
  bool IsUnion(void) const;
  bool MayHaveOutOfDateDefinition(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TagDecl)
};

static_assert(sizeof(Decl) == sizeof(TagDecl));

class TemplateParamObjectDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateParamObjectDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TemplateParamObjectDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TemplateParamObjectDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, TemplateParamObjectDecl)
  ::pasta::TemplateParamObjectDecl CanonicalDeclaration(void) const;
  // Value: (const clang::APValue &)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TemplateParamObjectDecl)
};

static_assert(sizeof(Decl) == sizeof(TemplateParamObjectDecl));

class TemplateTypeParmDecl : public TypeDecl {
 private:
  using TypeDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateTypeParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TemplateTypeParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TemplateTypeParmDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, TemplateTypeParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::TemplateTypeParmDecl, clang::TypeSourceInfo *> &)
  std::optional<::pasta::Type> DefaultArgument(void) const;
  std::optional<::pasta::Type> DefaultArgumentInfo(void) const;
  ::pasta::Token DefaultArgumentToken(void) const;
  uint32_t Depth(void) const;
  uint32_t Index(void) const;
  uint32_t NumExpansionParameters(void) const;
  // TypeConstraint: (const clang::TypeConstraint *)
  bool HasDefaultArgument(void) const;
  bool HasTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
  bool WasDeclaredWithTypename(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TemplateTypeParmDecl)
};

static_assert(sizeof(Decl) == sizeof(TemplateTypeParmDecl));

class TypeAliasDecl : public TypedefNameDecl {
 private:
  using TypedefNameDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TypeAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TypeAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, TypeAliasDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypedefNameDecl, TypeAliasDecl)
  std::optional<::pasta::TypeAliasTemplateDecl> DescribedAliasTemplate(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypeAliasDecl)
};

static_assert(sizeof(Decl) == sizeof(TypeAliasDecl));

class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 private:
  using RedeclarableTemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeAliasTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TypeAliasTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
  ::pasta::TypeAliasTemplateDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::TypeAliasTemplateDecl> InstantiatedFromMemberTemplate(void) const;
  std::optional<::pasta::TypeAliasTemplateDecl> PreviousDeclaration(void) const;
  ::pasta::TypeAliasDecl TemplatedDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypeAliasTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(TypeAliasTemplateDecl));

class TypedefDecl : public TypedefNameDecl {
 private:
  using TypedefNameDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypedefDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TypedefDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, TypedefDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, TypedefDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypedefNameDecl, TypedefDecl)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypedefDecl)
};

static_assert(sizeof(Decl) == sizeof(TypedefDecl));

class UnnamedGlobalConstantDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnnamedGlobalConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnnamedGlobalConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnnamedGlobalConstantDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, UnnamedGlobalConstantDecl)
  // Value: (const clang::APValue &)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UnnamedGlobalConstantDecl)
};

static_assert(sizeof(Decl) == sizeof(UnnamedGlobalConstantDecl));

class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
  ::pasta::UnresolvedUsingValueDecl CanonicalDeclaration(void) const;
  ::pasta::Token EllipsisToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
  bool IsAccessDeclaration(void) const;
  bool IsPackExpansion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UnresolvedUsingValueDecl)
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingValueDecl));

class UsingDecl : public BaseUsingDecl {
 private:
  using BaseUsingDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(BaseUsingDecl, UsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingDecl)
  ::pasta::UsingDecl CanonicalDeclaration(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
  bool HasTypename(void) const;
  bool IsAccessDeclaration(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingDecl));

class UsingEnumDecl : public BaseUsingDecl {
 private:
  using BaseUsingDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingEnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(BaseUsingDecl, UsingEnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingEnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingEnumDecl)
  ::pasta::UsingEnumDecl CanonicalDeclaration(void) const;
  ::pasta::EnumDecl EnumDeclaration(void) const;
  ::pasta::Token EnumToken(void) const;
  ::pasta::Type EnumType(void) const;
  // EnumTypeToken: (clang::TypeLoc)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingEnumDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingEnumDecl));

class VarDecl : public DeclaratorDecl {
 private:
  using DeclaratorDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, VarDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, VarDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, VarDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
  // CheckForConstantInitialization: (bool)
  // EnsureEvaluatedStatement: (clang::EvaluatedStmt *)
  // EvaluateDestruction: (bool)
  // EvaluateValue: (clang::APValue *)
  std::optional<::pasta::VarDecl> ActingDefinition(void) const;
  ::pasta::VarDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::VarTemplateDecl> DescribedVariableTemplate(void) const;
  // EvaluatedStatement: (clang::EvaluatedStmt *)
  // EvaluatedValue: (clang::APValue *)
  // FlexibleArrayInitializerCharacters: (clang::CharUnits)
  std::optional<::pasta::Expr> Initializer(void) const;
  enum VarDeclInitializationStyle InitializerStyle(void) const;
  std::optional<::pasta::VarDecl> InitializingDeclaration(void) const;
  std::optional<::pasta::VarDecl> InstantiatedFromStaticDataMember(void) const;
  enum LanguageLinkage LanguageLinkage(void) const;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::Token PointOfInstantiation(void) const;
  enum StorageClass StorageClass(void) const;
  enum StorageDuration StorageDuration(void) const;
  enum VarDeclTLSKind TLSKind(void) const;
  enum ThreadStorageClassSpecifier TSCSpec(void) const;
  std::optional<::pasta::VarDecl> TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const;
  bool HasConstantInitialization(void) const;
  bool HasDependentAlignment(void) const;
  bool HasExternalStorage(void) const;
  std::optional<bool> HasFlexibleArrayInitializer(void) const;
  bool HasGlobalStorage(void) const;
  std::optional<bool> HasICEInitializer(void) const;
  bool HasInitializer(void) const;
  bool HasLocalStorage(void) const;
  bool IsARCPseudoStrong(void) const;
  bool IsCXXForRangeDeclaration(void) const;
  bool IsConstexpr(void) const;
  bool IsDirectInitializer(void) const;
  bool IsEscapingByref(void) const;
  bool IsExceptionVariable(void) const;
  bool IsExternC(void) const;
  bool IsFileVariableDeclaration(void) const;
  bool IsFunctionOrMethodVariableDeclaration(void) const;
  bool IsInExternCContext(void) const;
  bool IsInExternCXXContext(void) const;
  bool IsInitializerCapture(void) const;
  bool IsInline(void) const;
  bool IsInlineSpecified(void) const;
  bool IsKnownToBeDefined(void) const;
  bool IsLocalVariableDeclaration(void) const;
  bool IsLocalVariableDeclarationOrParm(void) const;
  bool IsNRVOVariable(void) const;
  bool IsNoDestroy(void) const;
  bool IsNonEscapingByref(void) const;
  bool IsObjCForDeclaration(void) const;
  bool IsParameterPack(void) const;
  bool IsPreviousDeclarationInSameBlockScope(void) const;
  bool IsStaticDataMember(void) const;
  bool IsStaticLocal(void) const;
  bool IsThisDeclarationADemotedDefinition(void) const;
  bool IsUsableInConstantExpressions(void) const;
  bool MightBeUsableInConstantExpressions(void) const;
  // NeedsDestruction: (clang::QualType::DestructionKind)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(VarDecl)
};

static_assert(sizeof(Decl) == sizeof(VarDecl));

class VarTemplateDecl : public RedeclarableTemplateDecl {
 private:
  using RedeclarableTemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, VarTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, VarTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, VarTemplateDecl)
  ::pasta::VarTemplateDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::VarTemplateDecl> InstantiatedFromMemberTemplate(void) const;
  ::pasta::VarTemplateDecl MostRecentDeclaration(void) const;
  std::optional<::pasta::VarTemplateDecl> PreviousDeclaration(void) const;
  ::pasta::VarDecl TemplatedDeclaration(void) const;
  bool IsThisDeclarationADefinition(void) const;
  std::vector<::pasta::VarTemplateSpecializationDecl> Specializations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(VarTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(VarTemplateDecl));

class VarTemplateSpecializationDecl : public VarDecl {
 private:
  using VarDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, VarTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, VarTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
  ::pasta::Token ExternToken(void) const;
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> InstantiatedFrom(void) const;
  ::pasta::Token PointOfInstantiation(void) const;
  enum TemplateSpecializationKind SpecializationKind(void) const;
  ::pasta::VarTemplateDecl SpecializedTemplate(void) const;
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> SpecializedTemplateOrPartial(void) const;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const;
  // TemplateArgumentsInfo: (const clang::ASTTemplateArgumentListInfo *)
  std::vector<::pasta::TemplateArgument> TemplateInstantiationArguments(void) const;
  ::pasta::Token TemplateKeywordToken(void) const;
  ::pasta::Type TypeAsWritten(void) const;
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(VarTemplateSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(VarTemplateSpecializationDecl));

class CXXDeductionGuideDecl : public FunctionDecl {
 private:
  using FunctionDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, CXXDeductionGuideDecl)
  ::pasta::CXXConstructorDecl CorrespondingConstructor(void) const;
  ::pasta::TemplateDecl DeducedTemplate(void) const;
  enum DeductionCandidate DeductionCandidateKind(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsExplicit(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXDeductionGuideDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXDeductionGuideDecl));

class CXXMethodDecl : public FunctionDecl {
 private:
  using FunctionDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(FunctionDecl, CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXMethodDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
  ::pasta::CXXMethodDecl CanonicalDeclaration(void) const;
  // CorrespondingMethodDeclaredInClass: (const clang::CXXMethodDecl *)
  // CorrespondingMethodInClass: (const clang::CXXMethodDecl *)
  // DevirtualizedMethod: (const clang::CXXMethodDecl *)
  // MethodQualifiers: (clang::Qualifiers)
  ::pasta::CXXMethodDecl MostRecentDeclaration(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
  enum RefQualifierKind ReferenceQualifier(void) const;
  std::optional<::pasta::Type> ThisObjectType(void) const;
  std::optional<::pasta::Type> ThisType(void) const;
  bool HasInlineBody(void) const;
  bool IsConst(void) const;
  bool IsCopyAssignmentOperator(void) const;
  bool IsInstance(void) const;
  bool IsLambdaStaticInvoker(void) const;
  bool IsMoveAssignmentOperator(void) const;
  bool IsStatic(void) const;
  // IsUsualDeallocationFunction: (bool)
  bool IsVirtual(void) const;
  bool IsVolatile(void) const;
  std::vector<::pasta::CXXMethodDecl> OverriddenMethods(void) const;
  uint32_t SizeOverriddenMethods(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXMethodDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXMethodDecl));

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 private:
  using RedeclarableTemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ClassTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ClassTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, ClassTemplateDecl)
  ::pasta::ClassTemplateDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::ClassTemplateDecl> InstantiatedFromMemberTemplate(void) const;
  ::pasta::ClassTemplateDecl MostRecentDeclaration(void) const;
  std::optional<::pasta::ClassTemplateDecl> PreviousDeclaration(void) const;
  ::pasta::CXXRecordDecl TemplatedDeclaration(void) const;
  bool IsThisDeclarationADefinition(void) const;
  std::vector<::pasta::ClassTemplateSpecializationDecl> Specializations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateDecl));

class DecompositionDecl : public VarDecl {
 private:
  using VarDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DecompositionDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, DecompositionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, DecompositionDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, DecompositionDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, DecompositionDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, DecompositionDecl)
  std::vector<::pasta::BindingDecl> Bindings(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(DecompositionDecl)
};

static_assert(sizeof(Decl) == sizeof(DecompositionDecl));

class EnumDecl : public TagDecl {
 private:
  using TagDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, EnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, EnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, EnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(TagDecl, EnumDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, EnumDecl)
  std::vector<::pasta::EnumConstantDecl> Enumerators(void) const;
  ::pasta::EnumDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::EnumDecl> Definition(void) const;
  std::optional<::pasta::EnumDecl> InstantiatedFromMemberEnum(void) const;
  std::optional<::pasta::Type> IntegerType(void) const;
  ::pasta::TokenRange IntegerTypeRange(void) const;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::EnumDecl MostRecentDeclaration(void) const;
  uint32_t NumNegativeBits(void) const;
  uint32_t NumPositiveBits(void) const;
  std::optional<uint32_t> ODRHash(void) const;
  std::optional<::pasta::EnumDecl> PreviousDeclaration(void) const;
  std::optional<::pasta::Type> PromotionType(void) const;
  std::optional<::pasta::EnumDecl> TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  bool IsClosed(void) const;
  bool IsClosedFlag(void) const;
  bool IsClosedNonFlag(void) const;
  bool IsComplete(void) const;
  bool IsFixed(void) const;
  bool IsScoped(void) const;
  bool IsScopedUsingClassTag(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(EnumDecl)
};

static_assert(sizeof(Decl) == sizeof(EnumDecl));

class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 private:
  using RedeclarableTemplateDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FunctionTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, FunctionTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(TemplateDecl, FunctionTemplateDecl)
  ::pasta::FunctionTemplateDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::FunctionTemplateDecl> InstantiatedFromMemberTemplate(void) const;
  ::pasta::FunctionTemplateDecl MostRecentDeclaration(void) const;
  std::optional<::pasta::FunctionTemplateDecl> PreviousDeclaration(void) const;
  ::pasta::FunctionDecl TemplatedDeclaration(void) const;
  bool IsAbbreviated(void) const;
  bool IsThisDeclarationADefinition(void) const;
  std::vector<::pasta::FunctionDecl> Specializations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FunctionTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(FunctionTemplateDecl));

class ImplicitParamDecl : public VarDecl {
 private:
  using VarDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImplicitParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ImplicitParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, ImplicitParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ImplicitParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, ImplicitParamDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, ImplicitParamDecl)
  enum ImplicitParamDeclImplicitParamKind ParameterKind(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ImplicitParamDecl)
};

static_assert(sizeof(Decl) == sizeof(ImplicitParamDecl));

class OMPCapturedExprDecl : public VarDecl {
 private:
  using VarDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCapturedExprDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, OMPCapturedExprDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, OMPCapturedExprDecl)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(OMPCapturedExprDecl)
};

static_assert(sizeof(Decl) == sizeof(OMPCapturedExprDecl));

class ParmVarDecl : public VarDecl {
 private:
  using VarDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParmVarDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ParmVarDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, ParmVarDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ParmVarDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, ParmVarDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, ParmVarDecl)
  std::optional<::pasta::Expr> DefaultArgument(void) const;
  ::pasta::TokenRange DefaultArgumentRange(void) const;
  uint32_t FunctionScopeDepth(void) const;
  uint32_t FunctionScopeIndex(void) const;
  enum DeclObjCDeclQualifier ObjCDeclQualifier(void) const;
  ::pasta::Type OriginalType(void) const;
  std::optional<::pasta::Expr> UninstantiatedDefaultArgument(void) const;
  bool HasDefaultArgument(void) const;
  bool HasInheritedDefaultArgument(void) const;
  bool HasUninstantiatedDefaultArgument(void) const;
  bool HasUnparsedDefaultArgument(void) const;
  bool IsDestroyedInCallee(void) const;
  bool IsKNRPromoted(void) const;
  bool IsObjCMethodParameter(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ParmVarDecl)
};

static_assert(sizeof(Decl) == sizeof(ParmVarDecl));

class RecordDecl : public TagDecl {
 private:
  using TagDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, RecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, RecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, RecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(TagDecl, RecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
  bool CanPassInRegisters(void) const;
  std::vector<::pasta::FieldDecl> Fields(void) const;
  std::optional<::pasta::FieldDecl> FirstNamedDataMember(void) const;
  enum RecordDeclArgPassingKind ArgumentPassingRestrictions(void) const;
  std::optional<::pasta::RecordDecl> Definition(void) const;
  ::pasta::RecordDecl MostRecentDeclaration(void) const;
  std::optional<::pasta::RecordDecl> PreviousDeclaration(void) const;
  bool HasFlexibleArrayMember(void) const;
  bool HasLoadedFieldsFromExternalStorage(void) const;
  bool HasNonTrivialToPrimitiveCopyCUnion(void) const;
  bool HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const;
  bool HasNonTrivialToPrimitiveDestructCUnion(void) const;
  bool HasObjectMember(void) const;
  bool HasVolatileMember(void) const;
  bool IsAnonymousStructOrUnion(void) const;
  bool IsCapturedRecord(void) const;
  bool IsInjectedClassName(void) const;
  bool IsLambda(void) const;
  bool IsMsStruct(void) const;
  bool IsNonTrivialToPrimitiveCopy(void) const;
  bool IsNonTrivialToPrimitiveDefaultInitialize(void) const;
  bool IsNonTrivialToPrimitiveDestroy(void) const;
  bool IsOrContainsUnion(void) const;
  bool IsParameterDestroyedInCallee(void) const;
  bool IsRandomized(void) const;
  bool MayInsertExtraPadding(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::optional<uint64_t> Size(void) const noexcept;  // In bytes.
  std::optional<uint64_t> Alignment(void) const noexcept;  // In bytes.
  std::optional<uint64_t> SizeWithoutTrailingPadding(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(RecordDecl)
};

static_assert(sizeof(Decl) == sizeof(RecordDecl));

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 private:
  using VarTemplateSpecializationDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
  std::optional<::pasta::VarTemplatePartialSpecializationDecl> InstantiatedFromMember(void) const;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  ::pasta::TemplateParameterList TemplateParameters(void) const;
  bool HasAssociatedConstraints(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(VarTemplatePartialSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(VarTemplatePartialSpecializationDecl));

class CXXConstructorDecl : public CXXMethodDecl {
 private:
  using CXXMethodDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(FunctionDecl, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXConstructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, CXXConstructorDecl)
  ::pasta::CXXConstructorDecl CanonicalDeclaration(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  // InheritedConstructor: (clang::InheritedConstructor)
  uint32_t NumConstructorInitializers(void) const;
  std::optional<::pasta::CXXConstructorDecl> TargetConstructor(void) const;
  // Initializers: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  bool IsConvertingConstructor(bool) const;
  bool IsDefaultConstructor(void) const;
  bool IsDelegatingConstructor(void) const;
  bool IsExplicit(void) const;
  bool IsInheritingConstructor(void) const;
  bool IsSpecializationCopyingObject(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXConstructorDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXConstructorDecl));

class CXXConversionDecl : public CXXMethodDecl {
 private:
  using CXXMethodDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(CXXMethodDecl, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(FunctionDecl, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXConversionDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, CXXConversionDecl)
  ::pasta::CXXConversionDecl CanonicalDeclaration(void) const;
  ::pasta::Type ConversionType(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsExplicit(void) const;
  bool IsLambdaToBlockPointerConversion(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXConversionDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXConversionDecl));

class CXXDestructorDecl : public CXXMethodDecl {
 private:
  using CXXMethodDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclaratorDecl, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(FunctionDecl, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXDestructorDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, CXXDestructorDecl)
  ::pasta::CXXDestructorDecl CanonicalDeclaration(void) const;
  std::optional<::pasta::FunctionDecl> OperatorDelete(void) const;
  std::optional<::pasta::Expr> OperatorDeleteThisArgument(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXDestructorDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXDestructorDecl));

class CXXRecordDecl : public RecordDecl {
 private:
  using RecordDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(RecordDecl, CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(TagDecl, CXXRecordDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
  std::optional<bool> AllowConstDefaultInitializer(void) const;
  std::optional<std::vector<::pasta::CXXBaseSpecifier>> Bases(void) const;
  std::optional<enum MSInheritanceModel> CalculateInheritanceModel(void) const;
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  std::vector<::pasta::CXXConstructorDecl> Constructors(void) const;
  std::optional<bool> DefaultedCopyConstructorIsDeleted(void) const;
  std::optional<bool> DefaultedDefaultConstructorIsConstexpr(void) const;
  std::optional<bool> DefaultedDestructorIsConstexpr(void) const;
  std::optional<bool> DefaultedDestructorIsDeleted(void) const;
  std::optional<bool> DefaultedMoveConstructorIsDeleted(void) const;
  // ForallBases: (bool)
  std::optional<std::vector<::pasta::FriendDecl>> Friends(void) const;
  ::pasta::CXXRecordDecl CanonicalDeclaration(void) const;
  // Capture: (const clang::LambdaCapture *)
  std::optional<::pasta::CXXRecordDecl> Definition(void) const;
  std::optional<::pasta::FunctionTemplateDecl> DependentLambdaCallOperator(void) const;
  std::optional<::pasta::ClassTemplateDecl> DescribedClassTemplate(void) const;
  std::optional<::pasta::CXXDestructorDecl> Destructor(void) const;
  uint32_t DeviceLambdaManglingNumber(void) const;
  std::optional<::pasta::TemplateParameterList> GenericLambdaTemplateParameterList(void) const;
  std::optional<::pasta::CXXRecordDecl> InstantiatedFromMemberClass(void) const;
  std::optional<::pasta::CXXMethodDecl> LambdaCallOperator(void) const;
  std::optional<enum LambdaCaptureDefault> LambdaCaptureDefault(void) const;
  std::optional<::pasta::Decl> LambdaContextDeclaration(void) const;
  uint32_t LambdaDependencyKind(void) const;
  std::optional<std::vector<::pasta::NamedDecl>> LambdaExplicitTemplateParameters(void) const;
  uint32_t LambdaIndexInContext(void) const;
  std::optional<uint32_t> LambdaManglingNumber(void) const;
  // LambdaNumbering: (clang::CXXRecordDecl::LambdaNumbering)
  std::optional<enum MSInheritanceModel> MSInheritanceModel(void) const;
  enum MSVtorDispMode MSVtorDispMode(void) const;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::CXXRecordDecl MostRecentDeclaration(void) const;
  std::optional<uint32_t> NumBases(void) const;
  std::optional<uint32_t> NumVirtualBases(void) const;
  std::optional<uint32_t> ODRHash(void) const;
  std::optional<::pasta::CXXRecordDecl> PreviousDeclaration(void) const;
  std::optional<::pasta::CXXRecordDecl> TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  // VisibleConversionFunctions: (llvm::iterator_range<clang::UnresolvedSetIterator>)
  std::optional<bool> HasAnyDependentBases(void) const;
  std::optional<bool> HasConstexprDefaultConstructor(void) const;
  std::optional<bool> HasConstexprDestructor(void) const;
  std::optional<bool> HasConstexprNonCopyMoveConstructor(void) const;
  std::optional<bool> HasCopyAssignmentWithConstParameter(void) const;
  std::optional<bool> HasCopyConstructorWithConstParameter(void) const;
  std::optional<bool> HasDefaultConstructor(void) const;
  std::optional<bool> HasDefinition(void) const;
  std::optional<bool> HasDirectFields(void) const;
  std::optional<bool> HasFriends(void) const;
  std::optional<bool> HasInClassInitializer(void) const;
  std::optional<bool> HasInheritedAssignment(void) const;
  std::optional<bool> HasInheritedConstructor(void) const;
  std::optional<bool> HasInitializerMethod(void) const;
  std::optional<bool> HasIrrelevantDestructor(void) const;
  std::optional<bool> HasKnownLambdaInternalLinkage(void) const;
  // HasMemberName: (bool)
  std::optional<bool> HasMoveAssignment(void) const;
  std::optional<bool> HasMoveConstructor(void) const;
  std::optional<bool> HasMutableFields(void) const;
  std::optional<bool> HasNonLiteralTypeFieldsOrBases(void) const;
  std::optional<bool> HasNonTrivialCopyAssignment(void) const;
  std::optional<bool> HasNonTrivialCopyConstructor(void) const;
  std::optional<bool> HasNonTrivialCopyConstructorForCall(void) const;
  std::optional<bool> HasNonTrivialDefaultConstructor(void) const;
  std::optional<bool> HasNonTrivialDestructor(void) const;
  std::optional<bool> HasNonTrivialDestructorForCall(void) const;
  std::optional<bool> HasNonTrivialMoveAssignment(void) const;
  std::optional<bool> HasNonTrivialMoveConstructor(void) const;
  std::optional<bool> HasNonTrivialMoveConstructorForCall(void) const;
  std::optional<bool> HasPrivateFields(void) const;
  std::optional<bool> HasProtectedFields(void) const;
  std::optional<bool> HasSimpleCopyAssignment(void) const;
  std::optional<bool> HasSimpleCopyConstructor(void) const;
  std::optional<bool> HasSimpleDestructor(void) const;
  std::optional<bool> HasSimpleMoveAssignment(void) const;
  std::optional<bool> HasSimpleMoveConstructor(void) const;
  std::optional<bool> HasTrivialCopyAssignment(void) const;
  std::optional<bool> HasTrivialCopyConstructor(void) const;
  std::optional<bool> HasTrivialCopyConstructorForCall(void) const;
  std::optional<bool> HasTrivialDefaultConstructor(void) const;
  std::optional<bool> HasTrivialDestructor(void) const;
  std::optional<bool> HasTrivialDestructorForCall(void) const;
  std::optional<bool> HasTrivialMoveAssignment(void) const;
  std::optional<bool> HasTrivialMoveConstructor(void) const;
  std::optional<bool> HasTrivialMoveConstructorForCall(void) const;
  std::optional<bool> HasUninitializedReferenceMember(void) const;
  std::optional<bool> HasUserDeclaredConstructor(void) const;
  std::optional<bool> HasUserDeclaredCopyAssignment(void) const;
  std::optional<bool> HasUserDeclaredCopyConstructor(void) const;
  std::optional<bool> HasUserDeclaredDestructor(void) const;
  std::optional<bool> HasUserDeclaredMoveAssignment(void) const;
  std::optional<bool> HasUserDeclaredMoveConstructor(void) const;
  std::optional<bool> HasUserDeclaredMoveOperation(void) const;
  std::optional<bool> HasUserProvidedDefaultConstructor(void) const;
  std::optional<bool> HasVariantMembers(void) const;
  std::optional<bool> ImplicitCopyAssignmentHasConstParameter(void) const;
  std::optional<bool> ImplicitCopyConstructorHasConstParameter(void) const;
  std::optional<bool> IsAbstract(void) const;
  std::optional<bool> IsAggregate(void) const;
  std::optional<bool> IsAnyDestructorNoReturn(void) const;
  std::optional<bool> IsCLike(void) const;
  std::optional<bool> IsCXX11StandardLayout(void) const;
  // IsCurrentInstantiation: (bool)
  bool IsDependentLambda(void) const;
  std::optional<bool> IsDynamicClass(void) const;
  std::optional<bool> IsEffectivelyFinal(void) const;
  std::optional<bool> IsEmpty(void) const;
  bool IsGenericLambda(void) const;
  std::optional<bool> IsInterfaceLike(void) const;
  bool IsLambda(void) const;
  std::optional<bool> IsLiteral(void) const;
  std::optional<::pasta::FunctionDecl> IsLocalClass(void) const;
  bool IsNeverDependentLambda(void) const;
  std::optional<bool> IsPOD(void) const;
  std::optional<bool> IsParsingBaseSpecifiers(void) const;
  std::optional<bool> IsPolymorphic(void) const;
  // IsProvablyNotDerivedFrom: (bool)
  std::optional<bool> IsStandardLayout(void) const;
  std::optional<bool> IsStructural(void) const;
  std::optional<bool> IsTrivial(void) const;
  std::optional<bool> IsTriviallyCopyable(void) const;
  // IsVirtuallyDerivedFrom: (bool)
  std::optional<bool> LambdaIsDefaultConstructibleAndAssignable(void) const;
  // LookupInBases: (bool)
  std::optional<bool> MayBeAbstract(void) const;
  std::optional<bool> MayBeDynamicClass(void) const;
  std::optional<bool> MayBeNonDynamicClass(void) const;
  std::optional<std::vector<::pasta::CXXMethodDecl>> Methods(void) const;
  std::optional<bool> NeedsImplicitCopyAssignment(void) const;
  std::optional<bool> NeedsImplicitCopyConstructor(void) const;
  std::optional<bool> NeedsImplicitDefaultConstructor(void) const;
  std::optional<bool> NeedsImplicitDestructor(void) const;
  std::optional<bool> NeedsImplicitMoveAssignment(void) const;
  std::optional<bool> NeedsImplicitMoveConstructor(void) const;
  std::optional<bool> NeedsOverloadResolutionForCopyAssignment(void) const;
  std::optional<bool> NeedsOverloadResolutionForCopyConstructor(void) const;
  std::optional<bool> NeedsOverloadResolutionForDestructor(void) const;
  std::optional<bool> NeedsOverloadResolutionForMoveAssignment(void) const;
  std::optional<bool> NeedsOverloadResolutionForMoveConstructor(void) const;
  std::optional<bool> NullFieldOffsetIsZero(void) const;
  std::optional<std::vector<::pasta::CXXBaseSpecifier>> VirtualBases(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
  std::optional<uint64_t> SizeWithoutVirtualBases(void) const noexcept;
  std::optional<CXXRecordDecl> PrimaryBase(void) const noexcept;
  std::optional<bool> HasOwnVirtualFunctionTablePointer(void) const noexcept;
  std::optional<bool> HasExtendableVirtualFunctionTablePointer(void) const noexcept;
  std::optional<bool> HasVirtualBaseTablePointer(void) const noexcept;
  std::optional<bool> HasOwnVirtualBaseTablePointer(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CXXRecordDecl)
};

static_assert(sizeof(Decl) == sizeof(CXXRecordDecl));

class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 private:
  using CXXRecordDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
  ::pasta::Token ExternToken(void) const;
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> InstantiatedFrom(void) const;
  ::pasta::Token PointOfInstantiation(void) const;
  enum TemplateSpecializationKind SpecializationKind(void) const;
  ::pasta::ClassTemplateDecl SpecializedTemplate(void) const;
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> SpecializedTemplateOrPartial(void) const;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const;
  std::vector<::pasta::TemplateArgument> TemplateInstantiationArguments(void) const;
  ::pasta::Token TemplateKeywordToken(void) const;
  std::optional<::pasta::Type> TypeAsWritten(void) const;
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassTemplateSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateSpecializationDecl));

class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 private:
  using ClassTemplateSpecializationDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, ClassTemplatePartialSpecializationDecl)
  ::pasta::Type InjectedSpecializationType(void) const;
  std::optional<::pasta::ClassTemplatePartialSpecializationDecl> InstantiatedFromMember(void) const;
  std::optional<::pasta::ClassTemplatePartialSpecializationDecl> InstantiatedFromMemberTemplate(void) const;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  ::pasta::TemplateParameterList TemplateParameters(void) const;
  bool HasAssociatedConstraints(void) const;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassTemplatePartialSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassTemplatePartialSpecializationDecl));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
#include "DeclTail.h"
