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

void RegisterSEHExceptStmt(nb::module_ &m) {
  nb::class_<SEHExceptStmt, Stmt>(m, "SEHExceptStmt")
    .def_prop_ro("children", &SEHExceptStmt::Children)
    .def_prop_ro("begin_token", &SEHExceptStmt::BeginToken)
    .def_prop_ro("block", &SEHExceptStmt::Block)
    .def_prop_ro("end_token", &SEHExceptStmt::EndToken)
    .def_prop_ro("except_token", &SEHExceptStmt::ExceptToken)
    .def_prop_ro("filter_expression", &SEHExceptStmt::FilterExpression);
}
} // namespace pasta
