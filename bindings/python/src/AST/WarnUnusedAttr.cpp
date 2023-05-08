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

void RegisterWarnUnusedAttr(py::module_ &m) {
  py::class_<WarnUnusedAttr, InheritableAttr>(m, "WarnUnusedAttr")
    .def("__hash__", [](const WarnUnusedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WarnUnusedAttr& a, const WarnUnusedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &WarnUnusedAttr::Spelling);
}
} // namespace pasta
