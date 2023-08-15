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

void RegisterVarTemplateDecl(nb::module_ &m) {
  nb::class_<VarTemplateDecl, RedeclarableTemplateDecl>(m, "VarTemplateDecl")
    .def("__hash__", [](const VarTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &VarTemplateDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_member_template", &VarTemplateDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("most_recent_declaration", &VarTemplateDecl::MostRecentDeclaration)
    .def_prop_ro("previous_declaration", &VarTemplateDecl::PreviousDeclaration)
    .def_prop_ro("templated_declaration", &VarTemplateDecl::TemplatedDeclaration)
    .def_prop_ro("is_this_declaration_a_definition", &VarTemplateDecl::IsThisDeclarationADefinition)
    .def_prop_ro("specializations", &VarTemplateDecl::Specializations);
}
} // namespace pasta
