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

void RegisterImplicitCastExpr(nb::module_ &m) {
  nb::class_<ImplicitCastExpr, CastExpr>(m, "ImplicitCastExpr")
    .def("__hash__", [](const ImplicitCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &ImplicitCastExpr::BeginToken)
    .def_prop_ro("end_token", &ImplicitCastExpr::EndToken)
    .def_prop_ro("is_part_of_explicit_cast", &ImplicitCastExpr::IsPartOfExplicitCast);
}
} // namespace pasta
