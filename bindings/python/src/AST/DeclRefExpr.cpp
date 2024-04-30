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

void RegisterDeclRefExpr(nb::module_ &m) {
  nb::class_<DeclRefExpr, Expr>(m, "DeclRefExpr")
    .def_prop_ro("children", &DeclRefExpr::Children)
    .def_prop_ro("begin_token", &DeclRefExpr::BeginToken)
    .def_prop_ro("declaration", &DeclRefExpr::Declaration)
    .def_prop_ro("end_token", &DeclRefExpr::EndToken)
    .def_prop_ro("found_declaration", &DeclRefExpr::FoundDeclaration)
    .def_prop_ro("l_angle_token", &DeclRefExpr::LAngleToken)
    .def_prop_ro("num_template_arguments", &DeclRefExpr::NumTemplateArguments)
    .def_prop_ro("r_angle_token", &DeclRefExpr::RAngleToken)
    .def_prop_ro("template_keyword_token", &DeclRefExpr::TemplateKeywordToken)
    .def_prop_ro("had_multiple_candidates", &DeclRefExpr::HadMultipleCandidates)
    .def_prop_ro("has_explicit_template_arguments", &DeclRefExpr::HasExplicitTemplateArguments)
    .def_prop_ro("has_qualifier", &DeclRefExpr::HasQualifier)
    .def_prop_ro("has_template_keyword_and_arguments_info", &DeclRefExpr::HasTemplateKeywordAndArgumentsInfo)
    .def_prop_ro("has_template_keyword", &DeclRefExpr::HasTemplateKeyword)
    .def_prop_ro("is_captured_by_copy_in_lambda_with_explicit_object_parameter", &DeclRefExpr::IsCapturedByCopyInLambdaWithExplicitObjectParameter)
    .def_prop_ro("is_immediate_escalating", &DeclRefExpr::IsImmediateEscalating)
    .def_prop_ro("is_non_odr_use", &DeclRefExpr::IsNonOdrUse)
    .def_prop_ro("refers_to_enclosing_variable_or_capture", &DeclRefExpr::RefersToEnclosingVariableOrCapture);
}
} // namespace pasta
