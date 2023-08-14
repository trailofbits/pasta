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

void RegisterXRayInstrumentAttr(nb::module_ &m) {
  nb::class_<XRayInstrumentAttr, InheritableAttr>(m, "XRayInstrumentAttr")
    .def("__hash__", [](const XRayInstrumentAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("always_x_ray_instrument", &XRayInstrumentAttr::AlwaysXRayInstrument)
    .def_prop_ro("semantic_spelling", &XRayInstrumentAttr::SemanticSpelling)
    .def_prop_ro("spelling", &XRayInstrumentAttr::Spelling)
    .def_prop_ro("never_x_ray_instrument", &XRayInstrumentAttr::NeverXRayInstrument);
}
} // namespace pasta
