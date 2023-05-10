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

void RegisterOSReturnsNotRetainedAttr(py::module_ &m) {
  py::class_<OSReturnsNotRetainedAttr, InheritableAttr>(m, "OSReturnsNotRetainedAttr")
    .def("__hash__", [](const OSReturnsNotRetainedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OSReturnsNotRetainedAttr& a, const OSReturnsNotRetainedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &OSReturnsNotRetainedAttr::Spelling);
}
} // namespace pasta
