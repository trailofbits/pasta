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

void RegisterOMPTargetTeamsDistributeDirective(py::module_ &m) {
  py::class_<OMPTargetTeamsDistributeDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPTargetTeamsDistributeDirective")
    .def("__hash__", [](const OMPTargetTeamsDistributeDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTargetTeamsDistributeDirective& a, const OMPTargetTeamsDistributeDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta