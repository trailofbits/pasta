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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterAttributedType(py::module_ &m) {
  py::class_<AttributedType, Type>(m, "AttributedType")
    .def("__hash__", [](const AttributedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &AttributedType::Desugar)
    .def_property_readonly("attribute_kind", &AttributedType::AttributeKind)
    .def_property_readonly("equivalent_type", &AttributedType::EquivalentType)
    .def_property_readonly("immediate_nullability", &AttributedType::ImmediateNullability)
    .def_property_readonly("modified_type", &AttributedType::ModifiedType)
    .def_property_readonly("is_calling_conv", &AttributedType::IsCallingConv)
    .def_property_readonly("is_ms_type_spec", &AttributedType::IsMSTypeSpec)
    .def_property_readonly("is_qualifier", &AttributedType::IsQualifier)
    .def_property_readonly("is_sugared", &AttributedType::IsSugared);
}
} // namespace pasta
