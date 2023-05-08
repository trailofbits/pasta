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

void RegisterTargetVersionAttr(py::module_ &m) {
  py::class_<TargetVersionAttr, InheritableAttr>(m, "TargetVersionAttr")
    .def("__hash__", [](const TargetVersionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TargetVersionAttr& a, const TargetVersionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("name", &TargetVersionAttr::Name)
    .def_property_readonly("names_string", &TargetVersionAttr::NamesString)
    .def_property_readonly("names_string_length", &TargetVersionAttr::NamesStringLength)
    .def_property_readonly("spelling", &TargetVersionAttr::Spelling)
    .def_property_readonly("is_default_version", &TargetVersionAttr::IsDefaultVersion);
}
} // namespace pasta
