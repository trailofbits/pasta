/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterMipsShortCallAttr(nb::module_ &m) {
  nb::class_<MipsShortCallAttr, InheritableAttr>(m, "MipsShortCallAttr")
    .def("__hash__", [](const MipsShortCallAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &MipsShortCallAttr::SemanticSpelling)
    .def_prop_ro("spelling", &MipsShortCallAttr::Spelling);
}
} // namespace pasta
