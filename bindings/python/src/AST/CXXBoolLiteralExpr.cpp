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

void RegisterCXXBoolLiteralExpr(py::module_ &m) {
  py::class_<CXXBoolLiteralExpr, Expr>(m, "CXXBoolLiteralExpr")
    .def("__hash__", [](const CXXBoolLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXBoolLiteralExpr::Children)
    .def_property_readonly("begin_token", &CXXBoolLiteralExpr::BeginToken)
    .def_property_readonly("end_token", &CXXBoolLiteralExpr::EndToken)
    .def_property_readonly("token", &CXXBoolLiteralExpr::Token)
    .def_property_readonly("value", &CXXBoolLiteralExpr::Value);
}
} // namespace pasta
