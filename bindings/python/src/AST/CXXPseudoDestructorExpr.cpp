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

void RegisterCXXPseudoDestructorExpr(py::module_ &m) {
  py::class_<CXXPseudoDestructorExpr, Expr>(m, "CXXPseudoDestructorExpr")
    .def("__hash__", [](const CXXPseudoDestructorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXPseudoDestructorExpr& a, const CXXPseudoDestructorExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXPseudoDestructorExpr::Children)
    .def_property_readonly("base", &CXXPseudoDestructorExpr::Base)
    .def_property_readonly("begin_token", &CXXPseudoDestructorExpr::BeginToken)
    .def_property_readonly("colon_colon_token", &CXXPseudoDestructorExpr::ColonColonToken)
    .def_property_readonly("destroyed_type", &CXXPseudoDestructorExpr::DestroyedType)
    .def_property_readonly("destroyed_type_token", &CXXPseudoDestructorExpr::DestroyedTypeToken)
    .def_property_readonly("end_token", &CXXPseudoDestructorExpr::EndToken)
    .def_property_readonly("operator_token", &CXXPseudoDestructorExpr::OperatorToken)
    .def_property_readonly("scope_type", &CXXPseudoDestructorExpr::ScopeType)
    .def_property_readonly("tilde_token", &CXXPseudoDestructorExpr::TildeToken)
    .def_property_readonly("has_qualifier", &CXXPseudoDestructorExpr::HasQualifier)
    .def_property_readonly("is_arrow", &CXXPseudoDestructorExpr::IsArrow);
}
} // namespace pasta
