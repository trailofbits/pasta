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

void RegisterThisCallAttr(py::module_ &m) {
  py::class_<ThisCallAttr, Attr, InheritableAttr>(m, "ThisCallAttr")
    .def("__hash__", [](const ThisCallAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ThisCallAttr& a, const ThisCallAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ThisCallAttr::Spelling);
}
} // namespace pasta