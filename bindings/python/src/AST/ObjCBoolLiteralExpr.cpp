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

void RegisterObjCBoolLiteralExpr(nb::module_ &m) {
  nb::class_<ObjCBoolLiteralExpr, Expr>(m, "ObjCBoolLiteralExpr")
    .def("__hash__", [](const ObjCBoolLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCBoolLiteralExpr::Children)
    .def_prop_ro("begin_token", &ObjCBoolLiteralExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCBoolLiteralExpr::EndToken)
    .def_prop_ro("token", &ObjCBoolLiteralExpr::Token)
    .def_prop_ro("value", &ObjCBoolLiteralExpr::Value);
}
} // namespace pasta
