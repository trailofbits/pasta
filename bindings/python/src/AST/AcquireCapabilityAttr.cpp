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

void RegisterAcquireCapabilityAttr(nb::module_ &m) {
  nb::class_<AcquireCapabilityAttr, InheritableAttr>(m, "AcquireCapabilityAttr")
    .def("__hash__", [](const AcquireCapabilityAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &AcquireCapabilityAttr::SemanticSpelling)
    .def_prop_ro("spelling", &AcquireCapabilityAttr::Spelling)
    .def_prop_ro("is_shared", &AcquireCapabilityAttr::IsShared);
}
} // namespace pasta
