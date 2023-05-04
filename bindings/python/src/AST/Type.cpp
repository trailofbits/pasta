/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterType(py::module_ &m) {
  py::class_<Type>(m, "Type")
    .def("__hash__", [](const Type& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("AcceptsObjCTypeParameters", &Type::AcceptsObjCTypeParameters)
    .def_property_readonly("CanDecayToPointerType", &Type::CanDecayToPointerType)
    .def_property_readonly("CanHaveNullability", &Type::CanHaveNullability)
    .def_property_readonly("ContainsErrors", &Type::ContainsErrors)
    .def_property_readonly("ContainsUnexpandedParameterPack", &Type::ContainsUnexpandedParameterPack)
    .def_property_readonly("ArrayElementTypeNoTypeQualified", &Type::ArrayElementTypeNoTypeQualified)
    .def_property_readonly("AsCXXRecordDeclaration", &Type::AsCXXRecordDeclaration)
    .def_property_readonly("AsComplexIntegerType", &Type::AsComplexIntegerType)
    .def_property_readonly("AsObjCInterfacePointerType", &Type::AsObjCInterfacePointerType)
    .def_property_readonly("AsObjCInterfaceType", &Type::AsObjCInterfaceType)
    .def_property_readonly("AsObjCQualifiedClassType", &Type::AsObjCQualifiedClassType)
    .def_property_readonly("AsObjCQualifiedIdType", &Type::AsObjCQualifiedIdType)
    .def_property_readonly("AsObjCQualifiedInterfaceType", &Type::AsObjCQualifiedInterfaceType)
    .def_property_readonly("AsPlaceholderType", &Type::AsPlaceholderType)
    .def_property_readonly("AsRecordDeclaration", &Type::AsRecordDeclaration)
    .def_property_readonly("AsStructureType", &Type::AsStructureType)
    .def_property_readonly("AsTagDeclaration", &Type::AsTagDeclaration)
    .def_property_readonly("AsUnionType", &Type::AsUnionType)
    .def_property_readonly("CanonicalTypeInternal", &Type::CanonicalTypeInternal)
    .def_property_readonly("ContainedAutoType", &Type::ContainedAutoType)
    .def_property_readonly("ContainedDeducedType", &Type::ContainedDeducedType)
    .def_property_readonly("Linkage", &Type::Linkage)
    .def_property_readonly("LocallyUnqualifiedSingleStepDesugaredType", &Type::LocallyUnqualifiedSingleStepDesugaredType)
    .def_property_readonly("Nullability", &Type::Nullability)
    .def_property_readonly("PointeeCXXRecordDeclaration", &Type::PointeeCXXRecordDeclaration)
    .def_property_readonly("PointeeOrArrayElementType", &Type::PointeeOrArrayElementType)
    .def_property_readonly("PointeeType", &Type::PointeeType)
    .def_property_readonly("ScalarTypeKind", &Type::ScalarTypeKind)
    .def("SveElementType", &Type::SveElementType)
    .def_property_readonly("UnqualifiedDesugaredType", &Type::UnqualifiedDesugaredType)
    .def_property_readonly("Visibility", &Type::Visibility)
    .def_property_readonly("HasAutoForTrailingReturnType", &Type::HasAutoForTrailingReturnType)
    .def_property_readonly("HasFloatingRepresentation", &Type::HasFloatingRepresentation)
    .def_property_readonly("HasIntegerRepresentation", &Type::HasIntegerRepresentation)
    .def_property_readonly("HasObjCPointerRepresentation", &Type::HasObjCPointerRepresentation)
    .def_property_readonly("HasPointerRepresentation", &Type::HasPointerRepresentation)
    .def_property_readonly("HasSignedIntegerRepresentation", &Type::HasSignedIntegerRepresentation)
    .def_property_readonly("HasSizedVLAType", &Type::HasSizedVLAType)
    .def_property_readonly("HasUnnamedOrLocalType", &Type::HasUnnamedOrLocalType)
    .def_property_readonly("HasUnsignedIntegerRepresentation", &Type::HasUnsignedIntegerRepresentation)
    .def_property_readonly("IsAggregateType", &Type::IsAggregateType)
    .def_property_readonly("IsAlignValueT", &Type::IsAlignValueT)
    .def_property_readonly("IsAnyCharacterType", &Type::IsAnyCharacterType)
    .def_property_readonly("IsAnyComplexType", &Type::IsAnyComplexType)
    .def_property_readonly("IsAnyPointerType", &Type::IsAnyPointerType)
    .def_property_readonly("IsArithmeticType", &Type::IsArithmeticType)
    .def_property_readonly("IsArrayType", &Type::IsArrayType)
    .def_property_readonly("IsAtomicType", &Type::IsAtomicType)
    .def_property_readonly("IsBFloat16Type", &Type::IsBFloat16Type)
    .def_property_readonly("IsBitIntType", &Type::IsBitIntType)
    .def("IsBlockCompatibleObjCPointerType", &Type::IsBlockCompatibleObjCPointerType)
    .def_property_readonly("IsBlockPointerType", &Type::IsBlockPointerType)
    .def_property_readonly("IsBooleanType", &Type::IsBooleanType)
    .def_property_readonly("IsBuiltinType", &Type::IsBuiltinType)
    .def_property_readonly("IsCARCBridgableType", &Type::IsCARCBridgableType)
    .def_property_readonly("IsCUDADeviceBuiltinSurfaceType", &Type::IsCUDADeviceBuiltinSurfaceType)
    .def_property_readonly("IsCUDADeviceBuiltinTextureType", &Type::IsCUDADeviceBuiltinTextureType)
    .def_property_readonly("IsCanonicalUnqualified", &Type::IsCanonicalUnqualified)
    .def_property_readonly("IsChar16Type", &Type::IsChar16Type)
    .def_property_readonly("IsChar32Type", &Type::IsChar32Type)
    .def_property_readonly("IsChar8Type", &Type::IsChar8Type)
    .def_property_readonly("IsCharacterType", &Type::IsCharacterType)
    .def_property_readonly("IsClassType", &Type::IsClassType)
    .def_property_readonly("IsClkEventT", &Type::IsClkEventT)
    .def_property_readonly("IsComplexIntegerType", &Type::IsComplexIntegerType)
    .def_property_readonly("IsComplexType", &Type::IsComplexType)
    .def_property_readonly("IsCompoundType", &Type::IsCompoundType)
    .def_property_readonly("IsConstantArrayType", &Type::IsConstantArrayType)
    .def_property_readonly("IsConstantMatrixType", &Type::IsConstantMatrixType)
    .def_property_readonly("IsConstantSizeType", &Type::IsConstantSizeType)
    .def_property_readonly("IsDecltypeType", &Type::IsDecltypeType)
    .def_property_readonly("IsDependentAddressSpaceType", &Type::IsDependentAddressSpaceType)
    .def_property_readonly("IsDependentSizedArrayType", &Type::IsDependentSizedArrayType)
    .def_property_readonly("IsDependentType", &Type::IsDependentType)
    .def_property_readonly("IsElaboratedTypeSpecifier", &Type::IsElaboratedTypeSpecifier)
    .def_property_readonly("IsEnumeralType", &Type::IsEnumeralType)
    .def_property_readonly("IsEventT", &Type::IsEventT)
    .def_property_readonly("IsExtVectorBooleanType", &Type::IsExtVectorBooleanType)
    .def_property_readonly("IsExtVectorType", &Type::IsExtVectorType)
    .def_property_readonly("IsFixedPointOrIntegerType", &Type::IsFixedPointOrIntegerType)
    .def_property_readonly("IsFixedPointType", &Type::IsFixedPointType)
    .def_property_readonly("IsFloat128Type", &Type::IsFloat128Type)
    .def_property_readonly("IsFloat16Type", &Type::IsFloat16Type)
    .def_property_readonly("IsFloatingType", &Type::IsFloatingType)
    .def_property_readonly("IsFromAST", &Type::IsFromAST)
    .def_property_readonly("IsFunctionNoProtoType", &Type::IsFunctionNoProtoType)
    .def_property_readonly("IsFunctionPointerType", &Type::IsFunctionPointerType)
    .def_property_readonly("IsFunctionProtoType", &Type::IsFunctionProtoType)
    .def_property_readonly("IsFunctionReferenceType", &Type::IsFunctionReferenceType)
    .def_property_readonly("IsFunctionType", &Type::IsFunctionType)
    .def_property_readonly("IsFundamentalType", &Type::IsFundamentalType)
    .def_property_readonly("IsHalfType", &Type::IsHalfType)
    .def_property_readonly("IsIbm128Type", &Type::IsIbm128Type)
    .def_property_readonly("IsImageType", &Type::IsImageType)
    .def_property_readonly("IsIncompleteArrayType", &Type::IsIncompleteArrayType)
    .def_property_readonly("IsIncompleteOrObjectType", &Type::IsIncompleteOrObjectType)
    .def_property_readonly("IsIncompleteType", &Type::IsIncompleteType)
    .def_property_readonly("IsInstantiationDependentType", &Type::IsInstantiationDependentType)
    .def_property_readonly("IsIntegerType", &Type::IsIntegerType)
    .def_property_readonly("IsIntegralOrEnumerationType", &Type::IsIntegralOrEnumerationType)
    .def_property_readonly("IsIntegralOrUnscopedEnumerationType", &Type::IsIntegralOrUnscopedEnumerationType)
    .def("IsIntegralType", &Type::IsIntegralType)
    .def_property_readonly("IsInterfaceType", &Type::IsInterfaceType)
    .def_property_readonly("IsLValueReferenceType", &Type::IsLValueReferenceType)
    .def_property_readonly("IsLinkageValid", &Type::IsLinkageValid)
    .def("IsLiteralType", &Type::IsLiteralType)
    .def_property_readonly("IsMatrixType", &Type::IsMatrixType)
    .def_property_readonly("IsMemberDataPointerType", &Type::IsMemberDataPointerType)
    .def_property_readonly("IsMemberFunctionPointerType", &Type::IsMemberFunctionPointerType)
    .def_property_readonly("IsMemberPointerType", &Type::IsMemberPointerType)
    .def_property_readonly("IsNonOverloadPlaceholderType", &Type::IsNonOverloadPlaceholderType)
    .def_property_readonly("IsNothrowT", &Type::IsNothrowT)
    .def_property_readonly("IsNullPointerType", &Type::IsNullPointerType)
    .def_property_readonly("IsOCLExtOpaqueType", &Type::IsOCLExtOpaqueType)
    .def_property_readonly("IsOCLImage1dArrayROType", &Type::IsOCLImage1dArrayROType)
    .def_property_readonly("IsOCLImage1dArrayRWType", &Type::IsOCLImage1dArrayRWType)
    .def_property_readonly("IsOCLImage1dArrayWOType", &Type::IsOCLImage1dArrayWOType)
    .def_property_readonly("IsOCLImage1dBufferROType", &Type::IsOCLImage1dBufferROType)
    .def_property_readonly("IsOCLImage1dBufferRWType", &Type::IsOCLImage1dBufferRWType)
    .def_property_readonly("IsOCLImage1dBufferWOType", &Type::IsOCLImage1dBufferWOType)
    .def_property_readonly("IsOCLImage1dROType", &Type::IsOCLImage1dROType)
    .def_property_readonly("IsOCLImage1dRWType", &Type::IsOCLImage1dRWType)
    .def_property_readonly("IsOCLImage1dWOType", &Type::IsOCLImage1dWOType)
    .def_property_readonly("IsOCLImage2dArrayDepthROType", &Type::IsOCLImage2dArrayDepthROType)
    .def_property_readonly("IsOCLImage2dArrayDepthRWType", &Type::IsOCLImage2dArrayDepthRWType)
    .def_property_readonly("IsOCLImage2dArrayDepthWOType", &Type::IsOCLImage2dArrayDepthWOType)
    .def_property_readonly("IsOCLImage2dArrayMSAADepthROType", &Type::IsOCLImage2dArrayMSAADepthROType)
    .def_property_readonly("IsOCLImage2dArrayMSAADepthRWType", &Type::IsOCLImage2dArrayMSAADepthRWType)
    .def_property_readonly("IsOCLImage2dArrayMSAADepthWOType", &Type::IsOCLImage2dArrayMSAADepthWOType)
    .def_property_readonly("IsOCLImage2dArrayMSAAROType", &Type::IsOCLImage2dArrayMSAAROType)
    .def_property_readonly("IsOCLImage2dArrayMSAARWType", &Type::IsOCLImage2dArrayMSAARWType)
    .def_property_readonly("IsOCLImage2dArrayMSAAWOType", &Type::IsOCLImage2dArrayMSAAWOType)
    .def_property_readonly("IsOCLImage2dArrayROType", &Type::IsOCLImage2dArrayROType)
    .def_property_readonly("IsOCLImage2dArrayRWType", &Type::IsOCLImage2dArrayRWType)
    .def_property_readonly("IsOCLImage2dArrayWOType", &Type::IsOCLImage2dArrayWOType)
    .def_property_readonly("IsOCLImage2dDepthROType", &Type::IsOCLImage2dDepthROType)
    .def_property_readonly("IsOCLImage2dDepthRWType", &Type::IsOCLImage2dDepthRWType)
    .def_property_readonly("IsOCLImage2dDepthWOType", &Type::IsOCLImage2dDepthWOType)
    .def_property_readonly("IsOCLImage2dMSAADepthROType", &Type::IsOCLImage2dMSAADepthROType)
    .def_property_readonly("IsOCLImage2dMSAADepthRWType", &Type::IsOCLImage2dMSAADepthRWType)
    .def_property_readonly("IsOCLImage2dMSAADepthWOType", &Type::IsOCLImage2dMSAADepthWOType)
    .def_property_readonly("IsOCLImage2dMSAAROType", &Type::IsOCLImage2dMSAAROType)
    .def_property_readonly("IsOCLImage2dMSAARWType", &Type::IsOCLImage2dMSAARWType)
    .def_property_readonly("IsOCLImage2dMSAAWOType", &Type::IsOCLImage2dMSAAWOType)
    .def_property_readonly("IsOCLImage2dROType", &Type::IsOCLImage2dROType)
    .def_property_readonly("IsOCLImage2dRWType", &Type::IsOCLImage2dRWType)
    .def_property_readonly("IsOCLImage2dWOType", &Type::IsOCLImage2dWOType)
    .def_property_readonly("IsOCLImage3dROType", &Type::IsOCLImage3dROType)
    .def_property_readonly("IsOCLImage3dRWType", &Type::IsOCLImage3dRWType)
    .def_property_readonly("IsOCLImage3dWOType", &Type::IsOCLImage3dWOType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImeDualReferenceStreaminType", &Type::IsOCLIntelSubgroupAVCImeDualReferenceStreaminType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImePayloadType", &Type::IsOCLIntelSubgroupAVCImePayloadType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType", &Type::IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType", &Type::IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImeResultType", &Type::IsOCLIntelSubgroupAVCImeResultType)
    .def_property_readonly("IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType", &Type::IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType)
    .def_property_readonly("IsOCLIntelSubgroupAVCMcePayloadType", &Type::IsOCLIntelSubgroupAVCMcePayloadType)
    .def_property_readonly("IsOCLIntelSubgroupAVCMceResultType", &Type::IsOCLIntelSubgroupAVCMceResultType)
    .def_property_readonly("IsOCLIntelSubgroupAVCRefPayloadType", &Type::IsOCLIntelSubgroupAVCRefPayloadType)
    .def_property_readonly("IsOCLIntelSubgroupAVCRefResultType", &Type::IsOCLIntelSubgroupAVCRefResultType)
    .def_property_readonly("IsOCLIntelSubgroupAVCSicPayloadType", &Type::IsOCLIntelSubgroupAVCSicPayloadType)
    .def_property_readonly("IsOCLIntelSubgroupAVCSicResultType", &Type::IsOCLIntelSubgroupAVCSicResultType)
    .def_property_readonly("IsOCLIntelSubgroupAVCType", &Type::IsOCLIntelSubgroupAVCType)
    .def_property_readonly("IsObjCARCBridgableType", &Type::IsObjCARCBridgableType)
    .def_property_readonly("IsObjCARCImplicitlyUnretainedType", &Type::IsObjCARCImplicitlyUnretainedType)
    .def_property_readonly("IsObjCBoxableRecordType", &Type::IsObjCBoxableRecordType)
    .def_property_readonly("IsObjCBuiltinType", &Type::IsObjCBuiltinType)
    .def_property_readonly("IsObjCClassOrClassKindOfType", &Type::IsObjCClassOrClassKindOfType)
    .def_property_readonly("IsObjCClassType", &Type::IsObjCClassType)
    .def_property_readonly("IsObjCIdType", &Type::IsObjCIdType)
    .def_property_readonly("IsObjCIndependentClassType", &Type::IsObjCIndependentClassType)
    .def_property_readonly("IsObjCIndirectLifetimeType", &Type::IsObjCIndirectLifetimeType)
    .def_property_readonly("IsObjCInertUnsafeUnretainedType", &Type::IsObjCInertUnsafeUnretainedType)
    .def_property_readonly("IsObjCLifetimeType", &Type::IsObjCLifetimeType)
    .def_property_readonly("IsObjCNSObjectType", &Type::IsObjCNSObjectType)
    .def_property_readonly("IsObjCObjectOrInterfaceType", &Type::IsObjCObjectOrInterfaceType)
    .def_property_readonly("IsObjCObjectPointerType", &Type::IsObjCObjectPointerType)
    .def_property_readonly("IsObjCObjectType", &Type::IsObjCObjectType)
    .def_property_readonly("IsObjCQualifiedClassType", &Type::IsObjCQualifiedClassType)
    .def_property_readonly("IsObjCQualifiedIdType", &Type::IsObjCQualifiedIdType)
    .def_property_readonly("IsObjCQualifiedInterfaceType", &Type::IsObjCQualifiedInterfaceType)
    .def_property_readonly("IsObjCRetainableType", &Type::IsObjCRetainableType)
    .def_property_readonly("IsObjCSelType", &Type::IsObjCSelType)
    .def_property_readonly("IsObjectPointerType", &Type::IsObjectPointerType)
    .def_property_readonly("IsObjectType", &Type::IsObjectType)
    .def_property_readonly("IsOpenCLSpecificType", &Type::IsOpenCLSpecificType)
    .def_property_readonly("IsOverloadableType", &Type::IsOverloadableType)
    .def_property_readonly("IsPipeType", &Type::IsPipeType)
    .def_property_readonly("IsPlaceholderType", &Type::IsPlaceholderType)
    .def_property_readonly("IsPointerType", &Type::IsPointerType)
    .def_property_readonly("IsQueueT", &Type::IsQueueT)
    .def_property_readonly("IsRVVType", &Type::IsRVVType)
    .def_property_readonly("IsRValueReferenceType", &Type::IsRValueReferenceType)
    .def_property_readonly("IsRealFloatingType", &Type::IsRealFloatingType)
    .def_property_readonly("IsRealType", &Type::IsRealType)
    .def_property_readonly("IsRecordType", &Type::IsRecordType)
    .def_property_readonly("IsReferenceType", &Type::IsReferenceType)
    .def_property_readonly("IsReserveIDT", &Type::IsReserveIDT)
    .def_property_readonly("IsSVESizelessBuiltinType", &Type::IsSVESizelessBuiltinType)
    .def_property_readonly("IsSamplerT", &Type::IsSamplerT)
    .def_property_readonly("IsSaturatedFixedPointType", &Type::IsSaturatedFixedPointType)
    .def_property_readonly("IsScalarType", &Type::IsScalarType)
    .def_property_readonly("IsScopedEnumeralType", &Type::IsScopedEnumeralType)
    .def_property_readonly("IsSignedFixedPointType", &Type::IsSignedFixedPointType)
    .def_property_readonly("IsSignedIntegerOrEnumerationType", &Type::IsSignedIntegerOrEnumerationType)
    .def_property_readonly("IsSignedIntegerType", &Type::IsSignedIntegerType)
    .def_property_readonly("IsSizelessBuiltinType", &Type::IsSizelessBuiltinType)
    .def_property_readonly("IsSizelessType", &Type::IsSizelessType)
    .def_property_readonly("IsSpecifierType", &Type::IsSpecifierType)
    .def_property_readonly("IsStandardLayoutType", &Type::IsStandardLayoutType)
    .def_property_readonly("IsStdByteType", &Type::IsStdByteType)
    .def_property_readonly("IsStructuralType", &Type::IsStructuralType)
    .def_property_readonly("IsStructureOrClassType", &Type::IsStructureOrClassType)
    .def_property_readonly("IsStructureType", &Type::IsStructureType)
    .def_property_readonly("IsTemplateTypeParmType", &Type::IsTemplateTypeParmType)
    .def_property_readonly("IsTypedefNameType", &Type::IsTypedefNameType)
    .def_property_readonly("IsUndeducedAutoType", &Type::IsUndeducedAutoType)
    .def_property_readonly("IsUndeducedType", &Type::IsUndeducedType)
    .def_property_readonly("IsUnionType", &Type::IsUnionType)
    .def_property_readonly("IsUnsaturatedFixedPointType", &Type::IsUnsaturatedFixedPointType)
    .def_property_readonly("IsUnscopedEnumerationType", &Type::IsUnscopedEnumerationType)
    .def_property_readonly("IsUnsignedFixedPointType", &Type::IsUnsignedFixedPointType)
    .def_property_readonly("IsUnsignedIntegerOrEnumerationType", &Type::IsUnsignedIntegerOrEnumerationType)
    .def_property_readonly("IsUnsignedIntegerType", &Type::IsUnsignedIntegerType)
    .def_property_readonly("IsVLSTBuiltinType", &Type::IsVLSTBuiltinType)
    .def_property_readonly("IsVariableArrayType", &Type::IsVariableArrayType)
    .def_property_readonly("IsVariablyModifiedType", &Type::IsVariablyModifiedType)
    .def_property_readonly("IsVectorType", &Type::IsVectorType)
    .def_property_readonly("IsVisibilityExplicit", &Type::IsVisibilityExplicit)
    .def_property_readonly("IsVoidPointerType", &Type::IsVoidPointerType)
    .def_property_readonly("IsVoidType", &Type::IsVoidType)
    .def_property_readonly("IsWideCharacterType", &Type::IsWideCharacterType);
}
} // namespace pasta