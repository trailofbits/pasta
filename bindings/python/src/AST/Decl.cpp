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

void RegisterDecl(py::module_ &m) {
  py::class_<Decl>(m, "Decl")
    .def("__hash__", [](const Decl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("attributes", &Decl::Attributes)
    .def_property_readonly("access", &Decl::Access)
    .def_property_readonly("as_function", &Decl::AsFunction)
    .def_property_readonly("availability", &Decl::Availability)
    .def_property_readonly("begin_token", &Decl::BeginToken)
    .def_property_readonly("canonical_declaration", &Decl::CanonicalDeclaration)
    .def_property_readonly("declaration_context", &Decl::DeclarationContext)
    .def_property_readonly("defining_attribute", &Decl::DefiningAttribute)
    .def_property_readonly("described_template", &Decl::DescribedTemplate)
    .def_property_readonly("described_template_parameters", &Decl::DescribedTemplateParameters)
    .def_property_readonly("end_token", &Decl::EndToken)
    .def_property_readonly("external_source_symbol_attribute", &Decl::ExternalSourceSymbolAttribute)
    .def_property_readonly("friend_object_kind", &Decl::FriendObjectKind)
    .def_property_readonly("function_type", &Decl::FunctionType)
    .def_property_readonly("global_id", &Decl::GlobalID)
    .def_property_readonly("id", &Decl::ID)
    .def_property_readonly("identifier_namespace", &Decl::IdentifierNamespace)
    .def_property_readonly("lexical_declaration_context", &Decl::LexicalDeclarationContext)
    .def_property_readonly("max_alignment", &Decl::MaxAlignment)
    .def_property_readonly("module_ownership_kind", &Decl::ModuleOwnershipKind)
    .def_property_readonly("most_recent_declaration", &Decl::MostRecentDeclaration)
    .def_property_readonly("next_declaration_in_context", &Decl::NextDeclarationInContext)
    .def_property_readonly("non_closure_context", &Decl::NonClosureContext)
    .def_property_readonly("non_transparent_declaration_context", &Decl::NonTransparentDeclarationContext)
    .def_property_readonly("owning_module_id", &Decl::OwningModuleID)
    .def_property_readonly("parent_function_or_method", &Decl::ParentFunctionOrMethod)
    .def_property_readonly("previous_declaration", &Decl::PreviousDeclaration)
    .def_property_readonly("template_depth", &Decl::TemplateDepth)
    .def_property_readonly("translation_unit_declaration", &Decl::TranslationUnitDeclaration)
    .def_property_readonly("has_attributes", &Decl::HasAttributes)
    .def_property_readonly("has_body", &Decl::HasBody)
    .def_property_readonly("has_defining_attribute", &Decl::HasDefiningAttribute)
    .def_property_readonly("has_owning_module", &Decl::HasOwningModule)
    .def_property_readonly("has_tag_identifier_namespace", &Decl::HasTagIdentifierNamespace)
    .def_property_readonly("is_canonical_declaration", &Decl::IsCanonicalDeclaration)
    .def_property_readonly("is_defined_outside_function_or_method", &Decl::IsDefinedOutsideFunctionOrMethod)
    .def_property_readonly("is_deprecated", &Decl::IsDeprecated)
    .def_property_readonly("is_discarded_in_global_module_fragment", &Decl::IsDiscardedInGlobalModuleFragment)
    .def_property_readonly("is_file_context_declaration", &Decl::IsFileContextDeclaration)
    .def_property_readonly("is_first_declaration", &Decl::IsFirstDeclaration)
    .def_property_readonly("is_from_ast_file", &Decl::IsFromASTFile)
    .def_property_readonly("is_function_or_function_template", &Decl::IsFunctionOrFunctionTemplate)
    .def_property_readonly("is_in_anonymous_namespace", &Decl::IsInAnonymousNamespace)
    .def_property_readonly("is_in_export_declaration_context", &Decl::IsInExportDeclarationContext)
    .def_property_readonly("is_in_local_scope_for_instantiation", &Decl::IsInLocalScopeForInstantiation)
    .def_property_readonly("is_in_std_namespace", &Decl::IsInStdNamespace)
    .def_property_readonly("is_invalid_declaration", &Decl::IsInvalidDeclaration)
    .def_property_readonly("is_invisible_outside_the_owning_module", &Decl::IsInvisibleOutsideTheOwningModule)
    .def_property_readonly("is_local_extern_declaration", &Decl::IsLocalExternDeclaration)
    .def_property_readonly("is_module_private", &Decl::IsModulePrivate)
    .def_property_readonly("is_out_of_line", &Decl::IsOutOfLine)
    .def_property_readonly("is_parameter_pack", &Decl::IsParameterPack)
    .def_property_readonly("is_reachable", &Decl::IsReachable)
    .def_property_readonly("is_referenced", &Decl::IsReferenced)
    .def_property_readonly("is_template_declaration", &Decl::IsTemplateDeclaration)
    .def_property_readonly("is_template_parameter", &Decl::IsTemplateParameter)
    .def_property_readonly("is_template_parameter_pack", &Decl::IsTemplateParameterPack)
    .def_property_readonly("is_templated", &Decl::IsTemplated)
    .def_property_readonly("is_this_declaration_referenced", &Decl::IsThisDeclarationReferenced)
    .def_property_readonly("is_top_level_declaration_in_obj_c_container", &Decl::IsTopLevelDeclarationInObjCContainer)
    .def_property_readonly("is_unavailable", &Decl::IsUnavailable)
    .def_property_readonly("is_unconditionally_visible", &Decl::IsUnconditionallyVisible)
    .def_property_readonly("is_used", &Decl::IsUsed)
    .def_property_readonly("is_weak_imported", &Decl::IsWeakImported)
    .def_property_readonly("redeclarations", &Decl::Redeclarations);
}
} // namespace pasta
