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

void RegisterBinaryOperator(py::module_ &m) {
  py::class_<BinaryOperator, Expr>(m, "BinaryOperator")
    .def("__hash__", [](const BinaryOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &BinaryOperator::Children)
    .def_property_readonly("begin_token", &BinaryOperator::BeginToken)
    .def_property_readonly("end_token", &BinaryOperator::EndToken)
    .def_property_readonly("expression_token", &BinaryOperator::ExpressionToken)
    .def_property_readonly("lhs", &BinaryOperator::LHS)
    .def_property_readonly("opcode", &BinaryOperator::Opcode)
    .def_property_readonly("opcode_string", &BinaryOperator::OpcodeString)
    .def_property_readonly("operator_token", &BinaryOperator::OperatorToken)
    .def_property_readonly("rhs", &BinaryOperator::RHS)
    .def_property_readonly("has_stored_fp_features", &BinaryOperator::HasStoredFPFeatures)
    .def_property_readonly("is_additive_operation", &BinaryOperator::IsAdditiveOperation)
    .def_property_readonly("is_assignment_operation", &BinaryOperator::IsAssignmentOperation)
    .def_property_readonly("is_bitwise_operation", &BinaryOperator::IsBitwiseOperation)
    .def_property_readonly("is_comma_operation", &BinaryOperator::IsCommaOperation)
    .def_property_readonly("is_comparison_operation", &BinaryOperator::IsComparisonOperation)
    .def_property_readonly("is_compound_assignment_operation", &BinaryOperator::IsCompoundAssignmentOperation)
    .def_property_readonly("is_equality_operation", &BinaryOperator::IsEqualityOperation)
    .def_property_readonly("is_logical_operation", &BinaryOperator::IsLogicalOperation)
    .def_property_readonly("is_multiplicative_operation", &BinaryOperator::IsMultiplicativeOperation)
    .def_property_readonly("is_pointer_memory_operation", &BinaryOperator::IsPointerMemoryOperation)
    .def_property_readonly("is_relational_operation", &BinaryOperator::IsRelationalOperation)
    .def_property_readonly("is_shift_assign_operation", &BinaryOperator::IsShiftAssignOperation)
    .def_property_readonly("is_shift_operation", &BinaryOperator::IsShiftOperation);
}
} // namespace pasta
