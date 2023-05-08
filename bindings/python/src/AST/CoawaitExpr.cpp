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

void RegisterCoawaitExpr(py::module_ &m) {
  py::class_<CoawaitExpr, CoroutineSuspendExpr>(m, "CoawaitExpr")
    .def("__hash__", [](const CoawaitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CoawaitExpr& a, const CoawaitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("IsImplicit", &CoawaitExpr::IsImplicit);
}
} // namespace pasta
