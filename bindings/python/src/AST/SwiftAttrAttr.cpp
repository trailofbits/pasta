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

void RegisterSwiftAttrAttr(nb::module_ &m) {
  nb::class_<SwiftAttrAttr, InheritableAttr>(m, "SwiftAttrAttr")
    .def("__hash__", [](const SwiftAttrAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("attribute", &SwiftAttrAttr::Attribute)
    .def_prop_ro("attribute_length", &SwiftAttrAttr::AttributeLength)
    .def_prop_ro("spelling", &SwiftAttrAttr::Spelling);
}
} // namespace pasta
