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

void RegisterLockReturnedAttr(py::module_ &m) {
  py::class_<LockReturnedAttr, InheritableAttr>(m, "LockReturnedAttr")
    .def("__hash__", [](const LockReturnedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("argument", &LockReturnedAttr::Argument)
    .def_property_readonly("spelling", &LockReturnedAttr::Spelling);
}
} // namespace pasta
