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

void RegisterCXXNewExpr(py::module_ &m) {
  py::class_<CXXNewExpr, Expr, Stmt, ValueStmt>(m, "CXXNewExpr")
    .def_property_readonly("Children", &CXXNewExpr::Children)
    .def_property_readonly("DoesUsualArrayDeleteWantSize", &CXXNewExpr::DoesUsualArrayDeleteWantSize)
    .def_property_readonly("AllocatedType", &CXXNewExpr::AllocatedType)
    .def_property_readonly("ArraySize", &CXXNewExpr::ArraySize)
    .def_property_readonly("BeginToken", &CXXNewExpr::BeginToken)
    .def_property_readonly("ConstructExpression", &CXXNewExpr::ConstructExpression)
    .def_property_readonly("DirectInitializerRange", &CXXNewExpr::DirectInitializerRange)
    .def_property_readonly("EndToken", &CXXNewExpr::EndToken)
    .def_property_readonly("InitializationStyle", &CXXNewExpr::InitializationStyle)
    .def_property_readonly("Initializer", &CXXNewExpr::Initializer)
    .def_property_readonly("NumPlacementArguments", &CXXNewExpr::NumPlacementArguments)
    .def_property_readonly("OperatorDelete", &CXXNewExpr::OperatorDelete)
    .def_property_readonly("OperatorNew", &CXXNewExpr::OperatorNew)
    .def_property_readonly("Tokens", &CXXNewExpr::Tokens)
    .def_property_readonly("TypeIdParentheses", &CXXNewExpr::TypeIdParentheses)
    .def_property_readonly("HasInitializer", &CXXNewExpr::HasInitializer)
    .def_property_readonly("IsArray", &CXXNewExpr::IsArray)
    .def_property_readonly("IsGlobalNew", &CXXNewExpr::IsGlobalNew)
    .def_property_readonly("IsParenthesisTypeId", &CXXNewExpr::IsParenthesisTypeId)
    .def_property_readonly("PassAlignment", &CXXNewExpr::PassAlignment)
    .def_property_readonly("PlacementArguments", &CXXNewExpr::PlacementArguments)
    .def_property_readonly("ShouldNullCheckAllocation", &CXXNewExpr::ShouldNullCheckAllocation);
}
} // namespace pasta
