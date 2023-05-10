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

void RegisterNamedDecl(py::module_ &m) {
  py::class_<NamedDecl, Decl>(m, "NamedDecl")
    .def("__hash__", [](const NamedDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const NamedDecl& a, const NamedDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("formal_linkage", &NamedDecl::FormalLinkage)
    .def_property_readonly("linkage_internal", &NamedDecl::LinkageInternal)
    .def_property_readonly("most_recent_declaration", &NamedDecl::MostRecentDeclaration)
    .def_property_readonly("name", &NamedDecl::Name)
    .def_property_readonly("obj_cf_string_formatting_family", &NamedDecl::ObjCFStringFormattingFamily)
    .def_property_readonly("qualified_name_as_string", &NamedDecl::QualifiedNameAsString)
    .def_property_readonly("underlying_declaration", &NamedDecl::UnderlyingDeclaration)
    .def_property_readonly("visibility", &NamedDecl::Visibility)
    .def_property_readonly("has_external_formal_linkage", &NamedDecl::HasExternalFormalLinkage)
    .def_property_readonly("has_linkage", &NamedDecl::HasLinkage)
    .def_property_readonly("has_linkage_been_computed", &NamedDecl::HasLinkageBeenComputed)
    .def_property_readonly("is_cxx_class_member", &NamedDecl::IsCXXClassMember)
    .def_property_readonly("is_cxx_instance_member", &NamedDecl::IsCXXInstanceMember)
    .def_property_readonly("is_externally_declarable", &NamedDecl::IsExternallyDeclarable)
    .def_property_readonly("is_externally_visible", &NamedDecl::IsExternallyVisible)
    .def_property_readonly("is_linkage_valid", &NamedDecl::IsLinkageValid);
}
} // namespace pasta
