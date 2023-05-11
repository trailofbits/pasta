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

void RegisterCXXThisExpr(py::module_ &m) {
  py::class_<CXXThisExpr, Expr>(m, "CXXThisExpr")
    .def("__hash__", [](const CXXThisExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXThisExpr::Children)
    .def_property_readonly("begin_token", &CXXThisExpr::BeginToken)
    .def_property_readonly("end_token", &CXXThisExpr::EndToken)
    .def_property_readonly("token", &CXXThisExpr::Token)
    .def_property_readonly("is_implicit", &CXXThisExpr::IsImplicit);
}
} // namespace pasta
