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

void RegisterNonTypeTemplateParmDecl(py::module_ &m) {
  py::class_<NonTypeTemplateParmDecl, Decl, DeclaratorDecl, NamedDecl, ValueDecl>(m, "NonTypeTemplateParmDecl")
    .def_property_readonly("DefaultArgumentWasInherited", &NonTypeTemplateParmDecl::DefaultArgumentWasInherited)
    .def_property_readonly("DefaultArgument", &NonTypeTemplateParmDecl::DefaultArgument)
    .def_property_readonly("DefaultArgumentToken", &NonTypeTemplateParmDecl::DefaultArgumentToken)
    .def_property_readonly("NumExpansionTypes", &NonTypeTemplateParmDecl::NumExpansionTypes)
    .def_property_readonly("PlaceholderTypeConstraint", &NonTypeTemplateParmDecl::PlaceholderTypeConstraint)
    .def_property_readonly("HasDefaultArgument", &NonTypeTemplateParmDecl::HasDefaultArgument)
    .def_property_readonly("HasPlaceholderTypeConstraint", &NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint)
    .def_property_readonly("IsExpandedParameterPack", &NonTypeTemplateParmDecl::IsExpandedParameterPack)
    .def_property_readonly("IsPackExpansion", &NonTypeTemplateParmDecl::IsPackExpansion)
    .def_property_readonly("IsParameterPack", &NonTypeTemplateParmDecl::IsParameterPack);
}
} // namespace pasta
