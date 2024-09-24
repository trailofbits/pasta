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

void RegisterSizeOfPackExpr(nb::module_ &m) {
  nb::class_<SizeOfPackExpr, Expr>(m, "SizeOfPackExpr")
    .def_prop_ro("children", &SizeOfPackExpr::Children)
    .def_prop_ro("begin_token", &SizeOfPackExpr::BeginToken)
    .def_prop_ro("end_token", &SizeOfPackExpr::EndToken)
    .def_prop_ro("operator_token", &SizeOfPackExpr::OperatorToken)
    .def_prop_ro("pack", &SizeOfPackExpr::Pack)
    .def_prop_ro("pack_length", &SizeOfPackExpr::PackLength)
    .def_prop_ro("pack_token", &SizeOfPackExpr::PackToken)
    .def_prop_ro("partial_arguments", &SizeOfPackExpr::PartialArguments)
    .def_prop_ro("r_paren_token", &SizeOfPackExpr::RParenToken)
    .def_prop_ro("is_partially_substituted", &SizeOfPackExpr::IsPartiallySubstituted);
}
} // namespace pasta
