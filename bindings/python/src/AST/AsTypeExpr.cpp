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

void RegisterAsTypeExpr(nb::module_ &m) {
  nb::class_<AsTypeExpr, Expr>(m, "AsTypeExpr")
    .def("__hash__", [](const AsTypeExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &AsTypeExpr::Children)
    .def_prop_ro("begin_token", &AsTypeExpr::BeginToken)
    .def_prop_ro("builtin_token", &AsTypeExpr::BuiltinToken)
    .def_prop_ro("end_token", &AsTypeExpr::EndToken)
    .def_prop_ro("r_paren_token", &AsTypeExpr::RParenToken)
    .def_prop_ro("src_expression", &AsTypeExpr::SrcExpression);
}
} // namespace pasta
