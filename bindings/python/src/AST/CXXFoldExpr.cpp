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

void RegisterCXXFoldExpr(py::module_ &m) {
  py::class_<CXXFoldExpr, Expr>(m, "CXXFoldExpr")
    .def("__hash__", [](const CXXFoldExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXFoldExpr& a, const CXXFoldExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXFoldExpr::Children)
    .def_property_readonly("begin_token", &CXXFoldExpr::BeginToken)
    .def_property_readonly("callee", &CXXFoldExpr::Callee)
    .def_property_readonly("ellipsis_token", &CXXFoldExpr::EllipsisToken)
    .def_property_readonly("end_token", &CXXFoldExpr::EndToken)
    .def_property_readonly("initializer", &CXXFoldExpr::Initializer)
    .def_property_readonly("lhs", &CXXFoldExpr::LHS)
    .def_property_readonly("l_paren_token", &CXXFoldExpr::LParenToken)
    .def_property_readonly("num_expansions", &CXXFoldExpr::NumExpansions)
    .def_property_readonly("operator", &CXXFoldExpr::Operator)
    .def_property_readonly("pattern", &CXXFoldExpr::Pattern)
    .def_property_readonly("rhs", &CXXFoldExpr::RHS)
    .def_property_readonly("r_paren_token", &CXXFoldExpr::RParenToken)
    .def_property_readonly("is_left_fold", &CXXFoldExpr::IsLeftFold)
    .def_property_readonly("is_right_fold", &CXXFoldExpr::IsRightFold);
}
} // namespace pasta
