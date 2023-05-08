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

void RegisterArgumentWithTypeTagAttr(py::module_ &m) {
  py::class_<ArgumentWithTypeTagAttr, InheritableAttr>(m, "ArgumentWithTypeTagAttr")
    .def("__hash__", [](const ArgumentWithTypeTagAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ArgumentWithTypeTagAttr& a, const ArgumentWithTypeTagAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("is_pointer", &ArgumentWithTypeTagAttr::IsPointer)
    .def_property_readonly("semantic_spelling", &ArgumentWithTypeTagAttr::SemanticSpelling)
    .def_property_readonly("spelling", &ArgumentWithTypeTagAttr::Spelling);
}
} // namespace pasta
