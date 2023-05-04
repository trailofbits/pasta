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

void RegisterSectionAttr(py::module_ &m) {
  py::class_<SectionAttr, Attr, InheritableAttr>(m, "SectionAttr")
    .def("__hash__", [](const SectionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SectionAttr& a, const SectionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Name", &SectionAttr::Name)
    .def_property_readonly("NameLength", &SectionAttr::NameLength)
    .def_property_readonly("SemanticSpelling", &SectionAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &SectionAttr::Spelling);
}
} // namespace pasta
