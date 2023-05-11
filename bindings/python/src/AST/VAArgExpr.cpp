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

void RegisterVAArgExpr(py::module_ &m) {
  py::class_<VAArgExpr, Expr>(m, "VAArgExpr")
    .def("__hash__", [](const VAArgExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &VAArgExpr::Children)
    .def_property_readonly("begin_token", &VAArgExpr::BeginToken)
    .def_property_readonly("builtin_token", &VAArgExpr::BuiltinToken)
    .def_property_readonly("end_token", &VAArgExpr::EndToken)
    .def_property_readonly("r_paren_token", &VAArgExpr::RParenToken)
    .def_property_readonly("sub_expression", &VAArgExpr::SubExpression)
    .def_property_readonly("written_type", &VAArgExpr::WrittenType)
    .def_property_readonly("is_microsoft_abi", &VAArgExpr::IsMicrosoftABI);
}
} // namespace pasta
