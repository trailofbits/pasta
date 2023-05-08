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
    .def_property_readonly("children", &StmtExpr::Children)
    .def_property_readonly("begin_token", &StmtExpr::BeginToken)
    .def_property_readonly("end_token", &StmtExpr::EndToken)
    .def_property_readonly("l_paren_token", &StmtExpr::LParenToken)
    .def_property_readonly("r_paren_token", &StmtExpr::RParenToken)
    .def_property_readonly("sub_statement", &StmtExpr::SubStatement)
    .def_property_readonly("template_depth", &StmtExpr::TemplateDepth);
}
} // namespace pasta
