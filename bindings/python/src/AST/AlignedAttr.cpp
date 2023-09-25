/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterAlignedAttr(nb::module_ &m) {
  nb::class_<AlignedAttr, InheritableAttr>(m, "AlignedAttr")
    .def("__hash__", [](const AlignedAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("alignment", &AlignedAttr::Alignment)
    .def_prop_ro("alignment_expression", &AlignedAttr::AlignmentExpression)
    .def_prop_ro("alignment_type", &AlignedAttr::AlignmentType)
    .def_prop_ro("cached_alignment_value", &AlignedAttr::CachedAlignmentValue)
    .def_prop_ro("semantic_spelling", &AlignedAttr::SemanticSpelling)
    .def_prop_ro("spelling", &AlignedAttr::Spelling)
    .def_prop_ro("is_alignas", &AlignedAttr::IsAlignas)
    .def_prop_ro("is_alignment_dependent", &AlignedAttr::IsAlignmentDependent)
    .def_prop_ro("is_alignment_error_dependent", &AlignedAttr::IsAlignmentErrorDependent)
    .def_prop_ro("is_alignment_expression", &AlignedAttr::IsAlignmentExpression)
    .def_prop_ro("is_c11", &AlignedAttr::IsC11)
    .def_prop_ro("is_declspec", &AlignedAttr::IsDeclspec)
    .def_prop_ro("is_gnu", &AlignedAttr::IsGNU);
}
} // namespace pasta
