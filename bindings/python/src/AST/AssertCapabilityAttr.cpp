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

void RegisterAssertCapabilityAttr(py::module_ &m) {
  py::class_<AssertCapabilityAttr, Attr, InheritableAttr>(m, "AssertCapabilityAttr")
    .def("__hash__", [](const AssertCapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AssertCapabilityAttr& a, const AssertCapabilityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &AssertCapabilityAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &AssertCapabilityAttr::Spelling)
    .def_property_readonly("IsShared", &AssertCapabilityAttr::IsShared);
}
} // namespace pasta
