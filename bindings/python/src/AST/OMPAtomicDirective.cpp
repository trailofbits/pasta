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

void RegisterOMPAtomicDirective(nb::module_ &m) {
  nb::class_<OMPAtomicDirective, OMPExecutableDirective>(m, "OMPAtomicDirective")
    .def("__hash__", [](const OMPAtomicDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("condition_expression", &OMPAtomicDirective::ConditionExpression)
    .def_prop_ro("d", &OMPAtomicDirective::D)
    .def_prop_ro("expression", &OMPAtomicDirective::Expression)
    .def_prop_ro("r", &OMPAtomicDirective::R)
    .def_prop_ro("update_expression", &OMPAtomicDirective::UpdateExpression)
    .def_prop_ro("v", &OMPAtomicDirective::V)
    .def_prop_ro("x", &OMPAtomicDirective::X)
    .def_prop_ro("is_fail_only", &OMPAtomicDirective::IsFailOnly)
    .def_prop_ro("is_postfix_update", &OMPAtomicDirective::IsPostfixUpdate)
    .def_prop_ro("is_xlhs_in_rhs_part", &OMPAtomicDirective::IsXLHSInRHSPart);
}
} // namespace pasta
