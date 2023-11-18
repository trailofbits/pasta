/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXDependentScopeMemberExpr(nb::module_ &m) {
  nb::class_<CXXDependentScopeMemberExpr, Expr>(m, "CXXDependentScopeMemberExpr")
    .def_prop_ro("children", &CXXDependentScopeMemberExpr::Children)
    .def_prop_ro("base", &CXXDependentScopeMemberExpr::Base)
    .def_prop_ro("base_type", &CXXDependentScopeMemberExpr::BaseType)
    .def_prop_ro("begin_token", &CXXDependentScopeMemberExpr::BeginToken)
    .def_prop_ro("end_token", &CXXDependentScopeMemberExpr::EndToken)
    .def_prop_ro("first_qualifier_found_in_scope", &CXXDependentScopeMemberExpr::FirstQualifierFoundInScope)
    .def_prop_ro("l_angle_token", &CXXDependentScopeMemberExpr::LAngleToken)
    .def_prop_ro("member_token", &CXXDependentScopeMemberExpr::MemberToken)
    .def_prop_ro("num_template_arguments", &CXXDependentScopeMemberExpr::NumTemplateArguments)
    .def_prop_ro("operator_token", &CXXDependentScopeMemberExpr::OperatorToken)
    .def_prop_ro("r_angle_token", &CXXDependentScopeMemberExpr::RAngleToken)
    .def_prop_ro("template_keyword_token", &CXXDependentScopeMemberExpr::TemplateKeywordToken)
    .def_prop_ro("has_explicit_template_arguments", &CXXDependentScopeMemberExpr::HasExplicitTemplateArguments)
    .def_prop_ro("has_template_keyword", &CXXDependentScopeMemberExpr::HasTemplateKeyword)
    .def_prop_ro("is_arrow", &CXXDependentScopeMemberExpr::IsArrow)
    .def_prop_ro("is_implicit_access", &CXXDependentScopeMemberExpr::IsImplicitAccess);
}
} // namespace pasta
