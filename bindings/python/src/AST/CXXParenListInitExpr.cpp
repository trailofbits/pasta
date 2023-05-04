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

void RegisterCXXParenListInitExpr(py::module_ &m) {
  py::class_<CXXParenListInitExpr, Expr, Stmt, ValueStmt>(m, "CXXParenListInitExpr")
    .def("__hash__", [](const CXXParenListInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXParenListInitExpr& a, const CXXParenListInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXParenListInitExpr::Children)
    .def_property_readonly("ArrayFiller", &CXXParenListInitExpr::ArrayFiller)
    .def_property_readonly("BeginToken", &CXXParenListInitExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXParenListInitExpr::EndToken)
    .def_property_readonly("InitializerToken", &CXXParenListInitExpr::InitializerToken)
    .def_property_readonly("InitializedFieldInUnion", &CXXParenListInitExpr::InitializedFieldInUnion)
    .def_property_readonly("Tokens", &CXXParenListInitExpr::Tokens);
}
} // namespace pasta
