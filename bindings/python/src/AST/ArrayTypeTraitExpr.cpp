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

void RegisterArrayTypeTraitExpr(py::module_ &m) {
  py::class_<ArrayTypeTraitExpr, Expr, Stmt, ValueStmt>(m, "ArrayTypeTraitExpr")
    .def_property_readonly("Children", &ArrayTypeTraitExpr::Children)
    .def_property_readonly("BeginToken", &ArrayTypeTraitExpr::BeginToken)
    .def_property_readonly("DimensionExpression", &ArrayTypeTraitExpr::DimensionExpression)
    .def_property_readonly("EndToken", &ArrayTypeTraitExpr::EndToken)
    .def_property_readonly("QueriedType", &ArrayTypeTraitExpr::QueriedType)
    .def_property_readonly("Trait", &ArrayTypeTraitExpr::Trait)
    .def_property_readonly("Value", &ArrayTypeTraitExpr::Value);
}
} // namespace pasta
