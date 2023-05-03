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

void RegisterBTFDeclTagAttr(py::module_ &m) {
  py::class_<BTFDeclTagAttr, Attr, InheritableAttr>(m, "BTFDeclTagAttr")
    .def_property_readonly("BTFDeclTag", &BTFDeclTagAttr::BTFDeclTag)
    .def_property_readonly("BTFDeclTagLength", &BTFDeclTagAttr::BTFDeclTagLength)
    .def_property_readonly("Spelling", &BTFDeclTagAttr::Spelling);
}
} // namespace ogler
