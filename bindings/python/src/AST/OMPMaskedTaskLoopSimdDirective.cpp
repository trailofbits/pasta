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

void RegisterOMPMaskedTaskLoopSimdDirective(py::module_ &m) {
  py::class_<OMPMaskedTaskLoopSimdDirective, OMPLoopDirective>(m, "OMPMaskedTaskLoopSimdDirective")
    .def("__hash__", [](const OMPMaskedTaskLoopSimdDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPMaskedTaskLoopSimdDirective& a, const OMPMaskedTaskLoopSimdDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
