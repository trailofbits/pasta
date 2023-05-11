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

void RegisterSwiftBridgeAttr(py::module_ &m) {
  py::class_<SwiftBridgeAttr, InheritableAttr>(m, "SwiftBridgeAttr")
    .def("__hash__", [](const SwiftBridgeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &SwiftBridgeAttr::Spelling)
    .def_property_readonly("swift_type", &SwiftBridgeAttr::SwiftType)
    .def_property_readonly("swift_type_length", &SwiftBridgeAttr::SwiftTypeLength);
}
} // namespace pasta
