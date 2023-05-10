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

void RegisterAlwaysInlineAttr(py::module_ &m) {
  py::class_<AlwaysInlineAttr, DeclOrStmtAttr>(m, "AlwaysInlineAttr")
    .def("__hash__", [](const AlwaysInlineAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlwaysInlineAttr& a, const AlwaysInlineAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &AlwaysInlineAttr::SemanticSpelling)
    .def_property_readonly("spelling", &AlwaysInlineAttr::Spelling)
    .def_property_readonly("is_clang_always_inline", &AlwaysInlineAttr::IsClangAlwaysInline);
}
} // namespace pasta
