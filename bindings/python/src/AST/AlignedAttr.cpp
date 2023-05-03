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

void RegisterAlignedAttr(py::module_ &m) {
  py::class_<AlignedAttr, Attr, InheritableAttr>(m, "AlignedAttr")
    .def("Alignment", &AlignedAttr::Alignment)
    .def_property_readonly("AlignmentExpression", &AlignedAttr::AlignmentExpression)
    .def_property_readonly("AlignmentType", &AlignedAttr::AlignmentType)
    .def_property_readonly("SemanticSpelling", &AlignedAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &AlignedAttr::Spelling)
    .def_property_readonly("IsAlignas", &AlignedAttr::IsAlignas)
    .def_property_readonly("IsAlignmentDependent", &AlignedAttr::IsAlignmentDependent)
    .def_property_readonly("IsAlignmentErrorDependent", &AlignedAttr::IsAlignmentErrorDependent)
    .def_property_readonly("IsAlignmentExpression", &AlignedAttr::IsAlignmentExpression)
    .def_property_readonly("IsC11", &AlignedAttr::IsC11)
    .def_property_readonly("IsDeclspec", &AlignedAttr::IsDeclspec)
    .def_property_readonly("IsGNU", &AlignedAttr::IsGNU);
}
} // namespace ogler
