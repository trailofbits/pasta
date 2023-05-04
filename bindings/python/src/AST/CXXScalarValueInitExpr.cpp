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

void RegisterCXXScalarValueInitExpr(py::module_ &m) {
  py::class_<CXXScalarValueInitExpr, Expr, Stmt, ValueStmt>(m, "CXXScalarValueInitExpr")
    .def_property_readonly("Children", &CXXScalarValueInitExpr::Children)
    .def_property_readonly("BeginToken", &CXXScalarValueInitExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXScalarValueInitExpr::EndToken)
    .def_property_readonly("RParenToken", &CXXScalarValueInitExpr::RParenToken)
    .def_property_readonly("Type", &CXXScalarValueInitExpr::Type);
}
} // namespace pasta
