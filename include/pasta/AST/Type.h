/*
 * Copyright (c) 2021 Trail of Bits, Inc.
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
        const ::clang::QualType &type_);

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
  virtual void VisitVectorType(const VectorType &);
  virtual void VisitTypeWithKeyword(const TypeWithKeyword &);
  virtual void VisitAdjustedType(const AdjustedType &);
  virtual void VisitArrayType(const ArrayType &);
  virtual void VisitAtomicType(const AtomicType &);
  virtual void VisitAttributedType(const AttributedType &);
  virtual void VisitBlockPointerType(const BlockPointerType &);
  virtual void VisitBuiltinType(const BuiltinType &);
  virtual void VisitComplexType(const ComplexType &);
  virtual void VisitConstantArrayType(const ConstantArrayType &);
  virtual void VisitDecayedType(const DecayedType &);
  virtual void VisitDecltypeType(const DecltypeType &);
  virtual void VisitDeducedType(const DeducedType &);
  virtual void VisitDependentAddressSpaceType(const DependentAddressSpaceType &);
  virtual void VisitDependentExtIntType(const DependentExtIntType &);
  virtual void VisitDependentNameType(const DependentNameType &);
  virtual void VisitDependentSizedArrayType(const DependentSizedArrayType &);
  virtual void VisitDependentSizedExtVectorType(const DependentSizedExtVectorType &);
  virtual void VisitDependentTemplateSpecializationType(const DependentTemplateSpecializationType &);
  virtual void VisitDependentVectorType(const DependentVectorType &);
  virtual void VisitElaboratedType(const ElaboratedType &);
  virtual void VisitExtIntType(const ExtIntType &);
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
    const ::clang::VectorType *VectorType;
    const ::clang::TypeWithKeyword *TypeWithKeyword;
    const ::clang::AdjustedType *AdjustedType;
    const ::clang::ArrayType *ArrayType;
    const ::clang::AtomicType *AtomicType;
    const ::clang::AttributedType *AttributedType;
    const ::clang::BlockPointerType *BlockPointerType;
    const ::clang::BuiltinType *BuiltinType;
    const ::clang::ComplexType *ComplexType;
    const ::clang::ConstantArrayType *ConstantArrayType;
    const ::clang::DecayedType *DecayedType;
    const ::clang::DecltypeType *DecltypeType;
    const ::clang::DeducedType *DeducedType;
    const ::clang::DependentAddressSpaceType *DependentAddressSpaceType;
    const ::clang::DependentExtIntType *DependentExtIntType;
    const ::clang::DependentNameType *DependentNameType;
    const ::clang::DependentSizedArrayType *DependentSizedArrayType;
    const ::clang::DependentSizedExtVectorType *DependentSizedExtVectorType;
    const ::clang::DependentTemplateSpecializationType *DependentTemplateSpecializationType;
    const ::clang::DependentVectorType *DependentVectorType;
    const ::clang::ElaboratedType *ElaboratedType;
    const ::clang::ExtIntType *ExtIntType;
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
    u.Type = type_;
  }

 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(Type)
  static std::optional<::pasta::Type> From(const TokenContext &);
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AdjustedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AtomicType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AttributedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, AutoType)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentExtIntType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentNameType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedExtVectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentSizedMatrixType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentTemplateSpecializationType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, DependentVectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ElaboratedType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, EnumType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, ExtIntType)
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
  PASTA_DECLARE_DERIVED_OPERATORS(Type, VariableArrayType)
  PASTA_DECLARE_DERIVED_OPERATORS(Type, VectorType)
  inline bool operator==(const Type &that) const noexcept {
    return u.opaque == that.u.opaque && qualifiers == that.qualifiers;
  }
  inline bool operator!=(const Type &that) const noexcept {
    return u.opaque != that.u.opaque || qualifiers != that.qualifiers;
  }
  bool AcceptsObjCTypeParams(void) const;
  bool CanDecayToPointerType(void) const;
  bool CanHaveNullability(void) const;
  std::optional<::pasta::ArrayType> CastAsArrayTypeUnsafe(void) const;
  bool ContainsErrors(void) const;
  bool ContainsUnexpandedParameterPack(void) const;
  ::pasta::Type ArrayElementTypeNoTypeQualified(void) const;
  std::optional<::pasta::ArrayType> AsArrayTypeUnsafe(void) const;
  std::optional<::pasta::CXXRecordDecl> AsCXXRecordDeclaration(void) const;
  std::optional<::pasta::ComplexType> AsComplexIntegerType(void) const;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCInterfacePointerType(void) const;
  std::optional<::pasta::ObjCObjectType> AsObjCInterfaceType(void) const;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCQualifiedClassType(void) const;
  std::optional<::pasta::ObjCObjectPointerType> AsObjCQualifiedIdType(void) const;
  std::optional<::pasta::ObjCObjectType> AsObjCQualifiedInterfaceType(void) const;
  std::optional<::pasta::BuiltinType> AsPlaceholderType(void) const;
  std::optional<::pasta::RecordDecl> AsRecordDeclaration(void) const;
  std::optional<::pasta::RecordType> AsStructureType(void) const;
  std::optional<::pasta::TagDecl> AsTagDeclaration(void) const;
  std::optional<::pasta::RecordType> AsUnionType(void) const;
  std::optional<::pasta::Type> BaseElementTypeUnsafe(void) const;
  ::pasta::Type CanonicalTypeInternal(void) const;
  // CanonicalTypeUnqualified: (clang::CanQual<clang::Type>)
  ::pasta::AutoType ContainedAutoType(void) const;
  ::pasta::DeducedType ContainedDeducedType(void) const;
  ::pasta::TypeDependence Dependence(void) const;
  enum Linkage Linkage(void) const;
  // LinkageAndVisibility: (clang::LinkageInfo)
  ::pasta::Type LocallyUnqualifiedSingleStepDesugaredType(void) const;
  std::optional<::pasta::NullabilityKind> Nullability(void) const;
  ::pasta::ObjCLifetime ObjCARCImplicitLifetime(void) const;
  // ObjCSubstitutions: (llvm::Optional<llvm::ArrayRef<clang::QualType>>)
  ::pasta::CXXRecordDecl PointeeCXXRecordDeclaration(void) const;
  ::pasta::Type PointeeOrArrayElementType(void) const;
  ::pasta::Type PointeeType(void) const;
  ::pasta::ScalarTypeKind ScalarTypeKind(void) const;
  ::pasta::Type SveEltType(void) const;
  ::pasta::TypeKind Kind(void) const;
  std::string_view KindName(void) const;
  ::pasta::Type UnqualifiedDesugaredType(void) const;
  enum Visibility Visibility(void) const;
  // HasAttribute: (bool)
  bool HasAutoForTrailingReturnType(void) const;
  bool HasFloatingRepresentation(void) const;
  bool HasIntegerRepresentation(void) const;
  bool HasObjCPointerRepresentation(void) const;
  bool HasPointerRepresentation(void) const;
  bool HasSignedIntegerRepresentation(void) const;
  bool HasSizedVLAType(void) const;
  bool HasUnnamedOrLocalType(void) const;
  bool HasUnsignedIntegerRepresentation(void) const;
  bool IsAggregateType(void) const;
  bool IsAlignValT(void) const;
  bool IsAnyCharacterType(void) const;
  bool IsAnyComplexType(void) const;
  bool IsAnyPointerType(void) const;
  bool IsArithmeticType(void) const;
  bool IsArrayType(void) const;
  bool IsAtomicType(void) const;
  bool IsBFloat16Type(void) const;
  bool IsBlockCompatibleObjCPointerType(void) const;
  bool IsBlockPointerType(void) const;
  bool IsBooleanType(void) const;
  bool IsBuiltinType(void) const;
  bool IsCARCBridgableType(void) const;
  bool IsCUDADeviceBuiltinSurfaceType(void) const;
  bool IsCUDADeviceBuiltinTextureType(void) const;
  bool IsCanonicalUnqualified(void) const;
  bool IsChar16Type(void) const;
  bool IsChar32Type(void) const;
  bool IsChar8Type(void) const;
  bool IsCharacterType(void) const;
  bool IsClassType(void) const;
  bool IsClkEventT(void) const;
  bool IsComplexIntegerType(void) const;
  bool IsComplexType(void) const;
  bool IsCompoundType(void) const;
  bool IsConstantArrayType(void) const;
  bool IsConstantMatrixType(void) const;
  bool IsConstantSizeType(void) const;
  bool IsDecltypeType(void) const;
  bool IsDependentAddressSpaceType(void) const;
  bool IsDependentSizedArrayType(void) const;
  bool IsDependentType(void) const;
  bool IsElaboratedTypeSpecifier(void) const;
  bool IsEnumeralType(void) const;
  bool IsEventT(void) const;
  bool IsExtIntType(void) const;
  bool IsExtVectorType(void) const;
  bool IsFixedPointOrIntegerType(void) const;
  bool IsFixedPointType(void) const;
  bool IsFloat128Type(void) const;
  bool IsFloat16Type(void) const;
  bool IsFloatingType(void) const;
  bool IsFromAST(void) const;
  bool IsFunctionNoProtoType(void) const;
  bool IsFunctionPointerType(void) const;
  bool IsFunctionProtoType(void) const;
  bool IsFunctionReferenceType(void) const;
  bool IsFunctionType(void) const;
  bool IsFundamentalType(void) const;
  bool IsHalfType(void) const;
  bool IsImageType(void) const;
  bool IsIncompleteArrayType(void) const;
  bool IsIncompleteOrObjectType(void) const;
  bool IsIncompleteType(void) const;
  bool IsInstantiationDependentType(void) const;
  bool IsIntegerType(void) const;
  bool IsIntegralOrEnumerationType(void) const;
  bool IsIntegralOrUnscopedEnumerationType(void) const;
  bool IsIntegralType(void) const;
  bool IsInterfaceType(void) const;
  bool IsLValueReferenceType(void) const;
  bool IsLinkageValid(void) const;
  bool IsLiteralType(void) const;
  bool IsMatrixType(void) const;
  bool IsMemberDataPointerType(void) const;
  bool IsMemberFunctionPointerType(void) const;
  bool IsMemberPointerType(void) const;
  bool IsNonOverloadPlaceholderType(void) const;
  bool IsNothrowT(void) const;
  bool IsNullPointerType(void) const;
  bool IsOCLExtOpaqueType(void) const;
  bool IsOCLImage1dArrayROType(void) const;
  bool IsOCLImage1dArrayRWType(void) const;
  bool IsOCLImage1dArrayWOType(void) const;
  bool IsOCLImage1dBufferROType(void) const;
  bool IsOCLImage1dBufferRWType(void) const;
  bool IsOCLImage1dBufferWOType(void) const;
  bool IsOCLImage1dROType(void) const;
  bool IsOCLImage1dRWType(void) const;
  bool IsOCLImage1dWOType(void) const;
  bool IsOCLImage2dArrayDepthROType(void) const;
  bool IsOCLImage2dArrayDepthRWType(void) const;
  bool IsOCLImage2dArrayDepthWOType(void) const;
  bool IsOCLImage2dArrayMSAADepthROType(void) const;
  bool IsOCLImage2dArrayMSAADepthRWType(void) const;
  bool IsOCLImage2dArrayMSAADepthWOType(void) const;
  bool IsOCLImage2dArrayMSAAROType(void) const;
  bool IsOCLImage2dArrayMSAARWType(void) const;
  bool IsOCLImage2dArrayMSAAWOType(void) const;
  bool IsOCLImage2dArrayROType(void) const;
  bool IsOCLImage2dArrayRWType(void) const;
  bool IsOCLImage2dArrayWOType(void) const;
  bool IsOCLImage2dDepthROType(void) const;
  bool IsOCLImage2dDepthRWType(void) const;
  bool IsOCLImage2dDepthWOType(void) const;
  bool IsOCLImage2dMSAADepthROType(void) const;
  bool IsOCLImage2dMSAADepthRWType(void) const;
  bool IsOCLImage2dMSAADepthWOType(void) const;
  bool IsOCLImage2dMSAAROType(void) const;
  bool IsOCLImage2dMSAARWType(void) const;
  bool IsOCLImage2dMSAAWOType(void) const;
  bool IsOCLImage2dROType(void) const;
  bool IsOCLImage2dRWType(void) const;
  bool IsOCLImage2dWOType(void) const;
  bool IsOCLImage3dROType(void) const;
  bool IsOCLImage3dRWType(void) const;
  bool IsOCLImage3dWOType(void) const;
  bool IsOCLIntelSubgroupAVCImeDualReferenceStreaminType(void) const;
  bool IsOCLIntelSubgroupAVCImePayloadType(void) const;
  bool IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType(void) const;
  bool IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType(void) const;
  bool IsOCLIntelSubgroupAVCImeResultType(void) const;
  bool IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType(void) const;
  bool IsOCLIntelSubgroupAVCMcePayloadType(void) const;
  bool IsOCLIntelSubgroupAVCMceResultType(void) const;
  bool IsOCLIntelSubgroupAVCRefPayloadType(void) const;
  bool IsOCLIntelSubgroupAVCRefResultType(void) const;
  bool IsOCLIntelSubgroupAVCSicPayloadType(void) const;
  bool IsOCLIntelSubgroupAVCSicResultType(void) const;
  bool IsOCLIntelSubgroupAVCType(void) const;
  bool IsObjCARCBridgableType(void) const;
  bool IsObjCARCImplicitlyUnretainedType(void) const;
  bool IsObjCBoxableRecordType(void) const;
  bool IsObjCBuiltinType(void) const;
  bool IsObjCClassOrClassKindOfType(void) const;
  bool IsObjCClassType(void) const;
  // IsObjCIdOrObjectKindOfType: (bool)
  bool IsObjCIdType(void) const;
  bool IsObjCIndependentClassType(void) const;
  bool IsObjCIndirectLifetimeType(void) const;
  bool IsObjCInertUnsafeUnretainedType(void) const;
  bool IsObjCLifetimeType(void) const;
  bool IsObjCNSObjectType(void) const;
  bool IsObjCObjectOrInterfaceType(void) const;
  bool IsObjCObjectPointerType(void) const;
  bool IsObjCObjectType(void) const;
  bool IsObjCQualifiedClassType(void) const;
  bool IsObjCQualifiedIdType(void) const;
  bool IsObjCQualifiedInterfaceType(void) const;
  bool IsObjCRetainableType(void) const;
  bool IsObjCSelType(void) const;
  bool IsObjectPointerType(void) const;
  bool IsObjectType(void) const;
  bool IsOpenCLSpecificType(void) const;
  bool IsOverloadableType(void) const;
  bool IsPipeType(void) const;
  bool IsPlaceholderType(void) const;
  bool IsPointerType(void) const;
  bool IsPromotableIntegerType(void) const;
  bool IsQueueT(void) const;
  bool IsRValueReferenceType(void) const;
  bool IsRealFloatingType(void) const;
  bool IsRealType(void) const;
  bool IsRecordType(void) const;
  bool IsReferenceType(void) const;
  bool IsReserveIDT(void) const;
  bool IsSamplerT(void) const;
  bool IsSaturatedFixedPointType(void) const;
  bool IsScalarType(void) const;
  bool IsScopedEnumeralType(void) const;
  bool IsSignedFixedPointType(void) const;
  bool IsSignedIntegerOrEnumerationType(void) const;
  bool IsSignedIntegerType(void) const;
  bool IsSizelessBuiltinType(void) const;
  bool IsSizelessType(void) const;
  // IsSpecificBuiltinType: (bool)
  // IsSpecificPlaceholderType: (bool)
  bool IsSpecifierType(void) const;
  bool IsStandardLayoutType(void) const;
  bool IsStdByteType(void) const;
  bool IsStructuralType(void) const;
  bool IsStructureOrClassType(void) const;
  bool IsStructureType(void) const;
  bool IsTemplateTypeParmType(void) const;
  bool IsTypedefNameType(void) const;
  bool IsUndeducedAutoType(void) const;
  bool IsUndeducedType(void) const;
  bool IsUnionType(void) const;
  bool IsUnsaturatedFixedPointType(void) const;
  bool IsUnscopedEnumerationType(void) const;
  bool IsUnsignedFixedPointType(void) const;
  bool IsUnsignedIntegerOrEnumerationType(void) const;
  bool IsUnsignedIntegerType(void) const;
  bool IsVLSTBuiltinType(void) const;
  bool IsVariableArrayType(void) const;
  bool IsVariablyModifiedType(void) const;
  bool IsVectorType(void) const;
  bool IsVisibilityExplicit(void) const;
  bool IsVoidPointerType(void) const;
  bool IsVoidType(void) const;
  bool IsWideCharacterType(void) const;
  inline bool IsQualified(void) const noexcept {
    return qualifiers;
  }
  inline Type UnqualifiedType(void) const noexcept {
    return Type(ast, u.Type, kind, 0);
  }
  ::pasta::Type IgnoreParentheses(void) const;
  enum LangAS AddressSpace(void) const;
  ::pasta::Type AtomicUnqualifiedType(void) const;
  // BaseTypeIdentifier: (const clang::IdentifierInfo *)
  uint32_t CVRQualifiers(void) const;
  ::pasta::Type CanonicalType(void) const;
  ::pasta::Type DesugaredType(void) const;
  uint32_t LocalCVRQualifiers(void) const;
  uint32_t LocalFastQualifiers(void) const;
  // LocalQualifiers: (clang::Qualifiers)
  ::pasta::Type LocalUnqualifiedType(void) const;
  ::pasta::Type NonLValueExpressionType(void) const;
  ::pasta::Type NonPackExpansionType(void) const;
  ::pasta::Type NonReferenceType(void) const;
  // ObjCGCAttr: (clang::Qualifiers::GC)
  ::pasta::ObjCLifetime ObjCLifetime(void) const;
  // Qualifiers: (clang::Qualifiers)
  ::pasta::Type SingleStepDesugaredType(void) const;
  // SplitDesugaredType: (clang::SplitQualType)
  // SplitUnqualifiedType: (clang::SplitQualType)
  bool HasAddressSpace(void) const;
  bool HasLocalNonFastQualifiers(void) const;
  bool HasLocalQualifiers(void) const;
  bool HasNonTrivialObjCLifetime(void) const;
  bool HasNonTrivialToPrimitiveCopyCUnion(void) const;
  bool HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const;
  bool HasNonTrivialToPrimitiveDestructCUnion(void) const;
  bool HasQualifiers(void) const;
  bool HasStrongOrWeakObjCLifetime(void) const;
  // IsAddressSpaceOverlapping: (bool)
  // IsAtLeastAsQualifiedAs: (bool)
  bool IsCForbiddenLValueType(void) const;
  bool IsCXX11PODType(void) const;
  bool IsCXX98PODType(void) const;
  bool IsCanonical(void) const;
  bool IsCanonicalAsParam(void) const;
  bool IsConstQualified(void) const;
  bool IsConstant(void) const;
  // IsDestructedType: (clang::QualType::DestructionKind)
  bool IsLocalConstQualified(void) const;
  bool IsLocalRestrictQualified(void) const;
  bool IsLocalVolatileQualified(void) const;
  // IsMoreQualifiedThan: (bool)
  ::pasta::PrimitiveCopyKind IsNonTrivialToPrimitiveCopy(void) const;
  ::pasta::PrimitiveDefaultInitializeKind IsNonTrivialToPrimitiveDefaultInitialize(void) const;
  ::pasta::PrimitiveCopyKind IsNonTrivialToPrimitiveDestructiveMove(void) const;
  bool IsNonWeakInMRRWithObjCWeak(void) const;
  bool IsNull(void) const;
  bool IsObjCGCStrong(void) const;
  bool IsObjCGCWeak(void) const;
  bool IsPODType(void) const;
  bool IsRestrictQualified(void) const;
  bool IsTrivialType(void) const;
  bool IsTriviallyCopyableType(void) const;
  bool IsVolatileQualified(void) const;
  bool MayBeDynamicClass(void) const;
  bool MayBeNotDynamicClass(void) const;
  // Split: (clang::SplitQualType)
  // Stream: (clang::QualType::StreamedQualTypeHelper)
  ::pasta::Type StripObjCKindOfType(void) const;
  // SubstObjCMemberType: (clang::QualType)
  // SubstObjCTypeArguments: (clang::QualType)
  // WithCVRQualifiers: (clang::QualType)
  ::pasta::Type WithConst(void) const;
  // WithExactLocalFastQualifiers: (clang::QualType)
  // WithFastQualifiers: (clang::QualType)
  ::pasta::Type WithRestrict(void) const;
  ::pasta::Type WithVolatile(void) const;
  ::pasta::Type WithoutLocalFastQualifiers(void) const;
};

class TypeOfExprType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(TypeOfExprType)
  PASTA_DECLARE_BASE_OPERATORS(Type, TypeOfExprType)
  ::pasta::Type Desugar(void) const;
  ::pasta::Expr UnderlyingExpression(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type UnderlyingType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::TypedefNameDecl Declaration(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type BaseType(void) const;
  ::pasta::UTTKind UTTKind(void) const;
  ::pasta::Type UnderlyingType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::UnresolvedUsingTypenameDecl Declaration(void) const;
  bool IsSugared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(UnresolvedUsingType)
};
static_assert(sizeof(Type) == sizeof(UnresolvedUsingType));

class VectorType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(VectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, VectorType)
  PASTA_DECLARE_DERIVED_OPERATORS(VectorType, ExtVectorType)
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ElementType(void) const;
  uint32_t NumElements(void) const;
  ::pasta::VectorKind VectorKind(void) const;
  bool IsSugared(void) const;
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
  enum ElaboratedTypeKeyword Keyword(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ResolvedType(void) const;
  ::pasta::Type OriginalType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type ElementType(void) const;
  uint32_t IndexTypeCVRQualifiers(void) const;
  // IndexTypeQualifiers: (clang::Qualifiers)
  ::pasta::ArraySizeModifier SizeModifier(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ValueType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::AttributeKind AttributeKind(void) const;
  ::pasta::Type EquivalentType(void) const;
  std::optional<::pasta::NullabilityKind> ImmediateNullability(void) const;
  ::pasta::Type ModifiedType(void) const;
  bool IsCallingConv(void) const;
  bool IsMSTypeSpec(void) const;
  bool IsQualifier(void) const;
  bool IsSugared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(AttributedType)
};
static_assert(sizeof(Type) == sizeof(AttributedType));

class BlockPointerType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(BlockPointerType)
  PASTA_DECLARE_BASE_OPERATORS(Type, BlockPointerType)
  ::pasta::Type Desugar(void) const;
  ::pasta::Type PointeeType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  // Kind: (clang::BuiltinType::Kind)
  // Name: (llvm::StringRef)
  // NameAsCString: (const char *)
  bool IsFloatingPoint(void) const;
  bool IsInteger(void) const;
  bool IsNonOverloadPlaceholderType(void) const;
  bool IsPlaceholderType(void) const;
  bool IsSignedInteger(void) const;
  bool IsSugared(void) const;
  bool IsUnsignedInteger(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ElementType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  // Size: (const llvm::APInt &)
  ::pasta::Expr SizeExpression(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type ResolvedType(void) const;
  ::pasta::Type PointeeType(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Expr UnderlyingExpression(void) const;
  ::pasta::Type UnderlyingType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ResolvedType(void) const;
  bool IsDeduced(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Expr AddrSpaceExpression(void) const;
  ::pasta::Token AttributeToken(void) const;
  ::pasta::Type PointeeType(void) const;
  bool IsSugared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentAddressSpaceType)
};
static_assert(sizeof(Type) == sizeof(DependentAddressSpaceType));

class DependentExtIntType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentExtIntType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentExtIntType)
  ::pasta::Type Desugar(void) const;
  ::pasta::Expr NumBitsExpression(void) const;
  bool IsSigned(void) const;
  bool IsSugared(void) const;
  bool IsUnsigned(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(DependentExtIntType)
};
static_assert(sizeof(Type) == sizeof(DependentExtIntType));

class DependentNameType : public TypeWithKeyword {
 private:
  using TypeWithKeyword::TypeWithKeyword;
  using TypeWithKeyword::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(DependentNameType)
  PASTA_DECLARE_BASE_OPERATORS(Type, DependentNameType)
  PASTA_DECLARE_BASE_OPERATORS(TypeWithKeyword, DependentNameType)
  ::pasta::Type Desugar(void) const;
  // Identifier: (const clang::IdentifierInfo *)
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::TokenRange BracketsRange(void) const;
  ::pasta::Token LBracketToken(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr SizeExpression(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Token AttributeToken(void) const;
  ::pasta::Type ElementType(void) const;
  ::pasta::Expr SizeExpression(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  // Argument: (const clang::TemplateArgument &)
  // Arguments: (const clang::TemplateArgument *)
  // Identifier: (const clang::IdentifierInfo *)
  uint32_t NumArguments(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgument>)
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Token AttributeToken(void) const;
  ::pasta::Type ElementType(void) const;
  ::pasta::Expr SizeExpression(void) const;
  ::pasta::VectorKind VectorKind(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type NamedType(void) const;
  ::pasta::TagDecl OwnedTagDeclaration(void) const;
  // Qualifier: (clang::NestedNameSpecifier *)
  bool IsSugared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ElaboratedType)
};
static_assert(sizeof(Type) == sizeof(ElaboratedType));

class ExtIntType : public Type {
 private:
  using Type::Type;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExtIntType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ExtIntType)
  ::pasta::Type Desugar(void) const;
  uint32_t NumBits(void) const;
  bool IsSigned(void) const;
  bool IsSugared(void) const;
  bool IsUnsigned(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(ExtIntType)
};
static_assert(sizeof(Type) == sizeof(ExtIntType));

class ExtVectorType : public VectorType {
 private:
  using VectorType::VectorType;
  using VectorType::From;
 public:
  PASTA_DECLARE_DEFAULT_CONSTRUCTORS(ExtVectorType)
  PASTA_DECLARE_BASE_OPERATORS(Type, ExtVectorType)
  PASTA_DECLARE_BASE_OPERATORS(VectorType, ExtVectorType)
  ::pasta::Type Desugar(void) const;
  // IsAccessorWithinNumElements: (bool)
  bool IsSugared(void) const;
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
  enum CallingConv CallConv(void) const;
  ::pasta::Type CallResultType(void) const;
  bool CmseNSCallAttribute(void) const;
  // ExtInfo: (clang::FunctionType::ExtInfo)
  bool HasRegParm(void) const;
  bool NoReturnAttribute(void) const;
  uint32_t RegParmType(void) const;
  ::pasta::Type ReturnType(void) const;
  bool IsConst(void) const;
  bool IsRestrict(void) const;
  bool IsVolatile(void) const;
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
  ::pasta::Type Desugar(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::CXXRecordDecl Declaration(void) const;
  ::pasta::Type InjectedSpecializationType(void) const;
  ::pasta::TemplateSpecializationType InjectedTST(void) const;
  // TemplateName: (clang::TemplateName)
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  // MacroIdentifier: (const clang::IdentifierInfo *)
  ::pasta::Type ModifiedType(void) const;
  ::pasta::Type UnderlyingType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ElementType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type Class(void) const;
  ::pasta::CXXRecordDecl MostRecentCXXRecordDeclaration(void) const;
  ::pasta::Type PointeeType(void) const;
  bool IsMemberDataPointer(void) const;
  bool IsMemberFunctionPointer(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::ObjCInterfaceDecl InterfaceDeclaration(void) const;
  ::pasta::ObjCInterfaceType InterfaceType(void) const;
  uint32_t NumProtocols(void) const;
  ::pasta::ObjCObjectType ObjectType(void) const;
  ::pasta::Type PointeeType(void) const;
  // Protocol: (clang::ObjCProtocolDecl *)
  ::pasta::Type SuperClassType(void) const;
  std::vector<::pasta::Type> TypeArguments(void) const;
  std::vector<::pasta::Type> TypeArgumentsAsWritten(void) const;
  bool IsKindOfType(void) const;
  bool IsObjCClassType(void) const;
  bool IsObjCIdOrClassType(void) const;
  bool IsObjCIdType(void) const;
  bool IsObjCQualifiedClassType(void) const;
  bool IsObjCQualifiedIdType(void) const;
  bool IsSpecialized(void) const;
  bool IsSpecializedAsWritten(void) const;
  bool IsSugared(void) const;
  bool IsUnspecialized(void) const;
  bool IsUnspecializedAsWritten(void) const;
  std::vector<::pasta::ObjCProtocolDecl> Qualifieds(void) const;
  ::pasta::ObjCObjectPointerType StripObjCKindOfTypeAndQualifieds(void) const;
  std::vector<::pasta::ObjCProtocolDecl> Protocols(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type BaseType(void) const;
  ::pasta::ObjCInterfaceDecl Interface(void) const;
  ::pasta::Type SuperClassType(void) const;
  std::vector<::pasta::Type> TypeArguments(void) const;
  std::vector<::pasta::Type> TypeArgumentsAsWritten(void) const;
  bool IsKindOfType(void) const;
  bool IsKindOfTypeAsWritten(void) const;
  bool IsObjCClass(void) const;
  bool IsObjCId(void) const;
  bool IsObjCQualifiedClass(void) const;
  bool IsObjCQualifiedId(void) const;
  bool IsObjCUnqualifiedClass(void) const;
  bool IsObjCUnqualifiedId(void) const;
  bool IsObjCUnqualifiedIdOrClass(void) const;
  bool IsSpecialized(void) const;
  bool IsSpecializedAsWritten(void) const;
  bool IsSugared(void) const;
  bool IsUnspecialized(void) const;
  bool IsUnspecializedAsWritten(void) const;
  ::pasta::Type StripObjCKindOfTypeAndQualifieds(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::ObjCTypeParamDecl Declaration(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  std::optional<unsigned> NumExpansions(void) const;
  ::pasta::Type Pattern(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type InnerType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type ElementType(void) const;
  bool IsReadOnly(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type PointeeType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type PointeeType(void) const;
  ::pasta::Type PointeeTypeAsWritten(void) const;
  bool IsInnerReference(void) const;
  bool IsSpelledAsLValue(void) const;
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
  ::pasta::Type Desugar(void) const;
  // ArgumentPack: (clang::TemplateArgument)
  // Identifier: (clang::IdentifierInfo *)
  uint32_t NumArguments(void) const;
  ::pasta::TemplateTypeParmType ReplacedParameter(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::TemplateTypeParmType ReplacedParameter(void) const;
  ::pasta::Type ReplacementType(void) const;
  bool IsSugared(void) const;
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
  ::pasta::TagDecl Declaration(void) const;
  bool IsBeingDefined(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Type AliasedType(void) const;
  // Argument: (const clang::TemplateArgument &)
  // Arguments: (const clang::TemplateArgument *)
  uint32_t NumArguments(void) const;
  // TemplateName: (clang::TemplateName)
  bool IsCurrentInstantiation(void) const;
  bool IsSugared(void) const;
  bool IsTypeAlias(void) const;
  // TemplateArguments: (llvm::ArrayRef<clang::TemplateArgument>)
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
  ::pasta::Type Desugar(void) const;
  ::pasta::TemplateTypeParmDecl Declaration(void) const;
  uint32_t Depth(void) const;
  // Identifier: (clang::IdentifierInfo *)
  uint32_t Index(void) const;
  bool IsParameterPack(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::TokenRange BracketsRange(void) const;
  ::pasta::Token LBracketToken(void) const;
  ::pasta::Token RBracketToken(void) const;
  ::pasta::Expr SizeExpression(void) const;
  bool IsSugared(void) const;
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
  enum AutoTypeKeyword Keyword(void) const;
  uint32_t NumArguments(void) const;
  // TypeConstraintArguments: (llvm::ArrayRef<clang::TemplateArgument>)
  ::pasta::ConceptDecl TypeConstraintConcept(void) const;
  bool IsConstrained(void) const;
  bool IsDecltypeAuto(void) const;
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
  uint32_t NumColumns(void) const;
  uint32_t NumElementsFlattened(void) const;
  uint32_t NumRows(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::Token AttributeToken(void) const;
  ::pasta::Expr ColumnExpression(void) const;
  ::pasta::Type ElementType(void) const;
  ::pasta::Expr RowExpression(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::EnumDecl Declaration(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  bool IsSugared(void) const;
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
  enum CanThrowResult CanThrow(void) const;
  ::pasta::Type Desugar(void) const;
  std::vector<::pasta::Type> Exceptions(void) const;
  ::pasta::Token EllipsisToken(void) const;
  ::pasta::FunctionDecl ExceptionSpecDeclaration(void) const;
  // ExceptionSpecInfo: (clang::FunctionProtoType::ExceptionSpecInfo)
  ::pasta::FunctionDecl ExceptionSpecTemplate(void) const;
  enum ExceptionSpecificationType ExceptionSpecType(void) const;
  // ExceptionType: (clang::QualType)
  // ExtParameterInfo: (clang::FunctionType::ExtParameterInfo)
  // ExtParameterInfos: (llvm::ArrayRef<clang::FunctionType::ExtParameterInfo>)
  // ExtParameterInfosOrNull: (const clang::FunctionType::ExtParameterInfo *)
  // ExtProtoInfo: (clang::FunctionProtoType::ExtProtoInfo)
  // MethodQualifieds: (clang::Qualifiers)
  ::pasta::Expr NoexceptExpression(void) const;
  uint32_t NumExceptions(void) const;
  uint32_t NumParams(void) const;
  // ParamType: (clang::QualType)
  std::vector<::pasta::Type> ParamTypes(void) const;
  // ParameterABI: (clang::ParameterABI)
  enum RefQualifierKind ReferenceQualifier(void) const;
  bool HasDependentExceptionSpec(void) const;
  bool HasDynamicExceptionSpec(void) const;
  bool HasExceptionSpec(void) const;
  bool HasExtParameterInfos(void) const;
  bool HasInstantiationDependentExceptionSpec(void) const;
  bool HasNoexceptExceptionSpec(void) const;
  bool HasTrailingReturn(void) const;
  bool IsNothrow(void) const;
  // IsParamConsumed: (bool)
  bool IsSugared(void) const;
  bool IsTemplateVariadic(void) const;
  bool IsVariadic(void) const;
  // ParamTypes: (llvm::iterator_range<const clang::QualType *>)
  std::vector<::pasta::Type> ExceptionTypes(void) const;
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
  ::pasta::Type Desugar(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::ObjCInterfaceDecl Declaration(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  bool IsSugared(void) const;
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
  ::pasta::Type Desugar(void) const;
  ::pasta::RecordDecl Declaration(void) const;
  bool HasConstFields(void) const;
  bool IsSugared(void) const;
 protected:
  PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR(RecordType)
};
static_assert(sizeof(Type) == sizeof(RecordType));

}  // namespace pasta
#undef PASTA_DEFINE_DEFAULT_TYPE_CONSTRUCTOR
#endif  // !PASTA_IN_BOOTSTRAP
