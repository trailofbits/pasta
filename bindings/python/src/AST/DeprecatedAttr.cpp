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

void RegisterDeprecatedAttr(py::module_ &m) {
  py::class_<DeprecatedAttr, Attr, InheritableAttr>(m, "DeprecatedAttr")
    .def_property_readonly("Message", &DeprecatedAttr::Message)
    .def_property_readonly("MessageLength", &DeprecatedAttr::MessageLength)
    .def_property_readonly("Replacement", &DeprecatedAttr::Replacement)
    .def_property_readonly("ReplacementLength", &DeprecatedAttr::ReplacementLength)
    .def_property_readonly("Spelling", &DeprecatedAttr::Spelling);
}
} // namespace pasta
