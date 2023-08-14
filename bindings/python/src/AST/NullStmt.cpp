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

void RegisterNullStmt(nb::module_ &m) {
  nb::class_<NullStmt, Stmt>(m, "NullStmt")
    .def("__hash__", [](const NullStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &NullStmt::Children)
    .def_prop_ro("begin_token", &NullStmt::BeginToken)
    .def_prop_ro("end_token", &NullStmt::EndToken)
    .def_prop_ro("semi_token", &NullStmt::SemiToken)
    .def_prop_ro("has_leading_empty_macro", &NullStmt::HasLeadingEmptyMacro);
}
} // namespace pasta
