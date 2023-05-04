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

void RegisterCXXDefaultArgExpr(py::module_ &m) {
  py::class_<CXXDefaultArgExpr, Expr, Stmt, ValueStmt>(m, "CXXDefaultArgExpr")
    .def("__hash__", [](const CXXDefaultArgExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDefaultArgExpr& a, const CXXDefaultArgExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXDefaultArgExpr::Children)
    .def_property_readonly("AdjustedRewrittenExpression", &CXXDefaultArgExpr::AdjustedRewrittenExpression)
    .def_property_readonly("BeginToken", &CXXDefaultArgExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXDefaultArgExpr::EndToken)
    .def_property_readonly("Expression", &CXXDefaultArgExpr::Expression)
    .def_property_readonly("ExpressionToken", &CXXDefaultArgExpr::ExpressionToken)
    .def_property_readonly("Parameter", &CXXDefaultArgExpr::Parameter)
    .def_property_readonly("RewrittenExpression", &CXXDefaultArgExpr::RewrittenExpression)
    .def_property_readonly("UsedContext", &CXXDefaultArgExpr::UsedContext)
    .def_property_readonly("UsedToken", &CXXDefaultArgExpr::UsedToken)
    .def_property_readonly("HasRewrittenInitializer", &CXXDefaultArgExpr::HasRewrittenInitializer);
}
} // namespace pasta
