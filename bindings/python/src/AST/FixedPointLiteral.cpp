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

void RegisterFixedPointLiteral(py::module_ &m) {
  py::class_<FixedPointLiteral, Expr, Stmt, ValueStmt>(m, "FixedPointLiteral")
    .def_property_readonly("Children", &FixedPointLiteral::Children)
    .def_property_readonly("BeginToken", &FixedPointLiteral::BeginToken)
    .def_property_readonly("EndToken", &FixedPointLiteral::EndToken)
    .def_property_readonly("Token", &FixedPointLiteral::Token)
    .def_property_readonly("Scale", &FixedPointLiteral::Scale);
}
} // namespace pasta
