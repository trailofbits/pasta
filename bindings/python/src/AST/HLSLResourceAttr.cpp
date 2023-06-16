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

void RegisterHLSLResourceAttr(nb::module_ &m) {
  nb::class_<HLSLResourceAttr, InheritableAttr>(m, "HLSLResourceAttr")
    .def("__hash__", [](const HLSLResourceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("resource_shape", &HLSLResourceAttr::ResourceShape)
    .def_prop_ro("resource_type", &HLSLResourceAttr::ResourceType)
    .def_prop_ro("spelling", &HLSLResourceAttr::Spelling);
}
} // namespace pasta
