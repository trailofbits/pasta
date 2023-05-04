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

void RegisterMSPropertySubscriptExpr(py::module_ &m) {
  py::class_<MSPropertySubscriptExpr, Expr, Stmt, ValueStmt>(m, "MSPropertySubscriptExpr")
    .def("__hash__", [](const MSPropertySubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MSPropertySubscriptExpr& a, const MSPropertySubscriptExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &MSPropertySubscriptExpr::Children)
    .def_property_readonly("Base", &MSPropertySubscriptExpr::Base)
    .def_property_readonly("BeginToken", &MSPropertySubscriptExpr::BeginToken)
    .def_property_readonly("EndToken", &MSPropertySubscriptExpr::EndToken)
    .def_property_readonly("ExpressionToken", &MSPropertySubscriptExpr::ExpressionToken)
    .def_property_readonly("Index", &MSPropertySubscriptExpr::Index)
    .def_property_readonly("RBracketToken", &MSPropertySubscriptExpr::RBracketToken);
}
} // namespace pasta
