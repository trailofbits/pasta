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

void RegisterObjCPropertyImplDecl(py::module_ &m) {
  py::class_<ObjCPropertyImplDecl, Decl>(m, "ObjCPropertyImplDecl")
    .def("__hash__", [](const ObjCPropertyImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCPropertyImplDecl& a, const ObjCPropertyImplDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("BeginToken", &ObjCPropertyImplDecl::BeginToken)
    .def_property_readonly("GetterCXXConstructor", &ObjCPropertyImplDecl::GetterCXXConstructor)
    .def_property_readonly("GetterMethodDeclaration", &ObjCPropertyImplDecl::GetterMethodDeclaration)
    .def_property_readonly("PropertyDeclaration", &ObjCPropertyImplDecl::PropertyDeclaration)
    .def_property_readonly("PropertyImplementation", &ObjCPropertyImplDecl::PropertyImplementation)
    .def_property_readonly("PropertyInstanceVariableDeclaration", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclaration)
    .def_property_readonly("PropertyInstanceVariableDeclarationToken", &ObjCPropertyImplDecl::PropertyInstanceVariableDeclarationToken)
    .def_property_readonly("SetterCXXAssignment", &ObjCPropertyImplDecl::SetterCXXAssignment)
    .def_property_readonly("SetterMethodDeclaration", &ObjCPropertyImplDecl::SetterMethodDeclaration)
    .def_property_readonly("IsInstanceVariableNameSpecified", &ObjCPropertyImplDecl::IsInstanceVariableNameSpecified);
}
} // namespace pasta
