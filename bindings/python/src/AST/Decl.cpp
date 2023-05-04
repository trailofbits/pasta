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
    .def_property_readonly("Attributes", &Decl::Attributes)
    .def_property_readonly("Access", &Decl::Access)
    .def_property_readonly("AsFunction", &Decl::AsFunction)
    .def_property_readonly("Availability", &Decl::Availability)
    .def_property_readonly("BeginToken", &Decl::BeginToken)
    .def_property_readonly("CanonicalDeclaration", &Decl::CanonicalDeclaration)
    .def_property_readonly("DeclarationContext", &Decl::DeclarationContext)
    .def_property_readonly("DefiningAttribute", &Decl::DefiningAttribute)
    .def_property_readonly("DescribedTemplate", &Decl::DescribedTemplate)
    .def_property_readonly("DescribedTemplateParameters", &Decl::DescribedTemplateParameters)
    .def_property_readonly("EndToken", &Decl::EndToken)
    .def_property_readonly("ExternalSourceSymbolAttribute", &Decl::ExternalSourceSymbolAttribute)
    .def_property_readonly("FriendObjectKind", &Decl::FriendObjectKind)
    .def_property_readonly("FunctionType", &Decl::FunctionType)
    .def_property_readonly("GlobalID", &Decl::GlobalID)
    .def_property_readonly("ID", &Decl::ID)
    .def_property_readonly("IdentifierNamespace", &Decl::IdentifierNamespace)
    .def_property_readonly("LexicalDeclarationContext", &Decl::LexicalDeclarationContext)
    .def_property_readonly("MaxAlignment", &Decl::MaxAlignment)
    .def_property_readonly("ModuleOwnershipKind", &Decl::ModuleOwnershipKind)
    .def_property_readonly("MostRecentDeclaration", &Decl::MostRecentDeclaration)
    .def_property_readonly("NextDeclarationInContext", &Decl::NextDeclarationInContext)
    .def_property_readonly("NonClosureContext", &Decl::NonClosureContext)
    .def_property_readonly("NonTransparentDeclarationContext", &Decl::NonTransparentDeclarationContext)
    .def_property_readonly("OwningModuleID", &Decl::OwningModuleID)
    .def_property_readonly("ParentFunctionOrMethod", &Decl::ParentFunctionOrMethod)
    .def_property_readonly("PreviousDeclaration", &Decl::PreviousDeclaration)
    .def_property_readonly("TemplateDepth", &Decl::TemplateDepth)
    .def_property_readonly("TranslationUnitDeclaration", &Decl::TranslationUnitDeclaration)
    .def_property_readonly("HasAttributes", &Decl::HasAttributes)
    .def_property_readonly("HasBody", &Decl::HasBody)
    .def_property_readonly("HasDefiningAttribute", &Decl::HasDefiningAttribute)
    .def_property_readonly("HasOwningModule", &Decl::HasOwningModule)
    .def_property_readonly("HasTagIdentifierNamespace", &Decl::HasTagIdentifierNamespace)
    .def_property_readonly("IsCanonicalDeclaration", &Decl::IsCanonicalDeclaration)
    .def_property_readonly("IsDefinedOutsideFunctionOrMethod", &Decl::IsDefinedOutsideFunctionOrMethod)
    .def_property_readonly("IsDeprecated", &Decl::IsDeprecated)
    .def_property_readonly("IsDiscardedInGlobalModuleFragment", &Decl::IsDiscardedInGlobalModuleFragment)
    .def_property_readonly("IsFileContextDeclaration", &Decl::IsFileContextDeclaration)
    .def_property_readonly("IsFirstDeclaration", &Decl::IsFirstDeclaration)
    .def_property_readonly("IsFromASTFile", &Decl::IsFromASTFile)
    .def_property_readonly("IsFunctionOrFunctionTemplate", &Decl::IsFunctionOrFunctionTemplate)
    .def_property_readonly("IsInAnonymousNamespace", &Decl::IsInAnonymousNamespace)
    .def_property_readonly("IsInExportDeclarationContext", &Decl::IsInExportDeclarationContext)
    .def_property_readonly("IsInLocalScopeForInstantiation", &Decl::IsInLocalScopeForInstantiation)
    .def_property_readonly("IsInStdNamespace", &Decl::IsInStdNamespace)
    .def_property_readonly("IsInvalidDeclaration", &Decl::IsInvalidDeclaration)
    .def_property_readonly("IsInvisibleOutsideTheOwningModule", &Decl::IsInvisibleOutsideTheOwningModule)
    .def_property_readonly("IsLocalExternDeclaration", &Decl::IsLocalExternDeclaration)
    .def_property_readonly("IsModulePrivate", &Decl::IsModulePrivate)
    .def_property_readonly("IsOutOfLine", &Decl::IsOutOfLine)
    .def_property_readonly("IsParameterPack", &Decl::IsParameterPack)
    .def_property_readonly("IsReachable", &Decl::IsReachable)
    .def_property_readonly("IsReferenced", &Decl::IsReferenced)
    .def_property_readonly("IsTemplateDeclaration", &Decl::IsTemplateDeclaration)
    .def_property_readonly("IsTemplateParameter", &Decl::IsTemplateParameter)
    .def_property_readonly("IsTemplateParameterPack", &Decl::IsTemplateParameterPack)
    .def_property_readonly("IsTemplated", &Decl::IsTemplated)
    .def_property_readonly("IsThisDeclarationReferenced", &Decl::IsThisDeclarationReferenced)
    .def_property_readonly("IsTopLevelDeclarationInObjCContainer", &Decl::IsTopLevelDeclarationInObjCContainer)
    .def_property_readonly("IsUnavailable", &Decl::IsUnavailable)
    .def_property_readonly("IsUnconditionallyVisible", &Decl::IsUnconditionallyVisible)
    .def_property_readonly("IsUsed", &Decl::IsUsed)
    .def_property_readonly("IsWeakImported", &Decl::IsWeakImported)
    .def_property_readonly("Redeclarations", &Decl::Redeclarations);
}
} // namespace pasta
