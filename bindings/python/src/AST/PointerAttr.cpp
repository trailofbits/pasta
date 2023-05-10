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

void RegisterPointerAttr(py::module_ &m) {
  py::class_<PointerAttr, InheritableAttr>(m, "PointerAttr")
    .def("__hash__", [](const PointerAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PointerAttr& a, const PointerAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("deref_type", &PointerAttr::DerefType)
    .def_property_readonly("deref_type_token", &PointerAttr::DerefTypeToken)
    .def_property_readonly("spelling", &PointerAttr::Spelling);
}
} // namespace pasta
