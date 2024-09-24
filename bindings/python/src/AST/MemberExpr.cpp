/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterMemberExpr(nb::module_ &m) {
  nb::class_<MemberExpr, Expr>(m, "MemberExpr")
    .def_prop_ro("children", &MemberExpr::Children)
    .def_prop_ro("base", &MemberExpr::Base)
    .def_prop_ro("begin_token", &MemberExpr::BeginToken)
    .def_prop_ro("end_token", &MemberExpr::EndToken)
    .def_prop_ro("expression_token", &MemberExpr::ExpressionToken)
    .def_prop_ro("l_angle_token", &MemberExpr::LAngleToken)
    .def_prop_ro("member_declaration", &MemberExpr::MemberDeclaration)
    .def_prop_ro("member_token", &MemberExpr::MemberToken)
    .def_prop_ro("num_template_arguments", &MemberExpr::NumTemplateArguments)
    .def_prop_ro("operator_token", &MemberExpr::OperatorToken)
    .def_prop_ro("r_angle_token", &MemberExpr::RAngleToken)
    .def_prop_ro("template_keyword_token", &MemberExpr::TemplateKeywordToken)
    .def_prop_ro("had_multiple_candidates", &MemberExpr::HadMultipleCandidates)
    .def_prop_ro("has_explicit_template_arguments", &MemberExpr::HasExplicitTemplateArguments)
    .def_prop_ro("has_qualifier", &MemberExpr::HasQualifier)
    .def_prop_ro("has_template_keyword", &MemberExpr::HasTemplateKeyword)
    .def_prop_ro("is_arrow", &MemberExpr::IsArrow)
    .def_prop_ro("is_implicit_access", &MemberExpr::IsImplicitAccess)
    .def_prop_ro("is_non_odr_use", &MemberExpr::IsNonOdrUse);
}
} // namespace pasta
