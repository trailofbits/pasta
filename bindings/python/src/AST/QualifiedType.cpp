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
    .def_property_readonly("IgnoreParentheses", &QualifiedType::IgnoreParentheses)
    .def_property_readonly("AddressSpace", &QualifiedType::AddressSpace)
    .def_property_readonly("AtomicUnqualifiedType", &QualifiedType::AtomicUnqualifiedType)
    .def_property_readonly("CVRQualifiers", &QualifiedType::CVRQualifiers)
    .def_property_readonly("CanonicalType", &QualifiedType::CanonicalType)
    .def("DesugaredType", &QualifiedType::DesugaredType)
    .def_property_readonly("LocalCVRQualifiers", &QualifiedType::LocalCVRQualifiers)
    .def_property_readonly("LocalFastQualifiers", &QualifiedType::LocalFastQualifiers)
    .def_property_readonly("LocalUnqualifiedType", &QualifiedType::LocalUnqualifiedType)
    .def("NonLValueExpressionType", &QualifiedType::NonLValueExpressionType)
    .def_property_readonly("NonPackExpansionType", &QualifiedType::NonPackExpansionType)
    .def_property_readonly("NonReferenceType", &QualifiedType::NonReferenceType)
    .def("SingleStepDesugaredType", &QualifiedType::SingleStepDesugaredType)
    .def_property_readonly("HasAddressSpace", &QualifiedType::HasAddressSpace)
    .def_property_readonly("HasLocalNonFastQualifiers", &QualifiedType::HasLocalNonFastQualifiers)
    .def_property_readonly("HasLocalQualifiers", &QualifiedType::HasLocalQualifiers)
    .def_property_readonly("HasNonTrivialObjCLifetime", &QualifiedType::HasNonTrivialObjCLifetime)
    .def_property_readonly("HasNonTrivialToPrimitiveCopyCUnion", &QualifiedType::HasNonTrivialToPrimitiveCopyCUnion)
    .def_property_readonly("HasNonTrivialToPrimitiveDefaultInitializeCUnion", &QualifiedType::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_property_readonly("HasNonTrivialToPrimitiveDestructCUnion", &QualifiedType::HasNonTrivialToPrimitiveDestructCUnion)
    .def_property_readonly("HasQualifiers", &QualifiedType::HasQualifiers)
    .def_property_readonly("HasStrongOrWeakObjCLifetime", &QualifiedType::HasStrongOrWeakObjCLifetime)
    .def_property_readonly("IsCForbiddenLValueType", &QualifiedType::IsCForbiddenLValueType)
    .def("IsCXX11PODType", &QualifiedType::IsCXX11PODType)
    .def("IsCXX98PODType", &QualifiedType::IsCXX98PODType)
    .def_property_readonly("IsCanonical", &QualifiedType::IsCanonical)
    .def_property_readonly("IsCanonicalAsParameter", &QualifiedType::IsCanonicalAsParameter)
    .def_property_readonly("IsConstQualified", &QualifiedType::IsConstQualified)
    .def("IsConstant", &QualifiedType::IsConstant)
    .def_property_readonly("IsLocalConstQualified", &QualifiedType::IsLocalConstQualified)
    .def_property_readonly("IsLocalRestrictQualified", &QualifiedType::IsLocalRestrictQualified)
    .def_property_readonly("IsLocalVolatileQualified", &QualifiedType::IsLocalVolatileQualified)
    .def("IsNonWeakInMRRWithObjCWeak", &QualifiedType::IsNonWeakInMRRWithObjCWeak)
    .def_property_readonly("IsNull", &QualifiedType::IsNull)
    .def_property_readonly("IsObjCGCStrong", &QualifiedType::IsObjCGCStrong)
    .def_property_readonly("IsObjCGCWeak", &QualifiedType::IsObjCGCWeak)
    .def("IsPODType", &QualifiedType::IsPODType)
    .def_property_readonly("IsReferenceable", &QualifiedType::IsReferenceable)
    .def_property_readonly("IsRestrictQualified", &QualifiedType::IsRestrictQualified)
    .def("IsTrivialType", &QualifiedType::IsTrivialType)
    .def("IsTriviallyCopyableType", &QualifiedType::IsTriviallyCopyableType)
    .def("IsTriviallyRelocatableType", &QualifiedType::IsTriviallyRelocatableType)
    .def_property_readonly("IsVolatileQualified", &QualifiedType::IsVolatileQualified)
    .def_property_readonly("MayBeDynamicClass", &QualifiedType::MayBeDynamicClass)
    .def_property_readonly("MayBeNotDynamicClass", &QualifiedType::MayBeNotDynamicClass)
    .def("StripObjCKindOfType", &QualifiedType::StripObjCKindOfType)
    .def_property_readonly("WithConst", &QualifiedType::WithConst)
    .def_property_readonly("WithRestrict", &QualifiedType::WithRestrict)
    .def_property_readonly("WithVolatile", &QualifiedType::WithVolatile)
    .def_property_readonly("WithoutLocalFastQualifiers", &QualifiedType::WithoutLocalFastQualifiers);
}
} // namespace pasta
