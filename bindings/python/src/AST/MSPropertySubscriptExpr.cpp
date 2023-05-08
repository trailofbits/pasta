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
  py::class_<MSPropertySubscriptExpr, Expr>(m, "MSPropertySubscriptExpr")
    .def("__hash__", [](const MSPropertySubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MSPropertySubscriptExpr& a, const MSPropertySubscriptExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MSPropertySubscriptExpr::Children)
    .def_property_readonly("base", &MSPropertySubscriptExpr::Base)
    .def_property_readonly("begin_token", &MSPropertySubscriptExpr::BeginToken)
    .def_property_readonly("end_token", &MSPropertySubscriptExpr::EndToken)
    .def_property_readonly("expression_token", &MSPropertySubscriptExpr::ExpressionToken)
    .def_property_readonly("index", &MSPropertySubscriptExpr::Index)
    .def_property_readonly("r_bracket_token", &MSPropertySubscriptExpr::RBracketToken);
}
} // namespace pasta
