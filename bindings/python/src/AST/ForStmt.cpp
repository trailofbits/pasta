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
    .def("__hash__", [](const ForStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ForStmt& a, const ForStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ForStmt::Children)
    .def_property_readonly("begin_token", &ForStmt::BeginToken)
    .def_property_readonly("body", &ForStmt::Body)
    .def_property_readonly("condition", &ForStmt::Condition)
    .def_property_readonly("condition_variable", &ForStmt::ConditionVariable)
    .def_property_readonly("condition_variable_declaration_statement", &ForStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("end_token", &ForStmt::EndToken)
    .def_property_readonly("for_token", &ForStmt::ForToken)
    .def_property_readonly("increment", &ForStmt::Increment)
    .def_property_readonly("initializer", &ForStmt::Initializer)
    .def_property_readonly("l_paren_token", &ForStmt::LParenToken)
    .def_property_readonly("r_paren_token", &ForStmt::RParenToken);
}
} // namespace pasta
