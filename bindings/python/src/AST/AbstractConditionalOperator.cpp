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

void RegisterAbstractConditionalOperator(py::module_ &m) {
  py::class_<AbstractConditionalOperator, Expr>(m, "AbstractConditionalOperator")
    .def("__hash__", [](const AbstractConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AbstractConditionalOperator& a, const AbstractConditionalOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("colon_token", &AbstractConditionalOperator::ColonToken)
    .def_property_readonly("condition", &AbstractConditionalOperator::Condition)
    .def_property_readonly("false_expression", &AbstractConditionalOperator::FalseExpression)
    .def_property_readonly("question_token", &AbstractConditionalOperator::QuestionToken)
    .def_property_readonly("true_expression", &AbstractConditionalOperator::TrueExpression);
}
} // namespace pasta
