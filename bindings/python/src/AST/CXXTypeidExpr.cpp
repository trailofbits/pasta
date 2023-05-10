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

void RegisterCXXTypeidExpr(py::module_ &m) {
  py::class_<CXXTypeidExpr, Expr>(m, "CXXTypeidExpr")
    .def("__hash__", [](const CXXTypeidExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXTypeidExpr& a, const CXXTypeidExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXTypeidExpr::Children)
    .def_property_readonly("begin_token", &CXXTypeidExpr::BeginToken)
    .def_property_readonly("end_token", &CXXTypeidExpr::EndToken)
    .def_property_readonly("expression_operand", &CXXTypeidExpr::ExpressionOperand)
    .def_property_readonly("tokens", &CXXTypeidExpr::Tokens)
    .def("type_operand", &CXXTypeidExpr::TypeOperand)
    .def_property_readonly("type_operand_source_info", &CXXTypeidExpr::TypeOperandSourceInfo)
    .def("is_most_derived", &CXXTypeidExpr::IsMostDerived)
    .def_property_readonly("is_potentially_evaluated", &CXXTypeidExpr::IsPotentiallyEvaluated)
    .def_property_readonly("is_type_operand", &CXXTypeidExpr::IsTypeOperand);
}
} // namespace pasta
