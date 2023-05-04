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

void RegisterCXXPseudoDestructorExpr(py::module_ &m) {
  py::class_<CXXPseudoDestructorExpr, Expr, Stmt, ValueStmt>(m, "CXXPseudoDestructorExpr")
    .def_property_readonly("Children", &CXXPseudoDestructorExpr::Children)
    .def_property_readonly("Base", &CXXPseudoDestructorExpr::Base)
    .def_property_readonly("BeginToken", &CXXPseudoDestructorExpr::BeginToken)
    .def_property_readonly("ColonColonToken", &CXXPseudoDestructorExpr::ColonColonToken)
    .def_property_readonly("DestroyedType", &CXXPseudoDestructorExpr::DestroyedType)
    .def_property_readonly("DestroyedTypeToken", &CXXPseudoDestructorExpr::DestroyedTypeToken)
    .def_property_readonly("EndToken", &CXXPseudoDestructorExpr::EndToken)
    .def_property_readonly("OperatorToken", &CXXPseudoDestructorExpr::OperatorToken)
    .def_property_readonly("ScopeType", &CXXPseudoDestructorExpr::ScopeType)
    .def_property_readonly("TildeToken", &CXXPseudoDestructorExpr::TildeToken)
    .def_property_readonly("HasQualifier", &CXXPseudoDestructorExpr::HasQualifier)
    .def_property_readonly("IsArrow", &CXXPseudoDestructorExpr::IsArrow);
}
} // namespace pasta
