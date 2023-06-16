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

void RegisterTargetAttr(nb::module_ &m) {
  nb::class_<TargetAttr, InheritableAttr>(m, "TargetAttr")
    .def("__hash__", [](const TargetAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("architecture", &TargetAttr::Architecture)
    .def_prop_ro("features_string", &TargetAttr::FeaturesString)
    .def_prop_ro("features_string_length", &TargetAttr::FeaturesStringLength)
    .def_prop_ro("spelling", &TargetAttr::Spelling)
    .def_prop_ro("is_default_version", &TargetAttr::IsDefaultVersion);
}
} // namespace pasta
