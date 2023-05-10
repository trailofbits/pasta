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

void RegisterConstInitAttr(py::module_ &m) {
  py::class_<ConstInitAttr, InheritableAttr>(m, "ConstInitAttr")
    .def("__hash__", [](const ConstInitAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ConstInitAttr& a, const ConstInitAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &ConstInitAttr::SemanticSpelling)
    .def_property_readonly("spelling", &ConstInitAttr::Spelling)
    .def_property_readonly("is_constinit", &ConstInitAttr::IsConstinit);
}
} // namespace pasta
