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

void RegisterAlignMac68kAttr(nb::module_ &m) {
  nb::class_<AlignMac68kAttr, InheritableAttr>(m, "AlignMac68kAttr")
    .def("__hash__", [](const AlignMac68kAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &AlignMac68kAttr::Spelling);
}
} // namespace pasta
