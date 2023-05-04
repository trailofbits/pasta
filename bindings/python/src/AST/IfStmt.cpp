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

void RegisterIfStmt(py::module_ &m) {
  py::class_<IfStmt, Stmt>(m, "IfStmt")
    .def("__hash__", [](const IfStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const IfStmt& a, const IfStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &IfStmt::Children)
    .def_property_readonly("BeginToken", &IfStmt::BeginToken)
    .def_property_readonly("Condition", &IfStmt::Condition)
    .def_property_readonly("ConditionVariable", &IfStmt::ConditionVariable)
    .def_property_readonly("ConditionVariableDeclarationStatement", &IfStmt::ConditionVariableDeclarationStatement)
    .def_property_readonly("Else", &IfStmt::Else)
    .def_property_readonly("ElseToken", &IfStmt::ElseToken)
    .def_property_readonly("EndToken", &IfStmt::EndToken)
    .def_property_readonly("IfToken", &IfStmt::IfToken)
    .def_property_readonly("Initializer", &IfStmt::Initializer)
    .def_property_readonly("LParenToken", &IfStmt::LParenToken)
    .def("NondiscardedCase", &IfStmt::NondiscardedCase)
    .def_property_readonly("RParenToken", &IfStmt::RParenToken)
    .def_property_readonly("StatementKind", &IfStmt::StatementKind)
    .def_property_readonly("Then", &IfStmt::Then)
    .def_property_readonly("HasElseStorage", &IfStmt::HasElseStorage)
    .def_property_readonly("HasInitializerStorage", &IfStmt::HasInitializerStorage)
    .def_property_readonly("HasVariableStorage", &IfStmt::HasVariableStorage)
    .def_property_readonly("IsConsteval", &IfStmt::IsConsteval)
    .def_property_readonly("IsConstexpr", &IfStmt::IsConstexpr)
    .def_property_readonly("IsNegatedConsteval", &IfStmt::IsNegatedConsteval)
    .def_property_readonly("IsNonNegatedConsteval", &IfStmt::IsNonNegatedConsteval)
    .def_property_readonly("IsObjCAvailabilityCheck", &IfStmt::IsObjCAvailabilityCheck);
}
} // namespace pasta
