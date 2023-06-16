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

void RegisterDeprecatedAttr(nb::module_ &m) {
  nb::class_<DeprecatedAttr, InheritableAttr>(m, "DeprecatedAttr")
    .def("__hash__", [](const DeprecatedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("message", &DeprecatedAttr::Message)
    .def_prop_ro("message_length", &DeprecatedAttr::MessageLength)
    .def_prop_ro("replacement", &DeprecatedAttr::Replacement)
    .def_prop_ro("replacement_length", &DeprecatedAttr::ReplacementLength)
    .def_prop_ro("spelling", &DeprecatedAttr::Spelling);
}
} // namespace pasta
