/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterRecordDecl(nb::module_ &m) {
  nb::class_<RecordDecl, TagDecl>(m, "RecordDecl")
    .def("__hash__", [](const RecordDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("can_pass_in_registers", &RecordDecl::CanPassInRegisters)
    .def_prop_ro("fields", &RecordDecl::Fields)
    .def_prop_ro("first_named_data_member", &RecordDecl::FirstNamedDataMember)
    .def_prop_ro("argument_passing_restrictions", &RecordDecl::ArgumentPassingRestrictions)
    .def_prop_ro("definition", &RecordDecl::Definition)
    .def_prop_ro("most_recent_declaration", &RecordDecl::MostRecentDeclaration)
    .def_prop_ro("previous_declaration", &RecordDecl::PreviousDeclaration)
    .def_prop_ro("has_flexible_array_member", &RecordDecl::HasFlexibleArrayMember)
    .def_prop_ro("has_loaded_fields_from_external_storage", &RecordDecl::HasLoadedFieldsFromExternalStorage)
    .def_prop_ro("has_non_trivial_to_primitive_copy_c_union", &RecordDecl::HasNonTrivialToPrimitiveCopyCUnion)
    .def_prop_ro("has_non_trivial_to_primitive_default_initialize_c_union", &RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_prop_ro("has_non_trivial_to_primitive_destruct_c_union", &RecordDecl::HasNonTrivialToPrimitiveDestructCUnion)
    .def_prop_ro("has_object_member", &RecordDecl::HasObjectMember)
    .def_prop_ro("has_volatile_member", &RecordDecl::HasVolatileMember)
    .def_prop_ro("is_anonymous_struct_or_union", &RecordDecl::IsAnonymousStructOrUnion)
    .def_prop_ro("is_captured_record", &RecordDecl::IsCapturedRecord)
    .def_prop_ro("is_injected_class_name", &RecordDecl::IsInjectedClassName)
    .def_prop_ro("is_lambda", &RecordDecl::IsLambda)
    .def("is_ms_struct", &RecordDecl::IsMsStruct)
    .def_prop_ro("is_non_trivial_to_primitive_copy", &RecordDecl::IsNonTrivialToPrimitiveCopy)
    .def_prop_ro("is_non_trivial_to_primitive_default_initialize", &RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize)
    .def_prop_ro("is_non_trivial_to_primitive_destroy", &RecordDecl::IsNonTrivialToPrimitiveDestroy)
    .def_prop_ro("is_or_contains_union", &RecordDecl::IsOrContainsUnion)
    .def_prop_ro("is_parameter_destroyed_in_callee", &RecordDecl::IsParameterDestroyedInCallee)
    .def_prop_ro("is_randomized", &RecordDecl::IsRandomized)
    .def_prop_ro("may_insert_extra_padding", &RecordDecl::MayInsertExtraPadding);
}
} // namespace pasta
