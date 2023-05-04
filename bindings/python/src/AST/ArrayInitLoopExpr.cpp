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

void RegisterArrayInitLoopExpr(py::module_ &m) {
  py::class_<ArrayInitLoopExpr, Expr, Stmt, ValueStmt>(m, "ArrayInitLoopExpr")
    .def_property_readonly("Children", &ArrayInitLoopExpr::Children)
    .def_property_readonly("ArraySize", &ArrayInitLoopExpr::ArraySize)
    .def_property_readonly("BeginToken", &ArrayInitLoopExpr::BeginToken)
    .def_property_readonly("CommonExpression", &ArrayInitLoopExpr::CommonExpression)
    .def_property_readonly("EndToken", &ArrayInitLoopExpr::EndToken)
    .def_property_readonly("SubExpression", &ArrayInitLoopExpr::SubExpression);
}
} // namespace pasta
