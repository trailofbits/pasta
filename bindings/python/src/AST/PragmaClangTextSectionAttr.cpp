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

void RegisterPragmaClangTextSectionAttr(nb::module_ &m) {
  nb::class_<PragmaClangTextSectionAttr, InheritableAttr>(m, "PragmaClangTextSectionAttr")
    .def("__hash__", [](const PragmaClangTextSectionAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("name", &PragmaClangTextSectionAttr::Name)
    .def_prop_ro("name_length", &PragmaClangTextSectionAttr::NameLength)
    .def_prop_ro("spelling", &PragmaClangTextSectionAttr::Spelling);
}
} // namespace pasta
