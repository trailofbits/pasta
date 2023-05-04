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

void RegisterNoMips16Attr(py::module_ &m) {
  py::class_<NoMips16Attr, Attr, InheritableAttr>(m, "NoMips16Attr")
    .def("__hash__", [](const NoMips16Attr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NoMips16Attr& a, const NoMips16Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &NoMips16Attr::Spelling);
}
} // namespace pasta