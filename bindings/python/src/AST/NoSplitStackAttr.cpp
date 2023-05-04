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

void RegisterNoSplitStackAttr(py::module_ &m) {
  py::class_<NoSplitStackAttr, Attr, InheritableAttr>(m, "NoSplitStackAttr")
    .def("__hash__", [](const NoSplitStackAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NoSplitStackAttr& a, const NoSplitStackAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &NoSplitStackAttr::Spelling);
}
} // namespace pasta
