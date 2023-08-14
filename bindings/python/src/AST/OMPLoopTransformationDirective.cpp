/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPLoopTransformationDirective(nb::module_ &m) {
  nb::class_<OMPLoopTransformationDirective, OMPLoopBasedDirective>(m, "OMPLoopTransformationDirective")
    .def("__hash__", [](const OMPLoopTransformationDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("num_associated_loops", &OMPLoopTransformationDirective::NumAssociatedLoops)
    .def_prop_ro("pre_initializers", &OMPLoopTransformationDirective::PreInitializers)
    .def_prop_ro("transformed_statement", &OMPLoopTransformationDirective::TransformedStatement);
}
} // namespace pasta
