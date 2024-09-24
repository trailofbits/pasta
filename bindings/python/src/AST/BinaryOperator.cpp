/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterBinaryOperator(nb::module_ &m) {
  nb::class_<BinaryOperator, Expr>(m, "BinaryOperator")
    .def_prop_ro("children", &BinaryOperator::Children)
    .def_prop_ro("begin_token", &BinaryOperator::BeginToken)
    .def_prop_ro("end_token", &BinaryOperator::EndToken)
    .def_prop_ro("expression_token", &BinaryOperator::ExpressionToken)
    .def_prop_ro("lhs", &BinaryOperator::LHS)
    .def_prop_ro("opcode", &BinaryOperator::Opcode)
    .def_prop_ro("opcode_string", &BinaryOperator::OpcodeString)
    .def_prop_ro("operator_token", &BinaryOperator::OperatorToken)
    .def_prop_ro("rhs", &BinaryOperator::RHS)
    .def_prop_ro("has_stored_fp_features", &BinaryOperator::HasStoredFPFeatures)
    .def_prop_ro("is_additive_operation", &BinaryOperator::IsAdditiveOperation)
    .def_prop_ro("is_assignment_operation", &BinaryOperator::IsAssignmentOperation)
    .def_prop_ro("is_bitwise_operation", &BinaryOperator::IsBitwiseOperation)
    .def_prop_ro("is_comma_operation", &BinaryOperator::IsCommaOperation)
    .def_prop_ro("is_comparison_operation", &BinaryOperator::IsComparisonOperation)
    .def_prop_ro("is_compound_assignment_operation", &BinaryOperator::IsCompoundAssignmentOperation)
    .def_prop_ro("is_equality_operation", &BinaryOperator::IsEqualityOperation)
    .def_prop_ro("is_logical_operation", &BinaryOperator::IsLogicalOperation)
    .def_prop_ro("is_multiplicative_operation", &BinaryOperator::IsMultiplicativeOperation)
    .def_prop_ro("is_pointer_memory_operation", &BinaryOperator::IsPointerMemoryOperation)
    .def_prop_ro("is_relational_operation", &BinaryOperator::IsRelationalOperation)
    .def_prop_ro("is_shift_assign_operation", &BinaryOperator::IsShiftAssignOperation)
    .def_prop_ro("is_shift_operation", &BinaryOperator::IsShiftOperation);
}
} // namespace pasta
