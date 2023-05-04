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

void RegisterMSInheritanceAttr(py::module_ &m) {
  py::class_<MSInheritanceAttr, Attr, InheritableAttr>(m, "MSInheritanceAttr")
    .def("__hash__", [](const MSInheritanceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MSInheritanceAttr& a, const MSInheritanceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("BestCase", &MSInheritanceAttr::BestCase)
    .def_property_readonly("InheritanceModel", &MSInheritanceAttr::InheritanceModel)
    .def_property_readonly("SemanticSpelling", &MSInheritanceAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &MSInheritanceAttr::Spelling);
}
} // namespace pasta
