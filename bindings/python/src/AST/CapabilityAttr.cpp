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

void RegisterCapabilityAttr(nb::module_ &m) {
  nb::class_<CapabilityAttr, InheritableAttr>(m, "CapabilityAttr")
    .def("__hash__", [](const CapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("name", &CapabilityAttr::Name)
    .def_prop_ro("name_length", &CapabilityAttr::NameLength)
    .def_prop_ro("semantic_spelling", &CapabilityAttr::SemanticSpelling)
    .def_prop_ro("spelling", &CapabilityAttr::Spelling)
    .def_prop_ro("is_shared", &CapabilityAttr::IsShared);
}
} // namespace pasta
