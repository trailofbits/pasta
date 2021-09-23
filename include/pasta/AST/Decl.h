/*
 * Copyright (c) 2021 Trail of Bits, Inc.
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

#include "DeclManual.h"

#define PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class DeclBuilder; \
    friend class DeclVisitor; \
    base(void) = delete; \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::Decl *decl_);

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
  virtual void VisitUnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &);
  virtual void VisitUsingDecl(const UsingDecl &);
  virtual void VisitUsingDirectiveDecl(const UsingDirectiveDecl &);
  virtual void VisitUsingPackDecl(const UsingPackDecl &);
  virtual void VisitUsingShadowDecl(const UsingShadowDecl &);
  virtual void VisitValueDecl(const ValueDecl &);
  virtual void VisitOMPDeclarativeDirectiveDecl(const OMPDeclarativeDirectiveDecl &);
  virtual void VisitOMPDeclarativeDirectiveValueDecl(const OMPDeclarativeDirectiveValueDecl &);
  virtual void VisitAccessSpecDecl(const AccessSpecDecl &);
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
  // ContainsDecl: (bool)
  // ContainsDeclAndLoad: (bool)
  // Ddiags: (llvm::iterator_range<clang::DeclContext::ddiag_iterator>)
  std::vector<::pasta::Decl> Declarations(void) const;
  ::pasta::DeclKind DeclKind(void) const;
  ::pasta::DeclContext EnclosingNamespaceContext(void) const;
  ::pasta::LinkageSpecDecl ExternCContext(void) const;
  ::pasta::BlockDecl InnermostBlockDecl(void) const;
  ::pasta::DeclContext LexicalParent(void) const;
  ::pasta::DeclContext LookupParent(void) const;
  // LookupPtr: (clang::StoredDeclsMap *)
  ::pasta::Decl NonClosureAncestor(void) const;
  ::pasta::RecordDecl OuterLexicalRecordContext(void) const;
  ::pasta::DeclContext Parent(void) const;
  // ParentASTContext: (clang::ASTContext &)
  ::pasta::DeclContext PrimaryContext(void) const;
  ::pasta::DeclContext RedeclContext(void) const;
  bool HasExternalLexicalStorage(void) const;
  bool HasExternalVisibleStorage(void) const;
  bool IsClosure(void) const;
  // IsDeclInLexicalTraversal: (bool)
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
  std::vector<::pasta::Decl> AlreadyLoadedDecls(void) const;
  // Noload_lookups: (llvm::iterator_range<clang::DeclContext::all_lookups_iterator>)
  bool ShouldUseQualifiedLookup(void) const;
  // Using_directives: (llvm::iterator_range<clang::DeclContext::udir_iterator>)
 private:
  friend class Decl;
  friend class DeclVisitor;
  friend class UsingDirectiveDecl;
  std::shared_ptr<ASTImpl> ast;
  union {
    void *opaque;
    const ::clang::DeclContext *DeclContext;
  } u;
  inline DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *context_)
      : ast(std::move(ast_)) {
    u.DeclContext = context_;
  }
};

class Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Decl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, AccessSpecDecl)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingPackDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, ValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, VarTemplateSpecializationDecl)
  // Attributes: (llvm::iterator_range<clang::Attr *const *>)
  // CanBeWeakImported: (bool)
  // ASTContext: (clang::ASTContext &)
  enum AccessSpecifier Access(void) const;
  enum AccessSpecifier AccessUnsafe(void) const;
  ::pasta::FunctionDecl AsFunction(void) const;
  // Attributes: (const llvm::SmallVector<clang::Attr *, 4> &)
  enum AvailabilityResult Availability(void) const;
  ::pasta::Token BeginToken(void) const;
  // Body: (clang::Stmt *)
  ::pasta::Token BodyRBrace(void) const;
  ::pasta::Decl CanonicalDecl(void) const;
  ::pasta::DeclContext DeclContext(void) const;
  // DefiningAttr: (const clang::Attr *)
  ::pasta::TemplateDecl DescribedTemplate(void) const;
  // DescribedTemplateParams: (const clang::TemplateParameterList *)
  ::pasta::Token EndToken(void) const;
  // ExternalSourceSymbolAttr: (clang::ExternalSourceSymbolAttr *)
  ::pasta::FriendObjectKind FriendObjectKind(void) const;
  ::pasta::FunctionType FunctionType(void) const;
  uint32_t GlobalID(void) const;
  // ID: (long long)
  uint32_t IdentifierNamespace(void) const;
  // ImportedOwningModule: (clang::Module *)
  // LangOpts: (const clang::LangOptions &)
  ::pasta::DeclContext LexicalDeclContext(void) const;
  // LocalOwningModule: (clang::Module *)
  ::pasta::Token Token(void) const;
  uint32_t MaxAlignment(void) const;
  ::pasta::ModuleOwnershipKind ModuleOwnershipKind(void) const;
  ::pasta::Decl MostRecentDecl(void) const;
  ::pasta::Decl NextDeclInContext(void) const;
  ::pasta::Decl NonClosureContext(void) const;
  // OwningModule: (clang::Module *)
  // OwningModuleForLinkage: (clang::Module *)
  uint32_t OwningModuleID(void) const;
  ::pasta::DeclContext ParentFunctionOrMethod(void) const;
  ::pasta::Decl PreviousDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  uint32_t TemplateDepth(void) const;
  ::pasta::TranslationUnitDecl TranslationUnitDecl(void) const;
  // VersionIntroduced: (llvm::VersionTuple)
  bool HasAttributes(void) const;
  bool HasBody(void) const;
  bool HasDefiningAttr(void) const;
  bool HasOwningModule(void) const;
  bool HasTagIdentifierNamespace(void) const;
  bool IsCanonicalDecl(void) const;
  bool IsDefinedOutsideFunctionOrMethod(void) const;
  bool IsDeprecated(void) const;
  bool IsFirstDecl(void) const;
  bool IsFromASTFile(void) const;
  bool IsFunctionOrFunctionTemplate(void) const;
  bool IsImplicit(void) const;
  bool IsInAnonymousNamespace(void) const;
  // IsInIdentifierNamespace: (bool)
  bool IsInLocalScopeForInstantiation(void) const;
  bool IsInStdNamespace(void) const;
  bool IsInvalidDecl(void) const;
  bool IsModulePrivate(void) const;
  bool IsOutOfLine(void) const;
  bool IsParameterPack(void) const;
  bool IsReferenced(void) const;
  bool IsTemplateDecl(void) const;
  bool IsTemplateParameter(void) const;
  bool IsTemplateParameterPack(void) const;
  bool IsTemplated(void) const;
  bool IsThisDeclarationReferenced(void) const;
  bool IsTopLevelDeclInObjCContainer(void) const;
  bool IsUnavailable(void) const;
  bool IsUnconditionallyVisible(void) const;
  bool IsUsed(void) const;
  bool IsWeakImported(void) const;
  std::vector<::pasta::Decl> Redeclarations(void) const;
  PASTA_DECLARE_DERIVED_OPERATORS(Decl, DeclContext)

  inline DeclKind Kind(void) const {
    return kind;
  }

  std::string_view KindName(void) const;

  inline bool operator==(const Decl &that) const noexcept {
    return u.opaque == that.u.opaque;
  }
 protected:
  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::AccessSpecDecl *AccessSpecDecl;
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
    const ::clang::UnresolvedUsingTypenameDecl *UnresolvedUsingTypenameDecl;
    const ::clang::UnresolvedUsingValueDecl *UnresolvedUsingValueDecl;
    const ::clang::UsingDecl *UsingDecl;
    const ::clang::UsingDirectiveDecl *UsingDirectiveDecl;
    const ::clang::UsingPackDecl *UsingPackDecl;
    const ::clang::UsingShadowDecl *UsingShadowDecl;
    const ::clang::ValueDecl *ValueDecl;
    const ::clang::VarDecl *VarDecl;
    const ::clang::VarTemplateDecl *VarTemplateDecl;
    const ::clang::VarTemplatePartialSpecializationDecl *VarTemplatePartialSpecializationDecl;
    const ::clang::VarTemplateSpecializationDecl *VarTemplateSpecializationDecl;
    const ::clang::OMPDeclarativeDirectiveDecl *OMPDeclarativeDirectiveDecl;
    const ::clang::OMPDeclarativeDirectiveValueDecl *OMPDeclarativeDirectiveValueDecl;
    const void *opaque;
  } u;
  DeclKind kind;

  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Decl *decl_,
                       DeclKind kind_)
      : ast(std::move(ast_)),
        kind(kind_) {
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
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::Token AsmToken(void) const;
  // AsmString: (const clang::StringLiteral *)
  ::pasta::Token RParenToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FileScopeAsmDecl)
};

static_assert(sizeof(Decl) == sizeof(FileScopeAsmDecl));

class FriendDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendDecl)
  ::pasta::NamedDecl FindFriendDecl(void) const;
  ::pasta::Token FriendToken(void) const;
  // FriendType: (clang::TypeSourceInfo *)
  uint32_t FriendTypeNumTemplateParameterLists(void) const;
  // FriendTypeTemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::TokenRange TokenRange(void) const;
  bool IsUnsupportedFriend(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendDecl));

class FriendTemplateDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendTemplateDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, FriendTemplateDecl)
  ::pasta::NamedDecl FindFriendDecl(void) const;
  ::pasta::Token FriendToken(void) const;
  // FriendType: (clang::TypeSourceInfo *)
  uint32_t NumTemplateParameters(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(FriendTemplateDecl)
};

static_assert(sizeof(Decl) == sizeof(FriendTemplateDecl));

class ImportDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImportDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, ImportDecl)
  // IdentifierLocs: (llvm::ArrayRef<clang::SourceLocation>)
  // ImportedModule: (clang::Module *)
  ::pasta::TokenRange TokenRange(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ImportDecl)
};

static_assert(sizeof(Decl) == sizeof(ImportDecl));

class LifetimeExtendedTemporaryDecl : public Decl {
 private:
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LifetimeExtendedTemporaryDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
  // ChildrenExpr: (llvm::iterator_range<clang::ConstStmtIterator>)
  ::pasta::ValueDecl ExtendingDecl(void) const;
  uint32_t ManglingNumber(void) const;
  // OrCreateValue: (clang::APValue *)
  enum StorageDuration StorageDuration(void) const;
  // TemporaryExpr: (const clang::Expr *)
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
  ::pasta::LanguageIDs Language(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
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
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingPackDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, ValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
  // DeclarationReplaces: (bool)
  // DeclName: (clang::DeclarationName)
  // ExplicitVisibility: (llvm::Optional<clang::Visibility>)
  enum Linkage FormalLinkage(void) const;
  // Identifier: (clang::IdentifierInfo *)
  // LinkageAndVisibility: (clang::LinkageInfo)
  enum Linkage LinkageInternal(void) const;
  ::pasta::NamedDecl MostRecentDecl(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  enum ObjCStringFormatFamily ObjCFStringFormattingFamily(void) const;
  std::string QualifiedNameAsString(void) const;
  ::pasta::NamedDecl UnderlyingDecl(void) const;
  enum Visibility Visibility(void) const;
  bool HasExternalFormalLinkage(void) const;
  bool HasLinkage(void) const;
  bool HasLinkageBeenComputed(void) const;
  bool IsCXXClassMember(void) const;
  bool IsCXXInstanceMember(void) const;
  bool IsExternallyDeclarable(void) const;
  bool IsExternallyVisible(void) const;
  bool IsLinkageValid(void) const;
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
  ::pasta::NamespaceAliasDecl CanonicalDecl(void) const;
  ::pasta::NamespaceDecl Namespace(void) const;
  ::pasta::Token NamespaceToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::NamespaceDecl CanonicalDecl(void) const;
  ::pasta::NamespaceDecl OriginalNamespace(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAnonymousNamespace(void) const;
  bool IsInline(void) const;
  bool IsOriginalNamespace(void) const;
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
  // IvarDecl: (clang::ObjCIvarDecl *)
  // Method: (clang::ObjCMethodDecl *)
  ::pasta::TokenRange TokenRange(void) const;
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
  // FindPropertyImplDecl: (clang::ObjCPropertyImplDecl *)
  // FindPropertyImplIvarDecl: (clang::ObjCPropertyImplDecl *)
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
  ::pasta::Token IvarLBraceToken(void) const;
  ::pasta::Token IvarRBraceToken(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  uint32_t NumIvarInitializers(void) const;
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
  ::pasta::ObjCInterfaceDecl CanonicalDecl(void) const;
  // CategoryClassMethod: (clang::ObjCMethodDecl *)
  // CategoryInstanceMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCCategoryDecl CategoryListRaw(void) const;
  // CategoryMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCInterfaceDecl Definition(void) const;
  ::pasta::Token EndOfDefinitionToken(void) const;
  ::pasta::ObjCImplementationDecl Implementation(void) const;
  std::string_view ObjCRuntimeNameAsString(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::ObjCInterfaceDecl SuperClass(void) const;
  ::pasta::Token SuperClassToken(void) const;
  // SuperClassTInfo: (clang::TypeSourceInfo *)
  ::pasta::ObjCObjectType SuperClassType(void) const;
  ::pasta::Type TypeForDecl(void) const;
  // TypeParamList: (clang::ObjCTypeParamList *)
  // TypeParamListAsWritten: (clang::ObjCTypeParamList *)
  bool HasDefinition(void) const;
  bool HasDesignatedInitializers(void) const;
  bool IsArcWeakrefUnavailable(void) const;
  // IsDesignatedInitializer: (bool)
  bool IsImplicitInterfaceDecl(void) const;
  ::pasta::ObjCInterfaceDecl IsObjCRequiresPropertyDefs(void) const;
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
  std::vector<::pasta::Token> ProtocolLocations(void) const;
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
  ::pasta::ObjCPropertyDecl FindPropertyDecl(void) const;
  ::pasta::Token BeginToken(void) const;
  // Body: (clang::Stmt *)
  ::pasta::ObjCMethodDecl CanonicalDecl(void) const;
  ::pasta::ObjCCategoryDecl Category(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::ImplicitParamDecl CmdDecl(void) const;
  ::pasta::Token DeclaratorEndToken(void) const;
  ::pasta::Token EndToken(void) const;
  ::pasta::ImplementationControl ImplementationControl(void) const;
  enum ObjCMethodFamily MethodFamily(void) const;
  uint32_t NumSelectorLocs(void) const;
  // ObjCDeclQualifier: (clang::Decl::ObjCDeclQualifier)
  // ParamDecl: (const clang::ParmVarDecl *)
  ::pasta::Type ReturnType(void) const;
  // ReturnTypeSourceInfo: (clang::TypeSourceInfo *)
  ::pasta::TokenRange ReturnTypeSourceRange(void) const;
  // Selector: (clang::Selector)
  // SelectorToken: (clang::SourceLocation)
  ::pasta::Token SelectorStartToken(void) const;
  ::pasta::ImplicitParamDecl SelfDecl(void) const;
  // SelfType: (clang::QualType)
  ::pasta::TokenRange TokenRange(void) const;
  bool HasBody(void) const;
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
  // DefaultSynthIvarName: (clang::IdentifierInfo *)
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  // GetterName: (clang::Selector)
  ::pasta::Token GetterNameToken(void) const;
  ::pasta::Token LParenToken(void) const;
  // PropertyAttributes: (clang::ObjCPropertyAttribute::Kind)
  // PropertyAttributesAsWritten: (clang::ObjCPropertyAttribute::Kind)
  ::pasta::PropertyControl PropertyImplementation(void) const;
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  enum ObjCPropertyQueryKind QueryKind(void) const;
  ::pasta::SetterKind SetterKind(void) const;
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  // SetterName: (clang::Selector)
  ::pasta::Token SetterNameToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Type Type(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
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
  // GetterCXXConstructor: (clang::Expr *)
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  ::pasta::ObjCPropertyDecl PropertyDecl(void) const;
  // PropertyImplementation: (clang::ObjCPropertyImplDecl::Kind)
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  ::pasta::Token PropertyIvarDeclToken(void) const;
  // SetterCXXAssignment: (clang::Expr *)
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsIvarNameSpecified(void) const;
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
  ::pasta::ObjCProtocolDecl CanonicalDecl(void) const;
  ::pasta::ObjCProtocolDecl Definition(void) const;
  std::string_view ObjCRuntimeNameAsString(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  ::pasta::TokenRange TokenRange(void) const;
  bool HasDefinition(void) const;
  bool IsNonRuntimeProtocol(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupMethod: (clang::ObjCMethodDecl *)
  std::vector<::pasta::Token> ProtocolLocations(void) const;
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
  std::string_view Arg(void) const;
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
  // AssertExpr: (const clang::Expr *)
  // Message: (const clang::StringLiteral *)
  ::pasta::Token RParenToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
  // TemplateParameters: (clang::TemplateParameterList *)
  ::pasta::NamedDecl TemplatedDecl(void) const;
  bool HasAssociatedConstraints(void) const;
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
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::TemplateTemplateParmDecl, clang::TemplateArgumentLoc *> &)
  // DefaultArgument: (const clang::TemplateArgumentLoc &)
  ::pasta::Token DefaultArgumentToken(void) const;
  // ExpansionTemplateParameters: (clang::TemplateParameterList *)
  uint32_t NumExpansionTemplateParameters(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasDefaultArgument(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
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
  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Type TypeForDecl(void) const;
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
  ::pasta::TagDecl AnonDeclWithTypedefName(void) const;
  ::pasta::TypedefNameDecl CanonicalDecl(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  ::pasta::Type UnderlyingType(void) const;
  bool IsModed(void) const;
  bool IsTransparentTag(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(TypedefNameDecl)
};

static_assert(sizeof(Decl) == sizeof(TypedefNameDecl));

class UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  using TypeDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
  PASTA_DECLARE_BASE_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
  ::pasta::UnresolvedUsingTypenameDecl CanonicalDecl(void) const;
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

class UsingDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingDecl)
  ::pasta::UsingDecl CanonicalDecl(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Token UsingToken(void) const;
  bool HasTypename(void) const;
  bool IsAccessDeclaration(void) const;
  std::vector<::pasta::UsingShadowDecl> Shadows(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UsingDecl)
};

static_assert(sizeof(Decl) == sizeof(UsingDecl));

class UsingDirectiveDecl : public NamedDecl {
 private:
  using NamedDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDirectiveDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, UsingDirectiveDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, UsingDirectiveDecl)
  ::pasta::DeclContext CommonAncestor(void) const;
  ::pasta::Token IdentLocation(void) const;
  ::pasta::Token NamespaceKeyLocation(void) const;
  ::pasta::NamespaceDecl NominatedNamespace(void) const;
  ::pasta::NamedDecl NominatedNamespaceAsWritten(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::UsingPackDecl CanonicalDecl(void) const;
  ::pasta::NamedDecl InstantiatedFromUsingDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::UsingShadowDecl CanonicalDecl(void) const;
  ::pasta::UsingShadowDecl NextUsingShadowDecl(void) const;
  ::pasta::NamedDecl TargetDecl(void) const;
  ::pasta::UsingDecl UsingDecl(void) const;
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
  ::pasta::Type Type(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(AccessSpecDecl)
};

static_assert(sizeof(Decl) == sizeof(AccessSpecDecl));

class BindingDecl : public ValueDecl {
 private:
  using ValueDecl::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(Decl, BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(NamedDecl, BindingDecl)
  PASTA_DECLARE_BASE_OPERATORS(ValueDecl, BindingDecl)
  // Binding: (clang::Expr *)
  ::pasta::ValueDecl DecomposedDecl(void) const;
  ::pasta::VarDecl HoldingVar(void) const;
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
  ::pasta::Decl BlockManglingContextDecl(void) const;
  uint32_t BlockManglingNumber(void) const;
  // Body: (clang::Stmt *)
  ::pasta::Token CaretLocation(void) const;
  // CompoundBody: (clang::CompoundStmt *)
  uint32_t NumCaptures(void) const;
  uint32_t NumParams(void) const;
  // ParamDecl: (const clang::ParmVarDecl *)
  // SignatureAsWritten: (clang::TypeSourceInfo *)
  ::pasta::TokenRange TokenRange(void) const;
  bool HasCaptures(void) const;
  bool IsConversionFromLambda(void) const;
  bool IsVariadic(void) const;
  std::vector<::pasta::ParmVarDecl> Parameters(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
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
  // Body: (clang::Stmt *)
  ::pasta::ImplicitParamDecl ContextParam(void) const;
  uint32_t ContextParamPosition(void) const;
  uint32_t NumParams(void) const;
  // Param: (clang::ImplicitParamDecl *)
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
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  bool HasExplicitTemplateArgs(void) const;
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
  ::pasta::ConceptDecl CanonicalDecl(void) const;
  // ConstraintExpr: (clang::Expr *)
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::ConstructorUsingShadowDecl ConstructedBaseClassShadowDecl(void) const;
  ::pasta::CXXRecordDecl NominatedBaseClass(void) const;
  ::pasta::ConstructorUsingShadowDecl NominatedBaseClassShadowDecl(void) const;
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
  ::pasta::Token InnerLocStart(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  ::pasta::Token OuterLocStart(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  // TrailingRequiresClause: (const clang::Expr *)
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  ::pasta::Token TypeSpecEndToken(void) const;
  ::pasta::Token TypeSpecStartToken(void) const;
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
  ::pasta::EnumConstantDecl CanonicalDecl(void) const;
  // InitExpr: (const clang::Expr *)
  // InitVal: (const llvm::APSInt &)
  ::pasta::TokenRange TokenRange(void) const;
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
  // BitWidth: (clang::Expr *)
  uint32_t BitWidthValue(void) const;
  ::pasta::FieldDecl CanonicalDecl(void) const;
  ::pasta::VariableArrayType CapturedVLAType(void) const;
  uint32_t FieldIndex(void) const;
  enum InClassInitStyle InClassInitStyle(void) const;
  // InClassInitializer: (clang::Expr *)
  ::pasta::RecordDecl Parent(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasCapturedVLAType(void) const;
  bool HasInClassInitializer(void) const;
  bool IsAnonymousStructOrUnion(void) const;
  bool IsBitField(void) const;
  bool IsMutable(void) const;
  bool IsUnnamedBitfield(void) const;
  bool IsZeroLengthBitField(void) const;
  bool IsZeroSize(void) const;
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
  bool DoesDeclarationForceExternallyVisibleDefinition(void) const;
  bool DoesThisDeclarationHaveABody(void) const;
  uint32_t BuiltinID(void) const;
  ::pasta::Type CallResultType(void) const;
  ::pasta::FunctionDecl CanonicalDecl(void) const;
  enum ConstexprSpecKind ConstexprKind(void) const;
  ::pasta::Type DeclaredReturnType(void) const;
  // DefaultedFunctionInfo: (clang::FunctionDecl::DefaultedFunctionInfo *)
  ::pasta::FunctionDecl Definition(void) const;
  // DependentSpecializationInfo: (clang::DependentFunctionTemplateSpecializationInfo *)
  ::pasta::FunctionTemplateDecl DescribedFunctionTemplate(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::TokenRange ExceptionSpecSourceRange(void) const;
  enum ExceptionSpecificationType ExceptionSpecType(void) const;
  // FunctionTypeToken: (clang::FunctionTypeLoc)
  ::pasta::FunctionDecl InstantiatedFromMemberFunction(void) const;
  enum LanguageLinkage LanguageLinkage(void) const;
  // LiteralIdentifier: (const clang::IdentifierInfo *)
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  uint32_t MemoryFunctionKind(void) const;
  uint32_t MinRequiredArguments(void) const;
  enum MultiVersionKind MultiVersionKind(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  uint32_t NumParams(void) const;
  uint32_t ODRHash(void) const;
  enum OverloadedOperatorKind OverloadedOperator(void) const;
  // ParamDecl: (const clang::ParmVarDecl *)
  ::pasta::TokenRange ParametersSourceRange(void) const;
  ::pasta::Token PointOfInstantiation(void) const;
  ::pasta::FunctionTemplateDecl PrimaryTemplate(void) const;
  ::pasta::Type ReturnType(void) const;
  ::pasta::TokenRange ReturnTypeSourceRange(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  enum StorageClass StorageClass(void) const;
  ::pasta::FunctionDecl TemplateInstantiationPattern(void) const;
  // TemplateSpecializationArgs: (const clang::TemplateArgumentList *)
  // TemplateSpecializationArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateSpecializationInfo: (clang::FunctionTemplateSpecializationInfo *)
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const;
  // TemplatedKind: (clang::FunctionDecl::TemplatedKind)
  bool HasImplicitReturnZero(void) const;
  bool HasInheritedPrototype(void) const;
  bool HasOneParamOrDefaultArgs(void) const;
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
  bool IsImplicitlyInstantiable(void) const;
  bool IsInExternCContext(void) const;
  bool IsInExternCXXContext(void) const;
  bool IsInlineBuiltinDeclaration(void) const;
  bool IsInlineDefinitionExternallyVisible(void) const;
  bool IsInlineSpecified(void) const;
  bool IsInlined(void) const;
  bool IsLateTemplateParsed(void) const;
  bool IsMSExternInline(void) const;
  bool IsMSVCRTEntryPoint(void) const;
  bool IsMain(void) const;
  bool IsMultiVersion(void) const;
  bool IsNoReturn(void) const;
  bool IsOutOfLine(void) const;
  bool IsOverloadedOperator(void) const;
  bool IsPure(void) const;
  bool IsReplaceableGlobalAllocationFunction(void) const;
  bool IsReservedGlobalPlacementOperator(void) const;
  bool IsStatic(void) const;
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
  std::vector<::pasta::NamedDecl> Chain(void) const;
  ::pasta::FieldDecl AnonField(void) const;
  ::pasta::IndirectFieldDecl CanonicalDecl(void) const;
  uint32_t ChainingSize(void) const;
  ::pasta::VarDecl VarDecl(void) const;
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
  std::string_view MSAsmLabel(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  // Stmt: (clang::LabelStmt *)
  bool IsGnuLocal(void) const;
  bool IsMSAsmLabel(void) const;
  bool IsResolvedMSAsmLabel(void) const;
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
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::NonTypeTemplateParmDecl, clang::Expr *> &)
  // DefaultArgument: (clang::Expr *)
  ::pasta::Token DefaultArgumentToken(void) const;
  // ExpansionType: (clang::QualType)
  // ExpansionTypeSourceInfo: (clang::TypeSourceInfo *)
  uint32_t NumExpansionTypes(void) const;
  // PlaceholderTypeConstraint: (clang::Expr *)
  ::pasta::TokenRange TokenRange(void) const;
  bool HasDefaultArgument(void) const;
  bool HasPlaceholderTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
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
  // Varlists: (llvm::iterator_range<const clang::Expr *const *>)
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
  // MapperVarRef: (const clang::Expr *)
  ::pasta::OMPDeclareMapperDecl PrevDeclInScope(void) const;
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
  // Combiner: (const clang::Expr *)
  // CombinerIn: (const clang::Expr *)
  // CombinerOut: (const clang::Expr *)
  // InitOrig: (const clang::Expr *)
  // InitPriv: (const clang::Expr *)
  // Initializer: (const clang::Expr *)
  // InitializerKind: (clang::OMPDeclareReductionDecl::InitKind)
  ::pasta::OMPDeclareReductionDecl PrevDeclInScope(void) const;
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
  // Varlists: (llvm::iterator_range<const clang::Expr *const *>)
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
  ::pasta::Token IvarLBraceToken(void) const;
  ::pasta::Token IvarRBraceToken(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategory(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategoryRaw(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  // TypeParamList: (clang::ObjCTypeParamList *)
  std::vector<::pasta::ObjCIvarDecl> InstanceVariables(void) const;
  std::vector<::pasta::Token> ProtocolLocations(void) const;
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
  ::pasta::ObjCCategoryDecl CategoryDecl(void) const;
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
  // AccessControl: (clang::ObjCIvarDecl::AccessControl)
  // CanonicalAccessControl: (clang::ObjCIvarDecl::AccessControl)
  ::pasta::ObjCInterfaceDecl ContainingInterface(void) const;
  ::pasta::ObjCIvarDecl NextIvar(void) const;
  bool Synthesize(void) const;
  // UsageType: (clang::QualType)
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
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::RedeclarableTemplateDecl CanonicalDecl(void) const;
  ::pasta::RedeclarableTemplateDecl InstantiatedFromMemberTemplate(void) const;
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
  ::pasta::TagDecl CanonicalDecl(void) const;
  ::pasta::TagDecl Definition(void) const;
  ::pasta::Token InnerLocStart(void) const;
  std::string_view KindName(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  ::pasta::Token OuterLocStart(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  enum TagTypeKind TagKind(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::TypedefNameDecl TypedefNameForAnonDecl(void) const;
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
  bool IsUnion(void) const;
  bool MayHaveOutOfDateDef(void) const;
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
  ::pasta::TemplateParamObjectDecl CanonicalDecl(void) const;
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
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::TemplateTypeParmDecl, clang::TypeSourceInfo *> &)
  ::pasta::Type DefaultArgument(void) const;
  // DefaultArgumentInfo: (clang::TypeSourceInfo *)
  ::pasta::Token DefaultArgumentToken(void) const;
  uint32_t Depth(void) const;
  uint32_t Index(void) const;
  uint32_t NumExpansionParameters(void) const;
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::TypeAliasTemplateDecl DescribedAliasTemplate(void) const;
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::TypeAliasTemplateDecl CanonicalDecl(void) const;
  ::pasta::TypeAliasTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::TypeAliasTemplateDecl PreviousDecl(void) const;
  ::pasta::TypeAliasDecl TemplatedDecl(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
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
  ::pasta::UnresolvedUsingValueDecl CanonicalDecl(void) const;
  ::pasta::Token EllipsisToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Token UsingToken(void) const;
  bool IsAccessDeclaration(void) const;
  bool IsPackExpansion(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(UnresolvedUsingValueDecl)
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingValueDecl));

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
  // EnsureEvaluatedStmt: (clang::EvaluatedStmt *)
  // EvaluateDestruction: (bool)
  // EvaluateValue: (clang::APValue *)
  ::pasta::VarDecl ActingDefinition(void) const;
  ::pasta::VarDecl CanonicalDecl(void) const;
  ::pasta::VarTemplateDecl DescribedVarTemplate(void) const;
  // EvaluatedStmt: (clang::EvaluatedStmt *)
  // EvaluatedValue: (clang::APValue *)
  // Init: (const clang::Expr *)
  // InitStyle: (clang::VarDecl::InitializationStyle)
  ::pasta::VarDecl InitializingDeclaration(void) const;
  ::pasta::VarDecl InstantiatedFromStaticDataMember(void) const;
  enum LanguageLinkage LanguageLinkage(void) const;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::Token PointOfInstantiation(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  enum StorageClass StorageClass(void) const;
  enum StorageDuration StorageDuration(void) const;
  // TLSKind: (clang::VarDecl::TLSKind)
  enum ThreadStorageClassSpecifier TSCSpec(void) const;
  ::pasta::VarDecl TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKindForInstantiation(void) const;
  bool HasConstantInitialization(void) const;
  bool HasExternalStorage(void) const;
  bool HasGlobalStorage(void) const;
  bool HasICEInitializer(void) const;
  bool HasInit(void) const;
  bool HasLocalStorage(void) const;
  bool IsARCPseudoStrong(void) const;
  bool IsCXXForRangeDecl(void) const;
  bool IsConstexpr(void) const;
  bool IsDirectInit(void) const;
  bool IsEscapingByref(void) const;
  bool IsExceptionVariable(void) const;
  bool IsExternC(void) const;
  bool IsFileVarDecl(void) const;
  bool IsFunctionOrMethodVarDecl(void) const;
  bool IsInExternCContext(void) const;
  bool IsInExternCXXContext(void) const;
  bool IsInitCapture(void) const;
  bool IsInline(void) const;
  bool IsInlineSpecified(void) const;
  bool IsKnownToBeDefined(void) const;
  bool IsLocalVarDecl(void) const;
  bool IsLocalVarDeclOrParm(void) const;
  bool IsNRVOVariable(void) const;
  bool IsNoDestroy(void) const;
  bool IsNonEscapingByref(void) const;
  bool IsObjCForDecl(void) const;
  bool IsOutOfLine(void) const;
  bool IsParameterPack(void) const;
  bool IsPreviousDeclInSameBlockScope(void) const;
  bool IsStaticDataMember(void) const;
  bool IsStaticLocal(void) const;
  bool IsThisDeclarationADemotedDefinition(void) const;
  bool IsUsableInConstantExpressions(void) const;
  bool MightBeUsableInConstantExpressions(void) const;
  // NeedsDestruction: (clang::QualType::DestructionKind)
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
  ::pasta::VarTemplateDecl CanonicalDecl(void) const;
  ::pasta::VarTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::VarTemplateDecl MostRecentDecl(void) const;
  ::pasta::VarTemplateDecl PreviousDecl(void) const;
  ::pasta::VarDecl TemplatedDecl(void) const;
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
  // TemplateArgs: (const clang::TemplateArgumentList &)
  // TemplateArgsInfo: (const clang::TemplateArgumentListInfo &)
  // TemplateInstantiationArgs: (const clang::TemplateArgumentList &)
  ::pasta::Token TemplateKeywordToken(void) const;
  // TypeAsWritten: (clang::TypeSourceInfo *)
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
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
  ::pasta::TemplateDecl DeducedTemplate(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsCopyDeductionCandidate(void) const;
  bool IsExplicit(void) const;
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
  // Begin_overridden_methods: (const clang::CXXMethodDecl *const *)
  // End_overridden_methods: (const clang::CXXMethodDecl *const *)
  ::pasta::CXXMethodDecl CanonicalDecl(void) const;
  // CorrespondingMethodDeclaredInClass: (const clang::CXXMethodDecl *)
  // CorrespondingMethodInClass: (const clang::CXXMethodDecl *)
  // DevirtualizedMethod: (const clang::CXXMethodDecl *)
  // MethodQualifiers: (clang::Qualifiers)
  ::pasta::CXXMethodDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
  enum RefQualifierKind RefQualifier(void) const;
  ::pasta::Type ThisObjectType(void) const;
  ::pasta::Type ThisType(void) const;
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
  // Overridden_methods: (llvm::iterator_range<const clang::CXXMethodDecl *const *>)
  uint32_t Size_overridden_methods(void) const;
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
  ::pasta::ClassTemplateDecl CanonicalDecl(void) const;
  ::pasta::ClassTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::ClassTemplateDecl MostRecentDecl(void) const;
  ::pasta::ClassTemplateDecl PreviousDecl(void) const;
  ::pasta::CXXRecordDecl TemplatedDecl(void) const;
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
  ::pasta::EnumDecl CanonicalDecl(void) const;
  ::pasta::EnumDecl Definition(void) const;
  ::pasta::EnumDecl InstantiatedFromMemberEnum(void) const;
  ::pasta::Type IntegerType(void) const;
  ::pasta::TokenRange IntegerTypeRange(void) const;
  // IntegerTypeSourceInfo: (clang::TypeSourceInfo *)
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::EnumDecl MostRecentDecl(void) const;
  uint32_t NumNegativeBits(void) const;
  uint32_t NumPositiveBits(void) const;
  ::pasta::EnumDecl PreviousDecl(void) const;
  ::pasta::Type PromotionType(void) const;
  ::pasta::EnumDecl TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  bool IsClosed(void) const;
  bool IsClosedFlag(void) const;
  bool IsClosedNonFlag(void) const;
  bool IsComplete(void) const;
  bool IsFixed(void) const;
  bool IsScoped(void) const;
  bool IsScopedUsingClassTag(void) const;
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
  ::pasta::FunctionTemplateDecl CanonicalDecl(void) const;
  ::pasta::FunctionTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::FunctionTemplateDecl MostRecentDecl(void) const;
  ::pasta::FunctionTemplateDecl PreviousDecl(void) const;
  ::pasta::FunctionDecl TemplatedDecl(void) const;
  bool IsAbbreviated(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations: (llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::FunctionTemplateSpecializationInfo, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::FunctionTemplateSpecializationInfo>, clang::FunctionDecl>>)
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
  ::pasta::ImplicitParamKind ParameterKind(void) const;
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
  ::pasta::TokenRange TokenRange(void) const;
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
  // DefaultArg: (const clang::Expr *)
  ::pasta::TokenRange DefaultArgRange(void) const;
  uint32_t FunctionScopeDepth(void) const;
  uint32_t FunctionScopeIndex(void) const;
  // ObjCDeclQualifier: (clang::Decl::ObjCDeclQualifier)
  ::pasta::Type OriginalType(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  // UninstantiatedDefaultArg: (const clang::Expr *)
  bool HasDefaultArg(void) const;
  bool HasInheritedDefaultArg(void) const;
  bool HasUninstantiatedDefaultArg(void) const;
  bool HasUnparsedDefaultArg(void) const;
  bool IsDestroyedInCallee(void) const;
  bool IsKNRPromoted(void) const;
  bool IsObjCMethodParameter(void) const;
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
  ::pasta::FieldDecl FindFirstNamedDataMember(void) const;
  ::pasta::ArgPassingKind ArgPassingRestrictions(void) const;
  ::pasta::RecordDecl Definition(void) const;
  ::pasta::RecordDecl MostRecentDecl(void) const;
  ::pasta::RecordDecl PreviousDecl(void) const;
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
  bool IsParamDestroyedInCallee(void) const;
  bool MayInsertExtraPadding(void) const;
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
  ::pasta::VarTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateParameters: (clang::TemplateParameterList *)
  bool HasAssociatedConstraints(void) const;
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
  ::pasta::CXXConstructorDecl CanonicalDecl(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  // InheritedConstructor: (clang::InheritedConstructor)
  uint32_t NumCtorInitializers(void) const;
  ::pasta::CXXConstructorDecl TargetConstructor(void) const;
  // Initializers: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  // IsConvertingConstructor: (bool)
  bool IsDefaultConstructor(void) const;
  bool IsDelegatingConstructor(void) const;
  bool IsExplicit(void) const;
  bool IsInheritingConstructor(void) const;
  bool IsSpecializationCopyingObject(void) const;
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
  ::pasta::CXXConversionDecl CanonicalDecl(void) const;
  ::pasta::Type ConversionType(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsExplicit(void) const;
  bool IsLambdaToBlockPointerConversion(void) const;
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
  ::pasta::CXXDestructorDecl CanonicalDecl(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  // OperatorDeleteThisArg: (clang::Expr *)
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
  bool AllowConstDefaultInit(void) const;
  // Bases: (llvm::iterator_range<const clang::CXXBaseSpecifier *>)
  enum MSInheritanceModel CalculateInheritanceModel(void) const;
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  std::vector<::pasta::CXXConstructorDecl> Constructors(void) const;
  bool DefaultedCopyConstructorIsDeleted(void) const;
  bool DefaultedDefaultConstructorIsConstexpr(void) const;
  bool DefaultedDestructorIsConstexpr(void) const;
  bool DefaultedDestructorIsDeleted(void) const;
  bool DefaultedMoveConstructorIsDeleted(void) const;
  // ForallBases: (bool)
  std::vector<::pasta::FriendDecl> Friends(void) const;
  ::pasta::CXXRecordDecl CanonicalDecl(void) const;
  ::pasta::CXXRecordDecl Definition(void) const;
  ::pasta::FunctionTemplateDecl DependentLambdaCallOperator(void) const;
  ::pasta::ClassTemplateDecl DescribedClassTemplate(void) const;
  ::pasta::CXXDestructorDecl Destructor(void) const;
  uint32_t DeviceLambdaManglingNumber(void) const;
  // GenericLambdaTemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::CXXRecordDecl InstantiatedFromMemberClass(void) const;
  ::pasta::CXXMethodDecl LambdaCallOperator(void) const;
  enum LambdaCaptureDefault LambdaCaptureDefault(void) const;
  ::pasta::Decl LambdaContextDecl(void) const;
  std::vector<::pasta::NamedDecl> LambdaExplicitTemplateParameters(void) const;
  uint32_t LambdaManglingNumber(void) const;
  // LambdaTypeInfo: (clang::TypeSourceInfo *)
  enum MSInheritanceModel MSInheritanceModel(void) const;
  enum MSVtorDispMode MSVtorDispMode(void) const;
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::CXXRecordDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl MostRecentNonInjectedDecl(void) const;
  uint32_t NumBases(void) const;
  uint32_t NumVBases(void) const;
  uint32_t ODRHash(void) const;
  ::pasta::CXXRecordDecl PreviousDecl(void) const;
  ::pasta::CXXRecordDecl TemplateInstantiationPattern(void) const;
  enum TemplateSpecializationKind TemplateSpecializationKind(void) const;
  // VisibleConversionFunctions: (llvm::iterator_range<clang::UnresolvedSetIterator>)
  bool HasAnyDependentBases(void) const;
  bool HasConstexprDefaultConstructor(void) const;
  bool HasConstexprDestructor(void) const;
  bool HasConstexprNonCopyMoveConstructor(void) const;
  bool HasCopyAssignmentWithConstParam(void) const;
  bool HasCopyConstructorWithConstParam(void) const;
  bool HasDefaultConstructor(void) const;
  bool HasDefinition(void) const;
  bool HasDirectFields(void) const;
  bool HasFriends(void) const;
  bool HasInClassInitializer(void) const;
  bool HasInheritedAssignment(void) const;
  bool HasInheritedConstructor(void) const;
  bool HasIrrelevantDestructor(void) const;
  bool HasKnownLambdaInternalLinkage(void) const;
  // HasMemberName: (bool)
  bool HasMoveAssignment(void) const;
  bool HasMoveConstructor(void) const;
  bool HasMutableFields(void) const;
  bool HasNonLiteralTypeFieldsOrBases(void) const;
  bool HasNonTrivialCopyAssignment(void) const;
  bool HasNonTrivialCopyConstructor(void) const;
  bool HasNonTrivialCopyConstructorForCall(void) const;
  bool HasNonTrivialDefaultConstructor(void) const;
  bool HasNonTrivialDestructor(void) const;
  bool HasNonTrivialDestructorForCall(void) const;
  bool HasNonTrivialMoveAssignment(void) const;
  bool HasNonTrivialMoveConstructor(void) const;
  bool HasNonTrivialMoveConstructorForCall(void) const;
  bool HasPrivateFields(void) const;
  bool HasProtectedFields(void) const;
  bool HasSimpleCopyAssignment(void) const;
  bool HasSimpleCopyConstructor(void) const;
  bool HasSimpleDestructor(void) const;
  bool HasSimpleMoveAssignment(void) const;
  bool HasSimpleMoveConstructor(void) const;
  bool HasTrivialCopyAssignment(void) const;
  bool HasTrivialCopyConstructor(void) const;
  bool HasTrivialCopyConstructorForCall(void) const;
  bool HasTrivialDefaultConstructor(void) const;
  bool HasTrivialDestructor(void) const;
  bool HasTrivialDestructorForCall(void) const;
  bool HasTrivialMoveAssignment(void) const;
  bool HasTrivialMoveConstructor(void) const;
  bool HasTrivialMoveConstructorForCall(void) const;
  bool HasUninitializedReferenceMember(void) const;
  bool HasUserDeclaredConstructor(void) const;
  bool HasUserDeclaredCopyAssignment(void) const;
  bool HasUserDeclaredCopyConstructor(void) const;
  bool HasUserDeclaredDestructor(void) const;
  bool HasUserDeclaredMoveAssignment(void) const;
  bool HasUserDeclaredMoveConstructor(void) const;
  bool HasUserDeclaredMoveOperation(void) const;
  bool HasUserProvidedDefaultConstructor(void) const;
  bool HasVariantMembers(void) const;
  bool ImplicitCopyAssignmentHasConstParam(void) const;
  bool ImplicitCopyConstructorHasConstParam(void) const;
  bool IsAbstract(void) const;
  bool IsAggregate(void) const;
  bool IsAnyDestructorNoReturn(void) const;
  bool IsCLike(void) const;
  bool IsCXX11StandardLayout(void) const;
  // IsCurrentInstantiation: (bool)
  bool IsDependentLambda(void) const;
  bool IsDynamicClass(void) const;
  bool IsEffectivelyFinal(void) const;
  bool IsEmpty(void) const;
  bool IsGenericLambda(void) const;
  bool IsInterfaceLike(void) const;
  bool IsLambda(void) const;
  bool IsLiteral(void) const;
  ::pasta::FunctionDecl IsLocalClass(void) const;
  bool IsPOD(void) const;
  bool IsParsingBaseSpecifiers(void) const;
  bool IsPolymorphic(void) const;
  // IsProvablyNotDerivedFrom: (bool)
  bool IsStandardLayout(void) const;
  bool IsStructural(void) const;
  bool IsTrivial(void) const;
  bool IsTriviallyCopyable(void) const;
  // IsVirtuallyDerivedFrom: (bool)
  bool LambdaIsDefaultConstructibleAndAssignable(void) const;
  // LookupInBases: (bool)
  bool MayBeAbstract(void) const;
  bool MayBeDynamicClass(void) const;
  bool MayBeNonDynamicClass(void) const;
  std::vector<::pasta::CXXMethodDecl> Methods(void) const;
  bool NeedsImplicitCopyAssignment(void) const;
  bool NeedsImplicitCopyConstructor(void) const;
  bool NeedsImplicitDefaultConstructor(void) const;
  bool NeedsImplicitDestructor(void) const;
  bool NeedsImplicitMoveAssignment(void) const;
  bool NeedsImplicitMoveConstructor(void) const;
  bool NeedsOverloadResolutionForCopyAssignment(void) const;
  bool NeedsOverloadResolutionForCopyConstructor(void) const;
  bool NeedsOverloadResolutionForDestructor(void) const;
  bool NeedsOverloadResolutionForMoveAssignment(void) const;
  bool NeedsOverloadResolutionForMoveConstructor(void) const;
  bool NullFieldOffsetIsZero(void) const;
  // VirtualBases: (llvm::iterator_range<const clang::CXXBaseSpecifier *>)
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
  ::pasta::TokenRange TokenRange(void) const;
  enum TemplateSpecializationKind SpecializationKind(void) const;
  ::pasta::ClassTemplateDecl SpecializedTemplate(void) const;
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> SpecializedTemplateOrPartial(void) const;
  // TemplateArgs: (const clang::TemplateArgumentList &)
  // TemplateInstantiationArgs: (const clang::TemplateArgumentList &)
  ::pasta::Token TemplateKeywordToken(void) const;
  // TypeAsWritten: (clang::TypeSourceInfo *)
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
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
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMemberTemplate(void) const;
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateParameters: (clang::TemplateParameterList *)
  bool HasAssociatedConstraints(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR(ClassTemplatePartialSpecializationDecl)
};

static_assert(sizeof(Decl) == sizeof(ClassTemplatePartialSpecializationDecl));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_DECL_CONSTRUCTOR
#endif  // PASTA_IN_BOOTSTRAP
