/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPParallelMasterDirective(nb::module_ &m) {
  nb::class_<OMPParallelMasterDirective, OMPExecutableDirective>(m, "OMPParallelMasterDirective")
    .def("__hash__", [](const OMPParallelMasterDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("task_reduction_reference_expression", &OMPParallelMasterDirective::TaskReductionReferenceExpression);
}
} // namespace pasta
