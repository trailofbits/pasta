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

void RegisterPragmaClangBSSSectionAttr(py::module_ &m) {
  py::class_<PragmaClangBSSSectionAttr, Attr, InheritableAttr>(m, "PragmaClangBSSSectionAttr")
    .def("__hash__", [](const PragmaClangBSSSectionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PragmaClangBSSSectionAttr& a, const PragmaClangBSSSectionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Name", &PragmaClangBSSSectionAttr::Name)
    .def_property_readonly("NameLength", &PragmaClangBSSSectionAttr::NameLength)
    .def_property_readonly("Spelling", &PragmaClangBSSSectionAttr::Spelling);
}
} // namespace pasta
