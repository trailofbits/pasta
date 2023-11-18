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

void RegisterOpaqueValueExpr(nb::module_ &m) {
  nb::class_<OpaqueValueExpr, Expr>(m, "OpaqueValueExpr")
    .def_prop_ro("children", &OpaqueValueExpr::Children)
    .def_prop_ro("begin_token", &OpaqueValueExpr::BeginToken)
    .def_prop_ro("end_token", &OpaqueValueExpr::EndToken)
    .def_prop_ro("expression_token", &OpaqueValueExpr::ExpressionToken)
    .def_prop_ro("token", &OpaqueValueExpr::Token)
    .def_prop_ro("source_expression", &OpaqueValueExpr::SourceExpression)
    .def_prop_ro("is_unique", &OpaqueValueExpr::IsUnique);
}
} // namespace pasta
