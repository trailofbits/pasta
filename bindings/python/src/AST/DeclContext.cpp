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
    .def_property_readonly("Declarations", &DeclContext::Declarations)
    .def_property_readonly("DeclarationKind", &DeclContext::DeclarationKind)
    .def_property_readonly("DeclarationKindName", &DeclContext::DeclarationKindName)
    .def_property_readonly("EnclosingNamespaceContext", &DeclContext::EnclosingNamespaceContext)
    .def_property_readonly("ExternCContext", &DeclContext::ExternCContext)
    .def_property_readonly("InnermostBlockDeclaration", &DeclContext::InnermostBlockDeclaration)
    .def_property_readonly("LexicalParent", &DeclContext::LexicalParent)
    .def_property_readonly("LookupParent", &DeclContext::LookupParent)
    .def_property_readonly("NonClosureAncestor", &DeclContext::NonClosureAncestor)
    .def_property_readonly("NonTransparentContext", &DeclContext::NonTransparentContext)
    .def_property_readonly("OuterLexicalRecordContext", &DeclContext::OuterLexicalRecordContext)
    .def_property_readonly("Parent", &DeclContext::Parent)
    .def_property_readonly("PrimaryContext", &DeclContext::PrimaryContext)
    .def_property_readonly("RedeclarationContext", &DeclContext::RedeclarationContext)
    .def_property_readonly("HasExternalLexicalStorage", &DeclContext::HasExternalLexicalStorage)
    .def_property_readonly("HasExternalVisibleStorage", &DeclContext::HasExternalVisibleStorage)
    .def_property_readonly("HasValidDeclarationKind", &DeclContext::HasValidDeclarationKind)
    .def_property_readonly("IsClosure", &DeclContext::IsClosure)
    .def_property_readonly("IsDependentContext", &DeclContext::IsDependentContext)
    .def_property_readonly("IsExternCContext", &DeclContext::IsExternCContext)
    .def_property_readonly("IsExternCXXContext", &DeclContext::IsExternCXXContext)
    .def_property_readonly("IsFileContext", &DeclContext::IsFileContext)
    .def_property_readonly("IsFunctionOrMethod", &DeclContext::IsFunctionOrMethod)
    .def_property_readonly("IsInlineNamespace", &DeclContext::IsInlineNamespace)
    .def_property_readonly("IsLookupContext", &DeclContext::IsLookupContext)
    .def_property_readonly("IsNamespace", &DeclContext::IsNamespace)
    .def_property_readonly("IsObjCContainer", &DeclContext::IsObjCContainer)
    .def_property_readonly("IsRecord", &DeclContext::IsRecord)
    .def_property_readonly("IsStdNamespace", &DeclContext::IsStdNamespace)
    .def_property_readonly("IsTranslationUnit", &DeclContext::IsTranslationUnit)
    .def_property_readonly("IsTransparentContext", &DeclContext::IsTransparentContext)
    .def_property_readonly("AlreadyLoadedDeclarations", &DeclContext::AlreadyLoadedDeclarations)
    .def_property_readonly("ShouldUseQualifiedLookup", &DeclContext::ShouldUseQualifiedLookup);
}
} // namespace pasta
