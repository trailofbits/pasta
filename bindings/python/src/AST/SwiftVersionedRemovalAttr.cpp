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

void RegisterSwiftVersionedRemovalAttr(nb::module_ &m) {
  nb::class_<SwiftVersionedRemovalAttr, Attr>(m, "SwiftVersionedRemovalAttr")
    .def("__hash__", [](const SwiftVersionedRemovalAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("attribute_kind_to_remove", &SwiftVersionedRemovalAttr::AttributeKindToRemove)
    .def_prop_ro("is_replaced_by_active", &SwiftVersionedRemovalAttr::IsReplacedByActive)
    .def_prop_ro("raw_kind", &SwiftVersionedRemovalAttr::RawKind)
    .def_prop_ro("spelling", &SwiftVersionedRemovalAttr::Spelling);
}
} // namespace pasta
