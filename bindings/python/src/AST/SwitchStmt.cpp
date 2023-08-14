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

void RegisterSwitchStmt(nb::module_ &m) {
  nb::class_<SwitchStmt, Stmt>(m, "SwitchStmt")
    .def("__hash__", [](const SwitchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &SwitchStmt::Children)
    .def_prop_ro("begin_token", &SwitchStmt::BeginToken)
    .def_prop_ro("body", &SwitchStmt::Body)
    .def_prop_ro("condition", &SwitchStmt::Condition)
    .def_prop_ro("condition_variable", &SwitchStmt::ConditionVariable)
    .def_prop_ro("condition_variable_declaration_statement", &SwitchStmt::ConditionVariableDeclarationStatement)
    .def_prop_ro("end_token", &SwitchStmt::EndToken)
    .def_prop_ro("initializer", &SwitchStmt::Initializer)
    .def_prop_ro("l_paren_token", &SwitchStmt::LParenToken)
    .def_prop_ro("r_paren_token", &SwitchStmt::RParenToken)
    .def_prop_ro("first_switch_case", &SwitchStmt::FirstSwitchCase)
    .def_prop_ro("switch_token", &SwitchStmt::SwitchToken)
    .def_prop_ro("has_initializer_storage", &SwitchStmt::HasInitializerStorage)
    .def_prop_ro("has_variable_storage", &SwitchStmt::HasVariableStorage)
    .def_prop_ro("is_all_enum_cases_covered", &SwitchStmt::IsAllEnumCasesCovered);
}
} // namespace pasta
