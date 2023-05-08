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

namespace pasta {
namespace py = pybind11;

void RegisterTemplateTemplateParmDecl(py::module_ &m) {
  py::class_<TemplateTemplateParmDecl, TemplateDecl>(m, "TemplateTemplateParmDecl")
    .def("__hash__", [](const TemplateTemplateParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TemplateTemplateParmDecl& a, const TemplateTemplateParmDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("DefaultArgumentWasInherited", &TemplateTemplateParmDecl::DefaultArgumentWasInherited)
    .def_property_readonly("DefaultArgumentToken", &TemplateTemplateParmDecl::DefaultArgumentToken)
    .def_property_readonly("NumExpansionTemplateParameters", &TemplateTemplateParmDecl::NumExpansionTemplateParameters)
    .def_property_readonly("HasDefaultArgument", &TemplateTemplateParmDecl::HasDefaultArgument)
    .def_property_readonly("IsExpandedParameterPack", &TemplateTemplateParmDecl::IsExpandedParameterPack)
    .def_property_readonly("IsPackExpansion", &TemplateTemplateParmDecl::IsPackExpansion)
    .def_property_readonly("IsParameterPack", &TemplateTemplateParmDecl::IsParameterPack);
}
} // namespace pasta
