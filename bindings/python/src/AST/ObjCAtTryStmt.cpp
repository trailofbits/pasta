/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterObjCAtTryStmt(nb::module_ &m) {
  nb::class_<ObjCAtTryStmt, Stmt>(m, "ObjCAtTryStmt")
    .def_prop_ro("children", &ObjCAtTryStmt::Children)
    .def_prop_ro("at_try_token", &ObjCAtTryStmt::AtTryToken)
    .def_prop_ro("begin_token", &ObjCAtTryStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAtTryStmt::EndToken)
    .def_prop_ro("finally_statement", &ObjCAtTryStmt::FinallyStatement)
    .def_prop_ro("num_catch_statements", &ObjCAtTryStmt::NumCatchStatements)
    .def_prop_ro("try_body", &ObjCAtTryStmt::TryBody);
}
} // namespace pasta
