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

void RegisterObjCBridgedCastExpr(py::module_ &m) {
  py::class_<ObjCBridgedCastExpr, ExplicitCastExpr>(m, "ObjCBridgedCastExpr")
    .def("__hash__", [](const ObjCBridgedCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &ObjCBridgedCastExpr::BeginToken)
    .def_property_readonly("bridge_keyword_token", &ObjCBridgedCastExpr::BridgeKeywordToken)
    .def_property_readonly("bridge_kind", &ObjCBridgedCastExpr::BridgeKind)
    .def_property_readonly("bridge_kind_name", &ObjCBridgedCastExpr::BridgeKindName)
    .def_property_readonly("end_token", &ObjCBridgedCastExpr::EndToken)
    .def_property_readonly("l_paren_token", &ObjCBridgedCastExpr::LParenToken);
}
} // namespace pasta
