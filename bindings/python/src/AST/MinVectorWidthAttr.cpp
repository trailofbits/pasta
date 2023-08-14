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

void RegisterMinVectorWidthAttr(nb::module_ &m) {
  nb::class_<MinVectorWidthAttr, InheritableAttr>(m, "MinVectorWidthAttr")
    .def("__hash__", [](const MinVectorWidthAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &MinVectorWidthAttr::Spelling)
    .def_prop_ro("vector_width", &MinVectorWidthAttr::VectorWidth);
}
} // namespace pasta
