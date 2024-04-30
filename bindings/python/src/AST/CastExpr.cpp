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

void RegisterCastExpr(nb::module_ &m) {
  nb::class_<CastExpr, Expr>(m, "CastExpr")
    .def_prop_ro("changes_volatile_qualification", &CastExpr::ChangesVolatileQualification)
    .def_prop_ro("children", &CastExpr::Children)
    .def_prop_ro("cast_kind", &CastExpr::CastKind)
    .def_prop_ro("cast_kind_name", &CastExpr::CastKindName)
    .def_prop_ro("conversion_function", &CastExpr::ConversionFunction)
    .def_prop_ro("sub_expression", &CastExpr::SubExpression)
    .def_prop_ro("sub_expression_as_written", &CastExpr::SubExpressionAsWritten)
    .def_prop_ro("target_union_field", &CastExpr::TargetUnionField)
    .def_prop_ro("has_stored_fp_features", &CastExpr::HasStoredFPFeatures);
}
} // namespace pasta
