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

void RegisterCStyleCastExpr(py::module_ &m) {
  py::class_<CStyleCastExpr, ExplicitCastExpr>(m, "CStyleCastExpr")
    .def("__hash__", [](const CStyleCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &CStyleCastExpr::BeginToken)
    .def_property_readonly("end_token", &CStyleCastExpr::EndToken)
    .def_property_readonly("l_paren_token", &CStyleCastExpr::LParenToken)
    .def_property_readonly("r_paren_token", &CStyleCastExpr::RParenToken);
}
} // namespace pasta
