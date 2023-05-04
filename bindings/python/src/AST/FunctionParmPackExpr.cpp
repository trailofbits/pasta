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

void RegisterFunctionParmPackExpr(py::module_ &m) {
  py::class_<FunctionParmPackExpr, Expr, Stmt, ValueStmt>(m, "FunctionParmPackExpr")
    .def_property_readonly("Children", &FunctionParmPackExpr::Children)
    .def_property_readonly("BeginToken", &FunctionParmPackExpr::BeginToken)
    .def_property_readonly("EndToken", &FunctionParmPackExpr::EndToken)
    .def_property_readonly("NumExpansions", &FunctionParmPackExpr::NumExpansions)
    .def_property_readonly("ParameterPack", &FunctionParmPackExpr::ParameterPack)
    .def_property_readonly("ParameterPackToken", &FunctionParmPackExpr::ParameterPackToken);
}
} // namespace pasta
