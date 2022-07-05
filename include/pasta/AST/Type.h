/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

// This file is auto-generated.

#pragma once

#ifdef PASTA_IN_BOOTSTRAP
#  include "TypeBootstrap.h"
#else
#include <variant>
#include <vector>
#include <pasta/Util/Compiler.h>
#include "Forward.h"

#define PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(base) \
    friend class AST; \
    friend class ASTImpl; \
    friend class TypeBuilder; \
    friend class TypeVisitor; \
    friend class PrintedTokenRange; \
    base(void) = delete; \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::Type *type_); \
    explicit base( \
        std::shared_ptr<ASTImpl> ast_, \
        const ::clang::QualType &type_); \
   public: \
    inline const clang::base *RawType(void) const noexcept { \
      return u.base; \
    }

namespace pasta {
class TypeBuilder;

class TypeVisitor {
 public:
  virtual ~TypeVisitor(void);
  void Accept(const Type &);
  virtual void VisitType(const Type &);
  virtual void VisitTypeOfExprType(const TypeOfExprType &);
  virtual void VisitTypeOfType(const TypeOfType &);
  virtual void VisitTypedefType(const TypedefType &);
  virtual void VisitUnaryTransformType(const UnaryTransformType &);
  virtual void VisitUnresolvedUsingType(const UnresolvedUsingType &);
  virtual void VisitUsingType(const UsingType &);
  virtual void VisitVectorType(const VectorType &);
  virtual void VisitTypeWithKeyword(const TypeWithKeyword &);
  virtual void VisitAdjustedType(const AdjustedType &);
  virtual void VisitArrayType(const ArrayType &);
  virtual void VisitAtomicType(const AtomicType &);
  virtual void VisitAttributedType(const AttributedType &);
  virtual void VisitBitIntType(const BitIntType &);
  virtual void VisitBlockPointerType(const BlockPointerType &);
  virtual void VisitBuiltinType(const BuiltinType &);
  virtual void VisitComplexType(const ComplexType &);
  virtual void VisitConstantArrayType(const ConstantArrayType &);
  virtual void VisitDecayedType(const DecayedType &);
  virtual void VisitDecltypeType(const DecltypeType &);
  virtual void VisitDeducedType(const DeducedType &);
  virtual void VisitDependentAddressSpaceType(const DependentAddressSpaceType &);
  virtual void VisitDependentBitIntType(const DependentBitIntType &);
  virtual void VisitDependentNameType(const DependentNameType &);
  virtual void VisitDependentSizedArrayType(const DependentSizedArrayType &);
  virtual void VisitDependentSizedExtVectorType(const DependentSizedExtVectorType &);
  virtual void VisitDependentTemplateSpecializationType(const DependentTemplateSpecializationType &);
  virtual void VisitDependentVectorType(const DependentVectorType &);
  virtual void VisitElaboratedType(const ElaboratedType &);
  virtual void VisitExtVectorType(const ExtVectorType &);
  virtual void VisitFunctionType(const FunctionType &);
  virtual void VisitIncompleteArrayType(const IncompleteArrayType &);
  virtual void VisitInjectedClassNameType(const InjectedClassNameType &);
  virtual void VisitMacroQualifiedType(const MacroQualifiedType &);
  virtual void VisitMatrixType(const MatrixType &);
  virtual void VisitMemberPointerType(const MemberPointerType &);
  virtual void VisitObjCObjectPointerType(const ObjCObjectPointerType &);
  virtual void VisitObjCObjectType(const ObjCObjectType &);
  virtual void VisitObjCTypeParamType(const ObjCTypeParamType &);
  virtual void VisitPackExpansionType(const PackExpansionType &);
  virtual void VisitParenType(const ParenType &);
  virtual void VisitPipeType(const PipeType &);
  virtual void VisitPointerType(const PointerType &);
  virtual void VisitReferenceType(const ReferenceType &);
  virtual void VisitSubstTemplateTypeParmPackType(const SubstTemplateTypeParmPackType &);
  virtual void VisitSubstTemplateTypeParmType(const SubstTemplateTypeParmType &);
  virtual void VisitTagType(const TagType &);
  virtual void VisitTemplateSpecializationType(const TemplateSpecializationType &);
  virtual void VisitTemplateTypeParmType(const TemplateTypeParmType &);
  virtual void VisitVariableArrayType(const VariableArrayType &);
  virtual void VisitAutoType(const AutoType &);
  virtual void VisitConstantMatrixType(const ConstantMatrixType &);
  virtual void VisitDeducedTemplateSpecializationType(const DeducedTemplateSpecializationType &);
  virtual void VisitDependentSizedMatrixType(const DependentSizedMatrixType &);
  virtual void VisitEnumType(const EnumType &);
  virtual void VisitFunctionNoProtoType(const FunctionNoProtoType &);
  virtual void VisitFunctionProtoType(const FunctionProtoType &);
  virtual void VisitLValueReferenceType(const LValueReferenceType &);
  virtual void VisitObjCInterfaceType(const ObjCInterfaceType &);
  virtual void VisitRValueReferenceType(const RValueReferenceType &);
  virtual void VisitRecordType(const RecordType &);
};

// Wraps a type, including its qualifiers.
class Type {
 protected:
  friend class TypeBuilder;
  friend class PrintedTokenRange;

  friend class TokenContext;
  std::shared_ptr<ASTImpl> ast;
  union {
    const ::clang::Type *Type;
    const ::clang::TypeOfExprType *TypeOfExprType;
    const ::clang::TypeOfType *TypeOfType;
    const ::clang::TypedefType *TypedefType;
    const ::clang::UnaryTransformType *UnaryTransformType;
    const ::clang::UnresolvedUsingType *UnresolvedUsingType;
    const ::clang::UsingType *UsingType;
    const ::clang::VectorType *VectorType;
    const ::clang::TypeWithKeyword *TypeWithKeyword;
    const ::clang::AdjustedType *AdjustedType;
    const ::clang::ArrayType *ArrayType;
    const ::clang::AtomicType *AtomicType;
    const ::clang::AttributedType *AttributedType;
    const ::clang::BitIntType *BitIntType;
    const ::clang::BlockPointerType *BlockPointerType;
    const ::clang::BuiltinType *BuiltinType;
    const ::clang::ComplexType *ComplexType;
    const ::clang::ConstantArrayType *ConstantArrayType;
    const ::clang::DecayedType *DecayedType;
    const ::clang::DecltypeType *DecltypeType;
    const ::clang::DeducedType *DeducedType;
    const ::clang::DependentAddressSpaceType *DependentAddressSpaceType;
    const ::clang::DependentBitIntType *DependentBitIntType;
    const ::clang::DependentNameType *DependentNameType;
    const ::clang::DependentSizedArrayType *DependentSizedArrayType;
    const ::clang::DependentSizedExtVectorType *DependentSizedExtVectorType;
    const ::clang::DependentTemplateSpecializationType *DependentTemplateSpecializationType;
    const ::clang::DependentVectorType *DependentVectorType;
    const ::clang::ElaboratedType *ElaboratedType;
    const ::clang::ExtVectorType *ExtVectorType;
    const ::clang::FunctionType *FunctionType;
    const ::clang::IncompleteArrayType *IncompleteArrayType;
    const ::clang::InjectedClassNameType *InjectedClassNameType;
    const ::clang::MacroQualifiedType *MacroQualifiedType;
    const ::clang::MatrixType *MatrixType;
    const ::clang::MemberPointerType *MemberPointerType;
    const ::clang::ObjCObjectPointerType *ObjCObjectPointerType;
    const ::clang::ObjCObjectType *ObjCObjectType;
    const ::clang::ObjCTypeParamType *ObjCTypeParamType;
    const ::clang::PackExpansionType *PackExpansionType;
    const ::clang::ParenType *ParenType;
    const ::clang::PipeType *PipeType;
    const ::clang::PointerType *PointerType;
    const ::clang::ReferenceType *ReferenceType;
    const ::clang::SubstTemplateTypeParmPackType *SubstTemplateTypeParmPackType;
    const ::clang::SubstTemplateTypeParmType *SubstTemplateTypeParmType;
    const ::clang::TagType *TagType;
    const ::clang::TemplateSpecializationType *TemplateSpecializationType;
    const ::clang::TemplateTypeParmType *TemplateTypeParmType;
    const ::clang::VariableArrayType *VariableArrayType;
    const ::clang::AutoType *AutoType;
    const ::clang::ConstantMatrixType *ConstantMatrixType;
    const ::clang::DeducedTemplateSpecializationType *DeducedTemplateSpecializationType;
    const ::clang::DependentSizedMatrixType *DependentSizedMatrixType;
    const ::clang::EnumType *EnumType;
    const ::clang::FunctionNoProtoType *FunctionNoProtoType;
    const ::clang::FunctionProtoType *FunctionProtoType;
    const ::clang::LValueReferenceType *LValueReferenceType;
    const ::clang::ObjCInterfaceType *ObjCInterfaceType;
    const ::clang::RValueReferenceType *RValueReferenceType;
    const ::clang::RecordType *RecordType;
    void *opaque;
  } u;
  ::pasta::TypeKind kind;
  uint32_t qualifiers;

  inline explicit Type(std::shared_ptr<ASTImpl> ast_,
                       const ::clang::Type *type_,
                       ::pasta::TypeKind kind_,
                       uint32_t qualifiers_)
      : ast(std::move(ast_)),
        kind(kind_),
        qualifiers(qualifiers_) {
    assert(ast.get() != nullptr);
    u.Type = type_;
  }

 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Type)
  inline const clang::Type *RawType(void) const noexcept {
    return u.Type;
  }
  inline uint32_t RawQualifiers(void) const noexcept {
    return qualifiers;
  }
  static std::optional<::pasta::Type> From(const TokenContext &);
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AdjustedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AtomicType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AttributedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AutoType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, BitIntType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, BlockPointerType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, BuiltinType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ComplexType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ConstantArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ConstantMatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DecayedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DecltypeType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DeducedTemplateSpecializationType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DeducedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentAddressSpaceType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentBitIntType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentNameType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedExtVectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedMatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentTemplateSpecializationType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentVectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ElaboratedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, EnumType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ExtVectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, FunctionNoProtoType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, FunctionProtoType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, FunctionType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, IncompleteArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, InjectedClassNameType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, LValueReferenceType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, MacroQualifiedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, MatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, MemberPointerType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ObjCInterfaceType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ObjCObjectPointerType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ObjCObjectType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ObjCTypeParamType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, PackExpansionType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ParenType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, PipeType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, PointerType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, RValueReferenceType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, RecordType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ReferenceType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, SubstTemplateTypeParmPackType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, SubstTemplateTypeParmType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TagType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TemplateSpecializationType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TemplateTypeParmType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TypeOfExprType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TypeOfType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TypeWithKeyword)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, TypedefType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, UnaryTransformType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, UnresolvedUsingType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, UsingType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, VariableArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, VectorType)
  inline bool operator==(const Type &that) const noexcept {
    return u.opaque == that.u.opaque && qualifiers == that.qualifiers;
  }
  inline bool operator!=(const Type &that) const noexcept {
    return u.opaque != that.u.opaque || qualifiers != that.qualifiers;
  }
  inline bool IsQualified(void) const noexcept {
    return qualifiers;
  }
  inline Type UnqualifiedType(void) const noexcept {
    return Type(ast, u.Type, kind, 0);
  }

  /* Type methods */
  bool AcceptsObjCTypeParameters(void) const noexcept;
  bool CanDecayToPointerType(void) const noexcept;
  bool CanHaveNullability(void) const noexcept;
  bool ContainsErrors(void) const noexcept;
  bool ContainsUnexpandedParameterPack(void) const noexcept;
  std::optional<::pasta::Type> ArrayElementTypeNoTypeQualified(void) const noexcept;
  std::optional<::pasta::CXXRecordDecl> AsCXXRecordDeclaration(void) const noexcept;
  std::optional<::pasta::ComplexType> AsComplexIntegerType(void) const noexcept;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCInterfacePointerType(void) const noexcept;
  std::optional<::pasta::ObjCObjectType> AsObjCInterfaceType(void) const noexcept;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCQualifiedClassType(void) const noexcept;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCQualifiedIdType(void) const noexcept;
  std::optional<::pasta::ObjCObjectType> AsObjCQualifiedInterfaceType(void) const noexcept;
  std::optional<::pasta::BuiltinType> AsPlaceholderType(void) const noexcept;
  std::optional<::pasta::RecordDecl> AsRecordDeclaration(void) const noexcept;
  std::optional<::pasta::RecordType> AsStructureType(void) const noexcept;
  std::optional<::pasta::TagDecl> AsTagDeclaration(void) const noexcept;
  std::optional<::pasta::RecordType> AsUnionType(void) const noexcept;
  ::pasta::Type CanonicalTypeInternal(void) const noexcept;
  // CanonicalTypeUnqualified: (clang::CanQual<clang::Type>)
  std::optional<::pasta::AutoType> ContainedAutoType(void) const noexcept;
  std::optional<::pasta::DeducedType> ContainedDeducedType(void) const noexcept;
  // Dependence: (clang::TypeDependenceScope::TypeDependence)
  enum Linkage Linkage(void) const noexcept;
  // LinkageAndVisibility: (clang::LinkageInfo)
  ::pasta::Type LocallyUnqualifiedSingleStepDesugaredType(void) const noexcept;
  std::optional<::pasta::NullabilityKind> Nullability(void) const noexcept;
  // ObjCARCImplicitLifetime: (clang::Qualifiers::ObjCLifetime)
  // ObjCSubstitutions: (llvm::Optional<llvm::ArrayRef<clang::QualType>>)
  std::optional<::pasta::CXXRecordDecl> PointeeCXXRecordDeclaration(void) const noexcept;
  std::optional<::pasta::Type> PointeeOrArrayElementType(void) const noexcept;
  std::optional<::pasta::Type> PointeeType(void) const noexcept;
  std::optional<enum TypeScalarTypeKind> ScalarTypeKind(void) const noexcept;
  std::optional<::pasta::Type> SveElementType(void) const noexcept;
  ::pasta::TypeKind Kind(void) const noexcept;
  std::string_view KindName(void) const noexcept;
  ::pasta::Type UnqualifiedDesugaredType(void) const noexcept;
  enum Visibility Visibility(void) const noexcept;
  // HasAttribute: (bool)
  bool HasAutoForTrailingReturnType(void) const noexcept;
  bool HasFloatingRepresentation(void) const noexcept;
  bool HasIntegerRepresentation(void) const noexcept;
  bool HasObjCPointerRepresentation(void) const noexcept;
  bool HasPointerRepresentation(void) const noexcept;
  bool HasSignedIntegerRepresentation(void) const noexcept;
  bool HasSizedVLAType(void) const noexcept;
  bool HasUnnamedOrLocalType(void) const noexcept;
  bool HasUnsignedIntegerRepresentation(void) const noexcept;
  std::optional<bool> IsAggregateType(void) const noexcept;
  bool IsAlignValueT(void) const noexcept;
  bool IsAnyCharacterType(void) const noexcept;
  bool IsAnyComplexType(void) const noexcept;
  bool IsAnyPointerType(void) const noexcept;
  bool IsArithmeticType(void) const noexcept;
  bool IsArrayType(void) const noexcept;
  bool IsAtomicType(void) const noexcept;
  bool IsBFloat16Type(void) const noexcept;
  bool IsBitIntType(void) const noexcept;
  bool IsBlockCompatibleObjCPointerType(void) const noexcept;
  bool IsBlockPointerType(void) const noexcept;
  bool IsBooleanType(void) const noexcept;
  bool IsBuiltinType(void) const noexcept;
  bool IsCARCBridgableType(void) const noexcept;
  bool IsCUDADeviceBuiltinSurfaceType(void) const noexcept;
  bool IsCUDADeviceBuiltinTextureType(void) const noexcept;
  bool IsCanonicalUnqualified(void) const noexcept;
  bool IsChar16Type(void) const noexcept;
  bool IsChar32Type(void) const noexcept;
  bool IsChar8Type(void) const noexcept;
  bool IsCharacterType(void) const noexcept;
  bool IsClassType(void) const noexcept;
  bool IsClkEventT(void) const noexcept;
  bool IsComplexIntegerType(void) const noexcept;
  bool IsComplexType(void) const noexcept;
  bool IsCompoundType(void) const noexcept;
  bool IsConstantArrayType(void) const noexcept;
  bool IsConstantMatrixType(void) const noexcept;
  std::optional<bool> IsConstantSizeType(void) const noexcept;
  bool IsDecltypeType(void) const noexcept;
  bool IsDependentAddressSpaceType(void) const noexcept;
  bool IsDependentSizedArrayType(void) const noexcept;
  bool IsDependentType(void) const noexcept;
  bool IsElaboratedTypeSpecifier(void) const noexcept;
  bool IsEnumeralType(void) const noexcept;
  bool IsEventT(void) const noexcept;
  bool IsExtVectorType(void) const noexcept;
  bool IsFixedPointOrIntegerType(void) const noexcept;
  bool IsFixedPointType(void) const noexcept;
  bool IsFloat128Type(void) const noexcept;
  bool IsFloat16Type(void) const noexcept;
  bool IsFloatingType(void) const noexcept;
  bool IsFromAST(void) const noexcept;
  bool IsFunctionNoProtoType(void) const noexcept;
  bool IsFunctionPointerType(void) const noexcept;
  bool IsFunctionProtoType(void) const noexcept;
  bool IsFunctionReferenceType(void) const noexcept;
  bool IsFunctionType(void) const noexcept;
  bool IsFundamentalType(void) const noexcept;
  bool IsHalfType(void) const noexcept;
  bool IsIbm128Type(void) const noexcept;
  bool IsImageType(void) const noexcept;
  bool IsIncompleteArrayType(void) const noexcept;
  bool IsIncompleteOrObjectType(void) const noexcept;
  bool IsIncompleteType(void) const noexcept;
  bool IsInstantiationDependentType(void) const noexcept;
  bool IsIntegerType(void) const noexcept;
  bool IsIntegralOrEnumerationType(void) const noexcept;
  bool IsIntegralOrUnscopedEnumerationType(void) const noexcept;
  bool IsIntegralType(void) const noexcept;
  bool IsInterfaceType(void) const noexcept;
  bool IsLValueReferenceType(void) const noexcept;
  bool IsLinkageValid(void) const noexcept;
  std::optional<bool> IsLiteralType(void) const noexcept;
  bool IsMatrixType(void) const noexcept;
  bool IsMemberDataPointerType(void) const noexcept;
  bool IsMemberFunctionPointerType(void) const noexcept;
  bool IsMemberPointerType(void) const noexcept;
  bool IsNonOverloadPlaceholderType(void) const noexcept;
  bool IsNothrowT(void) const noexcept;
  bool IsNullPointerType(void) const noexcept;
  bool IsOCLExtOpaqueType(void) const noexcept;
  bool IsOCLImage1dArrayROType(void) const noexcept;
  bool IsOCLImage1dArrayRWType(void) const noexcept;
  bool IsOCLImage1dArrayWOType(void) const noexcept;
  bool IsOCLImage1dBufferROType(void) const noexcept;
  bool IsOCLImage1dBufferRWType(void) const noexcept;
  bool IsOCLImage1dBufferWOType(void) const noexcept;
  bool IsOCLImage1dROType(void) const noexcept;
  bool IsOCLImage1dRWType(void) const noexcept;
  bool IsOCLImage1dWOType(void) const noexcept;
  bool IsOCLImage2dArrayDepthROType(void) const noexcept;
  bool IsOCLImage2dArrayDepthRWType(void) const noexcept;
  bool IsOCLImage2dArrayDepthWOType(void) const noexcept;
  bool IsOCLImage2dArrayMSAADepthROType(void) const noexcept;
  bool IsOCLImage2dArrayMSAADepthRWType(void) const noexcept;
  bool IsOCLImage2dArrayMSAADepthWOType(void) const noexcept;
  bool IsOCLImage2dArrayMSAAROType(void) const noexcept;
  bool IsOCLImage2dArrayMSAARWType(void) const noexcept;
  bool IsOCLImage2dArrayMSAAWOType(void) const noexcept;
  bool IsOCLImage2dArrayROType(void) const noexcept;
  bool IsOCLImage2dArrayRWType(void) const noexcept;
  bool IsOCLImage2dArrayWOType(void) const noexcept;
  bool IsOCLImage2dDepthROType(void) const noexcept;
  bool IsOCLImage2dDepthRWType(void) const noexcept;
  bool IsOCLImage2dDepthWOType(void) const noexcept;
  bool IsOCLImage2dMSAADepthROType(void) const noexcept;
  bool IsOCLImage2dMSAADepthRWType(void) const noexcept;
  bool IsOCLImage2dMSAADepthWOType(void) const noexcept;
  bool IsOCLImage2dMSAAROType(void) const noexcept;
  bool IsOCLImage2dMSAARWType(void) const noexcept;
  bool IsOCLImage2dMSAAWOType(void) const noexcept;
  bool IsOCLImage2dROType(void) const noexcept;
  bool IsOCLImage2dRWType(void) const noexcept;
  bool IsOCLImage2dWOType(void) const noexcept;
  bool IsOCLImage3dROType(void) const noexcept;
  bool IsOCLImage3dRWType(void) const noexcept;
  bool IsOCLImage3dWOType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImeDualReferenceStreaminType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImePayloadType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImeResultType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCMcePayloadType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCMceResultType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCRefPayloadType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCRefResultType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCSicPayloadType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCSicResultType(void) const noexcept;
  bool IsOCLIntelSubgroupAVCType(void) const noexcept;
  bool IsObjCARCBridgableType(void) const noexcept;
  std::optional<bool> IsObjCARCImplicitlyUnretainedType(void) const noexcept;
  bool IsObjCBoxableRecordType(void) const noexcept;
  bool IsObjCBuiltinType(void) const noexcept;
  bool IsObjCClassOrClassKindOfType(void) const noexcept;
  bool IsObjCClassType(void) const noexcept;
  // IsObjCIdOrObjectKindOfType: (bool)
  bool IsObjCIdType(void) const noexcept;
  bool IsObjCIndependentClassType(void) const noexcept;
  bool IsObjCIndirectLifetimeType(void) const noexcept;
  bool IsObjCInertUnsafeUnretainedType(void) const noexcept;
  bool IsObjCLifetimeType(void) const noexcept;
  bool IsObjCNSObjectType(void) const noexcept;
  bool IsObjCObjectOrInterfaceType(void) const noexcept;
  bool IsObjCObjectPointerType(void) const noexcept;
  bool IsObjCObjectType(void) const noexcept;
  bool IsObjCQualifiedClassType(void) const noexcept;
  bool IsObjCQualifiedIdType(void) const noexcept;
  bool IsObjCQualifiedInterfaceType(void) const noexcept;
  bool IsObjCRetainableType(void) const noexcept;
  bool IsObjCSelType(void) const noexcept;
  bool IsObjectPointerType(void) const noexcept;
  bool IsObjectType(void) const noexcept;
  bool IsOpenCLSpecificType(void) const noexcept;
  bool IsOverloadableType(void) const noexcept;
  bool IsPipeType(void) const noexcept;
  bool IsPlaceholderType(void) const noexcept;
  bool IsPointerType(void) const noexcept;
  bool IsPromotableIntegerType(void) const noexcept;
  bool IsQueueT(void) const noexcept;
  bool IsRValueReferenceType(void) const noexcept;
  bool IsRealFloatingType(void) const noexcept;
  bool IsRealType(void) const noexcept;
  bool IsRecordType(void) const noexcept;
  bool IsReferenceType(void) const noexcept;
  bool IsReserveIDT(void) const noexcept;
  bool IsSamplerT(void) const noexcept;
  bool IsSaturatedFixedPointType(void) const noexcept;
  bool IsScalarType(void) const noexcept;
  bool IsScopedEnumeralType(void) const noexcept;
  bool IsSignedFixedPointType(void) const noexcept;
  bool IsSignedIntegerOrEnumerationType(void) const noexcept;
  bool IsSignedIntegerType(void) const noexcept;
  bool IsSizelessBuiltinType(void) const noexcept;
  bool IsSizelessType(void) const noexcept;
  // IsSpecificBuiltinType: (bool)
  // IsSpecificPlaceholderType: (bool)
  bool IsSpecifierType(void) const noexcept;
  std::optional<bool> IsStandardLayoutType(void) const noexcept;
  bool IsStdByteType(void) const noexcept;
  std::optional<bool> IsStructuralType(void) const noexcept;
  bool IsStructureOrClassType(void) const noexcept;
  bool IsStructureType(void) const noexcept;
  bool IsTemplateTypeParmType(void) const noexcept;
  bool IsTypedefNameType(void) const noexcept;
  bool IsUndeducedAutoType(void) const noexcept;
  bool IsUndeducedType(void) const noexcept;
  bool IsUnionType(void) const noexcept;
  bool IsUnsaturatedFixedPointType(void) const noexcept;
  bool IsUnscopedEnumerationType(void) const noexcept;
  bool IsUnsignedFixedPointType(void) const noexcept;
  bool IsUnsignedIntegerOrEnumerationType(void) const noexcept;
  bool IsUnsignedIntegerType(void) const noexcept;
  bool IsVLSTBuiltinType(void) const noexcept;
  bool IsVariableArrayType(void) const noexcept;
  bool IsVariablyModifiedType(void) const noexcept;
  bool IsVectorType(void) const noexcept;
  bool IsVisibilityExplicit(void) const noexcept;
  bool IsVoidPointerType(void) const noexcept;
  bool IsVoidType(void) const noexcept;
  bool IsWideCharacterType(void) const noexcept;

  /* QualType methods */
  ::pasta::Type IgnoreParentheses(void) const noexcept;
  enum LangAS AddressSpace(void) const noexcept;
  ::pasta::Type AtomicUnqualifiedType(void) const noexcept;
  // BaseTypeIdentifier: (const clang::IdentifierInfo *)
  uint32_t CVRQualifiers(void) const noexcept;
  ::pasta::Type CanonicalType(void) const noexcept;
  ::pasta::Type DesugaredType(void) const noexcept;
  uint32_t LocalCVRQualifiers(void) const noexcept;
  uint32_t LocalFastQualifiers(void) const noexcept;
  // LocalQualifiers: (clang::Qualifiers)
  ::pasta::Type LocalUnqualifiedType(void) const noexcept;
  ::pasta::Type NonLValueExpressionType(void) const noexcept;
  ::pasta::Type NonPackExpansionType(void) const noexcept;
  ::pasta::Type NonReferenceType(void) const noexcept;
  // ObjCGCAttr: (clang::Qualifiers::GC)
  // ObjCLifetime: (clang::Qualifiers::ObjCLifetime)
  // Qualifiers: (clang::Qualifiers)
  ::pasta::Type SingleStepDesugaredType(void) const noexcept;
  // SplitDesugaredType: (clang::SplitQualType)
  // SplitUnqualifiedType: (clang::SplitQualType)
  bool HasAddressSpace(void) const noexcept;
  bool HasLocalNonFastQualifiers(void) const noexcept;
  bool HasLocalQualifiers(void) const noexcept;
  bool HasNonTrivialObjCLifetime(void) const noexcept;
  bool HasNonTrivialToPrimitiveCopyCUnion(void) const noexcept;
  bool HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const noexcept;
  bool HasNonTrivialToPrimitiveDestructCUnion(void) const noexcept;
  bool HasQualifiers(void) const noexcept;
  bool HasStrongOrWeakObjCLifetime(void) const noexcept;
  // IsAddressSpaceOverlapping: (bool)
  // IsAtLeastAsQualifiedAs: (bool)
  bool IsCForbiddenLValueType(void) const noexcept;
  bool IsCXX11PODType(void) const noexcept;
  bool IsCXX98PODType(void) const noexcept;
  bool IsCanonical(void) const noexcept;
  bool IsCanonicalAsParameter(void) const noexcept;
  bool IsConstQualified(void) const noexcept;
  bool IsConstant(void) const noexcept;
  enum QualTypeDestructionKind IsDestructedType(void) const noexcept;
  bool IsLocalConstQualified(void) const noexcept;
  bool IsLocalRestrictQualified(void) const noexcept;
  bool IsLocalVolatileQualified(void) const noexcept;
  // IsMoreQualifiedThan: (bool)
  enum QualTypePrimitiveCopyKind IsNonTrivialToPrimitiveCopy(void) const noexcept;
  enum QualTypePrimitiveDefaultInitializeKind IsNonTrivialToPrimitiveDefaultInitialize(void) const noexcept;
  enum QualTypePrimitiveCopyKind IsNonTrivialToPrimitiveDestructiveMove(void) const noexcept;
  bool IsNonWeakInMRRWithObjCWeak(void) const noexcept;
  bool IsNull(void) const noexcept;
  bool IsObjCGCStrong(void) const noexcept;
  bool IsObjCGCWeak(void) const noexcept;
  bool IsPODType(void) const noexcept;
  bool IsRestrictQualified(void) const noexcept;
  bool IsTrivialType(void) const noexcept;
  bool IsTriviallyCopyableType(void) const noexcept;
  bool IsVolatileQualified(void) const noexcept;
  bool MayBeDynamicClass(void) const noexcept;
  bool MayBeNotDynamicClass(void) const noexcept;
  // Split: (clang::SplitQualType)
  // Stream: (clang::QualType::StreamedQualTypeHelper)
  ::pasta::Type StripObjCKindOfType(void) const noexcept;
  // SubstObjCMemberType: (clang::QualType)
  // SubstObjCTypeArguments: (clang::QualType)
  // WithCVRQualifiers: (clang::QualType)
  ::pasta::Type WithConst(void) const noexcept;
  // WithExactLocalFastQualifiers: (clang::QualType)
  // WithFastQualifiers: (clang::QualType)
  ::pasta::Type WithRestrict(void) const noexcept;
  ::pasta::Type WithVolatile(void) const noexcept;
  ::pasta::Type WithoutLocalFastQualifiers(void) const noexcept;
};

class TypeOfExprType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeOfExprType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TypeOfExprType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Expr UnderlyingExpression(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TypeOfExprType)
};
static_assert(sizeof(Type) == sizeof(TypeOfExprType));

class TypeOfType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeOfType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TypeOfType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TypeOfType)
};
static_assert(sizeof(Type) == sizeof(TypeOfType));

class TypedefType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypedefType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TypedefType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::TypedefNameDecl Declaration(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TypedefType)
};
static_assert(sizeof(Type) == sizeof(TypedefType));

class UnaryTransformType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnaryTransformType)
  PASTA_DECLARE_BASE_OPERATORS(Type, UnaryTransformType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type BaseType(void) const noexcept;
  enum UnaryTransformTypeUTTKind UTTKind(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(UnaryTransformType)
};
static_assert(sizeof(Type) == sizeof(UnaryTransformType));

class UnresolvedUsingType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UnresolvedUsingType)
  PASTA_DECLARE_BASE_OPERATORS(Type, UnresolvedUsingType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::UnresolvedUsingTypenameDecl Declaration(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(UnresolvedUsingType)
};
static_assert(sizeof(Type) == sizeof(UnresolvedUsingType));

class UsingType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(UsingType)
  PASTA_DECLARE_BASE_OPERATORS(Type, UsingType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::UsingShadowDecl FoundDeclaration(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(UsingType)
};
static_assert(sizeof(Type) == sizeof(UsingType));

class VectorType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, VectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(VectorType, ExtVectorType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  uint32_t NumElements(void) const noexcept;
  enum VectorTypeVectorKind VectorKind(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(VectorType)
};
static_assert(sizeof(Type) == sizeof(VectorType));

class TypeWithKeyword : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeWithKeyword)
  PASTA_DECLARE_BASE_OPERATORS(Type, TypeWithKeyword)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeWithKeyword, DependentNameType)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
  PASTA_DECLARE_DERIVED_OPERATORS(TypeWithKeyword, ElaboratedType)
  enum ElaboratedTypeKeyword Keyword(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TypeWithKeyword)
};
static_assert(sizeof(Type) == sizeof(TypeWithKeyword));

class AdjustedType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AdjustedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, AdjustedType)
  PASTA_DECLARE_DERIVED_OPERATORS(AdjustedType, DecayedType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ResolvedType(void) const noexcept;
  ::pasta::Type OriginalType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(AdjustedType)
};
static_assert(sizeof(Type) == sizeof(AdjustedType));

class ArrayType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ArrayType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(ArrayType, ConstantArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(ArrayType, DependentSizedArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(ArrayType, IncompleteArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(ArrayType, VariableArrayType)
  ::pasta::Type ElementType(void) const noexcept;
  uint32_t IndexTypeCVRQualifiers(void) const noexcept;
  // IndexTypeQualifiers: (clang::Qualifiers)
  enum ArrayTypeArraySizeModifier SizeModifier(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ArrayType)
};
static_assert(sizeof(Type) == sizeof(ArrayType));

class AtomicType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AtomicType)
  PASTA_DECLARE_BASE_OPERATORS(Type, AtomicType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ValueType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(AtomicType)
};
static_assert(sizeof(Type) == sizeof(AtomicType));

class AttributedType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AttributedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, AttributedType)
  ::pasta::Type Desugar(void) const noexcept;
  enum ::pasta::AttrKind AttributeKind(void) const noexcept;
  ::pasta::Type EquivalentType(void) const noexcept;
  std::optional<::pasta::NullabilityKind> ImmediateNullability(void) const noexcept;
  ::pasta::Type ModifiedType(void) const noexcept;
  bool IsCallingConv(void) const noexcept;
  bool IsMSTypeSpec(void) const noexcept;
  bool IsQualifier(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(AttributedType)
};
static_assert(sizeof(Type) == sizeof(AttributedType));

class BitIntType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BitIntType)
  PASTA_DECLARE_BASE_OPERATORS(Type, BitIntType)
  ::pasta::Type Desugar(void) const noexcept;
  uint32_t NumBits(void) const noexcept;
  bool IsSigned(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsUnsigned(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(BitIntType)
};
static_assert(sizeof(Type) == sizeof(BitIntType));

class BlockPointerType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlockPointerType)
  PASTA_DECLARE_BASE_OPERATORS(Type, BlockPointerType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(BlockPointerType)
};
static_assert(sizeof(Type) == sizeof(BlockPointerType));

class BuiltinType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BuiltinType)
  PASTA_DECLARE_BASE_OPERATORS(Type, BuiltinType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::BuiltinTypeKind Kind(void) const noexcept;
  // Name: (llvm::StringRef)
  // NameAsCString: (const char *)
  bool IsFloatingPoint(void) const noexcept;
  bool IsInteger(void) const noexcept;
  bool IsNonOverloadPlaceholderType(void) const noexcept;
  bool IsPlaceholderType(void) const noexcept;
  bool IsSignedInteger(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsUnsignedInteger(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(BuiltinType)
};
static_assert(sizeof(Type) == sizeof(BuiltinType));

class ComplexType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ComplexType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ComplexType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ComplexType)
};
static_assert(sizeof(Type) == sizeof(ComplexType));

class ConstantArrayType : public ArrayType {
 private:
  using ArrayType::ArrayType;
  using ArrayType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstantArrayType)
  PASTA_DECLARE_BASE_OPERATORS(ArrayType, ConstantArrayType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ConstantArrayType)
  ::pasta::Type Desugar(void) const noexcept;
  llvm::APInt Size(void) const noexcept;
  std::optional<::pasta::Expr> SizeExpression(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ConstantArrayType)
};
static_assert(sizeof(Type) == sizeof(ConstantArrayType));

class DecayedType : public AdjustedType {
 private:
  using AdjustedType::AdjustedType;
  using AdjustedType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DecayedType)
  PASTA_DECLARE_BASE_OPERATORS(AdjustedType, DecayedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DecayedType)
  ::pasta::Type ResolvedType(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DecayedType)
};
static_assert(sizeof(Type) == sizeof(DecayedType));

class DecltypeType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DecltypeType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DecltypeType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Expr UnderlyingExpression(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DecltypeType)
};
static_assert(sizeof(Type) == sizeof(DecltypeType));

class DeducedType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeducedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DeducedType)
  PASTA_DECLARE_DERIVED_OPERATORS(DeducedType, AutoType)
  PASTA_DECLARE_DERIVED_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
  ::pasta::Type Desugar(void) const noexcept;
  std::optional<::pasta::Type> ResolvedType(void) const noexcept;
  bool IsDeduced(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DeducedType)
};
static_assert(sizeof(Type) == sizeof(DeducedType));

class DependentAddressSpaceType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentAddressSpaceType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentAddressSpaceType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Expr AddrSpaceExpression(void) const noexcept;
  ::pasta::Token AttributeToken(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentAddressSpaceType)
};
static_assert(sizeof(Type) == sizeof(DependentAddressSpaceType));

class DependentBitIntType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentBitIntType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentBitIntType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Expr NumBitsExpression(void) const noexcept;
  bool IsSigned(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsUnsigned(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentBitIntType)
};
static_assert(sizeof(Type) == sizeof(DependentBitIntType));

class DependentNameType : public TypeWithKeyword {
 private:
  using TypeWithKeyword::TypeWithKeyword;
  using TypeWithKeyword::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentNameType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentNameType)
  PASTA_DECLARE_BASE_OPERATORS(TypeWithKeyword, DependentNameType)
  ::pasta::Type Desugar(void) const noexcept;
  // Identifier: (const clang::IdentifierInfo *)
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentNameType)
};
static_assert(sizeof(Type) == sizeof(DependentNameType));

class DependentSizedArrayType : public ArrayType {
 private:
  using ArrayType::ArrayType;
  using ArrayType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentSizedArrayType)
  PASTA_DECLARE_BASE_OPERATORS(ArrayType, DependentSizedArrayType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentSizedArrayType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::TokenRange BracketsRange(void) const noexcept;
  ::pasta::Token LBracketToken(void) const noexcept;
  ::pasta::Token RBracketToken(void) const noexcept;
  ::pasta::Expr SizeExpression(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentSizedArrayType)
};
static_assert(sizeof(Type) == sizeof(DependentSizedArrayType));

class DependentSizedExtVectorType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentSizedExtVectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentSizedExtVectorType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Token AttributeToken(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  ::pasta::Expr SizeExpression(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentSizedExtVectorType)
};
static_assert(sizeof(Type) == sizeof(DependentSizedExtVectorType));

class DependentTemplateSpecializationType : public TypeWithKeyword {
 private:
  using TypeWithKeyword::TypeWithKeyword;
  using TypeWithKeyword::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentTemplateSpecializationType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentTemplateSpecializationType)
  PASTA_DECLARE_BASE_OPERATORS(TypeWithKeyword, DependentTemplateSpecializationType)
  ::pasta::Type Desugar(void) const noexcept;
  // Argument: (const clang::TemplateArgument &)
  // Arguments: (const clang::TemplateArgument *)
  // Identifier: (const clang::IdentifierInfo *)
  uint32_t NumArguments(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const noexcept;
  // !!! Arg getNumArgs getArg (empty ret type = (const clang::TemplateArgument &))
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentTemplateSpecializationType)
};
static_assert(sizeof(Type) == sizeof(DependentTemplateSpecializationType));

class DependentVectorType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentVectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentVectorType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Token AttributeToken(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  ::pasta::Expr SizeExpression(void) const noexcept;
  enum VectorTypeVectorKind VectorKind(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentVectorType)
};
static_assert(sizeof(Type) == sizeof(DependentVectorType));

class ElaboratedType : public TypeWithKeyword {
 private:
  using TypeWithKeyword::TypeWithKeyword;
  using TypeWithKeyword::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ElaboratedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ElaboratedType)
  PASTA_DECLARE_BASE_OPERATORS(TypeWithKeyword, ElaboratedType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type NamedType(void) const noexcept;
  std::optional<::pasta::TagDecl> OwnedTagDeclaration(void) const noexcept;
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ElaboratedType)
};
static_assert(sizeof(Type) == sizeof(ElaboratedType));

class ExtVectorType : public VectorType {
 private:
  using VectorType::VectorType;
  using VectorType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExtVectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ExtVectorType)
  PASTA_DECLARE_BASE_OPERATORS(VectorType, ExtVectorType)
  ::pasta::Type Desugar(void) const noexcept;
  // IsAccessorWithinNumElements: (bool)
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ExtVectorType)
};
static_assert(sizeof(Type) == sizeof(ExtVectorType));

class FunctionType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionType)
  PASTA_DECLARE_BASE_OPERATORS(Type, FunctionType)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionType, FunctionNoProtoType)
  PASTA_DECLARE_DERIVED_OPERATORS(FunctionType, FunctionProtoType)
  enum CallingConv CallConv(void) const noexcept;
  ::pasta::Type CallResultType(void) const noexcept;
  bool CmseNSCallAttribute(void) const noexcept;
  // ExtInfo: (clang::FunctionType::ExtInfo)
  bool HasRegParm(void) const noexcept;
  bool NoReturnAttribute(void) const noexcept;
  uint32_t RegParmType(void) const noexcept;
  ::pasta::Type ReturnType(void) const noexcept;
  bool IsConst(void) const noexcept;
  bool IsRestrict(void) const noexcept;
  bool IsVolatile(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(FunctionType)
};
static_assert(sizeof(Type) == sizeof(FunctionType));

class IncompleteArrayType : public ArrayType {
 private:
  using ArrayType::ArrayType;
  using ArrayType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(IncompleteArrayType)
  PASTA_DECLARE_BASE_OPERATORS(ArrayType, IncompleteArrayType)
  PASTA_DECLARE_BASE_OPERATORS(Type, IncompleteArrayType)
  ::pasta::Type Desugar(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(IncompleteArrayType)
};
static_assert(sizeof(Type) == sizeof(IncompleteArrayType));

class InjectedClassNameType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(InjectedClassNameType)
  PASTA_DECLARE_BASE_OPERATORS(Type, InjectedClassNameType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::CXXRecordDecl Declaration(void) const noexcept;
  ::pasta::Type InjectedSpecializationType(void) const noexcept;
  ::pasta::TemplateSpecializationType InjectedTST(void) const noexcept;
  // TemplateName: (clang::TemplateName)
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(InjectedClassNameType)
};
static_assert(sizeof(Type) == sizeof(InjectedClassNameType));

class MacroQualifiedType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MacroQualifiedType)
  PASTA_DECLARE_BASE_OPERATORS(Type, MacroQualifiedType)
  ::pasta::Type Desugar(void) const noexcept;
  // MacroIdentifier: (const clang::IdentifierInfo *)
  ::pasta::Type ModifiedType(void) const noexcept;
  ::pasta::Type UnderlyingType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(MacroQualifiedType)
};
static_assert(sizeof(Type) == sizeof(MacroQualifiedType));

class MatrixType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MatrixType)
  PASTA_DECLARE_BASE_OPERATORS(Type, MatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(MatrixType, ConstantMatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(MatrixType, DependentSizedMatrixType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(MatrixType)
};
static_assert(sizeof(Type) == sizeof(MatrixType));

class MemberPointerType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(MemberPointerType)
  PASTA_DECLARE_BASE_OPERATORS(Type, MemberPointerType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type Class(void) const noexcept;
  ::pasta::CXXRecordDecl MostRecentCXXRecordDeclaration(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
  bool IsMemberDataPointer(void) const noexcept;
  bool IsMemberFunctionPointer(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(MemberPointerType)
};
static_assert(sizeof(Type) == sizeof(MemberPointerType));

class ObjCObjectPointerType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCObjectPointerType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ObjCObjectPointerType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::ObjCInterfaceDecl InterfaceDeclaration(void) const noexcept;
  ::pasta::ObjCInterfaceType InterfaceType(void) const noexcept;
  uint32_t NumProtocols(void) const noexcept;
  ::pasta::ObjCObjectType ObjectType(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
  // Protocol: (clang::ObjCProtocolDecl *)
  ::pasta::Type SuperClassType(void) const noexcept;
  std::vector<::pasta::Type> TypeArguments(void) const noexcept;
  std::vector<::pasta::Type> TypeArgumentsAsWritten(void) const noexcept;
  bool IsKindOfType(void) const noexcept;
  bool IsObjCClassType(void) const noexcept;
  bool IsObjCIdOrClassType(void) const noexcept;
  bool IsObjCIdType(void) const noexcept;
  bool IsObjCQualifiedClassType(void) const noexcept;
  bool IsObjCQualifiedIdType(void) const noexcept;
  bool IsSpecialized(void) const noexcept;
  bool IsSpecializedAsWritten(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsUnspecialized(void) const noexcept;
  bool IsUnspecializedAsWritten(void) const noexcept;
  std::vector<::pasta::ObjCProtocolDecl> Qualifieds(void) const noexcept;
  ::pasta::ObjCObjectPointerType StripObjCKindOfTypeAndQualifieds(void) const noexcept;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ObjCObjectPointerType)
};
static_assert(sizeof(Type) == sizeof(ObjCObjectPointerType));

class ObjCObjectType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCObjectType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ObjCObjectType)
  PASTA_DECLARE_DERIVED_OPERATORS(ObjCObjectType, ObjCInterfaceType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type BaseType(void) const noexcept;
  ::pasta::ObjCInterfaceDecl Interface(void) const noexcept;
  std::optional<::pasta::Type> SuperClassType(void) const noexcept;
  std::vector<::pasta::Type> TypeArguments(void) const noexcept;
  std::vector<::pasta::Type> TypeArgumentsAsWritten(void) const noexcept;
  bool IsKindOfType(void) const noexcept;
  bool IsKindOfTypeAsWritten(void) const noexcept;
  bool IsObjCClass(void) const noexcept;
  bool IsObjCId(void) const noexcept;
  bool IsObjCQualifiedClass(void) const noexcept;
  bool IsObjCQualifiedId(void) const noexcept;
  bool IsObjCUnqualifiedClass(void) const noexcept;
  bool IsObjCUnqualifiedId(void) const noexcept;
  bool IsObjCUnqualifiedIdOrClass(void) const noexcept;
  bool IsSpecialized(void) const noexcept;
  bool IsSpecializedAsWritten(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsUnspecialized(void) const noexcept;
  bool IsUnspecializedAsWritten(void) const noexcept;
  ::pasta::Type StripObjCKindOfTypeAndQualifieds(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ObjCObjectType)
};
static_assert(sizeof(Type) == sizeof(ObjCObjectType));

class ObjCTypeParamType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCTypeParamType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ObjCTypeParamType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::ObjCTypeParamDecl Declaration(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ObjCTypeParamType)
};
static_assert(sizeof(Type) == sizeof(ObjCTypeParamType));

class PackExpansionType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PackExpansionType)
  PASTA_DECLARE_BASE_OPERATORS(Type, PackExpansionType)
  ::pasta::Type Desugar(void) const noexcept;
  std::optional<unsigned> NumExpansions(void) const noexcept;
  ::pasta::Type Pattern(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(PackExpansionType)
};
static_assert(sizeof(Type) == sizeof(PackExpansionType));

class ParenType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ParenType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ParenType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type InnerType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ParenType)
};
static_assert(sizeof(Type) == sizeof(ParenType));

class PipeType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PipeType)
  PASTA_DECLARE_BASE_OPERATORS(Type, PipeType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type ElementType(void) const noexcept;
  bool IsReadOnly(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(PipeType)
};
static_assert(sizeof(Type) == sizeof(PipeType));

class PointerType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(PointerType)
  PASTA_DECLARE_BASE_OPERATORS(Type, PointerType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::Type PointeeType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(PointerType)
};
static_assert(sizeof(Type) == sizeof(PointerType));

class ReferenceType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ReferenceType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ReferenceType)
  PASTA_DECLARE_DERIVED_OPERATORS(ReferenceType, LValueReferenceType)
  PASTA_DECLARE_DERIVED_OPERATORS(ReferenceType, RValueReferenceType)
  ::pasta::Type PointeeType(void) const noexcept;
  ::pasta::Type PointeeTypeAsWritten(void) const noexcept;
  bool IsInnerReference(void) const noexcept;
  bool IsSpelledAsLValue(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ReferenceType)
};
static_assert(sizeof(Type) == sizeof(ReferenceType));

class SubstTemplateTypeParmPackType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SubstTemplateTypeParmPackType)
  PASTA_DECLARE_BASE_OPERATORS(Type, SubstTemplateTypeParmPackType)
  ::pasta::Type Desugar(void) const noexcept;
  // ArgumentPack: (clang::TemplateArgument)
  // Identifier: (clang::IdentifierInfo *)
  uint32_t NumArguments(void) const noexcept;
  ::pasta::TemplateTypeParmType ReplacedParameter(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(SubstTemplateTypeParmPackType)
};
static_assert(sizeof(Type) == sizeof(SubstTemplateTypeParmPackType));

class SubstTemplateTypeParmType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(SubstTemplateTypeParmType)
  PASTA_DECLARE_BASE_OPERATORS(Type, SubstTemplateTypeParmType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::TemplateTypeParmType ReplacedParameter(void) const noexcept;
  ::pasta::Type ReplacementType(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(SubstTemplateTypeParmType)
};
static_assert(sizeof(Type) == sizeof(SubstTemplateTypeParmType));

class TagType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TagType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TagType)
  PASTA_DECLARE_DERIVED_OPERATORS(TagType, EnumType)
  PASTA_DECLARE_DERIVED_OPERATORS(TagType, RecordType)
  ::pasta::TagDecl Declaration(void) const noexcept;
  bool IsBeingDefined(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TagType)
};
static_assert(sizeof(Type) == sizeof(TagType));

class TemplateSpecializationType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateSpecializationType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TemplateSpecializationType)
  ::pasta::Type Desugar(void) const noexcept;
  std::optional<::pasta::Type> AliasedType(void) const noexcept;
  // Argument: (const clang::TemplateArgument &)
  // Arguments: (const clang::TemplateArgument *)
  uint32_t NumArguments(void) const noexcept;
  // TemplateName: (clang::TemplateName)
  bool IsCurrentInstantiation(void) const noexcept;
  bool IsSugared(void) const noexcept;
  bool IsTypeAlias(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TemplateArguments(void) const noexcept;
  // !!! Arg getNumArgs getArg (empty ret type = (const clang::TemplateArgument &))
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TemplateSpecializationType)
};
static_assert(sizeof(Type) == sizeof(TemplateSpecializationType));

class TemplateTypeParmType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TemplateTypeParmType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TemplateTypeParmType)
  ::pasta::Type Desugar(void) const noexcept;
  std::optional<::pasta::TemplateTypeParmDecl> Declaration(void) const noexcept;
  uint32_t Depth(void) const noexcept;
  // Identifier: (clang::IdentifierInfo *)
  uint32_t Index(void) const noexcept;
  bool IsParameterPack(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(TemplateTypeParmType)
};
static_assert(sizeof(Type) == sizeof(TemplateTypeParmType));

class VariableArrayType : public ArrayType {
 private:
  using ArrayType::ArrayType;
  using ArrayType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VariableArrayType)
  PASTA_DECLARE_BASE_OPERATORS(ArrayType, VariableArrayType)
  PASTA_DECLARE_BASE_OPERATORS(Type, VariableArrayType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::TokenRange BracketsRange(void) const noexcept;
  ::pasta::Token LBracketToken(void) const noexcept;
  ::pasta::Token RBracketToken(void) const noexcept;
  ::pasta::Expr SizeExpression(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(VariableArrayType)
};
static_assert(sizeof(Type) == sizeof(VariableArrayType));

class AutoType : public DeducedType {
 private:
  using DeducedType::DeducedType;
  using DeducedType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(AutoType)
  PASTA_DECLARE_BASE_OPERATORS(DeducedType, AutoType)
  PASTA_DECLARE_BASE_OPERATORS(Type, AutoType)
  // Argument: (const clang::TemplateArgument &)
  // Arguments: (const clang::TemplateArgument *)
  enum AutoTypeKeyword Keyword(void) const noexcept;
  uint32_t NumArguments(void) const noexcept;
  std::vector<::pasta::TemplateArgument> TypeConstraintArguments(void) const noexcept;
  std::optional<::pasta::ConceptDecl> TypeConstraintConcept(void) const noexcept;
  bool IsConstrained(void) const noexcept;
  bool IsDecltypeAuto(void) const noexcept;
  // !!! Arg getNumArgs getArg (empty ret type = (const clang::TemplateArgument &))
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(AutoType)
};
static_assert(sizeof(Type) == sizeof(AutoType));

class ConstantMatrixType : public MatrixType {
 private:
  using MatrixType::MatrixType;
  using MatrixType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ConstantMatrixType)
  PASTA_DECLARE_BASE_OPERATORS(MatrixType, ConstantMatrixType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ConstantMatrixType)
  uint32_t NumColumns(void) const noexcept;
  uint32_t NumElementsFlattened(void) const noexcept;
  uint32_t NumRows(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ConstantMatrixType)
};
static_assert(sizeof(Type) == sizeof(ConstantMatrixType));

class DeducedTemplateSpecializationType : public DeducedType {
 private:
  using DeducedType::DeducedType;
  using DeducedType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DeducedTemplateSpecializationType)
  PASTA_DECLARE_BASE_OPERATORS(DeducedType, DeducedTemplateSpecializationType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DeducedTemplateSpecializationType)
  // TemplateName: (clang::TemplateName)
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DeducedTemplateSpecializationType)
};
static_assert(sizeof(Type) == sizeof(DeducedTemplateSpecializationType));

class DependentSizedMatrixType : public MatrixType {
 private:
  using MatrixType::MatrixType;
  using MatrixType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentSizedMatrixType)
  PASTA_DECLARE_BASE_OPERATORS(MatrixType, DependentSizedMatrixType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentSizedMatrixType)
  ::pasta::Token AttributeToken(void) const noexcept;
  ::pasta::Expr ColumnExpression(void) const noexcept;
  ::pasta::Expr RowExpression(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentSizedMatrixType)
};
static_assert(sizeof(Type) == sizeof(DependentSizedMatrixType));

class EnumType : public TagType {
 private:
  using TagType::TagType;
  using TagType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(EnumType)
  PASTA_DECLARE_BASE_OPERATORS(TagType, EnumType)
  PASTA_DECLARE_BASE_OPERATORS(Type, EnumType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::EnumDecl Declaration(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(EnumType)
};
static_assert(sizeof(Type) == sizeof(EnumType));

class FunctionNoProtoType : public FunctionType {
 private:
  using FunctionType::FunctionType;
  using FunctionType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionNoProtoType)
  PASTA_DECLARE_BASE_OPERATORS(FunctionType, FunctionNoProtoType)
  PASTA_DECLARE_BASE_OPERATORS(Type, FunctionNoProtoType)
  ::pasta::Type Desugar(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(FunctionNoProtoType)
};
static_assert(sizeof(Type) == sizeof(FunctionNoProtoType));

class FunctionProtoType : public FunctionType {
 private:
  using FunctionType::FunctionType;
  using FunctionType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(FunctionProtoType)
  PASTA_DECLARE_BASE_OPERATORS(FunctionType, FunctionProtoType)
  PASTA_DECLARE_BASE_OPERATORS(Type, FunctionProtoType)
  std::optional<enum CanThrowResult> CanThrow(void) const noexcept;
  ::pasta::Type Desugar(void) const noexcept;
  std::vector<::pasta::Type> Exceptions(void) const noexcept;
  ::pasta::Token EllipsisToken(void) const noexcept;
  std::optional<::pasta::FunctionDecl> ExceptionSpecDeclaration(void) const noexcept;
  // ExceptionSpecInfo: (clang::FunctionProtoType::ExceptionSpecInfo)
  std::optional<::pasta::FunctionDecl> ExceptionSpecTemplate(void) const noexcept;
  enum ExceptionSpecificationType ExceptionSpecType(void) const noexcept;
  // ExceptionType: (clang::QualType)
  // ExtParameterInfo: (clang::FunctionType::ExtParameterInfo)
  // ExtParameterInfos: (llvm::ArrayRef<clang::FunctionType::ExtParameterInfo>)
  // ExtParameterInfosOrNull: (const clang::FunctionType::ExtParameterInfo *)
  // ExtProtoInfo: (clang::FunctionProtoType::ExtProtoInfo)
  // MethodQualifieds: (clang::Qualifiers)
  std::optional<::pasta::Expr> NoexceptExpression(void) const noexcept;
  uint32_t NumExceptions(void) const noexcept;
  uint32_t NumParameters(void) const noexcept;
  // ParameterType: (clang::QualType)
  std::vector<::pasta::Type> ParameterTypes(void) const noexcept;
  // ParameterABI: (clang::ParameterABI)
  enum RefQualifierKind ReferenceQualifier(void) const noexcept;
  bool HasDependentExceptionSpec(void) const noexcept;
  bool HasDynamicExceptionSpec(void) const noexcept;
  bool HasExceptionSpec(void) const noexcept;
  bool HasExtParameterInfos(void) const noexcept;
  bool HasInstantiationDependentExceptionSpec(void) const noexcept;
  bool HasNoexceptExceptionSpec(void) const noexcept;
  bool HasTrailingReturn(void) const noexcept;
  std::optional<bool> IsNothrow(void) const noexcept;
  // IsParameterConsumed: (bool)
  bool IsSugared(void) const noexcept;
  bool IsTemplateVariadic(void) const noexcept;
  bool IsVariadic(void) const noexcept;
  // ParameterTypes: (llvm::iterator_range<const clang::QualType *>)
  std::vector<::pasta::Type> ExceptionTypes(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(FunctionProtoType)
};
static_assert(sizeof(Type) == sizeof(FunctionProtoType));

class LValueReferenceType : public ReferenceType {
 private:
  using ReferenceType::ReferenceType;
  using ReferenceType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(LValueReferenceType)
  PASTA_DECLARE_BASE_OPERATORS(ReferenceType, LValueReferenceType)
  PASTA_DECLARE_BASE_OPERATORS(Type, LValueReferenceType)
  ::pasta::Type Desugar(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(LValueReferenceType)
};
static_assert(sizeof(Type) == sizeof(LValueReferenceType));

class ObjCInterfaceType : public ObjCObjectType {
 private:
  using ObjCObjectType::ObjCObjectType;
  using ObjCObjectType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ObjCInterfaceType)
  PASTA_DECLARE_BASE_OPERATORS(ObjCObjectType, ObjCInterfaceType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ObjCInterfaceType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::ObjCInterfaceDecl Declaration(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ObjCInterfaceType)
};
static_assert(sizeof(Type) == sizeof(ObjCInterfaceType));

class RValueReferenceType : public ReferenceType {
 private:
  using ReferenceType::ReferenceType;
  using ReferenceType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RValueReferenceType)
  PASTA_DECLARE_BASE_OPERATORS(ReferenceType, RValueReferenceType)
  PASTA_DECLARE_BASE_OPERATORS(Type, RValueReferenceType)
  ::pasta::Type Desugar(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(RValueReferenceType)
};
static_assert(sizeof(Type) == sizeof(RValueReferenceType));

class RecordType : public TagType {
 private:
  using TagType::TagType;
  using TagType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(RecordType)
  PASTA_DECLARE_BASE_OPERATORS(TagType, RecordType)
  PASTA_DECLARE_BASE_OPERATORS(Type, RecordType)
  ::pasta::Type Desugar(void) const noexcept;
  ::pasta::RecordDecl Declaration(void) const noexcept;
  bool HasConstFields(void) const noexcept;
  bool IsSugared(void) const noexcept;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(RecordType)
};
static_assert(sizeof(Type) == sizeof(RecordType));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR
#endif  // !PASTA_IN_BOOTSTRAP
