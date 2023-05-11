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

void RegisterRecordDecl(py::module_ &m) {
  py::class_<RecordDecl, TagDecl>(m, "RecordDecl")
    .def("__hash__", [](const RecordDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("can_pass_in_registers", &RecordDecl::CanPassInRegisters)
    .def_property_readonly("fields", &RecordDecl::Fields)
    .def_property_readonly("first_named_data_member", &RecordDecl::FirstNamedDataMember)
    .def_property_readonly("argument_passing_restrictions", &RecordDecl::ArgumentPassingRestrictions)
    .def_property_readonly("definition", &RecordDecl::Definition)
    .def_property_readonly("most_recent_declaration", &RecordDecl::MostRecentDeclaration)
    .def_property_readonly("previous_declaration", &RecordDecl::PreviousDeclaration)
    .def_property_readonly("has_flexible_array_member", &RecordDecl::HasFlexibleArrayMember)
    .def_property_readonly("has_loaded_fields_from_external_storage", &RecordDecl::HasLoadedFieldsFromExternalStorage)
    .def_property_readonly("has_non_trivial_to_primitive_copy_c_union", &RecordDecl::HasNonTrivialToPrimitiveCopyCUnion)
    .def_property_readonly("has_non_trivial_to_primitive_default_initialize_c_union", &RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_property_readonly("has_non_trivial_to_primitive_destruct_c_union", &RecordDecl::HasNonTrivialToPrimitiveDestructCUnion)
    .def_property_readonly("has_object_member", &RecordDecl::HasObjectMember)
    .def_property_readonly("has_volatile_member", &RecordDecl::HasVolatileMember)
    .def_property_readonly("is_anonymous_struct_or_union", &RecordDecl::IsAnonymousStructOrUnion)
    .def_property_readonly("is_captured_record", &RecordDecl::IsCapturedRecord)
    .def_property_readonly("is_injected_class_name", &RecordDecl::IsInjectedClassName)
    .def_property_readonly("is_lambda", &RecordDecl::IsLambda)
    .def("is_ms_struct", &RecordDecl::IsMsStruct)
    .def_property_readonly("is_non_trivial_to_primitive_copy", &RecordDecl::IsNonTrivialToPrimitiveCopy)
    .def_property_readonly("is_non_trivial_to_primitive_default_initialize", &RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize)
    .def_property_readonly("is_non_trivial_to_primitive_destroy", &RecordDecl::IsNonTrivialToPrimitiveDestroy)
    .def_property_readonly("is_or_contains_union", &RecordDecl::IsOrContainsUnion)
    .def_property_readonly("is_parameter_destroyed_in_callee", &RecordDecl::IsParameterDestroyedInCallee)
    .def_property_readonly("is_randomized", &RecordDecl::IsRandomized)
    .def_property_readonly("may_insert_extra_padding", &RecordDecl::MayInsertExtraPadding);
}
} // namespace pasta
