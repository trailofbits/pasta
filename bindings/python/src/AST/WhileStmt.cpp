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

void RegisterWhileStmt(py::module_ &m) {
  py::class_<WhileStmt, Stmt>(m, "WhileStmt")
    .def_property_readonly("Children", &WhileStmt::Children)
    .def_property_readonly("BeginToken", &WhileStmt::BeginToken)
    .def_property_readonly("Body", &WhileStmt::Body)
    .def_property_readonly("Condition", &WhileStmt::Condition)
    .def_property_readonly("ConditionVariable", &WhileStmt::ConditionVariable)
    .def_property_readonly("ConditionVariableDeclarationStatement", &WhileStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("EndToken", &WhileStmt::EndToken)
    .def_property_readonly("LParenToken", &WhileStmt::LParenToken)
    .def_property_readonly("RParenToken", &WhileStmt::RParenToken)
    .def_property_readonly("WhileToken", &WhileStmt::WhileToken)
    .def_property_readonly("HasVariableStorage", &WhileStmt::HasVariableStorage);
}
} // namespace pasta
