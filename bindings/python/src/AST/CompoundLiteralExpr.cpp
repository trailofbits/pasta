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

void RegisterCompoundLiteralExpr(py::module_ &m) {
  py::class_<CompoundLiteralExpr, Expr>(m, "CompoundLiteralExpr")
    .def("__hash__", [](const CompoundLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CompoundLiteralExpr::Children)
    .def_property_readonly("begin_token", &CompoundLiteralExpr::BeginToken)
    .def_property_readonly("end_token", &CompoundLiteralExpr::EndToken)
    .def_property_readonly("initializer", &CompoundLiteralExpr::Initializer)
    .def_property_readonly("l_paren_token", &CompoundLiteralExpr::LParenToken)
    .def_property_readonly("type", &CompoundLiteralExpr::Type)
    .def_property_readonly("is_file_scope", &CompoundLiteralExpr::IsFileScope);
}
} // namespace pasta
