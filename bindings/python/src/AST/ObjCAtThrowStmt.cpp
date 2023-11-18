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

void RegisterObjCAtThrowStmt(nb::module_ &m) {
  nb::class_<ObjCAtThrowStmt, Stmt>(m, "ObjCAtThrowStmt")
    .def_prop_ro("children", &ObjCAtThrowStmt::Children)
    .def_prop_ro("begin_token", &ObjCAtThrowStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAtThrowStmt::EndToken)
    .def_prop_ro("throw_expression", &ObjCAtThrowStmt::ThrowExpression)
    .def_prop_ro("throw_token", &ObjCAtThrowStmt::ThrowToken);
}
} // namespace pasta
