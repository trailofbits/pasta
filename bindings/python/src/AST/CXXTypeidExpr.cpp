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

void RegisterCXXTypeidExpr(py::module_ &m) {
  py::class_<CXXTypeidExpr, Expr, Stmt, ValueStmt>(m, "CXXTypeidExpr")
    .def_property_readonly("Children", &CXXTypeidExpr::Children)
    .def_property_readonly("BeginToken", &CXXTypeidExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXTypeidExpr::EndToken)
    .def_property_readonly("ExpressionOperand", &CXXTypeidExpr::ExpressionOperand)
    .def_property_readonly("Tokens", &CXXTypeidExpr::Tokens)
    .def("TypeOperand", &CXXTypeidExpr::TypeOperand)
    .def_property_readonly("TypeOperandSourceInfo", &CXXTypeidExpr::TypeOperandSourceInfo)
    .def("IsMostDerived", &CXXTypeidExpr::IsMostDerived)
    .def_property_readonly("IsPotentiallyEvaluated", &CXXTypeidExpr::IsPotentiallyEvaluated)
    .def_property_readonly("IsTypeOperand", &CXXTypeidExpr::IsTypeOperand);
}
} // namespace pasta
