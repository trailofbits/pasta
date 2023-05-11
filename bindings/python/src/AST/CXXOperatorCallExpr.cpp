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

void RegisterCXXOperatorCallExpr(py::module_ &m) {
  py::class_<CXXOperatorCallExpr, CallExpr>(m, "CXXOperatorCallExpr")
    .def("__hash__", [](const CXXOperatorCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &CXXOperatorCallExpr::BeginToken)
    .def_property_readonly("end_token", &CXXOperatorCallExpr::EndToken)
    .def_property_readonly("expression_token", &CXXOperatorCallExpr::ExpressionToken)
    .def_property_readonly("operator", &CXXOperatorCallExpr::Operator)
    .def_property_readonly("operator_token", &CXXOperatorCallExpr::OperatorToken)
    .def_property_readonly("tokens", &CXXOperatorCallExpr::Tokens)
    .def_property_readonly("is_assignment_operation", &CXXOperatorCallExpr::IsAssignmentOperation)
    .def_property_readonly("is_comparison_operation", &CXXOperatorCallExpr::IsComparisonOperation)
    .def_property_readonly("is_infix_binary_operation", &CXXOperatorCallExpr::IsInfixBinaryOperation);
}
} // namespace pasta
