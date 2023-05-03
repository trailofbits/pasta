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

void RegisterTLSModelAttr(py::module_ &m) {
  py::class_<TLSModelAttr, Attr, InheritableAttr>(m, "TLSModelAttr")
    .def_property_readonly("Model", &TLSModelAttr::Model)
    .def_property_readonly("ModelLength", &TLSModelAttr::ModelLength)
    .def_property_readonly("Spelling", &TLSModelAttr::Spelling);
}
} // namespace ogler
