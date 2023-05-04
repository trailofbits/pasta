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

void RegisterOMPDispatchDirective(py::module_ &m) {
  py::class_<OMPDispatchDirective, OMPExecutableDirective, Stmt>(m, "OMPDispatchDirective")
    .def("__hash__", [](const OMPDispatchDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPDispatchDirective& a, const OMPDispatchDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TargetCallToken", &OMPDispatchDirective::TargetCallToken);
}
} // namespace pasta
