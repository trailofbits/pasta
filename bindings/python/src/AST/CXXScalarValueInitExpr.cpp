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

void RegisterCXXScalarValueInitExpr(py::module_ &m) {
  py::class_<CXXScalarValueInitExpr, Expr>(m, "CXXScalarValueInitExpr")
    .def("__hash__", [](const CXXScalarValueInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXScalarValueInitExpr& a, const CXXScalarValueInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXScalarValueInitExpr::Children)
    .def_property_readonly("begin_token", &CXXScalarValueInitExpr::BeginToken)
    .def_property_readonly("end_token", &CXXScalarValueInitExpr::EndToken)
    .def_property_readonly("r_paren_token", &CXXScalarValueInitExpr::RParenToken)
    .def_property_readonly("type", &CXXScalarValueInitExpr::Type);
}
} // namespace pasta
