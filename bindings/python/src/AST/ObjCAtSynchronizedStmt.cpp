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

void RegisterObjCAtSynchronizedStmt(nb::module_ &m) {
  nb::class_<ObjCAtSynchronizedStmt, Stmt>(m, "ObjCAtSynchronizedStmt")
    .def_prop_ro("children", &ObjCAtSynchronizedStmt::Children)
    .def_prop_ro("at_synchronized_token", &ObjCAtSynchronizedStmt::AtSynchronizedToken)
    .def_prop_ro("begin_token", &ObjCAtSynchronizedStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAtSynchronizedStmt::EndToken)
    .def_prop_ro("synch_body", &ObjCAtSynchronizedStmt::SynchBody)
    .def_prop_ro("synch_expression", &ObjCAtSynchronizedStmt::SynchExpression);
}
} // namespace pasta
