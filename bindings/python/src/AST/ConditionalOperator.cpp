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

void RegisterConditionalOperator(py::module_ &m) {
  py::class_<ConditionalOperator, AbstractConditionalOperator>(m, "ConditionalOperator")
    .def("__hash__", [](const ConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ConditionalOperator::Children)
    .def_property_readonly("begin_token", &ConditionalOperator::BeginToken)
    .def_property_readonly("condition", &ConditionalOperator::Condition)
    .def_property_readonly("end_token", &ConditionalOperator::EndToken)
    .def_property_readonly("false_expression", &ConditionalOperator::FalseExpression)
    .def_property_readonly("lhs", &ConditionalOperator::LHS)
    .def_property_readonly("rhs", &ConditionalOperator::RHS)
    .def_property_readonly("true_expression", &ConditionalOperator::TrueExpression);
}
} // namespace pasta
