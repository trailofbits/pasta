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

void RegisterCallableWhenAttr(py::module_ &m) {
  py::class_<CallableWhenAttr, InheritableAttr>(m, "CallableWhenAttr")
    .def("__hash__", [](const CallableWhenAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CallableWhenAttr& a, const CallableWhenAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &CallableWhenAttr::Spelling);
}
} // namespace pasta
