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

void RegisterObjCSubscriptRefExpr(nb::module_ &m) {
  nb::class_<ObjCSubscriptRefExpr, Expr>(m, "ObjCSubscriptRefExpr")
    .def_prop_ro("children", &ObjCSubscriptRefExpr::Children)
    .def_prop_ro("at_index_method_declaration", &ObjCSubscriptRefExpr::AtIndexMethodDeclaration)
    .def_prop_ro("base_expression", &ObjCSubscriptRefExpr::BaseExpression)
    .def_prop_ro("begin_token", &ObjCSubscriptRefExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCSubscriptRefExpr::EndToken)
    .def_prop_ro("key_expression", &ObjCSubscriptRefExpr::KeyExpression)
    .def_prop_ro("r_bracket_token", &ObjCSubscriptRefExpr::RBracketToken)
    .def_prop_ro("is_array_subscript_reference_expression", &ObjCSubscriptRefExpr::IsArraySubscriptReferenceExpression);
}
} // namespace pasta
