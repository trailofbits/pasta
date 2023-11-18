/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterTagDecl(nb::module_ &m) {
  nb::class_<TagDecl, TypeDecl>(m, "TagDecl")
    .def_prop_ro("brace_range", &TagDecl::BraceRange)
    .def_prop_ro("canonical_declaration", &TagDecl::CanonicalDeclaration)
    .def_prop_ro("definition", &TagDecl::Definition)
    .def_prop_ro("first_inner_token", &TagDecl::FirstInnerToken)
    .def_prop_ro("kind_name", &TagDecl::KindName)
    .def_prop_ro("num_template_parameter_lists", &TagDecl::NumTemplateParameterLists)
    .def_prop_ro("first_outer_token", &TagDecl::FirstOuterToken)
    .def_prop_ro("tag_kind", &TagDecl::TagKind)
    .def_prop_ro("typedef_name_for_anonymous_declaration", &TagDecl::TypedefNameForAnonymousDeclaration)
    .def_prop_ro("has_name_for_linkage", &TagDecl::HasNameForLinkage)
    .def_prop_ro("is_being_defined", &TagDecl::IsBeingDefined)
    .def_prop_ro("is_class", &TagDecl::IsClass)
    .def_prop_ro("is_complete_definition", &TagDecl::IsCompleteDefinition)
    .def_prop_ro("is_complete_definition_required", &TagDecl::IsCompleteDefinitionRequired)
    .def_prop_ro("is_dependent_type", &TagDecl::IsDependentType)
    .def_prop_ro("is_embedded_in_declarator", &TagDecl::IsEmbeddedInDeclarator)
    .def_prop_ro("is_enum", &TagDecl::IsEnum)
    .def_prop_ro("is_free_standing", &TagDecl::IsFreeStanding)
    .def_prop_ro("is_interface", &TagDecl::IsInterface)
    .def_prop_ro("is_struct", &TagDecl::IsStruct)
    .def_prop_ro("is_this_declaration_a_definition", &TagDecl::IsThisDeclarationADefinition)
    .def_prop_ro("is_this_declaration_a_demoted_definition", &TagDecl::IsThisDeclarationADemotedDefinition)
    .def_prop_ro("is_union", &TagDecl::IsUnion)
    .def_prop_ro("may_have_out_of_date_definition", &TagDecl::MayHaveOutOfDateDefinition);
}
} // namespace pasta
