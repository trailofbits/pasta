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

void RegisterOffsetOfExpr(py::module_ &m) {
  py::class_<OffsetOfExpr, Expr>(m, "OffsetOfExpr")
    .def("__hash__", [](const OffsetOfExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OffsetOfExpr& a, const OffsetOfExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &OffsetOfExpr::Children)
    .def_property_readonly("begin_token", &OffsetOfExpr::BeginToken)
    .def_property_readonly("end_token", &OffsetOfExpr::EndToken)
    .def_property_readonly("num_components", &OffsetOfExpr::NumComponents)
    .def_property_readonly("num_expressions", &OffsetOfExpr::NumExpressions)
    .def_property_readonly("operator_token", &OffsetOfExpr::OperatorToken)
    .def_property_readonly("r_paren_token", &OffsetOfExpr::RParenToken)
    .def_property_readonly("type", &OffsetOfExpr::Type);
}
} // namespace pasta
