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

void RegisterM68kInterruptAttr(py::module_ &m) {
  py::class_<M68kInterruptAttr, Attr, InheritableAttr>(m, "M68kInterruptAttr")
    .def("__hash__", [](const M68kInterruptAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const M68kInterruptAttr& a, const M68kInterruptAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Number", &M68kInterruptAttr::Number)
    .def_property_readonly("Spelling", &M68kInterruptAttr::Spelling);
}
} // namespace pasta
