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

void RegisterOMPForDirective(py::module_ &m) {
  py::class_<OMPForDirective, OMPLoopDirective>(m, "OMPForDirective")
    .def("__hash__", [](const OMPForDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPForDirective& a, const OMPForDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("task_reduction_reference_expression", &OMPForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("has_cancel", &OMPForDirective::HasCancel);
}
} // namespace pasta
