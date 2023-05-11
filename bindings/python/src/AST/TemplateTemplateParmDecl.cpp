/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterTemplateTemplateParmDecl(py::module_ &m) {
  py::class_<TemplateTemplateParmDecl, TemplateDecl>(m, "TemplateTemplateParmDecl")
    .def("__hash__", [](const TemplateTemplateParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("default_argument_was_inherited", &TemplateTemplateParmDecl::DefaultArgumentWasInherited)
    .def_property_readonly("default_argument_token", &TemplateTemplateParmDecl::DefaultArgumentToken)
    .def_property_readonly("num_expansion_template_parameters", &TemplateTemplateParmDecl::NumExpansionTemplateParameters)
    .def_property_readonly("has_default_argument", &TemplateTemplateParmDecl::HasDefaultArgument)
    .def_property_readonly("is_expanded_parameter_pack", &TemplateTemplateParmDecl::IsExpandedParameterPack)
    .def_property_readonly("is_pack_expansion", &TemplateTemplateParmDecl::IsPackExpansion)
    .def_property_readonly("is_parameter_pack", &TemplateTemplateParmDecl::IsParameterPack);
}
} // namespace pasta
