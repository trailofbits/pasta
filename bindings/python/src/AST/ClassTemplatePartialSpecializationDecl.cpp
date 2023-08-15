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

void RegisterClassTemplatePartialSpecializationDecl(nb::module_ &m) {
  nb::class_<ClassTemplatePartialSpecializationDecl, ClassTemplateSpecializationDecl>(m, "ClassTemplatePartialSpecializationDecl")
    .def("__hash__", [](const ClassTemplatePartialSpecializationDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("injected_specialization_type", &ClassTemplatePartialSpecializationDecl::InjectedSpecializationType)
    .def_prop_ro("instantiated_from_member", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_prop_ro("instantiated_from_member_template", &ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate)
    .def_prop_ro("template_parameters", &ClassTemplatePartialSpecializationDecl::TemplateParameters)
    .def_prop_ro("has_associated_constraints", &ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
