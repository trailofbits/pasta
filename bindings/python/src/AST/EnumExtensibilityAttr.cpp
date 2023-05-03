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

void RegisterEnumExtensibilityAttr(py::module_ &m) {
  py::class_<EnumExtensibilityAttr, Attr, InheritableAttr>(m, "EnumExtensibilityAttr")
    .def_property_readonly("Extensibility", &EnumExtensibilityAttr::Extensibility)
    .def_property_readonly("Spelling", &EnumExtensibilityAttr::Spelling);
}
} // namespace ogler
