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

void RegisterObjCMethodDecl(py::module_ &m) {
  py::class_<ObjCMethodDecl, NamedDecl>(m, "ObjCMethodDecl")
    .def("__hash__", [](const ObjCMethodDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def("defined_in_ns_object", &ObjCMethodDecl::DefinedInNSObject)
    .def_property_readonly("find_property_declaration", &ObjCMethodDecl::FindPropertyDeclaration)
    .def_property_readonly("begin_token", &ObjCMethodDecl::BeginToken)
    .def_property_readonly("canonical_declaration", &ObjCMethodDecl::CanonicalDeclaration)
    .def_property_readonly("category", &ObjCMethodDecl::Category)
    .def_property_readonly("class_interface", &ObjCMethodDecl::ClassInterface)
    .def_property_readonly("command_declaration", &ObjCMethodDecl::CommandDeclaration)
    .def_property_readonly("declarator_end_token", &ObjCMethodDecl::DeclaratorEndToken)
    .def_property_readonly("end_token", &ObjCMethodDecl::EndToken)
    .def_property_readonly("implementation_control", &ObjCMethodDecl::ImplementationControl)
    .def_property_readonly("method_family", &ObjCMethodDecl::MethodFamily)
    .def_property_readonly("num_selector_tokens", &ObjCMethodDecl::NumSelectorTokens)
    .def_property_readonly("obj_c_decl_qualifier", &ObjCMethodDecl::ObjCDeclQualifier)
    .def_property_readonly("return_type", &ObjCMethodDecl::ReturnType)
    .def_property_readonly("return_type_source_range", &ObjCMethodDecl::ReturnTypeSourceRange)
    .def_property_readonly("selector_start_token", &ObjCMethodDecl::SelectorStartToken)
    .def_property_readonly("self_declaration", &ObjCMethodDecl::SelfDeclaration)
    .def_property_readonly("has_parameter_destroyed_in_callee", &ObjCMethodDecl::HasParameterDestroyedInCallee)
    .def_property_readonly("has_redeclaration", &ObjCMethodDecl::HasRedeclaration)
    .def_property_readonly("has_related_result_type", &ObjCMethodDecl::HasRelatedResultType)
    .def_property_readonly("has_skipped_body", &ObjCMethodDecl::HasSkippedBody)
    .def_property_readonly("is_class_method", &ObjCMethodDecl::IsClassMethod)
    .def_property_readonly("is_defined", &ObjCMethodDecl::IsDefined)
    .def_property_readonly("is_designated_initializer_for_the_interface", &ObjCMethodDecl::IsDesignatedInitializerForTheInterface)
    .def_property_readonly("is_direct_method", &ObjCMethodDecl::IsDirectMethod)
    .def_property_readonly("is_instance_method", &ObjCMethodDecl::IsInstanceMethod)
    .def_property_readonly("is_optional", &ObjCMethodDecl::IsOptional)
    .def_property_readonly("is_overriding", &ObjCMethodDecl::IsOverriding)
    .def_property_readonly("is_property_accessor", &ObjCMethodDecl::IsPropertyAccessor)
    .def_property_readonly("is_redeclaration", &ObjCMethodDecl::IsRedeclaration)
    .def_property_readonly("is_synthesized_accessor_stub", &ObjCMethodDecl::IsSynthesizedAccessorStub)
    .def_property_readonly("is_this_declaration_a_definition", &ObjCMethodDecl::IsThisDeclarationADefinition)
    .def_property_readonly("is_this_declaration_a_designated_initializer", &ObjCMethodDecl::IsThisDeclarationADesignatedInitializer)
    .def_property_readonly("is_variadic", &ObjCMethodDecl::IsVariadic)
    .def_property_readonly("parameters", &ObjCMethodDecl::Parameters);
}
} // namespace pasta
