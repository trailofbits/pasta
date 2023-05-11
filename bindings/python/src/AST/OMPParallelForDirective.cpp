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

void RegisterOMPParallelForDirective(py::module_ &m) {
  py::class_<OMPParallelForDirective, OMPLoopDirective>(m, "OMPParallelForDirective")
    .def("__hash__", [](const OMPParallelForDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("task_reduction_reference_expression", &OMPParallelForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("has_cancel", &OMPParallelForDirective::HasCancel);
}
} // namespace pasta
