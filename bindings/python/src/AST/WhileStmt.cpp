/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterWhileStmt(nb::module_ &m) {
  nb::class_<WhileStmt, Stmt>(m, "WhileStmt")
    .def_prop_ro("children", &WhileStmt::Children)
    .def_prop_ro("begin_token", &WhileStmt::BeginToken)
    .def_prop_ro("body", &WhileStmt::Body)
    .def_prop_ro("condition", &WhileStmt::Condition)
    .def_prop_ro("condition_variable", &WhileStmt::ConditionVariable)
    .def_prop_ro("condition_variable_declaration_statement", &WhileStmt::ConditionVariableDeclarationStatement)
    .def_prop_ro("end_token", &WhileStmt::EndToken)
    .def_prop_ro("l_paren_token", &WhileStmt::LParenToken)
    .def_prop_ro("r_paren_token", &WhileStmt::RParenToken)
    .def_prop_ro("while_token", &WhileStmt::WhileToken)
    .def_prop_ro("has_variable_storage", &WhileStmt::HasVariableStorage);
}
} // namespace pasta
