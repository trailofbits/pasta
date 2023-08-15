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

void RegisterEnforceTCBAttr(nb::module_ &m) {
  nb::class_<EnforceTCBAttr, InheritableAttr>(m, "EnforceTCBAttr")
    .def("__hash__", [](const EnforceTCBAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &EnforceTCBAttr::Spelling)
    .def_prop_ro("tcb_name", &EnforceTCBAttr::TCBName)
    .def_prop_ro("tcb_name_length", &EnforceTCBAttr::TCBNameLength);
}
} // namespace pasta
