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

void RegisterCastExpr(py::module_ &m) {
  py::class_<CastExpr, Expr>(m, "CastExpr")
    .def("__hash__", [](const CastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CastExpr& a, const CastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CastExpr::Children)
    .def_property_readonly("CastKind", &CastExpr::CastKind)
    .def_property_readonly("CastKindName", &CastExpr::CastKindName)
    .def_property_readonly("ConversionFunction", &CastExpr::ConversionFunction)
    .def_property_readonly("SubExpression", &CastExpr::SubExpression)
    .def_property_readonly("SubExpressionAsWritten", &CastExpr::SubExpressionAsWritten)
    .def_property_readonly("TargetUnionField", &CastExpr::TargetUnionField)
    .def_property_readonly("HasStoredFPFeatures", &CastExpr::HasStoredFPFeatures);
}
} // namespace pasta
