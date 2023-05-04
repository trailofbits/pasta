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

void RegisterOMPOrderedDirective(py::module_ &m) {
  py::class_<OMPOrderedDirective, OMPExecutableDirective, Stmt>(m, "OMPOrderedDirective")
    .def("__hash__", [](const OMPOrderedDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPOrderedDirective& a, const OMPOrderedDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
