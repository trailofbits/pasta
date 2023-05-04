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

void RegisterSubstNonTypeTemplateParmExpr(py::module_ &m) {
  py::class_<SubstNonTypeTemplateParmExpr, Expr, Stmt, ValueStmt>(m, "SubstNonTypeTemplateParmExpr")
    .def_property_readonly("Children", &SubstNonTypeTemplateParmExpr::Children)
    .def_property_readonly("AssociatedDeclaration", &SubstNonTypeTemplateParmExpr::AssociatedDeclaration)
    .def_property_readonly("BeginToken", &SubstNonTypeTemplateParmExpr::BeginToken)
    .def_property_readonly("EndToken", &SubstNonTypeTemplateParmExpr::EndToken)
    .def_property_readonly("Index", &SubstNonTypeTemplateParmExpr::Index)
    .def_property_readonly("NameToken", &SubstNonTypeTemplateParmExpr::NameToken)
    .def_property_readonly("PackIndex", &SubstNonTypeTemplateParmExpr::PackIndex)
    .def_property_readonly("Parameter", &SubstNonTypeTemplateParmExpr::Parameter)
    .def("ParameterType", &SubstNonTypeTemplateParmExpr::ParameterType)
    .def_property_readonly("Replacement", &SubstNonTypeTemplateParmExpr::Replacement)
    .def_property_readonly("IsReferenceParameter", &SubstNonTypeTemplateParmExpr::IsReferenceParameter);
}
} // namespace pasta
