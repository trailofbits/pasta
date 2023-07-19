/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterAttributedType(nb::module_ &m) {
  nb::class_<AttributedType, Type>(m, "AttributedType")
    .def("__hash__", [](const AttributedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &AttributedType::Desugar)
    .def_prop_ro("attribute", &AttributedType::Attribute)
    .def_prop_ro("attribute_kind", &AttributedType::AttributeKind)
    .def_prop_ro("equivalent_type", &AttributedType::EquivalentType)
    .def_prop_ro("immediate_nullability", &AttributedType::ImmediateNullability)
    .def_prop_ro("modified_type", &AttributedType::ModifiedType)
    .def_prop_ro("has_attribute", &AttributedType::HasAttribute)
    .def_prop_ro("is_calling_conv", &AttributedType::IsCallingConv)
    .def_prop_ro("is_ms_type_spec", &AttributedType::IsMSTypeSpec)
    .def_prop_ro("is_qualifier", &AttributedType::IsQualifier)
    .def_prop_ro("is_sugared", &AttributedType::IsSugared);
}
} // namespace pasta
