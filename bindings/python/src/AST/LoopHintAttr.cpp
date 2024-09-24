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

void RegisterLoopHintAttr(nb::module_ &m) {
  nb::class_<LoopHintAttr, Attr>(m, "LoopHintAttr")
    .def("__hash__", [](const LoopHintAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("option", &LoopHintAttr::Option)
    .def_prop_ro("semantic_spelling", &LoopHintAttr::SemanticSpelling)
    .def_prop_ro("spelling", &LoopHintAttr::Spelling)
    .def_prop_ro("state", &LoopHintAttr::State)
    .def_prop_ro("value", &LoopHintAttr::Value);
}
} // namespace pasta
