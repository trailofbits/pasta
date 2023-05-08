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

void RegisterPreferredNameAttr(py::module_ &m) {
  py::class_<PreferredNameAttr, InheritableAttr>(m, "PreferredNameAttr")
    .def("__hash__", [](const PreferredNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const PreferredNameAttr& a, const PreferredNameAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &PreferredNameAttr::Spelling)
    .def_property_readonly("typedef_type", &PreferredNameAttr::TypedefType)
    .def_property_readonly("typedef_type_token", &PreferredNameAttr::TypedefTypeToken);
}
} // namespace pasta
