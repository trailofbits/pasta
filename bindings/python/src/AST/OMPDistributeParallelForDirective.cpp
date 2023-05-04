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

void RegisterOMPDistributeParallelForDirective(py::module_ &m) {
  py::class_<OMPDistributeParallelForDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPDistributeParallelForDirective")
    .def_property_readonly("TaskReductionReferenceExpression", &OMPDistributeParallelForDirective::TaskReductionReferenceExpression)
    .def_property_readonly("HasCancel", &OMPDistributeParallelForDirective::HasCancel);
}
} // namespace pasta
