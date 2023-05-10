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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterConceptDecl(py::module_ &m) {
  py::class_<ConceptDecl, TemplateDecl>(m, "ConceptDecl")
    .def("__hash__", [](const ConceptDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ConceptDecl& a, const ConceptDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &ConceptDecl::CanonicalDeclaration)
    .def_property_readonly("constraint_expression", &ConceptDecl::ConstraintExpression)
    .def_property_readonly("is_type_concept", &ConceptDecl::IsTypeConcept);
}
} // namespace pasta
