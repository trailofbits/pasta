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

void RegisterMipsShortCallAttr(py::module_ &m) {
  py::class_<MipsShortCallAttr, InheritableAttr>(m, "MipsShortCallAttr")
    .def("__hash__", [](const MipsShortCallAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MipsShortCallAttr& a, const MipsShortCallAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &MipsShortCallAttr::SemanticSpelling)
    .def_property_readonly("spelling", &MipsShortCallAttr::Spelling);
}
} // namespace pasta
