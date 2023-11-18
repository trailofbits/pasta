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

void RegisterForStmt(nb::module_ &m) {
  nb::class_<ForStmt, Stmt>(m, "ForStmt")
    .def_prop_ro("children", &ForStmt::Children)
    .def_prop_ro("begin_token", &ForStmt::BeginToken)
    .def_prop_ro("body", &ForStmt::Body)
    .def_prop_ro("condition", &ForStmt::Condition)
    .def_prop_ro("condition_variable", &ForStmt::ConditionVariable)
    .def_prop_ro("condition_variable_declaration_statement", &ForStmt::ConditionVariableDeclarationStatement)
    .def_prop_ro("end_token", &ForStmt::EndToken)
    .def_prop_ro("for_token", &ForStmt::ForToken)
    .def_prop_ro("increment", &ForStmt::Increment)
    .def_prop_ro("initializer", &ForStmt::Initializer)
    .def_prop_ro("l_paren_token", &ForStmt::LParenToken)
    .def_prop_ro("r_paren_token", &ForStmt::RParenToken);
}
} // namespace pasta
