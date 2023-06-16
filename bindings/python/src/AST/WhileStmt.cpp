/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterWhileStmt(nb::module_ &m) {
  nb::class_<WhileStmt, Stmt>(m, "WhileStmt")
    .def("__hash__", [](const WhileStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
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
