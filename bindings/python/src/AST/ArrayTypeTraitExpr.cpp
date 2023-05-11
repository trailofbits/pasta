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

void RegisterArrayTypeTraitExpr(py::module_ &m) {
  py::class_<ArrayTypeTraitExpr, Expr>(m, "ArrayTypeTraitExpr")
    .def("__hash__", [](const ArrayTypeTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ArrayTypeTraitExpr::Children)
    .def_property_readonly("begin_token", &ArrayTypeTraitExpr::BeginToken)
    .def_property_readonly("dimension_expression", &ArrayTypeTraitExpr::DimensionExpression)
    .def_property_readonly("end_token", &ArrayTypeTraitExpr::EndToken)
    .def_property_readonly("queried_type", &ArrayTypeTraitExpr::QueriedType)
    .def_property_readonly("trait", &ArrayTypeTraitExpr::Trait)
    .def_property_readonly("value", &ArrayTypeTraitExpr::Value);
}
} // namespace pasta
