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
  py::class_<ConceptSpecializationExpr, Expr>(m, "ConceptSpecializationExpr")
    .def("__hash__", [](const ConceptSpecializationExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ConceptSpecializationExpr& a, const ConceptSpecializationExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ConceptSpecializationExpr::Children)
    .def_property_readonly("begin_token", &ConceptSpecializationExpr::BeginToken)
    .def_property_readonly("end_token", &ConceptSpecializationExpr::EndToken)
    .def_property_readonly("specialization_declaration", &ConceptSpecializationExpr::SpecializationDeclaration)
    .def_property_readonly("template_arguments", &ConceptSpecializationExpr::TemplateArguments)
    .def_property_readonly("is_satisfied", &ConceptSpecializationExpr::IsSatisfied);
}
} // namespace pasta
