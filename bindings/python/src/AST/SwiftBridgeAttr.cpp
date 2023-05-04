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

void RegisterSwiftBridgeAttr(py::module_ &m) {
  py::class_<SwiftBridgeAttr, Attr, InheritableAttr>(m, "SwiftBridgeAttr")
    .def_property_readonly("Spelling", &SwiftBridgeAttr::Spelling)
    .def_property_readonly("SwiftType", &SwiftBridgeAttr::SwiftType)
    .def_property_readonly("SwiftTypeLength", &SwiftBridgeAttr::SwiftTypeLength);
}
} // namespace pasta
