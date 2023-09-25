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

void RegisterImplicitValueInitExpr(nb::module_ &m) {
  nb::class_<ImplicitValueInitExpr, Expr>(m, "ImplicitValueInitExpr")
    .def("__hash__", [](const ImplicitValueInitExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ImplicitValueInitExpr::Children)
    .def_prop_ro("begin_token", &ImplicitValueInitExpr::BeginToken)
    .def_prop_ro("end_token", &ImplicitValueInitExpr::EndToken);
}
} // namespace pasta
