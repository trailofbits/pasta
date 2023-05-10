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

void RegisterCXXDependentScopeMemberExpr(py::module_ &m) {
  py::class_<CXXDependentScopeMemberExpr, Expr>(m, "CXXDependentScopeMemberExpr")
    .def("__hash__", [](const CXXDependentScopeMemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDependentScopeMemberExpr& a, const CXXDependentScopeMemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXDependentScopeMemberExpr::Children)
    .def_property_readonly("base", &CXXDependentScopeMemberExpr::Base)
    .def_property_readonly("base_type", &CXXDependentScopeMemberExpr::BaseType)
    .def_property_readonly("begin_token", &CXXDependentScopeMemberExpr::BeginToken)
    .def_property_readonly("end_token", &CXXDependentScopeMemberExpr::EndToken)
    .def_property_readonly("first_qualifier_found_in_scope", &CXXDependentScopeMemberExpr::FirstQualifierFoundInScope)
    .def_property_readonly("l_angle_token", &CXXDependentScopeMemberExpr::LAngleToken)
    .def_property_readonly("member_token", &CXXDependentScopeMemberExpr::MemberToken)
    .def_property_readonly("num_template_arguments", &CXXDependentScopeMemberExpr::NumTemplateArguments)
    .def_property_readonly("operator_token", &CXXDependentScopeMemberExpr::OperatorToken)
    .def_property_readonly("r_angle_token", &CXXDependentScopeMemberExpr::RAngleToken)
    .def_property_readonly("template_keyword_token", &CXXDependentScopeMemberExpr::TemplateKeywordToken)
    .def_property_readonly("has_explicit_template_arguments", &CXXDependentScopeMemberExpr::HasExplicitTemplateArguments)
    .def_property_readonly("has_template_keyword", &CXXDependentScopeMemberExpr::HasTemplateKeyword)
    .def_property_readonly("is_arrow", &CXXDependentScopeMemberExpr::IsArrow)
    .def_property_readonly("is_implicit_access", &CXXDependentScopeMemberExpr::IsImplicitAccess);
}
} // namespace pasta
