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

void RegisterImplicitValueInitExpr(nb::module_ &m) {
  nb::class_<ImplicitValueInitExpr, Expr>(m, "ImplicitValueInitExpr")
    .def_prop_ro("children", &ImplicitValueInitExpr::Children)
    .def_prop_ro("begin_token", &ImplicitValueInitExpr::BeginToken)
    .def_prop_ro("end_token", &ImplicitValueInitExpr::EndToken);
}
} // namespace pasta
