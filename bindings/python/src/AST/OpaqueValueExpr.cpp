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
  py::class_<OpaqueValueExpr, Expr>(m, "OpaqueValueExpr")
    .def("__hash__", [](const OpaqueValueExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OpaqueValueExpr& a, const OpaqueValueExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &OpaqueValueExpr::Children)
    .def_property_readonly("begin_token", &OpaqueValueExpr::BeginToken)
    .def_property_readonly("end_token", &OpaqueValueExpr::EndToken)
    .def_property_readonly("expression_token", &OpaqueValueExpr::ExpressionToken)
    .def_property_readonly("token", &OpaqueValueExpr::Token)
    .def_property_readonly("source_expression", &OpaqueValueExpr::SourceExpression)
    .def_property_readonly("is_unique", &OpaqueValueExpr::IsUnique);
}
} // namespace pasta
