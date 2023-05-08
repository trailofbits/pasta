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
    .def_property_readonly("BeginToken", &CXXRewrittenBinaryOperator::BeginToken)
    .def_property_readonly("EndToken", &CXXRewrittenBinaryOperator::EndToken)
    .def_property_readonly("ExpressionToken", &CXXRewrittenBinaryOperator::ExpressionToken)
    .def_property_readonly("LHS", &CXXRewrittenBinaryOperator::LHS)
    .def_property_readonly("Opcode", &CXXRewrittenBinaryOperator::Opcode)
    .def_property_readonly("OpcodeString", &CXXRewrittenBinaryOperator::OpcodeString)
    .def_property_readonly("Operator", &CXXRewrittenBinaryOperator::Operator)
    .def_property_readonly("OperatorToken", &CXXRewrittenBinaryOperator::OperatorToken)
    .def_property_readonly("RHS", &CXXRewrittenBinaryOperator::RHS)
    .def_property_readonly("SemanticForm", &CXXRewrittenBinaryOperator::SemanticForm)
    .def_property_readonly("Tokens", &CXXRewrittenBinaryOperator::Tokens)
    .def_property_readonly("IsAssignmentOperation", &CXXRewrittenBinaryOperator::IsAssignmentOperation)
    .def_property_readonly("IsComparisonOperation", &CXXRewrittenBinaryOperator::IsComparisonOperation)
    .def_property_readonly("IsReversed", &CXXRewrittenBinaryOperator::IsReversed);
}
} // namespace pasta
