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

void RegisterPseudoObjectExpr(py::module_ &m) {
  py::class_<PseudoObjectExpr, Expr>(m, "PseudoObjectExpr")
    .def("__hash__", [](const PseudoObjectExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &PseudoObjectExpr::Children)
    .def_property_readonly("begin_token", &PseudoObjectExpr::BeginToken)
    .def_property_readonly("end_token", &PseudoObjectExpr::EndToken)
    .def_property_readonly("expression_token", &PseudoObjectExpr::ExpressionToken)
    .def_property_readonly("num_semantic_expressions", &PseudoObjectExpr::NumSemanticExpressions)
    .def_property_readonly("result_expression", &PseudoObjectExpr::ResultExpression)
    .def_property_readonly("result_expression_index", &PseudoObjectExpr::ResultExpressionIndex)
    .def_property_readonly("syntactic_form", &PseudoObjectExpr::SyntacticForm)
    .def_property_readonly("semantics", &PseudoObjectExpr::Semantics);
}
} // namespace pasta
