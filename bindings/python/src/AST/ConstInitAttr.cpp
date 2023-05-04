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

void RegisterConstInitAttr(py::module_ &m) {
  py::class_<ConstInitAttr, Attr, InheritableAttr>(m, "ConstInitAttr")
    .def("__hash__", [](const ConstInitAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ConstInitAttr& a, const ConstInitAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &ConstInitAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &ConstInitAttr::Spelling)
    .def_property_readonly("IsConstinit", &ConstInitAttr::IsConstinit);
}
} // namespace pasta