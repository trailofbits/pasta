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

void RegisterAlwaysInlineAttr(nb::module_ &m) {
  nb::class_<AlwaysInlineAttr, DeclOrStmtAttr>(m, "AlwaysInlineAttr")
    .def("__hash__", [](const AlwaysInlineAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &AlwaysInlineAttr::SemanticSpelling)
    .def_prop_ro("spelling", &AlwaysInlineAttr::Spelling)
    .def_prop_ro("is_clang_always_inline", &AlwaysInlineAttr::IsClangAlwaysInline);
}
} // namespace pasta
