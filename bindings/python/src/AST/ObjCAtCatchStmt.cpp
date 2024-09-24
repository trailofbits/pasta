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

void RegisterObjCAtCatchStmt(nb::module_ &m) {
  nb::class_<ObjCAtCatchStmt, Stmt>(m, "ObjCAtCatchStmt")
    .def_prop_ro("children", &ObjCAtCatchStmt::Children)
    .def_prop_ro("at_catch_token", &ObjCAtCatchStmt::AtCatchToken)
    .def_prop_ro("begin_token", &ObjCAtCatchStmt::BeginToken)
    .def_prop_ro("catch_body", &ObjCAtCatchStmt::CatchBody)
    .def_prop_ro("catch_parameter_declaration", &ObjCAtCatchStmt::CatchParameterDeclaration)
    .def_prop_ro("end_token", &ObjCAtCatchStmt::EndToken)
    .def_prop_ro("r_paren_token", &ObjCAtCatchStmt::RParenToken)
    .def_prop_ro("has_ellipsis", &ObjCAtCatchStmt::HasEllipsis);
}
} // namespace pasta
