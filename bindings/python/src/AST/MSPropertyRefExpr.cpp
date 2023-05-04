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

void RegisterMSPropertyRefExpr(py::module_ &m) {
  py::class_<MSPropertyRefExpr, Expr, Stmt, ValueStmt>(m, "MSPropertyRefExpr")
    .def_property_readonly("Children", &MSPropertyRefExpr::Children)
    .def_property_readonly("BaseExpression", &MSPropertyRefExpr::BaseExpression)
    .def_property_readonly("BeginToken", &MSPropertyRefExpr::BeginToken)
    .def_property_readonly("EndToken", &MSPropertyRefExpr::EndToken)
    .def_property_readonly("MemberToken", &MSPropertyRefExpr::MemberToken)
    .def_property_readonly("PropertyDeclaration", &MSPropertyRefExpr::PropertyDeclaration)
    .def_property_readonly("Tokens", &MSPropertyRefExpr::Tokens)
    .def_property_readonly("IsArrow", &MSPropertyRefExpr::IsArrow)
    .def_property_readonly("IsImplicitAccess", &MSPropertyRefExpr::IsImplicitAccess);
}
} // namespace pasta
