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
    .def_property_readonly("Children", &SwitchStmt::Children)
    .def_property_readonly("BeginToken", &SwitchStmt::BeginToken)
    .def_property_readonly("Body", &SwitchStmt::Body)
    .def_property_readonly("Condition", &SwitchStmt::Condition)
    .def_property_readonly("ConditionVariable", &SwitchStmt::ConditionVariable)
    .def_property_readonly("ConditionVariableDeclarationStatement", &SwitchStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("EndToken", &SwitchStmt::EndToken)
    .def_property_readonly("Initializer", &SwitchStmt::Initializer)
    .def_property_readonly("LParenToken", &SwitchStmt::LParenToken)
    .def_property_readonly("RParenToken", &SwitchStmt::RParenToken)
    .def_property_readonly("FirstSwitchCase", &SwitchStmt::FirstSwitchCase)
    .def_property_readonly("SwitchToken", &SwitchStmt::SwitchToken)
    .def_property_readonly("HasInitializerStorage", &SwitchStmt::HasInitializerStorage)
    .def_property_readonly("HasVariableStorage", &SwitchStmt::HasVariableStorage)
    .def_property_readonly("IsAllEnumCasesCovered", &SwitchStmt::IsAllEnumCasesCovered);
}
} // namespace pasta
