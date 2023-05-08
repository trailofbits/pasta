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

void RegisterSubstNonTypeTemplateParmPackExpr(py::module_ &m) {
  py::class_<SubstNonTypeTemplateParmPackExpr, Expr>(m, "SubstNonTypeTemplateParmPackExpr")
    .def("__hash__", [](const SubstNonTypeTemplateParmPackExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SubstNonTypeTemplateParmPackExpr& a, const SubstNonTypeTemplateParmPackExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &SubstNonTypeTemplateParmPackExpr::Children)
    .def_property_readonly("AssociatedDeclaration", &SubstNonTypeTemplateParmPackExpr::AssociatedDeclaration)
    .def_property_readonly("BeginToken", &SubstNonTypeTemplateParmPackExpr::BeginToken)
    .def_property_readonly("EndToken", &SubstNonTypeTemplateParmPackExpr::EndToken)
    .def_property_readonly("Index", &SubstNonTypeTemplateParmPackExpr::Index)
    .def_property_readonly("ParameterPack", &SubstNonTypeTemplateParmPackExpr::ParameterPack)
    .def_property_readonly("ParameterPackToken", &SubstNonTypeTemplateParmPackExpr::ParameterPackToken);
}
} // namespace pasta
