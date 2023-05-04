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

void RegisterConditionalOperator(py::module_ &m) {
  py::class_<ConditionalOperator, AbstractConditionalOperator, Expr, Stmt, ValueStmt>(m, "ConditionalOperator")
    .def("__hash__", [](const ConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ConditionalOperator& a, const ConditionalOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ConditionalOperator::Children)
    .def_property_readonly("BeginToken", &ConditionalOperator::BeginToken)
    .def_property_readonly("Condition", &ConditionalOperator::Condition)
    .def_property_readonly("EndToken", &ConditionalOperator::EndToken)
    .def_property_readonly("FalseExpression", &ConditionalOperator::FalseExpression)
    .def_property_readonly("LHS", &ConditionalOperator::LHS)
    .def_property_readonly("RHS", &ConditionalOperator::RHS)
    .def_property_readonly("TrueExpression", &ConditionalOperator::TrueExpression);
}
} // namespace pasta
