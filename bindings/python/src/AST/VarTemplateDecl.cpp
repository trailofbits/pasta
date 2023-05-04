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

void RegisterVarTemplateDecl(py::module_ &m) {
  py::class_<VarTemplateDecl, Decl, NamedDecl, RedeclarableTemplateDecl, TemplateDecl>(m, "VarTemplateDecl")
    .def_property_readonly("CanonicalDeclaration", &VarTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromMemberTemplate", &VarTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("MostRecentDeclaration", &VarTemplateDecl::MostRecentDeclaration)
    .def_property_readonly("PreviousDeclaration", &VarTemplateDecl::PreviousDeclaration)
    .def_property_readonly("TemplatedDeclaration", &VarTemplateDecl::TemplatedDeclaration)
    .def_property_readonly("IsThisDeclarationADefinition", &VarTemplateDecl::IsThisDeclarationADefinition)
    .def_property_readonly("Specializations", &VarTemplateDecl::Specializations);
}
} // namespace pasta
