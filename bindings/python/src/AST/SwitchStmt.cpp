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

void RegisterSwitchStmt(py::module_ &m) {
  py::class_<SwitchStmt, Stmt>(m, "SwitchStmt")
    .def("__hash__", [](const SwitchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SwitchStmt& a, const SwitchStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SwitchStmt::Children)
    .def_property_readonly("begin_token", &SwitchStmt::BeginToken)
    .def_property_readonly("body", &SwitchStmt::Body)
    .def_property_readonly("condition", &SwitchStmt::Condition)
    .def_property_readonly("condition_variable", &SwitchStmt::ConditionVariable)
    .def_property_readonly("condition_variable_declaration_statement", &SwitchStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("end_token", &SwitchStmt::EndToken)
    .def_property_readonly("initializer", &SwitchStmt::Initializer)
    .def_property_readonly("l_paren_token", &SwitchStmt::LParenToken)
    .def_property_readonly("r_paren_token", &SwitchStmt::RParenToken)
    .def_property_readonly("first_switch_case", &SwitchStmt::FirstSwitchCase)
    .def_property_readonly("switch_token", &SwitchStmt::SwitchToken)
    .def_property_readonly("has_initializer_storage", &SwitchStmt::HasInitializerStorage)
    .def_property_readonly("has_variable_storage", &SwitchStmt::HasVariableStorage)
    .def_property_readonly("is_all_enum_cases_covered", &SwitchStmt::IsAllEnumCasesCovered);
}
} // namespace pasta
