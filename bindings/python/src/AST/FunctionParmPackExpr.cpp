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

void RegisterFunctionParmPackExpr(py::module_ &m) {
  py::class_<FunctionParmPackExpr, Expr>(m, "FunctionParmPackExpr")
    .def("__hash__", [](const FunctionParmPackExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const FunctionParmPackExpr& a, const FunctionParmPackExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &FunctionParmPackExpr::Children)
    .def_property_readonly("begin_token", &FunctionParmPackExpr::BeginToken)
    .def_property_readonly("end_token", &FunctionParmPackExpr::EndToken)
    .def_property_readonly("num_expansions", &FunctionParmPackExpr::NumExpansions)
    .def_property_readonly("parameter_pack", &FunctionParmPackExpr::ParameterPack)
    .def_property_readonly("parameter_pack_token", &FunctionParmPackExpr::ParameterPackToken);
}
} // namespace pasta
