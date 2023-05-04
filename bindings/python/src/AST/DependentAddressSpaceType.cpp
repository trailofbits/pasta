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

void RegisterDependentAddressSpaceType(py::module_ &m) {
  py::class_<DependentAddressSpaceType, Type>(m, "DependentAddressSpaceType")
    .def("__hash__", [](const DependentAddressSpaceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentAddressSpaceType& a, const DependentAddressSpaceType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &DependentAddressSpaceType::Desugar)
    .def_property_readonly("AddressSpaceExpression", &DependentAddressSpaceType::AddressSpaceExpression)
    .def_property_readonly("AttributeToken", &DependentAddressSpaceType::AttributeToken)
    .def_property_readonly("PointeeType", &DependentAddressSpaceType::PointeeType)
    .def_property_readonly("IsSugared", &DependentAddressSpaceType::IsSugared);
}
} // namespace pasta
