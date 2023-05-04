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

void RegisterOMPTargetTeamsGenericLoopDirective(py::module_ &m) {
  py::class_<OMPTargetTeamsGenericLoopDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPTargetTeamsGenericLoopDirective")
    .def("__hash__", [](const OMPTargetTeamsGenericLoopDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTargetTeamsGenericLoopDirective& a, const OMPTargetTeamsGenericLoopDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
