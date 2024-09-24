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

void RegisterConditionalOperator(nb::module_ &m) {
  nb::class_<ConditionalOperator, AbstractConditionalOperator>(m, "ConditionalOperator")
    .def_prop_ro("children", &ConditionalOperator::Children)
    .def_prop_ro("begin_token", &ConditionalOperator::BeginToken)
    .def_prop_ro("condition", &ConditionalOperator::Condition)
    .def_prop_ro("end_token", &ConditionalOperator::EndToken)
    .def_prop_ro("false_expression", &ConditionalOperator::FalseExpression)
    .def_prop_ro("lhs", &ConditionalOperator::LHS)
    .def_prop_ro("rhs", &ConditionalOperator::RHS)
    .def_prop_ro("true_expression", &ConditionalOperator::TrueExpression);
}
} // namespace pasta
