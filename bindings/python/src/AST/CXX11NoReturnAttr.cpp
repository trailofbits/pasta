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

void RegisterCXX11NoReturnAttr(py::module_ &m) {
  py::class_<CXX11NoReturnAttr, Attr, InheritableAttr>(m, "CXX11NoReturnAttr")
    .def_property_readonly("SemanticSpelling", &CXX11NoReturnAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &CXX11NoReturnAttr::Spelling);
}
} // namespace pasta
