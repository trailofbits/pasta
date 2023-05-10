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

void RegisterTemplateTypeParmDecl(py::module_ &m) {
  py::class_<TemplateTypeParmDecl, TypeDecl>(m, "TemplateTypeParmDecl")
    .def("__hash__", [](const TemplateTypeParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TemplateTypeParmDecl& a, const TemplateTypeParmDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("default_argument_was_inherited", &TemplateTypeParmDecl::DefaultArgumentWasInherited)
    .def_property_readonly("default_argument", &TemplateTypeParmDecl::DefaultArgument)
    .def_property_readonly("default_argument_info", &TemplateTypeParmDecl::DefaultArgumentInfo)
    .def_property_readonly("default_argument_token", &TemplateTypeParmDecl::DefaultArgumentToken)
    .def_property_readonly("depth", &TemplateTypeParmDecl::Depth)
    .def_property_readonly("index", &TemplateTypeParmDecl::Index)
    .def_property_readonly("num_expansion_parameters", &TemplateTypeParmDecl::NumExpansionParameters)
    .def_property_readonly("has_default_argument", &TemplateTypeParmDecl::HasDefaultArgument)
    .def_property_readonly("has_type_constraint", &TemplateTypeParmDecl::HasTypeConstraint)
    .def_property_readonly("is_expanded_parameter_pack", &TemplateTypeParmDecl::IsExpandedParameterPack)
    .def_property_readonly("is_pack_expansion", &TemplateTypeParmDecl::IsPackExpansion)
    .def_property_readonly("is_parameter_pack", &TemplateTypeParmDecl::IsParameterPack)
    .def_property_readonly("was_declared_with_typename", &TemplateTypeParmDecl::WasDeclaredWithTypename);
}
} // namespace pasta
