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

void RegisterExpressionTraitExpr(nb::module_ &m) {
  nb::class_<ExpressionTraitExpr, Expr>(m, "ExpressionTraitExpr")
    .def("__hash__", [](const ExpressionTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ExpressionTraitExpr::Children)
    .def_prop_ro("begin_token", &ExpressionTraitExpr::BeginToken)
    .def_prop_ro("end_token", &ExpressionTraitExpr::EndToken)
    .def_prop_ro("queried_expression", &ExpressionTraitExpr::QueriedExpression)
    .def_prop_ro("trait", &ExpressionTraitExpr::Trait)
    .def_prop_ro("value", &ExpressionTraitExpr::Value);
}
} // namespace pasta
