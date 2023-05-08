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

void RegisterCXXNoexceptExpr(py::module_ &m) {
  py::class_<CXXNoexceptExpr, Expr>(m, "CXXNoexceptExpr")
    .def("__hash__", [](const CXXNoexceptExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXNoexceptExpr& a, const CXXNoexceptExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXNoexceptExpr::Children)
    .def_property_readonly("begin_token", &CXXNoexceptExpr::BeginToken)
    .def_property_readonly("end_token", &CXXNoexceptExpr::EndToken)
    .def_property_readonly("operand", &CXXNoexceptExpr::Operand)
    .def_property_readonly("tokens", &CXXNoexceptExpr::Tokens)
    .def_property_readonly("value", &CXXNoexceptExpr::Value);
}
} // namespace pasta
