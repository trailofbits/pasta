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

void RegisterOpaqueValueExpr(nb::module_ &m) {
  nb::class_<OpaqueValueExpr, Expr>(m, "OpaqueValueExpr")
    .def("__hash__", [](const OpaqueValueExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &OpaqueValueExpr::Children)
    .def_prop_ro("begin_token", &OpaqueValueExpr::BeginToken)
    .def_prop_ro("end_token", &OpaqueValueExpr::EndToken)
    .def_prop_ro("expression_token", &OpaqueValueExpr::ExpressionToken)
    .def_prop_ro("token", &OpaqueValueExpr::Token)
    .def_prop_ro("source_expression", &OpaqueValueExpr::SourceExpression)
    .def_prop_ro("is_unique", &OpaqueValueExpr::IsUnique);
}
} // namespace pasta
