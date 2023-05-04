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

void RegisterOpaqueValueExpr(py::module_ &m) {
  py::class_<OpaqueValueExpr, Expr, Stmt, ValueStmt>(m, "OpaqueValueExpr")
    .def("__hash__", [](const OpaqueValueExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OpaqueValueExpr& a, const OpaqueValueExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &OpaqueValueExpr::Children)
    .def_property_readonly("BeginToken", &OpaqueValueExpr::BeginToken)
    .def_property_readonly("EndToken", &OpaqueValueExpr::EndToken)
    .def_property_readonly("ExpressionToken", &OpaqueValueExpr::ExpressionToken)
    .def_property_readonly("Token", &OpaqueValueExpr::Token)
    .def_property_readonly("SourceExpression", &OpaqueValueExpr::SourceExpression)
    .def_property_readonly("IsUnique", &OpaqueValueExpr::IsUnique);
}
} // namespace pasta
