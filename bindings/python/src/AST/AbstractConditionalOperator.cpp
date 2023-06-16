/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterAbstractConditionalOperator(nb::module_ &m) {
  nb::class_<AbstractConditionalOperator, Expr>(m, "AbstractConditionalOperator")
    .def("__hash__", [](const AbstractConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("colon_token", &AbstractConditionalOperator::ColonToken)
    .def_prop_ro("condition", &AbstractConditionalOperator::Condition)
    .def_prop_ro("false_expression", &AbstractConditionalOperator::FalseExpression)
    .def_prop_ro("question_token", &AbstractConditionalOperator::QuestionToken)
    .def_prop_ro("true_expression", &AbstractConditionalOperator::TrueExpression);
}
} // namespace pasta
