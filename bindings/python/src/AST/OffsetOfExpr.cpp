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
    .def_property_readonly("Children", &OffsetOfExpr::Children)
    .def_property_readonly("BeginToken", &OffsetOfExpr::BeginToken)
    .def_property_readonly("EndToken", &OffsetOfExpr::EndToken)
    .def_property_readonly("NumComponents", &OffsetOfExpr::NumComponents)
    .def_property_readonly("NumExpressions", &OffsetOfExpr::NumExpressions)
    .def_property_readonly("OperatorToken", &OffsetOfExpr::OperatorToken)
    .def_property_readonly("RParenToken", &OffsetOfExpr::RParenToken)
    .def_property_readonly("Type", &OffsetOfExpr::Type);
}
} // namespace pasta
