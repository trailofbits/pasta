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

void RegisterRequiresExpr(nb::module_ &m) {
  nb::class_<RequiresExpr, Expr>(m, "RequiresExpr")
    .def("__hash__", [](const RequiresExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &RequiresExpr::Children)
    .def_prop_ro("begin_token", &RequiresExpr::BeginToken)
    .def_prop_ro("body", &RequiresExpr::Body)
    .def_prop_ro("end_token", &RequiresExpr::EndToken)
    .def_prop_ro("local_parameters", &RequiresExpr::LocalParameters)
    .def_prop_ro("r_brace_token", &RequiresExpr::RBraceToken)
    .def_prop_ro("requires_keyword_token", &RequiresExpr::RequiresKeywordToken)
    .def_prop_ro("is_satisfied", &RequiresExpr::IsSatisfied);
}
} // namespace pasta
