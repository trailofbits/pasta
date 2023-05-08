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

void RegisterUnaryExprOrTypeTraitExpr(py::module_ &m) {
  py::class_<UnaryExprOrTypeTraitExpr, Expr>(m, "UnaryExprOrTypeTraitExpr")
    .def("__hash__", [](const UnaryExprOrTypeTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UnaryExprOrTypeTraitExpr& a, const UnaryExprOrTypeTraitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &UnaryExprOrTypeTraitExpr::Children)
    .def_property_readonly("argument_expression", &UnaryExprOrTypeTraitExpr::ArgumentExpression)
    .def_property_readonly("argument_type", &UnaryExprOrTypeTraitExpr::ArgumentType)
    .def_property_readonly("begin_token", &UnaryExprOrTypeTraitExpr::BeginToken)
    .def_property_readonly("end_token", &UnaryExprOrTypeTraitExpr::EndToken)
    .def_property_readonly("kind", &UnaryExprOrTypeTraitExpr::Kind)
    .def_property_readonly("operator_token", &UnaryExprOrTypeTraitExpr::OperatorToken)
    .def_property_readonly("r_paren_token", &UnaryExprOrTypeTraitExpr::RParenToken)
    .def_property_readonly("type_of_argument", &UnaryExprOrTypeTraitExpr::TypeOfArgument)
    .def_property_readonly("is_argument_type", &UnaryExprOrTypeTraitExpr::IsArgumentType);
}
} // namespace pasta
