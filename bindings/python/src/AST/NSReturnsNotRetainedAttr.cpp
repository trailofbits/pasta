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

void RegisterNSReturnsNotRetainedAttr(py::module_ &m) {
  py::class_<NSReturnsNotRetainedAttr, InheritableAttr>(m, "NSReturnsNotRetainedAttr")
    .def("__hash__", [](const NSReturnsNotRetainedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NSReturnsNotRetainedAttr& a, const NSReturnsNotRetainedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &NSReturnsNotRetainedAttr::Spelling);
}
} // namespace pasta
