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

void RegisterMSVtorDispAttr(nb::module_ &m) {
  nb::class_<MSVtorDispAttr, InheritableAttr>(m, "MSVtorDispAttr")
    .def("__hash__", [](const MSVtorDispAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &MSVtorDispAttr::Spelling)
    .def_prop_ro("vdm", &MSVtorDispAttr::Vdm)
    .def_prop_ro("vtor_disp_mode", &MSVtorDispAttr::VtorDispMode);
}
} // namespace pasta
