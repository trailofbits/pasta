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

void RegisterBinaryConditionalOperator(py::module_ &m) {
  py::class_<BinaryConditionalOperator, AbstractConditionalOperator>(m, "BinaryConditionalOperator")
    .def("__hash__", [](const BinaryConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const BinaryConditionalOperator& a, const BinaryConditionalOperator& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &BinaryConditionalOperator::Children)
    .def_property_readonly("BeginToken", &BinaryConditionalOperator::BeginToken)
    .def_property_readonly("Common", &BinaryConditionalOperator::Common)
    .def_property_readonly("Condition", &BinaryConditionalOperator::Condition)
    .def_property_readonly("EndToken", &BinaryConditionalOperator::EndToken)
    .def_property_readonly("FalseExpression", &BinaryConditionalOperator::FalseExpression)
    .def_property_readonly("OpaqueValue", &BinaryConditionalOperator::OpaqueValue)
    .def_property_readonly("TrueExpression", &BinaryConditionalOperator::TrueExpression);
}
} // namespace pasta
