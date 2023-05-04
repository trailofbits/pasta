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

void RegisterFullExpr(py::module_ &m) {
  py::class_<FullExpr, Expr, Stmt, ValueStmt>(m, "FullExpr")
    .def("__hash__", [](const FullExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const FullExpr& a, const FullExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("SubExpression", &FullExpr::SubExpression);
}
} // namespace pasta