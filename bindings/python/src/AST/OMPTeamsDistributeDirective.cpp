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

void RegisterOMPTeamsDistributeDirective(py::module_ &m) {
  py::class_<OMPTeamsDistributeDirective, OMPExecutableDirective, OMPLoopBasedDirective, OMPLoopDirective, Stmt>(m, "OMPTeamsDistributeDirective")
    .def("__hash__", [](const OMPTeamsDistributeDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTeamsDistributeDirective& a, const OMPTeamsDistributeDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
