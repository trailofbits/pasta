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

void RegisterExplicitCastExpr(py::module_ &m) {
  py::class_<ExplicitCastExpr, CastExpr, Expr, Stmt, ValueStmt>(m, "ExplicitCastExpr")
    .def("__hash__", [](const ExplicitCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ExplicitCastExpr& a, const ExplicitCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TypeAsWritten", &ExplicitCastExpr::TypeAsWritten)
    .def_property_readonly("TypeInfoAsWritten", &ExplicitCastExpr::TypeInfoAsWritten);
}
} // namespace pasta