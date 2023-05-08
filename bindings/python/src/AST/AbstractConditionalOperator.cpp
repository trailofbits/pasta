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

void RegisterAbstractConditionalOperator(py::module_ &m) {
  py::class_<AbstractConditionalOperator, Expr>(m, "AbstractConditionalOperator")
    .def("__hash__", [](const AbstractConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AbstractConditionalOperator& a, const AbstractConditionalOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("ColonToken", &AbstractConditionalOperator::ColonToken)
    .def_property_readonly("Condition", &AbstractConditionalOperator::Condition)
    .def_property_readonly("FalseExpression", &AbstractConditionalOperator::FalseExpression)
    .def_property_readonly("QuestionToken", &AbstractConditionalOperator::QuestionToken)
    .def_property_readonly("TrueExpression", &AbstractConditionalOperator::TrueExpression);
}
} // namespace pasta
