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

void RegisterHLSLResourceBindingAttr(nb::module_ &m) {
  nb::class_<HLSLResourceBindingAttr, InheritableAttr>(m, "HLSLResourceBindingAttr")
    .def("__hash__", [](const HLSLResourceBindingAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("slot", &HLSLResourceBindingAttr::Slot)
    .def_prop_ro("slot_length", &HLSLResourceBindingAttr::SlotLength)
    .def_prop_ro("space", &HLSLResourceBindingAttr::Space)
    .def_prop_ro("space_length", &HLSLResourceBindingAttr::SpaceLength)
    .def_prop_ro("spelling", &HLSLResourceBindingAttr::Spelling);
}
} // namespace pasta
