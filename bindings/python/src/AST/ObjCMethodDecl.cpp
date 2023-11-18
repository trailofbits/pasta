/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCMethodDecl(nb::module_ &m) {
  nb::class_<ObjCMethodDecl, NamedDecl>(m, "ObjCMethodDecl")
    .def_prop_ro("defined_in_ns_object", &ObjCMethodDecl::DefinedInNSObject)
    .def_prop_ro("find_property_declaration", &ObjCMethodDecl::FindPropertyDeclaration)
    .def_prop_ro("begin_token", &ObjCMethodDecl::BeginToken)
    .def_prop_ro("canonical_declaration", &ObjCMethodDecl::CanonicalDeclaration)
    .def_prop_ro("category", &ObjCMethodDecl::Category)
    .def_prop_ro("class_interface", &ObjCMethodDecl::ClassInterface)
    .def_prop_ro("command_declaration", &ObjCMethodDecl::CommandDeclaration)
    .def_prop_ro("declarator_end_token", &ObjCMethodDecl::DeclaratorEndToken)
    .def_prop_ro("end_token", &ObjCMethodDecl::EndToken)
    .def_prop_ro("implementation_control", &ObjCMethodDecl::ImplementationControl)
    .def_prop_ro("method_family", &ObjCMethodDecl::MethodFamily)
    .def_prop_ro("num_selector_tokens", &ObjCMethodDecl::NumSelectorTokens)
    .def_prop_ro("obj_c_decl_qualifier", &ObjCMethodDecl::ObjCDeclQualifier)
    .def_prop_ro("return_type", &ObjCMethodDecl::ReturnType)
    .def_prop_ro("return_type_tokens", &ObjCMethodDecl::ReturnTypeTokens)
    .def_prop_ro("selector_start_token", &ObjCMethodDecl::SelectorStartToken)
    .def_prop_ro("self_declaration", &ObjCMethodDecl::SelfDeclaration)
    .def_prop_ro("has_parameter_destroyed_in_callee", &ObjCMethodDecl::HasParameterDestroyedInCallee)
    .def_prop_ro("has_redeclaration", &ObjCMethodDecl::HasRedeclaration)
    .def_prop_ro("has_related_result_type", &ObjCMethodDecl::HasRelatedResultType)
    .def_prop_ro("has_skipped_body", &ObjCMethodDecl::HasSkippedBody)
    .def_prop_ro("is_class_method", &ObjCMethodDecl::IsClassMethod)
    .def_prop_ro("is_defined", &ObjCMethodDecl::IsDefined)
    .def_prop_ro("is_designated_initializer_for_the_interface", &ObjCMethodDecl::IsDesignatedInitializerForTheInterface)
    .def_prop_ro("is_direct_method", &ObjCMethodDecl::IsDirectMethod)
    .def_prop_ro("is_instance_method", &ObjCMethodDecl::IsInstanceMethod)
    .def_prop_ro("is_optional", &ObjCMethodDecl::IsOptional)
    .def_prop_ro("is_overriding", &ObjCMethodDecl::IsOverriding)
    .def_prop_ro("is_property_accessor", &ObjCMethodDecl::IsPropertyAccessor)
    .def_prop_ro("is_redeclaration", &ObjCMethodDecl::IsRedeclaration)
    .def_prop_ro("is_synthesized_accessor_stub", &ObjCMethodDecl::IsSynthesizedAccessorStub)
    .def_prop_ro("is_this_declaration_a_definition", &ObjCMethodDecl::IsThisDeclarationADefinition)
    .def_prop_ro("is_this_declaration_a_designated_initializer", &ObjCMethodDecl::IsThisDeclarationADesignatedInitializer)
    .def_prop_ro("is_variadic", &ObjCMethodDecl::IsVariadic)
    .def_prop_ro("parameters", &ObjCMethodDecl::Parameters);
}
} // namespace pasta
