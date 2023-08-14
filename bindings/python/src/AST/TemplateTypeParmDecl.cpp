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

void RegisterTemplateTypeParmDecl(nb::module_ &m) {
  nb::class_<TemplateTypeParmDecl, TypeDecl>(m, "TemplateTypeParmDecl")
    .def("__hash__", [](const TemplateTypeParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("default_argument_was_inherited", &TemplateTypeParmDecl::DefaultArgumentWasInherited)
    .def_prop_ro("default_argument", &TemplateTypeParmDecl::DefaultArgument)
    .def_prop_ro("default_argument_info", &TemplateTypeParmDecl::DefaultArgumentInfo)
    .def_prop_ro("default_argument_token", &TemplateTypeParmDecl::DefaultArgumentToken)
    .def_prop_ro("depth", &TemplateTypeParmDecl::Depth)
    .def_prop_ro("index", &TemplateTypeParmDecl::Index)
    .def_prop_ro("num_expansion_parameters", &TemplateTypeParmDecl::NumExpansionParameters)
    .def_prop_ro("has_default_argument", &TemplateTypeParmDecl::HasDefaultArgument)
    .def_prop_ro("has_type_constraint", &TemplateTypeParmDecl::HasTypeConstraint)
    .def_prop_ro("is_expanded_parameter_pack", &TemplateTypeParmDecl::IsExpandedParameterPack)
    .def_prop_ro("is_pack_expansion", &TemplateTypeParmDecl::IsPackExpansion)
    .def_prop_ro("is_parameter_pack", &TemplateTypeParmDecl::IsParameterPack)
    .def_prop_ro("was_declared_with_typename", &TemplateTypeParmDecl::WasDeclaredWithTypename);
}
} // namespace pasta
