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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterOMPDistributeParallelForDirective(py::module_ &m) {
  py::class_<OMPDistributeParallelForDirective, OMPLoopDirective>(m, "OMPDistributeParallelForDirective")
    .def("__hash__", [](const OMPDistributeParallelForDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPDistributeParallelForDirective& a, const OMPDistributeParallelForDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("task_reduction_reference_expression", &OMPDistributeParallelForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("has_cancel", &OMPDistributeParallelForDirective::HasCancel);
}
} // namespace pasta
