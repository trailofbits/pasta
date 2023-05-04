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

void RegisterPackExpansionExpr(py::module_ &m) {
  py::class_<PackExpansionExpr, Expr, Stmt, ValueStmt>(m, "PackExpansionExpr")
    .def_property_readonly("Children", &PackExpansionExpr::Children)
    .def_property_readonly("BeginToken", &PackExpansionExpr::BeginToken)
    .def_property_readonly("EllipsisToken", &PackExpansionExpr::EllipsisToken)
    .def_property_readonly("EndToken", &PackExpansionExpr::EndToken)
    .def_property_readonly("NumExpansions", &PackExpansionExpr::NumExpansions)
    .def_property_readonly("Pattern", &PackExpansionExpr::Pattern);
}
} // namespace pasta
