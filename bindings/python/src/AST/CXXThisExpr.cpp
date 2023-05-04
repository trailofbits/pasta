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

void RegisterCXXThisExpr(py::module_ &m) {
  py::class_<CXXThisExpr, Expr, Stmt, ValueStmt>(m, "CXXThisExpr")
    .def("__hash__", [](const CXXThisExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXThisExpr& a, const CXXThisExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXThisExpr::Children)
    .def_property_readonly("BeginToken", &CXXThisExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXThisExpr::EndToken)
    .def_property_readonly("Token", &CXXThisExpr::Token)
    .def_property_readonly("IsImplicit", &CXXThisExpr::IsImplicit);
}
} // namespace pasta
