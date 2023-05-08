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

void RegisterCStyleCastExpr(py::module_ &m) {
  py::class_<CStyleCastExpr, ExplicitCastExpr>(m, "CStyleCastExpr")
    .def("__hash__", [](const CStyleCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CStyleCastExpr& a, const CStyleCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("BeginToken", &CStyleCastExpr::BeginToken)
    .def_property_readonly("EndToken", &CStyleCastExpr::EndToken)
    .def_property_readonly("LParenToken", &CStyleCastExpr::LParenToken)
    .def_property_readonly("RParenToken", &CStyleCastExpr::RParenToken);
}
} // namespace pasta
