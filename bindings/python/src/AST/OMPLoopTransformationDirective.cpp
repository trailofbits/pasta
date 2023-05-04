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

void RegisterOMPLoopTransformationDirective(py::module_ &m) {
  py::class_<OMPLoopTransformationDirective, OMPExecutableDirective, OMPLoopBasedDirective, Stmt>(m, "OMPLoopTransformationDirective")
    .def_property_readonly("NumAssociatedLoops", &OMPLoopTransformationDirective::NumAssociatedLoops)
    .def_property_readonly("PreInitializers", &OMPLoopTransformationDirective::PreInitializers)
    .def_property_readonly("TransformedStatement", &OMPLoopTransformationDirective::TransformedStatement);
}
} // namespace pasta
