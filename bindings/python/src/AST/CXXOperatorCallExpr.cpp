/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterCXXOperatorCallExpr(nb::module_ &m) {
  nb::class_<CXXOperatorCallExpr, CallExpr>(m, "CXXOperatorCallExpr")
    .def("__hash__", [](const CXXOperatorCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &CXXOperatorCallExpr::BeginToken)
    .def_prop_ro("end_token", &CXXOperatorCallExpr::EndToken)
    .def_prop_ro("expression_token", &CXXOperatorCallExpr::ExpressionToken)
    .def_prop_ro("operator", &CXXOperatorCallExpr::Operator)
    .def_prop_ro("operator_token", &CXXOperatorCallExpr::OperatorToken)
    .def_prop_ro("tokens", &CXXOperatorCallExpr::Tokens)
    .def_prop_ro("is_assignment_operation", &CXXOperatorCallExpr::IsAssignmentOperation)
    .def_prop_ro("is_comparison_operation", &CXXOperatorCallExpr::IsComparisonOperation)
    .def_prop_ro("is_infix_binary_operation", &CXXOperatorCallExpr::IsInfixBinaryOperation);
}
} // namespace pasta
