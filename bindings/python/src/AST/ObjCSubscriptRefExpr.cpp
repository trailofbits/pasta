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

void RegisterObjCSubscriptRefExpr(py::module_ &m) {
  py::class_<ObjCSubscriptRefExpr, Expr, Stmt, ValueStmt>(m, "ObjCSubscriptRefExpr")
    .def_property_readonly("Children", &ObjCSubscriptRefExpr::Children)
    .def_property_readonly("AtIndexMethodDeclaration", &ObjCSubscriptRefExpr::AtIndexMethodDeclaration)
    .def_property_readonly("BaseExpression", &ObjCSubscriptRefExpr::BaseExpression)
    .def_property_readonly("BeginToken", &ObjCSubscriptRefExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCSubscriptRefExpr::EndToken)
    .def_property_readonly("KeyExpression", &ObjCSubscriptRefExpr::KeyExpression)
    .def_property_readonly("RBracketToken", &ObjCSubscriptRefExpr::RBracketToken)
    .def_property_readonly("IsArraySubscriptReferenceExpression", &ObjCSubscriptRefExpr::IsArraySubscriptReferenceExpression);
}
} // namespace pasta
