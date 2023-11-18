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

void RegisterSubstNonTypeTemplateParmPackExpr(nb::module_ &m) {
  nb::class_<SubstNonTypeTemplateParmPackExpr, Expr>(m, "SubstNonTypeTemplateParmPackExpr")
    .def_prop_ro("children", &SubstNonTypeTemplateParmPackExpr::Children)
    .def_prop_ro("associated_declaration", &SubstNonTypeTemplateParmPackExpr::AssociatedDeclaration)
    .def_prop_ro("begin_token", &SubstNonTypeTemplateParmPackExpr::BeginToken)
    .def_prop_ro("end_token", &SubstNonTypeTemplateParmPackExpr::EndToken)
    .def_prop_ro("index", &SubstNonTypeTemplateParmPackExpr::Index)
    .def_prop_ro("parameter_pack", &SubstNonTypeTemplateParmPackExpr::ParameterPack)
    .def_prop_ro("parameter_pack_token", &SubstNonTypeTemplateParmPackExpr::ParameterPackToken);
}
} // namespace pasta
