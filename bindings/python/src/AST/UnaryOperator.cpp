/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterUnaryOperator(nb::module_ &m) {
  nb::class_<UnaryOperator, Expr>(m, "UnaryOperator")
    .def("__hash__", [](const UnaryOperator& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("can_overflow", &UnaryOperator::CanOverflow)
    .def_prop_ro("children", &UnaryOperator::Children)
    .def_prop_ro("begin_token", &UnaryOperator::BeginToken)
    .def_prop_ro("end_token", &UnaryOperator::EndToken)
    .def_prop_ro("expression_token", &UnaryOperator::ExpressionToken)
    .def_prop_ro("opcode", &UnaryOperator::Opcode)
    .def_prop_ro("operator_token", &UnaryOperator::OperatorToken)
    .def_prop_ro("sub_expression", &UnaryOperator::SubExpression)
    .def_prop_ro("has_stored_fp_features", &UnaryOperator::HasStoredFPFeatures)
    .def_prop_ro("is_arithmetic_operation", &UnaryOperator::IsArithmeticOperation)
    .def_prop_ro("is_decrement_operation", &UnaryOperator::IsDecrementOperation)
    .def_prop_ro("is_increment_decrement_operation", &UnaryOperator::IsIncrementDecrementOperation)
    .def_prop_ro("is_increment_operation", &UnaryOperator::IsIncrementOperation)
    .def_prop_ro("is_postfix", &UnaryOperator::IsPostfix)
    .def_prop_ro("is_prefix", &UnaryOperator::IsPrefix);
}
} // namespace pasta
