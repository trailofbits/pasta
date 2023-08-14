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

void RegisterObjCPropertyImplDecl(nb::module_ &m) {
  nb::class_<ObjCPropertyImplDecl, Decl>(m, "ObjCPropertyImplDecl")
    .def("__hash__", [](const ObjCPropertyImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("begin_token", &ObjCPropertyImplDecl::BeginToken)
    .def_prop_ro("getter_cxx_constructor", &ObjCPropertyImplDecl::GetterCXXConstructor)
    .def_prop_ro("getter_method_declaration", &ObjCPropertyImplDecl::GetterMethodDeclaration)
    .def_prop_ro("property_declaration", &ObjCPropertyImplDecl::PropertyDeclaration)
    .def_prop_ro("property_implementation", &ObjCPropertyImplDecl::PropertyImplementation)
    .def_prop_ro("property_instance_variable_declaration", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration)
    .def_prop_ro("property_instance_variable_declaration_token", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclarationToken)
    .def_prop_ro("setter_cxx_assignment", &ObjCPropertyImplDecl::SetterCXXAssignment)
    .def_prop_ro("setter_method_declaration", &ObjCPropertyImplDecl::SetterMethodDeclaration)
    .def_prop_ro("is_instance_variable_name_specified", &ObjCPropertyImplDecl::IsInstanceVariableNameSpecified);
}
} // namespace pasta
