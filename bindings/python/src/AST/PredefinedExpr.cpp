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

void RegisterPredefinedExpr(py::module_ &m) {
  py::class_<PredefinedExpr, Expr>(m, "PredefinedExpr")
    .def("__hash__", [](const PredefinedExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const PredefinedExpr& a, const PredefinedExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &PredefinedExpr::Children)
    .def_property_readonly("begin_token", &PredefinedExpr::BeginToken)
    .def_property_readonly("end_token", &PredefinedExpr::EndToken)
    .def_property_readonly("function_name", &PredefinedExpr::FunctionName)
    .def_property_readonly("identifier_kind", &PredefinedExpr::IdentifierKind)
    .def_property_readonly("identifier_kind_name", &PredefinedExpr::IdentifierKindName)
    .def_property_readonly("token", &PredefinedExpr::Token);
}
} // namespace pasta
