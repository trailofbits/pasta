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

void RegisterCXXForRangeStmt(nb::module_ &m) {
  nb::class_<CXXForRangeStmt, Stmt>(m, "CXXForRangeStmt")
    .def_prop_ro("children", &CXXForRangeStmt::Children)
    .def_prop_ro("begin_token", &CXXForRangeStmt::BeginToken)
    .def_prop_ro("begin_statement", &CXXForRangeStmt::BeginStatement)
    .def_prop_ro("body", &CXXForRangeStmt::Body)
    .def_prop_ro("coawait_token", &CXXForRangeStmt::CoawaitToken)
    .def_prop_ro("colon_token", &CXXForRangeStmt::ColonToken)
    .def_prop_ro("condition", &CXXForRangeStmt::Condition)
    .def_prop_ro("end_token", &CXXForRangeStmt::EndToken)
    .def_prop_ro("end_statement", &CXXForRangeStmt::EndStatement)
    .def_prop_ro("for_token", &CXXForRangeStmt::ForToken)
    .def_prop_ro("increment", &CXXForRangeStmt::Increment)
    .def_prop_ro("initializer", &CXXForRangeStmt::Initializer)
    .def_prop_ro("loop_variable_statement", &CXXForRangeStmt::LoopVariableStatement)
    .def_prop_ro("loop_variable", &CXXForRangeStmt::LoopVariable)
    .def_prop_ro("r_paren_token", &CXXForRangeStmt::RParenToken)
    .def_prop_ro("range_initializer", &CXXForRangeStmt::RangeInitializer)
    .def_prop_ro("range_statement", &CXXForRangeStmt::RangeStatement);
}
} // namespace pasta
