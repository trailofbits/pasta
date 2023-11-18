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

void RegisterObjCInterfaceDecl(nb::module_ &m) {
  nb::class_<ObjCInterfaceDecl, ObjCContainerDecl>(m, "ObjCInterfaceDecl")
    .def_prop_ro("all_referenced_protocols", &ObjCInterfaceDecl::AllReferencedProtocols)
    .def_prop_ro("declares_or_inherits_designated_initializers", &ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers)
    .def_prop_ro("canonical_declaration", &ObjCInterfaceDecl::CanonicalDeclaration)
    .def_prop_ro("category_list_raw", &ObjCInterfaceDecl::CategoryListRaw)
    .def_prop_ro("definition", &ObjCInterfaceDecl::Definition)
    .def_prop_ro("end_of_definition_token", &ObjCInterfaceDecl::EndOfDefinitionToken)
    .def_prop_ro("implementation", &ObjCInterfaceDecl::Implementation)
    .def_prop_ro("obj_c_runtime_name_as_string", &ObjCInterfaceDecl::ObjCRuntimeNameAsString)
    .def_prop_ro("super_class", &ObjCInterfaceDecl::SuperClass)
    .def_prop_ro("super_class_token", &ObjCInterfaceDecl::SuperClassToken)
    .def_prop_ro("super_class_type_info", &ObjCInterfaceDecl::SuperClassTypeInfo)
    .def_prop_ro("super_class_type", &ObjCInterfaceDecl::SuperClassType)
    .def_prop_ro("type_for_declaration", &ObjCInterfaceDecl::TypeForDeclaration)
    .def_prop_ro("has_definition", &ObjCInterfaceDecl::HasDefinition)
    .def_prop_ro("has_designated_initializers", &ObjCInterfaceDecl::HasDesignatedInitializers)
    .def_prop_ro("is_arc_weakref_unavailable", &ObjCInterfaceDecl::IsArcWeakrefUnavailable)
    .def_prop_ro("is_implicit_interface_declaration", &ObjCInterfaceDecl::IsImplicitInterfaceDeclaration)
    .def_prop_ro("is_obj_c_requires_property_definitions", &ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions)
    .def_prop_ro("is_this_declaration_a_definition", &ObjCInterfaceDecl::IsThisDeclarationADefinition)
    .def_prop_ro("instance_variables", &ObjCInterfaceDecl::InstanceVariables)
    .def_prop_ro("known_categories", &ObjCInterfaceDecl::KnownCategories)
    .def_prop_ro("known_extensions", &ObjCInterfaceDecl::KnownExtensions)
    .def_prop_ro("protocol_tokens", &ObjCInterfaceDecl::ProtocolTokens)
    .def_prop_ro("protocols", &ObjCInterfaceDecl::Protocols)
    .def_prop_ro("visible_categories", &ObjCInterfaceDecl::VisibleCategories)
    .def_prop_ro("visible_extensions", &ObjCInterfaceDecl::VisibleExtensions);
}
} // namespace pasta
