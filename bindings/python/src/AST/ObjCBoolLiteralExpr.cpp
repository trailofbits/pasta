/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCBoolLiteralExpr(nb::module_ &m) {
  nb::class_<ObjCBoolLiteralExpr, Expr>(m, "ObjCBoolLiteralExpr")
    .def_prop_ro("children", &ObjCBoolLiteralExpr::Children)
    .def_prop_ro("begin_token", &ObjCBoolLiteralExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCBoolLiteralExpr::EndToken)
    .def_prop_ro("token", &ObjCBoolLiteralExpr::Token)
    .def_prop_ro("value", &ObjCBoolLiteralExpr::Value);
}
} // namespace pasta
