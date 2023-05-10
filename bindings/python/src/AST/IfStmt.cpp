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

void RegisterIfStmt(py::module_ &m) {
  py::class_<IfStmt, Stmt>(m, "IfStmt")
    .def("__hash__", [](const IfStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const IfStmt& a, const IfStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &IfStmt::Children)
    .def_property_readonly("begin_token", &IfStmt::BeginToken)
    .def_property_readonly("condition", &IfStmt::Condition)
    .def_property_readonly("condition_variable", &IfStmt::ConditionVariable)
    .def_property_readonly("condition_variable_declaration_statement", &IfStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("else", &IfStmt::Else)
    .def_property_readonly("else_token", &IfStmt::ElseToken)
    .def_property_readonly("end_token", &IfStmt::EndToken)
    .def_property_readonly("if_token", &IfStmt::IfToken)
    .def_property_readonly("initializer", &IfStmt::Initializer)
    .def_property_readonly("l_paren_token", &IfStmt::LParenToken)
    .def("nondiscarded_case", &IfStmt::NondiscardedCase)
    .def_property_readonly("r_paren_token", &IfStmt::RParenToken)
    .def_property_readonly("statement_kind", &IfStmt::StatementKind)
    .def_property_readonly("then", &IfStmt::Then)
    .def_property_readonly("has_else_storage", &IfStmt::HasElseStorage)
    .def_property_readonly("has_initializer_storage", &IfStmt::HasInitializerStorage)
    .def_property_readonly("has_variable_storage", &IfStmt::HasVariableStorage)
    .def_property_readonly("is_consteval", &IfStmt::IsConsteval)
    .def_property_readonly("is_constexpr", &IfStmt::IsConstexpr)
    .def_property_readonly("is_negated_consteval", &IfStmt::IsNegatedConsteval)
    .def_property_readonly("is_non_negated_consteval", &IfStmt::IsNonNegatedConsteval)
    .def_property_readonly("is_obj_c_availability_check", &IfStmt::IsObjCAvailabilityCheck);
}
} // namespace pasta
