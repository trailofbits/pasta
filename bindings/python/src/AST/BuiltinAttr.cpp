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

void RegisterBuiltinAttr(py::module_ &m) {
  py::class_<BuiltinAttr, Attr, InheritableAttr>(m, "BuiltinAttr")
    .def("__hash__", [](const BuiltinAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const BuiltinAttr& a, const BuiltinAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("ID", &BuiltinAttr::ID)
    .def_property_readonly("Spelling", &BuiltinAttr::Spelling);
}
} // namespace pasta
