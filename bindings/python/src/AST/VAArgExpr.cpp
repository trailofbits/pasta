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

void RegisterVAArgExpr(py::module_ &m) {
  py::class_<VAArgExpr, Expr, Stmt, ValueStmt>(m, "VAArgExpr")
    .def_property_readonly("Children", &VAArgExpr::Children)
    .def_property_readonly("BeginToken", &VAArgExpr::BeginToken)
    .def_property_readonly("BuiltinToken", &VAArgExpr::BuiltinToken)
    .def_property_readonly("EndToken", &VAArgExpr::EndToken)
    .def_property_readonly("RParenToken", &VAArgExpr::RParenToken)
    .def_property_readonly("SubExpression", &VAArgExpr::SubExpression)
    .def_property_readonly("WrittenType", &VAArgExpr::WrittenType)
    .def_property_readonly("IsMicrosoftABI", &VAArgExpr::IsMicrosoftABI);
}
} // namespace pasta
