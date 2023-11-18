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

void RegisterAbstractConditionalOperator(nb::module_ &m) {
  nb::class_<AbstractConditionalOperator, Expr>(m, "AbstractConditionalOperator")
    .def_prop_ro("colon_token", &AbstractConditionalOperator::ColonToken)
    .def_prop_ro("condition", &AbstractConditionalOperator::Condition)
    .def_prop_ro("false_expression", &AbstractConditionalOperator::FalseExpression)
    .def_prop_ro("question_token", &AbstractConditionalOperator::QuestionToken)
    .def_prop_ro("true_expression", &AbstractConditionalOperator::TrueExpression);
}
} // namespace pasta
