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

void RegisterSwiftNewTypeAttr(py::module_ &m) {
  py::class_<SwiftNewTypeAttr, Attr, InheritableAttr>(m, "SwiftNewTypeAttr")
    .def("__hash__", [](const SwiftNewTypeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SwiftNewTypeAttr& a, const SwiftNewTypeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("NewtypeKind", &SwiftNewTypeAttr::NewtypeKind)
    .def_property_readonly("SemanticSpelling", &SwiftNewTypeAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &SwiftNewTypeAttr::Spelling);
}
} // namespace pasta
