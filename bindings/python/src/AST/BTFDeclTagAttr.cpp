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

void RegisterBTFDeclTagAttr(nb::module_ &m) {
  nb::class_<BTFDeclTagAttr, InheritableAttr>(m, "BTFDeclTagAttr")
    .def("__hash__", [](const BTFDeclTagAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("btf_decl_tag", &BTFDeclTagAttr::BTFDeclTag)
    .def_prop_ro("btf_decl_tag_length", &BTFDeclTagAttr::BTFDeclTagLength)
    .def_prop_ro("spelling", &BTFDeclTagAttr::Spelling);
}
} // namespace pasta
