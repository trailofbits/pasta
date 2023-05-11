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

void RegisterObjCPropertyDecl(py::module_ &m) {
  py::class_<ObjCPropertyDecl, NamedDecl>(m, "ObjCPropertyDecl")
    .def("__hash__", [](const ObjCPropertyDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("at_token", &ObjCPropertyDecl::AtToken)
    .def_property_readonly("getter_method_declaration", &ObjCPropertyDecl::GetterMethodDeclaration)
    .def_property_readonly("getter_name_token", &ObjCPropertyDecl::GetterNameToken)
    .def_property_readonly("l_paren_token", &ObjCPropertyDecl::LParenToken)
    .def_property_readonly("property_implementation", &ObjCPropertyDecl::PropertyImplementation)
    .def_property_readonly("property_instance_variable_declaration", &ObjCPropertyDecl::PropertyInstanceVariableDeclaration)
    .def_property_readonly("query_kind", &ObjCPropertyDecl::QueryKind)
    .def_property_readonly("setter_kind", &ObjCPropertyDecl::SetterKind)
    .def_property_readonly("setter_method_declaration", &ObjCPropertyDecl::SetterMethodDeclaration)
    .def_property_readonly("setter_name_token", &ObjCPropertyDecl::SetterNameToken)
    .def_property_readonly("type", &ObjCPropertyDecl::Type)
    .def_property_readonly("is_atomic", &ObjCPropertyDecl::IsAtomic)
    .def_property_readonly("is_class_property", &ObjCPropertyDecl::IsClassProperty)
    .def_property_readonly("is_direct_property", &ObjCPropertyDecl::IsDirectProperty)
    .def_property_readonly("is_instance_property", &ObjCPropertyDecl::IsInstanceProperty)
    .def_property_readonly("is_optional", &ObjCPropertyDecl::IsOptional)
    .def_property_readonly("is_read_only", &ObjCPropertyDecl::IsReadOnly)
    .def_property_readonly("is_retaining", &ObjCPropertyDecl::IsRetaining);
}
} // namespace pasta
