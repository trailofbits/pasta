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
  py::class_<CXXNoexceptExpr, Expr, Stmt, ValueStmt>(m, "CXXNoexceptExpr")
    .def_property_readonly("Children", &CXXNoexceptExpr::Children)
    .def_property_readonly("BeginToken", &CXXNoexceptExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXNoexceptExpr::EndToken)
    .def_property_readonly("Operand", &CXXNoexceptExpr::Operand)
    .def_property_readonly("Tokens", &CXXNoexceptExpr::Tokens)
    .def_property_readonly("Value", &CXXNoexceptExpr::Value);
}
} // namespace pasta
