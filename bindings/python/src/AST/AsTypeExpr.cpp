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

void RegisterAsTypeExpr(py::module_ &m) {
  py::class_<AsTypeExpr, Expr, Stmt, ValueStmt>(m, "AsTypeExpr")
    .def_property_readonly("Children", &AsTypeExpr::Children)
    .def_property_readonly("BeginToken", &AsTypeExpr::BeginToken)
    .def_property_readonly("BuiltinToken", &AsTypeExpr::BuiltinToken)
    .def_property_readonly("EndToken", &AsTypeExpr::EndToken)
    .def_property_readonly("RParenToken", &AsTypeExpr::RParenToken)
    .def_property_readonly("SrcExpression", &AsTypeExpr::SrcExpression);
}
} // namespace pasta
