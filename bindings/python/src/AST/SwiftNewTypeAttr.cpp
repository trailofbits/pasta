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

void RegisterSwiftNewTypeAttr(nb::module_ &m) {
  nb::class_<SwiftNewTypeAttr, InheritableAttr>(m, "SwiftNewTypeAttr")
    .def("__hash__", [](const SwiftNewTypeAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("newtype_kind", &SwiftNewTypeAttr::NewtypeKind)
    .def_prop_ro("semantic_spelling", &SwiftNewTypeAttr::SemanticSpelling)
    .def_prop_ro("spelling", &SwiftNewTypeAttr::Spelling);
}
} // namespace pasta
