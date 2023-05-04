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

void RegisterMaxFieldAlignmentAttr(py::module_ &m) {
  py::class_<MaxFieldAlignmentAttr, Attr, InheritableAttr>(m, "MaxFieldAlignmentAttr")
    .def("__hash__", [](const MaxFieldAlignmentAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MaxFieldAlignmentAttr& a, const MaxFieldAlignmentAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Alignment", &MaxFieldAlignmentAttr::Alignment)
    .def_property_readonly("Spelling", &MaxFieldAlignmentAttr::Spelling);
}
} // namespace pasta