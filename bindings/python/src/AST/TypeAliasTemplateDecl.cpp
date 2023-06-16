/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterTypeAliasTemplateDecl(nb::module_ &m) {
  nb::class_<TypeAliasTemplateDecl, RedeclarableTemplateDecl>(m, "TypeAliasTemplateDecl")
    .def("__hash__", [](const TypeAliasTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &TypeAliasTemplateDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_member_template", &TypeAliasTemplateDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("previous_declaration", &TypeAliasTemplateDecl::PreviousDeclaration)
    .def_prop_ro("templated_declaration", &TypeAliasTemplateDecl::TemplatedDeclaration);
}
} // namespace pasta
