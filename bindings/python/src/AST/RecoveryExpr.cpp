/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterRecoveryExpr(nb::module_ &m) {
  nb::class_<RecoveryExpr, Expr>(m, "RecoveryExpr")
    .def("__hash__", [](const RecoveryExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &RecoveryExpr::BeginToken)
    .def_prop_ro("end_token", &RecoveryExpr::EndToken)
    .def_prop_ro("sub_expressions", &RecoveryExpr::SubExpressions);
}
} // namespace pasta
