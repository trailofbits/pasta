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

void RegisterCXXFoldExpr(nb::module_ &m) {
  nb::class_<CXXFoldExpr, Expr>(m, "CXXFoldExpr")
    .def_prop_ro("children", &CXXFoldExpr::Children)
    .def_prop_ro("begin_token", &CXXFoldExpr::BeginToken)
    .def_prop_ro("callee", &CXXFoldExpr::Callee)
    .def_prop_ro("ellipsis_token", &CXXFoldExpr::EllipsisToken)
    .def_prop_ro("end_token", &CXXFoldExpr::EndToken)
    .def_prop_ro("initializer", &CXXFoldExpr::Initializer)
    .def_prop_ro("lhs", &CXXFoldExpr::LHS)
    .def_prop_ro("l_paren_token", &CXXFoldExpr::LParenToken)
    .def_prop_ro("num_expansions", &CXXFoldExpr::NumExpansions)
    .def_prop_ro("operator", &CXXFoldExpr::Operator)
    .def_prop_ro("pattern", &CXXFoldExpr::Pattern)
    .def_prop_ro("rhs", &CXXFoldExpr::RHS)
    .def_prop_ro("r_paren_token", &CXXFoldExpr::RParenToken)
    .def_prop_ro("is_left_fold", &CXXFoldExpr::IsLeftFold)
    .def_prop_ro("is_right_fold", &CXXFoldExpr::IsRightFold);
}
} // namespace pasta
