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

void RegisterChooseExpr(nb::module_ &m) {
  nb::class_<ChooseExpr, Expr>(m, "ChooseExpr")
    .def_prop_ro("children", &ChooseExpr::Children)
    .def_prop_ro("begin_token", &ChooseExpr::BeginToken)
    .def_prop_ro("builtin_token", &ChooseExpr::BuiltinToken)
    .def_prop_ro("chosen_sub_expression", &ChooseExpr::ChosenSubExpression)
    .def_prop_ro("condition", &ChooseExpr::Condition)
    .def_prop_ro("end_token", &ChooseExpr::EndToken)
    .def_prop_ro("lhs", &ChooseExpr::LHS)
    .def_prop_ro("rhs", &ChooseExpr::RHS)
    .def_prop_ro("r_paren_token", &ChooseExpr::RParenToken)
    .def_prop_ro("is_condition_dependent", &ChooseExpr::IsConditionDependent)
    .def_prop_ro("is_condition_true", &ChooseExpr::IsConditionTrue);
}
} // namespace pasta
