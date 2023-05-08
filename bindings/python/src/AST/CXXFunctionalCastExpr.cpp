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

void RegisterCXXFunctionalCastExpr(py::module_ &m) {
  py::class_<CXXFunctionalCastExpr, ExplicitCastExpr>(m, "CXXFunctionalCastExpr")
    .def("__hash__", [](const CXXFunctionalCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXFunctionalCastExpr& a, const CXXFunctionalCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &CXXFunctionalCastExpr::BeginToken)
    .def_property_readonly("end_token", &CXXFunctionalCastExpr::EndToken)
    .def_property_readonly("l_paren_token", &CXXFunctionalCastExpr::LParenToken)
    .def_property_readonly("r_paren_token", &CXXFunctionalCastExpr::RParenToken)
    .def_property_readonly("is_list_initialization", &CXXFunctionalCastExpr::IsListInitialization);
}
} // namespace pasta
