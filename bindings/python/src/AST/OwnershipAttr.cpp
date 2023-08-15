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

void RegisterOwnershipAttr(nb::module_ &m) {
  nb::class_<OwnershipAttr, InheritableAttr>(m, "OwnershipAttr")
    .def("__hash__", [](const OwnershipAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("own_kind", &OwnershipAttr::OwnKind)
    .def_prop_ro("semantic_spelling", &OwnershipAttr::SemanticSpelling)
    .def_prop_ro("spelling", &OwnershipAttr::Spelling)
    .def_prop_ro("is_holds", &OwnershipAttr::IsHolds)
    .def_prop_ro("is_returns", &OwnershipAttr::IsReturns)
    .def_prop_ro("is_takes", &OwnershipAttr::IsTakes);
}
} // namespace pasta
