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

void RegisterCXX11NoReturnAttr(nb::module_ &m) {
  nb::class_<CXX11NoReturnAttr, InheritableAttr>(m, "CXX11NoReturnAttr")
    .def("__hash__", [](const CXX11NoReturnAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &CXX11NoReturnAttr::SemanticSpelling)
    .def_prop_ro("spelling", &CXX11NoReturnAttr::Spelling);
}
} // namespace pasta
