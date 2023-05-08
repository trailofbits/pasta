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

void RegisterSwiftErrorAttr(py::module_ &m) {
  py::class_<SwiftErrorAttr, InheritableAttr>(m, "SwiftErrorAttr")
    .def("__hash__", [](const SwiftErrorAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SwiftErrorAttr& a, const SwiftErrorAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Convention", &SwiftErrorAttr::Convention)
    .def_property_readonly("Spelling", &SwiftErrorAttr::Spelling);
}
} // namespace pasta
