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

void RegisterCXXNullPtrLiteralExpr(py::module_ &m) {
  py::class_<CXXNullPtrLiteralExpr, Expr, Stmt, ValueStmt>(m, "CXXNullPtrLiteralExpr")
    .def("__hash__", [](const CXXNullPtrLiteralExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXNullPtrLiteralExpr& a, const CXXNullPtrLiteralExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXNullPtrLiteralExpr::Children)
    .def_property_readonly("BeginToken", &CXXNullPtrLiteralExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXNullPtrLiteralExpr::EndToken)
    .def_property_readonly("Token", &CXXNullPtrLiteralExpr::Token);
}
} // namespace pasta
