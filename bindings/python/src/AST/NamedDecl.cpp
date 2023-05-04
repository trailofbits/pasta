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

void RegisterNamedDecl(py::module_ &m) {
  py::class_<NamedDecl, Decl>(m, "NamedDecl")
    .def_property_readonly("FormalLinkage", &NamedDecl::FormalLinkage)
    .def_property_readonly("LinkageInternal", &NamedDecl::LinkageInternal)
    .def_property_readonly("MostRecentDeclaration", &NamedDecl::MostRecentDeclaration)
    .def_property_readonly("Name", &NamedDecl::Name)
    .def_property_readonly("ObjCFStringFormattingFamily", &NamedDecl::ObjCFStringFormattingFamily)
    .def_property_readonly("QualifiedNameAsString", &NamedDecl::QualifiedNameAsString)
    .def_property_readonly("UnderlyingDeclaration", &NamedDecl::UnderlyingDeclaration)
    .def_property_readonly("Visibility", &NamedDecl::Visibility)
    .def_property_readonly("HasExternalFormalLinkage", &NamedDecl::HasExternalFormalLinkage)
    .def_property_readonly("HasLinkage", &NamedDecl::HasLinkage)
    .def_property_readonly("HasLinkageBeenComputed", &NamedDecl::HasLinkageBeenComputed)
    .def_property_readonly("IsCXXClassMember", &NamedDecl::IsCXXClassMember)
    .def_property_readonly("IsCXXInstanceMember", &NamedDecl::IsCXXInstanceMember)
    .def_property_readonly("IsExternallyDeclarable", &NamedDecl::IsExternallyDeclarable)
    .def_property_readonly("IsExternallyVisible", &NamedDecl::IsExternallyVisible)
    .def_property_readonly("IsLinkageValid", &NamedDecl::IsLinkageValid);
}
} // namespace pasta
