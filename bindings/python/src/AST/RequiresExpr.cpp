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

void RegisterRequiresExpr(nb::module_ &m) {
  nb::class_<RequiresExpr, Expr>(m, "RequiresExpr")
    .def_prop_ro("children", &RequiresExpr::Children)
    .def_prop_ro("begin_token", &RequiresExpr::BeginToken)
    .def_prop_ro("body", &RequiresExpr::Body)
    .def_prop_ro("end_token", &RequiresExpr::EndToken)
    .def_prop_ro("l_paren_token", &RequiresExpr::LParenToken)
    .def_prop_ro("local_parameters", &RequiresExpr::LocalParameters)
    .def_prop_ro("r_brace_token", &RequiresExpr::RBraceToken)
    .def_prop_ro("r_paren_token", &RequiresExpr::RParenToken)
    .def_prop_ro("requires_keyword_token", &RequiresExpr::RequiresKeywordToken)
    .def_prop_ro("is_satisfied", &RequiresExpr::IsSatisfied);
}
} // namespace pasta
