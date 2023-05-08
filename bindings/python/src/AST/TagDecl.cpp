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
  py::class_<TagDecl, TypeDecl>(m, "TagDecl")
    .def("__hash__", [](const TagDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TagDecl& a, const TagDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("brace_range", &TagDecl::BraceRange)
    .def_property_readonly("canonical_declaration", &TagDecl::CanonicalDeclaration)
    .def_property_readonly("definition", &TagDecl::Definition)
    .def_property_readonly("first_inner_token", &TagDecl::FirstInnerToken)
    .def_property_readonly("kind_name", &TagDecl::KindName)
    .def_property_readonly("num_template_parameter_lists", &TagDecl::NumTemplateParameterLists)
    .def_property_readonly("first_outer_token", &TagDecl::FirstOuterToken)
    .def_property_readonly("tag_kind", &TagDecl::TagKind)
    .def_property_readonly("typedef_name_for_anonymous_declaration", &TagDecl::TypedefNameForAnonymousDeclaration)
    .def_property_readonly("has_name_for_linkage", &TagDecl::HasNameForLinkage)
    .def_property_readonly("is_being_defined", &TagDecl::IsBeingDefined)
    .def_property_readonly("is_class", &TagDecl::IsClass)
    .def_property_readonly("is_complete_definition", &TagDecl::IsCompleteDefinition)
    .def_property_readonly("is_complete_definition_required", &TagDecl::IsCompleteDefinitionRequired)
    .def_property_readonly("is_dependent_type", &TagDecl::IsDependentType)
    .def_property_readonly("is_embedded_in_declarator", &TagDecl::IsEmbeddedInDeclarator)
    .def_property_readonly("is_enum", &TagDecl::IsEnum)
    .def_property_readonly("is_free_standing", &TagDecl::IsFreeStanding)
    .def_property_readonly("is_interface", &TagDecl::IsInterface)
    .def_property_readonly("is_struct", &TagDecl::IsStruct)
    .def_property_readonly("is_this_declaration_a_definition", &TagDecl::IsThisDeclarationADefinition)
    .def_property_readonly("is_this_declaration_a_demoted_definition", &TagDecl::IsThisDeclarationADemotedDefinition)
    .def_property_readonly("is_union", &TagDecl::IsUnion)
    .def_property_readonly("may_have_out_of_date_definition", &TagDecl::MayHaveOutOfDateDefinition);
}
} // namespace pasta
