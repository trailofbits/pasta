/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCompoundAssignOperator(nb::module_ &m) {
  nb::class_<CompoundAssignOperator, BinaryOperator>(m, "CompoundAssignOperator")
    .def_prop_ro("computation_lhs_type", &CompoundAssignOperator::ComputationLHSType)
    .def_prop_ro("computation_result_type", &CompoundAssignOperator::ComputationResultType);
}
} // namespace pasta
