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

void RegisterNonTypeTemplateParmDecl(nb::module_ &m) {
  nb::class_<NonTypeTemplateParmDecl, DeclaratorDecl>(m, "NonTypeTemplateParmDecl")
    .def("__hash__", [](const NonTypeTemplateParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("default_argument_was_inherited", &NonTypeTemplateParmDecl::DefaultArgumentWasInherited)
    .def_prop_ro("default_argument", &NonTypeTemplateParmDecl::DefaultArgument)
    .def_prop_ro("default_argument_token", &NonTypeTemplateParmDecl::DefaultArgumentToken)
    .def_prop_ro("num_expansion_types", &NonTypeTemplateParmDecl::NumExpansionTypes)
    .def_prop_ro("placeholder_type_constraint", &NonTypeTemplateParmDecl::PlaceholderTypeConstraint)
    .def_prop_ro("has_default_argument", &NonTypeTemplateParmDecl::HasDefaultArgument)
    .def_prop_ro("has_placeholder_type_constraint", &NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint)
    .def_prop_ro("is_expanded_parameter_pack", &NonTypeTemplateParmDecl::IsExpandedParameterPack)
    .def_prop_ro("is_pack_expansion", &NonTypeTemplateParmDecl::IsPackExpansion)
    .def_prop_ro("is_parameter_pack", &NonTypeTemplateParmDecl::IsParameterPack);
}
} // namespace pasta
