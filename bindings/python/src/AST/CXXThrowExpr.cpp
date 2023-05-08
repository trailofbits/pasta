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
    .def_property_readonly("Children", &CXXThrowExpr::Children)
    .def_property_readonly("BeginToken", &CXXThrowExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXThrowExpr::EndToken)
    .def_property_readonly("SubExpression", &CXXThrowExpr::SubExpression)
    .def_property_readonly("ThrowToken", &CXXThrowExpr::ThrowToken)
    .def_property_readonly("IsThrownVariableInScope", &CXXThrowExpr::IsThrownVariableInScope);
}
} // namespace pasta
