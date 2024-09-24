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

void RegisterBreakStmt(nb::module_ &m) {
  nb::class_<BreakStmt, Stmt>(m, "BreakStmt")
    .def_prop_ro("children", &BreakStmt::Children)
    .def_prop_ro("begin_token", &BreakStmt::BeginToken)
    .def_prop_ro("break_token", &BreakStmt::BreakToken)
    .def_prop_ro("end_token", &BreakStmt::EndToken);
}
} // namespace pasta
