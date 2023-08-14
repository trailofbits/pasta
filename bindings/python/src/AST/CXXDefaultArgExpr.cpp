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

void RegisterCXXDefaultArgExpr(nb::module_ &m) {
  nb::class_<CXXDefaultArgExpr, Expr>(m, "CXXDefaultArgExpr")
    .def("__hash__", [](const CXXDefaultArgExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXDefaultArgExpr::Children)
    .def_prop_ro("adjusted_rewritten_expression", &CXXDefaultArgExpr::AdjustedRewrittenExpression)
    .def_prop_ro("begin_token", &CXXDefaultArgExpr::BeginToken)
    .def_prop_ro("end_token", &CXXDefaultArgExpr::EndToken)
    .def_prop_ro("expression", &CXXDefaultArgExpr::Expression)
    .def_prop_ro("expression_token", &CXXDefaultArgExpr::ExpressionToken)
    .def_prop_ro("parameter", &CXXDefaultArgExpr::Parameter)
    .def_prop_ro("rewritten_expression", &CXXDefaultArgExpr::RewrittenExpression)
    .def_prop_ro("used_context", &CXXDefaultArgExpr::UsedContext)
    .def_prop_ro("used_token", &CXXDefaultArgExpr::UsedToken)
    .def_prop_ro("has_rewritten_initializer", &CXXDefaultArgExpr::HasRewrittenInitializer);
}
} // namespace pasta
