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
  py::class_<ExpressionTraitExpr, Expr, Stmt, ValueStmt>(m, "ExpressionTraitExpr")
    .def("__hash__", [](const ExpressionTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ExpressionTraitExpr& a, const ExpressionTraitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ExpressionTraitExpr::Children)
    .def_property_readonly("BeginToken", &ExpressionTraitExpr::BeginToken)
    .def_property_readonly("EndToken", &ExpressionTraitExpr::EndToken)
    .def_property_readonly("QueriedExpression", &ExpressionTraitExpr::QueriedExpression)
    .def_property_readonly("Trait", &ExpressionTraitExpr::Trait)
    .def_property_readonly("Value", &ExpressionTraitExpr::Value);
}
} // namespace pasta
