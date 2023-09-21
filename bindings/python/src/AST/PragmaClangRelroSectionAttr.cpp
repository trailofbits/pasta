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

void RegisterPragmaClangRelroSectionAttr(nb::module_ &m) {
  nb::class_<PragmaClangRelroSectionAttr, InheritableAttr>(m, "PragmaClangRelroSectionAttr")
    .def("__hash__", [](const PragmaClangRelroSectionAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("name", &PragmaClangRelroSectionAttr::Name)
    .def_prop_ro("name_length", &PragmaClangRelroSectionAttr::NameLength)
    .def_prop_ro("spelling", &PragmaClangRelroSectionAttr::Spelling);
}
} // namespace pasta
