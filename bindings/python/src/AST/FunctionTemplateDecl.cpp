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

void RegisterFunctionTemplateDecl(nb::module_ &m) {
  nb::class_<FunctionTemplateDecl, RedeclarableTemplateDecl>(m, "FunctionTemplateDecl")
    .def_prop_ro("canonical_declaration", &FunctionTemplateDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_member_template", &FunctionTemplateDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("most_recent_declaration", &FunctionTemplateDecl::MostRecentDeclaration)
    .def_prop_ro("previous_declaration", &FunctionTemplateDecl::PreviousDeclaration)
    .def_prop_ro("templated_declaration", &FunctionTemplateDecl::TemplatedDeclaration)
    .def_prop_ro("is_abbreviated", &FunctionTemplateDecl::IsAbbreviated)
    .def_prop_ro("is_this_declaration_a_definition", &FunctionTemplateDecl::IsThisDeclarationADefinition)
    .def_prop_ro("specializations", &FunctionTemplateDecl::Specializations);
}
} // namespace pasta
