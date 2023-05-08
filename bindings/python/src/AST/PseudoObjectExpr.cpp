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

void RegisterPseudoObjectExpr(py::module_ &m) {
  py::class_<PseudoObjectExpr, Expr>(m, "PseudoObjectExpr")
    .def("__hash__", [](const PseudoObjectExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const PseudoObjectExpr& a, const PseudoObjectExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &PseudoObjectExpr::Children)
    .def_property_readonly("BeginToken", &PseudoObjectExpr::BeginToken)
    .def_property_readonly("EndToken", &PseudoObjectExpr::EndToken)
    .def_property_readonly("ExpressionToken", &PseudoObjectExpr::ExpressionToken)
    .def_property_readonly("NumSemanticExpressions", &PseudoObjectExpr::NumSemanticExpressions)
    .def_property_readonly("ResultExpression", &PseudoObjectExpr::ResultExpression)
    .def_property_readonly("ResultExpressionIndex", &PseudoObjectExpr::ResultExpressionIndex)
    .def_property_readonly("SyntacticForm", &PseudoObjectExpr::SyntacticForm)
    .def_property_readonly("Semantics", &PseudoObjectExpr::Semantics);
}
} // namespace pasta
