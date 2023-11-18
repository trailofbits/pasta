/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterIfStmt(nb::module_ &m) {
  nb::class_<IfStmt, Stmt>(m, "IfStmt")
    .def_prop_ro("children", &IfStmt::Children)
    .def_prop_ro("begin_token", &IfStmt::BeginToken)
    .def_prop_ro("condition", &IfStmt::Condition)
    .def_prop_ro("condition_variable", &IfStmt::ConditionVariable)
    .def_prop_ro("condition_variable_declaration_statement", &IfStmt::ConditionVariableDeclarationStatement)
    .def_prop_ro("else", &IfStmt::Else)
    .def_prop_ro("else_token", &IfStmt::ElseToken)
    .def_prop_ro("end_token", &IfStmt::EndToken)
    .def_prop_ro("if_token", &IfStmt::IfToken)
    .def_prop_ro("initializer", &IfStmt::Initializer)
    .def_prop_ro("l_paren_token", &IfStmt::LParenToken)
    .def_prop_ro("nondiscarded_case", &IfStmt::NondiscardedCase)
    .def_prop_ro("r_paren_token", &IfStmt::RParenToken)
    .def_prop_ro("statement_kind", &IfStmt::StatementKind)
    .def_prop_ro("then", &IfStmt::Then)
    .def_prop_ro("has_else_storage", &IfStmt::HasElseStorage)
    .def_prop_ro("has_initializer_storage", &IfStmt::HasInitializerStorage)
    .def_prop_ro("has_variable_storage", &IfStmt::HasVariableStorage)
    .def_prop_ro("is_consteval", &IfStmt::IsConsteval)
    .def_prop_ro("is_constexpr", &IfStmt::IsConstexpr)
    .def_prop_ro("is_negated_consteval", &IfStmt::IsNegatedConsteval)
    .def_prop_ro("is_non_negated_consteval", &IfStmt::IsNonNegatedConsteval)
    .def_prop_ro("is_obj_c_availability_check", &IfStmt::IsObjCAvailabilityCheck);
}
} // namespace pasta
