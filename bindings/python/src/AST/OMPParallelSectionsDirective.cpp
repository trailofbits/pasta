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

void RegisterOMPParallelSectionsDirective(py::module_ &m) {
  py::class_<OMPParallelSectionsDirective, OMPExecutableDirective>(m, "OMPParallelSectionsDirective")
    .def("__hash__", [](const OMPParallelSectionsDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("task_reduction_reference_expression", &OMPParallelSectionsDirective::TaskReductionReferenceExpression)
    .def_property_readonly("has_cancel", &OMPParallelSectionsDirective::HasCancel);
}
} // namespace pasta
