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

void RegisterOMPTargetParallelForDirective(py::module_ &m) {
  py::class_<OMPTargetParallelForDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPTargetParallelForDirective")
    .def("__hash__", [](const OMPTargetParallelForDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTargetParallelForDirective& a, const OMPTargetParallelForDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TaskReductionReferenceExpression", &OMPTargetParallelForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("HasCancel", &OMPTargetParallelForDirective::HasCancel);
}
} // namespace pasta
