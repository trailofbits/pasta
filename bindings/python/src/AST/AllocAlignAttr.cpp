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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterAllocAlignAttr(py::module_ &m) {
  py::class_<AllocAlignAttr, InheritableAttr>(m, "AllocAlignAttr")
    .def("__hash__", [](const AllocAlignAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AllocAlignAttr& a, const AllocAlignAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &AllocAlignAttr::Spelling);
}
} // namespace pasta
