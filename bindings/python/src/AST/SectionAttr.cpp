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
  py::class_<SectionAttr, InheritableAttr>(m, "SectionAttr")
    .def("__hash__", [](const SectionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SectionAttr& a, const SectionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("name", &SectionAttr::Name)
    .def_property_readonly("name_length", &SectionAttr::NameLength)
    .def_property_readonly("semantic_spelling", &SectionAttr::SemanticSpelling)
    .def_property_readonly("spelling", &SectionAttr::Spelling);
}
} // namespace pasta
