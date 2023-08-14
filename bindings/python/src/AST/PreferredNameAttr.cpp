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

void RegisterPreferredNameAttr(nb::module_ &m) {
  nb::class_<PreferredNameAttr, InheritableAttr>(m, "PreferredNameAttr")
    .def("__hash__", [](const PreferredNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &PreferredNameAttr::Spelling)
    .def_prop_ro("typedef_type", &PreferredNameAttr::TypedefType)
    .def_prop_ro("typedef_type_token", &PreferredNameAttr::TypedefTypeToken);
}
} // namespace pasta
