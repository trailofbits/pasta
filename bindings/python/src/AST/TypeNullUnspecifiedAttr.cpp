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

void RegisterTypeNullUnspecifiedAttr(py::module_ &m) {
  py::class_<TypeNullUnspecifiedAttr, Attr, TypeAttr>(m, "TypeNullUnspecifiedAttr")
    .def("__hash__", [](const TypeNullUnspecifiedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TypeNullUnspecifiedAttr& a, const TypeNullUnspecifiedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &TypeNullUnspecifiedAttr::Spelling);
}
} // namespace pasta