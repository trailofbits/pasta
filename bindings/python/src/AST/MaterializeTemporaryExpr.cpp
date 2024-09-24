/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterMaterializeTemporaryExpr(nb::module_ &m) {
  nb::class_<MaterializeTemporaryExpr, Expr>(m, "MaterializeTemporaryExpr")
    .def_prop_ro("children", &MaterializeTemporaryExpr::Children)
    .def_prop_ro("begin_token", &MaterializeTemporaryExpr::BeginToken)
    .def_prop_ro("end_token", &MaterializeTemporaryExpr::EndToken)
    .def_prop_ro("extending_declaration", &MaterializeTemporaryExpr::ExtendingDeclaration)
    .def_prop_ro("lifetime_extended_temporary_declaration", &MaterializeTemporaryExpr::LifetimeExtendedTemporaryDeclaration)
    .def_prop_ro("mangling_number", &MaterializeTemporaryExpr::ManglingNumber)
    .def_prop_ro("storage_duration", &MaterializeTemporaryExpr::StorageDuration)
    .def_prop_ro("sub_expression", &MaterializeTemporaryExpr::SubExpression)
    .def_prop_ro("is_bound_to_lvalue_reference", &MaterializeTemporaryExpr::IsBoundToLvalueReference)
    .def_prop_ro("is_usable_in_constant_expressions", &MaterializeTemporaryExpr::IsUsableInConstantExpressions);
}
} // namespace pasta
