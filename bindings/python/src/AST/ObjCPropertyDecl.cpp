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

void RegisterObjCPropertyDecl(py::module_ &m) {
  py::class_<ObjCPropertyDecl, Decl, NamedDecl>(m, "ObjCPropertyDecl")
    .def("__hash__", [](const ObjCPropertyDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCPropertyDecl& a, const ObjCPropertyDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AtToken", &ObjCPropertyDecl::AtToken)
    .def_property_readonly("GetterMethodDeclaration", &ObjCPropertyDecl::GetterMethodDeclaration)
    .def_property_readonly("GetterNameToken", &ObjCPropertyDecl::GetterNameToken)
    .def_property_readonly("LParenToken", &ObjCPropertyDecl::LParenToken)
    .def_property_readonly("PropertyImplementation", &ObjCPropertyDecl::PropertyImplementation)
    .def_property_readonly("PropertyInstanceVariableDeclaration", &ObjCPropertyDecl::PropertyInstanceVariableDeclaration)
    .def_property_readonly("QueryKind", &ObjCPropertyDecl::QueryKind)
    .def_property_readonly("SetterKind", &ObjCPropertyDecl::SetterKind)
    .def_property_readonly("SetterMethodDeclaration", &ObjCPropertyDecl::SetterMethodDeclaration)
    .def_property_readonly("SetterNameToken", &ObjCPropertyDecl::SetterNameToken)
    .def_property_readonly("Type", &ObjCPropertyDecl::Type)
    .def_property_readonly("IsAtomic", &ObjCPropertyDecl::IsAtomic)
    .def_property_readonly("IsClassProperty", &ObjCPropertyDecl::IsClassProperty)
    .def_property_readonly("IsDirectProperty", &ObjCPropertyDecl::IsDirectProperty)
    .def_property_readonly("IsInstanceProperty", &ObjCPropertyDecl::IsInstanceProperty)
    .def_property_readonly("IsOptional", &ObjCPropertyDecl::IsOptional)
    .def_property_readonly("IsReadOnly", &ObjCPropertyDecl::IsReadOnly)
    .def_property_readonly("IsRetaining", &ObjCPropertyDecl::IsRetaining);
}
} // namespace pasta
