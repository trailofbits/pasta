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

void RegisterConceptSpecializationExpr(nb::module_ &m) {
  nb::class_<ConceptSpecializationExpr, Expr>(m, "ConceptSpecializationExpr")
    .def_prop_ro("children", &ConceptSpecializationExpr::Children)
    .def_prop_ro("begin_token", &ConceptSpecializationExpr::BeginToken)
    .def_prop_ro("end_token", &ConceptSpecializationExpr::EndToken)
    .def_prop_ro("specialization_declaration", &ConceptSpecializationExpr::SpecializationDeclaration)
    .def_prop_ro("template_arguments", &ConceptSpecializationExpr::TemplateArguments)
    .def_prop_ro("is_satisfied", &ConceptSpecializationExpr::IsSatisfied);
}
} // namespace pasta
