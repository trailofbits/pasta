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

void RegisterObjCMethodFamilyAttr(nb::module_ &m) {
  nb::class_<ObjCMethodFamilyAttr, InheritableAttr>(m, "ObjCMethodFamilyAttr")
    .def("__hash__", [](const ObjCMethodFamilyAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("family", &ObjCMethodFamilyAttr::Family)
    .def_prop_ro("spelling", &ObjCMethodFamilyAttr::Spelling);
}
} // namespace pasta
