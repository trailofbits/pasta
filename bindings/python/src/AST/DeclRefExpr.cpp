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

void RegisterDeclRefExpr(py::module_ &m) {
  py::class_<DeclRefExpr, Expr>(m, "DeclRefExpr")
    .def("__hash__", [](const DeclRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DeclRefExpr& a, const DeclRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DeclRefExpr::Children)
    .def_property_readonly("begin_token", &DeclRefExpr::BeginToken)
    .def_property_readonly("declaration", &DeclRefExpr::Declaration)
    .def_property_readonly("end_token", &DeclRefExpr::EndToken)
    .def_property_readonly("found_declaration", &DeclRefExpr::FoundDeclaration)
    .def_property_readonly("l_angle_token", &DeclRefExpr::LAngleToken)
    .def_property_readonly("num_template_arguments", &DeclRefExpr::NumTemplateArguments)
    .def_property_readonly("r_angle_token", &DeclRefExpr::RAngleToken)
    .def_property_readonly("template_keyword_token", &DeclRefExpr::TemplateKeywordToken)
    .def_property_readonly("had_multiple_candidates", &DeclRefExpr::HadMultipleCandidates)
    .def_property_readonly("has_explicit_template_arguments", &DeclRefExpr::HasExplicitTemplateArguments)
    .def_property_readonly("has_qualifier", &DeclRefExpr::HasQualifier)
    .def_property_readonly("has_template_keyword_and_arguments_info", &DeclRefExpr::HasTemplateKeywordAndArgumentsInfo)
    .def_property_readonly("has_template_keyword", &DeclRefExpr::HasTemplateKeyword)
    .def_property_readonly("is_non_odr_use", &DeclRefExpr::IsNonOdrUse)
    .def_property_readonly("refers_to_enclosing_variable_or_capture", &DeclRefExpr::RefersToEnclosingVariableOrCapture);
}
} // namespace pasta
