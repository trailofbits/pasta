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

void RegisterCXXThisExpr(nb::module_ &m) {
  nb::class_<CXXThisExpr, Expr>(m, "CXXThisExpr")
    .def("__hash__", [](const CXXThisExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXThisExpr::Children)
    .def_prop_ro("begin_token", &CXXThisExpr::BeginToken)
    .def_prop_ro("end_token", &CXXThisExpr::EndToken)
    .def_prop_ro("token", &CXXThisExpr::Token)
    .def_prop_ro("is_implicit", &CXXThisExpr::IsImplicit);
}
} // namespace pasta
