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

void RegisterCapabilityAttr(py::module_ &m) {
  py::class_<CapabilityAttr, Attr, InheritableAttr>(m, "CapabilityAttr")
    .def_property_readonly("Name", &CapabilityAttr::Name)
    .def_property_readonly("NameLength", &CapabilityAttr::NameLength)
    .def_property_readonly("SemanticSpelling", &CapabilityAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &CapabilityAttr::Spelling)
    .def_property_readonly("IsShared", &CapabilityAttr::IsShared);
}
} // namespace pasta
