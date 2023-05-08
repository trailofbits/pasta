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

void RegisterUnusedAttr(py::module_ &m) {
  py::class_<UnusedAttr, InheritableAttr>(m, "UnusedAttr")
    .def("__hash__", [](const UnusedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const UnusedAttr& a, const UnusedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &UnusedAttr::SemanticSpelling)
    .def_property_readonly("spelling", &UnusedAttr::Spelling);
}
} // namespace pasta
