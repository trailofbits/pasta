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

void RegisterCaseStmt(nb::module_ &m) {
  nb::class_<CaseStmt, SwitchCase>(m, "CaseStmt")
    .def_prop_ro("case_statement_is_gnu_range", &CaseStmt::CaseStatementIsGNURange)
    .def_prop_ro("children", &CaseStmt::Children)
    .def_prop_ro("begin_token", &CaseStmt::BeginToken)
    .def_prop_ro("case_token", &CaseStmt::CaseToken)
    .def_prop_ro("ellipsis_token", &CaseStmt::EllipsisToken)
    .def_prop_ro("end_token", &CaseStmt::EndToken)
    .def_prop_ro("lhs", &CaseStmt::LHS)
    .def_prop_ro("rhs", &CaseStmt::RHS)
    .def_prop_ro("sub_statement", &CaseStmt::SubStatement);
}
} // namespace pasta
