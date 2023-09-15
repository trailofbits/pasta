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

void RegisterNoInlineAttr(nb::module_ &m) {
  nb::class_<NoInlineAttr, DeclOrStmtAttr>(m, "NoInlineAttr")
    .def("__hash__", [](const NoInlineAttr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &NoInlineAttr::Spelling)
    .def_prop_ro("is_clang_no_inline", &NoInlineAttr::IsClangNoInline);
}
} // namespace pasta
