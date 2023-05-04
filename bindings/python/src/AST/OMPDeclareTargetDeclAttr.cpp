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

void RegisterOMPDeclareTargetDeclAttr(py::module_ &m) {
  py::class_<OMPDeclareTargetDeclAttr, Attr, InheritableAttr>(m, "OMPDeclareTargetDeclAttr")
    .def_property_readonly("DevType", &OMPDeclareTargetDeclAttr::DevType)
    .def_property_readonly("Indirect", &OMPDeclareTargetDeclAttr::Indirect)
    .def_property_readonly("IndirectExpression", &OMPDeclareTargetDeclAttr::IndirectExpression)
    .def_property_readonly("Level", &OMPDeclareTargetDeclAttr::Level)
    .def_property_readonly("MapType", &OMPDeclareTargetDeclAttr::MapType)
    .def_property_readonly("Spelling", &OMPDeclareTargetDeclAttr::Spelling);
}
} // namespace pasta
