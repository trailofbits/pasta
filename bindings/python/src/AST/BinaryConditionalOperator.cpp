/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterBinaryConditionalOperator(nb::module_ &m) {
  nb::class_<BinaryConditionalOperator, AbstractConditionalOperator>(m, "BinaryConditionalOperator")
    .def("__hash__", [](const BinaryConditionalOperator& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &BinaryConditionalOperator::Children)
    .def_prop_ro("begin_token", &BinaryConditionalOperator::BeginToken)
    .def_prop_ro("common", &BinaryConditionalOperator::Common)
    .def_prop_ro("condition", &BinaryConditionalOperator::Condition)
    .def_prop_ro("end_token", &BinaryConditionalOperator::EndToken)
    .def_prop_ro("false_expression", &BinaryConditionalOperator::FalseExpression)
    .def_prop_ro("opaque_value", &BinaryConditionalOperator::OpaqueValue)
    .def_prop_ro("true_expression", &BinaryConditionalOperator::TrueExpression);
}
} // namespace pasta
