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

void RegisterShuffleVectorExpr(nb::module_ &m) {
  nb::class_<ShuffleVectorExpr, Expr>(m, "ShuffleVectorExpr")
    .def_prop_ro("children", &ShuffleVectorExpr::Children)
    .def_prop_ro("begin_token", &ShuffleVectorExpr::BeginToken)
    .def_prop_ro("builtin_token", &ShuffleVectorExpr::BuiltinToken)
    .def_prop_ro("end_token", &ShuffleVectorExpr::EndToken)
    .def_prop_ro("num_sub_expressions", &ShuffleVectorExpr::NumSubExpressions)
    .def_prop_ro("r_paren_token", &ShuffleVectorExpr::RParenToken);
}
} // namespace pasta
