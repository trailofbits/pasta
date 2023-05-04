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
  py::class_<DependentCoawaitExpr, Expr, Stmt, ValueStmt>(m, "DependentCoawaitExpr")
    .def("__hash__", [](const DependentCoawaitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DependentCoawaitExpr& a, const DependentCoawaitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &DependentCoawaitExpr::Children)
    .def_property_readonly("BeginToken", &DependentCoawaitExpr::BeginToken)
    .def_property_readonly("EndToken", &DependentCoawaitExpr::EndToken)
    .def_property_readonly("KeywordToken", &DependentCoawaitExpr::KeywordToken)
    .def_property_readonly("Operand", &DependentCoawaitExpr::Operand)
    .def_property_readonly("OperatorCoawaitLookup", &DependentCoawaitExpr::OperatorCoawaitLookup);
}
} // namespace pasta
