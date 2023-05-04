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

void RegisterSwiftAsyncContextAttr(py::module_ &m) {
  py::class_<SwiftAsyncContextAttr, Attr, InheritableAttr, InheritableParamAttr, ParameterABIAttr>(m, "SwiftAsyncContextAttr")
    .def("__hash__", [](const SwiftAsyncContextAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SwiftAsyncContextAttr& a, const SwiftAsyncContextAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &SwiftAsyncContextAttr::Spelling);
}
} // namespace pasta