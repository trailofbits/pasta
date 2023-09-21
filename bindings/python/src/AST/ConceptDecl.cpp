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

void RegisterConceptDecl(nb::module_ &m) {
  nb::class_<ConceptDecl, TemplateDecl>(m, "ConceptDecl")
    .def("__hash__", [](const ConceptDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &ConceptDecl::CanonicalDeclaration)
    .def_prop_ro("constraint_expression", &ConceptDecl::ConstraintExpression)
    .def_prop_ro("is_type_concept", &ConceptDecl::IsTypeConcept);
}
} // namespace pasta
