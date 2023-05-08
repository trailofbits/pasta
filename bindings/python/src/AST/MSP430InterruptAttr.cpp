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

void RegisterMSP430InterruptAttr(py::module_ &m) {
  py::class_<MSP430InterruptAttr, InheritableAttr>(m, "MSP430InterruptAttr")
    .def("__hash__", [](const MSP430InterruptAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MSP430InterruptAttr& a, const MSP430InterruptAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Number", &MSP430InterruptAttr::Number)
    .def_property_readonly("Spelling", &MSP430InterruptAttr::Spelling);
}
} // namespace pasta
