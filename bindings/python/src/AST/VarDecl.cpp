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

void RegisterVarDecl(py::module_ &m) {
  py::class_<VarDecl, DeclaratorDecl>(m, "VarDecl")
    .def("__hash__", [](const VarDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const VarDecl& a, const VarDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ActingDefinition", &VarDecl::ActingDefinition)
    .def_property_readonly("CanonicalDeclaration", &VarDecl::CanonicalDeclaration)
    .def_property_readonly("DescribedVariableTemplate", &VarDecl::DescribedVariableTemplate)
    .def_property_readonly("Initializer", &VarDecl::Initializer)
    .def_property_readonly("InitializerStyle", &VarDecl::InitializerStyle)
    .def_property_readonly("InitializingDeclaration", &VarDecl::InitializingDeclaration)
    .def_property_readonly("InstantiatedFromStaticDataMember", &VarDecl::InstantiatedFromStaticDataMember)
    .def_property_readonly("LanguageLinkage", &VarDecl::LanguageLinkage)
    .def_property_readonly("PointOfInstantiation", &VarDecl::PointOfInstantiation)
    .def_property_readonly("StorageClass", &VarDecl::StorageClass)
    .def_property_readonly("StorageDuration", &VarDecl::StorageDuration)
    .def_property_readonly("TLSKind", &VarDecl::TLSKind)
    .def_property_readonly("TSCSpec", &VarDecl::TSCSpec)
    .def_property_readonly("TemplateInstantiationPattern", &VarDecl::TemplateInstantiationPattern)
    .def_property_readonly("TemplateSpecializationKind", &VarDecl::TemplateSpecializationKind)
    .def_property_readonly("TemplateSpecializationKindForInstantiation", &VarDecl::TemplateSpecializationKindForInstantiation)
    .def_property_readonly("HasConstantInitialization", &VarDecl::HasConstantInitialization)
    .def_property_readonly("HasDependentAlignment", &VarDecl::HasDependentAlignment)
    .def_property_readonly("HasExternalStorage", &VarDecl::HasExternalStorage)
    .def("HasFlexibleArrayInitializer", &VarDecl::HasFlexibleArrayInitializer)
    .def_property_readonly("HasGlobalStorage", &VarDecl::HasGlobalStorage)
    .def("HasICEInitializer", &VarDecl::HasICEInitializer)
    .def_property_readonly("HasInitializer", &VarDecl::HasInitializer)
    .def_property_readonly("HasLocalStorage", &VarDecl::HasLocalStorage)
    .def_property_readonly("IsARCPseudoStrong", &VarDecl::IsARCPseudoStrong)
    .def_property_readonly("IsCXXForRangeDeclaration", &VarDecl::IsCXXForRangeDeclaration)
    .def_property_readonly("IsConstexpr", &VarDecl::IsConstexpr)
    .def_property_readonly("IsDirectInitializer", &VarDecl::IsDirectInitializer)
    .def_property_readonly("IsEscapingByref", &VarDecl::IsEscapingByref)
    .def_property_readonly("IsExceptionVariable", &VarDecl::IsExceptionVariable)
    .def_property_readonly("IsExternC", &VarDecl::IsExternC)
    .def_property_readonly("IsFileVariableDeclaration", &VarDecl::IsFileVariableDeclaration)
    .def_property_readonly("IsFunctionOrMethodVariableDeclaration", &VarDecl::IsFunctionOrMethodVariableDeclaration)
    .def_property_readonly("IsInExternCContext", &VarDecl::IsInExternCContext)
    .def_property_readonly("IsInExternCXXContext", &VarDecl::IsInExternCXXContext)
    .def_property_readonly("IsInitializerCapture", &VarDecl::IsInitializerCapture)
    .def_property_readonly("IsInline", &VarDecl::IsInline)
    .def_property_readonly("IsInlineSpecified", &VarDecl::IsInlineSpecified)
    .def_property_readonly("IsKnownToBeDefined", &VarDecl::IsKnownToBeDefined)
    .def_property_readonly("IsLocalVariableDeclaration", &VarDecl::IsLocalVariableDeclaration)
    .def_property_readonly("IsLocalVariableDeclarationOrParm", &VarDecl::IsLocalVariableDeclarationOrParm)
    .def_property_readonly("IsNRVOVariable", &VarDecl::IsNRVOVariable)
    .def("IsNoDestroy", &VarDecl::IsNoDestroy)
    .def_property_readonly("IsNonEscapingByref", &VarDecl::IsNonEscapingByref)
    .def_property_readonly("IsObjCForDeclaration", &VarDecl::IsObjCForDeclaration)
    .def_property_readonly("IsParameterPack", &VarDecl::IsParameterPack)
    .def_property_readonly("IsPreviousDeclarationInSameBlockScope", &VarDecl::IsPreviousDeclarationInSameBlockScope)
    .def_property_readonly("IsStaticDataMember", &VarDecl::IsStaticDataMember)
    .def_property_readonly("IsStaticLocal", &VarDecl::IsStaticLocal)
    .def_property_readonly("IsThisDeclarationADemotedDefinition", &VarDecl::IsThisDeclarationADemotedDefinition)
    .def("IsUsableInConstantExpressions", &VarDecl::IsUsableInConstantExpressions)
    .def("MightBeUsableInConstantExpressions", &VarDecl::MightBeUsableInConstantExpressions);
}
} // namespace pasta
