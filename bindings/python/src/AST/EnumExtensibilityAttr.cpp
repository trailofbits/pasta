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

void RegisterEnumExtensibilityAttr(py::module_ &m) {
  py::class_<EnumExtensibilityAttr, InheritableAttr>(m, "EnumExtensibilityAttr")
    .def("__hash__", [](const EnumExtensibilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("extensibility", &EnumExtensibilityAttr::Extensibility)
    .def_property_readonly("spelling", &EnumExtensibilityAttr::Spelling);
}
} // namespace pasta
