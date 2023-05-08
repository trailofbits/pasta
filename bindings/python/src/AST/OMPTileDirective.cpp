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

void RegisterOMPTileDirective(py::module_ &m) {
  py::class_<OMPTileDirective, OMPLoopTransformationDirective>(m, "OMPTileDirective")
    .def("__hash__", [](const OMPTileDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTileDirective& a, const OMPTileDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("pre_initializers", &OMPTileDirective::PreInitializers)
    .def_property_readonly("transformed_statement", &OMPTileDirective::TransformedStatement);
}
} // namespace pasta
