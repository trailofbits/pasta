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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterCXXDefaultArgExpr(py::module_ &m) {
  py::class_<CXXDefaultArgExpr, Expr>(m, "CXXDefaultArgExpr")
    .def("__hash__", [](const CXXDefaultArgExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDefaultArgExpr& a, const CXXDefaultArgExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXDefaultArgExpr::Children)
    .def_property_readonly("adjusted_rewritten_expression", &CXXDefaultArgExpr::AdjustedRewrittenExpression)
    .def_property_readonly("begin_token", &CXXDefaultArgExpr::BeginToken)
    .def_property_readonly("end_token", &CXXDefaultArgExpr::EndToken)
    .def_property_readonly("expression", &CXXDefaultArgExpr::Expression)
    .def_property_readonly("expression_token", &CXXDefaultArgExpr::ExpressionToken)
    .def_property_readonly("parameter", &CXXDefaultArgExpr::Parameter)
    .def_property_readonly("rewritten_expression", &CXXDefaultArgExpr::RewrittenExpression)
    .def_property_readonly("used_context", &CXXDefaultArgExpr::UsedContext)
    .def_property_readonly("used_token", &CXXDefaultArgExpr::UsedToken)
    .def_property_readonly("has_rewritten_initializer", &CXXDefaultArgExpr::HasRewrittenInitializer);
}
} // namespace pasta
