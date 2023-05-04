/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterConceptDecl(py::module_ &m) {
  py::class_<ConceptDecl, Decl, NamedDecl, TemplateDecl>(m, "ConceptDecl")
    .def_property_readonly("CanonicalDeclaration", &ConceptDecl::CanonicalDeclaration)
    .def_property_readonly("ConstraintExpression", &ConceptDecl::ConstraintExpression)
    .def_property_readonly("IsTypeConcept", &ConceptDecl::IsTypeConcept);
}
} // namespace pasta
