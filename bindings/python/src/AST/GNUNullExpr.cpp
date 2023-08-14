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

void RegisterGNUNullExpr(nb::module_ &m) {
  nb::class_<GNUNullExpr, Expr>(m, "GNUNullExpr")
    .def("__hash__", [](const GNUNullExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &GNUNullExpr::Children)
    .def_prop_ro("begin_token", &GNUNullExpr::BeginToken)
    .def_prop_ro("end_token", &GNUNullExpr::EndToken)
    .def_prop_ro("token_token", &GNUNullExpr::TokenToken);
}
} // namespace pasta
