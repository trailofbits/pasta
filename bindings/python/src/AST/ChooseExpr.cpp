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

void RegisterChooseExpr(py::module_ &m) {
  py::class_<ChooseExpr, Expr>(m, "ChooseExpr")
    .def("__hash__", [](const ChooseExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ChooseExpr& a, const ChooseExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ChooseExpr::Children)
    .def_property_readonly("begin_token", &ChooseExpr::BeginToken)
    .def_property_readonly("builtin_token", &ChooseExpr::BuiltinToken)
    .def_property_readonly("chosen_sub_expression", &ChooseExpr::ChosenSubExpression)
    .def_property_readonly("condition", &ChooseExpr::Condition)
    .def_property_readonly("end_token", &ChooseExpr::EndToken)
    .def_property_readonly("lhs", &ChooseExpr::LHS)
    .def_property_readonly("rhs", &ChooseExpr::RHS)
    .def_property_readonly("r_paren_token", &ChooseExpr::RParenToken)
    .def_property_readonly("is_condition_dependent", &ChooseExpr::IsConditionDependent)
    .def_property_readonly("is_condition_true", &ChooseExpr::IsConditionTrue);
}
} // namespace pasta
