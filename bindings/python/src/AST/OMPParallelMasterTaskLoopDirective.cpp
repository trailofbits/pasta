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

void RegisterOMPParallelMasterTaskLoopDirective(py::module_ &m) {
  py::class_<OMPParallelMasterTaskLoopDirective, OMPLoopDirective>(m, "OMPParallelMasterTaskLoopDirective")
    .def("__hash__", [](const OMPParallelMasterTaskLoopDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPParallelMasterTaskLoopDirective& a, const OMPParallelMasterTaskLoopDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("HasCancel", &OMPParallelMasterTaskLoopDirective::HasCancel);
}
} // namespace pasta
