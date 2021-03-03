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

  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, ::clang::Decl *decl_)
      : ast(ast_) {
    u.Decl = decl_;
  }
  inline DeclBase(const std::shared_ptr<ASTImpl> &ast_, ::clang::DeclContext *dc_, int)
      : ast(ast_) {
    u.DeclContext = dc_;
  }

  std::shared_ptr<ASTImpl> ast;
  union {
    ::clang::AccessSpecDecl *AccessSpecDecl;
    ::clang::BindingDecl *BindingDecl;
    ::clang::BlockDecl *BlockDecl;
    ::clang::BuiltinTemplateDecl *BuiltinTemplateDecl;
    ::clang::CXXConstructorDecl *CXXConstructorDecl;
    ::clang::CXXConversionDecl *CXXConversionDecl;
    ::clang::CXXDeductionGuideDecl *CXXDeductionGuideDecl;
    ::clang::CXXDestructorDecl *CXXDestructorDecl;
    ::clang::CXXMethodDecl *CXXMethodDecl;
    ::clang::CXXRecordDecl *CXXRecordDecl;
    ::clang::CapturedDecl *CapturedDecl;
    ::clang::ClassScopeFunctionSpecializationDecl *ClassScopeFunctionSpecializationDecl;
    ::clang::ClassTemplateDecl *ClassTemplateDecl;
    ::clang::ClassTemplatePartialSpecializationDecl *ClassTemplatePartialSpecializationDecl;
    ::clang::ClassTemplateSpecializationDecl *ClassTemplateSpecializationDecl;
    ::clang::ConceptDecl *ConceptDecl;
    ::clang::ConstructorUsingShadowDecl *ConstructorUsingShadowDecl;
    ::clang::Decl *Decl;
    ::clang::DeclContext *DeclContext;
    ::clang::DeclaratorDecl *DeclaratorDecl;
    ::clang::DecompositionDecl *DecompositionDecl;
    ::clang::EmptyDecl *EmptyDecl;
    ::clang::EnumConstantDecl *EnumConstantDecl;
    ::clang::EnumDecl *EnumDecl;
    ::clang::ExportDecl *ExportDecl;
    ::clang::ExternCContextDecl *ExternCContextDecl;
    ::clang::FieldDecl *FieldDecl;
    ::clang::FileScopeAsmDecl *FileScopeAsmDecl;
    ::clang::FriendDecl *FriendDecl;
    ::clang::FriendTemplateDecl *FriendTemplateDecl;
    ::clang::FunctionDecl *FunctionDecl;
    ::clang::FunctionTemplateDecl *FunctionTemplateDecl;
    ::clang::ImplicitParamDecl *ImplicitParamDecl;
    ::clang::ImportDecl *ImportDecl;
    ::clang::IndirectFieldDecl *IndirectFieldDecl;
    ::clang::LabelDecl *LabelDecl;
    ::clang::LifetimeExtendedTemporaryDecl *LifetimeExtendedTemporaryDecl;
    ::clang::LinkageSpecDecl *LinkageSpecDecl;
    ::clang::MSGuidDecl *MSGuidDecl;
    ::clang::MSPropertyDecl *MSPropertyDecl;
    ::clang::NamedDecl *NamedDecl;
    ::clang::NamespaceAliasDecl *NamespaceAliasDecl;
    ::clang::NamespaceDecl *NamespaceDecl;
    ::clang::NonTypeTemplateParmDecl *NonTypeTemplateParmDecl;
    ::clang::OMPAllocateDecl *OMPAllocateDecl;
    ::clang::OMPCapturedExprDecl *OMPCapturedExprDecl;
    ::clang::OMPDeclareMapperDecl *OMPDeclareMapperDecl;
    ::clang::OMPDeclareReductionDecl *OMPDeclareReductionDecl;
    ::clang::OMPRequiresDecl *OMPRequiresDecl;
    ::clang::OMPThreadPrivateDecl *OMPThreadPrivateDecl;
    ::clang::ObjCAtDefsFieldDecl *ObjCAtDefsFieldDecl;
    ::clang::ObjCCategoryDecl *ObjCCategoryDecl;
    ::clang::ObjCCategoryImplDecl *ObjCCategoryImplDecl;
    ::clang::ObjCCompatibleAliasDecl *ObjCCompatibleAliasDecl;
    ::clang::ObjCContainerDecl *ObjCContainerDecl;
    ::clang::ObjCImplDecl *ObjCImplDecl;
    ::clang::ObjCImplementationDecl *ObjCImplementationDecl;
    ::clang::ObjCInterfaceDecl *ObjCInterfaceDecl;
    ::clang::ObjCIvarDecl *ObjCIvarDecl;
    ::clang::ObjCMethodDecl *ObjCMethodDecl;
    ::clang::ObjCPropertyDecl *ObjCPropertyDecl;
    ::clang::ObjCPropertyImplDecl *ObjCPropertyImplDecl;
    ::clang::ObjCProtocolDecl *ObjCProtocolDecl;
    ::clang::ObjCTypeParamDecl *ObjCTypeParamDecl;
    ::clang::ParmVarDecl *ParmVarDecl;
    ::clang::PragmaCommentDecl *PragmaCommentDecl;
    ::clang::PragmaDetectMismatchDecl *PragmaDetectMismatchDecl;
    ::clang::RecordDecl *RecordDecl;
    ::clang::RedeclarableTemplateDecl *RedeclarableTemplateDecl;
    ::clang::RequiresExprBodyDecl *RequiresExprBodyDecl;
    ::clang::StaticAssertDecl *StaticAssertDecl;
    ::clang::TagDecl *TagDecl;
    ::clang::TemplateDecl *TemplateDecl;
    ::clang::TemplateTemplateParmDecl *TemplateTemplateParmDecl;
    ::clang::TemplateTypeParmDecl *TemplateTypeParmDecl;
    ::clang::TranslationUnitDecl *TranslationUnitDecl;
    ::clang::TypeAliasDecl *TypeAliasDecl;
    ::clang::TypeAliasTemplateDecl *TypeAliasTemplateDecl;
    ::clang::TypeDecl *TypeDecl;
    ::clang::TypedefDecl *TypedefDecl;
    ::clang::TypedefNameDecl *TypedefNameDecl;
    ::clang::UnresolvedUsingTypenameDecl *UnresolvedUsingTypenameDecl;
    ::clang::UnresolvedUsingValueDecl *UnresolvedUsingValueDecl;
    ::clang::UsingDecl *UsingDecl;
    ::clang::UsingDirectiveDecl *UsingDirectiveDecl;
    ::clang::UsingPackDecl *UsingPackDecl;
    ::clang::UsingShadowDecl *UsingShadowDecl;
    ::clang::ValueDecl *ValueDecl;
    ::clang::VarDecl *VarDecl;
    ::clang::VarTemplateDecl *VarTemplateDecl;
    ::clang::VarTemplatePartialSpecializationDecl *VarTemplatePartialSpecializationDecl;
    ::clang::VarTemplateSpecializationDecl *VarTemplateSpecializationDecl;
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
  AccessSpecDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::AccessSpecDecl *decl_);
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
  BindingDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::BindingDecl *decl_);
};

class BlockDecl : public Decl, public DeclContext {
 public:
  ~BlockDecl(void) = default;
  BlockDecl(const BlockDecl &) = default;
  BlockDecl(BlockDecl &&) noexcept = default;
  BlockDecl &operator=(const BlockDecl &) = default;
  BlockDecl &operator=(BlockDecl &&) noexcept = default;

  // BlockMissingReturnType
  // CanAvoidCopyToHeap
  // Captures
  // CapturesCXXThis
  // DoesNotEscape
  // BlockManglingContextDecl
  // BlockManglingNumber
  // Body
  // CaretLocation
  // CompoundBody
  // NumCaptures
  // NumParams
  // ParamDecl
  // SignatureAsWritten
  // HasCaptures
  // IsConversionFromLambda
  // IsVariadic
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
  BlockDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::BlockDecl *decl_);
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
  BuiltinTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::BuiltinTemplateDecl *decl_);
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
  // IsCopyConstructor
  // IsCopyOrMoveConstructor
  // IsDelegatingConstructor
  // IsExplicit
  // IsInheritingConstructor
  // IsMoveConstructor
 private:
  CXXConstructorDecl(void) = delete;

  CXXConstructorDecl(const DeclBase &) = delete;
  CXXConstructorDecl(DeclBase &&) noexcept = delete;
  CXXConstructorDecl &operator=(const DeclBase &) = delete;
  CXXConstructorDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  CXXConstructorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXConstructorDecl *decl_);
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
  // IsExplicit
 private:
  CXXConversionDecl(void) = delete;

  CXXConversionDecl(const DeclBase &) = delete;
  CXXConversionDecl(DeclBase &&) noexcept = delete;
  CXXConversionDecl &operator=(const DeclBase &) = delete;
  CXXConversionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  CXXConversionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXConversionDecl *decl_);
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
  // IsCopyDeductionCandidate
  // IsExplicit
 private:
  CXXDeductionGuideDecl(void) = delete;

  CXXDeductionGuideDecl(const DeclBase &) = delete;
  CXXDeductionGuideDecl(DeclBase &&) noexcept = delete;
  CXXDeductionGuideDecl &operator=(const DeclBase &) = delete;
  CXXDeductionGuideDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  CXXDeductionGuideDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXDeductionGuideDecl *decl_);
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
  CXXDestructorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXDestructorDecl *decl_);
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
  // IsConst
  // IsInstance
  // IsVirtual
  // IsVolatile
 private:
  CXXMethodDecl(void) = delete;

  CXXMethodDecl(const DeclBase &) = delete;
  CXXMethodDecl(DeclBase &&) noexcept = delete;
  CXXMethodDecl &operator=(const DeclBase &) = delete;
  CXXMethodDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  CXXMethodDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXMethodDecl *decl_);
};

class CXXRecordDecl : public RecordDecl {
 public:
  ~CXXRecordDecl(void) = default;
  CXXRecordDecl(const CXXRecordDecl &) = default;
  CXXRecordDecl(CXXRecordDecl &&) noexcept = default;
  CXXRecordDecl &operator=(const CXXRecordDecl &) = default;
  CXXRecordDecl &operator=(CXXRecordDecl &&) noexcept = default;

  // AllowConstDefaultInit
  // Bases
  // Captures
  // Ctors
  // DefaultedCopyConstructorIsDeleted
  // DefaultedDefaultConstructorIsConstexpr
  // DefaultedDestructorIsConstexpr
  // DefaultedDestructorIsDeleted
  // DefaultedMoveConstructorIsDeleted
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
  // HasConstexprDefaultConstructor
  // HasConstexprNonCopyMoveConstructor
  // HasCopyAssignmentWithConstParam
  // HasCopyConstructorWithConstParam
  // HasDefaultConstructor
  // HasDefinition
  // HasDirectFields
  // HasFriends
  // HasInClassInitializer
  // HasInheritedAssignment
  // HasInheritedConstructor
  // HasIrrelevantDestructor
  // HasKnownLambdaInternalLinkage
  // HasMoveAssignment
  // HasMoveConstructor
  // HasMutableFields
  // HasNonLiteralTypeFieldsOrBases
  // HasNonTrivialCopyAssignment
  // HasNonTrivialCopyConstructor
  // HasNonTrivialCopyConstructorForCall
  // HasNonTrivialDefaultConstructor
  // HasNonTrivialDestructor
  // HasNonTrivialDestructorForCall
  // HasNonTrivialMoveAssignment
  // HasNonTrivialMoveConstructor
  // HasNonTrivialMoveConstructorForCall
  // HasPrivateFields
  // HasProtectedFields
  // HasSimpleCopyAssignment
  // HasSimpleCopyConstructor
  // HasSimpleDestructor
  // HasSimpleMoveAssignment
  // HasSimpleMoveConstructor
  // HasTrivialCopyAssignment
  // HasTrivialCopyConstructor
  // HasTrivialCopyConstructorForCall
  // HasTrivialDefaultConstructor
  // HasTrivialDestructor
  // HasTrivialDestructorForCall
  // HasTrivialMoveAssignment
  // HasTrivialMoveConstructor
  // HasTrivialMoveConstructorForCall
  // HasUninitializedReferenceMember
  // HasUserDeclaredConstructor
  // HasUserDeclaredCopyAssignment
  // HasUserDeclaredCopyConstructor
  // HasUserDeclaredDestructor
  // HasUserDeclaredMoveAssignment
  // HasUserDeclaredMoveConstructor
  // HasUserDeclaredMoveOperation
  // HasUserProvidedDefaultConstructor
  // HasVariantMembers
  // ImplicitCopyAssignmentHasConstParam
  // ImplicitCopyConstructorHasConstParam
  // IsAbstract
  // IsAggregate
  // IsCXX11StandardLayout
  // IsDependentLambda
  // IsDynamicClass
  // IsEmpty
  // IsLambda
  // IsLiteral
  // IsLocalClass
  // IsPOD
  // IsParsingBaseSpecifiers
  // IsPolymorphic
  // IsStandardLayout
  // IsTrivial
  // MayBeDynamicClass
  // MayBeNonDynamicClass
  // Methods
  // NeedsImplicitCopyAssignment
  // NeedsImplicitCopyConstructor
  // NeedsImplicitDefaultConstructor
  // NeedsImplicitDestructor
  // NeedsImplicitMoveAssignment
  // NeedsImplicitMoveConstructor
  // NeedsOverloadResolutionForCopyAssignment
  // NeedsOverloadResolutionForCopyConstructor
  // NeedsOverloadResolutionForDestructor
  // NeedsOverloadResolutionForMoveAssignment
  // NeedsOverloadResolutionForMoveConstructor
  // Vbases
 private:
  CXXRecordDecl(void) = delete;

  CXXRecordDecl(const DeclBase &) = delete;
  CXXRecordDecl(DeclBase &&) noexcept = delete;
  CXXRecordDecl &operator=(const DeclBase &) = delete;
  CXXRecordDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  CXXRecordDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CXXRecordDecl *decl_);
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
  CapturedDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::CapturedDecl *decl_);
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
  // HasExplicitTemplateArgs
 private:
  ClassScopeFunctionSpecializationDecl(void) = delete;

  ClassScopeFunctionSpecializationDecl(const DeclBase &) = delete;
  ClassScopeFunctionSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassScopeFunctionSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassScopeFunctionSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ClassScopeFunctionSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ClassScopeFunctionSpecializationDecl *decl_);
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
  // IsThisDeclarationADefinition
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
  ClassTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ClassTemplateDecl *decl_);
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
  // HasAssociatedConstraints
 private:
  ClassTemplatePartialSpecializationDecl(void) = delete;

  ClassTemplatePartialSpecializationDecl(const DeclBase &) = delete;
  ClassTemplatePartialSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassTemplatePartialSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassTemplatePartialSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ClassTemplatePartialSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ClassTemplatePartialSpecializationDecl *decl_);
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
  // IsClassScopeExplicitSpecialization
  // IsExplicitInstantiationOrSpecialization
  // IsExplicitSpecialization
 private:
  ClassTemplateSpecializationDecl(void) = delete;

  ClassTemplateSpecializationDecl(const DeclBase &) = delete;
  ClassTemplateSpecializationDecl(DeclBase &&) noexcept = delete;
  ClassTemplateSpecializationDecl &operator=(const DeclBase &) = delete;
  ClassTemplateSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ClassTemplateSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ClassTemplateSpecializationDecl *decl_);
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
  // IsTypeConcept
 private:
  ConceptDecl(void) = delete;

  ConceptDecl(const DeclBase &) = delete;
  ConceptDecl(DeclBase &&) noexcept = delete;
  ConceptDecl &operator=(const DeclBase &) = delete;
  ConceptDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ConceptDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ConceptDecl *decl_);
};

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 public:
  ~ConstructorUsingShadowDecl(void) = default;
  ConstructorUsingShadowDecl(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl(ConstructorUsingShadowDecl &&) noexcept = default;
  ConstructorUsingShadowDecl &operator=(const ConstructorUsingShadowDecl &) = default;
  ConstructorUsingShadowDecl &operator=(ConstructorUsingShadowDecl &&) noexcept = default;

  // ConstructsVirtualBase
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
  ConstructorUsingShadowDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ConstructorUsingShadowDecl *decl_);
};

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
  // Location
  // ModuleOwnershipKind
  // MostRecentDecl
  // NextDeclInContext
  // NonClosureContext
  // OwningModule
  // OwningModuleID
  // PreviousDecl
  // TokenRange
  // TranslationUnitDecl
  // HasAttrs
  // HasBody
  // HasOwningModule
  // HasTagIdentifierNamespace
  // IsCanonicalDecl
  // IsDefinedOutsideFunctionOrMethod
  // IsDeprecated
  // IsFirstDecl
  // IsFromASTFile
  // IsFunctionOrFunctionTemplate
  // IsImplicit
  // IsInIdentifierNamespace
  // IsInvalidDecl
  // IsModulePrivate
  // IsTemplateParameter
  // IsThisDeclarationReferenced
  // IsTopLevelDeclInObjCContainer
  // IsUnavailable
  // IsUnconditionallyVisible
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
  Decl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::Decl *decl_);
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
  // HasExternalLexicalStorage
  // HasExternalVisibleStorage
  // IsClosure
  // IsDeclInLexicalTraversal
  // IsFileContext
  // IsFunctionOrMethod
  // IsLookupContext
  // IsNamespace
  // IsObjCContainer
  // IsRecord
  // IsTranslationUnit
  // Noload_decls
  // ShouldUseQualifiedLookup
 private:
  DeclContext(void) = delete;

  DeclContext(const DeclBase &) = delete;
  DeclContext(DeclBase &&) noexcept = delete;
  DeclContext &operator=(const DeclBase &) = delete;
  DeclContext &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  DeclContext(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::DeclContext *decl_);
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
  DeclaratorDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::DeclaratorDecl *decl_);
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
  DecompositionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::DecompositionDecl *decl_);
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
  EmptyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::EmptyDecl *decl_);
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
  EnumConstantDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::EnumConstantDecl *decl_);
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
  // IsComplete
  // IsFixed
  // IsScoped
  // IsScopedUsingClassTag
 private:
  EnumDecl(void) = delete;

  EnumDecl(const DeclBase &) = delete;
  EnumDecl(DeclBase &&) noexcept = delete;
  EnumDecl &operator=(const DeclBase &) = delete;
  EnumDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  EnumDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::EnumDecl *decl_);
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
  // HasBraces
 private:
  ExportDecl(void) = delete;

  ExportDecl(const DeclBase &) = delete;
  ExportDecl(DeclBase &&) noexcept = delete;
  ExportDecl &operator=(const DeclBase &) = delete;
  ExportDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ExportDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ExportDecl *decl_);
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
  ExternCContextDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ExternCContextDecl *decl_);
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
  // HasCapturedVLAType
  // HasInClassInitializer
  // IsBitField
  // IsMutable
  // IsUnnamedBitfield
 private:
  FieldDecl(void) = delete;

  FieldDecl(const DeclBase &) = delete;
  FieldDecl(DeclBase &&) noexcept = delete;
  FieldDecl &operator=(const DeclBase &) = delete;
  FieldDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  FieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FieldDecl *decl_);
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
  FileScopeAsmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FileScopeAsmDecl *decl_);
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
  // IsUnsupportedFriend
 private:
  FriendDecl(void) = delete;

  FriendDecl(const DeclBase &) = delete;
  FriendDecl(DeclBase &&) noexcept = delete;
  FriendDecl &operator=(const DeclBase &) = delete;
  FriendDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  FriendDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FriendDecl *decl_);
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
  FriendTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FriendTemplateDecl *decl_);
};

class FunctionDecl : public DeclaratorDecl, public DeclContext {
 public:
  ~FunctionDecl(void) = default;
  FunctionDecl(const FunctionDecl &) = default;
  FunctionDecl(FunctionDecl &&) noexcept = default;
  FunctionDecl &operator=(const FunctionDecl &) = default;
  FunctionDecl &operator=(FunctionDecl &&) noexcept = default;

  // DoesThisDeclarationHaveABody
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
  // HasBody
  // HasImplicitReturnZero
  // HasInheritedPrototype
  // HasPrototype
  // HasSkippedBody
  // HasWrittenPrototype
  // InstantiationIsPending
  // IsConsteval
  // IsConstexpr
  // IsConstexprSpecified
  // IsDefaulted
  // IsDefined
  // IsDeleted
  // IsDeletedAsWritten
  // IsExplicitlyDefaulted
  // IsFunctionTemplateSpecialization
  // IsInlineSpecified
  // IsInlined
  // IsLateTemplateParsed
  // IsMultiVersion
  // IsOverloadedOperator
  // IsPure
  // IsStatic
  // IsThisDeclarationADefinition
  // IsTrivial
  // IsTrivialForCall
  // IsUserProvided
  // IsVirtualAsWritten
  // Parameters
  // UsesFPIntrin
  // UsesSEHTry
  // WillHaveBody
 private:
  FunctionDecl(void) = delete;

  FunctionDecl(const DeclBase &) = delete;
  FunctionDecl(DeclBase &&) noexcept = delete;
  FunctionDecl &operator=(const DeclBase &) = delete;
  FunctionDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  FunctionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FunctionDecl *decl_);
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
  // IsAbbreviated
  // IsThisDeclarationADefinition
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
  FunctionTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::FunctionTemplateDecl *decl_);
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
  ImplicitParamDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ImplicitParamDecl *decl_);
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
  ImportDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ImportDecl *decl_);
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
  IndirectFieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::IndirectFieldDecl *decl_);
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
  // IsGnuLocal
  // IsMSAsmLabel
  // IsResolvedMSAsmLabel
 private:
  LabelDecl(void) = delete;

  LabelDecl(const DeclBase &) = delete;
  LabelDecl(DeclBase &&) noexcept = delete;
  LabelDecl &operator=(const DeclBase &) = delete;
  LabelDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  LabelDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::LabelDecl *decl_);
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
  LifetimeExtendedTemporaryDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::LifetimeExtendedTemporaryDecl *decl_);
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
  // HasBraces
 private:
  LinkageSpecDecl(void) = delete;

  LinkageSpecDecl(const DeclBase &) = delete;
  LinkageSpecDecl(DeclBase &&) noexcept = delete;
  LinkageSpecDecl &operator=(const DeclBase &) = delete;
  LinkageSpecDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  LinkageSpecDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::LinkageSpecDecl *decl_);
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
  MSGuidDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::MSGuidDecl *decl_);
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
  // HasGetter
  // HasSetter
 private:
  MSPropertyDecl(void) = delete;

  MSPropertyDecl(const DeclBase &) = delete;
  MSPropertyDecl(DeclBase &&) noexcept = delete;
  MSPropertyDecl &operator=(const DeclBase &) = delete;
  MSPropertyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  MSPropertyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::MSPropertyDecl *decl_);
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
  // HasExternalFormalLinkage
  // HasLinkageBeenComputed
  // IsCXXClassMember
  // IsExternallyDeclarable
  // IsExternallyVisible
 private:
  NamedDecl(void) = delete;

  NamedDecl(const DeclBase &) = delete;
  NamedDecl(DeclBase &&) noexcept = delete;
  NamedDecl &operator=(const DeclBase &) = delete;
  NamedDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  NamedDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::NamedDecl *decl_);
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
  NamespaceAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::NamespaceAliasDecl *decl_);
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
  // IsAnonymousNamespace
  // IsInline
 private:
  NamespaceDecl(void) = delete;

  NamespaceDecl(const DeclBase &) = delete;
  NamespaceDecl(DeclBase &&) noexcept = delete;
  NamespaceDecl &operator=(const DeclBase &) = delete;
  NamespaceDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  NamespaceDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::NamespaceDecl *decl_);
};

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 public:
  ~NonTypeTemplateParmDecl(void) = default;
  NonTypeTemplateParmDecl(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl(NonTypeTemplateParmDecl &&) noexcept = default;
  NonTypeTemplateParmDecl &operator=(const NonTypeTemplateParmDecl &) = default;
  NonTypeTemplateParmDecl &operator=(NonTypeTemplateParmDecl &&) noexcept = default;

  // DefaultArgumentWasInherited
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionType
  // ExpansionTypeSourceInfo
  // NumExpansionTypes
  // PlaceholderTypeConstraint
  // HasDefaultArgument
  // HasPlaceholderTypeConstraint
  // IsExpandedParameterPack
  // IsPackExpansion
  // IsParameterPack
 private:
  NonTypeTemplateParmDecl(void) = delete;

  NonTypeTemplateParmDecl(const DeclBase &) = delete;
  NonTypeTemplateParmDecl(DeclBase &&) noexcept = delete;
  NonTypeTemplateParmDecl &operator=(const DeclBase &) = delete;
  NonTypeTemplateParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  NonTypeTemplateParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::NonTypeTemplateParmDecl *decl_);
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
  OMPAllocateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPAllocateDecl *decl_);
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
  OMPCapturedExprDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPCapturedExprDecl *decl_);
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
  OMPDeclareMapperDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPDeclareMapperDecl *decl_);
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
  OMPDeclareReductionDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPDeclareReductionDecl *decl_);
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
  OMPRequiresDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPRequiresDecl *decl_);
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
  OMPThreadPrivateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::OMPThreadPrivateDecl *decl_);
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
  ObjCAtDefsFieldDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCAtDefsFieldDecl *decl_);
};

class ObjCCategoryDecl : public ObjCContainerDecl {
 public:
  ~ObjCCategoryDecl(void) = default;
  ObjCCategoryDecl(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl(ObjCCategoryDecl &&) noexcept = default;
  ObjCCategoryDecl &operator=(const ObjCCategoryDecl &) = default;
  ObjCCategoryDecl &operator=(ObjCCategoryDecl &&) noexcept = default;

  // IsClassExtension
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
  ObjCCategoryDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCCategoryDecl *decl_);
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
  ObjCCategoryImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCCategoryImplDecl *decl_);
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
  ObjCCompatibleAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCCompatibleAliasDecl *decl_);
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
  ObjCContainerDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCContainerDecl *decl_);
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
  ObjCImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCImplDecl *decl_);
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
  // HasDestructors
  // HasNonZeroConstructors
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
  ObjCImplementationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCImplementationDecl *decl_);
};

class ObjCInterfaceDecl : public ObjCContainerDecl {
 public:
  ~ObjCInterfaceDecl(void) = default;
  ObjCInterfaceDecl(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl(ObjCInterfaceDecl &&) noexcept = default;
  ObjCInterfaceDecl &operator=(const ObjCInterfaceDecl &) = default;
  ObjCInterfaceDecl &operator=(ObjCInterfaceDecl &&) noexcept = default;

  // All_referenced_protocols
  // DeclaresOrInheritsDesignatedInitializers
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
  // HasDefinition
  // IsImplicitInterfaceDecl
  // IsSuperClassOf
  // IsThisDeclarationADefinition
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
  ObjCInterfaceDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCInterfaceDecl *decl_);
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
  // Synthesize
 private:
  ObjCIvarDecl(void) = delete;

  ObjCIvarDecl(const DeclBase &) = delete;
  ObjCIvarDecl(DeclBase &&) noexcept = delete;
  ObjCIvarDecl &operator=(const DeclBase &) = delete;
  ObjCIvarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ObjCIvarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCIvarDecl *decl_);
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
  // HasBody
  // HasRedeclaration
  // HasRelatedResultType
  // HasSkippedBody
  // IsClassMethod
  // IsDefined
  // IsInstanceMethod
  // IsOptional
  // IsOverriding
  // IsPropertyAccessor
  // IsRedeclaration
  // IsSynthesizedAccessorStub
  // IsThisDeclarationADefinition
  // IsVariadic
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
  ObjCMethodDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCMethodDecl *decl_);
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
  // IsAtomic
  // IsClassProperty
  // IsDirectProperty
  // IsInstanceProperty
  // IsOptional
  // IsReadOnly
  // IsRetaining
 private:
  ObjCPropertyDecl(void) = delete;

  ObjCPropertyDecl(const DeclBase &) = delete;
  ObjCPropertyDecl(DeclBase &&) noexcept = delete;
  ObjCPropertyDecl &operator=(const DeclBase &) = delete;
  ObjCPropertyDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ObjCPropertyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCPropertyDecl *decl_);
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
  // IsIvarNameSpecified
 private:
  ObjCPropertyImplDecl(void) = delete;

  ObjCPropertyImplDecl(const DeclBase &) = delete;
  ObjCPropertyImplDecl(DeclBase &&) noexcept = delete;
  ObjCPropertyImplDecl &operator=(const DeclBase &) = delete;
  ObjCPropertyImplDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ObjCPropertyImplDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCPropertyImplDecl *decl_);
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
  // HasDefinition
  // IsThisDeclarationADefinition
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
  ObjCProtocolDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCProtocolDecl *decl_);
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
  // HasExplicitBound
 private:
  ObjCTypeParamDecl(void) = delete;

  ObjCTypeParamDecl(const DeclBase &) = delete;
  ObjCTypeParamDecl(DeclBase &&) noexcept = delete;
  ObjCTypeParamDecl &operator=(const DeclBase &) = delete;
  ObjCTypeParamDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ObjCTypeParamDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ObjCTypeParamDecl *decl_);
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
  // HasInheritedDefaultArg
  // HasUninstantiatedDefaultArg
  // HasUnparsedDefaultArg
  // IsKNRPromoted
  // IsObjCMethodParameter
 private:
  ParmVarDecl(void) = delete;

  ParmVarDecl(const DeclBase &) = delete;
  ParmVarDecl(DeclBase &&) noexcept = delete;
  ParmVarDecl &operator=(const DeclBase &) = delete;
  ParmVarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  ParmVarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ParmVarDecl *decl_);
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
  PragmaCommentDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::PragmaCommentDecl *decl_);
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
  PragmaDetectMismatchDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::PragmaDetectMismatchDecl *decl_);
};

class RecordDecl : public TagDecl {
 public:
  ~RecordDecl(void) = default;
  RecordDecl(const RecordDecl &) = default;
  RecordDecl(RecordDecl &&) noexcept = default;
  RecordDecl &operator=(const RecordDecl &) = default;
  RecordDecl &operator=(RecordDecl &&) noexcept = default;

  // CanPassInRegisters
  // Fields
  // ArgPassingRestrictions
  // Definition
  // MostRecentDecl
  // PreviousDecl
  // HasFlexibleArrayMember
  // HasLoadedFieldsFromExternalStorage
  // HasNonTrivialToPrimitiveCopyCUnion
  // HasNonTrivialToPrimitiveDefaultInitializeCUnion
  // HasNonTrivialToPrimitiveDestructCUnion
  // HasObjectMember
  // HasVolatileMember
  // IsAnonymousStructOrUnion
  // IsNonTrivialToPrimitiveCopy
  // IsNonTrivialToPrimitiveDefaultInitialize
  // IsNonTrivialToPrimitiveDestroy
  // IsParamDestroyedInCallee
 private:
  RecordDecl(void) = delete;

  RecordDecl(const DeclBase &) = delete;
  RecordDecl(DeclBase &&) noexcept = delete;
  RecordDecl &operator=(const DeclBase &) = delete;
  RecordDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  RecordDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::RecordDecl *decl_);
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
  // IsMemberSpecialization
 private:
  RedeclarableTemplateDecl(void) = delete;

  RedeclarableTemplateDecl(const DeclBase &) = delete;
  RedeclarableTemplateDecl(DeclBase &&) noexcept = delete;
  RedeclarableTemplateDecl &operator=(const DeclBase &) = delete;
  RedeclarableTemplateDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  RedeclarableTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::RedeclarableTemplateDecl *decl_);
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
  RequiresExprBodyDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::RequiresExprBodyDecl *decl_);
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
  // IsFailed
 private:
  StaticAssertDecl(void) = delete;

  StaticAssertDecl(const DeclBase &) = delete;
  StaticAssertDecl(DeclBase &&) noexcept = delete;
  StaticAssertDecl &operator=(const DeclBase &) = delete;
  StaticAssertDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  StaticAssertDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::StaticAssertDecl *decl_);
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
  // HasNameForLinkage
  // IsBeingDefined
  // IsClass
  // IsCompleteDefinition
  // IsCompleteDefinitionRequired
  // IsDependentType
  // IsEmbeddedInDeclarator
  // IsEnum
  // IsFreeStanding
  // IsInterface
  // IsStruct
  // IsThisDeclarationADefinition
  // IsUnion
  // MayHaveOutOfDateDef
 private:
  TagDecl(void) = delete;

  TagDecl(const DeclBase &) = delete;
  TagDecl(DeclBase &&) noexcept = delete;
  TagDecl &operator=(const DeclBase &) = delete;
  TagDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  TagDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TagDecl *decl_);
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
  TemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TemplateDecl *decl_);
};

class TemplateTemplateParmDecl : public TemplateDecl {
 public:
  ~TemplateTemplateParmDecl(void) = default;
  TemplateTemplateParmDecl(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl(TemplateTemplateParmDecl &&) noexcept = default;
  TemplateTemplateParmDecl &operator=(const TemplateTemplateParmDecl &) = default;
  TemplateTemplateParmDecl &operator=(TemplateTemplateParmDecl &&) noexcept = default;

  // DefaultArgumentWasInherited
  // DefaultArgStorage
  // DefaultArgument
  // ExpansionTemplateParameters
  // NumExpansionTemplateParameters
  // TokenRange
  // HasDefaultArgument
  // IsExpandedParameterPack
  // IsPackExpansion
  // IsParameterPack
 private:
  TemplateTemplateParmDecl(void) = delete;

  TemplateTemplateParmDecl(const DeclBase &) = delete;
  TemplateTemplateParmDecl(DeclBase &&) noexcept = delete;
  TemplateTemplateParmDecl &operator=(const DeclBase &) = delete;
  TemplateTemplateParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  TemplateTemplateParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TemplateTemplateParmDecl *decl_);
};

class TemplateTypeParmDecl : public TypeDecl {
 public:
  ~TemplateTypeParmDecl(void) = default;
  TemplateTypeParmDecl(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl(TemplateTypeParmDecl &&) noexcept = default;
  TemplateTypeParmDecl &operator=(const TemplateTypeParmDecl &) = default;
  TemplateTypeParmDecl &operator=(TemplateTypeParmDecl &&) noexcept = default;

  // DefaultArgumentWasInherited
  // AssociatedConstraints
  // DefaultArgStorage
  // DefaultArgument
  // DefaultArgumentInfo
  // NumExpansionParameters
  // TypeConstraint
  // HasDefaultArgument
  // HasTypeConstraint
  // IsExpandedParameterPack
  // IsPackExpansion
  // WasDeclaredWithTypename
 private:
  TemplateTypeParmDecl(void) = delete;

  TemplateTypeParmDecl(const DeclBase &) = delete;
  TemplateTypeParmDecl(DeclBase &&) noexcept = delete;
  TemplateTypeParmDecl &operator=(const DeclBase &) = delete;
  TemplateTypeParmDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  TemplateTypeParmDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TemplateTypeParmDecl *decl_);
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
  TranslationUnitDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TranslationUnitDecl *decl_);
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
  TypeAliasDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TypeAliasDecl *decl_);
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
  TypeAliasTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TypeAliasTemplateDecl *decl_);
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
  TypeDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TypeDecl *decl_);
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
  TypedefDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TypedefDecl *decl_);
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
  // IsModed
  // IsTransparentTag
 private:
  TypedefNameDecl(void) = delete;

  TypedefNameDecl(const DeclBase &) = delete;
  TypedefNameDecl(DeclBase &&) noexcept = delete;
  TypedefNameDecl &operator=(const DeclBase &) = delete;
  TypedefNameDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  TypedefNameDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::TypedefNameDecl *decl_);
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
  // IsPackExpansion
 private:
  UnresolvedUsingTypenameDecl(void) = delete;

  UnresolvedUsingTypenameDecl(const DeclBase &) = delete;
  UnresolvedUsingTypenameDecl(DeclBase &&) noexcept = delete;
  UnresolvedUsingTypenameDecl &operator=(const DeclBase &) = delete;
  UnresolvedUsingTypenameDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  UnresolvedUsingTypenameDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UnresolvedUsingTypenameDecl *decl_);
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
  // IsAccessDeclaration
  // IsPackExpansion
 private:
  UnresolvedUsingValueDecl(void) = delete;

  UnresolvedUsingValueDecl(const DeclBase &) = delete;
  UnresolvedUsingValueDecl(DeclBase &&) noexcept = delete;
  UnresolvedUsingValueDecl &operator=(const DeclBase &) = delete;
  UnresolvedUsingValueDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  UnresolvedUsingValueDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UnresolvedUsingValueDecl *decl_);
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
  // HasTypename
  // IsAccessDeclaration
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
  UsingDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UsingDecl *decl_);
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
  UsingDirectiveDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UsingDirectiveDecl *decl_);
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
  UsingPackDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UsingPackDecl *decl_);
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
  UsingShadowDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::UsingShadowDecl *decl_);
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
  ValueDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::ValueDecl *decl_);
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
  // HasExternalStorage
  // HasGlobalStorage
  // HasLocalStorage
  // IsARCPseudoStrong
  // IsCXXForRangeDecl
  // IsConstexpr
  // IsDirectInit
  // IsExceptionVariable
  // IsFileVarDecl
  // IsFunctionOrMethodVarDecl
  // IsInitCapture
  // IsInline
  // IsInlineSpecified
  // IsLocalVarDecl
  // IsLocalVarDeclOrParm
  // IsNRVOVariable
  // IsObjCForDecl
  // IsPreviousDeclInSameBlockScope
  // IsStaticDataMember
  // IsStaticLocal
  // IsThisDeclarationADefinition
  // IsThisDeclarationADemotedDefinition
 private:
  VarDecl(void) = delete;

  VarDecl(const DeclBase &) = delete;
  VarDecl(DeclBase &&) noexcept = delete;
  VarDecl &operator=(const DeclBase &) = delete;
  VarDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  VarDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::VarDecl *decl_);
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
  // IsThisDeclarationADefinition
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
  VarTemplateDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::VarTemplateDecl *decl_);
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
  // HasAssociatedConstraints
 private:
  VarTemplatePartialSpecializationDecl(void) = delete;

  VarTemplatePartialSpecializationDecl(const DeclBase &) = delete;
  VarTemplatePartialSpecializationDecl(DeclBase &&) noexcept = delete;
  VarTemplatePartialSpecializationDecl &operator=(const DeclBase &) = delete;
  VarTemplatePartialSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  VarTemplatePartialSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::VarTemplatePartialSpecializationDecl *decl_);
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
  // IsClassScopeExplicitSpecialization
  // IsExplicitInstantiationOrSpecialization
  // IsExplicitSpecialization
 private:
  VarTemplateSpecializationDecl(void) = delete;

  VarTemplateSpecializationDecl(const DeclBase &) = delete;
  VarTemplateSpecializationDecl(DeclBase &&) noexcept = delete;
  VarTemplateSpecializationDecl &operator=(const DeclBase &) = delete;
  VarTemplateSpecializationDecl &operator=(DeclBase &&) noexcept = delete;

  friend class AST;
  friend class ASTImpl;
  friend class DeclBase;
  VarTemplateSpecializationDecl(
      const std::shared_ptr<ASTImpl> &ast_,
      ::clang::VarTemplateSpecializationDecl *decl_);
};

}  // namespace pasta
