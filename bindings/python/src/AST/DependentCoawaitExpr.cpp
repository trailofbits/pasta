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

void RegisterDependentCoawaitExpr(py::module_ &m) {
  py::class_<DependentCoawaitExpr, Expr>(m, "DependentCoawaitExpr")
    .def("__hash__", [](const DependentCoawaitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DependentCoawaitExpr& a, const DependentCoawaitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DependentCoawaitExpr::Children)
    .def_property_readonly("begin_token", &DependentCoawaitExpr::BeginToken)
    .def_property_readonly("end_token", &DependentCoawaitExpr::EndToken)
    .def_property_readonly("keyword_token", &DependentCoawaitExpr::KeywordToken)
    .def_property_readonly("operand", &DependentCoawaitExpr::Operand)
    .def_property_readonly("operator_coawait_lookup", &DependentCoawaitExpr::OperatorCoawaitLookup);
}
} // namespace pasta
