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

void RegisterOMPTargetTeamsGenericLoopDirective(nb::module_ &m) {
  nb::class_<OMPTargetTeamsGenericLoopDirective, OMPLoopDirective>(m, "OMPTargetTeamsGenericLoopDirective")
    .def("__hash__", [](const OMPTargetTeamsGenericLoopDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
