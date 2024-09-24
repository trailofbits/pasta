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

void RegisterCXXRewrittenBinaryOperator(nb::module_ &m) {
  nb::class_<CXXRewrittenBinaryOperator, Expr>(m, "CXXRewrittenBinaryOperator")
    .def_prop_ro("begin_token", &CXXRewrittenBinaryOperator::BeginToken)
    .def_prop_ro("end_token", &CXXRewrittenBinaryOperator::EndToken)
    .def_prop_ro("expression_token", &CXXRewrittenBinaryOperator::ExpressionToken)
    .def_prop_ro("lhs", &CXXRewrittenBinaryOperator::LHS)
    .def_prop_ro("opcode", &CXXRewrittenBinaryOperator::Opcode)
    .def_prop_ro("opcode_string", &CXXRewrittenBinaryOperator::OpcodeString)
    .def_prop_ro("operator", &CXXRewrittenBinaryOperator::Operator)
    .def_prop_ro("operator_token", &CXXRewrittenBinaryOperator::OperatorToken)
    .def_prop_ro("rhs", &CXXRewrittenBinaryOperator::RHS)
    .def_prop_ro("semantic_form", &CXXRewrittenBinaryOperator::SemanticForm)
    .def_prop_ro("tokens", &CXXRewrittenBinaryOperator::Tokens)
    .def_prop_ro("is_assignment_operation", &CXXRewrittenBinaryOperator::IsAssignmentOperation)
    .def_prop_ro("is_comparison_operation", &CXXRewrittenBinaryOperator::IsComparisonOperation)
    .def_prop_ro("is_reversed", &CXXRewrittenBinaryOperator::IsReversed);
}
} // namespace pasta
