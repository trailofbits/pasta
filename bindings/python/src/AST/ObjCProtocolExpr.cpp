/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCProtocolExpr(nb::module_ &m) {
  nb::class_<ObjCProtocolExpr, Expr>(m, "ObjCProtocolExpr")
    .def("__hash__", [](const ObjCProtocolExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCProtocolExpr::Children)
    .def_prop_ro("at_token", &ObjCProtocolExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCProtocolExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCProtocolExpr::EndToken)
    .def_prop_ro("protocol", &ObjCProtocolExpr::Protocol)
    .def_prop_ro("protocol_id_token", &ObjCProtocolExpr::ProtocolIdToken)
    .def_prop_ro("r_paren_token", &ObjCProtocolExpr::RParenToken);
}
} // namespace pasta
