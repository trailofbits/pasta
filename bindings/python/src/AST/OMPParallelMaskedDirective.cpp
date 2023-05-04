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

void RegisterOMPParallelMaskedDirective(py::module_ &m) {
  py::class_<OMPParallelMaskedDirective, OMPExecutableDirective, Stmt>(m, "OMPParallelMaskedDirective")
    .def("__hash__", [](const OMPParallelMaskedDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPParallelMaskedDirective& a, const OMPParallelMaskedDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TaskReductionReferenceExpression", &OMPParallelMaskedDirective::TaskReductionReferenceExpression);
}
} // namespace pasta
