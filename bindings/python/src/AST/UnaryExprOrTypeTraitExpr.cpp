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
    .def_property_readonly("Children", &UnaryExprOrTypeTraitExpr::Children)
    .def_property_readonly("ArgumentExpression", &UnaryExprOrTypeTraitExpr::ArgumentExpression)
    .def_property_readonly("ArgumentType", &UnaryExprOrTypeTraitExpr::ArgumentType)
    .def_property_readonly("BeginToken", &UnaryExprOrTypeTraitExpr::BeginToken)
    .def_property_readonly("EndToken", &UnaryExprOrTypeTraitExpr::EndToken)
    .def_property_readonly("Kind", &UnaryExprOrTypeTraitExpr::Kind)
    .def_property_readonly("OperatorToken", &UnaryExprOrTypeTraitExpr::OperatorToken)
    .def_property_readonly("RParenToken", &UnaryExprOrTypeTraitExpr::RParenToken)
    .def_property_readonly("TypeOfArgument", &UnaryExprOrTypeTraitExpr::TypeOfArgument)
    .def_property_readonly("IsArgumentType", &UnaryExprOrTypeTraitExpr::IsArgumentType);
}
} // namespace pasta
