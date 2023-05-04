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

void RegisterObjCProtocolExpr(py::module_ &m) {
  py::class_<ObjCProtocolExpr, Expr, Stmt, ValueStmt>(m, "ObjCProtocolExpr")
    .def_property_readonly("Children", &ObjCProtocolExpr::Children)
    .def_property_readonly("AtToken", &ObjCProtocolExpr::AtToken)
    .def_property_readonly("BeginToken", &ObjCProtocolExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCProtocolExpr::EndToken)
    .def_property_readonly("Protocol", &ObjCProtocolExpr::Protocol)
    .def_property_readonly("ProtocolIdToken", &ObjCProtocolExpr::ProtocolIdToken)
    .def_property_readonly("RParenToken", &ObjCProtocolExpr::RParenToken);
}
} // namespace pasta
