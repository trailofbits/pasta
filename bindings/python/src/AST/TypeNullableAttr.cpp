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

void RegisterTypeNullableAttr(py::module_ &m) {
  py::class_<TypeNullableAttr, TypeAttr>(m, "TypeNullableAttr")
    .def("__hash__", [](const TypeNullableAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TypeNullableAttr& a, const TypeNullableAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &TypeNullableAttr::Spelling);
}
} // namespace pasta
