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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterMaterializeTemporaryExpr(py::module_ &m) {
  py::class_<MaterializeTemporaryExpr, Expr>(m, "MaterializeTemporaryExpr")
    .def("__hash__", [](const MaterializeTemporaryExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MaterializeTemporaryExpr& a, const MaterializeTemporaryExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MaterializeTemporaryExpr::Children)
    .def_property_readonly("begin_token", &MaterializeTemporaryExpr::BeginToken)
    .def_property_readonly("end_token", &MaterializeTemporaryExpr::EndToken)
    .def_property_readonly("extending_declaration", &MaterializeTemporaryExpr::ExtendingDeclaration)
    .def_property_readonly("lifetime_extended_temporary_declaration", &MaterializeTemporaryExpr::LifetimeExtendedTemporaryDeclaration)
    .def_property_readonly("mangling_number", &MaterializeTemporaryExpr::ManglingNumber)
    .def_property_readonly("storage_duration", &MaterializeTemporaryExpr::StorageDuration)
    .def_property_readonly("sub_expression", &MaterializeTemporaryExpr::SubExpression)
    .def_property_readonly("is_bound_to_lvalue_reference", &MaterializeTemporaryExpr::IsBoundToLvalueReference)
    .def("is_usable_in_constant_expressions", &MaterializeTemporaryExpr::IsUsableInConstantExpressions);
}
} // namespace pasta
