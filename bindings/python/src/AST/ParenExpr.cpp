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

void RegisterParenExpr(py::module_ &m) {
  py::class_<ParenExpr, Expr>(m, "ParenExpr")
    .def("__hash__", [](const ParenExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ParenExpr& a, const ParenExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ParenExpr::Children)
    .def_property_readonly("BeginToken", &ParenExpr::BeginToken)
    .def_property_readonly("EndToken", &ParenExpr::EndToken)
    .def_property_readonly("LParenToken", &ParenExpr::LParenToken)
    .def_property_readonly("RParenToken", &ParenExpr::RParenToken)
    .def_property_readonly("SubExpression", &ParenExpr::SubExpression);
}
} // namespace pasta
