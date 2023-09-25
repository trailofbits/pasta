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

void RegisterArrayTypeTraitExpr(nb::module_ &m) {
  nb::class_<ArrayTypeTraitExpr, Expr>(m, "ArrayTypeTraitExpr")
    .def("__hash__", [](const ArrayTypeTraitExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ArrayTypeTraitExpr::Children)
    .def_prop_ro("begin_token", &ArrayTypeTraitExpr::BeginToken)
    .def_prop_ro("dimension_expression", &ArrayTypeTraitExpr::DimensionExpression)
    .def_prop_ro("end_token", &ArrayTypeTraitExpr::EndToken)
    .def_prop_ro("queried_type", &ArrayTypeTraitExpr::QueriedType)
    .def_prop_ro("trait", &ArrayTypeTraitExpr::Trait)
    .def_prop_ro("value", &ArrayTypeTraitExpr::Value);
}
} // namespace pasta
