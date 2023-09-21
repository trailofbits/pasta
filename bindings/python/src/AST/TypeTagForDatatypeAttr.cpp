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

void RegisterTypeTagForDatatypeAttr(nb::module_ &m) {
  nb::class_<TypeTagForDatatypeAttr, InheritableAttr>(m, "TypeTagForDatatypeAttr")
    .def("__hash__", [](const TypeTagForDatatypeAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("layout_compatible", &TypeTagForDatatypeAttr::LayoutCompatible)
    .def_prop_ro("matching_c_type", &TypeTagForDatatypeAttr::MatchingCType)
    .def_prop_ro("matching_c_type_token", &TypeTagForDatatypeAttr::MatchingCTypeToken)
    .def_prop_ro("must_be_null", &TypeTagForDatatypeAttr::MustBeNull)
    .def_prop_ro("spelling", &TypeTagForDatatypeAttr::Spelling);
}
} // namespace pasta
