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

void RegisterTargetAttr(py::module_ &m) {
  py::class_<TargetAttr, InheritableAttr>(m, "TargetAttr")
    .def("__hash__", [](const TargetAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("architecture", &TargetAttr::Architecture)
    .def_property_readonly("features_string", &TargetAttr::FeaturesString)
    .def_property_readonly("features_string_length", &TargetAttr::FeaturesStringLength)
    .def_property_readonly("spelling", &TargetAttr::Spelling)
    .def_property_readonly("is_default_version", &TargetAttr::IsDefaultVersion);
}
} // namespace pasta
