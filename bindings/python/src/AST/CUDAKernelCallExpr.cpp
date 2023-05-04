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

void RegisterCUDAKernelCallExpr(py::module_ &m) {
  py::class_<CUDAKernelCallExpr, CallExpr, Expr, Stmt, ValueStmt>(m, "CUDAKernelCallExpr")
    .def("__hash__", [](const CUDAKernelCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CUDAKernelCallExpr& a, const CUDAKernelCallExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Config", &CUDAKernelCallExpr::Config);
}
} // namespace pasta
