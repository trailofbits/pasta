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

void RegisterMSPropertySubscriptExpr(nb::module_ &m) {
  nb::class_<MSPropertySubscriptExpr, Expr>(m, "MSPropertySubscriptExpr")
    .def("__hash__", [](const MSPropertySubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &MSPropertySubscriptExpr::Children)
    .def_prop_ro("base", &MSPropertySubscriptExpr::Base)
    .def_prop_ro("begin_token", &MSPropertySubscriptExpr::BeginToken)
    .def_prop_ro("end_token", &MSPropertySubscriptExpr::EndToken)
    .def_prop_ro("expression_token", &MSPropertySubscriptExpr::ExpressionToken)
    .def_prop_ro("index", &MSPropertySubscriptExpr::Index)
    .def_prop_ro("r_bracket_token", &MSPropertySubscriptExpr::RBracketToken);
}
} // namespace pasta
