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

void RegisterCXXUnresolvedConstructExpr(py::module_ &m) {
  py::class_<CXXUnresolvedConstructExpr, Expr>(m, "CXXUnresolvedConstructExpr")
    .def("__hash__", [](const CXXUnresolvedConstructExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXUnresolvedConstructExpr& a, const CXXUnresolvedConstructExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("arguments", &CXXUnresolvedConstructExpr::Arguments)
    .def_property_readonly("children", &CXXUnresolvedConstructExpr::Children)
    .def_property_readonly("begin_token", &CXXUnresolvedConstructExpr::BeginToken)
    .def_property_readonly("end_token", &CXXUnresolvedConstructExpr::EndToken)
    .def_property_readonly("l_paren_token", &CXXUnresolvedConstructExpr::LParenToken)
    .def_property_readonly("num_arguments", &CXXUnresolvedConstructExpr::NumArguments)
    .def_property_readonly("r_paren_token", &CXXUnresolvedConstructExpr::RParenToken)
    .def_property_readonly("type_as_written", &CXXUnresolvedConstructExpr::TypeAsWritten)
    .def_property_readonly("type", &CXXUnresolvedConstructExpr::Type)
    .def_property_readonly("is_list_initialization", &CXXUnresolvedConstructExpr::IsListInitialization);
}
} // namespace pasta
