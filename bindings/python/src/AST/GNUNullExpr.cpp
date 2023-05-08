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

void RegisterGNUNullExpr(py::module_ &m) {
  py::class_<GNUNullExpr, Expr>(m, "GNUNullExpr")
    .def("__hash__", [](const GNUNullExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const GNUNullExpr& a, const GNUNullExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &GNUNullExpr::Children)
    .def_property_readonly("begin_token", &GNUNullExpr::BeginToken)
    .def_property_readonly("end_token", &GNUNullExpr::EndToken)
    .def_property_readonly("token_token", &GNUNullExpr::TokenToken);
}
} // namespace pasta
