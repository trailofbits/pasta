/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterClassTemplateDecl(nb::module_ &m) {
  nb::class_<ClassTemplateDecl, RedeclarableTemplateDecl>(m, "ClassTemplateDecl")
    .def_prop_ro("canonical_declaration", &ClassTemplateDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_member_template", &ClassTemplateDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("most_recent_declaration", &ClassTemplateDecl::MostRecentDeclaration)
    .def_prop_ro("previous_declaration", &ClassTemplateDecl::PreviousDeclaration)
    .def_prop_ro("templated_declaration", &ClassTemplateDecl::TemplatedDeclaration)
    .def_prop_ro("is_this_declaration_a_definition", &ClassTemplateDecl::IsThisDeclarationADefinition)
    .def_prop_ro("specializations", &ClassTemplateDecl::Specializations);
}
} // namespace pasta
