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

void RegisterRedeclarableTemplateDecl(nb::module_ &m) {
  nb::class_<RedeclarableTemplateDecl, TemplateDecl>(m, "RedeclarableTemplateDecl")
    .def("__hash__", [](const RedeclarableTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &RedeclarableTemplateDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_member_template", &RedeclarableTemplateDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("is_member_specialization", &RedeclarableTemplateDecl::IsMemberSpecialization);
}
} // namespace pasta
