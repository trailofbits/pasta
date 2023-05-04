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

void RegisterFloatingLiteral(py::module_ &m) {
  py::class_<FloatingLiteral, Expr, Stmt, ValueStmt>(m, "FloatingLiteral")
    .def_property_readonly("Children", &FloatingLiteral::Children)
    .def_property_readonly("BeginToken", &FloatingLiteral::BeginToken)
    .def_property_readonly("EndToken", &FloatingLiteral::EndToken)
    .def_property_readonly("Token", &FloatingLiteral::Token)
    .def_property_readonly("ValueAsApproximateDouble", &FloatingLiteral::ValueAsApproximateDouble)
    .def_property_readonly("IsExact", &FloatingLiteral::IsExact);
}
} // namespace pasta
