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
  py::class_<AlignedAttr, InheritableAttr>(m, "AlignedAttr")
    .def("__hash__", [](const AlignedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlignedAttr& a, const AlignedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def("alignment", &AlignedAttr::Alignment)
    .def_property_readonly("alignment_expression", &AlignedAttr::AlignmentExpression)
    .def_property_readonly("alignment_type", &AlignedAttr::AlignmentType)
    .def_property_readonly("semantic_spelling", &AlignedAttr::SemanticSpelling)
    .def_property_readonly("spelling", &AlignedAttr::Spelling)
    .def_property_readonly("is_alignas", &AlignedAttr::IsAlignas)
    .def_property_readonly("is_alignment_dependent", &AlignedAttr::IsAlignmentDependent)
    .def_property_readonly("is_alignment_error_dependent", &AlignedAttr::IsAlignmentErrorDependent)
    .def_property_readonly("is_alignment_expression", &AlignedAttr::IsAlignmentExpression)
    .def_property_readonly("is_c11", &AlignedAttr::IsC11)
    .def_property_readonly("is_declspec", &AlignedAttr::IsDeclspec)
    .def_property_readonly("is_gnu", &AlignedAttr::IsGNU);
}
} // namespace pasta
