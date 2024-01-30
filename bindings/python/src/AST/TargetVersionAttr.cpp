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

void RegisterTargetVersionAttr(nb::module_ &m) {
  nb::class_<TargetVersionAttr, InheritableAttr>(m, "TargetVersionAttr")
    .def("__hash__", [](const TargetVersionAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("name", &TargetVersionAttr::Name)
    .def_prop_ro("names_string", &TargetVersionAttr::NamesString)
    .def_prop_ro("names_string_length", &TargetVersionAttr::NamesStringLength)
    .def_prop_ro("spelling", &TargetVersionAttr::Spelling)
    .def_prop_ro("is_default_version", &TargetVersionAttr::IsDefaultVersion);
}
} // namespace pasta
