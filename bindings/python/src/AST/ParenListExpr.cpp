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

void RegisterParenListExpr(nb::module_ &m) {
  nb::class_<ParenListExpr, Expr>(m, "ParenListExpr")
    .def("__hash__", [](const ParenListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ParenListExpr::Children)
    .def_prop_ro("begin_token", &ParenListExpr::BeginToken)
    .def_prop_ro("end_token", &ParenListExpr::EndToken)
    .def_prop_ro("l_paren_token", &ParenListExpr::LParenToken)
    .def_prop_ro("num_expressions", &ParenListExpr::NumExpressions)
    .def_prop_ro("r_paren_token", &ParenListExpr::RParenToken);
}
} // namespace pasta
