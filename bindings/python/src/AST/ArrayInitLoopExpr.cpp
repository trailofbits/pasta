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

void RegisterArrayInitLoopExpr(nb::module_ &m) {
  nb::class_<ArrayInitLoopExpr, Expr>(m, "ArrayInitLoopExpr")
    .def("__hash__", [](const ArrayInitLoopExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ArrayInitLoopExpr::Children)
    .def_prop_ro("array_size", &ArrayInitLoopExpr::ArraySize)
    .def_prop_ro("begin_token", &ArrayInitLoopExpr::BeginToken)
    .def_prop_ro("common_expression", &ArrayInitLoopExpr::CommonExpression)
    .def_prop_ro("end_token", &ArrayInitLoopExpr::EndToken)
    .def_prop_ro("sub_expression", &ArrayInitLoopExpr::SubExpression);
}
} // namespace pasta
