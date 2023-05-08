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
  py::class_<UnresolvedMemberExpr, OverloadExpr>(m, "UnresolvedMemberExpr")
    .def("__hash__", [](const UnresolvedMemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UnresolvedMemberExpr& a, const UnresolvedMemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &UnresolvedMemberExpr::Children)
    .def_property_readonly("base", &UnresolvedMemberExpr::Base)
    .def_property_readonly("base_type", &UnresolvedMemberExpr::BaseType)
    .def_property_readonly("begin_token", &UnresolvedMemberExpr::BeginToken)
    .def_property_readonly("end_token", &UnresolvedMemberExpr::EndToken)
    .def_property_readonly("expression_token", &UnresolvedMemberExpr::ExpressionToken)
    .def_property_readonly("member_token", &UnresolvedMemberExpr::MemberToken)
    .def_property_readonly("naming_class", &UnresolvedMemberExpr::NamingClass)
    .def_property_readonly("operator_token", &UnresolvedMemberExpr::OperatorToken)
    .def_property_readonly("has_unresolved_using", &UnresolvedMemberExpr::HasUnresolvedUsing)
    .def_property_readonly("is_arrow", &UnresolvedMemberExpr::IsArrow)
    .def_property_readonly("is_implicit_access", &UnresolvedMemberExpr::IsImplicitAccess);
}
} // namespace pasta
