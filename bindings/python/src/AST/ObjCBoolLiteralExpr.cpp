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

void RegisterObjCBoolLiteralExpr(py::module_ &m) {
  py::class_<ObjCBoolLiteralExpr, Expr, Stmt, ValueStmt>(m, "ObjCBoolLiteralExpr")
    .def_property_readonly("Children", &ObjCBoolLiteralExpr::Children)
    .def_property_readonly("BeginToken", &ObjCBoolLiteralExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCBoolLiteralExpr::EndToken)
    .def_property_readonly("Token", &ObjCBoolLiteralExpr::Token)
    .def_property_readonly("Value", &ObjCBoolLiteralExpr::Value);
}
} // namespace pasta
