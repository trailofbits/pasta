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

void RegisterSharedTrylockFunctionAttr(nb::module_ &m) {
  nb::class_<SharedTrylockFunctionAttr, InheritableAttr>(m, "SharedTrylockFunctionAttr")
    .def("__hash__", [](const SharedTrylockFunctionAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &SharedTrylockFunctionAttr::Spelling)
    .def_prop_ro("success_value", &SharedTrylockFunctionAttr::SuccessValue);
}
} // namespace pasta
