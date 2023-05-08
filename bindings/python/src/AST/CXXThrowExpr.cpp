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

void RegisterCXXThrowExpr(py::module_ &m) {
  py::class_<CXXThrowExpr, Expr>(m, "CXXThrowExpr")
    .def("__hash__", [](const CXXThrowExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXThrowExpr& a, const CXXThrowExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXThrowExpr::Children)
    .def_property_readonly("begin_token", &CXXThrowExpr::BeginToken)
    .def_property_readonly("end_token", &CXXThrowExpr::EndToken)
    .def_property_readonly("sub_expression", &CXXThrowExpr::SubExpression)
    .def_property_readonly("throw_token", &CXXThrowExpr::ThrowToken)
    .def_property_readonly("is_thrown_variable_in_scope", &CXXThrowExpr::IsThrownVariableInScope);
}
} // namespace pasta
