/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#ifdef PASTA_IN_BOOTSTRAP
#  include "DeclBootstrap.h"
#else
#include "Forward.h"

#define PASTA_DECLARE_DERIVED_OPERATORS(base, derived) \
      friend class derived; \
      base(const derived &that_); \
      base(derived &&that_) noexcept;  \
      base &operator=(const derived &);  \
      base &operator=(derived &&) noexcept;

#define PASTA_DECLARE_DEFAULT_CONSTRUCTORS(cls) \
  ~cls(void) = default; \
  cls(const cls &) = default; \
  cls(cls &&) noexcept = default; \
  cls &operator=(const cls &) = default; \
  cls &operator=(cls &&) noexcept = default;

namespace pasta {
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
 private:
  std::shared_ptr<ASTImpl> ast;
  const clang::DeclContext *context;

  inline DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *context_)
      : ast(std::move(ast_)),
        context(context_) {}
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
  // Attrs: (llvm::iterator_range<clang::Attr *const *>)
  AccessSpecifier Access(void) const;
  AccessSpecifier AccessUnsafe(void) const;
  ::pasta::FunctionDecl AsFunction(void) const;
  ::pasta::Token BeginToken(void) const;
  // Body: (clang::Stmt *)
  ::pasta::Decl CanonicalDecl(void) const;
  // DeclContext: (const clang::DeclContext *)
  ::pasta::Token EndToken(void) const;
  // FriendObjectKind: (clang::Decl::FriendObjectKind)
  uint32_t GlobalID(void) const;
  uint32_t IdentifierNamespace(void) const;
  // ImportedOwningModule: (clang::Module *)
  // LexicalDeclContext: (const clang::DeclContext *)
  // LocalOwningModule: (clang::Module *)
  ::pasta::Token Token(void) const;
  // ModuleOwnershipKind: (clang::Decl::ModuleOwnershipKind)
  ::pasta::Decl MostRecentDecl(void) const;
  ::pasta::Decl NextDeclInContext(void) const;
  ::pasta::Decl NonClosureContext(void) const;
  // OwningModule: (clang::Module *)
  uint32_t OwningModuleID(void) const;
  ::pasta::Decl PreviousDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::TranslationUnitDecl TranslationUnitDecl(void) const;
  bool HasAttrs(void) const;
  bool HasBody(void) const;
  bool HasOwningModule(void) const;
  bool HasTagIdentifierNamespace(void) const;
  bool IsCanonicalDecl(void) const;
  bool IsDefinedOutsideFunctionOrMethod(void) const;
  bool IsDeprecated(void) const;
  bool IsFirstDecl(void) const;
  bool IsFromASTFile(void) const;
  bool IsFunctionOrFunctionTemplate(void) const;
  bool IsImplicit(void) const;
  // IsInIdentifierNamespace: (bool)
  bool IsInvalidDecl(void) const;
  bool IsModulePrivate(void) const;
  bool IsTemplateParameter(void) const;
  bool IsThisDeclarationReferenced(void) const;
  bool IsTopLevelDeclInObjCContainer(void) const;
  bool IsUnavailable(void) const;
  bool IsUnconditionallyVisible(void) const;
  // Redecls: (llvm::iterator_range<clang::Decl::redecl_iterator>)
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

 private:
  Decl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit Decl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

class EmptyDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EmptyDecl)
 private:
  EmptyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EmptyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EmptyDecl));

class ExportDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExportDecl)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExportToken(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasBraces(void) const;
 private:
  ExportDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ExportDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ExportDecl));

class ExternCContextDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExternCContextDecl)
 private:
  ExternCContextDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ExternCContextDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ExternCContextDecl));

class FileScopeAsmDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FileScopeAsmDecl)
  ::pasta::Token AsmToken(void) const;
  // AsmString: (const clang::StringLiteral *)
  ::pasta::Token RParenToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 private:
  FileScopeAsmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FileScopeAsmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FileScopeAsmDecl));

class FriendDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendDecl)
  ::pasta::NamedDecl FindFriendDecl(void) const;
  ::pasta::Token FriendToken(void) const;
  // FriendType: (clang::TypeSourceInfo *)
  uint32_t FriendTypeNumTemplateParameterLists(void) const;
  // FriendTypeTemplateParameterList: (clang::TemplateParameterList *)
  ::pasta::TokenRange TokenRange(void) const;
  bool IsUnsupportedFriend(void) const;
 private:
  FriendDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FriendDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FriendDecl));

class FriendTemplateDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FriendTemplateDecl)
  ::pasta::NamedDecl FindFriendDecl(void) const;
  ::pasta::Token FriendToken(void) const;
  // FriendType: (clang::TypeSourceInfo *)
  uint32_t NumTemplateParameters(void) const;
  // TemplateParameterList: (clang::TemplateParameterList *)
 private:
  FriendTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FriendTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FriendTemplateDecl));

class ImportDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImportDecl)
  // ImportedModule: (clang::Module *)
 private:
  ImportDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ImportDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ImportDecl));

class LifetimeExtendedTemporaryDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LifetimeExtendedTemporaryDecl)
  // ChildrenExpr: (llvm::iterator_range<clang::ConstStmtIterator>)
  ::pasta::ValueDecl ExtendingDecl(void) const;
  uint32_t ManglingNumber(void) const;
  // TemporaryExpr: (const clang::Expr *)
  // Value: (clang::APValue *)
 private:
  LifetimeExtendedTemporaryDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LifetimeExtendedTemporaryDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LifetimeExtendedTemporaryDecl));

class LinkageSpecDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LinkageSpecDecl)
  ::pasta::Token EndToken(void) const;
  ::pasta::Token ExternToken(void) const;
  // Language: (clang::LinkageSpecDecl::LanguageIDs)
  ::pasta::Token RBraceToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasBraces(void) const;
 private:
  LinkageSpecDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LinkageSpecDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LinkageSpecDecl));

class NamedDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamedDecl)
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
  // DeclName: (clang::DeclarationName)
  Linkage FormalLinkage(void) const;
  // Identifier: (clang::IdentifierInfo *)
  ::pasta::NamedDecl MostRecentDecl(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  ::pasta::NamedDecl UnderlyingDecl(void) const;
  Visibility Visibility(void) const;
  bool HasExternalFormalLinkage(void) const;
  bool HasLinkageBeenComputed(void) const;
  bool IsCXXClassMember(void) const;
  bool IsExternallyDeclarable(void) const;
  bool IsExternallyVisible(void) const;
 private:
  NamedDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamedDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamedDecl));

class NamespaceAliasDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamespaceAliasDecl)
  ::pasta::Token AliasToken(void) const;
  ::pasta::NamedDecl AliasedNamespace(void) const;
  ::pasta::NamespaceAliasDecl CanonicalDecl(void) const;
  ::pasta::NamespaceDecl Namespace(void) const;
  ::pasta::Token NamespaceToken(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Token TargetNameToken(void) const;
 private:
  NamespaceAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamespaceAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamespaceAliasDecl));

class NamespaceDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NamespaceDecl)
  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
  ::pasta::Token BeginToken(void) const;
  ::pasta::NamespaceDecl CanonicalDecl(void) const;
  ::pasta::Token RBraceToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsAnonymousNamespace(void) const;
  bool IsInline(void) const;
 private:
  NamespaceDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NamespaceDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NamespaceDecl));

class ObjCCompatibleAliasDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCompatibleAliasDecl)
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
 private:
  ObjCCompatibleAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCompatibleAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCompatibleAliasDecl));

class ObjCContainerDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCContainerDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
  // Class_methods: (llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isClassMethod>>)
  // Class_properties: (llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isClassProperty>>)
  // CollectPropertiesToImplement: (void)
  ::pasta::TokenRange AtEndRange(void) const;
  ::pasta::Token AtStartToken(void) const;
  // ClassMethod: (clang::ObjCMethodDecl *)
  // InstanceMethod: (clang::ObjCMethodDecl *)
  ::pasta::TokenRange TokenRange(void) const;
  // Instance_methods: (llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isInstanceMethod>>)
  // Instance_properties: (llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isInstanceProperty>>)
  // Methods: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCMethodDecl>>)
  // Properties: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyDecl>>)
 private:
  ObjCContainerDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCContainerDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCContainerDecl));

class ObjCImplDecl : public ObjCContainerDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  // Property_impls: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyImplDecl>>)
 private:
  ObjCImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCImplDecl));

class ObjCImplementationDecl : public ObjCImplDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCImplementationDecl)
  // Identifier: (clang::IdentifierInfo *)
  ::pasta::Token IvarLBraceToken(void) const;
  ::pasta::Token IvarRBraceToken(void) const;
  std::string_view Name(void) const;
  std::string NameAsString(void) const;
  uint32_t NumIvarInitializers(void) const;
  ::pasta::ObjCInterfaceDecl SuperClass(void) const;
  ::pasta::Token SuperClassToken(void) const;
  bool HasDestructors(void) const;
  bool HasNonZeroConstructors(void) const;
  // Inits: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  // Ivars: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCIvarDecl>>)
 private:
  ObjCImplementationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCImplementationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCImplementationDecl));

class ObjCInterfaceDecl : public ObjCContainerDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCInterfaceDecl)
  // All_referenced_protocols: (llvm::iterator_range<clang::ObjCProtocolDecl *const *>)
  bool DeclaresOrInheritsDesignatedInitializers(void) const;
  ::pasta::ObjCInterfaceDecl CanonicalDecl(void) const;
  ::pasta::ObjCCategoryDecl CategoryListRaw(void) const;
  // CategoryMethod: (clang::ObjCMethodDecl *)
  ::pasta::ObjCInterfaceDecl Definition(void) const;
  ::pasta::Token EndOfDefinitionToken(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  ::pasta::TokenRange TokenRange(void) const;
  // SuperClassTInfo: (clang::TypeSourceInfo *)
  // SuperClassType: (const clang::ObjCObjectType *)
  // TypeForDecl: (const clang::Type *)
  // TypeParamListAsWritten: (clang::ObjCTypeParamList *)
  bool HasDefinition(void) const;
  bool IsImplicitInterfaceDecl(void) const;
  // IsSuperClassOf: (bool)
  bool IsThisDeclarationADefinition(void) const;
  // Ivars: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCIvarDecl>>)
  // Known_categories: (llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownCategory>>)
  // Known_extensions: (llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownExtension>>)
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // LookupPropertyAccessor: (clang::ObjCMethodDecl *)
  // Protocol_locs: (llvm::iterator_range<const clang::SourceLocation *>)
  // Protocols: (llvm::iterator_range<clang::ObjCProtocolDecl *const *>)
  // Visible_categories: (llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleCategory>>)
  // Visible_extensions: (llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleExtension>>)
 private:
  ObjCInterfaceDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCInterfaceDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCInterfaceDecl));

class ObjCMethodDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCMethodDecl)
  ::pasta::Token BeginToken(void) const;
  ::pasta::ObjCMethodDecl CanonicalDecl(void) const;
  ::pasta::ObjCCategoryDecl Category(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::ImplicitParamDecl CmdDecl(void) const;
  ::pasta::Token DeclaratorEndToken(void) const;
  // ImplementationControl: (clang::ObjCMethodDecl::ImplementationControl)
  uint32_t NumSelectorLocs(void) const;
  // ObjCDeclQualifier: (clang::Decl::ObjCDeclQualifier)
  // ParamDecl: (const clang::ParmVarDecl *)
  // ReturnType: (clang::QualType)
  // ReturnTypeSourceInfo: (clang::TypeSourceInfo *)
  // Selector: (clang::Selector)
  // SelectorToken: (clang::SourceLocation)
  ::pasta::Token SelectorStartToken(void) const;
  ::pasta::ImplicitParamDecl SelfDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasBody(void) const;
  bool HasRedeclaration(void) const;
  bool HasRelatedResultType(void) const;
  bool HasSkippedBody(void) const;
  bool IsClassMethod(void) const;
  bool IsDefined(void) const;
  bool IsInstanceMethod(void) const;
  bool IsOptional(void) const;
  bool IsOverriding(void) const;
  bool IsPropertyAccessor(void) const;
  bool IsRedeclaration(void) const;
  bool IsSynthesizedAccessorStub(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsVariadic(void) const;
  // Parameters: (llvm::ArrayRef<clang::ParmVarDecl *>)
 private:
  ObjCMethodDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCMethodDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCMethodDecl));

class ObjCPropertyDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyDecl)
  ::pasta::Token AtToken(void) const;
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  // GetterName: (clang::Selector)
  ::pasta::Token GetterNameToken(void) const;
  ::pasta::Token LParenToken(void) const;
  // PropertyAttributes: (clang::ObjCPropertyAttribute::Kind)
  // PropertyAttributesAsWritten: (clang::ObjCPropertyAttribute::Kind)
  // PropertyImplementation: (clang::ObjCPropertyDecl::PropertyControl)
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  ObjCPropertyQueryKind QueryKind(void) const;
  // SetterKind: (clang::ObjCPropertyDecl::SetterKind)
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  // SetterName: (clang::Selector)
  ::pasta::Token SetterNameToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  // Type: (clang::QualType)
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  bool IsAtomic(void) const;
  bool IsClassProperty(void) const;
  bool IsDirectProperty(void) const;
  bool IsInstanceProperty(void) const;
  bool IsOptional(void) const;
  bool IsReadOnly(void) const;
  bool IsRetaining(void) const;
 private:
  ObjCPropertyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCPropertyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyDecl));

class ObjCPropertyImplDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCPropertyImplDecl)
  ::pasta::Token BeginToken(void) const;
  // GetterCXXConstructor: (clang::Expr *)
  ::pasta::ObjCMethodDecl GetterMethodDecl(void) const;
  ::pasta::ObjCPropertyDecl PropertyDecl(void) const;
  // PropertyImplementation: (clang::ObjCPropertyImplDecl::Kind)
  ::pasta::ObjCIvarDecl PropertyIvarDecl(void) const;
  ::pasta::Token PropertyIvarDeclToken(void) const;
  // SetterCXXAssignment: (clang::Expr *)
  ::pasta::ObjCMethodDecl SetterMethodDecl(void) const;
  bool IsIvarNameSpecified(void) const;
 private:
  ObjCPropertyImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCPropertyImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCPropertyImplDecl));

class ObjCProtocolDecl : public ObjCContainerDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCProtocolDecl)
  ::pasta::ObjCProtocolDecl CanonicalDecl(void) const;
  ::pasta::ObjCProtocolDecl Definition(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  ::pasta::TokenRange TokenRange(void) const;
  bool HasDefinition(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // LookupClassMethod: (clang::ObjCMethodDecl *)
  // LookupInstanceMethod: (clang::ObjCMethodDecl *)
  // Protocol_locs: (llvm::iterator_range<const clang::SourceLocation *>)
  // Protocols: (llvm::iterator_range<clang::ObjCProtocolDecl *const *>)
 private:
  ObjCProtocolDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCProtocolDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCProtocolDecl));

class PragmaCommentDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaCommentDecl)
  std::string_view Arg(void) const;
  PragmaMSCommentKind CommentKind(void) const;
 private:
  PragmaCommentDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit PragmaCommentDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(PragmaCommentDecl));

class PragmaDetectMismatchDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PragmaDetectMismatchDecl)
  std::string_view Name(void) const;
  std::string_view Value(void) const;
 private:
  PragmaDetectMismatchDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit PragmaDetectMismatchDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(PragmaDetectMismatchDecl));

class RequiresExprBodyDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RequiresExprBodyDecl)
 private:
  RequiresExprBodyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RequiresExprBodyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RequiresExprBodyDecl));

class StaticAssertDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(StaticAssertDecl)
  // AssertExpr: (const clang::Expr *)
  // Message: (const clang::StringLiteral *)
  ::pasta::Token RParenToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool IsFailed(void) const;
 private:
  StaticAssertDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit StaticAssertDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(StaticAssertDecl));

class TemplateDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateDecl)
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
 private:
  TemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateDecl));

class TemplateTemplateParmDecl : public TemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateTemplateParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::TemplateTemplateParmDecl, clang::TemplateArgumentLoc *> &)
  // DefaultArgument: (const clang::TemplateArgumentLoc &)
  // ExpansionTemplateParameters: (clang::TemplateParameterList *)
  uint32_t NumExpansionTemplateParameters(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  bool HasDefaultArgument(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  TemplateTemplateParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateTemplateParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateTemplateParmDecl));

class TranslationUnitDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TranslationUnitDecl)
  // ASTContext: (clang::ASTContext &)
  ::pasta::NamespaceDecl AnonymousNamespace(void) const;
 private:
  TranslationUnitDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TranslationUnitDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TranslationUnitDecl));

class TypeDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeDecl)
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
  // TypeForDecl: (const clang::Type *)
 private:
  TypeDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeDecl));

class TypedefNameDecl : public TypeDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypedefNameDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, TypeAliasDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TypedefNameDecl, TypedefDecl)
  ::pasta::TypedefNameDecl CanonicalDecl(void) const;
  // TypeSourceInfo: (clang::TypeSourceInfo *)
  // UnderlyingType: (clang::QualType)
  bool IsModed(void) const;
  bool IsTransparentTag(void) const;
 private:
  TypedefNameDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypedefNameDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypedefNameDecl));

class UnresolvedUsingTypenameDecl : public TypeDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingTypenameDecl)
  ::pasta::UnresolvedUsingTypenameDecl CanonicalDecl(void) const;
  ::pasta::Token EllipsisToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token TypenameToken(void) const;
  ::pasta::Token UsingToken(void) const;
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingTypenameDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UnresolvedUsingTypenameDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingTypenameDecl));

class UsingDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDecl)
  ::pasta::UsingDecl CanonicalDecl(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
  bool HasTypename(void) const;
  bool IsAccessDeclaration(void) const;
  // Shadows: (llvm::iterator_range<clang::UsingDecl::shadow_iterator>)
 private:
  UsingDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingDecl));

class UsingDirectiveDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingDirectiveDecl)
  // CommonAncestor: (const clang::DeclContext *)
  ::pasta::Token IdentLocation(void) const;
  ::pasta::Token NamespaceKeyLocation(void) const;
  ::pasta::NamespaceDecl NominatedNamespace(void) const;
  ::pasta::NamedDecl NominatedNamespaceAsWritten(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::TokenRange TokenRange(void) const;
  ::pasta::Token UsingToken(void) const;
 private:
  UsingDirectiveDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingDirectiveDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingDirectiveDecl));

class UsingPackDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingPackDecl)
  // Expansions: (llvm::ArrayRef<clang::NamedDecl *>)
  ::pasta::UsingPackDecl CanonicalDecl(void) const;
  ::pasta::NamedDecl InstantiatedFromUsingDecl(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 private:
  UsingPackDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingPackDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingPackDecl));

class UsingShadowDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingShadowDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
  ::pasta::UsingShadowDecl CanonicalDecl(void) const;
  ::pasta::UsingShadowDecl NextUsingShadowDecl(void) const;
  ::pasta::NamedDecl TargetDecl(void) const;
 private:
  UsingShadowDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UsingShadowDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UsingShadowDecl));

class ValueDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ValueDecl)
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
  // Type: (clang::QualType)
 private:
  ValueDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ValueDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ValueDecl));

class OMPDeclarativeDirectiveDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclarativeDirectiveDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
 private:
  OMPDeclarativeDirectiveDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclarativeDirectiveDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclarativeDirectiveDecl));

class OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclarativeDirectiveValueDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
 private:
  OMPDeclarativeDirectiveValueDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclarativeDirectiveValueDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclarativeDirectiveValueDecl));

class AccessSpecDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AccessSpecDecl)
  ::pasta::Token AccessSpecifierToken(void) const;
  ::pasta::Token ColonToken(void) const;
  ::pasta::TokenRange TokenRange(void) const;
 private:
  AccessSpecDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit AccessSpecDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(AccessSpecDecl));

class BindingDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BindingDecl)
  // Binding: (clang::Expr *)
 private:
  BindingDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BindingDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BindingDecl));

class BlockDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlockDecl)
  bool BlockMissingReturnType(void) const;
  bool CanAvoidCopyToHeap(void) const;
  // Captures: (llvm::ArrayRef<clang::BlockDecl::Capture>)
  bool CapturesCXXThis(void) const;
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
  bool HasCaptures(void) const;
  bool IsConversionFromLambda(void) const;
  bool IsVariadic(void) const;
  // Parameters: (llvm::ArrayRef<clang::ParmVarDecl *>)
 private:
  BlockDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BlockDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BlockDecl));

class BuiltinTemplateDecl : public TemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinTemplateDecl)
  // BuiltinTemplateKind: (clang::BuiltinTemplateKind)
  ::pasta::TokenRange TokenRange(void) const;
 private:
  BuiltinTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit BuiltinTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(BuiltinTemplateDecl));

class CapturedDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CapturedDecl)
  ::pasta::ImplicitParamDecl ContextParam(void) const;
  uint32_t ContextParamPosition(void) const;
  uint32_t NumParams(void) const;
  // Param: (clang::ImplicitParamDecl *)
  // Parameters: (llvm::ArrayRef<clang::ImplicitParamDecl *>)
 private:
  CapturedDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CapturedDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CapturedDecl));

class ClassScopeFunctionSpecializationDecl : public Decl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassScopeFunctionSpecializationDecl)
  ::pasta::CXXMethodDecl Specialization(void) const;
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  bool HasExplicitTemplateArgs(void) const;
 private:
  ClassScopeFunctionSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassScopeFunctionSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassScopeFunctionSpecializationDecl));

class ConceptDecl : public TemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConceptDecl)
  ::pasta::ConceptDecl CanonicalDecl(void) const;
  // ConstraintExpr: (clang::Expr *)
  ::pasta::TokenRange TokenRange(void) const;
  bool IsTypeConcept(void) const;
 private:
  ConceptDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ConceptDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ConceptDecl));

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstructorUsingShadowDecl)
  bool ConstructsVirtualBase(void) const;
  ::pasta::CXXRecordDecl ConstructedBaseClass(void) const;
  ::pasta::ConstructorUsingShadowDecl ConstructedBaseClassShadowDecl(void) const;
  ::pasta::ConstructorUsingShadowDecl NominatedBaseClassShadowDecl(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
 private:
  ConstructorUsingShadowDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ConstructorUsingShadowDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ConstructorUsingShadowDecl));

class DeclaratorDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeclaratorDecl)
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
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  // TemplateParameterList: (clang::TemplateParameterList *)
  // TrailingRequiresClause: (const clang::Expr *)
  // TypeSourceInfo: (clang::TypeSourceInfo *)
 private:
  DeclaratorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit DeclaratorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(DeclaratorDecl));

class EnumConstantDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumConstantDecl)
  ::pasta::EnumConstantDecl CanonicalDecl(void) const;
  // InitExpr: (const clang::Expr *)
  // InitVal: (const llvm::APSInt &)
 private:
  EnumConstantDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EnumConstantDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EnumConstantDecl));

class FieldDecl : public DeclaratorDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FieldDecl, ObjCIvarDecl)
  // BitWidth: (clang::Expr *)
  ::pasta::FieldDecl CanonicalDecl(void) const;
  // CapturedVLAType: (const clang::VariableArrayType *)
  InClassInitStyle InClassInitStyle(void) const;
  // InClassInitializer: (clang::Expr *)
  ::pasta::RecordDecl Parent(void) const;
  bool HasCapturedVLAType(void) const;
  bool HasInClassInitializer(void) const;
  bool IsBitField(void) const;
  bool IsMutable(void) const;
  bool IsUnnamedBitfield(void) const;
 private:
  FieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FieldDecl));

class FunctionDecl : public DeclaratorDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXDestructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionDecl, CXXMethodDecl)
  bool DoesThisDeclarationHaveABody(void) const;
  // AssociatedConstraints: (void)
  // Body: (clang::Stmt *)
  // CallResultType: (clang::QualType)
  ::pasta::FunctionDecl CanonicalDecl(void) const;
  ConstexprSpecKind ConstexprKind(void) const;
  // DeclaredReturnType: (clang::QualType)
  ::pasta::FunctionDecl Definition(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ExceptionSpecificationType ExceptionSpecType(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // ParamDecl: (const clang::ParmVarDecl *)
  // ReturnType: (clang::QualType)
  StorageClass StorageClass(void) const;
  bool HasBody(void) const;
  bool HasImplicitReturnZero(void) const;
  bool HasInheritedPrototype(void) const;
  bool HasPrototype(void) const;
  bool HasSkippedBody(void) const;
  bool HasWrittenPrototype(void) const;
  bool InstantiationIsPending(void) const;
  bool IsConsteval(void) const;
  bool IsConstexpr(void) const;
  bool IsConstexprSpecified(void) const;
  bool IsDefaulted(void) const;
  bool IsDefined(void) const;
  bool IsDeleted(void) const;
  bool IsDeletedAsWritten(void) const;
  bool IsExplicitlyDefaulted(void) const;
  bool IsFunctionTemplateSpecialization(void) const;
  bool IsInlineSpecified(void) const;
  bool IsInlined(void) const;
  bool IsLateTemplateParsed(void) const;
  bool IsMultiVersion(void) const;
  bool IsOverloadedOperator(void) const;
  bool IsPure(void) const;
  bool IsStatic(void) const;
  bool IsThisDeclarationADefinition(void) const;
  bool IsTrivial(void) const;
  bool IsTrivialForCall(void) const;
  bool IsUserProvided(void) const;
  bool IsVirtualAsWritten(void) const;
  // Parameters: (llvm::ArrayRef<clang::ParmVarDecl *>)
  bool UsesSEHTry(void) const;
  bool WillHaveBody(void) const;
 private:
  FunctionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FunctionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FunctionDecl));

class IndirectFieldDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IndirectFieldDecl)
  // Chain: (llvm::ArrayRef<clang::NamedDecl *>)
  ::pasta::FieldDecl AnonField(void) const;
  ::pasta::IndirectFieldDecl CanonicalDecl(void) const;
  uint32_t ChainingSize(void) const;
  ::pasta::VarDecl VarDecl(void) const;
 private:
  IndirectFieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit IndirectFieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(IndirectFieldDecl));

class LabelDecl : public NamedDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LabelDecl)
  std::string_view MSAsmLabel(void) const;
  ::pasta::TokenRange TokenRange(void) const;
  // Stmt: (clang::LabelStmt *)
  bool IsGnuLocal(void) const;
  bool IsMSAsmLabel(void) const;
  bool IsResolvedMSAsmLabel(void) const;
 private:
  LabelDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit LabelDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(LabelDecl));

class MSGuidDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSGuidDecl)
  // Parts: (clang::MSGuidDeclParts)
 private:
  MSGuidDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit MSGuidDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(MSGuidDecl));

class MSPropertyDecl : public DeclaratorDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MSPropertyDecl)
  // GetterId: (clang::IdentifierInfo *)
  // SetterId: (clang::IdentifierInfo *)
  bool HasGetter(void) const;
  bool HasSetter(void) const;
 private:
  MSPropertyDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit MSPropertyDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(MSPropertyDecl));

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(NonTypeTemplateParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints: (void)
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::NonTypeTemplateParmDecl, clang::Expr *> &)
  // DefaultArgument: (clang::Expr *)
  // ExpansionType: (clang::QualType)
  // ExpansionTypeSourceInfo: (clang::TypeSourceInfo *)
  uint32_t NumExpansionTypes(void) const;
  // PlaceholderTypeConstraint: (clang::Expr *)
  bool HasDefaultArgument(void) const;
  bool HasPlaceholderTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  NonTypeTemplateParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit NonTypeTemplateParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(NonTypeTemplateParmDecl));

class OMPAllocateDecl : public OMPDeclarativeDirectiveDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPAllocateDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
  // Varlists: (llvm::iterator_range<const clang::Expr *const *>)
 private:
  OMPAllocateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPAllocateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPAllocateDecl));

class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareMapperDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
  // MapperVarRef: (const clang::Expr *)
 private:
  OMPDeclareMapperDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclareMapperDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareMapperDecl));

class OMPDeclareReductionDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPDeclareReductionDecl)
  // Combiner: (const clang::Expr *)
  // CombinerIn: (const clang::Expr *)
  // CombinerOut: (const clang::Expr *)
  // InitOrig: (const clang::Expr *)
  // InitPriv: (const clang::Expr *)
  // Initializer: (const clang::Expr *)
  // InitializerKind: (clang::OMPDeclareReductionDecl::InitKind)
 private:
  OMPDeclareReductionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPDeclareReductionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPDeclareReductionDecl));

class OMPRequiresDecl : public OMPDeclarativeDirectiveDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPRequiresDecl)
  // Clauses: (llvm::iterator_range<const clang::OMPClause *const *>)
 private:
  OMPRequiresDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPRequiresDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPRequiresDecl));

class OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPThreadPrivateDecl)
  // Varlists: (llvm::iterator_range<const clang::Expr *const *>)
 private:
  OMPThreadPrivateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPThreadPrivateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPThreadPrivateDecl));

class ObjCAtDefsFieldDecl : public FieldDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCAtDefsFieldDecl)
 private:
  ObjCAtDefsFieldDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCAtDefsFieldDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCAtDefsFieldDecl));

class ObjCCategoryDecl : public ObjCContainerDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCategoryDecl)
  bool IsClassExtension(void) const;
  ::pasta::Token CategoryNameToken(void) const;
  ::pasta::ObjCInterfaceDecl ClassInterface(void) const;
  ::pasta::Token IvarLBraceToken(void) const;
  ::pasta::Token IvarRBraceToken(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategory(void) const;
  ::pasta::ObjCCategoryDecl NextClassCategoryRaw(void) const;
  // ReferencedProtocols: (const clang::ObjCProtocolList &)
  // TypeParamList: (clang::ObjCTypeParamList *)
  // Ivars: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCIvarDecl>>)
  // Protocol_locs: (llvm::iterator_range<const clang::SourceLocation *>)
  // Protocols: (llvm::iterator_range<clang::ObjCProtocolDecl *const *>)
 private:
  ObjCCategoryDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCategoryDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryDecl));

class ObjCCategoryImplDecl : public ObjCImplDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCCategoryImplDecl)
  ::pasta::Token CategoryNameToken(void) const;
 private:
  ObjCCategoryImplDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCCategoryImplDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCCategoryImplDecl));

class ObjCIvarDecl : public FieldDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCIvarDecl)
  // AccessControl: (clang::ObjCIvarDecl::AccessControl)
  // CanonicalAccessControl: (clang::ObjCIvarDecl::AccessControl)
  ::pasta::ObjCIvarDecl NextIvar(void) const;
  bool Synthesize(void) const;
 private:
  ObjCIvarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCIvarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCIvarDecl));

class ObjCTypeParamDecl : public TypedefNameDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCTypeParamDecl)
  ::pasta::Token ColonToken(void) const;
  uint32_t Index(void) const;
  ObjCTypeParamVariance Variance(void) const;
  ::pasta::Token VarianceToken(void) const;
  bool HasExplicitBound(void) const;
 private:
  ObjCTypeParamDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ObjCTypeParamDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ObjCTypeParamDecl));

class RedeclarableTemplateDecl : public TemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RedeclarableTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
  ::pasta::RedeclarableTemplateDecl CanonicalDecl(void) const;
  ::pasta::RedeclarableTemplateDecl InstantiatedFromMemberTemplate(void) const;
  bool IsMemberSpecialization(void) const;
 private:
  RedeclarableTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RedeclarableTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RedeclarableTemplateDecl));

class TagDecl : public TypeDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TagDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, EnumDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(TagDecl, RecordDecl)
  ::pasta::TokenRange BraceRange(void) const;
  ::pasta::TagDecl CanonicalDecl(void) const;
  ::pasta::Token InnerLocStart(void) const;
  std::string_view KindName(void) const;
  uint32_t NumTemplateParameterLists(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  TagTypeKind TagKind(void) const;
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
 private:
  TagDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TagDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TagDecl));

class TemplateParamObjectDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateParamObjectDecl)
  ::pasta::TemplateParamObjectDecl CanonicalDecl(void) const;
  // Value: (const clang::APValue &)
 private:
  TemplateParamObjectDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateParamObjectDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateParamObjectDecl));

class TemplateTypeParmDecl : public TypeDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateTypeParmDecl)
  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints: (void)
  // DefaultArgStorage: (const clang::DefaultArgStorage<clang::TemplateTypeParmDecl, clang::TypeSourceInfo *> &)
  // DefaultArgument: (clang::QualType)
  // DefaultArgumentInfo: (clang::TypeSourceInfo *)
  uint32_t NumExpansionParameters(void) const;
  // TypeConstraint: (const clang::TypeConstraint *)
  bool HasDefaultArgument(void) const;
  bool HasTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool WasDeclaredWithTypename(void) const;
 private:
  TemplateTypeParmDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TemplateTypeParmDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TemplateTypeParmDecl));

class TypeAliasDecl : public TypedefNameDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeAliasDecl)
  ::pasta::TypeAliasTemplateDecl DescribedAliasTemplate(void) const;
 private:
  TypeAliasDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeAliasDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeAliasDecl));

class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeAliasTemplateDecl)
  ::pasta::TypeAliasTemplateDecl CanonicalDecl(void) const;
  ::pasta::TypeAliasTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::TypeAliasTemplateDecl PreviousDecl(void) const;
  ::pasta::TypeAliasDecl TemplatedDecl(void) const;
 private:
  TypeAliasTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypeAliasTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypeAliasTemplateDecl));

class TypedefDecl : public TypedefNameDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypedefDecl)
 private:
  TypedefDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit TypedefDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(TypedefDecl));

class UnresolvedUsingValueDecl : public ValueDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingValueDecl)
  ::pasta::UnresolvedUsingValueDecl CanonicalDecl(void) const;
  ::pasta::Token EllipsisToken(void) const;
  // NameInfo: (clang::DeclarationNameInfo)
  // Qualifier: (clang::NestedNameSpecifier *)
  // QualifierToken: (clang::NestedNameSpecifierLoc)
  ::pasta::Token UsingToken(void) const;
  bool IsAccessDeclaration(void) const;
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingValueDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit UnresolvedUsingValueDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(UnresolvedUsingValueDecl));

class VarDecl : public DeclaratorDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, DecompositionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, ImplicitParamDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, OMPCapturedExprDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, ParmVarDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
  ::pasta::VarDecl ActingDefinition(void) const;
  // AnyInitializer: (const clang::Expr *)
  ::pasta::VarDecl CanonicalDecl(void) const;
  // Init: (const clang::Expr *)
  // InitStyle: (clang::VarDecl::InitializationStyle)
  ::pasta::VarDecl InitializingDeclaration(void) const;
  StorageClass StorageClass(void) const;
  StorageDuration StorageDuration(void) const;
  ThreadStorageClassSpecifier TSCSpec(void) const;
  // HasDefinition: (clang::VarDecl::DefinitionKind)
  bool HasExternalStorage(void) const;
  bool HasGlobalStorage(void) const;
  bool HasLocalStorage(void) const;
  bool IsARCPseudoStrong(void) const;
  bool IsCXXForRangeDecl(void) const;
  bool IsConstexpr(void) const;
  bool IsDirectInit(void) const;
  bool IsExceptionVariable(void) const;
  bool IsFileVarDecl(void) const;
  bool IsFunctionOrMethodVarDecl(void) const;
  bool IsInitCapture(void) const;
  bool IsInline(void) const;
  bool IsInlineSpecified(void) const;
  bool IsLocalVarDecl(void) const;
  bool IsLocalVarDeclOrParm(void) const;
  bool IsNRVOVariable(void) const;
  bool IsObjCForDecl(void) const;
  bool IsPreviousDeclInSameBlockScope(void) const;
  bool IsStaticDataMember(void) const;
  bool IsStaticLocal(void) const;
  // IsThisDeclarationADefinition: (clang::VarDecl::DefinitionKind)
  bool IsThisDeclarationADemotedDefinition(void) const;
 private:
  VarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarDecl));

class VarTemplateDecl : public RedeclarableTemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplateDecl)
  ::pasta::VarTemplateDecl CanonicalDecl(void) const;
  ::pasta::VarTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::VarTemplateDecl MostRecentDecl(void) const;
  ::pasta::VarTemplateDecl PreviousDecl(void) const;
  ::pasta::VarDecl TemplatedDecl(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations: (llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::VarTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::VarTemplateSpecializationDecl>, clang::VarTemplateSpecializationDecl>>)
 private:
  VarTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplateDecl));

class VarTemplateSpecializationDecl : public VarDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
  // Profile: (void)
  ::pasta::Token ExternToken(void) const;
  // InstantiatedFrom: (llvm::PointerUnion<clang::VarTemplateDecl *, clang::VarTemplatePartialSpecializationDecl *>)
  ::pasta::Token PointOfInstantiation(void) const;
  TemplateSpecializationKind SpecializationKind(void) const;
  // SpecializedTemplateOrPartial: (llvm::PointerUnion<clang::VarTemplateDecl *, clang::VarTemplatePartialSpecializationDecl *>)
  // TemplateArgs: (const clang::TemplateArgumentList &)
  // TemplateArgsInfo: (const clang::TemplateArgumentListInfo &)
  // TemplateInstantiationArgs: (const clang::TemplateArgumentList &)
  ::pasta::Token TemplateKeywordToken(void) const;
  // TypeAsWritten: (clang::TypeSourceInfo *)
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  VarTemplateSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplateSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplateSpecializationDecl));

class CXXDeductionGuideDecl : public FunctionDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDeductionGuideDecl)
  ::pasta::TemplateDecl DeducedTemplate(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsCopyDeductionCandidate(void) const;
  bool IsExplicit(void) const;
 private:
  CXXDeductionGuideDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXDeductionGuideDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXDeductionGuideDecl));

class CXXMethodDecl : public FunctionDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXMethodDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXConversionDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
  ::pasta::CXXMethodDecl CanonicalDecl(void) const;
  // CorrespondingMethodDeclaredInClass: (const clang::CXXMethodDecl *)
  // CorrespondingMethodInClass: (const clang::CXXMethodDecl *)
  // DevirtualizedMethod: (const clang::CXXMethodDecl *)
  // MethodQualifiers: (clang::Qualifiers)
  ::pasta::CXXMethodDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl Parent(void) const;
  RefQualifierKind RefQualifier(void) const;
  bool IsConst(void) const;
  bool IsInstance(void) const;
  bool IsVirtual(void) const;
  bool IsVolatile(void) const;
 private:
  CXXMethodDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXMethodDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXMethodDecl));

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplateDecl)
  ::pasta::ClassTemplateDecl CanonicalDecl(void) const;
  ::pasta::ClassTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::ClassTemplateDecl MostRecentDecl(void) const;
  ::pasta::ClassTemplateDecl PreviousDecl(void) const;
  ::pasta::CXXRecordDecl TemplatedDecl(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations: (llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::ClassTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::ClassTemplateSpecializationDecl>, clang::ClassTemplateSpecializationDecl>>)
 private:
  ClassTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateDecl));

class DecompositionDecl : public VarDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DecompositionDecl)
  // Bindings: (llvm::ArrayRef<clang::BindingDecl *>)
 private:
  DecompositionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit DecompositionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(DecompositionDecl));

class EnumDecl : public TagDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumDecl)
  // Enumerators: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::EnumConstantDecl>>)
  ::pasta::EnumDecl CanonicalDecl(void) const;
  ::pasta::EnumDecl Definition(void) const;
  // IntegerType: (clang::QualType)
  // IntegerTypeSourceInfo: (clang::TypeSourceInfo *)
  // MemberSpecializationInfo: (clang::MemberSpecializationInfo *)
  ::pasta::EnumDecl MostRecentDecl(void) const;
  uint32_t NumNegativeBits(void) const;
  uint32_t NumPositiveBits(void) const;
  ::pasta::EnumDecl PreviousDecl(void) const;
  // PromotionType: (clang::QualType)
  bool IsComplete(void) const;
  bool IsFixed(void) const;
  bool IsScoped(void) const;
  bool IsScopedUsingClassTag(void) const;
 private:
  EnumDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit EnumDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(EnumDecl));

class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionTemplateDecl)
  ::pasta::FunctionTemplateDecl CanonicalDecl(void) const;
  ::pasta::FunctionTemplateDecl InstantiatedFromMemberTemplate(void) const;
  ::pasta::FunctionTemplateDecl MostRecentDecl(void) const;
  ::pasta::FunctionTemplateDecl PreviousDecl(void) const;
  ::pasta::FunctionDecl TemplatedDecl(void) const;
  bool IsAbbreviated(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations: (llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::FunctionTemplateSpecializationInfo, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::FunctionTemplateSpecializationInfo>, clang::FunctionDecl>>)
 private:
  FunctionTemplateDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit FunctionTemplateDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(FunctionTemplateDecl));

class ImplicitParamDecl : public VarDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ImplicitParamDecl)
  // ParameterKind: (clang::ImplicitParamDecl::ImplicitParamKind)
 private:
  ImplicitParamDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ImplicitParamDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ImplicitParamDecl));

class OMPCapturedExprDecl : public VarDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(OMPCapturedExprDecl)
 private:
  OMPCapturedExprDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit OMPCapturedExprDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(OMPCapturedExprDecl));

class ParmVarDecl : public VarDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParmVarDecl)
  // DefaultArg: (const clang::Expr *)
  uint32_t FunctionScopeDepth(void) const;
  uint32_t FunctionScopeIndex(void) const;
  // ObjCDeclQualifier: (clang::Decl::ObjCDeclQualifier)
  // UninstantiatedDefaultArg: (const clang::Expr *)
  bool HasInheritedDefaultArg(void) const;
  bool HasUninstantiatedDefaultArg(void) const;
  bool HasUnparsedDefaultArg(void) const;
  bool IsKNRPromoted(void) const;
  bool IsObjCMethodParameter(void) const;
 private:
  ParmVarDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ParmVarDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ParmVarDecl));

class RecordDecl : public TagDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
  bool CanPassInRegisters(void) const;
  // Fields: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::FieldDecl>>)
  // ArgPassingRestrictions: (clang::RecordDecl::ArgPassingKind)
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
  bool IsNonTrivialToPrimitiveCopy(void) const;
  bool IsNonTrivialToPrimitiveDefaultInitialize(void) const;
  bool IsNonTrivialToPrimitiveDestroy(void) const;
  bool IsParamDestroyedInCallee(void) const;
 private:
  RecordDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit RecordDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(RecordDecl));

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VarTemplatePartialSpecializationDecl)
  // Profile: (void)
  // AssociatedConstraints: (void)
  ::pasta::VarTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateParameters: (clang::TemplateParameterList *)
  bool HasAssociatedConstraints(void) const;
 private:
  VarTemplatePartialSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit VarTemplatePartialSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(VarTemplatePartialSpecializationDecl));

class CXXConstructorDecl : public CXXMethodDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConstructorDecl)
  ::pasta::CXXConstructorDecl CanonicalDecl(void) const;
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  // InheritedConstructor: (clang::InheritedConstructor)
  uint32_t NumCtorInitializers(void) const;
  // Inits: (llvm::iterator_range<clang::CXXCtorInitializer *const *>)
  bool IsCopyConstructor(void) const;
  bool IsCopyOrMoveConstructor(void) const;
  bool IsDelegatingConstructor(void) const;
  bool IsExplicit(void) const;
  bool IsInheritingConstructor(void) const;
  bool IsMoveConstructor(void) const;
 private:
  CXXConstructorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXConstructorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXConstructorDecl));

class CXXConversionDecl : public CXXMethodDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXConversionDecl)
  ::pasta::CXXConversionDecl CanonicalDecl(void) const;
  // ConversionType: (clang::QualType)
  // ExplicitSpecifier: (const clang::ExplicitSpecifier)
  bool IsExplicit(void) const;
 private:
  CXXConversionDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXConversionDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXConversionDecl));

class CXXDestructorDecl : public CXXMethodDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXDestructorDecl)
  ::pasta::CXXDestructorDecl CanonicalDecl(void) const;
  ::pasta::FunctionDecl OperatorDelete(void) const;
  // OperatorDeleteThisArg: (clang::Expr *)
 private:
  CXXDestructorDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXDestructorDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXDestructorDecl));

class CXXRecordDecl : public RecordDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(CXXRecordDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
  bool AllowConstDefaultInit(void) const;
  // Bases: (llvm::iterator_range<const clang::CXXBaseSpecifier *>)
  // Captures: (llvm::iterator_range<const clang::LambdaCapture *>)
  // Constructors: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXConstructorDecl>>)
  bool DefaultedCopyConstructorIsDeleted(void) const;
  bool DefaultedDefaultConstructorIsConstexpr(void) const;
  bool DefaultedDestructorIsConstexpr(void) const;
  bool DefaultedDestructorIsDeleted(void) const;
  bool DefaultedMoveConstructorIsDeleted(void) const;
  // Friends: (llvm::iterator_range<clang::CXXRecordDecl::friend_iterator>)
  ::pasta::CXXRecordDecl CanonicalDecl(void) const;
  ::pasta::CXXRecordDecl Definition(void) const;
  LambdaCaptureDefault LambdaCaptureDefault(void) const;
  uint32_t LambdaManglingNumber(void) const;
  // LambdaTypeInfo: (clang::TypeSourceInfo *)
  ::pasta::CXXRecordDecl MostRecentDecl(void) const;
  ::pasta::CXXRecordDecl MostRecentNonInjectedDecl(void) const;
  uint32_t NumBases(void) const;
  uint32_t NumVBases(void) const;
  ::pasta::CXXRecordDecl PreviousDecl(void) const;
  bool HasConstexprDefaultConstructor(void) const;
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
  bool IsCXX11StandardLayout(void) const;
  bool IsDependentLambda(void) const;
  bool IsDynamicClass(void) const;
  bool IsEmpty(void) const;
  bool IsLambda(void) const;
  bool IsLiteral(void) const;
  ::pasta::FunctionDecl IsLocalClass(void) const;
  bool IsPOD(void) const;
  bool IsParsingBaseSpecifiers(void) const;
  bool IsPolymorphic(void) const;
  bool IsStandardLayout(void) const;
  bool IsStructural(void) const;
  bool IsTrivial(void) const;
  bool MayBeDynamicClass(void) const;
  bool MayBeNonDynamicClass(void) const;
  // Methods: (llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXMethodDecl>>)
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
  // VirtualBases: (llvm::iterator_range<const clang::CXXBaseSpecifier *>)
 private:
  CXXRecordDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit CXXRecordDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(CXXRecordDecl));

class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplateSpecializationDecl)
  PASTA_DECLARE_DERIVED_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
  // Profile: (void)
  ::pasta::Token ExternToken(void) const;
  // InstantiatedFrom: (llvm::PointerUnion<clang::ClassTemplateDecl *, clang::ClassTemplatePartialSpecializationDecl *>)
  ::pasta::Token PointOfInstantiation(void) const;
  TemplateSpecializationKind SpecializationKind(void) const;
  // SpecializedTemplateOrPartial: (llvm::PointerUnion<clang::ClassTemplateDecl *, clang::ClassTemplatePartialSpecializationDecl *>)
  // TemplateArgs: (const clang::TemplateArgumentList &)
  // TemplateInstantiationArgs: (const clang::TemplateArgumentList &)
  ::pasta::Token TemplateKeywordToken(void) const;
  // TypeAsWritten: (clang::TypeSourceInfo *)
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  ClassTemplateSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplateSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplateSpecializationDecl));

class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ClassTemplatePartialSpecializationDecl)
  // Profile: (void)
  // AssociatedConstraints: (void)
  // InjectedSpecializationType: (clang::QualType)
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMember(void) const;
  ::pasta::ClassTemplatePartialSpecializationDecl InstantiatedFromMemberTemplate(void) const;
  // TemplateArgsAsWritten: (const clang::ASTTemplateArgumentListInfo *)
  // TemplateParameters: (clang::TemplateParameterList *)
  bool HasAssociatedConstraints(void) const;
 private:
  ClassTemplatePartialSpecializationDecl(void) = delete;

  friend class DeclBuilder;
  friend class AST;
  friend class ASTImpl;

 protected:
  explicit ClassTemplatePartialSpecializationDecl(
      std::shared_ptr<ASTImpl> ast_,
      const ::clang::Decl *decl_);
};

static_assert(sizeof(Decl) == sizeof(ClassTemplatePartialSpecializationDecl));

}  // namespace pasta
#undef PASTA_DECLARE_DERIVED_OPERATORS
#undef PASTA_DECLARE_DEFAULT_CONSTRUCTORS
#endif  // PASTA_IN_BOOTSTRAP
