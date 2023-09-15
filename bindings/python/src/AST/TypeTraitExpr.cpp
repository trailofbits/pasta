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

void RegisterTypeTraitExpr(nb::module_ &m) {
  nb::class_<TypeTraitExpr, Expr>(m, "TypeTraitExpr")
    .def("__hash__", [](const TypeTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &TypeTraitExpr::Children)
    .def_prop_ro("begin_token", &TypeTraitExpr::BeginToken)
    .def_prop_ro("end_token", &TypeTraitExpr::EndToken)
    .def_prop_ro("num_arguments", &TypeTraitExpr::NumArguments)
    .def_prop_ro("trait", &TypeTraitExpr::Trait)
    .def_prop_ro("value", &TypeTraitExpr::Value);
}
} // namespace pasta
