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

void RegisterCXXUnresolvedConstructExpr(py::module_ &m) {
  py::class_<CXXUnresolvedConstructExpr, Expr, Stmt, ValueStmt>(m, "CXXUnresolvedConstructExpr")
    .def("__hash__", [](const CXXUnresolvedConstructExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXUnresolvedConstructExpr& a, const CXXUnresolvedConstructExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Arguments", &CXXUnresolvedConstructExpr::Arguments)
    .def_property_readonly("Children", &CXXUnresolvedConstructExpr::Children)
    .def_property_readonly("BeginToken", &CXXUnresolvedConstructExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXUnresolvedConstructExpr::EndToken)
    .def_property_readonly("LParenToken", &CXXUnresolvedConstructExpr::LParenToken)
    .def_property_readonly("NumArguments", &CXXUnresolvedConstructExpr::NumArguments)
    .def_property_readonly("RParenToken", &CXXUnresolvedConstructExpr::RParenToken)
    .def_property_readonly("TypeAsWritten", &CXXUnresolvedConstructExpr::TypeAsWritten)
    .def_property_readonly("Type", &CXXUnresolvedConstructExpr::Type)
    .def_property_readonly("IsListInitialization", &CXXUnresolvedConstructExpr::IsListInitialization);
}
} // namespace pasta
