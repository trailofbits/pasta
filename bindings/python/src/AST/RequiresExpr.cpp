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

void RegisterRequiresExpr(py::module_ &m) {
  py::class_<RequiresExpr, Expr, Stmt, ValueStmt>(m, "RequiresExpr")
    .def_property_readonly("Children", &RequiresExpr::Children)
    .def_property_readonly("BeginToken", &RequiresExpr::BeginToken)
    .def_property_readonly("Body", &RequiresExpr::Body)
    .def_property_readonly("EndToken", &RequiresExpr::EndToken)
    .def_property_readonly("LocalParameters", &RequiresExpr::LocalParameters)
    .def_property_readonly("RBraceToken", &RequiresExpr::RBraceToken)
    .def_property_readonly("RequiresKeywordToken", &RequiresExpr::RequiresKeywordToken)
    .def_property_readonly("IsSatisfied", &RequiresExpr::IsSatisfied);
}
} // namespace pasta
