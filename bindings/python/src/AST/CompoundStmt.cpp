/*
 * Copyright (c) 2023 Trail of Bits, Inc.
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

void RegisterCompoundStmt(nb::module_ &m) {
  nb::class_<CompoundStmt, Stmt>(m, "CompoundStmt")
    .def_prop_ro("children", &CompoundStmt::Children)
    .def_prop_ro("begin_token", &CompoundStmt::BeginToken)
    .def_prop_ro("end_token", &CompoundStmt::EndToken)
    .def_prop_ro("left_brace_token", &CompoundStmt::LeftBraceToken)
    .def_prop_ro("right_brace_token", &CompoundStmt::RightBraceToken)
    .def_prop_ro("statement_expression_result", &CompoundStmt::StatementExpressionResult)
    .def_prop_ro("has_stored_fp_features", &CompoundStmt::HasStoredFPFeatures)
    .def_prop_ro("size", &CompoundStmt::Size);
}
} // namespace pasta
