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

void RegisterObjCInterfaceDecl(py::module_ &m) {
  py::class_<ObjCInterfaceDecl, Decl, NamedDecl, ObjCContainerDecl>(m, "ObjCInterfaceDecl")
    .def("__hash__", [](const ObjCInterfaceDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCInterfaceDecl& a, const ObjCInterfaceDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AllReferencedProtocols", &ObjCInterfaceDecl::AllReferencedProtocols)
    .def_property_readonly("DeclaresOrInheritsDesignatedInitializers", &ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers)
    .def_property_readonly("CanonicalDeclaration", &ObjCInterfaceDecl::CanonicalDeclaration)
    .def_property_readonly("CategoryListRaw", &ObjCInterfaceDecl::CategoryListRaw)
    .def_property_readonly("Definition", &ObjCInterfaceDecl::Definition)
    .def_property_readonly("EndOfDefinitionToken", &ObjCInterfaceDecl::EndOfDefinitionToken)
    .def_property_readonly("Implementation", &ObjCInterfaceDecl::Implementation)
    .def_property_readonly("ObjCRuntimeNameAsString", &ObjCInterfaceDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("SuperClass", &ObjCInterfaceDecl::SuperClass)
    .def_property_readonly("SuperClassToken", &ObjCInterfaceDecl::SuperClassToken)
    .def_property_readonly("SuperClassTypeInfo", &ObjCInterfaceDecl::SuperClassTypeInfo)
    .def_property_readonly("SuperClassType", &ObjCInterfaceDecl::SuperClassType)
    .def_property_readonly("TypeForDeclaration", &ObjCInterfaceDecl::TypeForDeclaration)
    .def_property_readonly("HasDefinition", &ObjCInterfaceDecl::HasDefinition)
    .def_property_readonly("HasDesignatedInitializers", &ObjCInterfaceDecl::HasDesignatedInitializers)
    .def_property_readonly("IsArcWeakrefUnavailable", &ObjCInterfaceDecl::IsArcWeakrefUnavailable)
    .def_property_readonly("IsImplicitInterfaceDeclaration", &ObjCInterfaceDecl::IsImplicitInterfaceDeclaration)
    .def_property_readonly("IsObjCRequiresPropertyDefinitions", &ObjCInterfaceDecl::IsObjCRequiresPropertyDefinitions)
    .def_property_readonly("IsThisDeclarationADefinition", &ObjCInterfaceDecl::IsThisDeclarationADefinition)
    .def_property_readonly("InstanceVariables", &ObjCInterfaceDecl::InstanceVariables)
    .def_property_readonly("KnownCategories", &ObjCInterfaceDecl::KnownCategories)
    .def_property_readonly("KnownExtensions", &ObjCInterfaceDecl::KnownExtensions)
    .def_property_readonly("ProtocolTokens", &ObjCInterfaceDecl::ProtocolTokens)
    .def_property_readonly("Protocols", &ObjCInterfaceDecl::Protocols)
    .def_property_readonly("VisibleCategories", &ObjCInterfaceDecl::VisibleCategories)
    .def_property_readonly("VisibleExtensions", &ObjCInterfaceDecl::VisibleExtensions);
}
} // namespace pasta
