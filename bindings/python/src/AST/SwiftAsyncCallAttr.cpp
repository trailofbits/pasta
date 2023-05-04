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

void RegisterSwiftAsyncCallAttr(py::module_ &m) {
  py::class_<SwiftAsyncCallAttr, Attr, InheritableAttr>(m, "SwiftAsyncCallAttr")
    .def("__hash__", [](const SwiftAsyncCallAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SwiftAsyncCallAttr& a, const SwiftAsyncCallAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &SwiftAsyncCallAttr::Spelling);
}
} // namespace pasta