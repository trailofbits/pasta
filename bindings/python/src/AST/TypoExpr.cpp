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

void RegisterTypoExpr(nb::module_ &m) {
  nb::class_<TypoExpr, Expr>(m, "TypoExpr")
    .def_prop_ro("children", &TypoExpr::Children)
    .def_prop_ro("begin_token", &TypoExpr::BeginToken)
    .def_prop_ro("end_token", &TypoExpr::EndToken);
}
} // namespace pasta
