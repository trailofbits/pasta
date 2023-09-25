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

void RegisterInitPriorityAttr(nb::module_ &m) {
  nb::class_<InitPriorityAttr, InheritableAttr>(m, "InitPriorityAttr")
    .def("__hash__", [](const InitPriorityAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("priority", &InitPriorityAttr::Priority)
    .def_prop_ro("spelling", &InitPriorityAttr::Spelling);
}
} // namespace pasta
