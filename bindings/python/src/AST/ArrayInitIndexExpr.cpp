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

void RegisterArrayInitIndexExpr(nb::module_ &m) {
  nb::class_<ArrayInitIndexExpr, Expr>(m, "ArrayInitIndexExpr")
    .def("__hash__", [](const ArrayInitIndexExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ArrayInitIndexExpr::Children)
    .def_prop_ro("begin_token", &ArrayInitIndexExpr::BeginToken)
    .def_prop_ro("end_token", &ArrayInitIndexExpr::EndToken);
}
} // namespace pasta
