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

void RegisterDeprecatedAttr(py::module_ &m) {
  py::class_<DeprecatedAttr, InheritableAttr>(m, "DeprecatedAttr")
    .def("__hash__", [](const DeprecatedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("message", &DeprecatedAttr::Message)
    .def_property_readonly("message_length", &DeprecatedAttr::MessageLength)
    .def_property_readonly("replacement", &DeprecatedAttr::Replacement)
    .def_property_readonly("replacement_length", &DeprecatedAttr::ReplacementLength)
    .def_property_readonly("spelling", &DeprecatedAttr::Spelling);
}
} // namespace pasta
