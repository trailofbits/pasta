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

void RegisterPredefinedExpr(py::module_ &m) {
  py::class_<PredefinedExpr, Expr, Stmt, ValueStmt>(m, "PredefinedExpr")
    .def("__hash__", [](const PredefinedExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const PredefinedExpr& a, const PredefinedExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &PredefinedExpr::Children)
    .def_property_readonly("BeginToken", &PredefinedExpr::BeginToken)
    .def_property_readonly("EndToken", &PredefinedExpr::EndToken)
    .def_property_readonly("FunctionName", &PredefinedExpr::FunctionName)
    .def_property_readonly("IdentifierKind", &PredefinedExpr::IdentifierKind)
    .def_property_readonly("IdentifierKindName", &PredefinedExpr::IdentifierKindName)
    .def_property_readonly("Token", &PredefinedExpr::Token);
}
} // namespace pasta
