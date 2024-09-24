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

void RegisterObjCBoxedExpr(nb::module_ &m) {
  nb::class_<ObjCBoxedExpr, Expr>(m, "ObjCBoxedExpr")
    .def_prop_ro("children", &ObjCBoxedExpr::Children)
    .def_prop_ro("at_token", &ObjCBoxedExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCBoxedExpr::BeginToken)
    .def_prop_ro("boxing_method", &ObjCBoxedExpr::BoxingMethod)
    .def_prop_ro("end_token", &ObjCBoxedExpr::EndToken)
    .def_prop_ro("tokens", &ObjCBoxedExpr::Tokens)
    .def_prop_ro("sub_expression", &ObjCBoxedExpr::SubExpression)
    .def_prop_ro("is_expressible_as_constant_initializer", &ObjCBoxedExpr::IsExpressibleAsConstantInitializer);
}
} // namespace pasta
