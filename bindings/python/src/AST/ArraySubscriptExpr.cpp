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

void RegisterArraySubscriptExpr(py::module_ &m) {
  py::class_<ArraySubscriptExpr, Expr, Stmt, ValueStmt>(m, "ArraySubscriptExpr")
    .def("__hash__", [](const ArraySubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ArraySubscriptExpr& a, const ArraySubscriptExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ArraySubscriptExpr::Children)
    .def_property_readonly("Base", &ArraySubscriptExpr::Base)
    .def_property_readonly("BeginToken", &ArraySubscriptExpr::BeginToken)
    .def_property_readonly("EndToken", &ArraySubscriptExpr::EndToken)
    .def_property_readonly("ExpressionToken", &ArraySubscriptExpr::ExpressionToken)
    .def_property_readonly("Index", &ArraySubscriptExpr::Index)
    .def_property_readonly("LHS", &ArraySubscriptExpr::LHS)
    .def_property_readonly("RBracketToken", &ArraySubscriptExpr::RBracketToken)
    .def_property_readonly("RHS", &ArraySubscriptExpr::RHS);
}
} // namespace pasta
