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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterFunctionDecl(py::module_ &m) {
  py::class_<FunctionDecl, DeclaratorDecl>(m, "FunctionDecl")
    .def("__hash__", [](const FunctionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const FunctionDecl& a, const FunctionDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("friend_constraint_refers_to_enclosing_template", &FunctionDecl::FriendConstraintRefersToEnclosingTemplate)
    .def_property_readonly("uses_fp_intrin", &FunctionDecl::UsesFPIntrin)
    .def_property_readonly("does_declaration_force_externally_visible_definition", &FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition)
    .def_property_readonly("does_this_declaration_have_a_body", &FunctionDecl::DoesThisDeclarationHaveABody)
    .def_property_readonly("builtin_id", &FunctionDecl::BuiltinID)
    .def_property_readonly("call_result_type", &FunctionDecl::CallResultType)
    .def_property_readonly("canonical_declaration", &FunctionDecl::CanonicalDeclaration)
    .def_property_readonly("constexpr_kind", &FunctionDecl::ConstexprKind)
    .def_property_readonly("declared_return_type", &FunctionDecl::DeclaredReturnType)
    .def_property_readonly("default_token", &FunctionDecl::DefaultToken)
    .def_property_readonly("definition", &FunctionDecl::Definition)
    .def_property_readonly("described_function_template", &FunctionDecl::DescribedFunctionTemplate)
    .def_property_readonly("ellipsis_token", &FunctionDecl::EllipsisToken)
    .def_property_readonly("exception_spec_source_range", &FunctionDecl::ExceptionSpecSourceRange)
    .def_property_readonly("exception_spec_type", &FunctionDecl::ExceptionSpecType)
    .def_property_readonly("instantiated_from_declaration", &FunctionDecl::InstantiatedFromDeclaration)
    .def_property_readonly("instantiated_from_member_function", &FunctionDecl::InstantiatedFromMemberFunction)
    .def_property_readonly("language_linkage", &FunctionDecl::LanguageLinkage)
    .def_property_readonly("memory_function_kind", &FunctionDecl::MemoryFunctionKind)
    .def_property_readonly("min_required_arguments", &FunctionDecl::MinRequiredArguments)
    .def_property_readonly("multi_version_kind", &FunctionDecl::MultiVersionKind)
    .def_property_readonly("num_parameters", &FunctionDecl::NumParameters)
    .def_property_readonly("odr_hash", &FunctionDecl::ODRHash)
    .def_property_readonly("overloaded_operator", &FunctionDecl::OverloadedOperator)
    .def_property_readonly("parameters_source_range", &FunctionDecl::ParametersSourceRange)
    .def_property_readonly("point_of_instantiation", &FunctionDecl::PointOfInstantiation)
    .def_property_readonly("primary_template", &FunctionDecl::PrimaryTemplate)
    .def_property_readonly("return_type", &FunctionDecl::ReturnType)
    .def_property_readonly("return_type_source_range", &FunctionDecl::ReturnTypeSourceRange)
    .def_property_readonly("storage_class", &FunctionDecl::StorageClass)
    .def_property_readonly("template_instantiation_pattern", &FunctionDecl::TemplateInstantiationPattern)
    .def_property_readonly("template_specialization_kind", &FunctionDecl::TemplateSpecializationKind)
    .def_property_readonly("template_specialization_kind_for_instantiation", &FunctionDecl::TemplateSpecializationKindForInstantiation)
    .def_property_readonly("templated_kind", &FunctionDecl::TemplatedKind)
    .def_property_readonly("has_implicit_return_zero", &FunctionDecl::HasImplicitReturnZero)
    .def_property_readonly("has_inherited_prototype", &FunctionDecl::HasInheritedPrototype)
    .def_property_readonly("has_one_parameter_or_default_arguments", &FunctionDecl::HasOneParameterOrDefaultArguments)
    .def_property_readonly("has_prototype", &FunctionDecl::HasPrototype)
    .def_property_readonly("has_skipped_body", &FunctionDecl::HasSkippedBody)
    .def_property_readonly("has_trivial_body", &FunctionDecl::HasTrivialBody)
    .def_property_readonly("has_written_prototype", &FunctionDecl::HasWrittenPrototype)
    .def_property_readonly("instantiation_is_pending", &FunctionDecl::InstantiationIsPending)
    .def_property_readonly("is_cpu_dispatch_multi_version", &FunctionDecl::IsCPUDispatchMultiVersion)
    .def_property_readonly("is_cpu_specific_multi_version", &FunctionDecl::IsCPUSpecificMultiVersion)
    .def_property_readonly("is_consteval", &FunctionDecl::IsConsteval)
    .def_property_readonly("is_constexpr", &FunctionDecl::IsConstexpr)
    .def_property_readonly("is_constexpr_specified", &FunctionDecl::IsConstexprSpecified)
    .def_property_readonly("is_defaulted", &FunctionDecl::IsDefaulted)
    .def_property_readonly("is_deleted", &FunctionDecl::IsDeleted)
    .def_property_readonly("is_deleted_as_written", &FunctionDecl::IsDeletedAsWritten)
    .def_property_readonly("is_destroying_operator_delete", &FunctionDecl::IsDestroyingOperatorDelete)
    .def_property_readonly("is_explicitly_defaulted", &FunctionDecl::IsExplicitlyDefaulted)
    .def_property_readonly("is_extern_c", &FunctionDecl::IsExternC)
    .def_property_readonly("is_function_template_specialization", &FunctionDecl::IsFunctionTemplateSpecialization)
    .def_property_readonly("is_global", &FunctionDecl::IsGlobal)
    .def_property_readonly("is_implicitly_instantiable", &FunctionDecl::IsImplicitlyInstantiable)
    .def_property_readonly("is_in_extern_c_context", &FunctionDecl::IsInExternCContext)
    .def_property_readonly("is_in_extern_cxx_context", &FunctionDecl::IsInExternCXXContext)
    .def_property_readonly("is_ineligible_or_not_selected", &FunctionDecl::IsIneligibleOrNotSelected)
    .def_property_readonly("is_inline_builtin_declaration", &FunctionDecl::IsInlineBuiltinDeclaration)
    .def_property_readonly("is_inline_definition_externally_visible", &FunctionDecl::IsInlineDefinitionExternallyVisible)
    .def_property_readonly("is_inline_specified", &FunctionDecl::IsInlineSpecified)
    .def_property_readonly("is_inlined", &FunctionDecl::IsInlined)
    .def_property_readonly("is_late_template_parsed", &FunctionDecl::IsLateTemplateParsed)
    .def_property_readonly("is_ms_extern_inline", &FunctionDecl::IsMSExternInline)
    .def_property_readonly("is_msvcrt_entry_point", &FunctionDecl::IsMSVCRTEntryPoint)
    .def_property_readonly("is_main", &FunctionDecl::IsMain)
    .def_property_readonly("is_multi_version", &FunctionDecl::IsMultiVersion)
    .def_property_readonly("is_no_return", &FunctionDecl::IsNoReturn)
    .def_property_readonly("is_overloaded_operator", &FunctionDecl::IsOverloadedOperator)
    .def_property_readonly("is_pure", &FunctionDecl::IsPure)
    .def_property_readonly("is_replaceable_global_allocation_function", &FunctionDecl::IsReplaceableGlobalAllocationFunction)
    .def_property_readonly("is_reserved_global_placement_operator", &FunctionDecl::IsReservedGlobalPlacementOperator)
    .def_property_readonly("is_static", &FunctionDecl::IsStatic)
    .def_property_readonly("is_target_clones_multi_version", &FunctionDecl::IsTargetClonesMultiVersion)
    .def_property_readonly("is_target_multi_version", &FunctionDecl::IsTargetMultiVersion)
    .def_property_readonly("is_template_instantiation", &FunctionDecl::IsTemplateInstantiation)
    .def_property_readonly("is_this_declaration_a_definition", &FunctionDecl::IsThisDeclarationADefinition)
    .def_property_readonly("is_this_declaration_instantiated_from_a_friend_definition", &FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition)
    .def_property_readonly("is_trivial", &FunctionDecl::IsTrivial)
    .def_property_readonly("is_trivial_for_call", &FunctionDecl::IsTrivialForCall)
    .def_property_readonly("is_user_provided", &FunctionDecl::IsUserProvided)
    .def_property_readonly("is_variadic", &FunctionDecl::IsVariadic)
    .def_property_readonly("is_virtual_as_written", &FunctionDecl::IsVirtualAsWritten)
    .def_property_readonly("parameters", &FunctionDecl::Parameters)
    .def_property_readonly("uses_seh_try", &FunctionDecl::UsesSEHTry)
    .def_property_readonly("will_have_body", &FunctionDecl::WillHaveBody)
    .def_property_readonly("Body", &FunctionDecl::Body);
}
} // namespace pasta
