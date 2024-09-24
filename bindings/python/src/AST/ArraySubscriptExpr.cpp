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

void RegisterArraySubscriptExpr(nb::module_ &m) {
  nb::class_<ArraySubscriptExpr, Expr>(m, "ArraySubscriptExpr")
    .def_prop_ro("children", &ArraySubscriptExpr::Children)
    .def_prop_ro("base", &ArraySubscriptExpr::Base)
    .def_prop_ro("begin_token", &ArraySubscriptExpr::BeginToken)
    .def_prop_ro("end_token", &ArraySubscriptExpr::EndToken)
    .def_prop_ro("expression_token", &ArraySubscriptExpr::ExpressionToken)
    .def_prop_ro("index", &ArraySubscriptExpr::Index)
    .def_prop_ro("lhs", &ArraySubscriptExpr::LHS)
    .def_prop_ro("r_bracket_token", &ArraySubscriptExpr::RBracketToken)
    .def_prop_ro("rhs", &ArraySubscriptExpr::RHS);
}
} // namespace pasta
