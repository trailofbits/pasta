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

void RegisterConceptSpecializationExpr(py::module_ &m) {
  py::class_<ConceptSpecializationExpr, Expr, Stmt, ValueStmt>(m, "ConceptSpecializationExpr")
    .def_property_readonly("Children", &ConceptSpecializationExpr::Children)
    .def_property_readonly("BeginToken", &ConceptSpecializationExpr::BeginToken)
    .def_property_readonly("EndToken", &ConceptSpecializationExpr::EndToken)
    .def_property_readonly("SpecializationDeclaration", &ConceptSpecializationExpr::SpecializationDeclaration)
    .def_property_readonly("TemplateArguments", &ConceptSpecializationExpr::TemplateArguments)
    .def_property_readonly("IsSatisfied", &ConceptSpecializationExpr::IsSatisfied);
}
} // namespace pasta
