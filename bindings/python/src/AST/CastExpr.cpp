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

void RegisterCastExpr(py::module_ &m) {
  py::class_<CastExpr, Expr>(m, "CastExpr")
    .def("__hash__", [](const CastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CastExpr::Children)
    .def_property_readonly("cast_kind", &CastExpr::CastKind)
    .def_property_readonly("cast_kind_name", &CastExpr::CastKindName)
    .def_property_readonly("conversion_function", &CastExpr::ConversionFunction)
    .def_property_readonly("sub_expression", &CastExpr::SubExpression)
    .def_property_readonly("sub_expression_as_written", &CastExpr::SubExpressionAsWritten)
    .def_property_readonly("target_union_field", &CastExpr::TargetUnionField)
    .def_property_readonly("has_stored_fp_features", &CastExpr::HasStoredFPFeatures);
}
} // namespace pasta
