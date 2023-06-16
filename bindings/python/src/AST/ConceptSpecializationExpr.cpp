/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterConceptSpecializationExpr(nb::module_ &m) {
  nb::class_<ConceptSpecializationExpr, Expr>(m, "ConceptSpecializationExpr")
    .def("__hash__", [](const ConceptSpecializationExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ConceptSpecializationExpr::Children)
    .def_prop_ro("begin_token", &ConceptSpecializationExpr::BeginToken)
    .def_prop_ro("end_token", &ConceptSpecializationExpr::EndToken)
    .def_prop_ro("specialization_declaration", &ConceptSpecializationExpr::SpecializationDeclaration)
    .def_prop_ro("template_arguments", &ConceptSpecializationExpr::TemplateArguments)
    .def_prop_ro("is_satisfied", &ConceptSpecializationExpr::IsSatisfied);
}
} // namespace pasta
