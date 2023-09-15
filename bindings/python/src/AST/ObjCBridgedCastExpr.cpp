/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCBridgedCastExpr(nb::module_ &m) {
  nb::class_<ObjCBridgedCastExpr, ExplicitCastExpr>(m, "ObjCBridgedCastExpr")
    .def("__hash__", [](const ObjCBridgedCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &ObjCBridgedCastExpr::BeginToken)
    .def_prop_ro("bridge_keyword_token", &ObjCBridgedCastExpr::BridgeKeywordToken)
    .def_prop_ro("bridge_kind", &ObjCBridgedCastExpr::BridgeKind)
    .def_prop_ro("bridge_kind_name", &ObjCBridgedCastExpr::BridgeKindName)
    .def_prop_ro("end_token", &ObjCBridgedCastExpr::EndToken)
    .def_prop_ro("l_paren_token", &ObjCBridgedCastExpr::LParenToken);
}
} // namespace pasta
