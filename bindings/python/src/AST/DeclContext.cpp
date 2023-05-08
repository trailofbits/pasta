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

void RegisterDeclContext(py::module_ &m) {
  py::class_<DeclContext>(m, "DeclContext")
    .def_property_readonly("declarations", &DeclContext::Declarations)
    .def_property_readonly("declaration_kind", &DeclContext::DeclarationKind)
    .def_property_readonly("declaration_kind_name", &DeclContext::DeclarationKindName)
    .def_property_readonly("enclosing_namespace_context", &DeclContext::EnclosingNamespaceContext)
    .def_property_readonly("extern_c_context", &DeclContext::ExternCContext)
    .def_property_readonly("innermost_block_declaration", &DeclContext::InnermostBlockDeclaration)
    .def_property_readonly("lexical_parent", &DeclContext::LexicalParent)
    .def_property_readonly("lookup_parent", &DeclContext::LookupParent)
    .def_property_readonly("non_closure_ancestor", &DeclContext::NonClosureAncestor)
    .def_property_readonly("non_transparent_context", &DeclContext::NonTransparentContext)
    .def_property_readonly("outer_lexical_record_context", &DeclContext::OuterLexicalRecordContext)
    .def_property_readonly("parent", &DeclContext::Parent)
    .def_property_readonly("primary_context", &DeclContext::PrimaryContext)
    .def_property_readonly("redeclaration_context", &DeclContext::RedeclarationContext)
    .def_property_readonly("has_external_lexical_storage", &DeclContext::HasExternalLexicalStorage)
    .def_property_readonly("has_external_visible_storage", &DeclContext::HasExternalVisibleStorage)
    .def_property_readonly("has_valid_declaration_kind", &DeclContext::HasValidDeclarationKind)
    .def_property_readonly("is_closure", &DeclContext::IsClosure)
    .def_property_readonly("is_dependent_context", &DeclContext::IsDependentContext)
    .def_property_readonly("is_extern_c_context", &DeclContext::IsExternCContext)
    .def_property_readonly("is_extern_cxx_context", &DeclContext::IsExternCXXContext)
    .def_property_readonly("is_file_context", &DeclContext::IsFileContext)
    .def_property_readonly("is_function_or_method", &DeclContext::IsFunctionOrMethod)
    .def_property_readonly("is_inline_namespace", &DeclContext::IsInlineNamespace)
    .def_property_readonly("is_lookup_context", &DeclContext::IsLookupContext)
    .def_property_readonly("is_namespace", &DeclContext::IsNamespace)
    .def_property_readonly("is_obj_c_container", &DeclContext::IsObjCContainer)
    .def_property_readonly("is_record", &DeclContext::IsRecord)
    .def_property_readonly("is_std_namespace", &DeclContext::IsStdNamespace)
    .def_property_readonly("is_translation_unit", &DeclContext::IsTranslationUnit)
    .def_property_readonly("is_transparent_context", &DeclContext::IsTransparentContext)
    .def_property_readonly("already_loaded_declarations", &DeclContext::AlreadyLoadedDeclarations)
    .def_property_readonly("should_use_qualified_lookup", &DeclContext::ShouldUseQualifiedLookup);
}
} // namespace pasta
