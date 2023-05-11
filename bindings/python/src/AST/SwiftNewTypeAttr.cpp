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

void RegisterSwiftNewTypeAttr(py::module_ &m) {
  py::class_<SwiftNewTypeAttr, InheritableAttr>(m, "SwiftNewTypeAttr")
    .def("__hash__", [](const SwiftNewTypeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("newtype_kind", &SwiftNewTypeAttr::NewtypeKind)
    .def_property_readonly("semantic_spelling", &SwiftNewTypeAttr::SemanticSpelling)
    .def_property_readonly("spelling", &SwiftNewTypeAttr::Spelling);
}
} // namespace pasta
