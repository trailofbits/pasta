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

void RegisterRestrictAttr(py::module_ &m) {
  py::class_<RestrictAttr, InheritableAttr>(m, "RestrictAttr")
    .def("__hash__", [](const RestrictAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &RestrictAttr::SemanticSpelling)
    .def_property_readonly("spelling", &RestrictAttr::Spelling);
}
} // namespace pasta
