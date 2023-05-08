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

void RegisterPtGuardedByAttr(py::module_ &m) {
  py::class_<PtGuardedByAttr, InheritableAttr>(m, "PtGuardedByAttr")
    .def("__hash__", [](const PtGuardedByAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PtGuardedByAttr& a, const PtGuardedByAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("argument", &PtGuardedByAttr::Argument)
    .def_property_readonly("spelling", &PtGuardedByAttr::Spelling);
}
} // namespace pasta
