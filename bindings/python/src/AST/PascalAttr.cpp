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

void RegisterPascalAttr(py::module_ &m) {
  py::class_<PascalAttr, InheritableAttr>(m, "PascalAttr")
    .def("__hash__", [](const PascalAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PascalAttr& a, const PascalAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &PascalAttr::Spelling);
}
} // namespace pasta
