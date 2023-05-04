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

void RegisterSwiftErrorAttr(py::module_ &m) {
  py::class_<SwiftErrorAttr, Attr, InheritableAttr>(m, "SwiftErrorAttr")
    .def_property_readonly("Convention", &SwiftErrorAttr::Convention)
    .def_property_readonly("Spelling", &SwiftErrorAttr::Spelling);
}
} // namespace pasta
