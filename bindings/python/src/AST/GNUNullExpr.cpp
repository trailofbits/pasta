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

void RegisterGNUNullExpr(py::module_ &m) {
  py::class_<GNUNullExpr, Expr, Stmt, ValueStmt>(m, "GNUNullExpr")
    .def_property_readonly("Children", &GNUNullExpr::Children)
    .def_property_readonly("BeginToken", &GNUNullExpr::BeginToken)
    .def_property_readonly("EndToken", &GNUNullExpr::EndToken)
    .def_property_readonly("TokenToken", &GNUNullExpr::TokenToken);
}
} // namespace pasta
