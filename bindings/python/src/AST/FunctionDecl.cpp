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

void RegisterFunctionDecl(nb::module_ &m) {
  nb::class_<FunctionDecl, DeclaratorDecl>(m, "FunctionDecl")
    .def("__hash__", [](const FunctionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("friend_constraint_refers_to_enclosing_template", &FunctionDecl::FriendConstraintRefersToEnclosingTemplate)
    .def_prop_ro("uses_fp_intrin", &FunctionDecl::UsesFPIntrin)
    .def_prop_ro("does_declaration_force_externally_visible_definition", &FunctionDecl::DoesDeclarationForceExternallyVisibleDefinition)
    .def_prop_ro("does_this_declaration_have_a_body", &FunctionDecl::DoesThisDeclarationHaveABody)
    .def_prop_ro("builtin_id", &FunctionDecl::BuiltinID)
    .def_prop_ro("call_result_type", &FunctionDecl::CallResultType)
    .def_prop_ro("canonical_declaration", &FunctionDecl::CanonicalDeclaration)
    .def_prop_ro("constexpr_kind", &FunctionDecl::ConstexprKind)
    .def_prop_ro("declared_return_type", &FunctionDecl::DeclaredReturnType)
    .def_prop_ro("default_token", &FunctionDecl::DefaultToken)
    .def_prop_ro("definition", &FunctionDecl::Definition)
    .def_prop_ro("described_function_template", &FunctionDecl::DescribedFunctionTemplate)
    .def_prop_ro("ellipsis_token", &FunctionDecl::EllipsisToken)
    .def_prop_ro("exception_spec_source_range", &FunctionDecl::ExceptionSpecSourceRange)
    .def_prop_ro("exception_spec_type", &FunctionDecl::ExceptionSpecType)
    .def_prop_ro("instantiated_from_declaration", &FunctionDecl::InstantiatedFromDeclaration)
    .def_prop_ro("instantiated_from_member_function", &FunctionDecl::InstantiatedFromMemberFunction)
    .def_prop_ro("language_linkage", &FunctionDecl::LanguageLinkage)
    .def_prop_ro("memory_function_kind", &FunctionDecl::MemoryFunctionKind)
    .def_prop_ro("min_required_arguments", &FunctionDecl::MinRequiredArguments)
    .def_prop_ro("multi_version_kind", &FunctionDecl::MultiVersionKind)
    .def_prop_ro("num_parameters", &FunctionDecl::NumParameters)
    .def_prop_ro("odr_hash", &FunctionDecl::ODRHash)
    .def_prop_ro("overloaded_operator", &FunctionDecl::OverloadedOperator)
    .def_prop_ro("parameters_source_range", &FunctionDecl::ParametersSourceRange)
    .def_prop_ro("point_of_instantiation", &FunctionDecl::PointOfInstantiation)
    .def_prop_ro("primary_template", &FunctionDecl::PrimaryTemplate)
    .def_prop_ro("return_type", &FunctionDecl::ReturnType)
    .def_prop_ro("return_type_source_range", &FunctionDecl::ReturnTypeSourceRange)
    .def_prop_ro("storage_class", &FunctionDecl::StorageClass)
    .def_prop_ro("template_instantiation_pattern", &FunctionDecl::TemplateInstantiationPattern)
    .def_prop_ro("template_specialization_kind", &FunctionDecl::TemplateSpecializationKind)
    .def_prop_ro("template_specialization_kind_for_instantiation", &FunctionDecl::TemplateSpecializationKindForInstantiation)
    .def_prop_ro("templated_kind", &FunctionDecl::TemplatedKind)
    .def_prop_ro("has_implicit_return_zero", &FunctionDecl::HasImplicitReturnZero)
    .def_prop_ro("has_inherited_prototype", &FunctionDecl::HasInheritedPrototype)
    .def_prop_ro("has_one_parameter_or_default_arguments", &FunctionDecl::HasOneParameterOrDefaultArguments)
    .def_prop_ro("has_prototype", &FunctionDecl::HasPrototype)
    .def_prop_ro("has_skipped_body", &FunctionDecl::HasSkippedBody)
    .def_prop_ro("has_trivial_body", &FunctionDecl::HasTrivialBody)
    .def_prop_ro("has_written_prototype", &FunctionDecl::HasWrittenPrototype)
    .def_prop_ro("instantiation_is_pending", &FunctionDecl::InstantiationIsPending)
    .def_prop_ro("is_cpu_dispatch_multi_version", &FunctionDecl::IsCPUDispatchMultiVersion)
    .def_prop_ro("is_cpu_specific_multi_version", &FunctionDecl::IsCPUSpecificMultiVersion)
    .def_prop_ro("is_consteval", &FunctionDecl::IsConsteval)
    .def_prop_ro("is_constexpr", &FunctionDecl::IsConstexpr)
    .def_prop_ro("is_constexpr_specified", &FunctionDecl::IsConstexprSpecified)
    .def_prop_ro("is_defaulted", &FunctionDecl::IsDefaulted)
    .def_prop_ro("is_deleted", &FunctionDecl::IsDeleted)
    .def_prop_ro("is_deleted_as_written", &FunctionDecl::IsDeletedAsWritten)
    .def_prop_ro("is_destroying_operator_delete", &FunctionDecl::IsDestroyingOperatorDelete)
    .def_prop_ro("is_explicitly_defaulted", &FunctionDecl::IsExplicitlyDefaulted)
    .def_prop_ro("is_extern_c", &FunctionDecl::IsExternC)
    .def_prop_ro("is_function_template_specialization", &FunctionDecl::IsFunctionTemplateSpecialization)
    .def_prop_ro("is_global", &FunctionDecl::IsGlobal)
    .def_prop_ro("is_implicitly_instantiable", &FunctionDecl::IsImplicitlyInstantiable)
    .def_prop_ro("is_in_extern_c_context", &FunctionDecl::IsInExternCContext)
    .def_prop_ro("is_in_extern_cxx_context", &FunctionDecl::IsInExternCXXContext)
    .def_prop_ro("is_ineligible_or_not_selected", &FunctionDecl::IsIneligibleOrNotSelected)
    .def_prop_ro("is_inline_builtin_declaration", &FunctionDecl::IsInlineBuiltinDeclaration)
    .def_prop_ro("is_inline_definition_externally_visible", &FunctionDecl::IsInlineDefinitionExternallyVisible)
    .def_prop_ro("is_inline_specified", &FunctionDecl::IsInlineSpecified)
    .def_prop_ro("is_inlined", &FunctionDecl::IsInlined)
    .def_prop_ro("is_late_template_parsed", &FunctionDecl::IsLateTemplateParsed)
    .def_prop_ro("is_ms_extern_inline", &FunctionDecl::IsMSExternInline)
    .def_prop_ro("is_msvcrt_entry_point", &FunctionDecl::IsMSVCRTEntryPoint)
    .def_prop_ro("is_main", &FunctionDecl::IsMain)
    .def_prop_ro("is_multi_version", &FunctionDecl::IsMultiVersion)
    .def_prop_ro("is_no_return", &FunctionDecl::IsNoReturn)
    .def_prop_ro("is_overloaded_operator", &FunctionDecl::IsOverloadedOperator)
    .def_prop_ro("is_pure", &FunctionDecl::IsPure)
    .def_prop_ro("is_replaceable_global_allocation_function", &FunctionDecl::IsReplaceableGlobalAllocationFunction)
    .def_prop_ro("is_reserved_global_placement_operator", &FunctionDecl::IsReservedGlobalPlacementOperator)
    .def_prop_ro("is_static", &FunctionDecl::IsStatic)
    .def_prop_ro("is_target_clones_multi_version", &FunctionDecl::IsTargetClonesMultiVersion)
    .def_prop_ro("is_target_multi_version", &FunctionDecl::IsTargetMultiVersion)
    .def_prop_ro("is_template_instantiation", &FunctionDecl::IsTemplateInstantiation)
    .def_prop_ro("is_this_declaration_a_definition", &FunctionDecl::IsThisDeclarationADefinition)
    .def_prop_ro("is_this_declaration_instantiated_from_a_friend_definition", &FunctionDecl::IsThisDeclarationInstantiatedFromAFriendDefinition)
    .def_prop_ro("is_trivial", &FunctionDecl::IsTrivial)
    .def_prop_ro("is_trivial_for_call", &FunctionDecl::IsTrivialForCall)
    .def_prop_ro("is_user_provided", &FunctionDecl::IsUserProvided)
    .def_prop_ro("is_variadic", &FunctionDecl::IsVariadic)
    .def_prop_ro("is_virtual_as_written", &FunctionDecl::IsVirtualAsWritten)
    .def_prop_ro("parameters", &FunctionDecl::Parameters)
    .def_prop_ro("uses_seh_try", &FunctionDecl::UsesSEHTry)
    .def_prop_ro("will_have_body", &FunctionDecl::WillHaveBody)
    .def_prop_ro("Body", &FunctionDecl::Body);
}
} // namespace pasta
