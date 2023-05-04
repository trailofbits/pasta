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

void RegisterCXXFunctionalCastExpr(py::module_ &m) {
  py::class_<CXXFunctionalCastExpr, CastExpr, ExplicitCastExpr, Expr, Stmt, ValueStmt>(m, "CXXFunctionalCastExpr")
    .def("__hash__", [](const CXXFunctionalCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXFunctionalCastExpr& a, const CXXFunctionalCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("BeginToken", &CXXFunctionalCastExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXFunctionalCastExpr::EndToken)
    .def_property_readonly("LParenToken", &CXXFunctionalCastExpr::LParenToken)
    .def_property_readonly("RParenToken", &CXXFunctionalCastExpr::RParenToken)
    .def_property_readonly("IsListInitialization", &CXXFunctionalCastExpr::IsListInitialization);
}
} // namespace pasta
