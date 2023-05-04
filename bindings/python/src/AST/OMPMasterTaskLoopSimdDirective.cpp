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

void RegisterOMPMasterTaskLoopSimdDirective(py::module_ &m) {
  py::class_<OMPMasterTaskLoopSimdDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPMasterTaskLoopSimdDirective")
    .def("__hash__", [](const OMPMasterTaskLoopSimdDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPMasterTaskLoopSimdDirective& a, const OMPMasterTaskLoopSimdDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
