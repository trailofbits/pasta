/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterExpressionTraitExpr(py::module_ &m) {
  py::class_<ExpressionTraitExpr, Expr>(m, "ExpressionTraitExpr")
    .def("__hash__", [](const ExpressionTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ExpressionTraitExpr& a, const ExpressionTraitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ExpressionTraitExpr::Children)
    .def_property_readonly("begin_token", &ExpressionTraitExpr::BeginToken)
    .def_property_readonly("end_token", &ExpressionTraitExpr::EndToken)
    .def_property_readonly("queried_expression", &ExpressionTraitExpr::QueriedExpression)
    .def_property_readonly("trait", &ExpressionTraitExpr::Trait)
    .def_property_readonly("value", &ExpressionTraitExpr::Value);
}
} // namespace pasta
