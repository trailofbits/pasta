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

void RegisterQualifiedType(py::module_ &m) {
  py::class_<QualifiedType, Type>(m, "QualifiedType")
    .def("__hash__", [](const QualifiedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const QualifiedType& a, const QualifiedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("ignore_parentheses", &QualifiedType::IgnoreParentheses)
    .def_property_readonly("address_space", &QualifiedType::AddressSpace)
    .def_property_readonly("atomic_unqualified_type", &QualifiedType::AtomicUnqualifiedType)
    .def_property_readonly("cvr_qualifiers", &QualifiedType::CVRQualifiers)
    .def_property_readonly("canonical_type", &QualifiedType::CanonicalType)
    .def("desugared_type", &QualifiedType::DesugaredType)
    .def_property_readonly("local_cvr_qualifiers", &QualifiedType::LocalCVRQualifiers)
    .def_property_readonly("local_fast_qualifiers", &QualifiedType::LocalFastQualifiers)
    .def_property_readonly("local_unqualified_type", &QualifiedType::LocalUnqualifiedType)
    .def("non_l_value_expression_type", &QualifiedType::NonLValueExpressionType)
    .def_property_readonly("non_pack_expansion_type", &QualifiedType::NonPackExpansionType)
    .def_property_readonly("non_reference_type", &QualifiedType::NonReferenceType)
    .def("single_step_desugared_type", &QualifiedType::SingleStepDesugaredType)
    .def_property_readonly("has_address_space", &QualifiedType::HasAddressSpace)
    .def_property_readonly("has_local_non_fast_qualifiers", &QualifiedType::HasLocalNonFastQualifiers)
    .def_property_readonly("has_local_qualifiers", &QualifiedType::HasLocalQualifiers)
    .def_property_readonly("has_non_trivial_obj_c_lifetime", &QualifiedType::HasNonTrivialObjCLifetime)
    .def_property_readonly("has_non_trivial_to_primitive_copy_c_union", &QualifiedType::HasNonTrivialToPrimitiveCopyCUnion)
    .def_property_readonly("has_non_trivial_to_primitive_default_initialize_c_union", &QualifiedType::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_property_readonly("has_non_trivial_to_primitive_destruct_c_union", &QualifiedType::HasNonTrivialToPrimitiveDestructCUnion)
    .def_property_readonly("has_qualifiers", &QualifiedType::HasQualifiers)
    .def_property_readonly("has_strong_or_weak_obj_c_lifetime", &QualifiedType::HasStrongOrWeakObjCLifetime)
    .def_property_readonly("is_c_forbidden_l_value_type", &QualifiedType::IsCForbiddenLValueType)
    .def("is_cxx11_pod_type", &QualifiedType::IsCXX11PODType)
    .def("is_cxx98_pod_type", &QualifiedType::IsCXX98PODType)
    .def_property_readonly("is_canonical", &QualifiedType::IsCanonical)
    .def_property_readonly("is_canonical_as_parameter", &QualifiedType::IsCanonicalAsParameter)
    .def_property_readonly("is_const_qualified", &QualifiedType::IsConstQualified)
    .def("is_constant", &QualifiedType::IsConstant)
    .def_property_readonly("is_local_const_qualified", &QualifiedType::IsLocalConstQualified)
    .def_property_readonly("is_local_restrict_qualified", &QualifiedType::IsLocalRestrictQualified)
    .def_property_readonly("is_local_volatile_qualified", &QualifiedType::IsLocalVolatileQualified)
    .def("is_non_weak_in_mrr_with_obj_c_weak", &QualifiedType::IsNonWeakInMRRWithObjCWeak)
    .def_property_readonly("is_null", &QualifiedType::IsNull)
    .def_property_readonly("is_obj_cgc_strong", &QualifiedType::IsObjCGCStrong)
    .def_property_readonly("is_obj_cgc_weak", &QualifiedType::IsObjCGCWeak)
    .def("is_pod_type", &QualifiedType::IsPODType)
    .def_property_readonly("is_referenceable", &QualifiedType::IsReferenceable)
    .def_property_readonly("is_restrict_qualified", &QualifiedType::IsRestrictQualified)
    .def("is_trivial_type", &QualifiedType::IsTrivialType)
    .def("is_trivially_copyable_type", &QualifiedType::IsTriviallyCopyableType)
    .def("is_trivially_relocatable_type", &QualifiedType::IsTriviallyRelocatableType)
    .def_property_readonly("is_volatile_qualified", &QualifiedType::IsVolatileQualified)
    .def_property_readonly("may_be_dynamic_class", &QualifiedType::MayBeDynamicClass)
    .def_property_readonly("may_be_not_dynamic_class", &QualifiedType::MayBeNotDynamicClass)
    .def("strip_obj_c_kind_of_type", &QualifiedType::StripObjCKindOfType)
    .def_property_readonly("with_const", &QualifiedType::WithConst)
    .def_property_readonly("with_restrict", &QualifiedType::WithRestrict)
    .def_property_readonly("with_volatile", &QualifiedType::WithVolatile)
    .def_property_readonly("without_local_fast_qualifiers", &QualifiedType::WithoutLocalFastQualifiers);
}
} // namespace pasta
