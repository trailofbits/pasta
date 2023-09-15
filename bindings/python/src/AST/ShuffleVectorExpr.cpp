/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterShuffleVectorExpr(nb::module_ &m) {
  nb::class_<ShuffleVectorExpr, Expr>(m, "ShuffleVectorExpr")
    .def("__hash__", [](const ShuffleVectorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ShuffleVectorExpr::Children)
    .def_prop_ro("begin_token", &ShuffleVectorExpr::BeginToken)
    .def_prop_ro("builtin_token", &ShuffleVectorExpr::BuiltinToken)
    .def_prop_ro("end_token", &ShuffleVectorExpr::EndToken)
    .def_prop_ro("num_sub_expressions", &ShuffleVectorExpr::NumSubExpressions)
    .def_prop_ro("r_paren_token", &ShuffleVectorExpr::RParenToken);
}
} // namespace pasta
