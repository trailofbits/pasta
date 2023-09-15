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

void RegisterCXXScalarValueInitExpr(nb::module_ &m) {
  nb::class_<CXXScalarValueInitExpr, Expr>(m, "CXXScalarValueInitExpr")
    .def("__hash__", [](const CXXScalarValueInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXScalarValueInitExpr::Children)
    .def_prop_ro("begin_token", &CXXScalarValueInitExpr::BeginToken)
    .def_prop_ro("end_token", &CXXScalarValueInitExpr::EndToken)
    .def_prop_ro("r_paren_token", &CXXScalarValueInitExpr::RParenToken)
    .def_prop_ro("type", &CXXScalarValueInitExpr::Type);
}
} // namespace pasta
