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

void RegisterConceptDecl(nb::module_ &m) {
  nb::class_<ConceptDecl, TemplateDecl>(m, "ConceptDecl")
    .def_prop_ro("canonical_declaration", &ConceptDecl::CanonicalDeclaration)
    .def_prop_ro("constraint_expression", &ConceptDecl::ConstraintExpression)
    .def_prop_ro("is_type_concept", &ConceptDecl::IsTypeConcept);
}
} // namespace pasta
