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

void RegisterExtVectorElementExpr(py::module_ &m) {
  py::class_<ExtVectorElementExpr, Expr, Stmt, ValueStmt>(m, "ExtVectorElementExpr")
    .def_property_readonly("Children", &ExtVectorElementExpr::Children)
    .def_property_readonly("ContainsDuplicateElements", &ExtVectorElementExpr::ContainsDuplicateElements)
    .def_property_readonly("AccessorToken", &ExtVectorElementExpr::AccessorToken)
    .def_property_readonly("Base", &ExtVectorElementExpr::Base)
    .def_property_readonly("BeginToken", &ExtVectorElementExpr::BeginToken)
    .def_property_readonly("EndToken", &ExtVectorElementExpr::EndToken)
    .def_property_readonly("NumElements", &ExtVectorElementExpr::NumElements)
    .def_property_readonly("IsArrow", &ExtVectorElementExpr::IsArrow);
}
} // namespace pasta
