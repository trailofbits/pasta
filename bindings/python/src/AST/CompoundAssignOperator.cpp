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

void RegisterCompoundAssignOperator(nb::module_ &m) {
  nb::class_<CompoundAssignOperator, BinaryOperator>(m, "CompoundAssignOperator")
    .def("__hash__", [](const CompoundAssignOperator& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("computation_lhs_type", &CompoundAssignOperator::ComputationLHSType)
    .def_prop_ro("computation_result_type", &CompoundAssignOperator::ComputationResultType);
}
} // namespace pasta
