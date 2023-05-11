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

void RegisterObjCPropertyImplDecl(py::module_ &m) {
  py::class_<ObjCPropertyImplDecl, Decl>(m, "ObjCPropertyImplDecl")
    .def("__hash__", [](const ObjCPropertyImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("begin_token", &ObjCPropertyImplDecl::BeginToken)
    .def_property_readonly("getter_cxx_constructor", &ObjCPropertyImplDecl::GetterCXXConstructor)
    .def_property_readonly("getter_method_declaration", &ObjCPropertyImplDecl::GetterMethodDeclaration)
    .def_property_readonly("property_declaration", &ObjCPropertyImplDecl::PropertyDeclaration)
    .def_property_readonly("property_implementation", &ObjCPropertyImplDecl::PropertyImplementation)
    .def_property_readonly("property_instance_variable_declaration", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration)
    .def_property_readonly("property_instance_variable_declaration_token", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclarationToken)
    .def_property_readonly("setter_cxx_assignment", &ObjCPropertyImplDecl::SetterCXXAssignment)
    .def_property_readonly("setter_method_declaration", &ObjCPropertyImplDecl::SetterMethodDeclaration)
    .def_property_readonly("is_instance_variable_name_specified", &ObjCPropertyImplDecl::IsInstanceVariableNameSpecified);
}
} // namespace pasta
