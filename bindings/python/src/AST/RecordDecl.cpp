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

void RegisterRecordDecl(py::module_ &m) {
  py::class_<RecordDecl, Decl, NamedDecl, TagDecl, TypeDecl>(m, "RecordDecl")
    .def_property_readonly("CanPassInRegisters", &RecordDecl::CanPassInRegisters)
    .def_property_readonly("Fields", &RecordDecl::Fields)
    .def_property_readonly("FirstNamedDataMember", &RecordDecl::FirstNamedDataMember)
    .def_property_readonly("ArgumentPassingRestrictions", &RecordDecl::ArgumentPassingRestrictions)
    .def_property_readonly("Definition", &RecordDecl::Definition)
    .def_property_readonly("MostRecentDeclaration", &RecordDecl::MostRecentDeclaration)
    .def_property_readonly("PreviousDeclaration", &RecordDecl::PreviousDeclaration)
    .def_property_readonly("HasFlexibleArrayMember", &RecordDecl::HasFlexibleArrayMember)
    .def_property_readonly("HasLoadedFieldsFromExternalStorage", &RecordDecl::HasLoadedFieldsFromExternalStorage)
    .def_property_readonly("HasNonTrivialToPrimitiveCopyCUnion", &RecordDecl::HasNonTrivialToPrimitiveCopyCUnion)
    .def_property_readonly("HasNonTrivialToPrimitiveDefaultInitializeCUnion", &RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion)
    .def_property_readonly("HasNonTrivialToPrimitiveDestructCUnion", &RecordDecl::HasNonTrivialToPrimitiveDestructCUnion)
    .def_property_readonly("HasObjectMember", &RecordDecl::HasObjectMember)
    .def_property_readonly("HasVolatileMember", &RecordDecl::HasVolatileMember)
    .def_property_readonly("IsAnonymousStructOrUnion", &RecordDecl::IsAnonymousStructOrUnion)
    .def_property_readonly("IsCapturedRecord", &RecordDecl::IsCapturedRecord)
    .def_property_readonly("IsInjectedClassName", &RecordDecl::IsInjectedClassName)
    .def_property_readonly("IsLambda", &RecordDecl::IsLambda)
    .def("IsMsStruct", &RecordDecl::IsMsStruct)
    .def_property_readonly("IsNonTrivialToPrimitiveCopy", &RecordDecl::IsNonTrivialToPrimitiveCopy)
    .def_property_readonly("IsNonTrivialToPrimitiveDefaultInitialize", &RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize)
    .def_property_readonly("IsNonTrivialToPrimitiveDestroy", &RecordDecl::IsNonTrivialToPrimitiveDestroy)
    .def_property_readonly("IsOrContainsUnion", &RecordDecl::IsOrContainsUnion)
    .def_property_readonly("IsParameterDestroyedInCallee", &RecordDecl::IsParameterDestroyedInCallee)
    .def_property_readonly("IsRandomized", &RecordDecl::IsRandomized)
    .def_property_readonly("MayInsertExtraPadding", &RecordDecl::MayInsertExtraPadding);
}
} // namespace pasta
