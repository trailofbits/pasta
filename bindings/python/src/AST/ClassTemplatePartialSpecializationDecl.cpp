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

void RegisterClassTemplatePartialSpecializationDecl(nb::module_ &m) {
  nb::class_<ClassTemplatePartialSpecializationDecl, ClassTemplateSpecializationDecl>(m, "ClassTemplatePartialSpecializationDecl")
    .def_prop_ro("injected_specialization_type", &ClassTemplatePartialSpecializationDecl::InjectedSpecializationType)
    .def_prop_ro("instantiated_from_member", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_prop_ro("instantiated_from_member_template", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("template_parameters", &ClassTemplatePartialSpecializationDecl::TemplateParameters)
    .def_prop_ro("has_associated_constraints", &ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
