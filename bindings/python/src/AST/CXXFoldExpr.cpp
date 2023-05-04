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

void RegisterCXXFoldExpr(py::module_ &m) {
  py::class_<CXXFoldExpr, Expr, Stmt, ValueStmt>(m, "CXXFoldExpr")
    .def("__hash__", [](const CXXFoldExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXFoldExpr& a, const CXXFoldExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXFoldExpr::Children)
    .def_property_readonly("BeginToken", &CXXFoldExpr::BeginToken)
    .def_property_readonly("Callee", &CXXFoldExpr::Callee)
    .def_property_readonly("EllipsisToken", &CXXFoldExpr::EllipsisToken)
    .def_property_readonly("EndToken", &CXXFoldExpr::EndToken)
    .def_property_readonly("Initializer", &CXXFoldExpr::Initializer)
    .def_property_readonly("LHS", &CXXFoldExpr::LHS)
    .def_property_readonly("LParenToken", &CXXFoldExpr::LParenToken)
    .def_property_readonly("NumExpansions", &CXXFoldExpr::NumExpansions)
    .def_property_readonly("Operator", &CXXFoldExpr::Operator)
    .def_property_readonly("Pattern", &CXXFoldExpr::Pattern)
    .def_property_readonly("RHS", &CXXFoldExpr::RHS)
    .def_property_readonly("RParenToken", &CXXFoldExpr::RParenToken)
    .def_property_readonly("IsLeftFold", &CXXFoldExpr::IsLeftFold)
    .def_property_readonly("IsRightFold", &CXXFoldExpr::IsRightFold);
}
} // namespace pasta
