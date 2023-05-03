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

void RegisterOwnershipAttr(py::module_ &m) {
  py::class_<OwnershipAttr, Attr, InheritableAttr>(m, "OwnershipAttr")
    .def_property_readonly("OwnKind", &OwnershipAttr::OwnKind)
    .def_property_readonly("SemanticSpelling", &OwnershipAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &OwnershipAttr::Spelling)
    .def_property_readonly("IsHolds", &OwnershipAttr::IsHolds)
    .def_property_readonly("IsReturns", &OwnershipAttr::IsReturns)
    .def_property_readonly("IsTakes", &OwnershipAttr::IsTakes);
}
} // namespace ogler
