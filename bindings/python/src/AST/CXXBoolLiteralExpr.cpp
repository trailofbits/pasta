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

void RegisterCXXBoolLiteralExpr(py::module_ &m) {
  py::class_<CXXBoolLiteralExpr, Expr, Stmt, ValueStmt>(m, "CXXBoolLiteralExpr")
    .def("__hash__", [](const CXXBoolLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXBoolLiteralExpr& a, const CXXBoolLiteralExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXBoolLiteralExpr::Children)
    .def_property_readonly("BeginToken", &CXXBoolLiteralExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXBoolLiteralExpr::EndToken)
    .def_property_readonly("Token", &CXXBoolLiteralExpr::Token)
    .def_property_readonly("Value", &CXXBoolLiteralExpr::Value);
}
} // namespace pasta
