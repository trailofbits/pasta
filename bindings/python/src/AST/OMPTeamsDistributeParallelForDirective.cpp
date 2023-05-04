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

void RegisterOMPTeamsDistributeParallelForDirective(py::module_ &m) {
  py::class_<OMPTeamsDistributeParallelForDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPTeamsDistributeParallelForDirective")
    .def("__hash__", [](const OMPTeamsDistributeParallelForDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTeamsDistributeParallelForDirective& a, const OMPTeamsDistributeParallelForDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TaskReductionReferenceExpression", &OMPTeamsDistributeParallelForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("HasCancel", &OMPTeamsDistributeParallelForDirective::HasCancel);
}
} // namespace pasta
