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

void RegisterCompoundLiteralExpr(py::module_ &m) {
  py::class_<CompoundLiteralExpr, Expr, Stmt, ValueStmt>(m, "CompoundLiteralExpr")
    .def("__hash__", [](const CompoundLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CompoundLiteralExpr& a, const CompoundLiteralExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CompoundLiteralExpr::Children)
    .def_property_readonly("BeginToken", &CompoundLiteralExpr::BeginToken)
    .def_property_readonly("EndToken", &CompoundLiteralExpr::EndToken)
    .def_property_readonly("Initializer", &CompoundLiteralExpr::Initializer)
    .def_property_readonly("LParenToken", &CompoundLiteralExpr::LParenToken)
    .def_property_readonly("Type", &CompoundLiteralExpr::Type)
    .def_property_readonly("IsFileScope", &CompoundLiteralExpr::IsFileScope);
}
} // namespace pasta
