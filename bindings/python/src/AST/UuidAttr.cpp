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

void RegisterUuidAttr(py::module_ &m) {
  py::class_<UuidAttr, Attr, InheritableAttr>(m, "UuidAttr")
    .def_property_readonly("Guid", &UuidAttr::Guid)
    .def_property_readonly("GuidDeclaration", &UuidAttr::GuidDeclaration)
    .def_property_readonly("GuidLength", &UuidAttr::GuidLength)
    .def_property_readonly("Spelling", &UuidAttr::Spelling);
}
} // namespace ogler
