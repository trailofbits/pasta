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
  py::class_<ObjCProtocolExpr, Expr>(m, "ObjCProtocolExpr")
    .def("__hash__", [](const ObjCProtocolExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCProtocolExpr& a, const ObjCProtocolExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCProtocolExpr::Children)
    .def_property_readonly("at_token", &ObjCProtocolExpr::AtToken)
    .def_property_readonly("begin_token", &ObjCProtocolExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCProtocolExpr::EndToken)
    .def_property_readonly("protocol", &ObjCProtocolExpr::Protocol)
    .def_property_readonly("protocol_id_token", &ObjCProtocolExpr::ProtocolIdToken)
    .def_property_readonly("r_paren_token", &ObjCProtocolExpr::RParenToken);
}
} // namespace pasta
