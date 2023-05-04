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

void RegisterTargetAttr(py::module_ &m) {
  py::class_<TargetAttr, Attr, InheritableAttr>(m, "TargetAttr")
    .def("__hash__", [](const TargetAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const TargetAttr& a, const TargetAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Architecture", &TargetAttr::Architecture)
    .def_property_readonly("FeaturesString", &TargetAttr::FeaturesString)
    .def_property_readonly("FeaturesStringLength", &TargetAttr::FeaturesStringLength)
    .def_property_readonly("Spelling", &TargetAttr::Spelling)
    .def_property_readonly("IsDefaultVersion", &TargetAttr::IsDefaultVersion);
}
} // namespace pasta
