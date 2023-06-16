/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterOMPParallelSectionsDirective(nb::module_ &m) {
  nb::class_<OMPParallelSectionsDirective, OMPExecutableDirective>(m, "OMPParallelSectionsDirective")
    .def("__hash__", [](const OMPParallelSectionsDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("task_reduction_reference_expression", &OMPParallelSectionsDirective::TaskReductionReferenceExpression)
    .def_prop_ro("has_cancel", &OMPParallelSectionsDirective::HasCancel);
}
} // namespace pasta
