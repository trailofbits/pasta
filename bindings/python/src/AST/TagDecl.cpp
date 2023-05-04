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

void RegisterTagDecl(py::module_ &m) {
  py::class_<TagDecl, Decl, NamedDecl, TypeDecl>(m, "TagDecl")
    .def_property_readonly("BraceRange", &TagDecl::BraceRange)
    .def_property_readonly("CanonicalDeclaration", &TagDecl::CanonicalDeclaration)
    .def_property_readonly("Definition", &TagDecl::Definition)
    .def_property_readonly("FirstInnerToken", &TagDecl::FirstInnerToken)
    .def_property_readonly("KindName", &TagDecl::KindName)
    .def_property_readonly("NumTemplateParameterLists", &TagDecl::NumTemplateParameterLists)
    .def_property_readonly("FirstOuterToken", &TagDecl::FirstOuterToken)
    .def_property_readonly("TagKind", &TagDecl::TagKind)
    .def_property_readonly("TypedefNameForAnonymousDeclaration", &TagDecl::TypedefNameForAnonymousDeclaration)
    .def_property_readonly("HasNameForLinkage", &TagDecl::HasNameForLinkage)
    .def_property_readonly("IsBeingDefined", &TagDecl::IsBeingDefined)
    .def_property_readonly("IsClass", &TagDecl::IsClass)
    .def_property_readonly("IsCompleteDefinition", &TagDecl::IsCompleteDefinition)
    .def_property_readonly("IsCompleteDefinitionRequired", &TagDecl::IsCompleteDefinitionRequired)
    .def_property_readonly("IsDependentType", &TagDecl::IsDependentType)
    .def_property_readonly("IsEmbeddedInDeclarator", &TagDecl::IsEmbeddedInDeclarator)
    .def_property_readonly("IsEnum", &TagDecl::IsEnum)
    .def_property_readonly("IsFreeStanding", &TagDecl::IsFreeStanding)
    .def_property_readonly("IsInterface", &TagDecl::IsInterface)
    .def_property_readonly("IsStruct", &TagDecl::IsStruct)
    .def_property_readonly("IsThisDeclarationADefinition", &TagDecl::IsThisDeclarationADefinition)
    .def_property_readonly("IsThisDeclarationADemotedDefinition", &TagDecl::IsThisDeclarationADemotedDefinition)
    .def_property_readonly("IsUnion", &TagDecl::IsUnion)
    .def_property_readonly("MayHaveOutOfDateDefinition", &TagDecl::MayHaveOutOfDateDefinition);
}
} // namespace pasta
