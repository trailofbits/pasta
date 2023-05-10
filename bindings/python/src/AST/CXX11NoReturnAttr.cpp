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

void RegisterCXX11NoReturnAttr(py::module_ &m) {
  py::class_<CXX11NoReturnAttr, InheritableAttr>(m, "CXX11NoReturnAttr")
    .def("__hash__", [](const CXX11NoReturnAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CXX11NoReturnAttr& a, const CXX11NoReturnAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("semantic_spelling", &CXX11NoReturnAttr::SemanticSpelling)
    .def_property_readonly("spelling", &CXX11NoReturnAttr::Spelling);
}
} // namespace pasta
