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

void RegisterParenExpr(py::module_ &m) {
  py::class_<ParenExpr, Expr>(m, "ParenExpr")
    .def("__hash__", [](const ParenExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ParenExpr& a, const ParenExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ParenExpr::Children)
    .def_property_readonly("begin_token", &ParenExpr::BeginToken)
    .def_property_readonly("end_token", &ParenExpr::EndToken)
    .def_property_readonly("l_paren_token", &ParenExpr::LParenToken)
    .def_property_readonly("r_paren_token", &ParenExpr::RParenToken)
    .def_property_readonly("sub_expression", &ParenExpr::SubExpression);
}
} // namespace pasta
