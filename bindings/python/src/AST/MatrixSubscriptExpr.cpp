/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterMatrixSubscriptExpr(nb::module_ &m) {
  nb::class_<MatrixSubscriptExpr, Expr>(m, "MatrixSubscriptExpr")
    .def("__hash__", [](const MatrixSubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &MatrixSubscriptExpr::Children)
    .def_prop_ro("base", &MatrixSubscriptExpr::Base)
    .def_prop_ro("begin_token", &MatrixSubscriptExpr::BeginToken)
    .def_prop_ro("column_index", &MatrixSubscriptExpr::ColumnIndex)
    .def_prop_ro("end_token", &MatrixSubscriptExpr::EndToken)
    .def_prop_ro("expression_token", &MatrixSubscriptExpr::ExpressionToken)
    .def_prop_ro("r_bracket_token", &MatrixSubscriptExpr::RBracketToken)
    .def_prop_ro("row_index", &MatrixSubscriptExpr::RowIndex)
    .def_prop_ro("is_incomplete", &MatrixSubscriptExpr::IsIncomplete);
}
} // namespace pasta
