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

void RegisterPointerAttr(py::module_ &m) {
  py::class_<PointerAttr, Attr, InheritableAttr>(m, "PointerAttr")
    .def("__hash__", [](const PointerAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PointerAttr& a, const PointerAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("DerefType", &PointerAttr::DerefType)
    .def_property_readonly("DerefTypeToken", &PointerAttr::DerefTypeToken)
    .def_property_readonly("Spelling", &PointerAttr::Spelling);
}
} // namespace pasta
