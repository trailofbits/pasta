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

void RegisterUnresolvedMemberExpr(py::module_ &m) {
  py::class_<UnresolvedMemberExpr, Expr, OverloadExpr, Stmt, ValueStmt>(m, "UnresolvedMemberExpr")
    .def("__hash__", [](const UnresolvedMemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UnresolvedMemberExpr& a, const UnresolvedMemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &UnresolvedMemberExpr::Children)
    .def_property_readonly("Base", &UnresolvedMemberExpr::Base)
    .def_property_readonly("BaseType", &UnresolvedMemberExpr::BaseType)
    .def_property_readonly("BeginToken", &UnresolvedMemberExpr::BeginToken)
    .def_property_readonly("EndToken", &UnresolvedMemberExpr::EndToken)
    .def_property_readonly("ExpressionToken", &UnresolvedMemberExpr::ExpressionToken)
    .def_property_readonly("MemberToken", &UnresolvedMemberExpr::MemberToken)
    .def_property_readonly("NamingClass", &UnresolvedMemberExpr::NamingClass)
    .def_property_readonly("OperatorToken", &UnresolvedMemberExpr::OperatorToken)
    .def_property_readonly("HasUnresolvedUsing", &UnresolvedMemberExpr::HasUnresolvedUsing)
    .def_property_readonly("IsArrow", &UnresolvedMemberExpr::IsArrow)
    .def_property_readonly("IsImplicitAccess", &UnresolvedMemberExpr::IsImplicitAccess);
}
} // namespace pasta
