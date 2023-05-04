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

void RegisterTemplateTypeParmDecl(py::module_ &m) {
  py::class_<TemplateTypeParmDecl, Decl, NamedDecl, TypeDecl>(m, "TemplateTypeParmDecl")
    .def("__hash__", [](const TemplateTypeParmDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TemplateTypeParmDecl& a, const TemplateTypeParmDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("DefaultArgumentWasInherited", &TemplateTypeParmDecl::DefaultArgumentWasInherited)
    .def_property_readonly("DefaultArgument", &TemplateTypeParmDecl::DefaultArgument)
    .def_property_readonly("DefaultArgumentInfo", &TemplateTypeParmDecl::DefaultArgumentInfo)
    .def_property_readonly("DefaultArgumentToken", &TemplateTypeParmDecl::DefaultArgumentToken)
    .def_property_readonly("Depth", &TemplateTypeParmDecl::Depth)
    .def_property_readonly("Index", &TemplateTypeParmDecl::Index)
    .def_property_readonly("NumExpansionParameters", &TemplateTypeParmDecl::NumExpansionParameters)
    .def_property_readonly("HasDefaultArgument", &TemplateTypeParmDecl::HasDefaultArgument)
    .def_property_readonly("HasTypeConstraint", &TemplateTypeParmDecl::HasTypeConstraint)
    .def_property_readonly("IsExpandedParameterPack", &TemplateTypeParmDecl::IsExpandedParameterPack)
    .def_property_readonly("IsPackExpansion", &TemplateTypeParmDecl::IsPackExpansion)
    .def_property_readonly("IsParameterPack", &TemplateTypeParmDecl::IsParameterPack)
    .def_property_readonly("WasDeclaredWithTypename", &TemplateTypeParmDecl::WasDeclaredWithTypename);
}
} // namespace pasta
