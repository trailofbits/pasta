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

void RegisterExprWithCleanups(nb::module_ &m) {
  nb::class_<ExprWithCleanups, FullExpr>(m, "ExprWithCleanups")
    .def_prop_ro("children", &ExprWithCleanups::Children)
    .def_prop_ro("cleanups_have_side_effects", &ExprWithCleanups::CleanupsHaveSideEffects)
    .def_prop_ro("begin_token", &ExprWithCleanups::BeginToken)
    .def_prop_ro("end_token", &ExprWithCleanups::EndToken)
    .def_prop_ro("num_objects", &ExprWithCleanups::NumObjects);
}
} // namespace pasta
