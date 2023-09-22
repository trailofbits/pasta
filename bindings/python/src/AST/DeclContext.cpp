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

void RegisterDeclContext(nb::module_ &m) {
  nb::class_<DeclContext>(m, "DeclContext")
    .def("__hash__", [](const DeclContext &decl) { return (intptr_t)decl.RawDeclContext(); })
    .def("__eq__", [](const DeclContext &a, const DeclContext &b) { return a.RawDeclContext() == b.RawDeclContext(); })
    .def("__ne__", [](const DeclContext &a, const DeclContext &b) { return a.RawDeclContext() != b.RawDeclContext(); })
    .def_prop_ro("declarations", &DeclContext::Declarations)
    .def_prop_ro("declaration_kind", &DeclContext::DeclarationKind)
    .def_prop_ro("declaration_kind_name", &DeclContext::DeclarationKindName)
    .def_prop_ro("enclosing_namespace_context", &DeclContext::EnclosingNamespaceContext)
    .def_prop_ro("extern_c_context", &DeclContext::ExternCContext)
    .def_prop_ro("innermost_block_declaration", &DeclContext::InnermostBlockDeclaration)
    .def_prop_ro("lexical_parent", &DeclContext::LexicalParent)
    .def_prop_ro("lookup_parent", &DeclContext::LookupParent)
    .def_prop_ro("non_closure_ancestor", &DeclContext::NonClosureAncestor)
    .def_prop_ro("non_transparent_context", &DeclContext::NonTransparentContext)
    .def_prop_ro("outer_lexical_record_context", &DeclContext::OuterLexicalRecordContext)
    .def_prop_ro("parent", &DeclContext::Parent)
    .def_prop_ro("primary_context", &DeclContext::PrimaryContext)
    .def_prop_ro("redeclaration_context", &DeclContext::RedeclarationContext)
    .def_prop_ro("has_external_lexical_storage", &DeclContext::HasExternalLexicalStorage)
    .def_prop_ro("has_external_visible_storage", &DeclContext::HasExternalVisibleStorage)
    .def_prop_ro("has_valid_declaration_kind", &DeclContext::HasValidDeclarationKind)
    .def_prop_ro("is_closure", &DeclContext::IsClosure)
    .def_prop_ro("is_dependent_context", &DeclContext::IsDependentContext)
    .def_prop_ro("is_extern_c_context", &DeclContext::IsExternCContext)
    .def_prop_ro("is_extern_cxx_context", &DeclContext::IsExternCXXContext)
    .def_prop_ro("is_file_context", &DeclContext::IsFileContext)
    .def_prop_ro("is_function_or_method", &DeclContext::IsFunctionOrMethod)
    .def_prop_ro("is_inline_namespace", &DeclContext::IsInlineNamespace)
    .def_prop_ro("is_lookup_context", &DeclContext::IsLookupContext)
    .def_prop_ro("is_namespace", &DeclContext::IsNamespace)
    .def_prop_ro("is_obj_c_container", &DeclContext::IsObjCContainer)
    .def_prop_ro("is_record", &DeclContext::IsRecord)
    .def_prop_ro("is_std_namespace", &DeclContext::IsStdNamespace)
    .def_prop_ro("is_translation_unit", &DeclContext::IsTranslationUnit)
    .def_prop_ro("is_transparent_context", &DeclContext::IsTransparentContext)
    .def_prop_ro("already_loaded_declarations", &DeclContext::AlreadyLoadedDeclarations)
    .def_prop_ro("should_use_qualified_lookup", &DeclContext::ShouldUseQualifiedLookup)
    .def_static("cast", +[] (const BlockDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXConstructorDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXConversionDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXDeductionGuideDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXDestructorDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXMethodDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CXXRecordDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const CapturedDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ClassTemplatePartialSpecializationDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ClassTemplateSpecializationDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const EnumDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ExportDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ExternCContextDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const FunctionDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const HLSLBufferDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const LinkageSpecDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const NamespaceDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const OMPDeclareMapperDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const OMPDeclareReductionDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCCategoryDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCCategoryImplDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCContainerDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCImplDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCImplementationDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCInterfaceDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCMethodDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const ObjCProtocolDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const RecordDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const RequiresExprBodyDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const TagDecl &cls) { return DeclContext(cls); })
    .def_static("cast", +[] (const TranslationUnitDecl &cls) { return DeclContext(cls); });
}
} // namespace pasta
