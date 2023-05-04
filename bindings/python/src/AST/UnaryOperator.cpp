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

void RegisterUnaryOperator(py::module_ &m) {
  py::class_<UnaryOperator, Expr, Stmt, ValueStmt>(m, "UnaryOperator")
    .def("__hash__", [](const UnaryOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UnaryOperator& a, const UnaryOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("CanOverflow", &UnaryOperator::CanOverflow)
    .def_property_readonly("Children", &UnaryOperator::Children)
    .def_property_readonly("BeginToken", &UnaryOperator::BeginToken)
    .def_property_readonly("EndToken", &UnaryOperator::EndToken)
    .def_property_readonly("ExpressionToken", &UnaryOperator::ExpressionToken)
    .def_property_readonly("Opcode", &UnaryOperator::Opcode)
    .def_property_readonly("OperatorToken", &UnaryOperator::OperatorToken)
    .def_property_readonly("SubExpression", &UnaryOperator::SubExpression)
    .def_property_readonly("HasStoredFPFeatures", &UnaryOperator::HasStoredFPFeatures)
    .def_property_readonly("IsArithmeticOperation", &UnaryOperator::IsArithmeticOperation)
    .def_property_readonly("IsDecrementOperation", &UnaryOperator::IsDecrementOperation)
    .def_property_readonly("IsIncrementDecrementOperation", &UnaryOperator::IsIncrementDecrementOperation)
    .def_property_readonly("IsIncrementOperation", &UnaryOperator::IsIncrementOperation)
    .def_property_readonly("IsPostfix", &UnaryOperator::IsPostfix)
    .def_property_readonly("IsPrefix", &UnaryOperator::IsPrefix);
}
} // namespace pasta
