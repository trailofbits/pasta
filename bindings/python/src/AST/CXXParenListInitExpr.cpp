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

void RegisterCXXParenListInitExpr(py::module_ &m) {
  py::class_<CXXParenListInitExpr, Expr>(m, "CXXParenListInitExpr")
    .def("__hash__", [](const CXXParenListInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXParenListInitExpr::Children)
    .def_property_readonly("array_filler", &CXXParenListInitExpr::ArrayFiller)
    .def_property_readonly("begin_token", &CXXParenListInitExpr::BeginToken)
    .def_property_readonly("end_token", &CXXParenListInitExpr::EndToken)
    .def_property_readonly("initializer_token", &CXXParenListInitExpr::InitializerToken)
    .def_property_readonly("initialized_field_in_union", &CXXParenListInitExpr::InitializedFieldInUnion)
    .def_property_readonly("tokens", &CXXParenListInitExpr::Tokens);
}
} // namespace pasta
