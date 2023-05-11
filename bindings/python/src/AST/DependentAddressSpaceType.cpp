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

void RegisterDependentAddressSpaceType(py::module_ &m) {
  py::class_<DependentAddressSpaceType, Type>(m, "DependentAddressSpaceType")
    .def("__hash__", [](const DependentAddressSpaceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentAddressSpaceType::Desugar)
    .def_property_readonly("address_space_expression", &DependentAddressSpaceType::AddressSpaceExpression)
    .def_property_readonly("attribute_token", &DependentAddressSpaceType::AttributeToken)
    .def_property_readonly("pointee_type", &DependentAddressSpaceType::PointeeType)
    .def_property_readonly("is_sugared", &DependentAddressSpaceType::IsSugared);
}
} // namespace pasta
