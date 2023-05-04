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

void RegisterDeclRefExpr(py::module_ &m) {
  py::class_<DeclRefExpr, Expr, Stmt, ValueStmt>(m, "DeclRefExpr")
    .def_property_readonly("Children", &DeclRefExpr::Children)
    .def_property_readonly("BeginToken", &DeclRefExpr::BeginToken)
    .def_property_readonly("Declaration", &DeclRefExpr::Declaration)
    .def_property_readonly("EndToken", &DeclRefExpr::EndToken)
    .def_property_readonly("FoundDeclaration", &DeclRefExpr::FoundDeclaration)
    .def_property_readonly("LAngleToken", &DeclRefExpr::LAngleToken)
    .def_property_readonly("NumTemplateArguments", &DeclRefExpr::NumTemplateArguments)
    .def_property_readonly("RAngleToken", &DeclRefExpr::RAngleToken)
    .def_property_readonly("TemplateKeywordToken", &DeclRefExpr::TemplateKeywordToken)
    .def_property_readonly("HadMultipleCandidates", &DeclRefExpr::HadMultipleCandidates)
    .def_property_readonly("HasExplicitTemplateArguments", &DeclRefExpr::HasExplicitTemplateArguments)
    .def_property_readonly("HasQualifier", &DeclRefExpr::HasQualifier)
    .def_property_readonly("HasTemplateKeywordAndArgumentsInfo", &DeclRefExpr::HasTemplateKeywordAndArgumentsInfo)
    .def_property_readonly("HasTemplateKeyword", &DeclRefExpr::HasTemplateKeyword)
    .def_property_readonly("IsNonOdrUse", &DeclRefExpr::IsNonOdrUse)
    .def_property_readonly("RefersToEnclosingVariableOrCapture", &DeclRefExpr::RefersToEnclosingVariableOrCapture);
}
} // namespace pasta
