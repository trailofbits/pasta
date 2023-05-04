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
  py::class_<ChooseExpr, Expr, Stmt, ValueStmt>(m, "ChooseExpr")
    .def_property_readonly("Children", &ChooseExpr::Children)
    .def_property_readonly("BeginToken", &ChooseExpr::BeginToken)
    .def_property_readonly("BuiltinToken", &ChooseExpr::BuiltinToken)
    .def_property_readonly("ChosenSubExpression", &ChooseExpr::ChosenSubExpression)
    .def_property_readonly("Condition", &ChooseExpr::Condition)
    .def_property_readonly("EndToken", &ChooseExpr::EndToken)
    .def_property_readonly("LHS", &ChooseExpr::LHS)
    .def_property_readonly("RHS", &ChooseExpr::RHS)
    .def_property_readonly("RParenToken", &ChooseExpr::RParenToken)
    .def_property_readonly("IsConditionDependent", &ChooseExpr::IsConditionDependent)
    .def_property_readonly("IsConditionTrue", &ChooseExpr::IsConditionTrue);
}
} // namespace pasta
