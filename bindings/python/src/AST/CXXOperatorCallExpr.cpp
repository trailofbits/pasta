/*
 * Copyright (c) 2023 Trail of Bits, Inc.
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

void RegisterCXXOperatorCallExpr(nb::module_ &m) {
  nb::class_<CXXOperatorCallExpr, CallExpr>(m, "CXXOperatorCallExpr")
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
