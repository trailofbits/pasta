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

void RegisterOMPParallelForSimdDirective(py::module_ &m) {
  py::class_<OMPParallelForSimdDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPParallelForSimdDirective")
    .def("__hash__", [](const OMPParallelForSimdDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPParallelForSimdDirective& a, const OMPParallelForSimdDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta