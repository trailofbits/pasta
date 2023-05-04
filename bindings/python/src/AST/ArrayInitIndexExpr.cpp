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

void RegisterArrayInitIndexExpr(py::module_ &m) {
  py::class_<ArrayInitIndexExpr, Expr, Stmt, ValueStmt>(m, "ArrayInitIndexExpr")
    .def("__hash__", [](const ArrayInitIndexExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ArrayInitIndexExpr& a, const ArrayInitIndexExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ArrayInitIndexExpr::Children)
    .def_property_readonly("BeginToken", &ArrayInitIndexExpr::BeginToken)
    .def_property_readonly("EndToken", &ArrayInitIndexExpr::EndToken);
}
} // namespace pasta