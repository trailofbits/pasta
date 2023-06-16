/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterVarDecl(nb::module_ &m) {
  nb::class_<VarDecl, DeclaratorDecl>(m, "VarDecl")
    .def("__hash__", [](const VarDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("acting_definition", &VarDecl::ActingDefinition)
    .def_prop_ro("canonical_declaration", &VarDecl::CanonicalDeclaration)
    .def_prop_ro("described_variable_template", &VarDecl::DescribedVariableTemplate)
    .def_prop_ro("initializer", &VarDecl::Initializer)
    .def_prop_ro("initializer_style", &VarDecl::InitializerStyle)
    .def_prop_ro("initializing_declaration", &VarDecl::InitializingDeclaration)
    .def_prop_ro("instantiated_from_static_data_member", &VarDecl::InstantiatedFromStaticDataMember)
    .def_prop_ro("language_linkage", &VarDecl::LanguageLinkage)
    .def_prop_ro("point_of_instantiation", &VarDecl::PointOfInstantiation)
    .def_prop_ro("storage_class", &VarDecl::StorageClass)
    .def_prop_ro("storage_duration", &VarDecl::StorageDuration)
    .def_prop_ro("tls_kind", &VarDecl::TLSKind)
    .def_prop_ro("tsc_spec", &VarDecl::TSCSpec)
    .def_prop_ro("template_instantiation_pattern", &VarDecl::TemplateInstantiationPattern)
    .def_prop_ro("template_specialization_kind", &VarDecl::TemplateSpecializationKind)
    .def_prop_ro("template_specialization_kind_for_instantiation", &VarDecl::TemplateSpecializationKindForInstantiation)
    .def_prop_ro("has_constant_initialization", &VarDecl::HasConstantInitialization)
    .def_prop_ro("has_dependent_alignment", &VarDecl::HasDependentAlignment)
    .def_prop_ro("has_external_storage", &VarDecl::HasExternalStorage)
    .def("has_flexible_array_initializer", &VarDecl::HasFlexibleArrayInitializer)
    .def_prop_ro("has_global_storage", &VarDecl::HasGlobalStorage)
    .def("has_ice_initializer", &VarDecl::HasICEInitializer)
    .def_prop_ro("has_initializer", &VarDecl::HasInitializer)
    .def_prop_ro("has_local_storage", &VarDecl::HasLocalStorage)
    .def_prop_ro("is_arc_pseudo_strong", &VarDecl::IsARCPseudoStrong)
    .def_prop_ro("is_cxx_for_range_declaration", &VarDecl::IsCXXForRangeDeclaration)
    .def_prop_ro("is_constexpr", &VarDecl::IsConstexpr)
    .def_prop_ro("is_direct_initializer", &VarDecl::IsDirectInitializer)
    .def_prop_ro("is_escaping_byref", &VarDecl::IsEscapingByref)
    .def_prop_ro("is_exception_variable", &VarDecl::IsExceptionVariable)
    .def_prop_ro("is_extern_c", &VarDecl::IsExternC)
    .def_prop_ro("is_file_variable_declaration", &VarDecl::IsFileVariableDeclaration)
    .def_prop_ro("is_function_or_method_variable_declaration", &VarDecl::IsFunctionOrMethodVariableDeclaration)
    .def_prop_ro("is_in_extern_c_context", &VarDecl::IsInExternCContext)
    .def_prop_ro("is_in_extern_cxx_context", &VarDecl::IsInExternCXXContext)
    .def_prop_ro("is_initializer_capture", &VarDecl::IsInitializerCapture)
    .def_prop_ro("is_inline", &VarDecl::IsInline)
    .def_prop_ro("is_inline_specified", &VarDecl::IsInlineSpecified)
    .def_prop_ro("is_known_to_be_defined", &VarDecl::IsKnownToBeDefined)
    .def_prop_ro("is_local_variable_declaration", &VarDecl::IsLocalVariableDeclaration)
    .def_prop_ro("is_local_variable_declaration_or_parm", &VarDecl::IsLocalVariableDeclarationOrParm)
    .def_prop_ro("is_nrvo_variable", &VarDecl::IsNRVOVariable)
    .def("is_no_destroy", &VarDecl::IsNoDestroy)
    .def_prop_ro("is_non_escaping_byref", &VarDecl::IsNonEscapingByref)
    .def_prop_ro("is_obj_c_for_declaration", &VarDecl::IsObjCForDeclaration)
    .def_prop_ro("is_parameter_pack", &VarDecl::IsParameterPack)
    .def_prop_ro("is_previous_declaration_in_same_block_scope", &VarDecl::IsPreviousDeclarationInSameBlockScope)
    .def_prop_ro("is_static_data_member", &VarDecl::IsStaticDataMember)
    .def_prop_ro("is_static_local", &VarDecl::IsStaticLocal)
    .def_prop_ro("is_this_declaration_a_demoted_definition", &VarDecl::IsThisDeclarationADemotedDefinition)
    .def("is_usable_in_constant_expressions", &VarDecl::IsUsableInConstantExpressions)
    .def("might_be_usable_in_constant_expressions", &VarDecl::MightBeUsableInConstantExpressions);
}
} // namespace pasta
