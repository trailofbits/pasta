/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterAssertCapabilityAttr(nb::module_ &m) {
  nb::class_<AssertCapabilityAttr, InheritableAttr>(m, "AssertCapabilityAttr")
    .def("__hash__", [](const AssertCapabilityAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &AssertCapabilityAttr::SemanticSpelling)
    .def_prop_ro("spelling", &AssertCapabilityAttr::Spelling)
    .def_prop_ro("is_shared", &AssertCapabilityAttr::IsShared);
}
} // namespace pasta
