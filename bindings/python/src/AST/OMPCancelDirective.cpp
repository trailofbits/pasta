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

void RegisterOMPCancelDirective(py::module_ &m) {
  py::class_<OMPCancelDirective, OMPExecutableDirective, Stmt>(m, "OMPCancelDirective")
    .def("__hash__", [](const OMPCancelDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPCancelDirective& a, const OMPCancelDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta