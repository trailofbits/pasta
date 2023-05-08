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
    .def_property_readonly("acting_definition", &VarDecl::ActingDefinition)
    .def_property_readonly("canonical_declaration", &VarDecl::CanonicalDeclaration)
    .def_property_readonly("described_variable_template", &VarDecl::DescribedVariableTemplate)
    .def_property_readonly("initializer", &VarDecl::Initializer)
    .def_property_readonly("initializer_style", &VarDecl::InitializerStyle)
    .def_property_readonly("initializing_declaration", &VarDecl::InitializingDeclaration)
    .def_property_readonly("instantiated_from_static_data_member", &VarDecl::InstantiatedFromStaticDataMember)
    .def_property_readonly("language_linkage", &VarDecl::LanguageLinkage)
    .def_property_readonly("point_of_instantiation", &VarDecl::PointOfInstantiation)
    .def_property_readonly("storage_class", &VarDecl::StorageClass)
    .def_property_readonly("storage_duration", &VarDecl::StorageDuration)
    .def_property_readonly("tls_kind", &VarDecl::TLSKind)
    .def_property_readonly("tsc_spec", &VarDecl::TSCSpec)
    .def_property_readonly("template_instantiation_pattern", &VarDecl::TemplateInstantiationPattern)
    .def_property_readonly("template_specialization_kind", &VarDecl::TemplateSpecializationKind)
    .def_property_readonly("template_specialization_kind_for_instantiation", &VarDecl::TemplateSpecializationKindForInstantiation)
    .def_property_readonly("has_constant_initialization", &VarDecl::HasConstantInitialization)
    .def_property_readonly("has_dependent_alignment", &VarDecl::HasDependentAlignment)
    .def_property_readonly("has_external_storage", &VarDecl::HasExternalStorage)
    .def("has_flexible_array_initializer", &VarDecl::HasFlexibleArrayInitializer)
    .def_property_readonly("has_global_storage", &VarDecl::HasGlobalStorage)
    .def("has_ice_initializer", &VarDecl::HasICEInitializer)
    .def_property_readonly("has_initializer", &VarDecl::HasInitializer)
    .def_property_readonly("has_local_storage", &VarDecl::HasLocalStorage)
    .def_property_readonly("is_arc_pseudo_strong", &VarDecl::IsARCPseudoStrong)
    .def_property_readonly("is_cxx_for_range_declaration", &VarDecl::IsCXXForRangeDeclaration)
    .def_property_readonly("is_constexpr", &VarDecl::IsConstexpr)
    .def_property_readonly("is_direct_initializer", &VarDecl::IsDirectInitializer)
    .def_property_readonly("is_escaping_byref", &VarDecl::IsEscapingByref)
    .def_property_readonly("is_exception_variable", &VarDecl::IsExceptionVariable)
    .def_property_readonly("is_extern_c", &VarDecl::IsExternC)
    .def_property_readonly("is_file_variable_declaration", &VarDecl::IsFileVariableDeclaration)
    .def_property_readonly("is_function_or_method_variable_declaration", &VarDecl::IsFunctionOrMethodVariableDeclaration)
    .def_property_readonly("is_in_extern_c_context", &VarDecl::IsInExternCContext)
    .def_property_readonly("is_in_extern_cxx_context", &VarDecl::IsInExternCXXContext)
    .def_property_readonly("is_initializer_capture", &VarDecl::IsInitializerCapture)
    .def_property_readonly("is_inline", &VarDecl::IsInline)
    .def_property_readonly("is_inline_specified", &VarDecl::IsInlineSpecified)
    .def_property_readonly("is_known_to_be_defined", &VarDecl::IsKnownToBeDefined)
    .def_property_readonly("is_local_variable_declaration", &VarDecl::IsLocalVariableDeclaration)
    .def_property_readonly("is_local_variable_declaration_or_parm", &VarDecl::IsLocalVariableDeclarationOrParm)
    .def_property_readonly("is_nrvo_variable", &VarDecl::IsNRVOVariable)
    .def("is_no_destroy", &VarDecl::IsNoDestroy)
    .def_property_readonly("is_non_escaping_byref", &VarDecl::IsNonEscapingByref)
    .def_property_readonly("is_obj_c_for_declaration", &VarDecl::IsObjCForDeclaration)
    .def_property_readonly("is_parameter_pack", &VarDecl::IsParameterPack)
    .def_property_readonly("is_previous_declaration_in_same_block_scope", &VarDecl::IsPreviousDeclarationInSameBlockScope)
    .def_property_readonly("is_static_data_member", &VarDecl::IsStaticDataMember)
    .def_property_readonly("is_static_local", &VarDecl::IsStaticLocal)
    .def_property_readonly("is_this_declaration_a_demoted_definition", &VarDecl::IsThisDeclarationADemotedDefinition)
    .def("is_usable_in_constant_expressions", &VarDecl::IsUsableInConstantExpressions)
    .def("might_be_usable_in_constant_expressions", &VarDecl::MightBeUsableInConstantExpressions);
}
} // namespace pasta
