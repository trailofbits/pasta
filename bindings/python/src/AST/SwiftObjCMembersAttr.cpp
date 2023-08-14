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

void RegisterSwiftObjCMembersAttr(nb::module_ &m) {
  nb::class_<SwiftObjCMembersAttr, Attr>(m, "SwiftObjCMembersAttr")
    .def("__hash__", [](const SwiftObjCMembersAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &SwiftObjCMembersAttr::Spelling);
}
} // namespace pasta
