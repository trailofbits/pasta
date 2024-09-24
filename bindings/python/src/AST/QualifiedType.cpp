/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterQualifiedType(nb::module_ &m) {
  nb::class_<QualifiedType, Type>(m, "QualifiedType")
    .def_prop_ro("ignore_parentheses", &QualifiedType::IgnoreParentheses)
    .def_prop_ro("address_space", &QualifiedType::AddressSpace)
    .def_prop_ro("atomic_unqualified_type", &QualifiedType::AtomicUnqualifiedType)
    .def_prop_ro("cvr_qualifiers", &QualifiedType::CVRQualifiers)
    .def_prop_ro("canonical_type", &QualifiedType::CanonicalType)
    .def_prop_ro("desugared_type", &QualifiedType::DesugaredType)
    .def_prop_ro("local_cvr_qualifiers", &QualifiedType::LocalCVRQualifiers)
    .def_prop_ro("local_fast_qualifiers", &QualifiedType::LocalFastQualifiers)
    .def_prop_ro("local_unqualified_type", &QualifiedType::LocalUnqualifiedType)
    .def_prop_ro("non_l_value_expression_type", &QualifiedType::NonLValueExpressionType)
    .def_prop_ro("non_pack_expansion_type", &QualifiedType::NonPackExpansionType)
    .def_prop_ro("non_reference_type", &QualifiedType::NonReferenceType)
    .def_prop_ro("single_step_desugared_type", &QualifiedType::SingleStepDesugaredType)
    .def_prop_ro("has_address_space", &QualifiedType::HasAddressSpace)
    .def_prop_ro("has_local_non_fast_qualifiers", &QualifiedType::HasLocalNonFastQualifiers)
    .def_prop_ro("has_local_qualifiers", &QualifiedType::HasLocalQualifiers)
    .def_prop_ro("has_non_trivial_obj_c_lifetime", &QualifiedType::HasNonTrivialObjCLifetime)
    .def_prop_ro("has_non_trivial_to_primitive_copy_c_union", &QualifiedType::HasNonTrivialToPrimitiveCopyCUnion)
    .def_prop_ro("has_non_trivial_to_primitive_default_initialize_c_union", &QualifiedType::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_prop_ro("has_non_trivial_to_primitive_destruct_c_union", &QualifiedType::HasNonTrivialToPrimitiveDestructCUnion)
    .def_prop_ro("has_qualifiers", &QualifiedType::HasQualifiers)
    .def_prop_ro("has_strong_or_weak_obj_c_lifetime", &QualifiedType::HasStrongOrWeakObjCLifetime)
    .def_prop_ro("is_c_forbidden_l_value_type", &QualifiedType::IsCForbiddenLValueType)
    .def_prop_ro("is_cxx11_pod_type", &QualifiedType::IsCXX11PODType)
    .def_prop_ro("is_cxx98_pod_type", &QualifiedType::IsCXX98PODType)
    .def_prop_ro("is_canonical", &QualifiedType::IsCanonical)
    .def_prop_ro("is_canonical_as_parameter", &QualifiedType::IsCanonicalAsParameter)
    .def_prop_ro("is_const_qualified", &QualifiedType::IsConstQualified)
    .def_prop_ro("is_constant", &QualifiedType::IsConstant)
    .def_prop_ro("is_local_const_qualified", &QualifiedType::IsLocalConstQualified)
    .def_prop_ro("is_local_restrict_qualified", &QualifiedType::IsLocalRestrictQualified)
    .def_prop_ro("is_local_volatile_qualified", &QualifiedType::IsLocalVolatileQualified)
    .def_prop_ro("is_non_weak_in_mrr_with_obj_c_weak", &QualifiedType::IsNonWeakInMRRWithObjCWeak)
    .def_prop_ro("is_null", &QualifiedType::IsNull)
    .def_prop_ro("is_obj_cgc_strong", &QualifiedType::IsObjCGCStrong)
    .def_prop_ro("is_obj_cgc_weak", &QualifiedType::IsObjCGCWeak)
    .def_prop_ro("is_pod_type", &QualifiedType::IsPODType)
    .def_prop_ro("is_referenceable", &QualifiedType::IsReferenceable)
    .def_prop_ro("is_restrict_qualified", &QualifiedType::IsRestrictQualified)
    .def_prop_ro("is_trivial_type", &QualifiedType::IsTrivialType)
    .def_prop_ro("is_trivially_copy_constructible_type", &QualifiedType::IsTriviallyCopyConstructibleType)
    .def_prop_ro("is_trivially_copyable_type", &QualifiedType::IsTriviallyCopyableType)
    .def_prop_ro("is_trivially_equality_comparable_type", &QualifiedType::IsTriviallyEqualityComparableType)
    .def_prop_ro("is_trivially_relocatable_type", &QualifiedType::IsTriviallyRelocatableType)
    .def_prop_ro("is_volatile_qualified", &QualifiedType::IsVolatileQualified)
    .def_prop_ro("is_web_assembly_externref_type", &QualifiedType::IsWebAssemblyExternrefType)
    .def_prop_ro("is_web_assembly_funcref_type", &QualifiedType::IsWebAssemblyFuncrefType)
    .def_prop_ro("is_web_assembly_reference_type", &QualifiedType::IsWebAssemblyReferenceType)
    .def_prop_ro("may_be_dynamic_class", &QualifiedType::MayBeDynamicClass)
    .def_prop_ro("may_be_not_dynamic_class", &QualifiedType::MayBeNotDynamicClass)
    .def_prop_ro("strip_obj_c_kind_of_type", &QualifiedType::StripObjCKindOfType)
    .def_prop_ro("with_const", &QualifiedType::WithConst)
    .def_prop_ro("with_restrict", &QualifiedType::WithRestrict)
    .def_prop_ro("with_volatile", &QualifiedType::WithVolatile)
    .def_prop_ro("without_local_fast_qualifiers", &QualifiedType::WithoutLocalFastQualifiers);
}
} // namespace pasta
