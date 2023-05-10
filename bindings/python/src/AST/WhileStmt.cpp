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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterWhileStmt(py::module_ &m) {
  py::class_<WhileStmt, Stmt>(m, "WhileStmt")
    .def("__hash__", [](const WhileStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const WhileStmt& a, const WhileStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &WhileStmt::Children)
    .def_property_readonly("begin_token", &WhileStmt::BeginToken)
    .def_property_readonly("body", &WhileStmt::Body)
    .def_property_readonly("condition", &WhileStmt::Condition)
    .def_property_readonly("condition_variable", &WhileStmt::ConditionVariable)
    .def_property_readonly("condition_variable_declaration_statement", &WhileStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("end_token", &WhileStmt::EndToken)
    .def_property_readonly("l_paren_token", &WhileStmt::LParenToken)
    .def_property_readonly("r_paren_token", &WhileStmt::RParenToken)
    .def_property_readonly("while_token", &WhileStmt::WhileToken)
    .def_property_readonly("has_variable_storage", &WhileStmt::HasVariableStorage);
}
} // namespace pasta
