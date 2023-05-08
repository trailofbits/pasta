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

void RegisterMemberExpr(py::module_ &m) {
  py::class_<MemberExpr, Expr>(m, "MemberExpr")
    .def("__hash__", [](const MemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MemberExpr& a, const MemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &MemberExpr::Children)
    .def_property_readonly("Base", &MemberExpr::Base)
    .def_property_readonly("BeginToken", &MemberExpr::BeginToken)
    .def_property_readonly("EndToken", &MemberExpr::EndToken)
    .def_property_readonly("ExpressionToken", &MemberExpr::ExpressionToken)
    .def_property_readonly("LAngleToken", &MemberExpr::LAngleToken)
    .def_property_readonly("MemberDeclaration", &MemberExpr::MemberDeclaration)
    .def_property_readonly("MemberToken", &MemberExpr::MemberToken)
    .def_property_readonly("NumTemplateArguments", &MemberExpr::NumTemplateArguments)
    .def_property_readonly("OperatorToken", &MemberExpr::OperatorToken)
    .def_property_readonly("RAngleToken", &MemberExpr::RAngleToken)
    .def_property_readonly("TemplateKeywordToken", &MemberExpr::TemplateKeywordToken)
    .def_property_readonly("HadMultipleCandidates", &MemberExpr::HadMultipleCandidates)
    .def_property_readonly("HasExplicitTemplateArguments", &MemberExpr::HasExplicitTemplateArguments)
    .def_property_readonly("HasQualifier", &MemberExpr::HasQualifier)
    .def_property_readonly("HasTemplateKeyword", &MemberExpr::HasTemplateKeyword)
    .def_property_readonly("IsArrow", &MemberExpr::IsArrow)
    .def_property_readonly("IsImplicitAccess", &MemberExpr::IsImplicitAccess)
    .def_property_readonly("IsNonOdrUse", &MemberExpr::IsNonOdrUse);
}
} // namespace pasta
