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

void RegisterMaterializeTemporaryExpr(py::module_ &m) {
  py::class_<MaterializeTemporaryExpr, Expr, Stmt, ValueStmt>(m, "MaterializeTemporaryExpr")
    .def_property_readonly("Children", &MaterializeTemporaryExpr::Children)
    .def_property_readonly("BeginToken", &MaterializeTemporaryExpr::BeginToken)
    .def_property_readonly("EndToken", &MaterializeTemporaryExpr::EndToken)
    .def_property_readonly("ExtendingDeclaration", &MaterializeTemporaryExpr::ExtendingDeclaration)
    .def_property_readonly("LifetimeExtendedTemporaryDeclaration", &MaterializeTemporaryExpr::LifetimeExtendedTemporaryDeclaration)
    .def_property_readonly("ManglingNumber", &MaterializeTemporaryExpr::ManglingNumber)
    .def_property_readonly("StorageDuration", &MaterializeTemporaryExpr::StorageDuration)
    .def_property_readonly("SubExpression", &MaterializeTemporaryExpr::SubExpression)
    .def_property_readonly("IsBoundToLvalueReference", &MaterializeTemporaryExpr::IsBoundToLvalueReference)
    .def("IsUsableInConstantExpressions", &MaterializeTemporaryExpr::IsUsableInConstantExpressions);
}
} // namespace pasta
