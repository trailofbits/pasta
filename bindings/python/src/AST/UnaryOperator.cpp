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

void RegisterUnaryOperator(py::module_ &m) {
  py::class_<UnaryOperator, Expr>(m, "UnaryOperator")
    .def("__hash__", [](const UnaryOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UnaryOperator& a, const UnaryOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("can_overflow", &UnaryOperator::CanOverflow)
    .def_property_readonly("children", &UnaryOperator::Children)
    .def_property_readonly("begin_token", &UnaryOperator::BeginToken)
    .def_property_readonly("end_token", &UnaryOperator::EndToken)
    .def_property_readonly("expression_token", &UnaryOperator::ExpressionToken)
    .def_property_readonly("opcode", &UnaryOperator::Opcode)
    .def_property_readonly("operator_token", &UnaryOperator::OperatorToken)
    .def_property_readonly("sub_expression", &UnaryOperator::SubExpression)
    .def_property_readonly("has_stored_fp_features", &UnaryOperator::HasStoredFPFeatures)
    .def_property_readonly("is_arithmetic_operation", &UnaryOperator::IsArithmeticOperation)
    .def_property_readonly("is_decrement_operation", &UnaryOperator::IsDecrementOperation)
    .def_property_readonly("is_increment_decrement_operation", &UnaryOperator::IsIncrementDecrementOperation)
    .def_property_readonly("is_increment_operation", &UnaryOperator::IsIncrementOperation)
    .def_property_readonly("is_postfix", &UnaryOperator::IsPostfix)
    .def_property_readonly("is_prefix", &UnaryOperator::IsPrefix);
}
} // namespace pasta
