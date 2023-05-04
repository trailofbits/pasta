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

void RegisterReturnsNonNullAttr(py::module_ &m) {
  py::class_<ReturnsNonNullAttr, Attr, InheritableAttr>(m, "ReturnsNonNullAttr")
    .def("__hash__", [](const ReturnsNonNullAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ReturnsNonNullAttr& a, const ReturnsNonNullAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ReturnsNonNullAttr::Spelling);
}
} // namespace pasta