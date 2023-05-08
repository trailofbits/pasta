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

void RegisterShuffleVectorExpr(py::module_ &m) {
  py::class_<ShuffleVectorExpr, Expr>(m, "ShuffleVectorExpr")
    .def("__hash__", [](const ShuffleVectorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ShuffleVectorExpr& a, const ShuffleVectorExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ShuffleVectorExpr::Children)
    .def_property_readonly("begin_token", &ShuffleVectorExpr::BeginToken)
    .def_property_readonly("builtin_token", &ShuffleVectorExpr::BuiltinToken)
    .def_property_readonly("end_token", &ShuffleVectorExpr::EndToken)
    .def_property_readonly("num_sub_expressions", &ShuffleVectorExpr::NumSubExpressions)
    .def_property_readonly("r_paren_token", &ShuffleVectorExpr::RParenToken);
}
} // namespace pasta
