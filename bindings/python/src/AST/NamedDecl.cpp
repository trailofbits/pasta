/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterNamedDecl(nb::module_ &m) {
  nb::class_<NamedDecl, Decl>(m, "NamedDecl")
    .def("__hash__", [](const NamedDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("formal_linkage", &NamedDecl::FormalLinkage)
    .def_prop_ro("linkage_internal", &NamedDecl::LinkageInternal)
    .def_prop_ro("most_recent_declaration", &NamedDecl::MostRecentDeclaration)
    .def_prop_ro("name", &NamedDecl::Name)
    .def_prop_ro("obj_cf_string_formatting_family", &NamedDecl::ObjCFStringFormattingFamily)
    .def_prop_ro("qualified_name_as_string", &NamedDecl::QualifiedNameAsString)
    .def_prop_ro("underlying_declaration", &NamedDecl::UnderlyingDeclaration)
    .def_prop_ro("visibility", &NamedDecl::Visibility)
    .def_prop_ro("has_external_formal_linkage", &NamedDecl::HasExternalFormalLinkage)
    .def_prop_ro("has_linkage", &NamedDecl::HasLinkage)
    .def_prop_ro("has_linkage_been_computed", &NamedDecl::HasLinkageBeenComputed)
    .def_prop_ro("is_cxx_class_member", &NamedDecl::IsCXXClassMember)
    .def_prop_ro("is_cxx_instance_member", &NamedDecl::IsCXXInstanceMember)
    .def_prop_ro("is_externally_declarable", &NamedDecl::IsExternallyDeclarable)
    .def_prop_ro("is_externally_visible", &NamedDecl::IsExternallyVisible)
    .def_prop_ro("is_linkage_valid", &NamedDecl::IsLinkageValid);
}
} // namespace pasta
