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

void RegisterAsTypeExpr(py::module_ &m) {
  py::class_<AsTypeExpr, Expr>(m, "AsTypeExpr")
    .def("__hash__", [](const AsTypeExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AsTypeExpr& a, const AsTypeExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &AsTypeExpr::Children)
    .def_property_readonly("begin_token", &AsTypeExpr::BeginToken)
    .def_property_readonly("builtin_token", &AsTypeExpr::BuiltinToken)
    .def_property_readonly("end_token", &AsTypeExpr::EndToken)
    .def_property_readonly("r_paren_token", &AsTypeExpr::RParenToken)
    .def_property_readonly("src_expression", &AsTypeExpr::SrcExpression);
}
} // namespace pasta
