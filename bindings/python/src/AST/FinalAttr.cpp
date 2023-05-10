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

void RegisterFinalAttr(py::module_ &m) {
  py::class_<FinalAttr, InheritableAttr>(m, "FinalAttr")
    .def("__hash__", [](const FinalAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const FinalAttr& a, const FinalAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &FinalAttr::SemanticSpelling)
    .def_property_readonly("spelling", &FinalAttr::Spelling)
    .def_property_readonly("is_spelled_as_sealed", &FinalAttr::IsSpelledAsSealed);
}
} // namespace pasta
