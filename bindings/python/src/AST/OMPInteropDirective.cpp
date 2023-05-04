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

void RegisterOMPInteropDirective(py::module_ &m) {
  py::class_<OMPInteropDirective, OMPExecutableDirective, Stmt>(m, "OMPInteropDirective")
    .def("__hash__", [](const OMPInteropDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPInteropDirective& a, const OMPInteropDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta