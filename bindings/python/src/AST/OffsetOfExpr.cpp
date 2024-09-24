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

void RegisterOffsetOfExpr(nb::module_ &m) {
  nb::class_<OffsetOfExpr, Expr>(m, "OffsetOfExpr")
    .def_prop_ro("children", &OffsetOfExpr::Children)
    .def_prop_ro("begin_token", &OffsetOfExpr::BeginToken)
    .def_prop_ro("end_token", &OffsetOfExpr::EndToken)
    .def_prop_ro("num_components", &OffsetOfExpr::NumComponents)
    .def_prop_ro("num_expressions", &OffsetOfExpr::NumExpressions)
    .def_prop_ro("operator_token", &OffsetOfExpr::OperatorToken)
    .def_prop_ro("r_paren_token", &OffsetOfExpr::RParenToken);
}
} // namespace pasta
