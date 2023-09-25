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

void RegisterConceptSpecializationExpr(nb::module_ &m) {
  nb::class_<ConceptSpecializationExpr, Expr>(m, "ConceptSpecializationExpr")
    .def("__hash__", [](const ConceptSpecializationExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ConceptSpecializationExpr::Children)
    .def_prop_ro("begin_token", &ConceptSpecializationExpr::BeginToken)
    .def_prop_ro("concept_name_token", &ConceptSpecializationExpr::ConceptNameToken)
    .def_prop_ro("end_token", &ConceptSpecializationExpr::EndToken)
    .def_prop_ro("expression_token", &ConceptSpecializationExpr::ExpressionToken)
    .def_prop_ro("found_declaration", &ConceptSpecializationExpr::FoundDeclaration)
    .def_prop_ro("named_concept", &ConceptSpecializationExpr::NamedConcept)
    .def_prop_ro("specialization_declaration", &ConceptSpecializationExpr::SpecializationDeclaration)
    .def_prop_ro("template_arguments", &ConceptSpecializationExpr::TemplateArguments)
    .def_prop_ro("template_keyword_token", &ConceptSpecializationExpr::TemplateKeywordToken)
    .def_prop_ro("has_explicit_template_arguments", &ConceptSpecializationExpr::HasExplicitTemplateArguments)
    .def_prop_ro("is_satisfied", &ConceptSpecializationExpr::IsSatisfied);
}
} // namespace pasta
