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

void RegisterSwiftNameAttr(py::module_ &m) {
  py::class_<SwiftNameAttr, Attr, InheritableAttr>(m, "SwiftNameAttr")
    .def_property_readonly("Name", &SwiftNameAttr::Name)
    .def_property_readonly("NameLength", &SwiftNameAttr::NameLength)
    .def_property_readonly("Spelling", &SwiftNameAttr::Spelling);
}
} // namespace pasta
