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

void RegisterPragmaClangTextSectionAttr(py::module_ &m) {
  py::class_<PragmaClangTextSectionAttr, InheritableAttr>(m, "PragmaClangTextSectionAttr")
    .def("__hash__", [](const PragmaClangTextSectionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PragmaClangTextSectionAttr& a, const PragmaClangTextSectionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("name", &PragmaClangTextSectionAttr::Name)
    .def_property_readonly("name_length", &PragmaClangTextSectionAttr::NameLength)
    .def_property_readonly("spelling", &PragmaClangTextSectionAttr::Spelling);
}
} // namespace pasta
