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

void RegisterForStmt(py::module_ &m) {
  py::class_<ForStmt, Stmt>(m, "ForStmt")
    .def_property_readonly("Children", &ForStmt::Children)
    .def_property_readonly("BeginToken", &ForStmt::BeginToken)
    .def_property_readonly("Body", &ForStmt::Body)
    .def_property_readonly("Condition", &ForStmt::Condition)
    .def_property_readonly("ConditionVariable", &ForStmt::ConditionVariable)
    .def_property_readonly("ConditionVariableDeclarationStatement", &ForStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("EndToken", &ForStmt::EndToken)
    .def_property_readonly("ForToken", &ForStmt::ForToken)
    .def_property_readonly("Increment", &ForStmt::Increment)
    .def_property_readonly("Initializer", &ForStmt::Initializer)
    .def_property_readonly("LParenToken", &ForStmt::LParenToken)
    .def_property_readonly("RParenToken", &ForStmt::RParenToken);
}
} // namespace pasta
