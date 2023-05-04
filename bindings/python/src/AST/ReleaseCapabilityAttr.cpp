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

void RegisterReleaseCapabilityAttr(py::module_ &m) {
  py::class_<ReleaseCapabilityAttr, Attr, InheritableAttr>(m, "ReleaseCapabilityAttr")
    .def("__hash__", [](const ReleaseCapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ReleaseCapabilityAttr& a, const ReleaseCapabilityAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &ReleaseCapabilityAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &ReleaseCapabilityAttr::Spelling)
    .def_property_readonly("IsGeneric", &ReleaseCapabilityAttr::IsGeneric)
    .def_property_readonly("IsShared", &ReleaseCapabilityAttr::IsShared);
}
} // namespace pasta
