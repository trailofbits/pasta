/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <memory>

namespace clang {
class AccessSpecDecl;
class BindingDecl;
class BlockDecl;
class BuiltinTemplateDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class CapturedDecl;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class Decl;
class DeclContext;
class DeclaratorDecl;
class DecompositionDecl;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class ExportDecl;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FriendDecl;
class FriendTemplateDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class ImplicitParamDecl;
class ImportDecl;
class IndirectFieldDecl;
class LabelDecl;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NonTypeTemplateParmDecl;
class OMPAllocateDecl;
class OMPCapturedExprDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCProtocolDecl;
class ObjCTypeParamDecl;
class ParmVarDecl;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class RecordDecl;
class RedeclarableTemplateDecl;
class RequiresExprBodyDecl;
class StaticAssertDecl;
class TagDecl;
class TemplateDecl;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TranslationUnitDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingDirectiveDecl;
class UsingPackDecl;
class UsingShadowDecl;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
}  // namespace clang
namespace pasta {
class AST;
class ASTImpl;
class DeclBase {
 public:
  ~DeclBase(void) = default;
  DeclBase(const DeclBase &) = default;
  DeclBase(DeclBase &&) noexcept = default;
  DeclBase &operator=(const DeclBase &) = default;
  DeclBase &operator=(DeclBase &&) noexcept = default;

 protected:
  DeclBase(void) = delete;

  friend class AST;
  friend class ASTImpl;

  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, const ::clang::Decl *decl_)
      : ast(ast_) {
    u.Decl = decl_;
  }
  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, const ::clang::DeclContext *dc_, int)
      : ast(ast_) {
    u.DeclContext = dc_;
  }

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
    const ::clang::DeclContext *DeclContext;
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
  } u;
};

class AccessSpecDecl;
class BindingDecl;
class BlockDecl;
class BuiltinTemplateDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class CapturedDecl;
class ClassScopeFunctionSpecializationDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class Decl;
class DeclContext;
class DeclaratorDecl;
class DecompositionDecl;
class EmptyDecl;
class EnumConstantDecl;
class EnumDecl;
class ExportDecl;
class ExternCContextDecl;
class FieldDecl;
class FileScopeAsmDecl;
class FriendDecl;
class FriendTemplateDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class ImplicitParamDecl;
class ImportDecl;
class IndirectFieldDecl;
class LabelDecl;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NonTypeTemplateParmDecl;
class OMPAllocateDecl;
class OMPCapturedExprDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCProtocolDecl;
class ObjCTypeParamDecl;
class ParmVarDecl;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class RecordDecl;
class RedeclarableTemplateDecl;
class RequiresExprBodyDecl;
class StaticAssertDecl;
class TagDecl;
class TemplateDecl;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class TranslationUnitDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingDirectiveDecl;
class UsingPackDecl;
class UsingShadowDecl;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
class Decl : public DeclBase {
 public:
  ~Decl(void) = default;
  Decl(const Decl &) = default;
  Decl(Decl &&) noexcept = default;
  Decl &operator=(const Decl &) = default;
  Decl &operator=(Decl &&) noexcept = default;

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
  // IsInIdentifierNamespace
  bool IsInvalidDecl(void) const;
  bool IsModulePrivate(void) const;
  bool IsTemplateParameter(void) const;
  bool IsThisDeclarationReferenced(void) const;
  bool IsTopLevelDeclInObjCContainer(void) const;
  bool IsUnavailable(void) const;
  bool IsUnconditionallyVisible(void) const;
  // Redecls
 private:
  Decl(void) = delete;

  Decl(const DeclBase &) = delete;
  Decl(DeclBase &&) noexcept = delete;
  Decl &operator=(const DeclBase &) = delete;
  Decl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  Decl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::Decl *decl_);
};

class DeclContext : public DeclBase {
 public:
  ~DeclContext(void) = default;
  DeclContext(const DeclContext &) = default;
  DeclContext(DeclContext &&) noexcept = default;
  DeclContext &operator=(const DeclContext &) = default;
  DeclContext &operator=(DeclContext &&) noexcept = default;

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
  bool HasExternalLexicalStorage(void) const;
  bool HasExternalVisibleStorage(void) const;
  bool IsClosure(void) const;
  // IsDeclInLexicalTraversal
  bool IsFileContext(void) const;
  bool IsFunctionOrMethod(void) const;
  bool IsLookupContext(void) const;
  bool IsNamespace(void) const;
  bool IsObjCContainer(void) const;
  bool IsRecord(void) const;
  bool IsTranslationUnit(void) const;
  // Noload_decls
  bool ShouldUseQualifiedLookup(void) const;
 private:
  DeclContext(void) = delete;

  DeclContext(const DeclBase &) = delete;
  DeclContext(DeclBase &&) noexcept = delete;
  DeclContext &operator=(const DeclBase &) = delete;
  DeclContext &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  DeclContext(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::DeclContext *decl_);
};

class EmptyDecl : public Decl {
 public:
  ~EmptyDecl(void) = default;
  EmptyDecl(const EmptyDecl &) = default;
  EmptyDecl(EmptyDecl &&) noexcept = default;
  EmptyDecl &operator=(const EmptyDecl &) = default;
  EmptyDecl &operator=(EmptyDecl &&) noexcept = default;

 private:
  EmptyDecl(void) = delete;

  EmptyDecl(const DeclBase &) = delete;
  EmptyDecl(DeclBase &&) noexcept = delete;
  EmptyDecl &operator=(const DeclBase &) = delete;
  EmptyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  EmptyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::EmptyDecl *decl_);
};

class ExportDecl : public Decl, public DeclContext {
 public:
  ~ExportDecl(void) = default;
  ExportDecl(const ExportDecl &) = default;
  ExportDecl(ExportDecl &&) noexcept = default;
  ExportDecl &operator=(const ExportDecl &) = default;
  ExportDecl &operator=(ExportDecl &&) noexcept = default;

  // EndToken
  // ExportToken
  // RBraceToken
  // TokenRange
  bool HasBraces(void) const;
 private:
  ExportDecl(void) = delete;

  ExportDecl(const DeclBase &) = delete;
  ExportDecl(DeclBase &&) noexcept = delete;
  ExportDecl &operator=(const DeclBase &) = delete;
  ExportDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ExportDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ExportDecl *decl_);
};

class ExternCContextDecl : public Decl, public DeclContext {
 public:
  ~ExternCContextDecl(void) = default;
  ExternCContextDecl(const ExternCContextDecl &) = default;
  ExternCContextDecl(ExternCContextDecl &&) noexcept = default;
  ExternCContextDecl &operator=(const ExternCContextDecl &) = default;
  ExternCContextDecl &operator=(ExternCContextDecl &&) noexcept = default;

 private:
  ExternCContextDecl(void) = delete;

  ExternCContextDecl(const DeclBase &) = delete;
  ExternCContextDecl(DeclBase &&) noexcept = delete;
  ExternCContextDecl &operator=(const DeclBase &) = delete;
  ExternCContextDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ExternCContextDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ExternCContextDecl *decl_);
};

class FileScopeAsmDecl : public Decl {
 public:
  ~FileScopeAsmDecl(void) = default;
  FileScopeAsmDecl(const FileScopeAsmDecl &) = default;
  FileScopeAsmDecl(FileScopeAsmDecl &&) noexcept = default;
  FileScopeAsmDecl &operator=(const FileScopeAsmDecl &) = default;
  FileScopeAsmDecl &operator=(FileScopeAsmDecl &&) noexcept = default;

  // AsmToken
  // AsmString
  // RParenToken
  // TokenRange
 private:
  FileScopeAsmDecl(void) = delete;

  FileScopeAsmDecl(const DeclBase &) = delete;
  FileScopeAsmDecl(DeclBase &&) noexcept = delete;
  FileScopeAsmDecl &operator=(const DeclBase &) = delete;
  FileScopeAsmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FileScopeAsmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FileScopeAsmDecl *decl_);
};

class FriendDecl : public Decl {
 public:
  ~FriendDecl(void) = default;
  FriendDecl(const FriendDecl &) = default;
  FriendDecl(FriendDecl &&) noexcept = default;
  FriendDecl &operator=(const FriendDecl &) = default;
  FriendDecl &operator=(FriendDecl &&) noexcept = default;

  // FriendDecl
  // FriendToken
  // FriendType
  // FriendTypeNumTemplateParameterLists
  // FriendTypeTemplateParameterList
  // TokenRange
  bool IsUnsupportedFriend(void) const;
 private:
  FriendDecl(void) = delete;

  FriendDecl(const DeclBase &) = delete;
  FriendDecl(DeclBase &&) noexcept = delete;
  FriendDecl &operator=(const DeclBase &) = delete;
  FriendDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FriendDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FriendDecl *decl_);
};

class FriendTemplateDecl : public Decl {
 public:
  ~FriendTemplateDecl(void) = default;
  FriendTemplateDecl(const FriendTemplateDecl &) = default;
  FriendTemplateDecl(FriendTemplateDecl &&) noexcept = default;
  FriendTemplateDecl &operator=(const FriendTemplateDecl &) = default;
  FriendTemplateDecl &operator=(FriendTemplateDecl &&) noexcept = default;

  // FriendDecl
  // FriendToken
  // FriendType
  // NumTemplateParameters
  // TemplateParameterList
 private:
  FriendTemplateDecl(void) = delete;

  FriendTemplateDecl(const DeclBase &) = delete;
  FriendTemplateDecl(DeclBase &&) noexcept = delete;
  FriendTemplateDecl &operator=(const DeclBase &) = delete;
  FriendTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FriendTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FriendTemplateDecl *decl_);
};

class ImportDecl : public Decl {
 public:
  ~ImportDecl(void) = default;
  ImportDecl(const ImportDecl &) = default;
  ImportDecl(ImportDecl &&) noexcept = default;
  ImportDecl &operator=(const ImportDecl &) = default;
  ImportDecl &operator=(ImportDecl &&) noexcept = default;

  // ImportedModule
 private:
  ImportDecl(void) = delete;

  ImportDecl(const DeclBase &) = delete;
  ImportDecl(DeclBase &&) noexcept = delete;
  ImportDecl &operator=(const DeclBase &) = delete;
  ImportDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ImportDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ImportDecl *decl_);
};

class LifetimeExtendedTemporaryDecl : public Decl {
 public:
  ~LifetimeExtendedTemporaryDecl(void) = default;
  LifetimeExtendedTemporaryDecl(const LifetimeExtendedTemporaryDecl &) = default;
  LifetimeExtendedTemporaryDecl(LifetimeExtendedTemporaryDecl &&) noexcept = default;
  LifetimeExtendedTemporaryDecl &operator=(const LifetimeExtendedTemporaryDecl &) = default;
  LifetimeExtendedTemporaryDecl &operator=(LifetimeExtendedTemporaryDecl &&) noexcept = default;

  // ChildrenExpr
  // ExtendingDecl
  // ManglingNumber
  // TemporaryExpr
  // Value
 private:
  LifetimeExtendedTemporaryDecl(void) = delete;

  LifetimeExtendedTemporaryDecl(const DeclBase &) = delete;
  LifetimeExtendedTemporaryDecl(DeclBase &&) noexcept = delete;
  LifetimeExtendedTemporaryDecl &operator=(const DeclBase &) = delete;
  LifetimeExtendedTemporaryDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  LifetimeExtendedTemporaryDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::LifetimeExtendedTemporaryDecl *decl_);
};

class LinkageSpecDecl : public Decl, public DeclContext {
 public:
  ~LinkageSpecDecl(void) = default;
  LinkageSpecDecl(const LinkageSpecDecl &) = default;
  LinkageSpecDecl(LinkageSpecDecl &&) noexcept = default;
  LinkageSpecDecl &operator=(const LinkageSpecDecl &) = default;
  LinkageSpecDecl &operator=(LinkageSpecDecl &&) noexcept = default;

  // EndToken
  // ExternToken
  // Language
  // RBraceToken
  // TokenRange
  bool HasBraces(void) const;
 private:
  LinkageSpecDecl(void) = delete;

  LinkageSpecDecl(const DeclBase &) = delete;
  LinkageSpecDecl(DeclBase &&) noexcept = delete;
  LinkageSpecDecl &operator=(const DeclBase &) = delete;
  LinkageSpecDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  LinkageSpecDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::LinkageSpecDecl *decl_);
};

class NamedDecl : public Decl {
 public:
  ~NamedDecl(void) = default;
  NamedDecl(const NamedDecl &) = default;
  NamedDecl(NamedDecl &&) noexcept = default;
  NamedDecl &operator=(const NamedDecl &) = default;
  NamedDecl &operator=(NamedDecl &&) noexcept = default;

  // DeclName
  // FormalLinkage
  // Identifier
  // MostRecentDecl
  // Name
  // NameAsString
  // UnderlyingDecl
  // Visibility
  bool HasExternalFormalLinkage(void) const;
  bool HasLinkageBeenComputed(void) const;
  bool IsCXXClassMember(void) const;
  bool IsExternallyDeclarable(void) const;
  bool IsExternallyVisible(void) const;
 private:
  NamedDecl(void) = delete;

  NamedDecl(const DeclBase &) = delete;
  NamedDecl(DeclBase &&) noexcept = delete;
  NamedDecl &operator=(const DeclBase &) = delete;
  NamedDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  NamedDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::NamedDecl *decl_);
};

class NamespaceAliasDecl : public NamedDecl {
 public:
  ~NamespaceAliasDecl(void) = default;
  NamespaceAliasDecl(const NamespaceAliasDecl &) = default;
  NamespaceAliasDecl(NamespaceAliasDecl &&) noexcept = default;
  NamespaceAliasDecl &operator=(const NamespaceAliasDecl &) = default;
  NamespaceAliasDecl &operator=(NamespaceAliasDecl &&) noexcept = default;

  // AliasToken
  // AliasedNamespace
  // CanonicalDecl
  // Namespace
  // NamespaceToken
  // Qualifier
  // QualifierToken
  // TokenRange
  // TargetNameToken
 private:
  NamespaceAliasDecl(void) = delete;

  NamespaceAliasDecl(const DeclBase &) = delete;
  NamespaceAliasDecl(DeclBase &&) noexcept = delete;
  NamespaceAliasDecl &operator=(const DeclBase &) = delete;
  NamespaceAliasDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  NamespaceAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::NamespaceAliasDecl *decl_);
};

class NamespaceDecl : public NamedDecl, public DeclContext {
 public:
  ~NamespaceDecl(void) = default;
  NamespaceDecl(const NamespaceDecl &) = default;
  NamespaceDecl(NamespaceDecl &&) noexcept = default;
  NamespaceDecl &operator=(const NamespaceDecl &) = default;
  NamespaceDecl &operator=(NamespaceDecl &&) noexcept = default;

  // AnonymousNamespace
  // BeginToken
  // CanonicalDecl
  // RBraceToken
  // TokenRange
  bool IsAnonymousNamespace(void) const;
  bool IsInline(void) const;
 private:
  NamespaceDecl(void) = delete;

  NamespaceDecl(const DeclBase &) = delete;
  NamespaceDecl(DeclBase &&) noexcept = delete;
  NamespaceDecl &operator=(const DeclBase &) = delete;
  NamespaceDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  NamespaceDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::NamespaceDecl *decl_);
};

class OMPAllocateDecl : public Decl {
 public:
  ~OMPAllocateDecl(void) = default;
  OMPAllocateDecl(const OMPAllocateDecl &) = default;
  OMPAllocateDecl(OMPAllocateDecl &&) noexcept = default;
  OMPAllocateDecl &operator=(const OMPAllocateDecl &) = default;
  OMPAllocateDecl &operator=(OMPAllocateDecl &&) noexcept = default;

  // Clauselists
  // Varlists
 private:
  OMPAllocateDecl(void) = delete;

  OMPAllocateDecl(const DeclBase &) = delete;
  OMPAllocateDecl(DeclBase &&) noexcept = delete;
  OMPAllocateDecl &operator=(const DeclBase &) = delete;
  OMPAllocateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPAllocateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPAllocateDecl *decl_);
};

class OMPRequiresDecl : public Decl {
 public:
  ~OMPRequiresDecl(void) = default;
  OMPRequiresDecl(const OMPRequiresDecl &) = default;
  OMPRequiresDecl(OMPRequiresDecl &&) noexcept = default;
  OMPRequiresDecl &operator=(const OMPRequiresDecl &) = default;
  OMPRequiresDecl &operator=(OMPRequiresDecl &&) noexcept = default;

  // Clauselists
 private:
  OMPRequiresDecl(void) = delete;

  OMPRequiresDecl(const DeclBase &) = delete;
  OMPRequiresDecl(DeclBase &&) noexcept = delete;
  OMPRequiresDecl &operator=(const DeclBase &) = delete;
  OMPRequiresDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPRequiresDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPRequiresDecl *decl_);
};

class OMPThreadPrivateDecl : public Decl {
 public:
  ~OMPThreadPrivateDecl(void) = default;
  OMPThreadPrivateDecl(const OMPThreadPrivateDecl &) = default;
  OMPThreadPrivateDecl(OMPThreadPrivateDecl &&) noexcept = default;
  OMPThreadPrivateDecl &operator=(const OMPThreadPrivateDecl &) = default;
  OMPThreadPrivateDecl &operator=(OMPThreadPrivateDecl &&) noexcept = default;

  // Varlists
 private:
  OMPThreadPrivateDecl(void) = delete;

  OMPThreadPrivateDecl(const DeclBase &) = delete;
  OMPThreadPrivateDecl(DeclBase &&) noexcept = delete;
  OMPThreadPrivateDecl &operator=(const DeclBase &) = delete;
  OMPThreadPrivateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPThreadPrivateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPThreadPrivateDecl *decl_);
};

class ObjCCompatibleAliasDecl : public NamedDecl {
 public:
  ~ObjCCompatibleAliasDecl(void) = default;
  ObjCCompatibleAliasDecl(const ObjCCompatibleAliasDecl &) = default;
  ObjCCompatibleAliasDecl(ObjCCompatibleAliasDecl &&) noexcept = default;
  ObjCCompatibleAliasDecl &operator=(const ObjCCompatibleAliasDecl &) = default;
  ObjCCompatibleAliasDecl &operator=(ObjCCompatibleAliasDecl &&) noexcept = default;

  // ClassInterface
 private:
  ObjCCompatibleAliasDecl(void) = delete;

  ObjCCompatibleAliasDecl(const DeclBase &) = delete;
  ObjCCompatibleAliasDecl(DeclBase &&) noexcept = delete;
  ObjCCompatibleAliasDecl &operator=(const DeclBase &) = delete;
  ObjCCompatibleAliasDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCCompatibleAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCCompatibleAliasDecl *decl_);
};

class ObjCContainerDecl : public NamedDecl, public DeclContext {
 public:
  ~ObjCContainerDecl(void) = default;
  ObjCContainerDecl(const ObjCContainerDecl &) = default;
  ObjCContainerDecl(ObjCContainerDecl &&) noexcept = default;
  ObjCContainerDecl &operator=(const ObjCContainerDecl &) = default;
  ObjCContainerDecl &operator=(ObjCContainerDecl &&) noexcept = default;

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
 private:
  ObjCContainerDecl(void) = delete;

  ObjCContainerDecl(const DeclBase &) = delete;
  ObjCContainerDecl(DeclBase &&) noexcept = delete;
  ObjCContainerDecl &operator=(const DeclBase &) = delete;
  ObjCContainerDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCContainerDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCContainerDecl *decl_);
};

class ObjCImplDecl : public ObjCContainerDecl {
 public:
  ~ObjCImplDecl(void) = default;
  ObjCImplDecl(const ObjCImplDecl &) = default;
  ObjCImplDecl(ObjCImplDecl &&) noexcept = default;
  ObjCImplDecl &operator=(const ObjCImplDecl &) = default;
  ObjCImplDecl &operator=(ObjCImplDecl &&) noexcept = default;

  // ClassInterface
  // Property_impls
 private:
  ObjCImplDecl(void) = delete;

  ObjCImplDecl(const DeclBase &) = delete;
  ObjCImplDecl(DeclBase &&) noexcept = delete;
  ObjCImplDecl &operator=(const DeclBase &) = delete;
  ObjCImplDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCImplDecl *decl_);
};

class ObjCImplementationDecl : public ObjCImplDecl {
 public:
  ~ObjCImplementationDecl(void) = default;
  ObjCImplementationDecl(const ObjCImplementationDecl &) = default;
  ObjCImplementationDecl(ObjCImplementationDecl &&) noexcept = default;
  ObjCImplementationDecl &operator=(const ObjCImplementationDecl &) = default;
  ObjCImplementationDecl &operator=(ObjCImplementationDecl &&) noexcept = default;

  // Identifier
  // IvarLBraceToken
  // IvarRBraceToken
  // Name
  // NameAsString
  // NumIvarInitializers
  // SuperClass
  // SuperClassToken
  bool HasDestructors(void) const;
  bool HasNonZeroConstructors(void) const;
  // Inits
  // Ivars
 private:
  ObjCImplementationDecl(void) = delete;

  ObjCImplementationDecl(const DeclBase &) = delete;
  ObjCImplementationDecl(DeclBase &&) noexcept = delete;
  ObjCImplementationDecl &operator=(const DeclBase &) = delete;
  ObjCImplementationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCImplementationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCImplementationDecl *decl_);
};

class ObjCInterfaceDecl : public ObjCContainerDecl {
 public:
  ~ObjCInterfaceDecl(void) = default;
  ObjCInterfaceDecl(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl(ObjCInterfaceDecl &&) noexcept = default;
  ObjCInterfaceDecl &operator=(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl &operator=(ObjCInterfaceDecl &&) noexcept = default;

  // All_referenced_protocols
  bool DeclaresOrInheritsDesignatedInitializers(void) const;
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
  bool HasDefinition(void) const;
  bool IsImplicitInterfaceDecl(void) const;
  // IsSuperClassOf
  bool IsThisDeclarationADefinition(void) const;
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
 private:
  ObjCInterfaceDecl(void) = delete;

  ObjCInterfaceDecl(const DeclBase &) = delete;
  ObjCInterfaceDecl(DeclBase &&) noexcept = delete;
  ObjCInterfaceDecl &operator=(const DeclBase &) = delete;
  ObjCInterfaceDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCInterfaceDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCInterfaceDecl *decl_);
};

class ObjCMethodDecl : public NamedDecl, public DeclContext {
 public:
  ~ObjCMethodDecl(void) = default;
  ObjCMethodDecl(const ObjCMethodDecl &) = default;
  ObjCMethodDecl(ObjCMethodDecl &&) noexcept = default;
  ObjCMethodDecl &operator=(const ObjCMethodDecl &) = default;
  ObjCMethodDecl &operator=(ObjCMethodDecl &&) noexcept = default;

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
  // Parameters
 private:
  ObjCMethodDecl(void) = delete;

  ObjCMethodDecl(const DeclBase &) = delete;
  ObjCMethodDecl(DeclBase &&) noexcept = delete;
  ObjCMethodDecl &operator=(const DeclBase &) = delete;
  ObjCMethodDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCMethodDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCMethodDecl *decl_);
};

class ObjCPropertyDecl : public NamedDecl {
 public:
  ~ObjCPropertyDecl(void) = default;
  ObjCPropertyDecl(const ObjCPropertyDecl &) = default;
  ObjCPropertyDecl(ObjCPropertyDecl &&) noexcept = default;
  ObjCPropertyDecl &operator=(const ObjCPropertyDecl &) = default;
  ObjCPropertyDecl &operator=(ObjCPropertyDecl &&) noexcept = default;

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
  bool IsAtomic(void) const;
  bool IsClassProperty(void) const;
  bool IsDirectProperty(void) const;
  bool IsInstanceProperty(void) const;
  bool IsOptional(void) const;
  bool IsReadOnly(void) const;
  bool IsRetaining(void) const;
 private:
  ObjCPropertyDecl(void) = delete;

  ObjCPropertyDecl(const DeclBase &) = delete;
  ObjCPropertyDecl(DeclBase &&) noexcept = delete;
  ObjCPropertyDecl &operator=(const DeclBase &) = delete;
  ObjCPropertyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCPropertyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCPropertyDecl *decl_);
};

class ObjCPropertyImplDecl : public Decl {
 public:
  ~ObjCPropertyImplDecl(void) = default;
  ObjCPropertyImplDecl(const ObjCPropertyImplDecl &) = default;
  ObjCPropertyImplDecl(ObjCPropertyImplDecl &&) noexcept = default;
  ObjCPropertyImplDecl &operator=(const ObjCPropertyImplDecl &) = default;
  ObjCPropertyImplDecl &operator=(ObjCPropertyImplDecl &&) noexcept = default;

  // BeginToken
  // GetterCXXConstructor
  // GetterMethodDecl
  // PropertyDecl
  // PropertyImplementation
  // PropertyIvarDecl
  // PropertyIvarDeclToken
  // SetterCXXAssignment
  // SetterMethodDecl
  bool IsIvarNameSpecified(void) const;
 private:
  ObjCPropertyImplDecl(void) = delete;

  ObjCPropertyImplDecl(const DeclBase &) = delete;
  ObjCPropertyImplDecl(DeclBase &&) noexcept = delete;
  ObjCPropertyImplDecl &operator=(const DeclBase &) = delete;
  ObjCPropertyImplDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCPropertyImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCPropertyImplDecl *decl_);
};

class ObjCProtocolDecl : public ObjCContainerDecl {
 public:
  ~ObjCProtocolDecl(void) = default;
  ObjCProtocolDecl(const ObjCProtocolDecl &) = default;
  ObjCProtocolDecl(ObjCProtocolDecl &&) noexcept = default;
  ObjCProtocolDecl &operator=(const ObjCProtocolDecl &) = default;
  ObjCProtocolDecl &operator=(ObjCProtocolDecl &&) noexcept = default;

  // CanonicalDecl
  // Definition
  // ReferencedProtocols
  // TokenRange
  bool HasDefinition(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // LookupClassMethod
  // LookupInstanceMethod
  // Protocol_locs
  // Protocols
 private:
  ObjCProtocolDecl(void) = delete;

  ObjCProtocolDecl(const DeclBase &) = delete;
  ObjCProtocolDecl(DeclBase &&) noexcept = delete;
  ObjCProtocolDecl &operator=(const DeclBase &) = delete;
  ObjCProtocolDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCProtocolDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCProtocolDecl *decl_);
};

class PragmaCommentDecl : public Decl {
 public:
  ~PragmaCommentDecl(void) = default;
  PragmaCommentDecl(const PragmaCommentDecl &) = default;
  PragmaCommentDecl(PragmaCommentDecl &&) noexcept = default;
  PragmaCommentDecl &operator=(const PragmaCommentDecl &) = default;
  PragmaCommentDecl &operator=(PragmaCommentDecl &&) noexcept = default;

  // Arg
  // CommentKind
 private:
  PragmaCommentDecl(void) = delete;

  PragmaCommentDecl(const DeclBase &) = delete;
  PragmaCommentDecl(DeclBase &&) noexcept = delete;
  PragmaCommentDecl &operator=(const DeclBase &) = delete;
  PragmaCommentDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  PragmaCommentDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::PragmaCommentDecl *decl_);
};

class PragmaDetectMismatchDecl : public Decl {
 public:
  ~PragmaDetectMismatchDecl(void) = default;
  PragmaDetectMismatchDecl(const PragmaDetectMismatchDecl &) = default;
  PragmaDetectMismatchDecl(PragmaDetectMismatchDecl &&) noexcept = default;
  PragmaDetectMismatchDecl &operator=(const PragmaDetectMismatchDecl &) = default;
  PragmaDetectMismatchDecl &operator=(PragmaDetectMismatchDecl &&) noexcept = default;

  // Name
  // Value
 private:
  PragmaDetectMismatchDecl(void) = delete;

  PragmaDetectMismatchDecl(const DeclBase &) = delete;
  PragmaDetectMismatchDecl(DeclBase &&) noexcept = delete;
  PragmaDetectMismatchDecl &operator=(const DeclBase &) = delete;
  PragmaDetectMismatchDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  PragmaDetectMismatchDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::PragmaDetectMismatchDecl *decl_);
};

class RequiresExprBodyDecl : public Decl, public DeclContext {
 public:
  ~RequiresExprBodyDecl(void) = default;
  RequiresExprBodyDecl(const RequiresExprBodyDecl &) = default;
  RequiresExprBodyDecl(RequiresExprBodyDecl &&) noexcept = default;
  RequiresExprBodyDecl &operator=(const RequiresExprBodyDecl &) = default;
  RequiresExprBodyDecl &operator=(RequiresExprBodyDecl &&) noexcept = default;

 private:
  RequiresExprBodyDecl(void) = delete;

  RequiresExprBodyDecl(const DeclBase &) = delete;
  RequiresExprBodyDecl(DeclBase &&) noexcept = delete;
  RequiresExprBodyDecl &operator=(const DeclBase &) = delete;
  RequiresExprBodyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  RequiresExprBodyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::RequiresExprBodyDecl *decl_);
};

class StaticAssertDecl : public Decl {
 public:
  ~StaticAssertDecl(void) = default;
  StaticAssertDecl(const StaticAssertDecl &) = default;
  StaticAssertDecl(StaticAssertDecl &&) noexcept = default;
  StaticAssertDecl &operator=(const StaticAssertDecl &) = default;
  StaticAssertDecl &operator=(StaticAssertDecl &&) noexcept = default;

  // AssertExpr
  // Message
  // RParenToken
  // TokenRange
  bool IsFailed(void) const;
 private:
  StaticAssertDecl(void) = delete;

  StaticAssertDecl(const DeclBase &) = delete;
  StaticAssertDecl(DeclBase &&) noexcept = delete;
  StaticAssertDecl &operator=(const DeclBase &) = delete;
  StaticAssertDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  StaticAssertDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::StaticAssertDecl *decl_);
};

class TemplateDecl : public NamedDecl {
 public:
  ~TemplateDecl(void) = default;
  TemplateDecl(const TemplateDecl &) = default;
  TemplateDecl(TemplateDecl &&) noexcept = default;
  TemplateDecl &operator=(const TemplateDecl &) = default;
  TemplateDecl &operator=(TemplateDecl &&) noexcept = default;

  // TokenRange
  // TemplateParameters
  // TemplatedDecl
 private:
  TemplateDecl(void) = delete;

  TemplateDecl(const DeclBase &) = delete;
  TemplateDecl(DeclBase &&) noexcept = delete;
  TemplateDecl &operator=(const DeclBase &) = delete;
  TemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TemplateDecl *decl_);
};

class TemplateTemplateParmDecl : public TemplateDecl {
 public:
  ~TemplateTemplateParmDecl(void) = default;
  TemplateTemplateParmDecl(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl(TemplateTemplateParmDecl &&) noexcept = default;
  TemplateTemplateParmDecl &operator=(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl &operator=(TemplateTemplateParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionTemplateParameters
  // NumExpansionTemplateParameters
  // TokenRange
  bool HasDefaultArgument(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  TemplateTemplateParmDecl(void) = delete;

  TemplateTemplateParmDecl(const DeclBase &) = delete;
  TemplateTemplateParmDecl(DeclBase &&) noexcept = delete;
  TemplateTemplateParmDecl &operator=(const DeclBase &) = delete;
  TemplateTemplateParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TemplateTemplateParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TemplateTemplateParmDecl *decl_);
};

class TranslationUnitDecl : public Decl, public DeclContext {
 public:
  ~TranslationUnitDecl(void) = default;
  TranslationUnitDecl(const TranslationUnitDecl &) = default;
  TranslationUnitDecl(TranslationUnitDecl &&) noexcept = default;
  TranslationUnitDecl &operator=(const TranslationUnitDecl &) = default;
  TranslationUnitDecl &operator=(TranslationUnitDecl &&) noexcept = default;

  // ASTContext
  // AnonymousNamespace
 private:
  TranslationUnitDecl(void) = delete;

  TranslationUnitDecl(const DeclBase &) = delete;
  TranslationUnitDecl(DeclBase &&) noexcept = delete;
  TranslationUnitDecl &operator=(const DeclBase &) = delete;
  TranslationUnitDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TranslationUnitDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TranslationUnitDecl *decl_);
};

class TypeDecl : public NamedDecl {
 public:
  ~TypeDecl(void) = default;
  TypeDecl(const TypeDecl &) = default;
  TypeDecl(TypeDecl &&) noexcept = default;
  TypeDecl &operator=(const TypeDecl &) = default;
  TypeDecl &operator=(TypeDecl &&) noexcept = default;

  // BeginToken
  // TokenRange
  // TypeForDecl
 private:
  TypeDecl(void) = delete;

  TypeDecl(const DeclBase &) = delete;
  TypeDecl(DeclBase &&) noexcept = delete;
  TypeDecl &operator=(const DeclBase &) = delete;
  TypeDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TypeDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TypeDecl *decl_);
};

class TypedefNameDecl : public TypeDecl {
 public:
  ~TypedefNameDecl(void) = default;
  TypedefNameDecl(const TypedefNameDecl &) = default;
  TypedefNameDecl(TypedefNameDecl &&) noexcept = default;
  TypedefNameDecl &operator=(const TypedefNameDecl &) = default;
  TypedefNameDecl &operator=(TypedefNameDecl &&) noexcept = default;

  // CanonicalDecl
  // TypeSourceInfo
  // UnderlyingType
  bool IsModed(void) const;
  bool IsTransparentTag(void) const;
 private:
  TypedefNameDecl(void) = delete;

  TypedefNameDecl(const DeclBase &) = delete;
  TypedefNameDecl(DeclBase &&) noexcept = delete;
  TypedefNameDecl &operator=(const DeclBase &) = delete;
  TypedefNameDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TypedefNameDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TypedefNameDecl *decl_);
};

class UnresolvedUsingTypenameDecl : public TypeDecl {
 public:
  ~UnresolvedUsingTypenameDecl(void) = default;
  UnresolvedUsingTypenameDecl(const UnresolvedUsingTypenameDecl &) = default;
  UnresolvedUsingTypenameDecl(UnresolvedUsingTypenameDecl &&) noexcept = default;
  UnresolvedUsingTypenameDecl &operator=(const UnresolvedUsingTypenameDecl &) = default;
  UnresolvedUsingTypenameDecl &operator=(UnresolvedUsingTypenameDecl &&) noexcept = default;

  // CanonicalDecl
  // EllipsisToken
  // NameInfo
  // Qualifier
  // QualifierToken
  // TypenameToken
  // UsingToken
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingTypenameDecl(void) = delete;

  UnresolvedUsingTypenameDecl(const DeclBase &) = delete;
  UnresolvedUsingTypenameDecl(DeclBase &&) noexcept = delete;
  UnresolvedUsingTypenameDecl &operator=(const DeclBase &) = delete;
  UnresolvedUsingTypenameDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UnresolvedUsingTypenameDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UnresolvedUsingTypenameDecl *decl_);
};

class UsingDecl : public NamedDecl {
 public:
  ~UsingDecl(void) = default;
  UsingDecl(const UsingDecl &) = default;
  UsingDecl(UsingDecl &&) noexcept = default;
  UsingDecl &operator=(const UsingDecl &) = default;
  UsingDecl &operator=(UsingDecl &&) noexcept = default;

  // CanonicalDecl
  // NameInfo
  // Qualifier
  // QualifierToken
  // UsingToken
  bool HasTypename(void) const;
  bool IsAccessDeclaration(void) const;
  // Shadows
 private:
  UsingDecl(void) = delete;

  UsingDecl(const DeclBase &) = delete;
  UsingDecl(DeclBase &&) noexcept = delete;
  UsingDecl &operator=(const DeclBase &) = delete;
  UsingDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UsingDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UsingDecl *decl_);
};

class UsingDirectiveDecl : public NamedDecl {
 public:
  ~UsingDirectiveDecl(void) = default;
  UsingDirectiveDecl(const UsingDirectiveDecl &) = default;
  UsingDirectiveDecl(UsingDirectiveDecl &&) noexcept = default;
  UsingDirectiveDecl &operator=(const UsingDirectiveDecl &) = default;
  UsingDirectiveDecl &operator=(UsingDirectiveDecl &&) noexcept = default;

  // CommonAncestor
  // IdentLocation
  // NamespaceKeyLocation
  // NominatedNamespace
  // NominatedNamespaceAsWritten
  // Qualifier
  // QualifierToken
  // TokenRange
  // UsingToken
 private:
  UsingDirectiveDecl(void) = delete;

  UsingDirectiveDecl(const DeclBase &) = delete;
  UsingDirectiveDecl(DeclBase &&) noexcept = delete;
  UsingDirectiveDecl &operator=(const DeclBase &) = delete;
  UsingDirectiveDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UsingDirectiveDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UsingDirectiveDecl *decl_);
};

class UsingPackDecl : public NamedDecl {
 public:
  ~UsingPackDecl(void) = default;
  UsingPackDecl(const UsingPackDecl &) = default;
  UsingPackDecl(UsingPackDecl &&) noexcept = default;
  UsingPackDecl &operator=(const UsingPackDecl &) = default;
  UsingPackDecl &operator=(UsingPackDecl &&) noexcept = default;

  // Expansions
  // CanonicalDecl
  // InstantiatedFromUsingDecl
  // TokenRange
 private:
  UsingPackDecl(void) = delete;

  UsingPackDecl(const DeclBase &) = delete;
  UsingPackDecl(DeclBase &&) noexcept = delete;
  UsingPackDecl &operator=(const DeclBase &) = delete;
  UsingPackDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UsingPackDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UsingPackDecl *decl_);
};

class UsingShadowDecl : public NamedDecl {
 public:
  ~UsingShadowDecl(void) = default;
  UsingShadowDecl(const UsingShadowDecl &) = default;
  UsingShadowDecl(UsingShadowDecl &&) noexcept = default;
  UsingShadowDecl &operator=(const UsingShadowDecl &) = default;
  UsingShadowDecl &operator=(UsingShadowDecl &&) noexcept = default;

  // CanonicalDecl
  // NextUsingShadowDecl
  // TargetDecl
 private:
  UsingShadowDecl(void) = delete;

  UsingShadowDecl(const DeclBase &) = delete;
  UsingShadowDecl(DeclBase &&) noexcept = delete;
  UsingShadowDecl &operator=(const DeclBase &) = delete;
  UsingShadowDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UsingShadowDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UsingShadowDecl *decl_);
};

class ValueDecl : public NamedDecl {
 public:
  ~ValueDecl(void) = default;
  ValueDecl(const ValueDecl &) = default;
  ValueDecl(ValueDecl &&) noexcept = default;
  ValueDecl &operator=(const ValueDecl &) = default;
  ValueDecl &operator=(ValueDecl &&) noexcept = default;

  // Type
 private:
  ValueDecl(void) = delete;

  ValueDecl(const DeclBase &) = delete;
  ValueDecl(DeclBase &&) noexcept = delete;
  ValueDecl &operator=(const DeclBase &) = delete;
  ValueDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ValueDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ValueDecl *decl_);
};

class AccessSpecDecl : public Decl {
 public:
  ~AccessSpecDecl(void) = default;
  AccessSpecDecl(const AccessSpecDecl &) = default;
  AccessSpecDecl(AccessSpecDecl &&) noexcept = default;
  AccessSpecDecl &operator=(const AccessSpecDecl &) = default;
  AccessSpecDecl &operator=(AccessSpecDecl &&) noexcept = default;

  // AccessSpecifierToken
  // ColonToken
  // TokenRange
 private:
  AccessSpecDecl(void) = delete;

  AccessSpecDecl(const DeclBase &) = delete;
  AccessSpecDecl(DeclBase &&) noexcept = delete;
  AccessSpecDecl &operator=(const DeclBase &) = delete;
  AccessSpecDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  AccessSpecDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::AccessSpecDecl *decl_);
};

class BindingDecl : public ValueDecl {
 public:
  ~BindingDecl(void) = default;
  BindingDecl(const BindingDecl &) = default;
  BindingDecl(BindingDecl &&) noexcept = default;
  BindingDecl &operator=(const BindingDecl &) = default;
  BindingDecl &operator=(BindingDecl &&) noexcept = default;

  // Binding
 private:
  BindingDecl(void) = delete;

  BindingDecl(const DeclBase &) = delete;
  BindingDecl(DeclBase &&) noexcept = delete;
  BindingDecl &operator=(const DeclBase &) = delete;
  BindingDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  BindingDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::BindingDecl *decl_);
};

class BlockDecl : public Decl, public DeclContext {
 public:
  ~BlockDecl(void) = default;
  BlockDecl(const BlockDecl &) = default;
  BlockDecl(BlockDecl &&) noexcept = default;
  BlockDecl &operator=(const BlockDecl &) = default;
  BlockDecl &operator=(BlockDecl &&) noexcept = default;

  bool BlockMissingReturnType(void) const;
  bool CanAvoidCopyToHeap(void) const;
  // Captures
  bool CapturesCXXThis(void) const;
  bool DoesNotEscape(void) const;
  // BlockManglingContextDecl
  // BlockManglingNumber
  // Body
  // CaretLocation
  // CompoundBody
  // NumCaptures
  // NumParams
  // ParamDecl
  // SignatureAsWritten
  bool HasCaptures(void) const;
  bool IsConversionFromLambda(void) const;
  bool IsVariadic(void) const;
  // Parameters
 private:
  BlockDecl(void) = delete;

  BlockDecl(const DeclBase &) = delete;
  BlockDecl(DeclBase &&) noexcept = delete;
  BlockDecl &operator=(const DeclBase &) = delete;
  BlockDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  BlockDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::BlockDecl *decl_);
};

class BuiltinTemplateDecl : public TemplateDecl {
 public:
  ~BuiltinTemplateDecl(void) = default;
  BuiltinTemplateDecl(const BuiltinTemplateDecl &) = default;
  BuiltinTemplateDecl(BuiltinTemplateDecl &&) noexcept = default;
  BuiltinTemplateDecl &operator=(const BuiltinTemplateDecl &) = default;
  BuiltinTemplateDecl &operator=(BuiltinTemplateDecl &&) noexcept = default;

  // BuiltinTemplateKind
  // TokenRange
 private:
  BuiltinTemplateDecl(void) = delete;

  BuiltinTemplateDecl(const DeclBase &) = delete;
  BuiltinTemplateDecl(DeclBase &&) noexcept = delete;
  BuiltinTemplateDecl &operator=(const DeclBase &) = delete;
  BuiltinTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  BuiltinTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::BuiltinTemplateDecl *decl_);
};

class CapturedDecl : public Decl, public DeclContext {
 public:
  ~CapturedDecl(void) = default;
  CapturedDecl(const CapturedDecl &) = default;
  CapturedDecl(CapturedDecl &&) noexcept = default;
  CapturedDecl &operator=(const CapturedDecl &) = default;
  CapturedDecl &operator=(CapturedDecl &&) noexcept = default;

  // ContextParam
  // ContextParamPosition
  // NumParams
  // Param
  // Parameters
 private:
  CapturedDecl(void) = delete;

  CapturedDecl(const DeclBase &) = delete;
  CapturedDecl(DeclBase &&) noexcept = delete;
  CapturedDecl &operator=(const DeclBase &) = delete;
  CapturedDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CapturedDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CapturedDecl *decl_);
};

class ClassScopeFunctionSpecializationDecl : public Decl {
 public:
  ~ClassScopeFunctionSpecializationDecl(void) = default;
  ClassScopeFunctionSpecializationDecl(const ClassScopeFunctionSpecializationDecl &) = default;
  ClassScopeFunctionSpecializationDecl(ClassScopeFunctionSpecializationDecl &&) noexcept = default;
  ClassScopeFunctionSpecializationDecl &operator=(const ClassScopeFunctionSpecializationDecl &) = default;
  ClassScopeFunctionSpecializationDecl &operator=(ClassScopeFunctionSpecializationDecl &&) noexcept = default;

  // Specialization
  // TemplateArgsAsWritten
  bool HasExplicitTemplateArgs(void) const;
 private:
  ClassScopeFunctionSpecializationDecl(void) = delete;

  ClassScopeFunctionSpecializationDecl(const DeclBase &) = delete;
  ClassScopeFunctionSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassScopeFunctionSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassScopeFunctionSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ClassScopeFunctionSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ClassScopeFunctionSpecializationDecl *decl_);
};

class ConceptDecl : public TemplateDecl {
 public:
  ~ConceptDecl(void) = default;
  ConceptDecl(const ConceptDecl &) = default;
  ConceptDecl(ConceptDecl &&) noexcept = default;
  ConceptDecl &operator=(const ConceptDecl &) = default;
  ConceptDecl &operator=(ConceptDecl &&) noexcept = default;

  // ConstraintExpr
  // TokenRange
  bool IsTypeConcept(void) const;
 private:
  ConceptDecl(void) = delete;

  ConceptDecl(const DeclBase &) = delete;
  ConceptDecl(DeclBase &&) noexcept = delete;
  ConceptDecl &operator=(const DeclBase &) = delete;
  ConceptDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ConceptDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ConceptDecl *decl_);
};

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 public:
  ~ConstructorUsingShadowDecl(void) = default;
  ConstructorUsingShadowDecl(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl(ConstructorUsingShadowDecl &&) noexcept = default;
  ConstructorUsingShadowDecl &operator=(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl &operator=(ConstructorUsingShadowDecl &&) noexcept = default;

  bool ConstructsVirtualBase(void) const;
  // ConstructedBaseClass
  // ConstructedBaseClassShadowDecl
  // NominatedBaseClassShadowDecl
  // Parent
 private:
  ConstructorUsingShadowDecl(void) = delete;

  ConstructorUsingShadowDecl(const DeclBase &) = delete;
  ConstructorUsingShadowDecl(DeclBase &&) noexcept = delete;
  ConstructorUsingShadowDecl &operator=(const DeclBase &) = delete;
  ConstructorUsingShadowDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ConstructorUsingShadowDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ConstructorUsingShadowDecl *decl_);
};

class DeclaratorDecl : public ValueDecl {
 public:
  ~DeclaratorDecl(void) = default;
  DeclaratorDecl(const DeclaratorDecl &) = default;
  DeclaratorDecl(DeclaratorDecl &&) noexcept = default;
  DeclaratorDecl &operator=(const DeclaratorDecl &) = default;
  DeclaratorDecl &operator=(DeclaratorDecl &&) noexcept = default;

  // BeginToken
  // InnerLocStart
  // NumTemplateParameterLists
  // Qualifier
  // QualifierToken
  // TemplateParameterList
  // TrailingRequiresClause
  // TypeSourceInfo
 private:
  DeclaratorDecl(void) = delete;

  DeclaratorDecl(const DeclBase &) = delete;
  DeclaratorDecl(DeclBase &&) noexcept = delete;
  DeclaratorDecl &operator=(const DeclBase &) = delete;
  DeclaratorDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  DeclaratorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::DeclaratorDecl *decl_);
};

class EnumConstantDecl : public ValueDecl {
 public:
  ~EnumConstantDecl(void) = default;
  EnumConstantDecl(const EnumConstantDecl &) = default;
  EnumConstantDecl(EnumConstantDecl &&) noexcept = default;
  EnumConstantDecl &operator=(const EnumConstantDecl &) = default;
  EnumConstantDecl &operator=(EnumConstantDecl &&) noexcept = default;

  // CanonicalDecl
  // InitExpr
  // InitVal
 private:
  EnumConstantDecl(void) = delete;

  EnumConstantDecl(const DeclBase &) = delete;
  EnumConstantDecl(DeclBase &&) noexcept = delete;
  EnumConstantDecl &operator=(const DeclBase &) = delete;
  EnumConstantDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  EnumConstantDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::EnumConstantDecl *decl_);
};

class FieldDecl : public DeclaratorDecl {
 public:
  ~FieldDecl(void) = default;
  FieldDecl(const FieldDecl &) = default;
  FieldDecl(FieldDecl &&) noexcept = default;
  FieldDecl &operator=(const FieldDecl &) = default;
  FieldDecl &operator=(FieldDecl &&) noexcept = default;

  // BitWidth
  // CanonicalDecl
  // CapturedVLAType
  // InClassInitStyle
  // InClassInitializer
  // Parent
  bool HasCapturedVLAType(void) const;
  bool HasInClassInitializer(void) const;
  bool IsBitField(void) const;
  bool IsMutable(void) const;
  bool IsUnnamedBitfield(void) const;
 private:
  FieldDecl(void) = delete;

  FieldDecl(const DeclBase &) = delete;
  FieldDecl(DeclBase &&) noexcept = delete;
  FieldDecl &operator=(const DeclBase &) = delete;
  FieldDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FieldDecl *decl_);
};

class FunctionDecl : public DeclaratorDecl, public DeclContext {
 public:
  ~FunctionDecl(void) = default;
  FunctionDecl(const FunctionDecl &) = default;
  FunctionDecl(FunctionDecl &&) noexcept = default;
  FunctionDecl &operator=(const FunctionDecl &) = default;
  FunctionDecl &operator=(FunctionDecl &&) noexcept = default;

  bool DoesThisDeclarationHaveABody(void) const;
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
  // Parameters
  bool UsesFPIntrin(void) const;
  bool UsesSEHTry(void) const;
  bool WillHaveBody(void) const;
 private:
  FunctionDecl(void) = delete;

  FunctionDecl(const DeclBase &) = delete;
  FunctionDecl(DeclBase &&) noexcept = delete;
  FunctionDecl &operator=(const DeclBase &) = delete;
  FunctionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FunctionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FunctionDecl *decl_);
};

class IndirectFieldDecl : public ValueDecl {
 public:
  ~IndirectFieldDecl(void) = default;
  IndirectFieldDecl(const IndirectFieldDecl &) = default;
  IndirectFieldDecl(IndirectFieldDecl &&) noexcept = default;
  IndirectFieldDecl &operator=(const IndirectFieldDecl &) = default;
  IndirectFieldDecl &operator=(IndirectFieldDecl &&) noexcept = default;

  // Chain
  // AnonField
  // CanonicalDecl
  // ChainingSize
  // VarDecl
 private:
  IndirectFieldDecl(void) = delete;

  IndirectFieldDecl(const DeclBase &) = delete;
  IndirectFieldDecl(DeclBase &&) noexcept = delete;
  IndirectFieldDecl &operator=(const DeclBase &) = delete;
  IndirectFieldDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  IndirectFieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::IndirectFieldDecl *decl_);
};

class LabelDecl : public NamedDecl {
 public:
  ~LabelDecl(void) = default;
  LabelDecl(const LabelDecl &) = default;
  LabelDecl(LabelDecl &&) noexcept = default;
  LabelDecl &operator=(const LabelDecl &) = default;
  LabelDecl &operator=(LabelDecl &&) noexcept = default;

  // MSAsmLabel
  // TokenRange
  // Stmt
  bool IsGnuLocal(void) const;
  bool IsMSAsmLabel(void) const;
  bool IsResolvedMSAsmLabel(void) const;
 private:
  LabelDecl(void) = delete;

  LabelDecl(const DeclBase &) = delete;
  LabelDecl(DeclBase &&) noexcept = delete;
  LabelDecl &operator=(const DeclBase &) = delete;
  LabelDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  LabelDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::LabelDecl *decl_);
};

class MSGuidDecl : public ValueDecl {
 public:
  ~MSGuidDecl(void) = default;
  MSGuidDecl(const MSGuidDecl &) = default;
  MSGuidDecl(MSGuidDecl &&) noexcept = default;
  MSGuidDecl &operator=(const MSGuidDecl &) = default;
  MSGuidDecl &operator=(MSGuidDecl &&) noexcept = default;

  // Parts
 private:
  MSGuidDecl(void) = delete;

  MSGuidDecl(const DeclBase &) = delete;
  MSGuidDecl(DeclBase &&) noexcept = delete;
  MSGuidDecl &operator=(const DeclBase &) = delete;
  MSGuidDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  MSGuidDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::MSGuidDecl *decl_);
};

class MSPropertyDecl : public DeclaratorDecl {
 public:
  ~MSPropertyDecl(void) = default;
  MSPropertyDecl(const MSPropertyDecl &) = default;
  MSPropertyDecl(MSPropertyDecl &&) noexcept = default;
  MSPropertyDecl &operator=(const MSPropertyDecl &) = default;
  MSPropertyDecl &operator=(MSPropertyDecl &&) noexcept = default;

  // GetterId
  // SetterId
  bool HasGetter(void) const;
  bool HasSetter(void) const;
 private:
  MSPropertyDecl(void) = delete;

  MSPropertyDecl(const DeclBase &) = delete;
  MSPropertyDecl(DeclBase &&) noexcept = delete;
  MSPropertyDecl &operator=(const DeclBase &) = delete;
  MSPropertyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  MSPropertyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::MSPropertyDecl *decl_);
};

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 public:
  ~NonTypeTemplateParmDecl(void) = default;
  NonTypeTemplateParmDecl(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl(NonTypeTemplateParmDecl &&) noexcept = default;
  NonTypeTemplateParmDecl &operator=(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl &operator=(NonTypeTemplateParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionType
  // ExpansionTypeSourceInfo
  // NumExpansionTypes
  // PlaceholderTypeConstraint
  bool HasDefaultArgument(void) const;
  bool HasPlaceholderTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool IsParameterPack(void) const;
 private:
  NonTypeTemplateParmDecl(void) = delete;

  NonTypeTemplateParmDecl(const DeclBase &) = delete;
  NonTypeTemplateParmDecl(DeclBase &&) noexcept = delete;
  NonTypeTemplateParmDecl &operator=(const DeclBase &) = delete;
  NonTypeTemplateParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  NonTypeTemplateParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::NonTypeTemplateParmDecl *decl_);
};

class OMPDeclareMapperDecl : public ValueDecl, public DeclContext {
 public:
  ~OMPDeclareMapperDecl(void) = default;
  OMPDeclareMapperDecl(const OMPDeclareMapperDecl &) = default;
  OMPDeclareMapperDecl(OMPDeclareMapperDecl &&) noexcept = default;
  OMPDeclareMapperDecl &operator=(const OMPDeclareMapperDecl &) = default;
  OMPDeclareMapperDecl &operator=(OMPDeclareMapperDecl &&) noexcept = default;

  // Clauselists
  // MapperVarRef
 private:
  OMPDeclareMapperDecl(void) = delete;

  OMPDeclareMapperDecl(const DeclBase &) = delete;
  OMPDeclareMapperDecl(DeclBase &&) noexcept = delete;
  OMPDeclareMapperDecl &operator=(const DeclBase &) = delete;
  OMPDeclareMapperDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPDeclareMapperDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPDeclareMapperDecl *decl_);
};

class OMPDeclareReductionDecl : public ValueDecl, public DeclContext {
 public:
  ~OMPDeclareReductionDecl(void) = default;
  OMPDeclareReductionDecl(const OMPDeclareReductionDecl &) = default;
  OMPDeclareReductionDecl(OMPDeclareReductionDecl &&) noexcept = default;
  OMPDeclareReductionDecl &operator=(const OMPDeclareReductionDecl &) = default;
  OMPDeclareReductionDecl &operator=(OMPDeclareReductionDecl &&) noexcept = default;

  // Combiner
  // CombinerIn
  // CombinerOut
  // InitOrig
  // InitPriv
  // Initializer
  // InitializerKind
 private:
  OMPDeclareReductionDecl(void) = delete;

  OMPDeclareReductionDecl(const DeclBase &) = delete;
  OMPDeclareReductionDecl(DeclBase &&) noexcept = delete;
  OMPDeclareReductionDecl &operator=(const DeclBase &) = delete;
  OMPDeclareReductionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPDeclareReductionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPDeclareReductionDecl *decl_);
};

class ObjCAtDefsFieldDecl : public FieldDecl {
 public:
  ~ObjCAtDefsFieldDecl(void) = default;
  ObjCAtDefsFieldDecl(const ObjCAtDefsFieldDecl &) = default;
  ObjCAtDefsFieldDecl(ObjCAtDefsFieldDecl &&) noexcept = default;
  ObjCAtDefsFieldDecl &operator=(const ObjCAtDefsFieldDecl &) = default;
  ObjCAtDefsFieldDecl &operator=(ObjCAtDefsFieldDecl &&) noexcept = default;

 private:
  ObjCAtDefsFieldDecl(void) = delete;

  ObjCAtDefsFieldDecl(const DeclBase &) = delete;
  ObjCAtDefsFieldDecl(DeclBase &&) noexcept = delete;
  ObjCAtDefsFieldDecl &operator=(const DeclBase &) = delete;
  ObjCAtDefsFieldDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCAtDefsFieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCAtDefsFieldDecl *decl_);
};

class ObjCCategoryDecl : public ObjCContainerDecl {
 public:
  ~ObjCCategoryDecl(void) = default;
  ObjCCategoryDecl(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl(ObjCCategoryDecl &&) noexcept = default;
  ObjCCategoryDecl &operator=(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl &operator=(ObjCCategoryDecl &&) noexcept = default;

  bool IsClassExtension(void) const;
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
 private:
  ObjCCategoryDecl(void) = delete;

  ObjCCategoryDecl(const DeclBase &) = delete;
  ObjCCategoryDecl(DeclBase &&) noexcept = delete;
  ObjCCategoryDecl &operator=(const DeclBase &) = delete;
  ObjCCategoryDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCCategoryDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCCategoryDecl *decl_);
};

class ObjCCategoryImplDecl : public ObjCImplDecl {
 public:
  ~ObjCCategoryImplDecl(void) = default;
  ObjCCategoryImplDecl(const ObjCCategoryImplDecl &) = default;
  ObjCCategoryImplDecl(ObjCCategoryImplDecl &&) noexcept = default;
  ObjCCategoryImplDecl &operator=(const ObjCCategoryImplDecl &) = default;
  ObjCCategoryImplDecl &operator=(ObjCCategoryImplDecl &&) noexcept = default;

  // CategoryNameToken
 private:
  ObjCCategoryImplDecl(void) = delete;

  ObjCCategoryImplDecl(const DeclBase &) = delete;
  ObjCCategoryImplDecl(DeclBase &&) noexcept = delete;
  ObjCCategoryImplDecl &operator=(const DeclBase &) = delete;
  ObjCCategoryImplDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCCategoryImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCCategoryImplDecl *decl_);
};

class ObjCIvarDecl : public FieldDecl {
 public:
  ~ObjCIvarDecl(void) = default;
  ObjCIvarDecl(const ObjCIvarDecl &) = default;
  ObjCIvarDecl(ObjCIvarDecl &&) noexcept = default;
  ObjCIvarDecl &operator=(const ObjCIvarDecl &) = default;
  ObjCIvarDecl &operator=(ObjCIvarDecl &&) noexcept = default;

  // AccessControl
  // CanonicalAccessControl
  // NextIvar
  bool Synthesize(void) const;
 private:
  ObjCIvarDecl(void) = delete;

  ObjCIvarDecl(const DeclBase &) = delete;
  ObjCIvarDecl(DeclBase &&) noexcept = delete;
  ObjCIvarDecl &operator=(const DeclBase &) = delete;
  ObjCIvarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCIvarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCIvarDecl *decl_);
};

class ObjCTypeParamDecl : public TypedefNameDecl {
 public:
  ~ObjCTypeParamDecl(void) = default;
  ObjCTypeParamDecl(const ObjCTypeParamDecl &) = default;
  ObjCTypeParamDecl(ObjCTypeParamDecl &&) noexcept = default;
  ObjCTypeParamDecl &operator=(const ObjCTypeParamDecl &) = default;
  ObjCTypeParamDecl &operator=(ObjCTypeParamDecl &&) noexcept = default;

  // ColonToken
  // Index
  // Variance
  // VarianceToken
  bool HasExplicitBound(void) const;
 private:
  ObjCTypeParamDecl(void) = delete;

  ObjCTypeParamDecl(const DeclBase &) = delete;
  ObjCTypeParamDecl(DeclBase &&) noexcept = delete;
  ObjCTypeParamDecl &operator=(const DeclBase &) = delete;
  ObjCTypeParamDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ObjCTypeParamDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ObjCTypeParamDecl *decl_);
};

class RedeclarableTemplateDecl : public TemplateDecl {
 public:
  ~RedeclarableTemplateDecl(void) = default;
  RedeclarableTemplateDecl(const RedeclarableTemplateDecl &) = default;
  RedeclarableTemplateDecl(RedeclarableTemplateDecl &&) noexcept = default;
  RedeclarableTemplateDecl &operator=(const RedeclarableTemplateDecl &) = default;
  RedeclarableTemplateDecl &operator=(RedeclarableTemplateDecl &&) noexcept = default;

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  bool IsMemberSpecialization(void) const;
 private:
  RedeclarableTemplateDecl(void) = delete;

  RedeclarableTemplateDecl(const DeclBase &) = delete;
  RedeclarableTemplateDecl(DeclBase &&) noexcept = delete;
  RedeclarableTemplateDecl &operator=(const DeclBase &) = delete;
  RedeclarableTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  RedeclarableTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::RedeclarableTemplateDecl *decl_);
};

class TagDecl : public TypeDecl, public DeclContext {
 public:
  ~TagDecl(void) = default;
  TagDecl(const TagDecl &) = default;
  TagDecl(TagDecl &&) noexcept = default;
  TagDecl &operator=(const TagDecl &) = default;
  TagDecl &operator=(TagDecl &&) noexcept = default;

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

  TagDecl(const DeclBase &) = delete;
  TagDecl(DeclBase &&) noexcept = delete;
  TagDecl &operator=(const DeclBase &) = delete;
  TagDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TagDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TagDecl *decl_);
};

class TemplateTypeParmDecl : public TypeDecl {
 public:
  ~TemplateTypeParmDecl(void) = default;
  TemplateTypeParmDecl(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl(TemplateTypeParmDecl &&) noexcept = default;
  TemplateTypeParmDecl &operator=(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl &operator=(TemplateTypeParmDecl &&) noexcept = default;

  bool DefaultArgumentWasInherited(void) const;
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // DefaultArgumentInfo
  // NumExpansionParameters
  // TypeConstraint
  bool HasDefaultArgument(void) const;
  bool HasTypeConstraint(void) const;
  bool IsExpandedParameterPack(void) const;
  bool IsPackExpansion(void) const;
  bool WasDeclaredWithTypename(void) const;
 private:
  TemplateTypeParmDecl(void) = delete;

  TemplateTypeParmDecl(const DeclBase &) = delete;
  TemplateTypeParmDecl(DeclBase &&) noexcept = delete;
  TemplateTypeParmDecl &operator=(const DeclBase &) = delete;
  TemplateTypeParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TemplateTypeParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TemplateTypeParmDecl *decl_);
};

class TypeAliasDecl : public TypedefNameDecl {
 public:
  ~TypeAliasDecl(void) = default;
  TypeAliasDecl(const TypeAliasDecl &) = default;
  TypeAliasDecl(TypeAliasDecl &&) noexcept = default;
  TypeAliasDecl &operator=(const TypeAliasDecl &) = default;
  TypeAliasDecl &operator=(TypeAliasDecl &&) noexcept = default;

  // DescribedAliasTemplate
 private:
  TypeAliasDecl(void) = delete;

  TypeAliasDecl(const DeclBase &) = delete;
  TypeAliasDecl(DeclBase &&) noexcept = delete;
  TypeAliasDecl &operator=(const DeclBase &) = delete;
  TypeAliasDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TypeAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TypeAliasDecl *decl_);
};

class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~TypeAliasTemplateDecl(void) = default;
  TypeAliasTemplateDecl(const TypeAliasTemplateDecl &) = default;
  TypeAliasTemplateDecl(TypeAliasTemplateDecl &&) noexcept = default;
  TypeAliasTemplateDecl &operator=(const TypeAliasTemplateDecl &) = default;
  TypeAliasTemplateDecl &operator=(TypeAliasTemplateDecl &&) noexcept = default;

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // PreviousDecl
  // TemplatedDecl
 private:
  TypeAliasTemplateDecl(void) = delete;

  TypeAliasTemplateDecl(const DeclBase &) = delete;
  TypeAliasTemplateDecl(DeclBase &&) noexcept = delete;
  TypeAliasTemplateDecl &operator=(const DeclBase &) = delete;
  TypeAliasTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TypeAliasTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TypeAliasTemplateDecl *decl_);
};

class TypedefDecl : public TypedefNameDecl {
 public:
  ~TypedefDecl(void) = default;
  TypedefDecl(const TypedefDecl &) = default;
  TypedefDecl(TypedefDecl &&) noexcept = default;
  TypedefDecl &operator=(const TypedefDecl &) = default;
  TypedefDecl &operator=(TypedefDecl &&) noexcept = default;

 private:
  TypedefDecl(void) = delete;

  TypedefDecl(const DeclBase &) = delete;
  TypedefDecl(DeclBase &&) noexcept = delete;
  TypedefDecl &operator=(const DeclBase &) = delete;
  TypedefDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  TypedefDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::TypedefDecl *decl_);
};

class UnresolvedUsingValueDecl : public ValueDecl {
 public:
  ~UnresolvedUsingValueDecl(void) = default;
  UnresolvedUsingValueDecl(const UnresolvedUsingValueDecl &) = default;
  UnresolvedUsingValueDecl(UnresolvedUsingValueDecl &&) noexcept = default;
  UnresolvedUsingValueDecl &operator=(const UnresolvedUsingValueDecl &) = default;
  UnresolvedUsingValueDecl &operator=(UnresolvedUsingValueDecl &&) noexcept = default;

  // CanonicalDecl
  // EllipsisToken
  // NameInfo
  // Qualifier
  // QualifierToken
  // UsingToken
  bool IsAccessDeclaration(void) const;
  bool IsPackExpansion(void) const;
 private:
  UnresolvedUsingValueDecl(void) = delete;

  UnresolvedUsingValueDecl(const DeclBase &) = delete;
  UnresolvedUsingValueDecl(DeclBase &&) noexcept = delete;
  UnresolvedUsingValueDecl &operator=(const DeclBase &) = delete;
  UnresolvedUsingValueDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  UnresolvedUsingValueDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::UnresolvedUsingValueDecl *decl_);
};

class VarDecl : public DeclaratorDecl {
 public:
  ~VarDecl(void) = default;
  VarDecl(const VarDecl &) = default;
  VarDecl(VarDecl &&) noexcept = default;
  VarDecl &operator=(const VarDecl &) = default;
  VarDecl &operator=(VarDecl &&) noexcept = default;

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
  // IsThisDeclarationADefinition
  bool IsThisDeclarationADemotedDefinition(void) const;
 private:
  VarDecl(void) = delete;

  VarDecl(const DeclBase &) = delete;
  VarDecl(DeclBase &&) noexcept = delete;
  VarDecl &operator=(const DeclBase &) = delete;
  VarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  VarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::VarDecl *decl_);
};

class VarTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~VarTemplateDecl(void) = default;
  VarTemplateDecl(const VarTemplateDecl &) = default;
  VarTemplateDecl(VarTemplateDecl &&) noexcept = default;
  VarTemplateDecl &operator=(const VarTemplateDecl &) = default;
  VarTemplateDecl &operator=(VarTemplateDecl &&) noexcept = default;

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  VarTemplateDecl(void) = delete;

  VarTemplateDecl(const DeclBase &) = delete;
  VarTemplateDecl(DeclBase &&) noexcept = delete;
  VarTemplateDecl &operator=(const DeclBase &) = delete;
  VarTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  VarTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::VarTemplateDecl *decl_);
};

class VarTemplateSpecializationDecl : public VarDecl {
 public:
  ~VarTemplateSpecializationDecl(void) = default;
  VarTemplateSpecializationDecl(const VarTemplateSpecializationDecl &) = default;
  VarTemplateSpecializationDecl(VarTemplateSpecializationDecl &&) noexcept = default;
  VarTemplateSpecializationDecl &operator=(const VarTemplateSpecializationDecl &) = default;
  VarTemplateSpecializationDecl &operator=(VarTemplateSpecializationDecl &&) noexcept = default;

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
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  VarTemplateSpecializationDecl(void) = delete;

  VarTemplateSpecializationDecl(const DeclBase &) = delete;
  VarTemplateSpecializationDecl(DeclBase &&) noexcept = delete;
  VarTemplateSpecializationDecl &operator=(const DeclBase &) = delete;
  VarTemplateSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  VarTemplateSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::VarTemplateSpecializationDecl *decl_);
};

class CXXDeductionGuideDecl : public FunctionDecl {
 public:
  ~CXXDeductionGuideDecl(void) = default;
  CXXDeductionGuideDecl(const CXXDeductionGuideDecl &) = default;
  CXXDeductionGuideDecl(CXXDeductionGuideDecl &&) noexcept = default;
  CXXDeductionGuideDecl &operator=(const CXXDeductionGuideDecl &) = default;
  CXXDeductionGuideDecl &operator=(CXXDeductionGuideDecl &&) noexcept = default;

  // DeducedTemplate
  // ExplicitSpecifier
  bool IsCopyDeductionCandidate(void) const;
  bool IsExplicit(void) const;
 private:
  CXXDeductionGuideDecl(void) = delete;

  CXXDeductionGuideDecl(const DeclBase &) = delete;
  CXXDeductionGuideDecl(DeclBase &&) noexcept = delete;
  CXXDeductionGuideDecl &operator=(const DeclBase &) = delete;
  CXXDeductionGuideDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXDeductionGuideDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXDeductionGuideDecl *decl_);
};

class CXXMethodDecl : public FunctionDecl {
 public:
  ~CXXMethodDecl(void) = default;
  CXXMethodDecl(const CXXMethodDecl &) = default;
  CXXMethodDecl(CXXMethodDecl &&) noexcept = default;
  CXXMethodDecl &operator=(const CXXMethodDecl &) = default;
  CXXMethodDecl &operator=(CXXMethodDecl &&) noexcept = default;

  // CanonicalDecl
  // CorrespondingMethodDeclaredInClass
  // CorrespondingMethodInClass
  // DevirtualizedMethod
  // MethodQualifiers
  // MostRecentDecl
  // Parent
  // RefQualifier
  bool IsConst(void) const;
  bool IsInstance(void) const;
  bool IsVirtual(void) const;
  bool IsVolatile(void) const;
 private:
  CXXMethodDecl(void) = delete;

  CXXMethodDecl(const DeclBase &) = delete;
  CXXMethodDecl(DeclBase &&) noexcept = delete;
  CXXMethodDecl &operator=(const DeclBase &) = delete;
  CXXMethodDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXMethodDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXMethodDecl *decl_);
};

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~ClassTemplateDecl(void) = default;
  ClassTemplateDecl(const ClassTemplateDecl &) = default;
  ClassTemplateDecl(ClassTemplateDecl &&) noexcept = default;
  ClassTemplateDecl &operator=(const ClassTemplateDecl &) = default;
  ClassTemplateDecl &operator=(ClassTemplateDecl &&) noexcept = default;

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  ClassTemplateDecl(void) = delete;

  ClassTemplateDecl(const DeclBase &) = delete;
  ClassTemplateDecl(DeclBase &&) noexcept = delete;
  ClassTemplateDecl &operator=(const DeclBase &) = delete;
  ClassTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ClassTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ClassTemplateDecl *decl_);
};

class DecompositionDecl : public VarDecl {
 public:
  ~DecompositionDecl(void) = default;
  DecompositionDecl(const DecompositionDecl &) = default;
  DecompositionDecl(DecompositionDecl &&) noexcept = default;
  DecompositionDecl &operator=(const DecompositionDecl &) = default;
  DecompositionDecl &operator=(DecompositionDecl &&) noexcept = default;

  // Bindings
 private:
  DecompositionDecl(void) = delete;

  DecompositionDecl(const DeclBase &) = delete;
  DecompositionDecl(DeclBase &&) noexcept = delete;
  DecompositionDecl &operator=(const DeclBase &) = delete;
  DecompositionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  DecompositionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::DecompositionDecl *decl_);
};

class EnumDecl : public TagDecl {
 public:
  ~EnumDecl(void) = default;
  EnumDecl(const EnumDecl &) = default;
  EnumDecl(EnumDecl &&) noexcept = default;
  EnumDecl &operator=(const EnumDecl &) = default;
  EnumDecl &operator=(EnumDecl &&) noexcept = default;

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
  bool IsComplete(void) const;
  bool IsFixed(void) const;
  bool IsScoped(void) const;
  bool IsScopedUsingClassTag(void) const;
 private:
  EnumDecl(void) = delete;

  EnumDecl(const DeclBase &) = delete;
  EnumDecl(DeclBase &&) noexcept = delete;
  EnumDecl &operator=(const DeclBase &) = delete;
  EnumDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  EnumDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::EnumDecl *decl_);
};

class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 public:
  ~FunctionTemplateDecl(void) = default;
  FunctionTemplateDecl(const FunctionTemplateDecl &) = default;
  FunctionTemplateDecl(FunctionTemplateDecl &&) noexcept = default;
  FunctionTemplateDecl &operator=(const FunctionTemplateDecl &) = default;
  FunctionTemplateDecl &operator=(FunctionTemplateDecl &&) noexcept = default;

  // CanonicalDecl
  // InstantiatedFromMemberTemplate
  // MostRecentDecl
  // PreviousDecl
  // TemplatedDecl
  bool IsAbbreviated(void) const;
  bool IsThisDeclarationADefinition(void) const;
  // Specializations
 private:
  FunctionTemplateDecl(void) = delete;

  FunctionTemplateDecl(const DeclBase &) = delete;
  FunctionTemplateDecl(DeclBase &&) noexcept = delete;
  FunctionTemplateDecl &operator=(const DeclBase &) = delete;
  FunctionTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  FunctionTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::FunctionTemplateDecl *decl_);
};

class ImplicitParamDecl : public VarDecl {
 public:
  ~ImplicitParamDecl(void) = default;
  ImplicitParamDecl(const ImplicitParamDecl &) = default;
  ImplicitParamDecl(ImplicitParamDecl &&) noexcept = default;
  ImplicitParamDecl &operator=(const ImplicitParamDecl &) = default;
  ImplicitParamDecl &operator=(ImplicitParamDecl &&) noexcept = default;

  // ParameterKind
 private:
  ImplicitParamDecl(void) = delete;

  ImplicitParamDecl(const DeclBase &) = delete;
  ImplicitParamDecl(DeclBase &&) noexcept = delete;
  ImplicitParamDecl &operator=(const DeclBase &) = delete;
  ImplicitParamDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ImplicitParamDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ImplicitParamDecl *decl_);
};

class OMPCapturedExprDecl : public VarDecl {
 public:
  ~OMPCapturedExprDecl(void) = default;
  OMPCapturedExprDecl(const OMPCapturedExprDecl &) = default;
  OMPCapturedExprDecl(OMPCapturedExprDecl &&) noexcept = default;
  OMPCapturedExprDecl &operator=(const OMPCapturedExprDecl &) = default;
  OMPCapturedExprDecl &operator=(OMPCapturedExprDecl &&) noexcept = default;

 private:
  OMPCapturedExprDecl(void) = delete;

  OMPCapturedExprDecl(const DeclBase &) = delete;
  OMPCapturedExprDecl(DeclBase &&) noexcept = delete;
  OMPCapturedExprDecl &operator=(const DeclBase &) = delete;
  OMPCapturedExprDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  OMPCapturedExprDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::OMPCapturedExprDecl *decl_);
};

class ParmVarDecl : public VarDecl {
 public:
  ~ParmVarDecl(void) = default;
  ParmVarDecl(const ParmVarDecl &) = default;
  ParmVarDecl(ParmVarDecl &&) noexcept = default;
  ParmVarDecl &operator=(const ParmVarDecl &) = default;
  ParmVarDecl &operator=(ParmVarDecl &&) noexcept = default;

  // DefaultArg
  // FunctionScopeDepth
  // FunctionScopeIndex
  // ObjCDeclQualifier
  // UninstantiatedDefaultArg
  bool HasInheritedDefaultArg(void) const;
  bool HasUninstantiatedDefaultArg(void) const;
  bool HasUnparsedDefaultArg(void) const;
  bool IsKNRPromoted(void) const;
  bool IsObjCMethodParameter(void) const;
 private:
  ParmVarDecl(void) = delete;

  ParmVarDecl(const DeclBase &) = delete;
  ParmVarDecl(DeclBase &&) noexcept = delete;
  ParmVarDecl &operator=(const DeclBase &) = delete;
  ParmVarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ParmVarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ParmVarDecl *decl_);
};

class RecordDecl : public TagDecl {
 public:
  ~RecordDecl(void) = default;
  RecordDecl(const RecordDecl &) = default;
  RecordDecl(RecordDecl &&) noexcept = default;
  RecordDecl &operator=(const RecordDecl &) = default;
  RecordDecl &operator=(RecordDecl &&) noexcept = default;

  bool CanPassInRegisters(void) const;
  // Fields
  // ArgPassingRestrictions
  // Definition
  // MostRecentDecl
  // PreviousDecl
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

  RecordDecl(const DeclBase &) = delete;
  RecordDecl(DeclBase &&) noexcept = delete;
  RecordDecl &operator=(const DeclBase &) = delete;
  RecordDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  RecordDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::RecordDecl *decl_);
};

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 public:
  ~VarTemplatePartialSpecializationDecl(void) = default;
  VarTemplatePartialSpecializationDecl(const VarTemplatePartialSpecializationDecl &) = default;
  VarTemplatePartialSpecializationDecl(VarTemplatePartialSpecializationDecl &&) noexcept = default;
  VarTemplatePartialSpecializationDecl &operator=(const VarTemplatePartialSpecializationDecl &) = default;
  VarTemplatePartialSpecializationDecl &operator=(VarTemplatePartialSpecializationDecl &&) noexcept = default;

  // Profile
  // AssociatedConstraints
  // InstantiatedFromMember
  // TemplateArgsAsWritten
  // TemplateParameters
  bool HasAssociatedConstraints(void) const;
 private:
  VarTemplatePartialSpecializationDecl(void) = delete;

  VarTemplatePartialSpecializationDecl(const DeclBase &) = delete;
  VarTemplatePartialSpecializationDecl(DeclBase &&) noexcept = delete;
  VarTemplatePartialSpecializationDecl &operator=(const DeclBase &) = delete;
  VarTemplatePartialSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  VarTemplatePartialSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::VarTemplatePartialSpecializationDecl *decl_);
};

class CXXConstructorDecl : public CXXMethodDecl {
 public:
  ~CXXConstructorDecl(void) = default;
  CXXConstructorDecl(const CXXConstructorDecl &) = default;
  CXXConstructorDecl(CXXConstructorDecl &&) noexcept = default;
  CXXConstructorDecl &operator=(const CXXConstructorDecl &) = default;
  CXXConstructorDecl &operator=(CXXConstructorDecl &&) noexcept = default;

  // CanonicalDecl
  // ExplicitSpecifier
  // InheritedConstructor
  // NumCtorInitializers
  // Inits
  bool IsCopyConstructor(void) const;
  bool IsCopyOrMoveConstructor(void) const;
  bool IsDelegatingConstructor(void) const;
  bool IsExplicit(void) const;
  bool IsInheritingConstructor(void) const;
  bool IsMoveConstructor(void) const;
 private:
  CXXConstructorDecl(void) = delete;

  CXXConstructorDecl(const DeclBase &) = delete;
  CXXConstructorDecl(DeclBase &&) noexcept = delete;
  CXXConstructorDecl &operator=(const DeclBase &) = delete;
  CXXConstructorDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXConstructorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXConstructorDecl *decl_);
};

class CXXConversionDecl : public CXXMethodDecl {
 public:
  ~CXXConversionDecl(void) = default;
  CXXConversionDecl(const CXXConversionDecl &) = default;
  CXXConversionDecl(CXXConversionDecl &&) noexcept = default;
  CXXConversionDecl &operator=(const CXXConversionDecl &) = default;
  CXXConversionDecl &operator=(CXXConversionDecl &&) noexcept = default;

  // CanonicalDecl
  // ConversionType
  // ExplicitSpecifier
  bool IsExplicit(void) const;
 private:
  CXXConversionDecl(void) = delete;

  CXXConversionDecl(const DeclBase &) = delete;
  CXXConversionDecl(DeclBase &&) noexcept = delete;
  CXXConversionDecl &operator=(const DeclBase &) = delete;
  CXXConversionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXConversionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXConversionDecl *decl_);
};

class CXXDestructorDecl : public CXXMethodDecl {
 public:
  ~CXXDestructorDecl(void) = default;
  CXXDestructorDecl(const CXXDestructorDecl &) = default;
  CXXDestructorDecl(CXXDestructorDecl &&) noexcept = default;
  CXXDestructorDecl &operator=(const CXXDestructorDecl &) = default;
  CXXDestructorDecl &operator=(CXXDestructorDecl &&) noexcept = default;

  // CanonicalDecl
  // OperatorDelete
  // OperatorDeleteThisArg
 private:
  CXXDestructorDecl(void) = delete;

  CXXDestructorDecl(const DeclBase &) = delete;
  CXXDestructorDecl(DeclBase &&) noexcept = delete;
  CXXDestructorDecl &operator=(const DeclBase &) = delete;
  CXXDestructorDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXDestructorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXDestructorDecl *decl_);
};

class CXXRecordDecl : public RecordDecl {
 public:
  ~CXXRecordDecl(void) = default;
  CXXRecordDecl(const CXXRecordDecl &) = default;
  CXXRecordDecl(CXXRecordDecl &&) noexcept = default;
  CXXRecordDecl &operator=(const CXXRecordDecl &) = default;
  CXXRecordDecl &operator=(CXXRecordDecl &&) noexcept = default;

  bool AllowConstDefaultInit(void) const;
  // Bases
  // Captures
  // Constructors
  bool DefaultedCopyConstructorIsDeleted(void) const;
  bool DefaultedDefaultConstructorIsConstexpr(void) const;
  bool DefaultedDestructorIsConstexpr(void) const;
  bool DefaultedDestructorIsDeleted(void) const;
  bool DefaultedMoveConstructorIsDeleted(void) const;
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
  // IsLocalClass
  bool IsPOD(void) const;
  bool IsParsingBaseSpecifiers(void) const;
  bool IsPolymorphic(void) const;
  bool IsStandardLayout(void) const;
  bool IsTrivial(void) const;
  bool MayBeDynamicClass(void) const;
  bool MayBeNonDynamicClass(void) const;
  // Methods
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
  // VirtualBases
 private:
  CXXRecordDecl(void) = delete;

  CXXRecordDecl(const DeclBase &) = delete;
  CXXRecordDecl(DeclBase &&) noexcept = delete;
  CXXRecordDecl &operator=(const DeclBase &) = delete;
  CXXRecordDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  CXXRecordDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::CXXRecordDecl *decl_);
};

class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 public:
  ~ClassTemplateSpecializationDecl(void) = default;
  ClassTemplateSpecializationDecl(const ClassTemplateSpecializationDecl &) = default;
  ClassTemplateSpecializationDecl(ClassTemplateSpecializationDecl &&) noexcept = default;
  ClassTemplateSpecializationDecl &operator=(const ClassTemplateSpecializationDecl &) = default;
  ClassTemplateSpecializationDecl &operator=(ClassTemplateSpecializationDecl &&) noexcept = default;

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
  bool IsClassScopeExplicitSpecialization(void) const;
  bool IsExplicitInstantiationOrSpecialization(void) const;
  bool IsExplicitSpecialization(void) const;
 private:
  ClassTemplateSpecializationDecl(void) = delete;

  ClassTemplateSpecializationDecl(const DeclBase &) = delete;
  ClassTemplateSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassTemplateSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassTemplateSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ClassTemplateSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ClassTemplateSpecializationDecl *decl_);
};

class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 public:
  ~ClassTemplatePartialSpecializationDecl(void) = default;
  ClassTemplatePartialSpecializationDecl(const ClassTemplatePartialSpecializationDecl &) = default;
  ClassTemplatePartialSpecializationDecl(ClassTemplatePartialSpecializationDecl &&) noexcept = default;
  ClassTemplatePartialSpecializationDecl &operator=(const ClassTemplatePartialSpecializationDecl &) = default;
  ClassTemplatePartialSpecializationDecl &operator=(ClassTemplatePartialSpecializationDecl &&) noexcept = default;

  // Profile
  // AssociatedConstraints
  // InjectedSpecializationType
  // InstantiatedFromMember
  // InstantiatedFromMemberTemplate
  // TemplateArgsAsWritten
  // TemplateParameters
  bool HasAssociatedConstraints(void) const;
 private:
  ClassTemplatePartialSpecializationDecl(void) = delete;

  ClassTemplatePartialSpecializationDecl(const DeclBase &) = delete;
  ClassTemplatePartialSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassTemplatePartialSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassTemplatePartialSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;

 protected:
  ClassTemplatePartialSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      const ::clang::ClassTemplatePartialSpecializationDecl *decl_);
};

}  // namespace pasta
