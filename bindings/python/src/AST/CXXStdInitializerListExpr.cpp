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

void RegisterCXXStdInitializerListExpr(py::module_ &m) {
  py::class_<CXXStdInitializerListExpr, Expr, Stmt, ValueStmt>(m, "CXXStdInitializerListExpr")
    .def_property_readonly("Children", &CXXStdInitializerListExpr::Children)
    .def_property_readonly("BeginToken", &CXXStdInitializerListExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXStdInitializerListExpr::EndToken)
    .def_property_readonly("Tokens", &CXXStdInitializerListExpr::Tokens)
    .def_property_readonly("SubExpression", &CXXStdInitializerListExpr::SubExpression);
}
} // namespace pasta
