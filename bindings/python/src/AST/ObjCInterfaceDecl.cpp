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

void RegisterObjCInterfaceDecl(py::module_ &m) {
  py::class_<ObjCInterfaceDecl, ObjCContainerDecl>(m, "ObjCInterfaceDecl")
    .def("__hash__", [](const ObjCInterfaceDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCInterfaceDecl& a, const ObjCInterfaceDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("all_referenced_protocols", &ObjCInterfaceDecl::AllReferencedProtocols)
    .def_property_readonly("declares_or_inherits_designated_initializers", &ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers)
    .def_property_readonly("canonical_declaration", &ObjCInterfaceDecl::CanonicalDeclaration)
    .def_property_readonly("category_list_raw", &ObjCInterfaceDecl::CategoryListRaw)
    .def_property_readonly("definition", &ObjCInterfaceDecl::Definition)
    .def_property_readonly("end_of_definition_token", &ObjCInterfaceDecl::EndOfDefinitionToken)
    .def_property_readonly("implementation", &ObjCInterfaceDecl::Implementation)
    .def_property_readonly("obj_c_runtime_name_as_string", &ObjCInterfaceDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("super_class", &ObjCInterfaceDecl::SuperClass)
    .def_property_readonly("super_class_token", &ObjCInterfaceDecl::SuperClassToken)
    .def_property_readonly("super_class_type_info", &ObjCInterfaceDecl::SuperClassTypeInfo)
    .def_property_readonly("super_class_type", &ObjCInterfaceDecl::SuperClassType)
    .def_property_readonly("type_for_declaration", &ObjCInterfaceDecl::TypeForDeclaration)
    .def_property_readonly("has_definition", &ObjCInterfaceDecl::HasDefinition)
    .def_property_readonly("has_designated_initializers", &ObjCInterfaceDecl::HasDesignatedInitializers)
    .def_property_readonly("is_arc_weakref_unavailable", &ObjCInterfaceDecl::IsArcWeakrefUnavailable)
    .def_property_readonly("is_implicit_interface_declaration", &ObjCInterfaceDecl::IsImplicitInterfaceDeclaration)
    .def_property_readonly("is_obj_c_requires_property_definitions", &ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions)
    .def_property_readonly("is_this_declaration_a_definition", &ObjCInterfaceDecl::IsThisDeclarationADefinition)
    .def_property_readonly("instance_variables", &ObjCInterfaceDecl::InstanceVariables)
    .def_property_readonly("known_categories", &ObjCInterfaceDecl::KnownCategories)
    .def_property_readonly("known_extensions", &ObjCInterfaceDecl::KnownExtensions)
    .def_property_readonly("protocol_tokens", &ObjCInterfaceDecl::ProtocolTokens)
    .def_property_readonly("protocols", &ObjCInterfaceDecl::Protocols)
    .def_property_readonly("visible_categories", &ObjCInterfaceDecl::VisibleCategories)
    .def_property_readonly("visible_extensions", &ObjCInterfaceDecl::VisibleExtensions);
}
} // namespace pasta
