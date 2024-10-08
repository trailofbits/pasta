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

void RegisterArgumentWithTypeTagAttr(nb::module_ &m) {
  nb::class_<ArgumentWithTypeTagAttr, InheritableAttr>(m, "ArgumentWithTypeTagAttr")
    .def("__hash__", [](const ArgumentWithTypeTagAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("is_pointer", &ArgumentWithTypeTagAttr::IsPointer)
    .def_prop_ro("semantic_spelling", &ArgumentWithTypeTagAttr::SemanticSpelling)
    .def_prop_ro("spelling", &ArgumentWithTypeTagAttr::Spelling);
}
} // namespace pasta
