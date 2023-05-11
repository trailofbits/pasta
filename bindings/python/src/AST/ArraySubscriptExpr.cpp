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

void RegisterArraySubscriptExpr(py::module_ &m) {
  py::class_<ArraySubscriptExpr, Expr>(m, "ArraySubscriptExpr")
    .def("__hash__", [](const ArraySubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ArraySubscriptExpr::Children)
    .def_property_readonly("base", &ArraySubscriptExpr::Base)
    .def_property_readonly("begin_token", &ArraySubscriptExpr::BeginToken)
    .def_property_readonly("end_token", &ArraySubscriptExpr::EndToken)
    .def_property_readonly("expression_token", &ArraySubscriptExpr::ExpressionToken)
    .def_property_readonly("index", &ArraySubscriptExpr::Index)
    .def_property_readonly("lhs", &ArraySubscriptExpr::LHS)
    .def_property_readonly("r_bracket_token", &ArraySubscriptExpr::RBracketToken)
    .def_property_readonly("rhs", &ArraySubscriptExpr::RHS);
}
} // namespace pasta
