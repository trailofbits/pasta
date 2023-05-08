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

void RegisterCXXOperatorCallExpr(py::module_ &m) {
  py::class_<CXXOperatorCallExpr, CallExpr>(m, "CXXOperatorCallExpr")
    .def("__hash__", [](const CXXOperatorCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXOperatorCallExpr& a, const CXXOperatorCallExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("BeginToken", &CXXOperatorCallExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXOperatorCallExpr::EndToken)
    .def_property_readonly("ExpressionToken", &CXXOperatorCallExpr::ExpressionToken)
    .def_property_readonly("Operator", &CXXOperatorCallExpr::Operator)
    .def_property_readonly("OperatorToken", &CXXOperatorCallExpr::OperatorToken)
    .def_property_readonly("Tokens", &CXXOperatorCallExpr::Tokens)
    .def_property_readonly("IsAssignmentOperation", &CXXOperatorCallExpr::IsAssignmentOperation)
    .def_property_readonly("IsComparisonOperation", &CXXOperatorCallExpr::IsComparisonOperation)
    .def_property_readonly("IsInfixBinaryOperation", &CXXOperatorCallExpr::IsInfixBinaryOperation);
}
} // namespace pasta
