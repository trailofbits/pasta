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

void RegisterAttributedType(py::module_ &m) {
  py::class_<AttributedType, Type>(m, "AttributedType")
    .def("__hash__", [](const AttributedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const AttributedType& a, const AttributedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &AttributedType::Desugar)
    .def_property_readonly("AttributeKind", &AttributedType::AttributeKind)
    .def_property_readonly("EquivalentType", &AttributedType::EquivalentType)
    .def_property_readonly("ImmediateNullability", &AttributedType::ImmediateNullability)
    .def_property_readonly("ModifiedType", &AttributedType::ModifiedType)
    .def_property_readonly("IsCallingConv", &AttributedType::IsCallingConv)
    .def_property_readonly("IsMSTypeSpec", &AttributedType::IsMSTypeSpec)
    .def_property_readonly("IsQualifier", &AttributedType::IsQualifier)
    .def_property_readonly("IsSugared", &AttributedType::IsSugared);
}
} // namespace pasta
