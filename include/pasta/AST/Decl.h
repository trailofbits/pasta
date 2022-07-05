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
  // Encloses: (bool)
  // Equals: (bool)
  // InEnclosingNamespaceSetOf: (bool)
  // ContainsDeclaration: (bool)
  // ContainsDeclarationAndLoad: (bool)
  // Ddiags: (llvm::iterator_range<clang::DeclContext::ddiag_iterator>)
  std::vector<::pasta::Decl> Declarations(void) const noexcept;
  ::pasta::DeclKind DeclarationKind(void) const noexcept;
  std::string_view DeclarationKindName(void) const noexcept;
  std::optional<::pasta::DeclContext> EnclosingNamespaceContext(void) const noexcept;
  std::optional<::pasta::LinkageSpecDecl> ExternCContext(void) const noexcept;
  std::optional<::pasta::BlockDecl> InnermostBlockDeclaration(void) const noexcept;
  std::optional<::pasta::DeclContext> LexicalParent(void) const noexcept;
  std::optional<::pasta::DeclContext> LookupParent(void) const noexcept;
  // LookupPointer: (clang::StoredDeclsMap *)
  std::optional<::pasta::Decl> NonClosureAncestor(void) const noexcept;
  ::pasta::DeclContext NonTransparentContext(void) const noexcept;
  std::optional<::pasta::RecordDecl> OuterLexicalRecordContext(void) const noexcept;
  std::optional<::pasta::DeclContext> Parent(void) const noexcept;
  // ParentASTContext: (clang::ASTContext &)
  ::pasta::DeclContext PrimaryContext(void) const noexcept;
  ::pasta::DeclContext RedeclarationContext(void) const noexcept;
  bool HasExternalLexicalStorage(void) const noexcept;
  bool HasExternalVisibleStorage(void) const noexcept;
  bool IsClosure(void) const noexcept;
  // IsDeclarationInLexicalTraversal: (bool)
  bool IsDependentContext(void) const noexcept;
  bool IsExternCContext(void) const noexcept;
  bool IsExternCXXContext(void) const noexcept;
  bool IsFileContext(void) const noexcept;
  bool IsFunctionOrMethod(void) const noexcept;
  bool IsInlineNamespace(void) const noexcept;
  bool IsLookupContext(void) const noexcept;
  bool IsNamespace(void) const noexcept;
  bool IsObjCContainer(void) const noexcept;
  bool IsRecord(void) const noexcept;
  bool IsStdNamespace(void) const noexcept;
  bool IsTranslationUnit(void) const noexcept;
  bool IsTransparentContext(void) const noexcept;
  // Lookup: (clang::DeclContextLookupResult)
  // Lookups: (llvm::iterator_range<clang::DeclContext::all_lookups_iterator>)
  std::vector<::pasta::Decl> AlreadyLoadedDeclarations(void) const noexcept;
  // NoloadLookups: (llvm::iterator_range<clang::DeclContext::all_lookups_iterator>)
  bool ShouldUseQualifiedLookup(void) const noexcept;
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
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TranslationUnitDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypeDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypedefDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, TypedefNameDecl)
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
  std::vector<::pasta::Attr> Attributes(void) const noexcept;
  // CanBeWeakImported: (bool)
  // ASTContext: (clang::ASTContext &)
  enum AccessSpecifier Access(void) const noexcept;
  std::optional<::pasta::FunctionDecl> AsFunction(void) const noexcept;
  // Attributes: (const llvm::SmallVector<clang::Attr *, 4> &)
  enum AvailabilityResult Availability(void) const noexcept;
  ::pasta::Token BeginToken(void) const noexcept;
  ::pasta::Decl CanonicalDeclaration(void) const noexcept;
  ::pasta::DeclContext DeclarationContext(void) const noexcept;
  std::optional<::pasta::Attr> DefiningAttribute(void) const noexcept;
  std::optional<::pasta::TemplateDecl> DescribedTemplate(void) const noexcept;
  std::optional<::pasta::TemplateParameterList> DescribedTemplateParameters(void) const noexcept;
  ::pasta::Token EndToken(void) const noexcept;
  // ExternalSourceSymbolAttribute: (clang::ExternalSourceSymbolAttr *)
  enum DeclFriendObjectKind FriendObjectKind(void) const noexcept;
  std::optional<::pasta::FunctionType> FunctionType(void) const noexcept;
  uint32_t GlobalID(void) const noexcept;
  int64_t ID(void) const noexcept;
  uint32_t IdentifierNamespace(void) const noexcept;
  // ImportedOwningModule: (clang::Module *)
  // LangOpts: (const clang::LangOptions &)
  ::pasta::DeclContext LexicalDeclarationContext(void) const noexcept;
  // LocalOwningModule: (clang::Module *)
  uint32_t MaxAlignment(void) const noexcept;
  enum DeclModuleOwnershipKind ModuleOwnershipKind(void) const noexcept;
  ::pasta::Decl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::Decl> NextDeclarationInContext(void) const noexcept;
  std::optional<::pasta::Decl> NonClosureContext(void) const noexcept;
  // OwningModule: (clang::Module *)
  // OwningModuleForLinkage: (clang::Module *)
  uint32_t OwningModuleID(void) const noexcept;
  std::optional<::pasta::DeclContext> ParentFunctionOrMethod(void) const noexcept;
  std::optional<::pasta::Decl> PreviousDeclaration(void) const noexcept;
  uint32_t TemplateDepth(void) const noexcept;
  ::pasta::TranslationUnitDecl TranslationUnitDeclaration(void) const noexcept;
  // VersionIntroduced: (llvm::VersionTuple)
  bool HasAttributes(void) const noexcept;
  bool HasBody(void) const noexcept;
  bool HasDefiningAttribute(void) const noexcept;
  bool HasOwningModule(void) const noexcept;
  bool HasTagIdentifierNamespace(void) const noexcept;
  bool IsCanonicalDeclaration(void) const noexcept;
  bool IsDefinedOutsideFunctionOrMethod(void) const noexcept;
  bool IsDeprecated(void) const noexcept;
  bool IsFirstDeclaration(void) const noexcept;
  bool IsFromASTFile(void) const noexcept;
  bool IsFunctionOrFunctionTemplate(void) const noexcept;
  bool IsImplicit(void) const noexcept;
  bool IsInAnonymousNamespace(void) const noexcept;
  bool IsInExportDeclarationContext(void) const noexcept;
  // IsInIdentifierNamespace: (bool)
  bool IsInLocalScopeForInstantiation(void) const noexcept;
  bool IsInStdNamespace(void) const noexcept;
  bool IsInvalidDeclaration(void) const noexcept;
  bool IsModulePrivate(void) const noexcept;
  bool IsOutOfLine(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
  bool IsReferenced(void) const noexcept;
  bool IsTemplateDeclaration(void) const noexcept;
  bool IsTemplateParameter(void) const noexcept;
  bool IsTemplateParameterPack(void) const noexcept;
  bool IsTemplated(void) const noexcept;
  bool IsThisDeclarationReferenced(void) const noexcept;
  bool IsTopLevelDeclarationInObjCContainer(void) const noexcept;
  bool IsUnavailable(void) const noexcept;
  bool IsUnconditionallyVisible(void) const noexcept;
  bool IsUsed(void) const noexcept;
  bool IsWeakImported(void) const noexcept;
  std::vector<::pasta::Decl> Redeclarations(void) const noexcept;
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
    const ::clang::TranslationUnitDecl *TranslationUnitDecl;
    const ::clang::TypeAliasDecl *TypeAliasDecl;
    const ::clang::TypeAliasTemplateDecl *TypeAliasTemplateDecl;
    const ::clang::TypeDecl *TypeDecl;
    const ::clang::TypedefDecl *TypedefDecl;
    const ::clang::TypedefNameDecl *TypedefNameDecl;
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
  ::pasta::Token EndToken(void) const noexcept;
  ::pasta::Token ExportToken(void) const noexcept;
  ::pasta::Token RBraceToken(void) const noexcept;
  bool HasBraces(void) const noexcept;
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
  ::pasta::Token AssemblyToken(void) const noexcept;
  ::pasta::StringLiteral AssemblyString(void) const noexcept;
  ::pasta::Token RParenToken(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FileScopeAsmDecl)
};

static_assert(sizeof(Decl) == sizeof(FileScopeAsmDecl));

class FriendDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendDecl)
  std::optional<::pasta::NamedDecl> FriendDeclaration(void) const noexcept;
  ::pasta::Token FriendToken(void) const noexcept;
  std::optional<::pasta::Type> FriendType(void) const noexcept;
  uint32_t FriendTypeNumTemplateParameterLists(void) const noexcept;
  // FriendTypeTemplateParameterList: (clang::TemplateParameterList *)
  bool IsUnsupportedFriend(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> FriendTypeTemplateParameterLists(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendDecl));

class FriendTemplateDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendTemplateDecl)
  ::pasta::NamedDecl FriendDeclaration(void) const noexcept;
  ::pasta::Token FriendToken(void) const noexcept;
  ::pasta::Type FriendType(void) const noexcept;
  uint32_t NumTemplateParameters(void) const noexcept;
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendTemplateDecl));

class ImportDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImportDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ImportDecl)
  std::vector<::pasta::Token> IdentifierTokens(void) const noexcept;
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
  std::vector<::pasta::Stmt> ChildrenExpression(void) const noexcept;
  ::pasta::ValueDecl ExtendingDeclaration(void) const noexcept;
  uint32_t ManglingNumber(void) const noexcept;
  // OrCreateValue: (clang::APValue *)
  enum StorageDuration StorageDuration(void) const noexcept;
  ::pasta::Expr TemporaryExpression(void) const noexcept;
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
  ::pasta::Token EndToken(void) const noexcept;
  ::pasta::Token ExternToken(void) const noexcept;
  enum LinkageSpecDeclLanguageIDs Language(void) const noexcept;
  ::pasta::Token RBraceToken(void) const noexcept;
  bool HasBraces(void) const noexcept;
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
  // ExplicitVisibility: (llvm::Optional<clang::Visibility>)
  enum Linkage FormalLinkage(void) const noexcept;
  // Identifier: (clang::IdentifierInfo *)
  // LinkageAndVisibility: (clang::LinkageInfo)
  enum Linkage LinkageInternal(void) const noexcept;
  ::pasta::NamedDecl MostRecentDeclaration(void) const noexcept;
  std::string Name(void) const noexcept;
  std::optional<enum ObjCStringFormatFamily> ObjCFStringFormattingFamily(void) const noexcept;
  std::string QualifiedNameAsString(void) const noexcept;
  ::pasta::NamedDecl UnderlyingDeclaration(void) const noexcept;
  enum Visibility Visibility(void) const noexcept;
  bool HasExternalFormalLinkage(void) const noexcept;
  bool HasLinkage(void) const noexcept;
  bool HasLinkageBeenComputed(void) const noexcept;
  bool IsCXXClassMember(void) const noexcept;
  bool IsCXXInstanceMember(void) const noexcept;
  bool IsExternallyDeclarable(void) const noexcept;
  bool IsExternallyVisible(void) const noexcept;
  bool IsLinkageValid(void) const noexcept;
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
  ::pasta::Token AliasToken(void) const noexcept;
  ::pasta::NamedDecl AliasedNamespace(void) const noexcept;
  ::pasta::NamespaceAliasDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::NamespaceDecl Namespace(void) const noexcept;
  ::pasta::Token NamespaceToken(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token TargetNameToken(void) const noexcept;
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
  ::pasta::NamespaceDecl AnonymousNamespace(void) const noexcept;
  ::pasta::Token BeginToken(void) const noexcept;
  ::pasta::NamespaceDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::NamespaceDecl OriginalNamespace(void) const noexcept;
  ::pasta::Token RBraceToken(void) const noexcept;
  bool IsAnonymousNamespace(void) const noexcept;
  bool IsInline(void) const noexcept;
  bool IsOriginalNamespace(void) const noexcept;
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
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const noexcept;
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
  std::vector<::pasta::ObjCMethodDecl> ClassMethods(void) const noexcept;
  std::vector<::pasta::ObjCPropertyDecl> ClassProperties(void) const noexcept;
  ::pasta::TokenRange AtEndRange(void) const noexcept;
  ::pasta::Token AtStartToken(void) const noexcept;
  // ClassMethod: (clang::ObjCMethodDecl *)
  // InstanceMethod: (clang::ObjCMethodDecl *)
  // InstanceVariableDeclaration: (clang::ObjCIvarDecl *)
  // Method: (clang::ObjCMethodDecl *)
  // Property: (clang::ObjCPropertyDecl *)
  std::vector<::pasta::ObjCMethodDecl> InstanceMethods(void) const noexcept;
  std::vector<::pasta::ObjCPropertyDecl> InstanceProperties(void) const noexcept;
  std::vector<::pasta::ObjCMethodDecl> Methods(void) const noexcept;
  std::vector<::pasta::ObjCPropertyDecl> Properties(void) const noexcept;
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
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const noexcept;
  std::vector<::pasta::ObjCPropertyImplDecl> PropertyImplementations(void) const noexcept;
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
  ::pasta::Token InstanceVariableLBraceToken(void) const noexcept;
  ::pasta::Token InstanceVariableRBraceToken(void) const noexcept;
  std::string Name(void) const noexcept;
  uint32_t NumInstanceVariableInitializers(void) const noexcept;
  std::string_view ObjCRuntimeNameAsString(void) const noexcept;
  ::pasta::ObjCInterfaceDecl SuperClass(void) const noexcept;
  ::pasta::Token SuperClassToken(void) const noexcept;
  bool HasDestructors(void) const noexcept;
  bool HasNonZeroConstructors(void) const noexcept;
  // Initializers: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const noexcept;
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
  std::vector<::pasta::ObjCProtocolDecl> AllReferencedProtocols(void) const noexcept;
  bool DeclaresOrInheritsDesignatedInitializers(void) const noexcept;
  ::pasta::ObjCInterfaceDecl CanonicalDeclaration(void) const noexcept;
  // CategoryClassMethod: (clang::ObjCMethodDecl *)
  // CategoryInstanceMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCCategoryDecl CategoryListRaw(void) const noexcept;
  // CategoryMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCInterfaceDecl Definition(void) const noexcept;
  ::pasta::Token EndOfDefinitionToken(void) const noexcept;
  ::pasta::ObjCImplementationDecl Implementation(void) const noexcept;
  std::string_view ObjCRuntimeNameAsString(void) const noexcept;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  std::optional<::pasta::ObjCInterfaceDecl> SuperClass(void) const noexcept;
  ::pasta::Token SuperClassToken(void) const noexcept;
  std::optional<::pasta::Type> SuperClassTypeInfo(void) const noexcept;
  std::optional<::pasta::ObjCObjectType> SuperClassType(void) const noexcept;
  ::pasta::Type TypeForDeclaration(void) const noexcept;
  // TypeParameterList: (clang::ObjCTypeParamList *)
  // TypeParameterListAsWritten: (clang::ObjCTypeParamList *)
  bool HasDefinition(void) const noexcept;
  bool HasDesignatedInitializers(void) const noexcept;
  bool IsArcWeakrefUnavailable(void) const noexcept;
  // IsDesignatedInitializer: (bool)
  bool IsImplicitInterfaceDeclaration(void) const noexcept;
  ::pasta::ObjCInterfaceDecl IsObjCRequiresPropertyDefinitions(void) const noexcept;
  // IsSuperClassOf: (bool)
  bool IsThisDeclarationADefinition(void) const noexcept;
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const noexcept;
  std::vector<::pasta::ObjCCategoryDecl> KnownCategories(void) const noexcept;
  std::vector<::pasta::ObjCCategoryDecl> KnownExtensions(void) const noexcept;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupMethod: (clang::ObjCMethodDecl *)
  // LookupPrivateMethod: (clang::ObjCMethodDecl *)
  // LookupPropertyAccessor: (clang::ObjCMethodDecl *)
  std::vector<::pasta::Token> ProtocolTokens(void) const noexcept;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const noexcept;
  std::vector<::pasta::ObjCCategoryDecl> VisibleCategories(void) const noexcept;
  std::vector<::pasta::ObjCCategoryDecl> VisibleExtensions(void) const noexcept;
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
  bool DefinedInNSObject(void) const noexcept;
  ::pasta::ObjCPropertyDecl FindPropertyDeclaration(void) const noexcept;
  ::pasta::Token BeginToken(void) const noexcept;
  ::pasta::ObjCMethodDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::ObjCCategoryDecl Category(void) const noexcept;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const noexcept;
  ::pasta::ImplicitParamDecl CommandDeclaration(void) const noexcept;
  ::pasta::Token DeclaratorEndToken(void) const noexcept;
  ::pasta::Token EndToken(void) const noexcept;
  enum ObjCMethodDeclImplementationControl ImplementationControl(void) const noexcept;
  enum ObjCMethodFamily MethodFamily(void) const noexcept;
  uint32_t NumSelectorTokens(void) const noexcept;
  enum DeclObjCDeclQualifier ObjCDeclQualifier(void) const noexcept;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::Type ReturnType(void) const noexcept;
  ::pasta::TokenRange ReturnTypeSourceRange(void) const noexcept;
  // Selector: (clang::Selector)
  // SelectorToken: (clang::SourceLocation)
  ::pasta::Token SelectorStartToken(void) const noexcept;
  ::pasta::ImplicitParamDecl SelfDeclaration(void) const noexcept;
  // SelfType: (clang::QualType)
  bool HasParameterDestroyedInCallee(void) const noexcept;
  bool HasRedeclaration(void) const noexcept;
  bool HasRelatedResultType(void) const noexcept;
  bool HasSkippedBody(void) const noexcept;
  bool IsClassMethod(void) const noexcept;
  bool IsDefined(void) const noexcept;
  bool IsDesignatedInitializerForTheInterface(void) const noexcept;
  bool IsDirectMethod(void) const noexcept;
  bool IsInstanceMethod(void) const noexcept;
  bool IsOptional(void) const noexcept;
  bool IsOverriding(void) const noexcept;
  bool IsPropertyAccessor(void) const noexcept;
  bool IsRedeclaration(void) const noexcept;
  bool IsSynthesizedAccessorStub(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  bool IsThisDeclarationADesignatedInitializer(void) const noexcept;
  bool IsVariadic(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const noexcept;
  std::vector<::pasta::Token> SelectorTokens(void) const noexcept;
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
  ::pasta::Token AtToken(void) const noexcept;
  // DefaultSynthInstanceVariableName: (clang::IdentifierInfo *)
  ::pasta::ObjCMethodDecl GetterMethodDeclaration(void) const noexcept;
  // GetterName: (clang::Selector)
  ::pasta::Token GetterNameToken(void) const noexcept;
  ::pasta::Token LParenToken(void) const noexcept;
  // PropertyAttributes: (clang::ObjCPropertyAttribute::Kind)
  // PropertyAttributesAsWritten: (clang::ObjCPropertyAttribute::Kind)
  enum ObjCPropertyDeclPropertyControl PropertyImplementation(void) const noexcept;
  ::pasta::ObjCIvarDecl PropertyInstanceVariableDeclaration(void) const noexcept;
  enum ObjCPropertyQueryKind QueryKind(void) const noexcept;
  enum ObjCPropertyDeclSetterKind SetterKind(void) const noexcept;
  ::pasta::ObjCMethodDecl SetterMethodDeclaration(void) const noexcept;
  // SetterName: (clang::Selector)
  ::pasta::Token SetterNameToken(void) const noexcept;
  ::pasta::Type Type(void) const noexcept;
  // UsageType: (clang::QualType)
  bool IsAtomic(void) const noexcept;
  bool IsClassProperty(void) const noexcept;
  bool IsDirectProperty(void) const noexcept;
  bool IsInstanceProperty(void) const noexcept;
  bool IsOptional(void) const noexcept;
  bool IsReadOnly(void) const noexcept;
  bool IsRetaining(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCPropertyDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyDecl));

class ObjCPropertyImplDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyImplDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ObjCPropertyImplDecl)
  ::pasta::Token BeginToken(void) const noexcept;
  ::pasta::Expr GetterCXXConstructor(void) const noexcept;
  ::pasta::ObjCMethodDecl GetterMethodDeclaration(void) const noexcept;
  ::pasta::ObjCPropertyDecl PropertyDeclaration(void) const noexcept;
  enum ObjCPropertyImplDeclKind PropertyImplementation(void) const noexcept;
  ::pasta::ObjCIvarDecl PropertyInstanceVariableDeclaration(void) const noexcept;
  ::pasta::Token PropertyInstanceVariableDeclarationToken(void) const noexcept;
  ::pasta::Expr SetterCXXAssignment(void) const noexcept;
  ::pasta::ObjCMethodDecl SetterMethodDeclaration(void) const noexcept;
  bool IsInstanceVariableNameSpecified(void) const noexcept;
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
  ::pasta::ObjCProtocolDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::ObjCProtocolDecl Definition(void) const noexcept;
  std::string_view ObjCRuntimeNameAsString(void) const noexcept;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  bool HasDefinition(void) const noexcept;
  bool IsNonRuntimeProtocol(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupMethod: (clang::ObjCMethodDecl *)
  std::vector<::pasta::Token> ProtocolTokens(void) const noexcept;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ObjCProtocolDecl)
};

static_assert(sizeof(Decl) == sizeof(ObjCProtocolDecl));

class PragmaCommentDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaCommentDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, PragmaCommentDecl)
  std::string_view Argument(void) const noexcept;
  enum PragmaMSCommentKind CommentKind(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(PragmaCommentDecl)
};

static_assert(sizeof(Decl) == sizeof(PragmaCommentDecl));

class PragmaDetectMismatchDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaDetectMismatchDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, PragmaDetectMismatchDecl)
  std::string_view Name(void) const noexcept;
  std::string_view Value(void) const noexcept;
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
  ::pasta::Expr AssertExpression(void) const noexcept;
  ::pasta::StringLiteral Message(void) const noexcept;
  ::pasta::Token RParenToken(void) const noexcept;
  bool IsFailed(void) const noexcept;
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
  ::pasta::TemplateParameterList TemplateParameters(void) const noexcept;
  ::pasta::NamedDecl TemplatedDeclaration(void) const noexcept;
  bool HasAssociatedConstraints(void) const noexcept;
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
  bool DefaultArgumentWasInherited(void) const noexcept;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::TemplateTemplateParmDecl, clang::TemplateArgumentLoc *> &)
  // DefaultArgument: (const clang::TemplateArgumentLoc &)
  ::pasta::Token DefaultArgumentToken(void) const noexcept;
  // ExpansionTemplateParameters: (clang::TemplateParameterList *)
  uint32_t NumExpansionTemplateParameters(void) const noexcept;
  bool HasDefaultArgument(void) const noexcept;
  bool IsExpandedParameterPack(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TemplateTemplateParmDecl)
};

static_assert(sizeof(Decl) == sizeof(TemplateTemplateParmDecl));

class TranslationUnitDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TranslationUnitDecl)
  PASTA_DECLARE_BASE_OPERATORS(DeclContext, TranslationUnitDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, TranslationUnitDecl)
  // ASTContext: (clang::ASTContext &)
  ::pasta::NamespaceDecl AnonymousNamespace(void) const noexcept;
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
  ::pasta::Token BeginToken(void) const noexcept;
  std::optional<::pasta::Type> TypeForDeclaration(void) const noexcept;
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
  std::optional<::pasta::TagDecl> AnonymousDeclarationWithTypedefName(void) const noexcept;
  ::pasta::TypedefNameDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsModed(void) const noexcept;
  bool IsTransparentTag(void) const noexcept;
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
  ::pasta::UnresolvedUsingTypenameDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::Token EllipsisToken(void) const noexcept;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token TypenameToken(void) const noexcept;
  ::pasta::Token UsingToken(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
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
  ::pasta::DeclContext CommonAncestor(void) const noexcept;
  ::pasta::Token IdentifierToken(void) const noexcept;
  ::pasta::Token NamespaceKeyToken(void) const noexcept;
  ::pasta::NamespaceDecl NominatedNamespace(void) const noexcept;
  ::pasta::NamedDecl NominatedNamespaceAsWritten(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const noexcept;
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
  std::vector<::pasta::NamedDecl> Expansions(void) const noexcept;
  ::pasta::UsingPackDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::NamedDecl InstantiatedFromUsingDeclaration(void) const noexcept;
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
  ::pasta::UsingShadowDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::BaseUsingDecl Introducer(void) const noexcept;
  std::optional<::pasta::UsingShadowDecl> NextUsingShadowDeclaration(void) const noexcept;
  ::pasta::NamedDecl TargetDeclaration(void) const noexcept;
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
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
  ::pasta::Type Type(void) const noexcept;
  bool IsWeak(void) const noexcept;
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
  ::pasta::Token AccessSpecifierToken(void) const noexcept;
  ::pasta::Token ColonToken(void) const noexcept;
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
  std::vector<::pasta::UsingShadowDecl> Shadows(void) const noexcept;
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
  ::pasta::Expr Binding(void) const noexcept;
  ::pasta::ValueDecl DecomposedDeclaration(void) const noexcept;
  ::pasta::VarDecl HoldingVariable(void) const noexcept;
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
  bool BlockMissingReturnType(void) const noexcept;
  bool CanAvoidCopyToHeap(void) const noexcept;
  // Captures: (llvm::ArrayRef<clang::BlockDecl::Capture>)
  bool CapturesCXXThis(void) const noexcept;
  // CapturesVariable: (bool)
  bool DoesNotEscape(void) const noexcept;
  std::optional<::pasta::Decl> BlockManglingContextDeclaration(void) const noexcept;
  uint32_t BlockManglingNumber(void) const noexcept;
  ::pasta::Token CaretToken(void) const noexcept;
  ::pasta::CompoundStmt CompoundBody(void) const noexcept;
  uint32_t NumCaptures(void) const noexcept;
  uint32_t NumParameters(void) const noexcept;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::Type SignatureAsWritten(void) const noexcept;
  bool HasCaptures(void) const noexcept;
  bool IsConversionFromLambda(void) const noexcept;
  bool IsVariadic(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  ::pasta::ImplicitParamDecl ContextParameter(void) const noexcept;
  uint32_t ContextParameterPosition(void) const noexcept;
  uint32_t NumParameters(void) const noexcept;
  // Parameter: (clang::ImplicitParamDecl *)
  bool IsNothrow(void) const noexcept;
  std::vector<::pasta::ImplicitParamDecl> Parameters(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(CapturedDecl)
};

static_assert(sizeof(Decl) == sizeof(CapturedDecl));

class ClassScopeFunctionSpecializationDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassScopeFunctionSpecializationDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
  ::pasta::CXXMethodDecl Specialization(void) const noexcept;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  bool HasExplicitTemplateArguments(void) const noexcept;
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
  ::pasta::ConceptDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::Expr ConstraintExpression(void) const noexcept;
  bool IsTypeConcept(void) const noexcept;
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
  bool ConstructsVirtualBase(void) const noexcept;
  ::pasta::CXXRecordDecl ConstructedBaseClass(void) const noexcept;
  std::optional<::pasta::ConstructorUsingShadowDecl> ConstructedBaseClassShadowDeclaration(void) const noexcept;
  ::pasta::UsingDecl Introducer(void) const noexcept;
  ::pasta::CXXRecordDecl NominatedBaseClass(void) const noexcept;
  std::optional<::pasta::ConstructorUsingShadowDecl> NominatedBaseClassShadowDeclaration(void) const noexcept;
  ::pasta::CXXRecordDecl Parent(void) const noexcept;
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
  ::pasta::Token BeginToken(void) const noexcept;
  ::pasta::Token FirstInnerToken(void) const noexcept;
  uint32_t NumTemplateParameterLists(void) const noexcept;
  ::pasta::Token FirstOuterToken(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::optional<::pasta::Expr> TrailingRequiresClause(void) const noexcept;
  ::pasta::Token TypeSpecEndToken(void) const noexcept;
  ::pasta::Token TypeSpecStartToken(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::EnumConstantDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::Expr> InitializerExpression(void) const noexcept;
  llvm::APSInt InitializerValue(void) const noexcept;
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
  std::optional<::pasta::Expr> BitWidth(void) const noexcept;
  uint32_t BitWidthValue(void) const noexcept;
  ::pasta::FieldDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::VariableArrayType> CapturedVLAType(void) const noexcept;
  uint32_t FieldIndex(void) const noexcept;
  enum InClassInitStyle InClassInitializerStyle(void) const noexcept;
  std::optional<::pasta::Expr> InClassInitializer(void) const noexcept;
  ::pasta::RecordDecl Parent(void) const noexcept;
  bool HasCapturedVLAType(void) const noexcept;
  bool HasInClassInitializer(void) const noexcept;
  bool IsAnonymousStructOrUnion(void) const noexcept;
  bool IsBitField(void) const noexcept;
  bool IsMutable(void) const noexcept;
  bool IsUnnamedBitfield(void) const noexcept;
  bool IsZeroLengthBitField(void) const noexcept;
  bool IsZeroSize(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  bool UsesFPIntrin(void) const noexcept;
  std::optional<bool> DoesDeclarationForceExternallyVisibleDefinition(void) const noexcept;
  bool DoesThisDeclarationHaveABody(void) const noexcept;
  uint32_t BuiltinID(void) const noexcept;
  ::pasta::Type CallResultType(void) const noexcept;
  ::pasta::FunctionDecl CanonicalDeclaration(void) const noexcept;
  enum ConstexprSpecKind ConstexprKind(void) const noexcept;
  ::pasta::Type DeclaredReturnType(void) const noexcept;
  // DefaultedFunctionInfo: (clang::FunctionDecl::DefaultedFunctionInfo *)
  std::optional<::pasta::FunctionDecl> Definition(void) const noexcept;
  // DependentSpecializationInfo: (clang::DependentFunctionTemplateSpecializationInfo *)
  std::optional<::pasta::FunctionTemplateDecl> DescribedFunctionTemplate(void) const noexcept;
  ::pasta::Token EllipsisToken(void) const noexcept;
  ::pasta::TokenRange ExceptionSpecSourceRange(void) const noexcept;
  enum ExceptionSpecificationType ExceptionSpecType(void) const noexcept;
  // FunctionTypeToken: (clang::FunctionTypeLoc)
  std::optional<::pasta::FunctionDecl> InstantiatedFromMemberFunction(void) const noexcept;
  enum LanguageLinkage LanguageLinkage(void) const noexcept;
  // LiteralIdentifier: (const clang::IdentifierInfo *)
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  uint32_t MemoryFunctionKind(void) const noexcept;
  uint32_t MinRequiredArguments(void) const noexcept;
  enum MultiVersionKind MultiVersionKind(void) const noexcept;
  // NameInfo: (clang::DeclarationNameInfo)
  uint32_t NumParameters(void) const noexcept;
  std::optional<uint32_t> ODRHash(void) const noexcept;
  enum OverloadedOperatorKind OverloadedOperator(void) const noexcept;
  // ParameterDeclaration: (const clang::ParmVarDecl *)
  ::pasta::TokenRange ParametersSourceRange(void) const noexcept;
  ::pasta::Token PointOfInstantiation(void) const noexcept;
  std::optional<::pasta::FunctionTemplateDecl> PrimaryTemplate(void) const noexcept;
  ::pasta::Type ReturnType(void) const noexcept;
  ::pasta::TokenRange ReturnTypeSourceRange(void) const noexcept;
  enum StorageClass StorageClass(void) const noexcept;
  std::optional<::pasta::FunctionDecl> TemplateInstantiationPattern(void) const noexcept;
  // TemplateSpecializationArguments: (const clang::TemplateArgumentList *)
  // TemplateSpecializationArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateSpecializationInfo: (clang::FunctionTemplateSpecializationInfo *)
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const noexcept;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const noexcept;
  enum FunctionDeclTemplatedKind TemplatedKind(void) const noexcept;
  bool HasImplicitReturnZero(void) const noexcept;
  bool HasInheritedPrototype(void) const noexcept;
  bool HasOneParameterOrDefaultArguments(void) const noexcept;
  bool HasPrototype(void) const noexcept;
  bool HasSkippedBody(void) const noexcept;
  bool HasTrivialBody(void) const noexcept;
  bool HasWrittenPrototype(void) const noexcept;
  bool InstantiationIsPending(void) const noexcept;
  bool IsCPUDispatchMultiVersion(void) const noexcept;
  bool IsCPUSpecificMultiVersion(void) const noexcept;
  bool IsConsteval(void) const noexcept;
  bool IsConstexpr(void) const noexcept;
  bool IsConstexprSpecified(void) const noexcept;
  bool IsDefaulted(void) const noexcept;
  bool IsDeleted(void) const noexcept;
  bool IsDeletedAsWritten(void) const noexcept;
  bool IsDestroyingOperatorDelete(void) const noexcept;
  bool IsExplicitlyDefaulted(void) const noexcept;
  bool IsExternC(void) const noexcept;
  bool IsFunctionTemplateSpecialization(void) const noexcept;
  bool IsGlobal(void) const noexcept;
  bool IsImplicitlyInstantiable(void) const noexcept;
  bool IsInExternCContext(void) const noexcept;
  bool IsInExternCXXContext(void) const noexcept;
  bool IsInlineBuiltinDeclaration(void) const noexcept;
  std::optional<bool> IsInlineDefinitionExternallyVisible(void) const noexcept;
  bool IsInlineSpecified(void) const noexcept;
  bool IsInlined(void) const noexcept;
  bool IsLateTemplateParsed(void) const noexcept;
  std::optional<bool> IsMSExternInline(void) const noexcept;
  bool IsMSVCRTEntryPoint(void) const noexcept;
  bool IsMain(void) const noexcept;
  bool IsMultiVersion(void) const noexcept;
  bool IsNoReturn(void) const noexcept;
  bool IsOverloadedOperator(void) const noexcept;
  bool IsPure(void) const noexcept;
  bool IsReplaceableGlobalAllocationFunction(void) const noexcept;
  std::optional<bool> IsReservedGlobalPlacementOperator(void) const noexcept;
  bool IsStatic(void) const noexcept;
  bool IsTargetClonesMultiVersion(void) const noexcept;
  bool IsTargetMultiVersion(void) const noexcept;
  bool IsTemplateInstantiation(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  bool IsThisDeclarationInstantiatedFromAFriendDefinition(void) const noexcept;
  bool IsTrivial(void) const noexcept;
  bool IsTrivialForCall(void) const noexcept;
  bool IsUserProvided(void) const noexcept;
  bool IsVariadic(void) const noexcept;
  bool IsVirtualAsWritten(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const noexcept;
  bool UsesSEHTry(void) const noexcept;
  bool WillHaveBody(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
  std::optional<::pasta::Stmt> Body(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FunctionDecl)
};

static_assert(sizeof(Decl) == sizeof(FunctionDecl));

class IndirectFieldDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, IndirectFieldDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, IndirectFieldDecl)
  std::vector<::pasta::NamedDecl> Chain(void) const noexcept;
  std::optional<::pasta::FieldDecl> AnonymousField(void) const noexcept;
  ::pasta::IndirectFieldDecl CanonicalDeclaration(void) const noexcept;
  uint32_t ChainingSize(void) const noexcept;
  std::optional<::pasta::VarDecl> VariableDeclaration(void) const noexcept;
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
  std::string_view MSAssemblyLabel(void) const noexcept;
  ::pasta::LabelStmt Statement(void) const noexcept;
  bool IsGnuLocal(void) const noexcept;
  bool IsMSAssemblyLabel(void) const noexcept;
  bool IsResolvedMSAssemblyLabel(void) const noexcept;
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
  bool HasGetter(void) const noexcept;
  bool HasSetter(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  bool DefaultArgumentWasInherited(void) const noexcept;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::NonTypeTemplateParmDecl, clang::Expr *> &)
  std::optional<::pasta::Expr> DefaultArgument(void) const noexcept;
  ::pasta::Token DefaultArgumentToken(void) const noexcept;
  // ExpansionType: (clang::QualType)
  // ExpansionType: (clang::TypeSourceInfo *)
  std::optional<uint32_t> NumExpansionTypes(void) const noexcept;
  std::optional<::pasta::Expr> PlaceholderTypeConstraint(void) const noexcept;
  bool HasDefaultArgument(void) const noexcept;
  bool HasPlaceholderTypeConstraint(void) const noexcept;
  bool IsExpandedParameterPack(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::Type> ExpansionTypes(void) const noexcept;
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
  std::vector<::pasta::Expr> Varlists(void) const noexcept;
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
  ::pasta::Expr MapperVariableReference(void) const noexcept;
  ::pasta::OMPDeclareMapperDecl PrevDeclarationInScope(void) const noexcept;
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
  ::pasta::Expr Combiner(void) const noexcept;
  ::pasta::Expr CombinerIn(void) const noexcept;
  ::pasta::Expr CombinerOut(void) const noexcept;
  ::pasta::Expr InitializerOriginal(void) const noexcept;
  ::pasta::Expr InitializerPrivate(void) const noexcept;
  ::pasta::Expr Initializer(void) const noexcept;
  enum OMPDeclareReductionDeclInitKind InitializerKind(void) const noexcept;
  ::pasta::OMPDeclareReductionDecl PrevDeclarationInScope(void) const noexcept;
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
  std::vector<::pasta::Expr> Varlists(void) const noexcept;
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
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  bool IsClassExtension(void) const noexcept;
  ::pasta::Token CategoryNameToken(void) const noexcept;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const noexcept;
  ::pasta::ObjCCategoryImplDecl Implementation(void) const noexcept;
  ::pasta::Token InstanceVariableLBraceToken(void) const noexcept;
  ::pasta::Token InstanceVariableRBraceToken(void) const noexcept;
  ::pasta::ObjCCategoryDecl NextClassCategory(void) const noexcept;
  ::pasta::ObjCCategoryDecl NextClassCategoryRaw(void) const noexcept;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  // TypeParameterList: (clang::ObjCTypeParamList *)
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const noexcept;
  std::vector<::pasta::Token> ProtocolTokens(void) const noexcept;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const noexcept;
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
  ::pasta::ObjCCategoryDecl CategoryDeclaration(void) const noexcept;
  ::pasta::Token CategoryNameToken(void) const noexcept;
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
  enum ObjCIvarDeclAccessControl AccessControl(void) const noexcept;
  enum ObjCIvarDeclAccessControl CanonicalAccessControl(void) const noexcept;
  ::pasta::ObjCIvarDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::ObjCInterfaceDecl ContainingInterface(void) const noexcept;
  ::pasta::ObjCIvarDecl NextInstanceVariable(void) const noexcept;
  bool Synthesize(void) const noexcept;
  // UsageType: (clang::QualType)
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::Token ColonToken(void) const noexcept;
  uint32_t Index(void) const noexcept;
  enum ObjCTypeParamVariance Variance(void) const noexcept;
  ::pasta::Token VarianceToken(void) const noexcept;
  bool HasExplicitBound(void) const noexcept;
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
  ::pasta::RedeclarableTemplateDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::RedeclarableTemplateDecl InstantiatedFromMemberTemplate(void) const noexcept;
  bool IsMemberSpecialization(void) const noexcept;
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
  ::pasta::TokenRange BraceRange(void) const noexcept;
  ::pasta::TagDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::TagDecl> Definition(void) const noexcept;
  ::pasta::Token FirstInnerToken(void) const noexcept;
  std::string_view KindName(void) const noexcept;
  uint32_t NumTemplateParameterLists(void) const noexcept;
  ::pasta::Token FirstOuterToken(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  enum TagTypeKind TagKind(void) const noexcept;
  // TemplateParameterList: (clang::TemplateParameterList *)
  std::optional<::pasta::TypedefNameDecl> TypedefNameForAnonymousDeclaration(void) const noexcept;
  bool HasNameForLinkage(void) const noexcept;
  bool IsBeingDefined(void) const noexcept;
  bool IsClass(void) const noexcept;
  bool IsCompleteDefinition(void) const noexcept;
  bool IsCompleteDefinitionRequired(void) const noexcept;
  bool IsDependentType(void) const noexcept;
  bool IsEmbeddedInDeclarator(void) const noexcept;
  bool IsEnum(void) const noexcept;
  bool IsFreeStanding(void) const noexcept;
  bool IsInterface(void) const noexcept;
  bool IsStruct(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  bool IsUnion(void) const noexcept;
  bool MayHaveOutOfDateDefinition(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::TemplateParamObjectDecl CanonicalDeclaration(void) const noexcept;
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
  bool DefaultArgumentWasInherited(void) const noexcept;
  // DefaultArgumentStorage: (const clang::DefaultArgStorage<clang::TemplateTypeParmDecl, clang::TypeSourceInfo *> &)
  std::optional<::pasta::Type> DefaultArgument(void) const noexcept;
  std::optional<::pasta::Type> DefaultArgumentInfo(void) const noexcept;
  ::pasta::Token DefaultArgumentToken(void) const noexcept;
  uint32_t Depth(void) const noexcept;
  uint32_t Index(void) const noexcept;
  uint32_t NumExpansionParameters(void) const noexcept;
  // TypeConstraint: (const clang::TypeConstraint *)
  bool HasDefaultArgument(void) const noexcept;
  bool HasTypeConstraint(void) const noexcept;
  bool IsExpandedParameterPack(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
  bool WasDeclaredWithTypename(void) const noexcept;
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
  std::optional<::pasta::TypeAliasTemplateDecl> DescribedAliasTemplate(void) const noexcept;
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
  ::pasta::TypeAliasTemplateDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::TypeAliasTemplateDecl> InstantiatedFromMemberTemplate(void) const noexcept;
  std::optional<::pasta::TypeAliasTemplateDecl> PreviousDeclaration(void) const noexcept;
  ::pasta::TypeAliasDecl TemplatedDeclaration(void) const noexcept;
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

class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
  ::pasta::UnresolvedUsingValueDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::Token EllipsisToken(void) const noexcept;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const noexcept;
  bool IsAccessDeclaration(void) const noexcept;
  bool IsPackExpansion(void) const noexcept;
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
  ::pasta::UsingDecl CanonicalDeclaration(void) const noexcept;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const noexcept;
  bool HasTypename(void) const noexcept;
  bool IsAccessDeclaration(void) const noexcept;
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
  ::pasta::UsingEnumDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::EnumDecl EnumDeclaration(void) const noexcept;
  ::pasta::Token EnumToken(void) const noexcept;
  ::pasta::Token UsingToken(void) const noexcept;
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
  std::optional<::pasta::VarDecl> ActingDefinition(void) const noexcept;
  ::pasta::VarDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::VarTemplateDecl> DescribedVariableTemplate(void) const noexcept;
  // EvaluatedStatement: (clang::EvaluatedStmt *)
  // EvaluatedValue: (clang::APValue *)
  std::optional<::pasta::Expr> Initializer(void) const noexcept;
  enum VarDeclInitializationStyle InitializerStyle(void) const noexcept;
  std::optional<::pasta::VarDecl> InitializingDeclaration(void) const noexcept;
  std::optional<::pasta::VarDecl> InstantiatedFromStaticDataMember(void) const noexcept;
  enum LanguageLinkage LanguageLinkage(void) const noexcept;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::Token PointOfInstantiation(void) const noexcept;
  enum StorageClass StorageClass(void) const noexcept;
  enum StorageDuration StorageDuration(void) const noexcept;
  enum VarDeclTLSKind TLSKind(void) const noexcept;
  enum ThreadStorageClassSpecifier TSCSpec(void) const noexcept;
  std::optional<::pasta::VarDecl> TemplateInstantiationPattern(void) const noexcept;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const noexcept;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const noexcept;
  bool HasConstantInitialization(void) const noexcept;
  bool HasDependentAlignment(void) const noexcept;
  bool HasExternalStorage(void) const noexcept;
  bool HasGlobalStorage(void) const noexcept;
  std::optional<bool> HasICEInitializer(void) const noexcept;
  bool HasInitializer(void) const noexcept;
  bool HasLocalStorage(void) const noexcept;
  bool IsARCPseudoStrong(void) const noexcept;
  bool IsCXXForRangeDeclaration(void) const noexcept;
  bool IsConstexpr(void) const noexcept;
  bool IsDirectInitializer(void) const noexcept;
  bool IsEscapingByref(void) const noexcept;
  bool IsExceptionVariable(void) const noexcept;
  bool IsExternC(void) const noexcept;
  bool IsFileVariableDeclaration(void) const noexcept;
  bool IsFunctionOrMethodVariableDeclaration(void) const noexcept;
  bool IsInExternCContext(void) const noexcept;
  bool IsInExternCXXContext(void) const noexcept;
  bool IsInitializerCapture(void) const noexcept;
  bool IsInline(void) const noexcept;
  bool IsInlineSpecified(void) const noexcept;
  bool IsKnownToBeDefined(void) const noexcept;
  bool IsLocalVariableDeclaration(void) const noexcept;
  bool IsLocalVariableDeclarationOrParm(void) const noexcept;
  bool IsNRVOVariable(void) const noexcept;
  bool IsNoDestroy(void) const noexcept;
  bool IsNonEscapingByref(void) const noexcept;
  bool IsObjCForDeclaration(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
  bool IsPreviousDeclarationInSameBlockScope(void) const noexcept;
  bool IsStaticDataMember(void) const noexcept;
  bool IsStaticLocal(void) const noexcept;
  bool IsThisDeclarationADemotedDefinition(void) const noexcept;
  bool IsUsableInConstantExpressions(void) const noexcept;
  bool MightBeUsableInConstantExpressions(void) const noexcept;
  enum QualTypeDestructionKind NeedsDestruction(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::VarTemplateDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::VarTemplateDecl InstantiatedFromMemberTemplate(void) const noexcept;
  ::pasta::VarTemplateDecl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::VarTemplateDecl> PreviousDeclaration(void) const noexcept;
  ::pasta::VarDecl TemplatedDeclaration(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  std::vector<::pasta::VarTemplateSpecializationDecl> Specializations(void) const noexcept;
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
  ::pasta::Token ExternToken(void) const noexcept;
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> InstantiatedFrom(void) const noexcept;
  ::pasta::Token PointOfInstantiation(void) const noexcept;
  enum TemplateSpecializationKind SpecializationKind(void) const noexcept;
  ::pasta::VarTemplateDecl SpecializedTemplate(void) const noexcept;
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> SpecializedTemplateOrPartial(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const noexcept;
  // TemplateArgumentsInfo: (const clang::TemplateArgumentListInfo &)
  std::vector<::pasta::TemplateArgument> TemplateInstantiationArguments(void) const noexcept;
  ::pasta::Token TemplateKeywordToken(void) const noexcept;
  ::pasta::Type TypeAsWritten(void) const noexcept;
  bool IsClassScopeExplicitSpecialization(void) const noexcept;
  bool IsExplicitInstantiationOrSpecialization(void) const noexcept;
  bool IsExplicitSpecialization(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::CXXConstructorDecl CorrespondingConstructor(void) const noexcept;
  ::pasta::TemplateDecl DeducedTemplate(void) const noexcept;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsCopyDeductionCandidate(void) const noexcept;
  bool IsExplicit(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  ::pasta::CXXMethodDecl CanonicalDeclaration(void) const noexcept;
  // CorrespondingMethodDeclaredInClass: (const clang::CXXMethodDecl *)
  // CorrespondingMethodInClass: (const clang::CXXMethodDecl *)
  // DevirtualizedMethod: (const clang::CXXMethodDecl *)
  // MethodQualifiers: (clang::Qualifiers)
  ::pasta::CXXMethodDecl MostRecentDeclaration(void) const noexcept;
  ::pasta::CXXRecordDecl Parent(void) const noexcept;
  enum RefQualifierKind ReferenceQualifier(void) const noexcept;
  std::optional<::pasta::Type> ThisObjectType(void) const noexcept;
  std::optional<::pasta::Type> ThisType(void) const noexcept;
  bool HasInlineBody(void) const noexcept;
  bool IsConst(void) const noexcept;
  bool IsCopyAssignmentOperator(void) const noexcept;
  bool IsInstance(void) const noexcept;
  bool IsLambdaStaticInvoker(void) const noexcept;
  bool IsMoveAssignmentOperator(void) const noexcept;
  bool IsStatic(void) const noexcept;
  // IsUsualDeallocationFunction: (bool)
  bool IsVirtual(void) const noexcept;
  bool IsVolatile(void) const noexcept;
  std::vector<::pasta::CXXMethodDecl> OverriddenMethods(void) const noexcept;
  uint32_t SizeOverriddenMethods(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  ::pasta::ClassTemplateDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::ClassTemplateDecl InstantiatedFromMemberTemplate(void) const noexcept;
  ::pasta::ClassTemplateDecl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::ClassTemplateDecl> PreviousDeclaration(void) const noexcept;
  ::pasta::CXXRecordDecl TemplatedDeclaration(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  std::vector<::pasta::ClassTemplateSpecializationDecl> Specializations(void) const noexcept;
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
  std::vector<::pasta::BindingDecl> Bindings(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  std::vector<::pasta::EnumConstantDecl> Enumerators(void) const noexcept;
  ::pasta::EnumDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::EnumDecl Definition(void) const noexcept;
  std::optional<::pasta::EnumDecl> InstantiatedFromMemberEnum(void) const noexcept;
  std::optional<::pasta::Type> IntegerType(void) const noexcept;
  ::pasta::TokenRange IntegerTypeRange(void) const noexcept;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::EnumDecl MostRecentDeclaration(void) const noexcept;
  uint32_t NumNegativeBits(void) const noexcept;
  uint32_t NumPositiveBits(void) const noexcept;
  std::optional<uint32_t> ODRHash(void) const noexcept;
  std::optional<::pasta::EnumDecl> PreviousDeclaration(void) const noexcept;
  ::pasta::Type PromotionType(void) const noexcept;
  std::optional<::pasta::EnumDecl> TemplateInstantiationPattern(void) const noexcept;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const noexcept;
  bool IsClosed(void) const noexcept;
  bool IsClosedFlag(void) const noexcept;
  bool IsClosedNonFlag(void) const noexcept;
  bool IsComplete(void) const noexcept;
  bool IsFixed(void) const noexcept;
  bool IsScoped(void) const noexcept;
  bool IsScopedUsingClassTag(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::FunctionTemplateDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::FunctionTemplateDecl InstantiatedFromMemberTemplate(void) const noexcept;
  ::pasta::FunctionTemplateDecl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::FunctionTemplateDecl> PreviousDeclaration(void) const noexcept;
  ::pasta::FunctionDecl TemplatedDeclaration(void) const noexcept;
  bool IsAbbreviated(void) const noexcept;
  bool IsThisDeclarationADefinition(void) const noexcept;
  std::vector<::pasta::FunctionDecl> Specializations(void) const noexcept;
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
  enum ImplicitParamDeclImplicitParamKind ParameterKind(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  std::optional<::pasta::Expr> DefaultArgument(void) const noexcept;
  ::pasta::TokenRange DefaultArgumentRange(void) const noexcept;
  uint32_t FunctionScopeDepth(void) const noexcept;
  uint32_t FunctionScopeIndex(void) const noexcept;
  enum DeclObjCDeclQualifier ObjCDeclQualifier(void) const noexcept;
  ::pasta::Type OriginalType(void) const noexcept;
  std::optional<::pasta::Expr> UninstantiatedDefaultArgument(void) const noexcept;
  bool HasDefaultArgument(void) const noexcept;
  bool HasInheritedDefaultArgument(void) const noexcept;
  bool HasUninstantiatedDefaultArgument(void) const noexcept;
  bool HasUnparsedDefaultArgument(void) const noexcept;
  bool IsDestroyedInCallee(void) const noexcept;
  bool IsKNRPromoted(void) const noexcept;
  bool IsObjCMethodParameter(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  bool CanPassInRegisters(void) const noexcept;
  std::vector<::pasta::FieldDecl> Fields(void) const noexcept;
  std::optional<::pasta::FieldDecl> FirstNamedDataMember(void) const noexcept;
  enum RecordDeclArgPassingKind ArgumentPassingRestrictions(void) const noexcept;
  std::optional<::pasta::RecordDecl> Definition(void) const noexcept;
  ::pasta::RecordDecl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::RecordDecl> PreviousDeclaration(void) const noexcept;
  bool HasFlexibleArrayMember(void) const noexcept;
  bool HasLoadedFieldsFromExternalStorage(void) const noexcept;
  bool HasNonTrivialToPrimitiveCopyCUnion(void) const noexcept;
  bool HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const noexcept;
  bool HasNonTrivialToPrimitiveDestructCUnion(void) const noexcept;
  bool HasObjectMember(void) const noexcept;
  bool HasVolatileMember(void) const noexcept;
  bool IsAnonymousStructOrUnion(void) const noexcept;
  bool IsCapturedRecord(void) const noexcept;
  bool IsInjectedClassName(void) const noexcept;
  bool IsLambda(void) const noexcept;
  bool IsMsStruct(void) const noexcept;
  bool IsNonTrivialToPrimitiveCopy(void) const noexcept;
  bool IsNonTrivialToPrimitiveDefaultInitialize(void) const noexcept;
  bool IsNonTrivialToPrimitiveDestroy(void) const noexcept;
  bool IsOrContainsUnion(void) const noexcept;
  bool IsParameterDestroyedInCallee(void) const noexcept;
  bool MayInsertExtraPadding(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::VarTemplatePartialSpecializationDecl InstantiatedFromMember(void) const noexcept;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  ::pasta::TemplateParameterList TemplateParameters(void) const noexcept;
  bool HasAssociatedConstraints(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::CXXConstructorDecl CanonicalDeclaration(void) const noexcept;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  // InheritedConstructor: (clang::InheritedConstructor)
  uint32_t NumConstructorInitializers(void) const noexcept;
  std::optional<::pasta::CXXConstructorDecl> TargetConstructor(void) const noexcept;
  // Initializers: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  bool IsConvertingConstructor(bool) const noexcept;
  bool IsDefaultConstructor(void) const noexcept;
  bool IsDelegatingConstructor(void) const noexcept;
  bool IsExplicit(void) const noexcept;
  bool IsInheritingConstructor(void) const noexcept;
  bool IsSpecializationCopyingObject(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  ::pasta::CXXConversionDecl CanonicalDeclaration(void) const noexcept;
  ::pasta::Type ConversionType(void) const noexcept;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsExplicit(void) const noexcept;
  bool IsLambdaToBlockPointerConversion(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  ::pasta::CXXDestructorDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::FunctionDecl> OperatorDelete(void) const noexcept;
  std::optional<::pasta::Expr> OperatorDeleteThisArgument(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
  std::vector<::pasta::ParmVarDecl> ParameterDeclarations(void) const noexcept;
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
  std::optional<bool> AllowConstDefaultInitializer(void) const noexcept;
  std::optional<std::vector<::pasta::CXXBaseSpecifier>> Bases(void) const noexcept;
  std::optional<enum MSInheritanceModel> CalculateInheritanceModel(void) const noexcept;
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  std::vector<::pasta::CXXConstructorDecl> Constructors(void) const noexcept;
  std::optional<bool> DefaultedCopyConstructorIsDeleted(void) const noexcept;
  std::optional<bool> DefaultedDefaultConstructorIsConstexpr(void) const noexcept;
  std::optional<bool> DefaultedDestructorIsConstexpr(void) const noexcept;
  std::optional<bool> DefaultedDestructorIsDeleted(void) const noexcept;
  std::optional<bool> DefaultedMoveConstructorIsDeleted(void) const noexcept;
  // ForallBases: (bool)
  std::optional<std::vector<::pasta::FriendDecl>> Friends(void) const noexcept;
  ::pasta::CXXRecordDecl CanonicalDeclaration(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> Definition(void) const noexcept;
  std::optional<::pasta::FunctionTemplateDecl> DependentLambdaCallOperator(void) const noexcept;
  std::optional<::pasta::ClassTemplateDecl> DescribedClassTemplate(void) const noexcept;
  std::optional<::pasta::CXXDestructorDecl> Destructor(void) const noexcept;
  uint32_t DeviceLambdaManglingNumber(void) const noexcept;
  std::optional<::pasta::TemplateParameterList> GenericLambdaTemplateParameterList(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> InstantiatedFromMemberClass(void) const noexcept;
  std::optional<::pasta::CXXMethodDecl> LambdaCallOperator(void) const noexcept;
  std::optional<enum LambdaCaptureDefault> LambdaCaptureDefault(void) const noexcept;
  std::optional<::pasta::Decl> LambdaContextDeclaration(void) const noexcept;
  std::optional<std::vector<::pasta::NamedDecl>> LambdaExplicitTemplateParameters(void) const noexcept;
  std::optional<uint32_t> LambdaManglingNumber(void) const noexcept;
  std::optional<::pasta::Type> LambdaType(void) const noexcept;
  std::optional<enum MSInheritanceModel> MSInheritanceModel(void) const noexcept;
  enum MSVtorDispMode MSVtorDispMode(void) const noexcept;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::CXXRecordDecl MostRecentDeclaration(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> MostRecentNonInjectedDeclaration(void) const noexcept;
  std::optional<uint32_t> NumBases(void) const noexcept;
  std::optional<uint32_t> NumVirtualBases(void) const noexcept;
  std::optional<uint32_t> ODRHash(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> PreviousDeclaration(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> TemplateInstantiationPattern(void) const noexcept;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const noexcept;
  // VisibleConversionFunctions: (llvm::iterator_range<clang::UnresolvedSetIterator>)
  std::optional<bool> HasAnyDependentBases(void) const noexcept;
  std::optional<bool> HasConstexprDefaultConstructor(void) const noexcept;
  std::optional<bool> HasConstexprDestructor(void) const noexcept;
  std::optional<bool> HasConstexprNonCopyMoveConstructor(void) const noexcept;
  std::optional<bool> HasCopyAssignmentWithConstParameter(void) const noexcept;
  std::optional<bool> HasCopyConstructorWithConstParameter(void) const noexcept;
  std::optional<bool> HasDefaultConstructor(void) const noexcept;
  std::optional<bool> HasDefinition(void) const noexcept;
  std::optional<bool> HasDirectFields(void) const noexcept;
  std::optional<bool> HasFriends(void) const noexcept;
  std::optional<bool> HasInClassInitializer(void) const noexcept;
  std::optional<bool> HasInheritedAssignment(void) const noexcept;
  std::optional<bool> HasInheritedConstructor(void) const noexcept;
  std::optional<bool> HasInitializerMethod(void) const noexcept;
  std::optional<bool> HasIrrelevantDestructor(void) const noexcept;
  std::optional<bool> HasKnownLambdaInternalLinkage(void) const noexcept;
  // HasMemberName: (bool)
  std::optional<bool> HasMoveAssignment(void) const noexcept;
  std::optional<bool> HasMoveConstructor(void) const noexcept;
  std::optional<bool> HasMutableFields(void) const noexcept;
  std::optional<bool> HasNonLiteralTypeFieldsOrBases(void) const noexcept;
  std::optional<bool> HasNonTrivialCopyAssignment(void) const noexcept;
  std::optional<bool> HasNonTrivialCopyConstructor(void) const noexcept;
  std::optional<bool> HasNonTrivialCopyConstructorForCall(void) const noexcept;
  std::optional<bool> HasNonTrivialDefaultConstructor(void) const noexcept;
  std::optional<bool> HasNonTrivialDestructor(void) const noexcept;
  std::optional<bool> HasNonTrivialDestructorForCall(void) const noexcept;
  std::optional<bool> HasNonTrivialMoveAssignment(void) const noexcept;
  std::optional<bool> HasNonTrivialMoveConstructor(void) const noexcept;
  std::optional<bool> HasNonTrivialMoveConstructorForCall(void) const noexcept;
  std::optional<bool> HasPrivateFields(void) const noexcept;
  std::optional<bool> HasProtectedFields(void) const noexcept;
  std::optional<bool> HasSimpleCopyAssignment(void) const noexcept;
  std::optional<bool> HasSimpleCopyConstructor(void) const noexcept;
  std::optional<bool> HasSimpleDestructor(void) const noexcept;
  std::optional<bool> HasSimpleMoveAssignment(void) const noexcept;
  std::optional<bool> HasSimpleMoveConstructor(void) const noexcept;
  std::optional<bool> HasTrivialCopyAssignment(void) const noexcept;
  std::optional<bool> HasTrivialCopyConstructor(void) const noexcept;
  std::optional<bool> HasTrivialCopyConstructorForCall(void) const noexcept;
  std::optional<bool> HasTrivialDefaultConstructor(void) const noexcept;
  std::optional<bool> HasTrivialDestructor(void) const noexcept;
  std::optional<bool> HasTrivialDestructorForCall(void) const noexcept;
  std::optional<bool> HasTrivialMoveAssignment(void) const noexcept;
  std::optional<bool> HasTrivialMoveConstructor(void) const noexcept;
  std::optional<bool> HasTrivialMoveConstructorForCall(void) const noexcept;
  std::optional<bool> HasUninitializedReferenceMember(void) const noexcept;
  std::optional<bool> HasUserDeclaredConstructor(void) const noexcept;
  std::optional<bool> HasUserDeclaredCopyAssignment(void) const noexcept;
  std::optional<bool> HasUserDeclaredCopyConstructor(void) const noexcept;
  std::optional<bool> HasUserDeclaredDestructor(void) const noexcept;
  std::optional<bool> HasUserDeclaredMoveAssignment(void) const noexcept;
  std::optional<bool> HasUserDeclaredMoveConstructor(void) const noexcept;
  std::optional<bool> HasUserDeclaredMoveOperation(void) const noexcept;
  std::optional<bool> HasUserProvidedDefaultConstructor(void) const noexcept;
  std::optional<bool> HasVariantMembers(void) const noexcept;
  std::optional<bool> ImplicitCopyAssignmentHasConstParameter(void) const noexcept;
  std::optional<bool> ImplicitCopyConstructorHasConstParameter(void) const noexcept;
  std::optional<bool> IsAbstract(void) const noexcept;
  std::optional<bool> IsAggregate(void) const noexcept;
  std::optional<bool> IsAnyDestructorNoReturn(void) const noexcept;
  std::optional<bool> IsCLike(void) const noexcept;
  std::optional<bool> IsCXX11StandardLayout(void) const noexcept;
  // IsCurrentInstantiation: (bool)
  bool IsDependentLambda(void) const noexcept;
  std::optional<bool> IsDynamicClass(void) const noexcept;
  std::optional<bool> IsEffectivelyFinal(void) const noexcept;
  std::optional<bool> IsEmpty(void) const noexcept;
  bool IsGenericLambda(void) const noexcept;
  std::optional<bool> IsInterfaceLike(void) const noexcept;
  bool IsLambda(void) const noexcept;
  std::optional<bool> IsLiteral(void) const noexcept;
  std::optional<::pasta::FunctionDecl> IsLocalClass(void) const noexcept;
  std::optional<bool> IsPOD(void) const noexcept;
  std::optional<bool> IsParsingBaseSpecifiers(void) const noexcept;
  std::optional<bool> IsPolymorphic(void) const noexcept;
  // IsProvablyNotDerivedFrom: (bool)
  std::optional<bool> IsStandardLayout(void) const noexcept;
  std::optional<bool> IsStructural(void) const noexcept;
  std::optional<bool> IsTrivial(void) const noexcept;
  std::optional<bool> IsTriviallyCopyable(void) const noexcept;
  // IsVirtuallyDerivedFrom: (bool)
  std::optional<bool> LambdaIsDefaultConstructibleAndAssignable(void) const noexcept;
  // LookupInBases: (bool)
  std::optional<bool> MayBeAbstract(void) const noexcept;
  std::optional<bool> MayBeDynamicClass(void) const noexcept;
  std::optional<bool> MayBeNonDynamicClass(void) const noexcept;
  std::optional<std::vector<::pasta::CXXMethodDecl>> Methods(void) const noexcept;
  std::optional<bool> NeedsImplicitCopyAssignment(void) const noexcept;
  std::optional<bool> NeedsImplicitCopyConstructor(void) const noexcept;
  std::optional<bool> NeedsImplicitDefaultConstructor(void) const noexcept;
  std::optional<bool> NeedsImplicitDestructor(void) const noexcept;
  std::optional<bool> NeedsImplicitMoveAssignment(void) const noexcept;
  std::optional<bool> NeedsImplicitMoveConstructor(void) const noexcept;
  std::optional<bool> NeedsOverloadResolutionForCopyAssignment(void) const noexcept;
  std::optional<bool> NeedsOverloadResolutionForCopyConstructor(void) const noexcept;
  std::optional<bool> NeedsOverloadResolutionForDestructor(void) const noexcept;
  std::optional<bool> NeedsOverloadResolutionForMoveAssignment(void) const noexcept;
  std::optional<bool> NeedsOverloadResolutionForMoveConstructor(void) const noexcept;
  std::optional<bool> NullFieldOffsetIsZero(void) const noexcept;
  std::optional<std::vector<::pasta::CXXBaseSpecifier>> VirtualBases(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::Token ExternToken(void) const noexcept;
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> InstantiatedFrom(void) const noexcept;
  ::pasta::Token PointOfInstantiation(void) const noexcept;
  enum TemplateSpecializationKind SpecializationKind(void) const noexcept;
  ::pasta::ClassTemplateDecl SpecializedTemplate(void) const noexcept;
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> SpecializedTemplateOrPartial(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TemplateInstantiationArguments(void) const noexcept;
  ::pasta::Token TemplateKeywordToken(void) const noexcept;
  std::optional<::pasta::Type> TypeAsWritten(void) const noexcept;
  bool IsClassScopeExplicitSpecialization(void) const noexcept;
  bool IsExplicitInstantiationOrSpecialization(void) const noexcept;
  bool IsExplicitSpecialization(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
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
  ::pasta::Type InjectedSpecializationType(void) const noexcept;
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMember(void) const noexcept;
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMemberTemplate(void) const noexcept;
  // TemplateArgumentsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  ::pasta::TemplateParameterList TemplateParameters(void) const noexcept;
  bool HasAssociatedConstraints(void) const noexcept;
  std::vector<::pasta::TemplateParameterList> TemplateParameterLists(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassTemplatePartialSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassTemplatePartialSpecializationDecl));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
#include "DeclTail.h"
