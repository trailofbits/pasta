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

void RegisterOwnerAttr(py::module_ &m) {
  py::class_<OwnerAttr, Attr, InheritableAttr>(m, "OwnerAttr")
    .def_property_readonly("DerefType", &OwnerAttr::DerefType)
    .def_property_readonly("DerefTypeToken", &OwnerAttr::DerefTypeToken)
    .def_property_readonly("Spelling", &OwnerAttr::Spelling);
}
} // namespace ogler
