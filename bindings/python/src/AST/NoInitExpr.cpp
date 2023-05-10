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

void RegisterNoInitExpr(py::module_ &m) {
  py::class_<NoInitExpr, Expr>(m, "NoInitExpr")
    .def("__hash__", [](const NoInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const NoInitExpr& a, const NoInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &NoInitExpr::Children)
    .def_property_readonly("begin_token", &NoInitExpr::BeginToken)
    .def_property_readonly("end_token", &NoInitExpr::EndToken);
}
} // namespace pasta
