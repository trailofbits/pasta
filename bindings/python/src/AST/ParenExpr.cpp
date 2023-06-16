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

void RegisterParenExpr(nb::module_ &m) {
  nb::class_<ParenExpr, Expr>(m, "ParenExpr")
    .def("__hash__", [](const ParenExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ParenExpr::Children)
    .def_prop_ro("begin_token", &ParenExpr::BeginToken)
    .def_prop_ro("end_token", &ParenExpr::EndToken)
    .def_prop_ro("l_paren_token", &ParenExpr::LParenToken)
    .def_prop_ro("r_paren_token", &ParenExpr::RParenToken)
    .def_prop_ro("sub_expression", &ParenExpr::SubExpression);
}
} // namespace pasta
