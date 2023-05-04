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

void RegisterCXXBindTemporaryExpr(py::module_ &m) {
  py::class_<CXXBindTemporaryExpr, Expr, Stmt, ValueStmt>(m, "CXXBindTemporaryExpr")
    .def("__hash__", [](const CXXBindTemporaryExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXBindTemporaryExpr& a, const CXXBindTemporaryExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXBindTemporaryExpr::Children)
    .def_property_readonly("BeginToken", &CXXBindTemporaryExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXBindTemporaryExpr::EndToken)
    .def_property_readonly("SubExpression", &CXXBindTemporaryExpr::SubExpression);
}
} // namespace pasta
