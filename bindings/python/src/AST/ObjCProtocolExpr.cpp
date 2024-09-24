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

void RegisterObjCProtocolExpr(nb::module_ &m) {
  nb::class_<ObjCProtocolExpr, Expr>(m, "ObjCProtocolExpr")
    .def_prop_ro("children", &ObjCProtocolExpr::Children)
    .def_prop_ro("at_token", &ObjCProtocolExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCProtocolExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCProtocolExpr::EndToken)
    .def_prop_ro("protocol", &ObjCProtocolExpr::Protocol)
    .def_prop_ro("protocol_id_token", &ObjCProtocolExpr::ProtocolIdToken)
    .def_prop_ro("r_paren_token", &ObjCProtocolExpr::RParenToken);
}
} // namespace pasta
