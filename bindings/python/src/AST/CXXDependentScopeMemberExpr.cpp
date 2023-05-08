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

void RegisterCXXDependentScopeMemberExpr(py::module_ &m) {
  py::class_<CXXDependentScopeMemberExpr, Expr>(m, "CXXDependentScopeMemberExpr")
    .def("__hash__", [](const CXXDependentScopeMemberExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDependentScopeMemberExpr& a, const CXXDependentScopeMemberExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXDependentScopeMemberExpr::Children)
    .def_property_readonly("Base", &CXXDependentScopeMemberExpr::Base)
    .def_property_readonly("BaseType", &CXXDependentScopeMemberExpr::BaseType)
    .def_property_readonly("BeginToken", &CXXDependentScopeMemberExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXDependentScopeMemberExpr::EndToken)
    .def_property_readonly("FirstQualifierFoundInScope", &CXXDependentScopeMemberExpr::FirstQualifierFoundInScope)
    .def_property_readonly("LAngleToken", &CXXDependentScopeMemberExpr::LAngleToken)
    .def_property_readonly("MemberToken", &CXXDependentScopeMemberExpr::MemberToken)
    .def_property_readonly("NumTemplateArguments", &CXXDependentScopeMemberExpr::NumTemplateArguments)
    .def_property_readonly("OperatorToken", &CXXDependentScopeMemberExpr::OperatorToken)
    .def_property_readonly("RAngleToken", &CXXDependentScopeMemberExpr::RAngleToken)
    .def_property_readonly("TemplateKeywordToken", &CXXDependentScopeMemberExpr::TemplateKeywordToken)
    .def_property_readonly("HasExplicitTemplateArguments", &CXXDependentScopeMemberExpr::HasExplicitTemplateArguments)
    .def_property_readonly("HasTemplateKeyword", &CXXDependentScopeMemberExpr::HasTemplateKeyword)
    .def_property_readonly("IsArrow", &CXXDependentScopeMemberExpr::IsArrow)
    .def_property_readonly("IsImplicitAccess", &CXXDependentScopeMemberExpr::IsImplicitAccess);
}
} // namespace pasta
