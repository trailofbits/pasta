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

void RegisterSwiftAsyncNameAttr(py::module_ &m) {
  py::class_<SwiftAsyncNameAttr, InheritableAttr>(m, "SwiftAsyncNameAttr")
    .def("__hash__", [](const SwiftAsyncNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SwiftAsyncNameAttr& a, const SwiftAsyncNameAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("name", &SwiftAsyncNameAttr::Name)
    .def_property_readonly("name_length", &SwiftAsyncNameAttr::NameLength)
    .def_property_readonly("spelling", &SwiftAsyncNameAttr::Spelling);
}
} // namespace pasta
