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

void RegisterUnresolvedMemberExpr(nb::module_ &m) {
  nb::class_<UnresolvedMemberExpr, OverloadExpr>(m, "UnresolvedMemberExpr")
    .def("__hash__", [](const UnresolvedMemberExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &UnresolvedMemberExpr::Children)
    .def_prop_ro("base", &UnresolvedMemberExpr::Base)
    .def_prop_ro("base_type", &UnresolvedMemberExpr::BaseType)
    .def_prop_ro("begin_token", &UnresolvedMemberExpr::BeginToken)
    .def_prop_ro("end_token", &UnresolvedMemberExpr::EndToken)
    .def_prop_ro("expression_token", &UnresolvedMemberExpr::ExpressionToken)
    .def_prop_ro("member_token", &UnresolvedMemberExpr::MemberToken)
    .def_prop_ro("naming_class", &UnresolvedMemberExpr::NamingClass)
    .def_prop_ro("operator_token", &UnresolvedMemberExpr::OperatorToken)
    .def_prop_ro("has_unresolved_using", &UnresolvedMemberExpr::HasUnresolvedUsing)
    .def_prop_ro("is_arrow", &UnresolvedMemberExpr::IsArrow)
    .def_prop_ro("is_implicit_access", &UnresolvedMemberExpr::IsImplicitAccess);
}
} // namespace pasta
