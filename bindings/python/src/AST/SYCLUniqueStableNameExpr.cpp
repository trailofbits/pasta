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

void RegisterSYCLUniqueStableNameExpr(py::module_ &m) {
  py::class_<SYCLUniqueStableNameExpr, Expr>(m, "SYCLUniqueStableNameExpr")
    .def("__hash__", [](const SYCLUniqueStableNameExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SYCLUniqueStableNameExpr& a, const SYCLUniqueStableNameExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def("compute_name", &SYCLUniqueStableNameExpr::ComputeName)
    .def_property_readonly("children", &SYCLUniqueStableNameExpr::Children)
    .def_property_readonly("begin_token", &SYCLUniqueStableNameExpr::BeginToken)
    .def_property_readonly("end_token", &SYCLUniqueStableNameExpr::EndToken)
    .def_property_readonly("l_paren_token", &SYCLUniqueStableNameExpr::LParenToken)
    .def_property_readonly("token", &SYCLUniqueStableNameExpr::Token)
    .def_property_readonly("r_paren_token", &SYCLUniqueStableNameExpr::RParenToken)
    .def_property_readonly("type", &SYCLUniqueStableNameExpr::Type);
}
} // namespace pasta
