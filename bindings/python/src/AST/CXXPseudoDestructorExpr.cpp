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

void RegisterCXXPseudoDestructorExpr(nb::module_ &m) {
  nb::class_<CXXPseudoDestructorExpr, Expr>(m, "CXXPseudoDestructorExpr")
    .def("__hash__", [](const CXXPseudoDestructorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXPseudoDestructorExpr::Children)
    .def_prop_ro("base", &CXXPseudoDestructorExpr::Base)
    .def_prop_ro("begin_token", &CXXPseudoDestructorExpr::BeginToken)
    .def_prop_ro("colon_colon_token", &CXXPseudoDestructorExpr::ColonColonToken)
    .def_prop_ro("destroyed_type", &CXXPseudoDestructorExpr::DestroyedType)
    .def_prop_ro("destroyed_type_token", &CXXPseudoDestructorExpr::DestroyedTypeToken)
    .def_prop_ro("end_token", &CXXPseudoDestructorExpr::EndToken)
    .def_prop_ro("operator_token", &CXXPseudoDestructorExpr::OperatorToken)
    .def_prop_ro("scope_type", &CXXPseudoDestructorExpr::ScopeType)
    .def_prop_ro("tilde_token", &CXXPseudoDestructorExpr::TildeToken)
    .def_prop_ro("has_qualifier", &CXXPseudoDestructorExpr::HasQualifier)
    .def_prop_ro("is_arrow", &CXXPseudoDestructorExpr::IsArrow);
}
} // namespace pasta
