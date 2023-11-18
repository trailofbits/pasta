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

void RegisterObjCForCollectionStmt(nb::module_ &m) {
  nb::class_<ObjCForCollectionStmt, Stmt>(m, "ObjCForCollectionStmt")
    .def_prop_ro("children", &ObjCForCollectionStmt::Children)
    .def_prop_ro("begin_token", &ObjCForCollectionStmt::BeginToken)
    .def_prop_ro("body", &ObjCForCollectionStmt::Body)
    .def_prop_ro("collection", &ObjCForCollectionStmt::Collection)
    .def_prop_ro("element", &ObjCForCollectionStmt::Element)
    .def_prop_ro("end_token", &ObjCForCollectionStmt::EndToken)
    .def_prop_ro("for_token", &ObjCForCollectionStmt::ForToken)
    .def_prop_ro("r_paren_token", &ObjCForCollectionStmt::RParenToken);
}
} // namespace pasta
