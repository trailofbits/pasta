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

void RegisterOMPDeclareTargetDeclAttr(py::module_ &m) {
  py::class_<OMPDeclareTargetDeclAttr, InheritableAttr>(m, "OMPDeclareTargetDeclAttr")
    .def("__hash__", [](const OMPDeclareTargetDeclAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OMPDeclareTargetDeclAttr& a, const OMPDeclareTargetDeclAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("dev_type", &OMPDeclareTargetDeclAttr::DevType)
    .def_property_readonly("indirect", &OMPDeclareTargetDeclAttr::Indirect)
    .def_property_readonly("indirect_expression", &OMPDeclareTargetDeclAttr::IndirectExpression)
    .def_property_readonly("level", &OMPDeclareTargetDeclAttr::Level)
    .def_property_readonly("map_type", &OMPDeclareTargetDeclAttr::MapType)
    .def_property_readonly("spelling", &OMPDeclareTargetDeclAttr::Spelling);
}
} // namespace pasta
