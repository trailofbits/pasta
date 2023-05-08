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

void RegisterPragmaClangRodataSectionAttr(py::module_ &m) {
  py::class_<PragmaClangRodataSectionAttr, InheritableAttr>(m, "PragmaClangRodataSectionAttr")
    .def("__hash__", [](const PragmaClangRodataSectionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PragmaClangRodataSectionAttr& a, const PragmaClangRodataSectionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Name", &PragmaClangRodataSectionAttr::Name)
    .def_property_readonly("NameLength", &PragmaClangRodataSectionAttr::NameLength)
    .def_property_readonly("Spelling", &PragmaClangRodataSectionAttr::Spelling);
}
} // namespace pasta
