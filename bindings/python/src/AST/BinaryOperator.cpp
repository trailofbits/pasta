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

void RegisterBinaryOperator(py::module_ &m) {
  py::class_<BinaryOperator, Expr, Stmt, ValueStmt>(m, "BinaryOperator")
    .def("__hash__", [](const BinaryOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const BinaryOperator& a, const BinaryOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &BinaryOperator::Children)
    .def_property_readonly("BeginToken", &BinaryOperator::BeginToken)
    .def_property_readonly("EndToken", &BinaryOperator::EndToken)
    .def_property_readonly("ExpressionToken", &BinaryOperator::ExpressionToken)
    .def_property_readonly("LHS", &BinaryOperator::LHS)
    .def_property_readonly("Opcode", &BinaryOperator::Opcode)
    .def_property_readonly("OpcodeString", &BinaryOperator::OpcodeString)
    .def_property_readonly("OperatorToken", &BinaryOperator::OperatorToken)
    .def_property_readonly("RHS", &BinaryOperator::RHS)
    .def_property_readonly("HasStoredFPFeatures", &BinaryOperator::HasStoredFPFeatures)
    .def_property_readonly("IsAdditiveOperation", &BinaryOperator::IsAdditiveOperation)
    .def_property_readonly("IsAssignmentOperation", &BinaryOperator::IsAssignmentOperation)
    .def_property_readonly("IsBitwiseOperation", &BinaryOperator::IsBitwiseOperation)
    .def_property_readonly("IsCommaOperation", &BinaryOperator::IsCommaOperation)
    .def_property_readonly("IsComparisonOperation", &BinaryOperator::IsComparisonOperation)
    .def_property_readonly("IsCompoundAssignmentOperation", &BinaryOperator::IsCompoundAssignmentOperation)
    .def_property_readonly("IsEqualityOperation", &BinaryOperator::IsEqualityOperation)
    .def_property_readonly("IsLogicalOperation", &BinaryOperator::IsLogicalOperation)
    .def_property_readonly("IsMultiplicativeOperation", &BinaryOperator::IsMultiplicativeOperation)
    .def_property_readonly("IsPointerMemoryOperation", &BinaryOperator::IsPointerMemoryOperation)
    .def_property_readonly("IsRelationalOperation", &BinaryOperator::IsRelationalOperation)
    .def_property_readonly("IsShiftAssignOperation", &BinaryOperator::IsShiftAssignOperation)
    .def_property_readonly("IsShiftOperation", &BinaryOperator::IsShiftOperation);
}
} // namespace pasta
