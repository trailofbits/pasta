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

void RegisterCompoundLiteralExpr(nb::module_ &m) {
  nb::class_<CompoundLiteralExpr, Expr>(m, "CompoundLiteralExpr")
    .def_prop_ro("children", &CompoundLiteralExpr::Children)
    .def_prop_ro("begin_token", &CompoundLiteralExpr::BeginToken)
    .def_prop_ro("end_token", &CompoundLiteralExpr::EndToken)
    .def_prop_ro("initializer", &CompoundLiteralExpr::Initializer)
    .def_prop_ro("l_paren_token", &CompoundLiteralExpr::LParenToken)
    .def_prop_ro("is_file_scope", &CompoundLiteralExpr::IsFileScope);
}
} // namespace pasta
