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

void RegisterStmtExpr(nb::module_ &m) {
  nb::class_<StmtExpr, Expr>(m, "StmtExpr")
    .def("__hash__", [](const StmtExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &StmtExpr::Children)
    .def_prop_ro("begin_token", &StmtExpr::BeginToken)
    .def_prop_ro("end_token", &StmtExpr::EndToken)
    .def_prop_ro("l_paren_token", &StmtExpr::LParenToken)
    .def_prop_ro("r_paren_token", &StmtExpr::RParenToken)
    .def_prop_ro("sub_statement", &StmtExpr::SubStatement)
    .def_prop_ro("template_depth", &StmtExpr::TemplateDepth);
}
} // namespace pasta
