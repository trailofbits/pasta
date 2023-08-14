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

void RegisterCXXParenListInitExpr(nb::module_ &m) {
  nb::class_<CXXParenListInitExpr, Expr>(m, "CXXParenListInitExpr")
    .def("__hash__", [](const CXXParenListInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXParenListInitExpr::Children)
    .def_prop_ro("array_filler", &CXXParenListInitExpr::ArrayFiller)
    .def_prop_ro("begin_token", &CXXParenListInitExpr::BeginToken)
    .def_prop_ro("end_token", &CXXParenListInitExpr::EndToken)
    .def_prop_ro("initializer_token", &CXXParenListInitExpr::InitializerToken)
    .def_prop_ro("initialized_field_in_union", &CXXParenListInitExpr::InitializedFieldInUnion)
    .def_prop_ro("tokens", &CXXParenListInitExpr::Tokens);
}
} // namespace pasta
