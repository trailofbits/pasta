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

void RegisterUnaryExprOrTypeTraitExpr(nb::module_ &m) {
  nb::class_<UnaryExprOrTypeTraitExpr, Expr>(m, "UnaryExprOrTypeTraitExpr")
    .def_prop_ro("children", &UnaryExprOrTypeTraitExpr::Children)
    .def_prop_ro("argument_expression", &UnaryExprOrTypeTraitExpr::ArgumentExpression)
    .def_prop_ro("argument_type", &UnaryExprOrTypeTraitExpr::ArgumentType)
    .def_prop_ro("begin_token", &UnaryExprOrTypeTraitExpr::BeginToken)
    .def_prop_ro("end_token", &UnaryExprOrTypeTraitExpr::EndToken)
    .def_prop_ro("keyword_kind", &UnaryExprOrTypeTraitExpr::KeywordKind)
    .def_prop_ro("operator_token", &UnaryExprOrTypeTraitExpr::OperatorToken)
    .def_prop_ro("r_paren_token", &UnaryExprOrTypeTraitExpr::RParenToken)
    .def_prop_ro("type_of_argument", &UnaryExprOrTypeTraitExpr::TypeOfArgument)
    .def_prop_ro("is_argument_type", &UnaryExprOrTypeTraitExpr::IsArgumentType);
}
} // namespace pasta
