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

void RegisterParenListExpr(py::module_ &m) {
  py::class_<ParenListExpr, Expr, Stmt, ValueStmt>(m, "ParenListExpr")
    .def("__hash__", [](const ParenListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ParenListExpr& a, const ParenListExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ParenListExpr::Children)
    .def_property_readonly("BeginToken", &ParenListExpr::BeginToken)
    .def_property_readonly("EndToken", &ParenListExpr::EndToken)
    .def_property_readonly("LParenToken", &ParenListExpr::LParenToken)
    .def_property_readonly("NumExpressions", &ParenListExpr::NumExpressions)
    .def_property_readonly("RParenToken", &ParenListExpr::RParenToken);
}
} // namespace pasta
