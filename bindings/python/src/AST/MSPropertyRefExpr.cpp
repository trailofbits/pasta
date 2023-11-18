/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterMSPropertyRefExpr(nb::module_ &m) {
  nb::class_<MSPropertyRefExpr, Expr>(m, "MSPropertyRefExpr")
    .def_prop_ro("children", &MSPropertyRefExpr::Children)
    .def_prop_ro("base_expression", &MSPropertyRefExpr::BaseExpression)
    .def_prop_ro("begin_token", &MSPropertyRefExpr::BeginToken)
    .def_prop_ro("end_token", &MSPropertyRefExpr::EndToken)
    .def_prop_ro("member_token", &MSPropertyRefExpr::MemberToken)
    .def_prop_ro("property_declaration", &MSPropertyRefExpr::PropertyDeclaration)
    .def_prop_ro("tokens", &MSPropertyRefExpr::Tokens)
    .def_prop_ro("is_arrow", &MSPropertyRefExpr::IsArrow)
    .def_prop_ro("is_implicit_access", &MSPropertyRefExpr::IsImplicitAccess);
}
} // namespace pasta
