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

void RegisterObjCBridgedCastExpr(py::module_ &m) {
  py::class_<ObjCBridgedCastExpr, CastExpr, ExplicitCastExpr, Expr, Stmt, ValueStmt>(m, "ObjCBridgedCastExpr")
    .def("__hash__", [](const ObjCBridgedCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCBridgedCastExpr& a, const ObjCBridgedCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("BeginToken", &ObjCBridgedCastExpr::BeginToken)
    .def_property_readonly("BridgeKeywordToken", &ObjCBridgedCastExpr::BridgeKeywordToken)
    .def_property_readonly("BridgeKind", &ObjCBridgedCastExpr::BridgeKind)
    .def_property_readonly("BridgeKindName", &ObjCBridgedCastExpr::BridgeKindName)
    .def_property_readonly("EndToken", &ObjCBridgedCastExpr::EndToken)
    .def_property_readonly("LParenToken", &ObjCBridgedCastExpr::LParenToken);
}
} // namespace pasta
