/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterHLSLParamModifierAttr(nb::module_ &m) {
  nb::class_<HLSLParamModifierAttr, TypeAttr>(m, "HLSLParamModifierAttr")
    .def("__hash__", [](const HLSLParamModifierAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("merged_spelling", &HLSLParamModifierAttr::MergedSpelling)
    .def_prop_ro("semantic_spelling", &HLSLParamModifierAttr::SemanticSpelling)
    .def_prop_ro("spelling", &HLSLParamModifierAttr::Spelling)
    .def_prop_ro("is_any_in", &HLSLParamModifierAttr::IsAnyIn)
    .def_prop_ro("is_any_out", &HLSLParamModifierAttr::IsAnyOut)
    .def_prop_ro("is_in", &HLSLParamModifierAttr::IsIn)
    .def_prop_ro("is_in_out", &HLSLParamModifierAttr::IsInOut)
    .def_prop_ro("is_out", &HLSLParamModifierAttr::IsOut);
}
} // namespace pasta
