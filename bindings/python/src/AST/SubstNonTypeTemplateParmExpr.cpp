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

void RegisterSubstNonTypeTemplateParmExpr(nb::module_ &m) {
  nb::class_<SubstNonTypeTemplateParmExpr, Expr>(m, "SubstNonTypeTemplateParmExpr")
    .def_prop_ro("children", &SubstNonTypeTemplateParmExpr::Children)
    .def_prop_ro("associated_declaration", &SubstNonTypeTemplateParmExpr::AssociatedDeclaration)
    .def_prop_ro("begin_token", &SubstNonTypeTemplateParmExpr::BeginToken)
    .def_prop_ro("end_token", &SubstNonTypeTemplateParmExpr::EndToken)
    .def_prop_ro("index", &SubstNonTypeTemplateParmExpr::Index)
    .def_prop_ro("name_token", &SubstNonTypeTemplateParmExpr::NameToken)
    .def_prop_ro("pack_index", &SubstNonTypeTemplateParmExpr::PackIndex)
    .def_prop_ro("parameter", &SubstNonTypeTemplateParmExpr::Parameter)
    .def_prop_ro("parameter_type", &SubstNonTypeTemplateParmExpr::ParameterType)
    .def_prop_ro("replacement", &SubstNonTypeTemplateParmExpr::Replacement)
    .def_prop_ro("is_reference_parameter", &SubstNonTypeTemplateParmExpr::IsReferenceParameter);
}
} // namespace pasta
