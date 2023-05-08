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

void RegisterAlwaysDestroyAttr(py::module_ &m) {
  py::class_<AlwaysDestroyAttr, InheritableAttr>(m, "AlwaysDestroyAttr")
    .def("__hash__", [](const AlwaysDestroyAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlwaysDestroyAttr& a, const AlwaysDestroyAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &AlwaysDestroyAttr::Spelling);
}
} // namespace pasta
