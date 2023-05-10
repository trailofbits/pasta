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

void RegisterNoStackProtectorAttr(py::module_ &m) {
  py::class_<NoStackProtectorAttr, InheritableAttr>(m, "NoStackProtectorAttr")
    .def("__hash__", [](const NoStackProtectorAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NoStackProtectorAttr& a, const NoStackProtectorAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &NoStackProtectorAttr::SemanticSpelling)
    .def_property_readonly("spelling", &NoStackProtectorAttr::Spelling);
}
} // namespace pasta
