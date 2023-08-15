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

void RegisterAcquireHandleAttr(nb::module_ &m) {
  nb::class_<AcquireHandleAttr, InheritableAttr>(m, "AcquireHandleAttr")
    .def("__hash__", [](const AcquireHandleAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("handle_type", &AcquireHandleAttr::HandleType)
    .def_prop_ro("handle_type_length", &AcquireHandleAttr::HandleTypeLength)
    .def_prop_ro("spelling", &AcquireHandleAttr::Spelling);
}
} // namespace pasta
