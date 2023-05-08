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

void RegisterImplicitValueInitExpr(py::module_ &m) {
  py::class_<ImplicitValueInitExpr, Expr>(m, "ImplicitValueInitExpr")
    .def("__hash__", [](const ImplicitValueInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ImplicitValueInitExpr& a, const ImplicitValueInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ImplicitValueInitExpr::Children)
    .def_property_readonly("begin_token", &ImplicitValueInitExpr::BeginToken)
    .def_property_readonly("end_token", &ImplicitValueInitExpr::EndToken);
}
} // namespace pasta
