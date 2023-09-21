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

void RegisterUuidAttr(nb::module_ &m) {
  nb::class_<UuidAttr, InheritableAttr>(m, "UuidAttr")
    .def("__hash__", [](const UuidAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("guid", &UuidAttr::Guid)
    .def_prop_ro("guid_declaration", &UuidAttr::GuidDeclaration)
    .def_prop_ro("guid_length", &UuidAttr::GuidLength)
    .def_prop_ro("spelling", &UuidAttr::Spelling);
}
} // namespace pasta
