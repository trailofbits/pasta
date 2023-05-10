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

void RegisterOMPUnrollDirective(py::module_ &m) {
  py::class_<OMPUnrollDirective, OMPLoopTransformationDirective>(m, "OMPUnrollDirective")
    .def("__hash__", [](const OMPUnrollDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPUnrollDirective& a, const OMPUnrollDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("pre_initializers", &OMPUnrollDirective::PreInitializers)
    .def_property_readonly("transformed_statement", &OMPUnrollDirective::TransformedStatement);
}
} // namespace pasta
