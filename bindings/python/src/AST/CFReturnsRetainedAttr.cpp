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

void RegisterCFReturnsRetainedAttr(py::module_ &m) {
  py::class_<CFReturnsRetainedAttr, InheritableAttr>(m, "CFReturnsRetainedAttr")
    .def("__hash__", [](const CFReturnsRetainedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CFReturnsRetainedAttr& a, const CFReturnsRetainedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &CFReturnsRetainedAttr::Spelling);
}
} // namespace pasta
