/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPParallelMaskedDirective(nb::module_ &m) {
  nb::class_<OMPParallelMaskedDirective, OMPExecutableDirective>(m, "OMPParallelMaskedDirective")
    .def("__hash__", [](const OMPParallelMaskedDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("task_reduction_reference_expression", &OMPParallelMaskedDirective::TaskReductionReferenceExpression);
}
} // namespace pasta
