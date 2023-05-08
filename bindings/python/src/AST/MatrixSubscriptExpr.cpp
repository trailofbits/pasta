/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterMatrixSubscriptExpr(py::module_ &m) {
  py::class_<MatrixSubscriptExpr, Expr>(m, "MatrixSubscriptExpr")
    .def("__hash__", [](const MatrixSubscriptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MatrixSubscriptExpr& a, const MatrixSubscriptExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MatrixSubscriptExpr::Children)
    .def_property_readonly("base", &MatrixSubscriptExpr::Base)
    .def_property_readonly("begin_token", &MatrixSubscriptExpr::BeginToken)
    .def_property_readonly("column_index", &MatrixSubscriptExpr::ColumnIndex)
    .def_property_readonly("end_token", &MatrixSubscriptExpr::EndToken)
    .def_property_readonly("expression_token", &MatrixSubscriptExpr::ExpressionToken)
    .def_property_readonly("r_bracket_token", &MatrixSubscriptExpr::RBracketToken)
    .def_property_readonly("row_index", &MatrixSubscriptExpr::RowIndex)
    .def_property_readonly("is_incomplete", &MatrixSubscriptExpr::IsIncomplete);
}
} // namespace pasta
