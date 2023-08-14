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

void RegisterGenericSelectionExpr(nb::module_ &m) {
  nb::class_<GenericSelectionExpr, Expr>(m, "GenericSelectionExpr")
    .def("__hash__", [](const GenericSelectionExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &GenericSelectionExpr::Children)
    .def_prop_ro("association_expressions", &GenericSelectionExpr::AssociationExpressions)
    .def_prop_ro("begin_token", &GenericSelectionExpr::BeginToken)
    .def_prop_ro("controlling_expression", &GenericSelectionExpr::ControllingExpression)
    .def_prop_ro("default_token", &GenericSelectionExpr::DefaultToken)
    .def_prop_ro("end_token", &GenericSelectionExpr::EndToken)
    .def_prop_ro("generic_token", &GenericSelectionExpr::GenericToken)
    .def_prop_ro("num_associations", &GenericSelectionExpr::NumAssociations)
    .def_prop_ro("r_paren_token", &GenericSelectionExpr::RParenToken)
    .def_prop_ro("result_expression", &GenericSelectionExpr::ResultExpression)
    .def_prop_ro("result_index", &GenericSelectionExpr::ResultIndex)
    .def_prop_ro("is_result_dependent", &GenericSelectionExpr::IsResultDependent);
}
} // namespace pasta
