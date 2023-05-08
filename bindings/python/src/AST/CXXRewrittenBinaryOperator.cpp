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

void RegisterCXXRewrittenBinaryOperator(py::module_ &m) {
  py::class_<CXXRewrittenBinaryOperator, Expr>(m, "CXXRewrittenBinaryOperator")
    .def("__hash__", [](const CXXRewrittenBinaryOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXRewrittenBinaryOperator& a, const CXXRewrittenBinaryOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &CXXRewrittenBinaryOperator::BeginToken)
    .def_property_readonly("end_token", &CXXRewrittenBinaryOperator::EndToken)
    .def_property_readonly("expression_token", &CXXRewrittenBinaryOperator::ExpressionToken)
    .def_property_readonly("lhs", &CXXRewrittenBinaryOperator::LHS)
    .def_property_readonly("opcode", &CXXRewrittenBinaryOperator::Opcode)
    .def_property_readonly("opcode_string", &CXXRewrittenBinaryOperator::OpcodeString)
    .def_property_readonly("operator", &CXXRewrittenBinaryOperator::Operator)
    .def_property_readonly("operator_token", &CXXRewrittenBinaryOperator::OperatorToken)
    .def_property_readonly("rhs", &CXXRewrittenBinaryOperator::RHS)
    .def_property_readonly("semantic_form", &CXXRewrittenBinaryOperator::SemanticForm)
    .def_property_readonly("tokens", &CXXRewrittenBinaryOperator::Tokens)
    .def_property_readonly("is_assignment_operation", &CXXRewrittenBinaryOperator::IsAssignmentOperation)
    .def_property_readonly("is_comparison_operation", &CXXRewrittenBinaryOperator::IsComparisonOperation)
    .def_property_readonly("is_reversed", &CXXRewrittenBinaryOperator::IsReversed);
}
} // namespace pasta
