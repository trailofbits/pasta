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

void RegisterStmtExpr(py::module_ &m) {
  py::class_<StmtExpr, Expr>(m, "StmtExpr")
    .def("__hash__", [](const StmtExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const StmtExpr& a, const StmtExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &StmtExpr::Children)
    .def_property_readonly("BeginToken", &StmtExpr::BeginToken)
    .def_property_readonly("EndToken", &StmtExpr::EndToken)
    .def_property_readonly("LParenToken", &StmtExpr::LParenToken)
    .def_property_readonly("RParenToken", &StmtExpr::RParenToken)
    .def_property_readonly("SubStatement", &StmtExpr::SubStatement)
    .def_property_readonly("TemplateDepth", &StmtExpr::TemplateDepth);
}
} // namespace pasta
