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

void RegisterArrayInitLoopExpr(py::module_ &m) {
  py::class_<ArrayInitLoopExpr, Expr>(m, "ArrayInitLoopExpr")
    .def("__hash__", [](const ArrayInitLoopExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ArrayInitLoopExpr::Children)
    .def_property_readonly("array_size", &ArrayInitLoopExpr::ArraySize)
    .def_property_readonly("begin_token", &ArrayInitLoopExpr::BeginToken)
    .def_property_readonly("common_expression", &ArrayInitLoopExpr::CommonExpression)
    .def_property_readonly("end_token", &ArrayInitLoopExpr::EndToken)
    .def_property_readonly("sub_expression", &ArrayInitLoopExpr::SubExpression);
}
} // namespace pasta
