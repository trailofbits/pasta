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

void RegisterConvertVectorExpr(py::module_ &m) {
  py::class_<ConvertVectorExpr, Expr>(m, "ConvertVectorExpr")
    .def("__hash__", [](const ConvertVectorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ConvertVectorExpr& a, const ConvertVectorExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ConvertVectorExpr::Children)
    .def_property_readonly("BeginToken", &ConvertVectorExpr::BeginToken)
    .def_property_readonly("BuiltinToken", &ConvertVectorExpr::BuiltinToken)
    .def_property_readonly("EndToken", &ConvertVectorExpr::EndToken)
    .def_property_readonly("RParenToken", &ConvertVectorExpr::RParenToken)
    .def_property_readonly("SrcExpression", &ConvertVectorExpr::SrcExpression)
    .def_property_readonly("Type", &ConvertVectorExpr::Type);
}
} // namespace pasta
