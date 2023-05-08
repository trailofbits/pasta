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

void RegisterMipsLongCallAttr(py::module_ &m) {
  py::class_<MipsLongCallAttr, InheritableAttr>(m, "MipsLongCallAttr")
    .def("__hash__", [](const MipsLongCallAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MipsLongCallAttr& a, const MipsLongCallAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &MipsLongCallAttr::SemanticSpelling)
    .def_property_readonly("spelling", &MipsLongCallAttr::Spelling);
}
} // namespace pasta
