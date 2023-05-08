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
    .def_property_readonly("AngleBrackets", &CXXNamedCastExpr::AngleBrackets)
    .def_property_readonly("BeginToken", &CXXNamedCastExpr::BeginToken)
    .def_property_readonly("CastName", &CXXNamedCastExpr::CastName)
    .def_property_readonly("EndToken", &CXXNamedCastExpr::EndToken)
    .def_property_readonly("OperatorToken", &CXXNamedCastExpr::OperatorToken)
    .def_property_readonly("RParenToken", &CXXNamedCastExpr::RParenToken);
}
} // namespace pasta
