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

void RegisterTemplateTemplateParmDecl(nb::module_ &m) {
  nb::class_<TemplateTemplateParmDecl, TemplateDecl>(m, "TemplateTemplateParmDecl")
    .def("__hash__", [](const TemplateTemplateParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("default_argument_was_inherited", &TemplateTemplateParmDecl::DefaultArgumentWasInherited)
    .def_prop_ro("default_argument_token", &TemplateTemplateParmDecl::DefaultArgumentToken)
    .def_prop_ro("num_expansion_template_parameters", &TemplateTemplateParmDecl::NumExpansionTemplateParameters)
    .def_prop_ro("has_default_argument", &TemplateTemplateParmDecl::HasDefaultArgument)
    .def_prop_ro("is_expanded_parameter_pack", &TemplateTemplateParmDecl::IsExpandedParameterPack)
    .def_prop_ro("is_pack_expansion", &TemplateTemplateParmDecl::IsPackExpansion)
    .def_prop_ro("is_parameter_pack", &TemplateTemplateParmDecl::IsParameterPack);
}
} // namespace pasta
