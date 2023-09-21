/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPUnrollDirective(nb::module_ &m) {
  nb::class_<OMPUnrollDirective, OMPLoopTransformationDirective>(m, "OMPUnrollDirective")
    .def("__hash__", [](const OMPUnrollDirective& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("pre_initializers", &OMPUnrollDirective::PreInitializers)
    .def_prop_ro("transformed_statement", &OMPUnrollDirective::TransformedStatement);
}
} // namespace pasta
