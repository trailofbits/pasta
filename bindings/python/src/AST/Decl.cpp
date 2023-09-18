/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterDecl(nb::module_ &m) {
  nb::class_<Decl>(m, "Decl")
    .def("__hash__", [](const Decl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_static("cast", nb::overload_cast<const DeclContext &>(&Decl::From))
    .def_prop_ro("kind", &Decl::Kind)
    .def_prop_ro("kind_name", &Decl::KindName)
    .def_prop_ro("attributes", &Decl::Attributes)
    .def_prop_ro("access", &Decl::Access)
    .def_prop_ro("as_function", &Decl::AsFunction)
    .def_prop_ro("availability", &Decl::Availability)
    .def_prop_ro("begin_token", &Decl::BeginToken)
    .def_prop_ro("canonical_declaration", &Decl::CanonicalDeclaration)
    .def_prop_ro("declaration_context", &Decl::DeclarationContext)
    .def_prop_ro("defining_attribute", &Decl::DefiningAttribute)
    .def_prop_ro("described_template", &Decl::DescribedTemplate)
    .def_prop_ro("described_template_parameters", &Decl::DescribedTemplateParameters)
    .def_prop_ro("end_token", &Decl::EndToken)
    .def_prop_ro("external_source_symbol_attribute", &Decl::ExternalSourceSymbolAttribute)
    .def_prop_ro("friend_object_kind", &Decl::FriendObjectKind)
    .def_prop_ro("function_type", &Decl::FunctionType)
    .def_prop_ro("global_id", &Decl::GlobalID)
    .def_prop_ro("id", &Decl::ID)
    .def_prop_ro("identifier_namespace", &Decl::IdentifierNamespace)
    .def_prop_ro("lexical_declaration_context", &Decl::LexicalDeclarationContext)
    .def_prop_ro("max_alignment", &Decl::MaxAlignment)
    .def_prop_ro("module_ownership_kind", &Decl::ModuleOwnershipKind)
    .def_prop_ro("most_recent_declaration", &Decl::MostRecentDeclaration)
    .def_prop_ro("next_declaration_in_context", &Decl::NextDeclarationInContext)
    .def_prop_ro("non_closure_context", &Decl::NonClosureContext)
    .def_prop_ro("non_transparent_declaration_context", &Decl::NonTransparentDeclarationContext)
    .def_prop_ro("owning_module_id", &Decl::OwningModuleID)
    .def_prop_ro("parent_function_or_method", &Decl::ParentFunctionOrMethod)
    .def_prop_ro("previous_declaration", &Decl::PreviousDeclaration)
    .def_prop_ro("template_depth", &Decl::TemplateDepth)
    .def_prop_ro("translation_unit_declaration", &Decl::TranslationUnitDeclaration)
    .def_prop_ro("has_attributes", &Decl::HasAttributes)
    .def_prop_ro("has_body", &Decl::HasBody)
    .def_prop_ro("has_defining_attribute", &Decl::HasDefiningAttribute)
    .def_prop_ro("has_owning_module", &Decl::HasOwningModule)
    .def_prop_ro("has_tag_identifier_namespace", &Decl::HasTagIdentifierNamespace)
    .def_prop_ro("is_canonical_declaration", &Decl::IsCanonicalDeclaration)
    .def_prop_ro("is_defined_outside_function_or_method", &Decl::IsDefinedOutsideFunctionOrMethod)
    .def_prop_ro("is_deprecated", &Decl::IsDeprecated)
    .def_prop_ro("is_discarded_in_global_module_fragment", &Decl::IsDiscardedInGlobalModuleFragment)
    .def_prop_ro("is_file_context_declaration", &Decl::IsFileContextDeclaration)
    .def_prop_ro("is_first_declaration", &Decl::IsFirstDeclaration)
    .def_prop_ro("is_from_ast_file", &Decl::IsFromASTFile)
    .def_prop_ro("is_function_or_function_template", &Decl::IsFunctionOrFunctionTemplate)
    .def_prop_ro("is_function_pointer_type", &Decl::IsFunctionPointerType)
    .def_prop_ro("is_in_anonymous_namespace", &Decl::IsInAnonymousNamespace)
    .def_prop_ro("is_in_another_module_unit", &Decl::IsInAnotherModuleUnit)
    .def_prop_ro("is_in_export_declaration_context", &Decl::IsInExportDeclarationContext)
    .def_prop_ro("is_in_local_scope_for_instantiation", &Decl::IsInLocalScopeForInstantiation)
    .def_prop_ro("is_in_std_namespace", &Decl::IsInStdNamespace)
    .def_prop_ro("is_invalid_declaration", &Decl::IsInvalidDeclaration)
    .def_prop_ro("is_invisible_outside_the_owning_module", &Decl::IsInvisibleOutsideTheOwningModule)
    .def_prop_ro("is_local_extern_declaration", &Decl::IsLocalExternDeclaration)
    .def_prop_ro("is_module_private", &Decl::IsModulePrivate)
    .def_prop_ro("is_out_of_line", &Decl::IsOutOfLine)
    .def_prop_ro("is_parameter_pack", &Decl::IsParameterPack)
    .def_prop_ro("is_reachable", &Decl::IsReachable)
    .def_prop_ro("is_referenced", &Decl::IsReferenced)
    .def_prop_ro("is_template_declaration", &Decl::IsTemplateDeclaration)
    .def_prop_ro("is_template_parameter", &Decl::IsTemplateParameter)
    .def_prop_ro("is_template_parameter_pack", &Decl::IsTemplateParameterPack)
    .def_prop_ro("is_templated", &Decl::IsTemplated)
    .def_prop_ro("is_this_declaration_referenced", &Decl::IsThisDeclarationReferenced)
    .def_prop_ro("is_top_level_declaration_in_obj_c_container", &Decl::IsTopLevelDeclarationInObjCContainer)
    .def_prop_ro("is_unavailable", &Decl::IsUnavailable)
    .def_prop_ro("is_unconditionally_visible", &Decl::IsUnconditionallyVisible)
    .def_prop_ro("is_used", &Decl::IsUsed)
    .def_prop_ro("is_weak_imported", &Decl::IsWeakImported)
    .def_prop_ro("redeclarations", &Decl::Redeclarations)
    .def_prop_ro("is_implicit", &Decl::IsImplicit)
    .def_prop_ro("token", &Decl::Token);
}
} // namespace pasta
