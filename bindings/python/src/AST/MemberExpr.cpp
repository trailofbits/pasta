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

void RegisterMemberExpr(py::module_ &m) {
  py::class_<MemberExpr, Expr>(m, "MemberExpr")
    .def("__hash__", [](const MemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MemberExpr& a, const MemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MemberExpr::Children)
    .def_property_readonly("base", &MemberExpr::Base)
    .def_property_readonly("begin_token", &MemberExpr::BeginToken)
    .def_property_readonly("end_token", &MemberExpr::EndToken)
    .def_property_readonly("expression_token", &MemberExpr::ExpressionToken)
    .def_property_readonly("l_angle_token", &MemberExpr::LAngleToken)
    .def_property_readonly("member_declaration", &MemberExpr::MemberDeclaration)
    .def_property_readonly("member_token", &MemberExpr::MemberToken)
    .def_property_readonly("num_template_arguments", &MemberExpr::NumTemplateArguments)
    .def_property_readonly("operator_token", &MemberExpr::OperatorToken)
    .def_property_readonly("r_angle_token", &MemberExpr::RAngleToken)
    .def_property_readonly("template_keyword_token", &MemberExpr::TemplateKeywordToken)
    .def_property_readonly("had_multiple_candidates", &MemberExpr::HadMultipleCandidates)
    .def_property_readonly("has_explicit_template_arguments", &MemberExpr::HasExplicitTemplateArguments)
    .def_property_readonly("has_qualifier", &MemberExpr::HasQualifier)
    .def_property_readonly("has_template_keyword", &MemberExpr::HasTemplateKeyword)
    .def_property_readonly("is_arrow", &MemberExpr::IsArrow)
    .def_property_readonly("is_implicit_access", &MemberExpr::IsImplicitAccess)
    .def_property_readonly("is_non_odr_use", &MemberExpr::IsNonOdrUse);
}
} // namespace pasta
