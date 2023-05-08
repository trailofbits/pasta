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
    .def_property_readonly("children", &ConvertVectorExpr::Children)
    .def_property_readonly("begin_token", &ConvertVectorExpr::BeginToken)
    .def_property_readonly("builtin_token", &ConvertVectorExpr::BuiltinToken)
    .def_property_readonly("end_token", &ConvertVectorExpr::EndToken)
    .def_property_readonly("r_paren_token", &ConvertVectorExpr::RParenToken)
    .def_property_readonly("src_expression", &ConvertVectorExpr::SrcExpression)
    .def_property_readonly("type", &ConvertVectorExpr::Type);
}
} // namespace pasta
