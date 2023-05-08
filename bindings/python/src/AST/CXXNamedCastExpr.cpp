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

void RegisterCXXNamedCastExpr(py::module_ &m) {
  py::class_<CXXNamedCastExpr, ExplicitCastExpr>(m, "CXXNamedCastExpr")
    .def("__hash__", [](const CXXNamedCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXNamedCastExpr& a, const CXXNamedCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("angle_brackets", &CXXNamedCastExpr::AngleBrackets)
    .def_property_readonly("begin_token", &CXXNamedCastExpr::BeginToken)
    .def_property_readonly("cast_name", &CXXNamedCastExpr::CastName)
    .def_property_readonly("end_token", &CXXNamedCastExpr::EndToken)
    .def_property_readonly("operator_token", &CXXNamedCastExpr::OperatorToken)
    .def_property_readonly("r_paren_token", &CXXNamedCastExpr::RParenToken);
}
} // namespace pasta
