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

void RegisterSwiftNameAttr(nb::module_ &m) {
  nb::class_<SwiftNameAttr, InheritableAttr>(m, "SwiftNameAttr")
    .def("__hash__", [](const SwiftNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("name", &SwiftNameAttr::Name)
    .def_prop_ro("name_length", &SwiftNameAttr::NameLength)
    .def_prop_ro("spelling", &SwiftNameAttr::Spelling);
}
} // namespace pasta
