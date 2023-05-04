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

void RegisterOMPParallelMaskedTaskLoopDirective(py::module_ &m) {
  py::class_<OMPParallelMaskedTaskLoopDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPParallelMaskedTaskLoopDirective")
    .def("__hash__", [](const OMPParallelMaskedTaskLoopDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPParallelMaskedTaskLoopDirective& a, const OMPParallelMaskedTaskLoopDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("HasCancel", &OMPParallelMaskedTaskLoopDirective::HasCancel);
}
} // namespace pasta