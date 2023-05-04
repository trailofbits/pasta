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
  py::class_<MatrixSubscriptExpr, Expr, Stmt, ValueStmt>(m, "MatrixSubscriptExpr")
    .def_property_readonly("Children", &MatrixSubscriptExpr::Children)
    .def_property_readonly("Base", &MatrixSubscriptExpr::Base)
    .def_property_readonly("BeginToken", &MatrixSubscriptExpr::BeginToken)
    .def_property_readonly("ColumnIndex", &MatrixSubscriptExpr::ColumnIndex)
    .def_property_readonly("EndToken", &MatrixSubscriptExpr::EndToken)
    .def_property_readonly("ExpressionToken", &MatrixSubscriptExpr::ExpressionToken)
    .def_property_readonly("RBracketToken", &MatrixSubscriptExpr::RBracketToken)
    .def_property_readonly("RowIndex", &MatrixSubscriptExpr::RowIndex)
    .def_property_readonly("IsIncomplete", &MatrixSubscriptExpr::IsIncomplete);
}
} // namespace pasta
