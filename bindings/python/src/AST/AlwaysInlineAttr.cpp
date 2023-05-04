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

void RegisterAlwaysInlineAttr(py::module_ &m) {
  py::class_<AlwaysInlineAttr, Attr, DeclOrStmtAttr, InheritableAttr>(m, "AlwaysInlineAttr")
    .def("__hash__", [](const AlwaysInlineAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlwaysInlineAttr& a, const AlwaysInlineAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &AlwaysInlineAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &AlwaysInlineAttr::Spelling)
    .def_property_readonly("IsClangAlwaysInline", &AlwaysInlineAttr::IsClangAlwaysInline);
}
} // namespace pasta