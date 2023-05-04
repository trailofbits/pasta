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

void RegisterOverrideAttr(py::module_ &m) {
  py::class_<OverrideAttr, Attr, InheritableAttr>(m, "OverrideAttr")
    .def("__hash__", [](const OverrideAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OverrideAttr& a, const OverrideAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &OverrideAttr::Spelling);
}
} // namespace pasta