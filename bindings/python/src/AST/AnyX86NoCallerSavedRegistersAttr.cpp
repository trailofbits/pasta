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

void RegisterAnyX86NoCallerSavedRegistersAttr(nb::module_ &m) {
  nb::class_<AnyX86NoCallerSavedRegistersAttr, InheritableAttr>(m, "AnyX86NoCallerSavedRegistersAttr")
    .def("__hash__", [](const AnyX86NoCallerSavedRegistersAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("spelling", &AnyX86NoCallerSavedRegistersAttr::Spelling);
}
} // namespace pasta
