/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterType(nb::module_ &m) {
  nb::class_<Type>(m, "Type")
    .def("__hash__", [](const Type& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("accepts_obj_c_type_parameters", &Type::AcceptsObjCTypeParameters)
    .def_prop_ro("can_decay_to_pointer_type", &Type::CanDecayToPointerType)
    .def_prop_ro("can_have_nullability", &Type::CanHaveNullability)
    .def_prop_ro("contains_errors", &Type::ContainsErrors)
    .def_prop_ro("contains_unexpanded_parameter_pack", &Type::ContainsUnexpandedParameterPack)
    .def_prop_ro("array_element_type_no_type_qualified", &Type::ArrayElementTypeNoTypeQualified)
    .def_prop_ro("as_cxx_record_declaration", &Type::AsCXXRecordDeclaration)
    .def_prop_ro("as_complex_integer_type", &Type::AsComplexIntegerType)
    .def_prop_ro("as_obj_c_interface_pointer_type", &Type::AsObjCInterfacePointerType)
    .def_prop_ro("as_obj_c_interface_type", &Type::AsObjCInterfaceType)
    .def_prop_ro("as_obj_c_qualified_class_type", &Type::AsObjCQualifiedClassType)
    .def_prop_ro("as_obj_c_qualified_id_type", &Type::AsObjCQualifiedIdType)
    .def_prop_ro("as_obj_c_qualified_interface_type", &Type::AsObjCQualifiedInterfaceType)
    .def_prop_ro("as_placeholder_type", &Type::AsPlaceholderType)
    .def_prop_ro("as_record_declaration", &Type::AsRecordDeclaration)
    .def_prop_ro("as_structure_type", &Type::AsStructureType)
    .def_prop_ro("as_tag_declaration", &Type::AsTagDeclaration)
    .def_prop_ro("as_union_type", &Type::AsUnionType)
    .def_prop_ro("canonical_type_internal", &Type::CanonicalTypeInternal)
    .def_prop_ro("contained_auto_type", &Type::ContainedAutoType)
    .def_prop_ro("contained_deduced_type", &Type::ContainedDeducedType)
    .def_prop_ro("linkage", &Type::Linkage)
    .def_prop_ro("locally_unqualified_single_step_desugared_type", &Type::LocallyUnqualifiedSingleStepDesugaredType)
    .def_prop_ro("nullability", &Type::Nullability)
    .def_prop_ro("pointee_cxx_record_declaration", &Type::PointeeCXXRecordDeclaration)
    .def_prop_ro("pointee_or_array_element_type", &Type::PointeeOrArrayElementType)
    .def_prop_ro("pointee_type", &Type::PointeeType)
    .def_prop_ro("scalar_type_kind", &Type::ScalarTypeKind)
    .def("sve_element_type", &Type::SveElementType)
    .def_prop_ro("unqualified_desugared_type", &Type::UnqualifiedDesugaredType)
    .def_prop_ro("visibility", &Type::Visibility)
    .def_prop_ro("has_auto_for_trailing_return_type", &Type::HasAutoForTrailingReturnType)
    .def_prop_ro("has_floating_representation", &Type::HasFloatingRepresentation)
    .def_prop_ro("has_integer_representation", &Type::HasIntegerRepresentation)
    .def_prop_ro("has_obj_c_pointer_representation", &Type::HasObjCPointerRepresentation)
    .def_prop_ro("has_pointer_representation", &Type::HasPointerRepresentation)
    .def_prop_ro("has_signed_integer_representation", &Type::HasSignedIntegerRepresentation)
    .def_prop_ro("has_sized_vla_type", &Type::HasSizedVLAType)
    .def_prop_ro("has_unnamed_or_local_type", &Type::HasUnnamedOrLocalType)
    .def_prop_ro("has_unsigned_integer_representation", &Type::HasUnsignedIntegerRepresentation)
    .def_prop_ro("is_aggregate_type", &Type::IsAggregateType)
    .def_prop_ro("is_align_value_t", &Type::IsAlignValueT)
    .def_prop_ro("is_any_character_type", &Type::IsAnyCharacterType)
    .def_prop_ro("is_any_complex_type", &Type::IsAnyComplexType)
    .def_prop_ro("is_any_pointer_type", &Type::IsAnyPointerType)
    .def_prop_ro("is_arithmetic_type", &Type::IsArithmeticType)
    .def_prop_ro("is_array_type", &Type::IsArrayType)
    .def_prop_ro("is_atomic_type", &Type::IsAtomicType)
    .def_prop_ro("is_b_float16_type", &Type::IsBFloat16Type)
    .def_prop_ro("is_bit_int_type", &Type::IsBitIntType)
    .def("is_block_compatible_obj_c_pointer_type", &Type::IsBlockCompatibleObjCPointerType)
    .def_prop_ro("is_block_pointer_type", &Type::IsBlockPointerType)
    .def_prop_ro("is_boolean_type", &Type::IsBooleanType)
    .def_prop_ro("is_builtin_type", &Type::IsBuiltinType)
    .def_prop_ro("is_carc_bridgable_type", &Type::IsCARCBridgableType)
    .def_prop_ro("is_cuda_device_builtin_surface_type", &Type::IsCUDADeviceBuiltinSurfaceType)
    .def_prop_ro("is_cuda_device_builtin_texture_type", &Type::IsCUDADeviceBuiltinTextureType)
    .def_prop_ro("is_canonical_unqualified", &Type::IsCanonicalUnqualified)
    .def_prop_ro("is_char16_type", &Type::IsChar16Type)
    .def_prop_ro("is_char32_type", &Type::IsChar32Type)
    .def_prop_ro("is_char8_type", &Type::IsChar8Type)
    .def_prop_ro("is_character_type", &Type::IsCharacterType)
    .def_prop_ro("is_class_type", &Type::IsClassType)
    .def_prop_ro("is_clk_event_t", &Type::IsClkEventT)
    .def_prop_ro("is_complex_integer_type", &Type::IsComplexIntegerType)
    .def_prop_ro("is_complex_type", &Type::IsComplexType)
    .def_prop_ro("is_compound_type", &Type::IsCompoundType)
    .def_prop_ro("is_constant_array_type", &Type::IsConstantArrayType)
    .def_prop_ro("is_constant_matrix_type", &Type::IsConstantMatrixType)
    .def_prop_ro("is_constant_size_type", &Type::IsConstantSizeType)
    .def_prop_ro("is_decltype_type", &Type::IsDecltypeType)
    .def_prop_ro("is_dependent_address_space_type", &Type::IsDependentAddressSpaceType)
    .def_prop_ro("is_dependent_sized_array_type", &Type::IsDependentSizedArrayType)
    .def_prop_ro("is_dependent_type", &Type::IsDependentType)
    .def_prop_ro("is_elaborated_type_specifier", &Type::IsElaboratedTypeSpecifier)
    .def_prop_ro("is_enumeral_type", &Type::IsEnumeralType)
    .def_prop_ro("is_event_t", &Type::IsEventT)
    .def_prop_ro("is_ext_vector_boolean_type", &Type::IsExtVectorBooleanType)
    .def_prop_ro("is_ext_vector_type", &Type::IsExtVectorType)
    .def_prop_ro("is_fixed_point_or_integer_type", &Type::IsFixedPointOrIntegerType)
    .def_prop_ro("is_fixed_point_type", &Type::IsFixedPointType)
    .def_prop_ro("is_float128_type", &Type::IsFloat128Type)
    .def_prop_ro("is_float16_type", &Type::IsFloat16Type)
    .def_prop_ro("is_floating_type", &Type::IsFloatingType)
    .def_prop_ro("is_from_ast", &Type::IsFromAST)
    .def_prop_ro("is_function_no_proto_type", &Type::IsFunctionNoProtoType)
    .def_prop_ro("is_function_pointer_type", &Type::IsFunctionPointerType)
    .def_prop_ro("is_function_proto_type", &Type::IsFunctionProtoType)
    .def_prop_ro("is_function_reference_type", &Type::IsFunctionReferenceType)
    .def_prop_ro("is_function_type", &Type::IsFunctionType)
    .def_prop_ro("is_fundamental_type", &Type::IsFundamentalType)
    .def_prop_ro("is_half_type", &Type::IsHalfType)
    .def_prop_ro("is_ibm128_type", &Type::IsIbm128Type)
    .def_prop_ro("is_image_type", &Type::IsImageType)
    .def_prop_ro("is_incomplete_array_type", &Type::IsIncompleteArrayType)
    .def_prop_ro("is_incomplete_or_object_type", &Type::IsIncompleteOrObjectType)
    .def_prop_ro("is_incomplete_type", &Type::IsIncompleteType)
    .def_prop_ro("is_instantiation_dependent_type", &Type::IsInstantiationDependentType)
    .def_prop_ro("is_integer_type", &Type::IsIntegerType)
    .def_prop_ro("is_integral_or_enumeration_type", &Type::IsIntegralOrEnumerationType)
    .def_prop_ro("is_integral_or_unscoped_enumeration_type", &Type::IsIntegralOrUnscopedEnumerationType)
    .def("is_integral_type", &Type::IsIntegralType)
    .def_prop_ro("is_interface_type", &Type::IsInterfaceType)
    .def_prop_ro("is_l_value_reference_type", &Type::IsLValueReferenceType)
    .def_prop_ro("is_linkage_valid", &Type::IsLinkageValid)
    .def("is_literal_type", &Type::IsLiteralType)
    .def_prop_ro("is_matrix_type", &Type::IsMatrixType)
    .def_prop_ro("is_member_data_pointer_type", &Type::IsMemberDataPointerType)
    .def_prop_ro("is_member_function_pointer_type", &Type::IsMemberFunctionPointerType)
    .def_prop_ro("is_member_pointer_type", &Type::IsMemberPointerType)
    .def_prop_ro("is_non_overload_placeholder_type", &Type::IsNonOverloadPlaceholderType)
    .def_prop_ro("is_nothrow_t", &Type::IsNothrowT)
    .def_prop_ro("is_null_pointer_type", &Type::IsNullPointerType)
    .def_prop_ro("is_ocl_ext_opaque_type", &Type::IsOCLExtOpaqueType)
    .def_prop_ro("is_ocl_image_1d_array_ro_type", &Type::IsOCLImage1dArrayROType)
    .def_prop_ro("is_ocl_image_1d_array_rw_type", &Type::IsOCLImage1dArrayRWType)
    .def_prop_ro("is_ocl_image_1d_array_wo_type", &Type::IsOCLImage1dArrayWOType)
    .def_prop_ro("is_ocl_image_1d_buffer_ro_type", &Type::IsOCLImage1dBufferROType)
    .def_prop_ro("is_ocl_image_1d_buffer_rw_type", &Type::IsOCLImage1dBufferRWType)
    .def_prop_ro("is_ocl_image_1d_buffer_wo_type", &Type::IsOCLImage1dBufferWOType)
    .def_prop_ro("is_ocl_image_1d_ro_type", &Type::IsOCLImage1dROType)
    .def_prop_ro("is_ocl_image_1d_rw_type", &Type::IsOCLImage1dRWType)
    .def_prop_ro("is_ocl_image_1d_wo_type", &Type::IsOCLImage1dWOType)
    .def_prop_ro("is_ocl_image_2d_array_depth_ro_type", &Type::IsOCLImage2dArrayDepthROType)
    .def_prop_ro("is_ocl_image_2d_array_depth_rw_type", &Type::IsOCLImage2dArrayDepthRWType)
    .def_prop_ro("is_ocl_image_2d_array_depth_wo_type", &Type::IsOCLImage2dArrayDepthWOType)
    .def_prop_ro("is_ocl_image_2d_array_msaa_depth_ro_type", &Type::IsOCLImage2dArrayMSAADepthROType)
    .def_prop_ro("is_ocl_image_2d_array_msaa_depth_rw_type", &Type::IsOCLImage2dArrayMSAADepthRWType)
    .def_prop_ro("is_ocl_image_2d_array_msaa_depth_wo_type", &Type::IsOCLImage2dArrayMSAADepthWOType)
    .def_prop_ro("is_ocl_image_2d_array_msaaro_type", &Type::IsOCLImage2dArrayMSAAROType)
    .def_prop_ro("is_ocl_image_2d_array_msaarw_type", &Type::IsOCLImage2dArrayMSAARWType)
    .def_prop_ro("is_ocl_image_2d_array_msaawo_type", &Type::IsOCLImage2dArrayMSAAWOType)
    .def_prop_ro("is_ocl_image_2d_array_ro_type", &Type::IsOCLImage2dArrayROType)
    .def_prop_ro("is_ocl_image_2d_array_rw_type", &Type::IsOCLImage2dArrayRWType)
    .def_prop_ro("is_ocl_image_2d_array_wo_type", &Type::IsOCLImage2dArrayWOType)
    .def_prop_ro("is_ocl_image_2d_depth_ro_type", &Type::IsOCLImage2dDepthROType)
    .def_prop_ro("is_ocl_image_2d_depth_rw_type", &Type::IsOCLImage2dDepthRWType)
    .def_prop_ro("is_ocl_image_2d_depth_wo_type", &Type::IsOCLImage2dDepthWOType)
    .def_prop_ro("is_ocl_image_2d_msaa_depth_ro_type", &Type::IsOCLImage2dMSAADepthROType)
    .def_prop_ro("is_ocl_image_2d_msaa_depth_rw_type", &Type::IsOCLImage2dMSAADepthRWType)
    .def_prop_ro("is_ocl_image_2d_msaa_depth_wo_type", &Type::IsOCLImage2dMSAADepthWOType)
    .def_prop_ro("is_ocl_image_2d_msaaro_type", &Type::IsOCLImage2dMSAAROType)
    .def_prop_ro("is_ocl_image_2d_msaarw_type", &Type::IsOCLImage2dMSAARWType)
    .def_prop_ro("is_ocl_image_2d_msaawo_type", &Type::IsOCLImage2dMSAAWOType)
    .def_prop_ro("is_ocl_image_2d_ro_type", &Type::IsOCLImage2dROType)
    .def_prop_ro("is_ocl_image_2d_rw_type", &Type::IsOCLImage2dRWType)
    .def_prop_ro("is_ocl_image_2d_wo_type", &Type::IsOCLImage2dWOType)
    .def_prop_ro("is_ocl_image_3d_ro_type", &Type::IsOCLImage3dROType)
    .def_prop_ro("is_ocl_image_3d_rw_type", &Type::IsOCLImage3dRWType)
    .def_prop_ro("is_ocl_image_3d_wo_type", &Type::IsOCLImage3dWOType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type", &Type::IsOCLIntelSubgroupAVCImeDualReferenceStreaminType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_payload_type", &Type::IsOCLIntelSubgroupAVCImePayloadType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type", &Type::IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type", &Type::IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_result_type", &Type::IsOCLIntelSubgroupAVCImeResultType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type", &Type::IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_mce_payload_type", &Type::IsOCLIntelSubgroupAVCMcePayloadType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_mce_result_type", &Type::IsOCLIntelSubgroupAVCMceResultType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ref_payload_type", &Type::IsOCLIntelSubgroupAVCRefPayloadType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_ref_result_type", &Type::IsOCLIntelSubgroupAVCRefResultType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_sic_payload_type", &Type::IsOCLIntelSubgroupAVCSicPayloadType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_sic_result_type", &Type::IsOCLIntelSubgroupAVCSicResultType)
    .def_prop_ro("is_ocl_intel_subgroup_avc_type", &Type::IsOCLIntelSubgroupAVCType)
    .def_prop_ro("is_obj_carc_bridgable_type", &Type::IsObjCARCBridgableType)
    .def_prop_ro("is_obj_carc_implicitly_unretained_type", &Type::IsObjCARCImplicitlyUnretainedType)
    .def_prop_ro("is_obj_c_boxable_record_type", &Type::IsObjCBoxableRecordType)
    .def_prop_ro("is_obj_c_builtin_type", &Type::IsObjCBuiltinType)
    .def_prop_ro("is_obj_c_class_or_class_kind_of_type", &Type::IsObjCClassOrClassKindOfType)
    .def_prop_ro("is_obj_c_class_type", &Type::IsObjCClassType)
    .def_prop_ro("is_obj_c_id_type", &Type::IsObjCIdType)
    .def_prop_ro("is_obj_c_independent_class_type", &Type::IsObjCIndependentClassType)
    .def_prop_ro("is_obj_c_indirect_lifetime_type", &Type::IsObjCIndirectLifetimeType)
    .def_prop_ro("is_obj_c_inert_unsafe_unretained_type", &Type::IsObjCInertUnsafeUnretainedType)
    .def_prop_ro("is_obj_c_lifetime_type", &Type::IsObjCLifetimeType)
    .def_prop_ro("is_obj_cns_object_type", &Type::IsObjCNSObjectType)
    .def_prop_ro("is_obj_c_object_or_interface_type", &Type::IsObjCObjectOrInterfaceType)
    .def_prop_ro("is_obj_c_object_pointer_type", &Type::IsObjCObjectPointerType)
    .def_prop_ro("is_obj_c_object_type", &Type::IsObjCObjectType)
    .def_prop_ro("is_obj_c_qualified_class_type", &Type::IsObjCQualifiedClassType)
    .def_prop_ro("is_obj_c_qualified_id_type", &Type::IsObjCQualifiedIdType)
    .def_prop_ro("is_obj_c_qualified_interface_type", &Type::IsObjCQualifiedInterfaceType)
    .def_prop_ro("is_obj_c_retainable_type", &Type::IsObjCRetainableType)
    .def_prop_ro("is_obj_c_sel_type", &Type::IsObjCSelType)
    .def_prop_ro("is_object_pointer_type", &Type::IsObjectPointerType)
    .def_prop_ro("is_object_type", &Type::IsObjectType)
    .def_prop_ro("is_open_cl_specific_type", &Type::IsOpenCLSpecificType)
    .def_prop_ro("is_overloadable_type", &Type::IsOverloadableType)
    .def_prop_ro("is_pipe_type", &Type::IsPipeType)
    .def_prop_ro("is_placeholder_type", &Type::IsPlaceholderType)
    .def_prop_ro("is_pointer_type", &Type::IsPointerType)
    .def_prop_ro("is_queue_t", &Type::IsQueueT)
    .def_prop_ro("is_rvv_type", &Type::IsRVVType)
    .def_prop_ro("is_r_value_reference_type", &Type::IsRValueReferenceType)
    .def_prop_ro("is_real_floating_type", &Type::IsRealFloatingType)
    .def_prop_ro("is_real_type", &Type::IsRealType)
    .def_prop_ro("is_record_type", &Type::IsRecordType)
    .def_prop_ro("is_reference_type", &Type::IsReferenceType)
    .def_prop_ro("is_reserve_idt", &Type::IsReserveIDT)
    .def_prop_ro("is_sve_sizeless_builtin_type", &Type::IsSVESizelessBuiltinType)
    .def_prop_ro("is_sampler_t", &Type::IsSamplerT)
    .def_prop_ro("is_saturated_fixed_point_type", &Type::IsSaturatedFixedPointType)
    .def_prop_ro("is_scalar_type", &Type::IsScalarType)
    .def_prop_ro("is_scoped_enumeral_type", &Type::IsScopedEnumeralType)
    .def_prop_ro("is_signed_fixed_point_type", &Type::IsSignedFixedPointType)
    .def_prop_ro("is_signed_integer_or_enumeration_type", &Type::IsSignedIntegerOrEnumerationType)
    .def_prop_ro("is_signed_integer_type", &Type::IsSignedIntegerType)
    .def_prop_ro("is_sizeless_builtin_type", &Type::IsSizelessBuiltinType)
    .def_prop_ro("is_sizeless_type", &Type::IsSizelessType)
    .def_prop_ro("is_specifier_type", &Type::IsSpecifierType)
    .def_prop_ro("is_standard_layout_type", &Type::IsStandardLayoutType)
    .def_prop_ro("is_std_byte_type", &Type::IsStdByteType)
    .def_prop_ro("is_structural_type", &Type::IsStructuralType)
    .def_prop_ro("is_structure_or_class_type", &Type::IsStructureOrClassType)
    .def_prop_ro("is_structure_type", &Type::IsStructureType)
    .def_prop_ro("is_template_type_parm_type", &Type::IsTemplateTypeParmType)
    .def_prop_ro("is_typedef_name_type", &Type::IsTypedefNameType)
    .def_prop_ro("is_undeduced_auto_type", &Type::IsUndeducedAutoType)
    .def_prop_ro("is_undeduced_type", &Type::IsUndeducedType)
    .def_prop_ro("is_union_type", &Type::IsUnionType)
    .def_prop_ro("is_unsaturated_fixed_point_type", &Type::IsUnsaturatedFixedPointType)
    .def_prop_ro("is_unscoped_enumeration_type", &Type::IsUnscopedEnumerationType)
    .def_prop_ro("is_unsigned_fixed_point_type", &Type::IsUnsignedFixedPointType)
    .def_prop_ro("is_unsigned_integer_or_enumeration_type", &Type::IsUnsignedIntegerOrEnumerationType)
    .def_prop_ro("is_unsigned_integer_type", &Type::IsUnsignedIntegerType)
    .def_prop_ro("is_vlst_builtin_type", &Type::IsVLSTBuiltinType)
    .def_prop_ro("is_variable_array_type", &Type::IsVariableArrayType)
    .def_prop_ro("is_variably_modified_type", &Type::IsVariablyModifiedType)
    .def_prop_ro("is_vector_type", &Type::IsVectorType)
    .def_prop_ro("is_visibility_explicit", &Type::IsVisibilityExplicit)
    .def_prop_ro("is_void_pointer_type", &Type::IsVoidPointerType)
    .def_prop_ro("is_void_type", &Type::IsVoidType)
    .def_prop_ro("is_wide_character_type", &Type::IsWideCharacterType);
}
} // namespace pasta
